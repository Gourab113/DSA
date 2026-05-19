
select productName, price,
case
   when price > 0 then "price > 0"
   when price < 0 then "price < 0"
   else "price = 0"
end as 'price_condition';


select customerName, city, countrye
from customers
order by
(
  case
     when city is null then country
     else city
  end
);