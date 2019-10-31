SELECT FirstName, LastName, City, State 
FROM Person a LEFT JOIN Address b on  a.PersonId = b.PersonId; 