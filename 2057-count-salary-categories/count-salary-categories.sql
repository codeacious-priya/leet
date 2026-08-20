SELECT
    'Low Salary' As category
    ,COUNT(CASE WHEN income<20000 THEN 1  end) AS accounts_count
FROM accounts
union all
select 
  'Average Salary' As category
  ,count(case when income between 20000 and 50000 then 1  end) as accounts_count
  from accounts

  union all
  select 
     'High Salary' As category 
     ,count(case when income>50000 then 1  end) as accounts_count
     from accounts