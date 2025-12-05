/*==============================================================*/
/* DBMS name:      MySQL 5.0                                    */
/* Created on:     2025/12/2 15:19:07                           */
/*==============================================================*/

-- 创建数据库
CREATE DATABASE IF NOT EXISTS book;

USE book;

drop table if exists Book;

drop table if exists Borrow;

drop table if exists Depart;

drop table if exists TUser;

/*==============================================================*/
/* Table: Book                                                  */
/*==============================================================*/
create table Book
(
   BookID               char(10) not null,
   BookName             varchar(50),
   Authors              varchar(50),
   Publication          varchar(50),
   PublicDate           date,
   Price                numeric(6,2),
   primary key (BookID)
);

/*==============================================================*/
/* Table: Borrow                                                */
/*==============================================================*/
create table Borrow
(
   UserID               char(6) not null,
   BookID               char(10) not null,
   BorrowTime           datetime,
   ReturnTime           datetime,
   PenalSum             numeric(5,2),
   Payment              numeric(5,2),
   primary key (UserID, BookID)
);

/*==============================================================*/
/* Table: Depart                                                */
/*==============================================================*/
create table Depart
(
   DepartID             char(4) not null,
   DepartName           varchar(50),
   ParentDepartID       char(4),
   primary key (DepartID)
);

/*==============================================================*/
/* Table: User                                                  */
/*==============================================================*/
create table TUser
(
   UserID               char(6) not null,
   DepartID             char(4),
   UserName             varchar(20),
   Password             varchar(10),
   PhoneNum             char(11),
   Sex                  char(2),
   primary key (UserID)
);

alter table Borrow add constraint FK_Borrow foreign key (BookID)
      references Book (BookID) on delete restrict on update restrict;

alter table Borrow add constraint FK_Borrow2 foreign key (UserID)
      references TUser (UserID) on delete restrict on update restrict;

alter table Depart add constraint FK_FK_ParentDepartID foreign key (ParentDepartID)
      references Depart (DepartID) on delete restrict on update restrict;

alter table TUser add constraint FK_FK_User_DepartID foreign key (DepartID)
      references Depart (DepartID) on delete restrict on update restrict;

INSERT INTO Book (BookID, BookName, Authors, Publication, PublicDate, Price) VALUES
('TP312C', 'C Primer Plus（第6版）', '[美] Stephen Prata', '人民邮电出版社', '2016-03-01', 99.00),
('TP312J', 'Java核心技术 卷I（第11版）', '[美] Cay S. Horstmann', '机械工业出版社', '2019-06-01', 149.00),
('TP316.7', 'Python编程：从入门到实践', '[美] Eric Matthes', '人民邮电出版社', '2016-07-01', 89.00),
('I247.5', '三体', '刘慈欣', '重庆出版社', '2008-01-01', 23.00),
('I247.57', '活着', '余华', '作家出版社', '1993-05-01', 32.50),
('TP393.0', '深入理解计算机系统（第3版）', '[美] Randal E. Bryant', '机械工业出版社', '2016-11-01', 139.00),
('H15', '百年孤独', '[哥伦比亚] 加西亚·马尔克斯', '南海出版公司', '2011-06-01', 39.50),
('TP311.13', '代码整洁之道', '[美] Robert C. Martin', '人民邮电出版社', '2010-01-01', 59.00),
('K825.37', '人类简史：从动物到上帝', '[以色列] 尤瓦尔·赫拉利', '中信出版社', '2014-11-01', 68.00),
('I247.7', '平凡的世界（全三册）', '路遥', '人民文学出版社', '2004-01-01', 119.40);