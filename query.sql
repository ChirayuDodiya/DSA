--1. Company-wide 3rd Highest Salary
SELECT DISTINCT salary
FROM Employee
ORDER BY salary DESC
LIMIT 1 OFFSET 2;

--2. Company-wide 3rd Highest Salary(with duplicates)
SELECT salary
FROM (
    SELECT salary,
           DENSE_RANK() OVER (ORDER BY salary DESC) AS rnk
    FROM Employee
) t
WHERE rnk = 3;

--3. per department
WITH ranked AS (
    SELECT departmentId,
           salary,
           DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) AS rnk
    FROM Employee
)
SELECT departmentId, salary
FROM ranked
WHERE rnk = 3;

--4.per department 3rd woth duplicates
WITH ranked AS (
    SELECT e.id,
           e.name,
           e.salary,
           e.departmentId,
           DENSE_RANK() OVER (PARTITION BY e.departmentId ORDER BY e.salary DESC) AS rnk
    FROM Employee e
)
SELECT d.name AS Department,
       r.name AS Employee,
       r.salary AS Salary
FROM ranked r
JOIN Department d
  ON r.departmentId = d.id
WHERE r.rnk = 3;
