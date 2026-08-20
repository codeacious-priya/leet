# Write your MySQL query statement below
with tt as (
   select person_name,weight,turn,sum(weight) over (order by turn) as t
    from Queue q 
    order by q.turn asc
)
select person_name from tt where tt.t<=1000 order by turn desc limit 1;
