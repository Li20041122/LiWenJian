package edu.fosu.book.controller;

import edu.fosu.book.entity.Depart;
import edu.fosu.book.service.DepartService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/depart")
public class DepartController {

    @Autowired
    private DepartService departService;

    @GetMapping("/{id}")
    public ResponseEntity<Depart> getDepartById(@PathVariable String id) {
        Depart depart = departService.selectByPrimaryKey(id);
        if (depart != null) {
            return ResponseEntity.ok(depart);
        } else {
            return ResponseEntity.notFound().build();
        }
    }

    @GetMapping
    public ResponseEntity<List<Depart>> getAllDeparts() {
        List<Depart> departs = departService.getAllDeparts();
        if (departs != null) {
            return ResponseEntity.ok(departs);
        } else {
            return ResponseEntity.notFound().build();
        }
    }

    @PostMapping
    public ResponseEntity<Depart> insertDepart(@RequestBody Depart depart) {
        Depart savedDepart = departService.insertDepart(depart);
        return ResponseEntity.status(HttpStatus.CREATED).body(savedDepart);
    }

    @PutMapping("/{id}")
    public ResponseEntity<Depart> updateDepartById(@PathVariable String id, @RequestBody Depart depart) {
        if (!id.equals(depart.getDepartid())) {
            return ResponseEntity.badRequest().build();
        }

        Depart existingDepart = departService.selectByPrimaryKey(id);
        if (existingDepart != null) {
            Depart updatedDepart = departService.updateByPrimaryKey(depart);
            return ResponseEntity.ok(updatedDepart);
        } else {
            return ResponseEntity.notFound().build();
        }
    }

    @DeleteMapping("/{id}")
    public ResponseEntity<Depart> deleteDepartById(@PathVariable String id) {
        Depart existingDepart = departService.selectByPrimaryKey(id);
        if (existingDepart != null) {
            departService.deleteByPrimaryKey(id);
            return ResponseEntity.noContent().build();
        } else {
            return ResponseEntity.notFound().build();
        }
    }
}
