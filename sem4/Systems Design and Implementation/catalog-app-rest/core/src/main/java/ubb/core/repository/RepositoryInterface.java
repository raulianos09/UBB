package ubb.core.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.repository.NoRepositoryBean;
import ubb.core.model.BaseEntity;

import java.io.Serializable;

@NoRepositoryBean
public interface RepositoryInterface<T extends BaseEntity<ID>, ID extends Serializable>
        extends JpaRepository<T, ID> {
}
