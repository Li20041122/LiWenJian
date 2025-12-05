package edu.fosu.book.dao;

import edu.fosu.book.entity.Book;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface BookMapper {
    int deleteByPrimaryKey(String bookid);

    int insert(Book record);

    Book selectByPrimaryKey(String bookid);

    List<Book> selectAll();

    int updateByPrimaryKey(Book record);
}