package xyz.zinglix.mps;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;

public interface MakeUpRepository extends JpaRepository<MakeUp,Long> {
    List<MakeUp> findByProductId(Long id);
}
