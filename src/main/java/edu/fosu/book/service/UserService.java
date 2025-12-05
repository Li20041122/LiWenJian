package edu.fosu.book.service;

import edu.fosu.book.entity.User;

import java.util.List;

public interface UserService {
    User selectByPrimaryKey(String id);

    List<User> getAllUsers();

    User insertUser(User user);

    User updateByPrimaryKey(User user);

    void deleteByPrimaryKey(String id);
}
