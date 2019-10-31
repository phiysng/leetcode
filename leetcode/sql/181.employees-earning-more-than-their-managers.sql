# Write your MySQL query statement below

SELECT Name Employee
FROM Employee e
WHERE ManagerId IS NOT NULL
    AND Salary > 
    (SELECT (Salary) 
        FROM Employee 
            WHERE id = e.ManagerId);
  
SELECT a.Name as Employee
FROM Employee a
    JOIN Employee E 
    ON a.ManagerId = E.Id AND a.Salary > E.Salary;