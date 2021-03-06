/*
URL：https://leetcode.com/problems/second-highest-salary/

Write a SQL query to get the second highest salary from the Employee table.

+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
For example, given the above Employee table, the second highest salary is 200. If there is no second highest salary, then the query should return null.

 */
 
DROP TABLE IF EXISTS Employee;
CREATE TABLE Employee (
Id INT NOT NULL AUTO_INCREMENT,
Salary INT NOT NULL, 
PRIMARY KEY (Id) 
 );
 
INSERT INTO Employee(Salary) VALUES (100),(200),(300);
 
SELECT * FROM Employee;


/*Solution1:  559ms. You are here! 
 Your runtime beats 98.76 % of mysql submissions.*/
SELECT MAX(Salary) AS SecondhighestSalary FROM Employee
WHERE Salary < ( SELECT MAX(Salary) FROM Employee);
 

/*Solution2:  891ms.*/ 
SELECT (SELECT MAX(Salary) FROM Employee WHERE Salary NOT IN 
(SELECT MAX(Salary) FROM Employee)) AS SecondhighestSalary;

/*Solution3: */
SELECT MAX(Salary) AS SecondhighestSalary FROM Employee
WHERE Salary NOT IN ( SELECT MAX(Salary) FROM Employee); 










