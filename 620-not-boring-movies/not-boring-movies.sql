# Write your MySQL query statement below
select c.id , c.movie , c.description , c.rating 
from Cinema c
where c.description != 'boring' and 
id %2 =1 
order by c.rating DESC;