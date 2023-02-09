drop database if exists SMS;
create database SMS;
use SMS;
create table login (
    user varchar(20) primary key,
    password varchar(20) not null
);
insert into login values("admin", "111");