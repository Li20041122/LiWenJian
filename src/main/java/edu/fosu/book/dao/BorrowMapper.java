package edu.fosu.book.dao;

import edu.fosu.book.entity.Borrow;
import java.util.List;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

@Mapper
public interface BorrowMapper {
    int deleteByPrimaryKey(@Param("userid") String userid, @Param("bookid") String bookid);

    int insert(Borrow record);

    Borrow selectByPrimaryKey(@Param("userid") String userid, @Param("bookid") String bookid);

    List<Borrow> selectAll();

    int updateByPrimaryKey(Borrow record);
}