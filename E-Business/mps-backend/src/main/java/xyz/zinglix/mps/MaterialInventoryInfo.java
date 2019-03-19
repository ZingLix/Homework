package xyz.zinglix.mps;

class MaterialInventoryInfo{
    private Long id;
    private String name;
    private Long material_inv;
    private Long process_inv;
    private String unit;
    private boolean method; //true生产,false调配
    private double loss;
    private Integer workAhead;

    public MaterialInventoryInfo(Long id, String name, Long material_inv, Long process_inv, String unit, boolean method, double loss, Integer workAhead) {
        this.id = id;
        this.name = name;
        this.material_inv = material_inv;
        this.process_inv = process_inv;
        this.unit = unit;
        this.method = method;
        this.loss = loss;
        this.workAhead = workAhead;
    }

    public String getUnit() {
        return unit;
    }

    public void setUnit(String unit) {
        this.unit = unit;
    }

    public boolean isMethod() {
        return method;
    }

    public void setMethod(boolean method) {
        this.method = method;
    }

    public double getLoss() {
        return loss;
    }

    public void setLoss(double loss) {
        this.loss = loss;
    }

    public Integer getWorkAhead() {
        return workAhead;
    }

    public void setWorkAhead(Integer workAhead) {
        this.workAhead = workAhead;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Long getMaterial_inv() {
        return material_inv;
    }

    public void setMaterial_inv(Long material_inv) {
        this.material_inv = material_inv;
    }

    public Long getProcess_inv() {
        return process_inv;
    }

    public void setProcess_inv(Long process_inv) {
        this.process_inv = process_inv;
    }

    public MaterialInventoryInfo(Material m,Inventory i) {
        this.id = m.getId();
        this.name = m.getName();
        this.material_inv = i.getMaterialInv();
        this.process_inv = i.getProcessInv();
        this.loss=m.getLoss();
        this.unit=m.getUnit();
        this.method=m.isMethod();
        this.workAhead=m.getWorkAhead();
    }
}