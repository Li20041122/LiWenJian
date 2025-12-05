package edu.fosu.book.entity;

import java.math.BigDecimal;
import java.util.Date;

public class Book {
    private String bookid;

    private String bookname;

    private String authors;

    private String publication;

    private Date publicdate;

    private BigDecimal price;

    public String getBookid() {
        return bookid;
    }

    public void setBookid(String bookid) {
        this.bookid = bookid == null ? null : bookid.trim();
    }

    public String getBookname() {
        return bookname;
    }

    public void setBookname(String bookname) {
        this.bookname = bookname == null ? null : bookname.trim();
    }

    public String getAuthors() {
        return authors;
    }

    public void setAuthors(String authors) {
        this.authors = authors == null ? null : authors.trim();
    }

    public String getPublication() {
        return publication;
    }

    public void setPublication(String publication) {
        this.publication = publication == null ? null : publication.trim();
    }

    public Date getPublicdate() {
        return publicdate;
    }

    public void setPublicdate(Date publicdate) {
        this.publicdate = publicdate;
    }

    public BigDecimal getPrice() {
        return price;
    }

    public void setPrice(BigDecimal price) {
        this.price = price;
    }
}