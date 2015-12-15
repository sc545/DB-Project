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
cus_point int not null default 0
);

create table tblOrder
(
order_id int primary key identity(1, 1),
order_date date not null,
order_used_point int not null default 0,
order_price int not null default 0,
order_save_point int not null default 0,
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

create table student
(
stu_id int,
stu_name varchar(20)
);

insert into student
values
(1, '유원상'),
(2, '김인태');
select * from student

create view stu_view
as
select * from student

select * from stu_view

insert into stu_view
values
(3, '김영민');

UPDATE dbo.tblCustomer SET cus_point = 10000 WHERE cus_id = 1;

create procedure test
as


create view view_Order_Beverage
as
select order_id, bev_name, bev_size, bev_hot_ice from tblOrder_Beverage ob inner join tblBeverage b
on ob.bev_id = b.bev_id;

create view view_Order_Side
as
select order_id, side_name from tblOrder_Side os inner join tblSide s
on os.side_id = s.side_id;

create procedure usp_order @param int
as
select * from tblOrder o inner join (select ob.order_id, bev_name, bev_size, bev_hot_ice, side_name from  view_Order_Beverage ob inner join view_Order_Side os ON ob.order_id = os.order_id) obs
ON o.order_id = @param;

create view view_order
as
select o.order_id, bev_name, bev_size, bev_hot_ice, side_name, order_date, order_used_point, order_price, order_save_point, cus_id  from tblOrder o inner join (select ob.order_id, bev_name, bev_size, bev_hot_ice, side_name from  view_Order_Beverage ob inner join view_Order_Side os ON ob.order_id = os.order_id) obs
ON o.order_id = obs.order_id;

select * from view_Order_Beverage;
select * from view_order;

select * from tblOrder

insert into tblOrder
(order_date, order_used_point, order_price, order_save_point, cus_id)
values
('20151216', 0, 5000, 500, 1)
select @@IDENTITY

insert into view_order
(bev_name, bev_size, bev_hot_ice, side_name, order_date, order_used_point, order_price, order_save_point, cus_id)
values
('아메리카노', '미디움', 'hot', '-', '20151216', 0, 5000, 500, 1)

select * from tblOrder_Beverage
insert into tblOrder_Beverage
(order_id)
values
(insert into tblOrder
(order_date, order_used_point, order_price, order_save_point, cus_id)
values
('20151216', 0, 5000, 500, 1)
select @@IDENTITY)