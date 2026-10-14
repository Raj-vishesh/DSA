# Write your MySQL query statement below
(
select name as results
from Users 
join  MovieRating
    on Users.user_id = MovieRating.user_id 
group by Users.user_id , Users.name
order by count(*)  DESC , Users.name ASC
limit 1

)


union all

(

select title  as results
from Movies
join MovieRating 
    on Movies.movie_id = MovieRating.movie_id   
where MovieRating.created_at >= '2020-02-01'
and  MovieRating.created_at < '2020-03-01'

group by Movies.movie_id , Movies.title
order by AVG(Movierating.rating) DESC , Movies.title ASC
limit 1

)