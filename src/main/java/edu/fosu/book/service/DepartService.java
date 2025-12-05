package edu.fosu.book.service;

import edu.fosu.book.entity.Depart;

import java.util.List;

public interface DepartService {
    Depart selectByPrimaryKey(String id);

    List<Depart> getAllDeparts();

    Depart insertDepart(Depart depart);

    Depart updateByPrimaryKey(Depart depart);

    void deleteByPrimaryKey(String id);
}
