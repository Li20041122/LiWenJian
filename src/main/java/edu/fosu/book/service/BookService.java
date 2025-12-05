package edu.fosu.book.service;

import edu.fosu.book.entity.Book;

import java.util.List;

public interface BookService {
    Book selectByPrimaryKey(String id);

    List<Book> getAllBooks();

    Book insertBook(Book book);

    Book updateByPrimaryKey(Book book);

    void deleteByPrimaryKey(String id);
}
