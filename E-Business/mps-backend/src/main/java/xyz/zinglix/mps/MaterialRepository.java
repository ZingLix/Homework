package xyz.zinglix.mps;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;
import java.util.Optional;

public interface MaterialRepository extends JpaRepository<Material,Long> {

    Optional<Material> findById(Long id);
}
