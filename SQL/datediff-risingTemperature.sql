-- datediff used to calculate difference between two date

-- leetcode 197. Rising Temperature

-- today temperature is greater than the previous date temperature then take that id  

select w1.id as 'id'
from Weather w1
where w1.temperature > 
(
    select w2.temperature
    from Weather w2
    where datediff(w1.recordDate, w2.recordDate) = 1
);