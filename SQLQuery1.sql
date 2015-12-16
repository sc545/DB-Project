create database HugCoffe;
drop database HugCoffe
use HugCoffe
use master 
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
order_id int primary key,
order_date date not null,
order_used_point int not null default 0,
order_price int not null default 0,
order_save_point int not null default 0,
cus_id int
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
bev_id int,
bev_size int not null default 1 check(bev_size>=-1 and bev_size<3),
bev_hot_ice int not null default 0 check(bev_hot_ice>=-1 and bev_hot_ice<2),
bev_price int
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
side_id int,
side_price int
);

create table tblGoods
(
goods_id int primary key identity(1, 1),
goods_name varchar(20) not null,
goods_num int not null
);

create table tblSales
(
sales_date date,
sales_total int not null,
sales_num int not null
);

select * from tblOrder
select * from tblSales

insert into tblSales
select order_date, SUM(order_price) as order_price, COUNT(order_id) as order_id from tblOrder where order_date = '2015-12-17'
group by order_date

UPDATE dbo.tblSales SET sales_date = order_date from tblOrder where order_date = '2015-12-17', sales_total = (SELECT SUM(order_price) as order_price from tblOrder where order_date = '2015-12-17'), sales_num = (SELECT COUNT(order_id) as order_id from tblOrder where order_date = '2015-12-17' 
UPDATE dbo.tblSales SET sales_date = '2015-12-17', sales_total = 1, sales_num = 1 WHERE sales_date = '2015-12-17'
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
(1, 'À¯¿ø»ó'),
(2, '±èÀÎÅÂ');
select * from student

create view stu_view
as
select * from student

select * from stu_view

insert into stu_view
values
(3, '±è¿µ¹Î');

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
select o.order_id, bev_name, bev_size, bev_hot_ice, side_name, order_date, order_used_point, order_price, order_save_point, order_date, cus_id  from tblOrder o inner join (select ob.order_id, bev_name, bev_size, bev_hot_ice, side_name from  view_Order_Beverage ob inner join view_Order_Side os ON ob.order_id = os.order_id) obs
ON o.order_id = obs.order_id;

DELETE FROM dbo.tblOrder WHERE order_id = 1

select * from tblOrder

select * from tblOrder_Beverage

select * from tblOrder_Side

select * from view_order_Beverage

select * from view_order_Side

select ob.order_id, bev_name, bev_size, bev_hot_ice, side_name from  view_Order_Beverage ob inner join view_Order_Side os ON ob.order_id = os.order_id


create view view_order
as
select o.order_id, bev_id, bev_size, bev_hot_ice, side_id, order_used_point, order_price, order_save_point, order_date, cus_id  from tblOrder o inner join (select ob.order_id, bev_id, bev_size, bev_hot_ice, side_id from  tblOrder_Beverage ob inner join tblOrder_Side os ON ob.order_id = os.order_id) obs
ON o.order_id = obs.order_id
group by o.order_id


select ob.order_id, bev_id, bev_size, bev_hot_ice, side_id from  tblOrder_Beverage ob inner join tblOrder_Side os ON ob.order_id = os.order_id


select * from view_order

delete from tblOrder_Side

update tblOrder_Side
set order_id = 2;

INSERT INTO dbo.tblOrder VALUES (1, '1993-12-01', 0, 1000, 100, 1)

select * from tblOrder;

update tblCustomer
set cus_point = 10000
where cus_id = 1;

SELECT * FROM dbo.tblOrder WHERE m_order_id = 1

UPDATE dbo.tblOrder SET order_date = '2012-11-22', order_used_point = 0, order_price = 0, order_save_point = 0, cus_id = 0 WHERE order_id = 4

UPDATE dbo.tblOrder_Beverage SET bev_id = 1, bev_size = 1, bev_hot_ice = 1, bev_price = 0 WHERE order_id = 4