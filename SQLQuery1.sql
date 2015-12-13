create database HugCoffe;

use HugCoffe

create table admin
(
id varchar(20) constraint id unique,
pass varchar(20)
);

insert into admin
values
('admin', 'admin');

select * from admin;


create table tblCustomer
(
cus_id int primary key identity(1, 1),
cus_name varchar(20) not null,
cus_phone char(13) not null,
cus_point int default 0
);

create table tblOrder
(
order_id int primary key identity(1, 1),
order_date date not null,
order_price int not null,
cus_id int constraint fk_cus_id_tblorder foreign key (cus_id) references tblCustomer(cus_id)
);

create table tblBeverage
(
bev_id int primary key identity(1, 1),
bev_name varchar(20) not null,
bev_price int not null
);

create table tblOrder_Beverage
(
order_id int constraint fk_order_id_tblorder_beverage foreign key (order_id) references tblOrder(order_id),
bev_id int constraint fk_bev_id_tblorder_beverage foreign key (bev_id) references tblBeverage(bev_id),
bev_size int not null default 1 check(bev_size>=0 and bev_size<3),
bev_hot_ice int not null default 0 check(bev_hot_ice>=0 and bev_hot_ice<2),
bev_num int not null
);

create table tblSide
(
side_id int primary key identity(1, 1),
side_name varchar(20) not null,
side_price int not null
);

create table tblOrder_Side
(
order_id int constraint fk_order_id_tblorder_side foreign key (order_id) references tblOrder(order_id),
side_id int constraint fk_side_id_tblorder_side foreign key (side_id) references tblSide(side_id),
side_num int not null
);

create table tblSales
(
sales_date date primary key,
sales_total int not null,
sales_num int not null
);

create table tblGoods
(
goods_id int primary key identity(1, 1),
goods_name varchar(20) not null,
goods_num int not null
);


select * from tblCustomer

select * from tblBeverage;
select * from tblSide;

delete from tblCustomer

insert into tblCustomer
(cus_name, cus_phone)
values
('123', '123');


UPDATE dbo.tblCustomer SET cus_name = 1, cus_phone = 1 WHERE cus_id = 31

DELETE FROM dbo.tblCustomer WHERE cus_id = 31