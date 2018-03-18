import java.util.*;

public class Selection {

    public static Integer Select1(ArrayList<Integer> data,int n){
        n=data.size()-n;
        ArrayList<Integer> tmp=new ArrayList<>(data);
        Collections.sort(tmp);
        return tmp.get(n);
    }

    public static Integer Select2(ArrayList<Integer> data,int n){
        n=data.size()-n+1;
        LinkedList<Integer> list=new LinkedList<>();

        for(int i=0;i<n;i++){
            list.add(data.get(i));
        }
        Collections.sort(list);

        for(int i=n;i<data.size();i++){
            if(data.get(i)<list.getLast()){
                Integer j=data.get(i);
                ListIterator<Integer> it =list.listIterator();
                while(it.hasNext()){
                    if(it.next()>j) {
                        it.previous();
                        it.add(j);
                        list.removeLast();
                        break;
                    }
                }
            }
        }
        return list.getLast();
    }

}
