with cte as(
    select Employee.* , dense_rank() over (order by salary desc) as drnk from Employee
)

select  COALESCE(
        MAX(CASE WHEN drnk = 2 THEN salary END), 
        NULL
    ) AS SecondHighestSalary  from cte;