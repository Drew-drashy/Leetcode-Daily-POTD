# Write your MySQL query statement below
with tb as (
    select person_name,sum(weight) over (order by turn ) as kio from queue
)

select person_name from tb where kio<=1000
order by kio desc limit 1;

