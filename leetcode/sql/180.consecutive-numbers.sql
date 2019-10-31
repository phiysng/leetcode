# Write your MySQL query statement below

SELECT DISTINCT l1.Num ConsecutiveNums 
FROM 
Logs l1,
Logs l2,
Logs l3
WHERE
l1.Id = l2.Id-1
AND l2.Id = l3.Id-1
AND L1.Num = L2.Num
AND L2.Num = L3.Num;
