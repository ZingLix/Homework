package xyz.zinglix.mps;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;

import java.util.List;



public interface InventoryRepository extends JpaRepository<Inventory,Long> {

    @Query("SELECT new xyz.zinglix.mps.MaterialInventoryInfo(m, i) from Material m, Inventory i Where m.id=i.id")
    public List<MaterialInventoryInfo> findMaterialInventoryInfo();
}