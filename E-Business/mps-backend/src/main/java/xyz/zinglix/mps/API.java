package xyz.zinglix.mps;

import java.text.SimpleDateFormat;
import java.util.*;

import java.text.DateFormat ;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.util.Pair;
import org.springframework.web.bind.annotation.*;

class item implements Comparable<item>{
    public static Long id=0L;

    public Long getId() {
        return id++;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public Material material;
    public Long count;
    public Long newCount;
    public Date readyDate;
    public Date finishedDate;
    public List<item> neededItem;
    public item(Material m,Long count,Date d){
        material=m;
        this.count=count;
        this.finishedDate=d;
        neededItem=new ArrayList<>();
    }
    public int compareTo(item other){
        return readyDate.compareTo(other.readyDate);
    }

    public Material getMaterial() {
        return material;
    }

    public void setMaterial(Material material) {
        this.material = material;
    }

    public Long getCount() {
        return count;
    }

    public void setCount(Long count) {
        this.count = count;
    }

    public Long getNewCount() {
        return newCount;
    }

    public void setNewCount(Long newCount) {
        this.newCount = newCount;
    }

    public String getReadyDate() {
        DateFormat df=DateFormat.getDateInstance();
        return df.format(readyDate);
    }

    public void setReadyDate(Date readyDate) {
        this.readyDate = readyDate;
    }

    public String getFinishedDate() {
        DateFormat df=DateFormat.getDateInstance();
        return df.format(finishedDate);
    }

    public void setFinishedDate(Date finishedDate) {
        this.finishedDate = finishedDate;
    }

    public List<item> getNeededItem() {
        return neededItem;
    }

    public void setNeededItem(List<item> neededItem) {
        this.neededItem = neededItem;
    }
}

class Response{
    Long id;

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public Response() {
    }

    public Response(Long id) {
        this.id = id;
    }
}

@RestController
public class API {
    @Autowired
    private InventoryRepository inventoryRepository;

    @Autowired
    private MaterialRepository materialRepository;

    @Autowired
    private MakeUpRepository makeUpRepository;

    @CrossOrigin
    @RequestMapping("/api/inventory")
    public List<MaterialInventoryInfo> inventory() {
        return inventoryRepository.findMaterialInventoryInfo();
    }

    private List<item> itemList;

    @CrossOrigin
    @RequestMapping("/api/addRecord")
    @ResponseBody
    public List<item> addRecord(@RequestBody Map<String,Object> reqMap) {
        itemList=new ArrayList<>();
        Long productID = ((Number)reqMap.get("id")).longValue(),count =((Number)reqMap.get("count")).longValue();
        SimpleDateFormat sdf =   new SimpleDateFormat( "yyyy-MM-dd" );
        Date d;
        try {
            d = sdf.parse(reqMap.get("date").toString());
        }catch (Exception e){
            return null;
        }
        var m=materialRepository.findById(productID);
        if(!m.isPresent()) return null;
        item target=new item(m.get(),count,d);
        var l= inventoryRepository.findMaterialInventoryInfo().get(Math.toIntExact(target.material.getId()-1));
        target.newCount=target.count-l.getMaterial_inv()-l.getProcess_inv();
        deal(target);
        Collections.sort(itemList);
        check(itemList);
        List<item> result=new ArrayList<>();
        result.add(target);
        return result;
    }

    private void deal(item i){
        Calendar c=new GregorianCalendar();
        c.setTime(i.finishedDate);
        c.add(Calendar.DATE,-i.material.getWorkAhead());
        i.readyDate=c.getTime();
        if(i.material.isMethod()){
            var needed=makeUpRepository.findByProductId(i.material.getId());
            for(var n:needed){
                c.setTime(i.readyDate);
                c.add(Calendar.DATE,-(int)(n.getDistributionAhead()+n.getManufactureAhead()));
                i.neededItem.add(new item(materialRepository.findById(n.getSubProductId()).get(),
                        (long)Math.ceil((i.count*n.getCount())/(1-materialRepository.findById(n.getSubProductId()).get().getLoss())),
                        c.getTime()));
            }
            for(var it:i.neededItem){
                deal(it);
                itemList.add(it);
            }
        }
    }
    private void check(List<item> items){
        var inv=inventoryRepository.findMaterialInventoryInfo();
        for(var i:items){
            Long need=i.count;
            if(inv.get(Math.toIntExact(i.material.getId())-1).getProcess_inv()!=0){
                if(need>inv.get(Math.toIntExact(i.material.getId())-1).getProcess_inv()){
                    need-=inv.get(Math.toIntExact(i.material.getId())-1).getProcess_inv();
                    inv.get(Math.toIntExact(i.material.getId())-1).setProcess_inv(0L);
                }else{
                    inv.get(Math.toIntExact(i.material.getId())-1).setProcess_inv(inv.get(Math.toIntExact(i.material.getId())-1).getProcess_inv()-need);
                    need=0L;
                }
            }
            if(need!=0){
                if(need>inv.get(Math.toIntExact(i.material.getId())-1).getMaterial_inv()){
                    need-=inv.get(Math.toIntExact(i.material.getId())-1).getMaterial_inv();
                    inv.get(Math.toIntExact(i.material.getId())-1).setMaterial_inv(0L);
                }else{
                    inv.get(Math.toIntExact(i.material.getId())-1).setMaterial_inv(inv.get(Math.toIntExact(i.material.getId())-1).getMaterial_inv()-need);
                    need=0L;
                }
            }
            i.newCount=need;
        }
    }

    @Autowired
    OrderRepository order;

    @GetMapping("/api/crm")
    public List<Orders> orders(){
        return order.findAll();
    }

    @RequestMapping("/api/crm/{id}")
    public Map<Long,Float> crm(@PathVariable Long id){
        List<Orders> orders=order.findAll();
        Map<Long,Set<Long>> userorder=new HashMap<>();
        //过滤重复订单，得到每个用户购买过的商品列表
        for(var o:orders){
            if(!userorder.containsKey(o.userId)){
                userorder.put(o.userId,new HashSet<>());
            }
            userorder.get(o.userId).add(o.productId);
        }
        //计算每个商品有多少人买过
        Map<Long,Long> map=new HashMap<>();
        for(var p:userorder.values()){
            for(var pid:p){
                if(!map.containsKey(pid)) map.put(pid,0L);
                map.put(pid,map.get(pid)+1);
            }
        }
        var map_backup=map;
        //移除支持度小于0.3的商品
        List<Long> toberemoved=new ArrayList<>();
        for(var p:map.keySet()){
            if((float)map.get(p)/userorder.size()<0.3){
                toberemoved.add(p);
            }
        }
        for(var p:toberemoved) map.remove(p);
        //两两商品计算支持度
        Map<Pair<Long,Long>,Long> map2=new HashMap<>();
        for(var p:map.keySet()) {
            for (var q : map.keySet()) {
                if (p >= q) continue;
                if (p != id && q != id) continue;
                Long count = 0L;
                for (var s : userorder.values()) {
                    if (s.contains(p) && s.contains(q)) count++;
                }
                map2.put(Pair.of(p, q), count);
            }
        }
        //计算兴趣度
        Map<Long,Float> res=new HashMap<>();
        for(var m:map2.keySet()){
            Long other=m.getFirst()==id?m.getSecond():m.getFirst();
            Float interest= (float)map2.get(m)/(map.get(id)*map_backup.get(other))*userorder.size();
            res.put(other,interest);
        }
        return res;
    }
}
