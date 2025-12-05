package edu.fosu.book.service.impl;

import edu.fosu.book.dao.BookMapper;
import edu.fosu.book.entity.Book;
import edu.fosu.book.service.BookService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class BookServiceImpl implements BookService {
    @Autowired
    BookMapper bookMapper;

    @Override
    public Book selectByPrimaryKey(String id) {
        return bookMapper.selectByPrimaryKey(id);
    }

    @Override
    public List<Book> getAllBooks() {
        return bookMapper.selectAll();
    }

    @Override
    public Book insertBook(Book book) {
        int ret = bookMapper.insert(book);
        if(ret == 0)
            return book;
        else
            return null;
    }

    @Override
    public Book updateByPrimaryKey(Book book) {
        int ret = bookMapper.updateByPrimaryKey(book);
        if(ret == 0)
            return book;
        else
            return null;
    }

    @Override
    public void deleteByPrimaryKey(String id) {
        bookMapper.deleteByPrimaryKey(id);
    }
}
