-- 1251. Average Selling Price
-- coalesce (a,b) : it returns the first not null or not undefined value


select p.product_id as 'product_id', 
coalesce( round(sum(p.price * u.units )/
sum(u.units), 2 ), 0)    as 'average_price'
from Prices p
left join UnitsSold  u
on p.product_id = u.product_id and u.purchase_date  between p.start_date and
p.end_date 
group by p.product_id;
