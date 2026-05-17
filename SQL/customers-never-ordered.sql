-- customers who never make an order
-- don't use distinct here, because different person name can be same


select name  as 'Customers'      
from Customers
where not exists (
  select *
  from Orders
  where Orders.customerId = Customers.id
);