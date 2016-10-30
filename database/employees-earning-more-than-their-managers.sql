/* URL: https://leetcode.com/problems/employees-earning-more-than-their-managers/

The Employee table holds all employees including their managers. Every employee has an 
Id, and there is also a column for the manager Id.

+----+-------+--------+-----------+
| Id | Name  | Salary | ManagerId |
+----+-------+--------+-----------+
| 1  | Joe   | 70000  | 3         |
| 2  | Henry | 80000  | 4         |
| 3  | Sam   | 60000  | NULL      |
| 4  | Max   | 90000  | NULL      |
+----+-------+--------+-----------+
Given the Employee table, write a SQL query that finds out employees who earn more than
their managers. For the above table, Joe is the only employee who earns more than his manager.

+----------+
| Employee |
+----------+
| Joe      |
+----------+

*/
DROP TABLE IF EXISTS Employee;

CREATE TABLE IF NOT EXISTS Employee (
	Id INT,
	Name VARCHAR(200),
	Salary INT,
	ManagerId INT(11)
);

INSERT INTO Employee VALUES('1', 'Joe', '70000', '3');
INSERT INTO Employee VALUES('2', 'Henry', '80000', '4');
INSERT INTO Employee VALUES('3', 'Sam', '60000', NULL);
INSERT INTO Employee VALUES('4', 'Max', '90000', NULL);

SELECT C.Name AS Employee FROM (
SELECT * FROM Employee AS A
WHERE A.Salary > (
SELECT B.Salary FROM Employee AS B
WHERE A.ManagerId = B.Id 
) 
) AS C;
