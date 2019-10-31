SELECT d.Name Department, e.Name Employee, e.Salary Salary
FROM Employee e
         JOIN Department d ON e.DepartmentId = d.Id
         JOIN (SELECT e.DepartmentId DepartmentId, MAX(Salary) Salary
               FROM (Employee e
                        JOIN Department d ON e.DepartmentId = d.Id)
               GROUP BY d.Name) t ON t.DepartmentId = e.DepartmentId AND e.Salary = t.Salary;
