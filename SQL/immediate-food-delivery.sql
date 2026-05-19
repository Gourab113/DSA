
-- can use multiple column name in where in function


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

