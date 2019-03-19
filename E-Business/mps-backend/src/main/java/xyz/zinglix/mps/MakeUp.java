package xyz.zinglix.mps;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;

@Entity
public class MakeUp {
    @Id
    @GeneratedValue(strategy= GenerationType.IDENTITY)
    private Long id;
    private Long productId;
    private Long subProductId;
    private Integer count;
    private Long distributionAhead;
    private Long manufactureAhead;

    public MakeUp(Long id, Long productId, Long subProductId, Integer count, Long distributionAhead, Long manufactureAhead) {
        this.id = id;
        this.productId = productId;
        this.subProductId = subProductId;
        this.count = count;
        this.distributionAhead = distributionAhead;
        this.manufactureAhead = manufactureAhead;
    }
public MakeUp(){}
    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public Long getProductId() {
        return productId;
    }

    public void setProductId(Long productId) {
        this.productId = productId;
    }

    public Long getSubProductId() {
        return subProductId;
    }

    public void setSubProductId(Long subProductId) {
        this.subProductId = subProductId;
    }

    public Integer getCount() {
        return count;
    }

    public void setCount(Integer count) {
        this.count = count;
    }

    public Long getDistributionAhead() {
        return distributionAhead;
    }

    public void setDistributionAhead(Long distributionAhead) {
        this.distributionAhead = distributionAhead;
    }

    public Long getManufactureAhead() {
        return manufactureAhead;
    }

    public void setManufactureAhead(Long manufactureAhead) {
        this.manufactureAhead = manufactureAhead;
    }
}
