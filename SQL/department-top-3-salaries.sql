

-- leetcode 185, Department Top Three Salaries

select d1.name as 'Department', e1.name as 'Employee', e1.salary as 'Salary'
from Employee e1
join Department d1
on e1.departmentId = d1.id
where e1.salary in (
    select salary
    from (
        select distinct(e2.salary)
        from Employee e2
        where e2.departmentId = e1.departmentId
        order by e2.salary desc
        limit 3
    ) as temp 
    -- use as a temporary table:  select salary from temp
    -- we can use limit in subquery when we create a table 
);

