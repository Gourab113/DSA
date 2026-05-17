-- Get numbers that have atleast 3 consecutive same number

-- when join we will make a single row from multiple table,
-- then we can compare them, can use multiple join

-- select those number that appears consecutively atleast 3 times

select distinct(l1.num) as ConsecutiveNums
from logs l1
join logs l2 on l1.id +1 = l2.id
join logs l3 on l1.id + 2 = l3.id
where l1.num = l2.num and l1.num = l3.num;

