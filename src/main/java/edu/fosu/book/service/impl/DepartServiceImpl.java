package edu.fosu.book.service.impl;

import edu.fosu.book.dao.DepartMapper;
import edu.fosu.book.entity.Depart;
import edu.fosu.book.service.DepartService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class DepartServiceImpl implements DepartService {
    @Autowired
    DepartMapper departMapper;

    @Override
    public Depart selectByPrimaryKey(String id) {
        return departMapper.selectByPrimaryKey(id);
    }

    @Override
    public List<Depart> getAllDeparts() {
        return departMapper.selectAll();
    }

    @Override
    public Depart insertDepart(Depart depart) {
        int ret = departMapper.insert(depart);
        if(ret == 0)
            return depart;
        else
            return null;
    }

    @Override
    public Depart updateByPrimaryKey(Depart depart) {
        int ret = departMapper.updateByPrimaryKey(depart);
        if(ret == 0)
            return depart;
        else
            return null;
    }

    @Override
    public void deleteByPrimaryKey(String id) {
        departMapper.deleteByPrimaryKey(id);
    }
}
