with t as (select d.customer_id,min(d.order_date) as x,min(d.customer_pref_delivery_date) as y from delivery d
group by customer_id)

select
ROUND(sum(if(t.x=t.y,1,0)*100.0)/
count(t.customer_id),2)
as immediate_percentage 
from t



