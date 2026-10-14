# Write your MySQL query statement below
select person_name
from(
    select person_name ,
    sum(weight) over (order by turn) as cum_wt
    from Queue
) as q

where cum_wt <= 1000
order by cum_wt DESC
limit 1;
