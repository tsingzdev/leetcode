/*
URL: https://leetcode.com/problems/delete-duplicate-emails/ 
reference: http://www.cnblogs.com/grandyang/p/5371227.html
https://github.com/int32bit/leetcode/tree/master/database/DeleteDuplicateEmails 


Write a SQL query to delete all duplicate email entries in a table named Person, keeping only
 unique emails based on its smallest Id.

+----+------------------+
| Id | Email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
| 3  | john@example.com |
+----+------------------+
Id is the primary key column for this table.
For example, after running your query, the above Person table should have the following rows:

+----+------------------+
| Id | Email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
+----+------------------+

*/
DROP TABLE Person;
CREATE TABLE Person (
Id  INT NOT NULL AUTO_INCREMENT,
Email varchar(200),
PRIMARY KEY (Id)
); 

Insert into person (Email) VALUES  
('john@example.com'),
('bob@example.com'),
('john@example.com');

SELECT * FROM Person;

SELECT DISTINCT Id,   Email FROM Person
ORDER BY Id;

DROP TABLE IF EXISTS TEMPPERSON; 

/* 1  */
CREATE TABLE IF NOT EXISTS TEMPPERSON
SELECT * FROM Person 
WHERE Email NOT IN
(
SELECT Email FROM person
GROUP BY Email HAVING COUNT(*) >=2
);

INSERT INTO TEMPPERSON
SELECT MIN(Id), Email FROM person 
WHERE Email  IN
(
SELECT Email FROM Person
GROUP BY Email HAVING COUNT(*) >=2
);

SELECT DISTINCT Id, Email FROM TEMPPERSON
ORDER BY Id;

/* 2   1434ms */

delete p1 from Person p1, Person p2 where p1.Email = p2.Email and p1.Id > p2.Id;

SELECT * FROM Person; 

/* 3   1003ms*/
DELETE FROM Person WHERE Id NOT IN
(SELECT Id FROM 
	(SELECT MIN(Id) Id FROM Person GROUP BY Email) p

);

SELECT * FROM Person; 

/* 4 JOIN */
DELETE p2 FROM Person p1 JOIN Person p2 
ON p2.Email = p1.Email WHERE p2.Id > p1.Id;

SELECT * FROM Person; 
