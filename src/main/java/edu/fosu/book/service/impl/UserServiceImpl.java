package edu.fosu.book.service.impl;

import edu.fosu.book.dao.UserMapper;
import edu.fosu.book.entity.User;
import edu.fosu.book.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class UserServiceImpl implements UserService {
    @Autowired
    UserMapper userMapper;

    @Override
    public User selectByPrimaryKey(String id) {
        return userMapper.selectByPrimaryKey(id);
    }

    @Override
    public List<User> getAllUsers() {
        return userMapper.selectAll();
    }

    @Override
    public User insertUser(User user) {
        int ret = userMapper.insert(user);
        if(ret == 0)
            return user;
        else
            return null;
    }

    @Override
    public User updateByPrimaryKey(User user) {
        int ret = userMapper.updateByPrimaryKey(user);
        if(ret == 0)
            return user;
        else
            return null;
    }

    @Override
    public void deleteByPrimaryKey(String id) {
        userMapper.deleteByPrimaryKey(id);
    }
}
