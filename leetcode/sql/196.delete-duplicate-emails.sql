# Write your MySQL query statement below
# 这里使用一张临时表保存数据
# 否则会报错 You can't specify target table 'Person' for update in FROM clause

DELETE
FROM Person
WHERE Id NOT IN 
    (SELECT t.minid 
        FROM (
            SELECT MIN(Id) minid FROM Person GROUP BY Email)
            as t);
