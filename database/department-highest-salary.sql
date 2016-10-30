/* url: https://leetcode.com/problems/department-highest-salary/

The Employee table holds all employees. Every employee has an Id, a salary, and there
 is also a column for the department Id.

+----+-------+--------+--------------+
| Id | Name  | Salary | DepartmentId |
+----+-------+--------+--------------+
| 1  | Joe   | 70000  | 1            |
| 2  | Henry | 80000  | 2            |
| 3  | Sam   | 60000  | 2            |
| 4  | Max   | 90000  | 1   
  5    Amy   | 90000    1
+----+-------+--------+--------------+
The Department table holds all departments of the company.

+----+----------+
| Id | Name     |
+----+----------+
| 1  | IT       |
| 2  | Sales    
+----+----------+
Write a SQL query to find employees who have the highest salary in each of the departments. 
For the above tables, Max has the highest salary in the IT department and Henry has the 
highest salary in the Sales department.

+------------+----------+--------+
| Department | Employee | Salary |
+------------+----------+--------+
| IT         | Max      | 90000  |
| Sales      | Henry    | 80000  |
+------------+----------+--------+

*/
DROP TABLE IF EXISTS Employee; 

CREATE TABLE IF NOT EXISTS Employee (
	Id INT NOT NULL,
	Name VARCHAR(200),
	Salary INT,
	DepartmentId INT(11)
);

INSERT INTO Employee VALUES('1', 'Joe', '70000', '1');
INSERT INTO Employee VALUES('2', 'Henry', '80000', '2');
INSERT INTO Employee VALUES('3', 'Sam', '60000', '2');
INSERT INTO Employee VALUES('4', 'Max', '90000', '1');
INSERT INTO Employee VALUES('5', 'Amy', '90000', '1');


CREATE TABLE IF NOT EXISTS Department (
	Id INT,
	Name VARCHAR(200)
);

INSERT INTO Department VALUES('1', 'IT' );
INSERT INTO Department VALUES('2', 'Sales');

SELECT * FROM  Employee;
SELECT * FROM Department;


/*--------BEGIN QUERY-----------*/


/*WRONG ANSWER */
SELECT B.Name AS Department, A.Name AS Employee, C.Salary   
FROM Employee AS A, Department AS B,  (
SELECT DepartmentId, MAX(Salary) AS Salary FROM Employee GROUP BY DepartmentId) AS C
WHERE  C.Salary = A.Salary and B.Id = C.DepartmentId;


/*You are here! 
Your runtime beats 62.75% of mysql submissions.*/
SELECT B.Name AS Department, A.Name AS Employee, C.Salary   
FROM Employee AS A, Department AS B,  (
SELECT DepartmentId, MAX(Salary) AS Salary FROM Employee GROUP BY DepartmentId) AS C
WHERE  C.Salary = A.Salary and B.Id = C.DepartmentId 
and A.DepartmentId = C.DepartmentId; -- Also this











