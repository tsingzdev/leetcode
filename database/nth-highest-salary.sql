/*https://leetcode.com/problems/nth-highest-salary/#/description*/
/*
Write a SQL query to get the nth highest salary from the Employee table.

+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
For example, given the above Employee table, the nth highest salary where n = 2 is 200. If there is no nth highest salary, then the query should return null.

+------------------------+
| getNthHighestSalary(2) |
+------------------------+
| 200                    |
+------------------------+
 
 */
DROP TABLE IF EXISTS Employee;
CREATE TABLE Employee (
        Id INT NOT NULL AUTO_INCREMENT,
        Salary INT NOT NULL,
        PRIMARY KEY (Id)
);

INSERT INTO Employee(Salary) VALUES (100),(200),(300);

SELECT * FROM Employee;

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
                # Write your MySQL query statement below.
		SELECT MAX(Salary) 
            FROM Employee Emp1
            WHERE (N-1) = ( 
                 SELECT COUNT(DISTINCT(Emp2.Salary))
                        FROM Employee Emp2
                        WHERE Emp2.Salary > Emp1.Salary)
                
            );
END
