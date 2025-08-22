with cte as(
    select 
    * , dense_rank() over( order by salary desc) as "sal_rank" from Employee
)

select if(count(*) = 0 , null , salary) as SecondHighestSalary from cte where sal_rank = 2;