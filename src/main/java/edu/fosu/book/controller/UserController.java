package edu.fosu.book.controller;

import edu.fosu.book.entity.User;
import edu.fosu.book.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/user")
public class UserController {

    @Autowired
    private UserService userService;

    @GetMapping("/{id}")
    public ResponseEntity<User> getUserById(@PathVariable String id) {
        User user = userService.selectByPrimaryKey(id);
        if (user != null) {
            return ResponseEntity.ok(user);
        } else {
            return ResponseEntity.notFound().build();
        }
    }

    @GetMapping
    public ResponseEntity<List<User>> getAllUsers() {
        List<User> users = userService.getAllUsers();
        if (users != null) {
            return ResponseEntity.ok(users);
        } else {
            return ResponseEntity.notFound().build();
        }
    }

    @PostMapping
    public ResponseEntity<User> insertUser(@RequestBody User user) {
        User savedUser = userService.insertUser(user);
        return ResponseEntity.status(HttpStatus.CREATED).body(savedUser);
    }

    @PutMapping("/{id}")
    public ResponseEntity<User> updateUserById(@PathVariable String id, @RequestBody User user) {
        if (!id.equals(user.getUserid())) {
            return ResponseEntity.badRequest().build();
        }

        User existingUser = userService.selectByPrimaryKey(id);
        if (existingUser != null) {
            User updatedUser = userService.updateByPrimaryKey(user);
            return ResponseEntity.ok(updatedUser);
        } else {
            return ResponseEntity.notFound().build();
        }
    }

    @DeleteMapping("/{id}")
    public ResponseEntity<User> deleteUserById(@PathVariable String id) {
        User existingUser = userService.selectByPrimaryKey(id);
        if (existingUser != null) {
            userService.deleteByPrimaryKey(id);
            return ResponseEntity.noContent().build();
        } else {
            return ResponseEntity.notFound().build();
        }
    }
}
