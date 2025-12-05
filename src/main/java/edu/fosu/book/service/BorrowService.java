package edu.fosu.book.service;

import edu.fosu.book.entity.Borrow;

import java.util.List;

public interface BorrowService {
    Borrow selectByPrimaryKey(String userid, String bookid);

    List<Borrow> getAllBorrows();

    Borrow insertBorrow(Borrow borrow);

    Borrow updateByPrimaryKey(Borrow borrow);

    void deleteByPrimaryKey(String userid, String bookid);
}
