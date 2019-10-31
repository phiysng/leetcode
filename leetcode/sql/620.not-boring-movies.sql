# Write your MySQL query statement below

SELECT id , movie , description , rating 
FROM cinema 
WHERE description !='boring' AND LEFT(id,1) % 2 = 1 
ORDER BY rating DESC;
