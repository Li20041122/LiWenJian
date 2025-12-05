package edu.fosu.book.service.impl;

import edu.fosu.book.dao.BorrowMapper;
import edu.fosu.book.entity.Borrow;
import edu.fosu.book.service.BorrowService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class BorrowServiceImpl implements BorrowService {
    @Autowired
    BorrowMapper borrowMapper;

    @Override
    public Borrow selectByPrimaryKey(String userid, String bookid) {
        return borrowMapper.selectByPrimaryKey(userid, bookid);
    }

    @Override
    public List<Borrow> getAllBorrows() {
        return borrowMapper.selectAll();
    }

    @Override
    public Borrow insertBorrow(Borrow borrow) {
        int ret = borrowMapper.insert(borrow);
        if(ret == 0)
            return borrow;
        else
            return null;
    }

    @Override
    public Borrow updateByPrimaryKey(Borrow borrow) {
        int ret = borrowMapper.updateByPrimaryKey(borrow);
        if(ret == 0)
            return borrow;
        else
            return null;
    }

    @Override
    public void deleteByPrimaryKey(String userid, String bookid) {
        borrowMapper.deleteByPrimaryKey(userid, bookid);
    }
}
