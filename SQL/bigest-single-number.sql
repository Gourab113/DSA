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