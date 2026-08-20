SELECT
    'Low Salary' As category
    ,sum(CASE WHEN income<20000 THEN 1 else 0 end) AS accounts_count
FROM accounts
union all
select 
  'Average Salary' As category
  ,sum(case when income between 20000 and 50000 then 1 else 0 end) as accounts_count
  from accounts

  union all
  select 
     'High Salary' As category 
     ,sum(case when income>50000 then 1 else 0 end) as accounts_count
     from accounts