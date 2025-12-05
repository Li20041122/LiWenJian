package edu.fosu.book.controller;

import edu.fosu.book.entity.Book;
import edu.fosu.book.service.BookService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.autoconfigure.AutoConfiguration;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/book")
public class BookController {

    @Autowired
    private BookService bookService;

    @GetMapping("/{id}")
    public ResponseEntity<Book> getBookById(@PathVariable String id) {
        Book book = bookService.selectByPrimaryKey(id);
        if (book != null) {
            return ResponseEntity.ok(book);
        } else {
            return ResponseEntity.notFound().build();
        }
    }

    @GetMapping
    public ResponseEntity<List<Book>> getAllBooks() {
        List<Book> books = bookService.getAllBooks();
        if (books != null) {
            return ResponseEntity.ok(books);
        } else {
            return ResponseEntity.notFound().build();
        }
    }

    @PostMapping
    public ResponseEntity<Book> insertBook(@RequestBody Book book) {
        Book savedBook = bookService.insertBook(book);
        return ResponseEntity.status(HttpStatus.CREATED).body(savedBook);
    }

    @PutMapping("/{id}")
    public ResponseEntity<Book> updateBookById(@PathVariable String id, @RequestBody Book book) {
        if (!id.equals(book.getBookid())) {
            return ResponseEntity.badRequest().build();
        }

        Book existingBook = bookService.selectByPrimaryKey(id);
        if (existingBook != null) {
            Book updatedBook = bookService.updateByPrimaryKey(book);
            return ResponseEntity.ok(updatedBook);
        } else {
            return ResponseEntity.notFound().build();
        }
    }

    @DeleteMapping("/{id}")
    public ResponseEntity<Book> deleteBookById(@PathVariable String id) {
        Book existingBook = bookService.selectByPrimaryKey(id);
        if (existingBook != null) {
            bookService.deleteByPrimaryKey(id);
            return ResponseEntity.noContent().build();
        } else {
            return ResponseEntity.notFound().build();
        }
    }
}
