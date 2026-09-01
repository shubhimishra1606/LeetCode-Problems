# Write your MySQL query statement below
select class
from (select class, count(student) as strength
      from courses
      group by class) as class_wise_strength
where strength>=5;