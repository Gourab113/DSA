-- /1. get distinct values from a table

select distinct city, address
from student;

-- 2. get 5 data 3 to 8, specific column or * for all column

select  name, address
from student
limit 5 offset 2;

-- 2. Select based on conditions, using Where
-- Use single coutation for string

select * 
from customers
where city = 'Germany'; 

--  customer Id 5 theke beshi hole tader show korbo
SELECT *
FROM Customers
where CustomerId > 5; 

-- operator , =, <=, >=, <> not equal, between, in, like
SELECT count(price)
FROM Products
where price >= 18;  --price 17 theke boro product count

-- between a and b : values btween a and b, a and b included
SELECT * FROM Products
where price between 15 and 20;

SELECT * FROM Products
where ProductName between 'a'and 'cc';

-- In is used to select column value present or not
select * from customers
where CustomerId in (1,2,3);

select * from customers
where Country in ('Mexico', 'Germany');


--multiple conditions, using and, %, _
--City have character c and country starts with G and address have 2nd character a
  
SELECT * FROM Customers
where city like '%C%' and country like 'G%' and address like '_a%';

-- Count() used to count the number of rows

select count(distinct city)
from customers;


-- OrderBy used to sort the result in asending or descending order
-- First sort descending by category id then sort by supplier id

SELECT *
FROM Products
order by categoryId desc, SupplierId desc
limit 10;

-- And , or for where condition
SELECT * FROM Customers
where (CustomerName like 'A%' or CustomerName like 'B%')
and city in ('Berlin', 'Madrid', 'London');


-- NOT, operator can be used with other operators
-- Not like, not between, not in, not exists

SELECT * FROM Customers
where Country not in ('Germany', 'Mexico')
and CustomerId not between 1 and 80
and CustomerName not like 'W%';

-- IS NULL, IS NOT NULL , get null values

SELECT *
FROM Customers
WHERE Address IS NULL;


-- UPDATE data
update customers
set country = 'Bangladesh', city = 'Dhaka'
where id = 1;


-- Delete data
delete from customers
where id = 1;

-- Delete table:
drop table customers;

-- Aggrigate functions min, max, count, sum, average

select avg(Price) as avg_price, min(price) as min_price, count(distinct price) as total_count,
max(Price) as max_price, sum(Price) as total_price
from products
where SupplierId in (1,2);

-- JOIN ***
-- Join returns only matching values of both
-- left join, returns all the row of the left table and matched row from right table
-- right join, returns all row from right table and matched row from left table
-- full join, returns all rows

select customers.CustomerId,customers.CustomerName, Customers.City
from customers
join orders
on customers.CustomerId = orders.CustomerId;

-- left join, select all customers but orders tabledata can be null if not found
select customers.CustomerId, orders.EmployeeId 
from customers
left join orders
on customers.CustomerId = orders.CustomerId
order by customers.CustomerId desc;

-- right join, take all rows from right table and matched row from left table

select orders.CustomerId, orders.OrderId, employees.EmployeeId
from orders
right join Employees
on orders.EmployeeId = Employees.EmployeeId
order by orders.CustomerId;

-- Not IN
-- All customers that don't order
select * 
from customers
where CustomerId not in (
  select CustomerId from orders
);


-- get second height salary of employee **

select max(salary) as SecondHighestSalary 
from Employee
where salary < (
    select max(salary)
    from Employee
);

-- Limit and Offset
-- Limit tells how many rows to return 
-- offset tells how many rows skips from top

-- skip the first 4 row then 10 row returns
select *
from employee
limit 10 offset 4;

-- alias give short name using as
Select O.customerId as Id
from orders as O
join customers as C
on o.customerId = c.customerId;

-- Union , combine two same select result, remove duplicate row
SELECT City from Customers
union 
select City from Suppliers;

-- union all, used to combine results of select statement, contains duplicate rows
SELECT City from Customers
union all
select City from Suppliers;

-- Group By, used to group rows that have same values
-- it is used with aggregate functions
-- each city, how many customer
select count(CustomerId) as 'total customer', City
from Customers
group by City;


-- how many orders for each shipper
select count(O.OrderID) as total_order, S.ShipperID 
from Orders as O
join Shippers as S
on O.ShipperID= S.ShipperID
group by S.ShipperId;

-- Having: used to apply filter on aggrigates after group by performed
-- Get city lists where customers count is atleast 2

from Customers
group by City
having count(CustomerId) > 2
order by count(CustomerId) desc
limit 3 offset 2;

-- Exists: used in where, check any subquery returns atleast one row
-- false otherwise
-- outside table can access from inside
select SupplierName from Suppliers
where exists(
   select ProductID
   from Products
   where Products.SupplierID = Suppliers.SupplierID and Price < 20
);


-- Datediff(date1, date2) it returns result (date1 - date2)
-- Datediff used to calculate difference between dates

SELECT DATEDIFF("2017-06-25", "2017-06-15");
-- result 10


-- round a value to decimal point use round
-- round(4.55555,2) gives 2 decimal values after point
select machine_id, round(avg(time), 3) as 'processing_time'
from
(select (b.timestamp - a.timestamp) as 'time', a.machine_id as 'machine_id',
a.process_id as 'process_id'
from Activity a
join Activity b
on a.machine_id= b.machine_id and 
a.process_id = b.process_id
where a.activity_type = 'start' and 
b.activity_type = 'end') as temp
group by machine_id;

-- length(value) is used to find the length of a string


--coalesce() : return the first not null or not undefined value
-- coalesce(null, 2): return 2, 0/0 is null

-- can use alias inside group by


select r.contest_id, round((count(r.user_id)*100 / 
      ( select count(u.user_id) 
       from Users u)
       ), 2)as 'percentage'
from Register  r
group by r.contest_id
order by percentage desc,  r.contest_id asc;


-- string functions

-- concat(a,b,c) : concat is used to add multiple string column
-- insert(current, start, length, replaced_value) : 1 based indexing, replace character
-- substr(string, start, length) : start position : 1 2 3  from left and   -3 -2 -1 from right
-- substr is used to get the specific value from string from start to length

-- case 

-- can check multiple values in where in
=

select round(( (
    select count(*)
    from Delivery
    where (customer_id, order_date) in (
        select customer_id, min(order_date) as 'order_date'
        from Delivery 
        group by customer_id
    ) and datediff(customer_pref_delivery_date, order_date  ) =0
)* 100 /count(*) ), 2) as 'immediate_percentage'
from Delivery
where (customer_id, order_date) in (
    select customer_id, min(order_date) as 'order_date'
    from Delivery 
    group by customer_id
);


--limit does not give null value, but max(), min() gives null when value not found
-- bigest single number
select max(num) as 'num'
from MyNumbers
where num in (
    select num
    from MyNumbers
    group by num
    having count(num) = 1
);