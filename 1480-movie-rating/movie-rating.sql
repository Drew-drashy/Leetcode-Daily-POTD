# Write your MySQL query statement below
# Write your MySQL query statement below
WITH cte AS (SELECT mr.movie_id, mr.user_id, mr.rating, mr.created_at, u.name, m.title
                FROM Users u
                JOIN MovieRating mr ON u.user_id = mr.user_id
                JOIN Movies m ON m.movie_id = mr.movie_id)
(SELECT name AS results
FROM cte
GROUP BY user_id 
ORDER BY COUNT(*) DESC, name ASC
LIMIT 1)

UNION ALL

(SELECT title 
FROM cte
WHERE created_at BETWEEN '2020-02-01' AND '2020-02-29'
GROUP BY movie_id
ORDER BY AVG(rating) DESC, title ASC
LIMIT 1)