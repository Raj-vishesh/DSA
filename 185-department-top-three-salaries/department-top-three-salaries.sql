# Write your MySQL query statement below
with RankedEmployees as (
    select 
        e.name as Employee,
        e.salary as Salary,
        d.name as department,
        DENSE_RANK() over (
            partition by e.departmentId
            order by e.salary DESC
        ) as rnk

    FROM Employee e
    join Department d
    on e.departmentId = d.id

)

select Department , Employee, Salary 
from RankedEmployees
where rnk <= 3;