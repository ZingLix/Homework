package xyz.zinglix.mps;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;

@Entity
public class Material {
    @Id
    @GeneratedValue(strategy= GenerationType.IDENTITY)
    private Long id;
    private String name;
    private String unit;
    private boolean method; //true生产,false调配
    private double loss;
    private Integer workAhead;

    Material(Long id,String name,String unit,boolean method,double loss,int workAhead){
        this.id=id;
        this.name=name;
        this.unit=unit;
        this.method=method;
        this.loss=loss;
        this.workAhead=workAhead;
    }
    public Material(){}
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
}
