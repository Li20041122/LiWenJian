package edu.fosu.book.controller;

import edu.fosu.book.entity.Borrow;
import edu.fosu.book.service.BorrowService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/borrow")
public class BorrowController {

    @Autowired
    private BorrowService borrowService;

    @GetMapping("/{userid}/{bookid}")
    public ResponseEntity<Borrow> getBorrowByPrimaryKey(@PathVariable String userid, @PathVariable String bookid) {
        Borrow borrow = borrowService.selectByPrimaryKey(userid, bookid);
        if (borrow != null) {
            return ResponseEntity.ok(borrow);
        } else {
            return ResponseEntity.notFound().build();
        }
    }

    @GetMapping
    public ResponseEntity<List<Borrow>> getAllBorrows() {
        List<Borrow> borrows = borrowService.getAllBorrows();
        if (borrows != null) {
            return ResponseEntity.ok(borrows);
        } else {
            return ResponseEntity.notFound().build();
        }
    }

    @PostMapping
    public ResponseEntity<Borrow> insertBorrow(@RequestBody Borrow borrow) {
        Borrow savedBorrow = borrowService.insertBorrow(borrow);
        return ResponseEntity.status(HttpStatus.CREATED).body(savedBorrow);
    }

    @PutMapping("/{userid}/{bookid}")
    public ResponseEntity<Borrow> updateBorrowByPrimaryKey(@PathVariable String userid, @PathVariable String bookid, @RequestBody Borrow borrow) {
        if (!userid.equals(borrow.getUserid()) || !bookid.equals(borrow.getBookid())) {
            return ResponseEntity.badRequest().build();
        }

        Borrow existingBorrow = borrowService.selectByPrimaryKey(userid, bookid);
        if (existingBorrow != null) {
            Borrow updatedBorrow = borrowService.updateByPrimaryKey(borrow);
            return ResponseEntity.ok(updatedBorrow);
        } else {
            return ResponseEntity.notFound().build();
        }
    }

    @DeleteMapping("/{userid}/{bookid}")
    public ResponseEntity<Borrow> deleteBorrowByPrimaryKey(@PathVariable String userid, @PathVariable String bookid) {
        Borrow existingBorrow = borrowService.selectByPrimaryKey(userid, bookid);
        if (existingBorrow != null) {
            borrowService.deleteByPrimaryKey(userid, bookid);
            return ResponseEntity.noContent().build();
        } else {
            return ResponseEntity.notFound().build();
        }
    }
}
