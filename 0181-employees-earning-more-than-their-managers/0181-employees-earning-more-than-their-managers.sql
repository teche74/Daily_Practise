-- select e2.name as Employee from Employee e1 left join employee e2 on e1.id = e2.managerId where e1.salary < e2.salary;


select name as Employee from employee x where salary > (select salary from Employee where id = x.managerId ) and managerId is not null;