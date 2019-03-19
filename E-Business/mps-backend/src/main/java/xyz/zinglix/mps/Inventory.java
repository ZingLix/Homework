package xyz.zinglix.mps;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
@Entity
public class Inventory {
    @Id
    private Long id;
    private Long processInv;
    private Long materialInv;

    public Inventory(Long id, Long processInv, Long materialInv) {
        this.id = id;
        this.processInv = processInv;
        this.materialInv = materialInv;
    }

    public Inventory(){}

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public Long getProcessInv() {
        return processInv;
    }

    public void setProcessInv(Long processInv) {
        this.processInv = processInv;
    }

    public Long getMaterialInv() {
        return materialInv;
    }

    public void setMaterialInv(Long materialInv) {
        this.materialInv = materialInv;
    }
}
