# Write your MySQL query statement below

#select e1.customer_id,count(e1.visit_id) as count_no_trans from Visits e1 left join Transactions e2 on e1.visit_id = e2.visit_id where e2.transaction_id is null group by e1.customer_id;

select customer_id,count(visit_id) as count_no_trans 
from Visits where visit_id not in(select visit_id from Transactions) 
group by customer_id;
