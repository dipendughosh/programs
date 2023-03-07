/*create table ROOMS(ROOM_NO varchar(5) primary key ,AC_NONAC integer, NO_OF_BEDS integer)*/
/*create table RESERVATION(RS_ID varchar(5) primary key, DT_OF_CHECKIN date, DT_OF_CHECKOUT date, ROOM_NO varchar(5), foreign key(ROOM_NO) references ROOMS(ROOM_NO))*/
/*create table CUSTOMER( CUST_ID varchar(5) , NAME varchar(50), ADDRESS varchar(50), RS_ID varchar(5), Foreign key(RS_ID) references RESERVATION(RS_ID))*/
alter table ROOMS add reserved integer