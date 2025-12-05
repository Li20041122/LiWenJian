package edu.fosu.book.entity;

import java.math.BigDecimal;
import java.util.Date;

public class Borrow {
    private String userid;

    private String bookid;

    private Date borrowtime;

    private Date returntime;

    private BigDecimal penalsum;

    private BigDecimal payment;

    public String getUserid() {
        return userid;
    }

    public void setUserid(String userid) {
        this.userid = userid == null ? null : userid.trim();
    }

    public String getBookid() {
        return bookid;
    }

    public void setBookid(String bookid) {
        this.bookid = bookid == null ? null : bookid.trim();
    }

    public Date getBorrowtime() {
        return borrowtime;
    }

    public void setBorrowtime(Date borrowtime) {
        this.borrowtime = borrowtime;
    }

    public Date getReturntime() {
        return returntime;
    }

    public void setReturntime(Date returntime) {
        this.returntime = returntime;
    }

    public BigDecimal getPenalsum() {
        return penalsum;
    }

    public void setPenalsum(BigDecimal penalsum) {
        this.penalsum = penalsum;
    }

    public BigDecimal getPayment() {
        return payment;
    }

    public void setPayment(BigDecimal payment) {
        this.payment = payment;
    }
}