# Write your MySQL query statement below
select customer_id, count(visit_id) as count_no_trans
from (select *
from Visits
where visit_id not in(select distinct visit_id 
                       from Transactions)
) as cust_no_trans
group by customer_id