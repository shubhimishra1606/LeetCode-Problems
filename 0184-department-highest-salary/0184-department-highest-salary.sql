# Write your MySQL query statement below
select d.name as Department, e.name as Employee, e.salary as Salary
from Employee e
inner join Department d
on e.departmentid=d.id
where salary=(select max(e2.salary) from         Employee e2
where e2.departmentid=e.departmentid
               )