/* URL: https://leetcode.com/problems/customers-who-never-order/ */
/* */

/*
+----+-------+
| Id | Name  |
+----+-------+
| 1  | Joe   |
| 2  | Henry |
| 3  | Sam   |
| 4  | Max   |
+----+-------+

+----+------------+
| Id | CustomerId |
+----+------------+
| 1  | 3          |
| 2  | 1          |
+----+------------+
*/


CREATE TABLE Customers (
Id INT,
Name VARCHAR(200)
);
INSERT INTO Customers VALUES ('1', 'Joe');
INSERT INTO Customers VALUES ('2', 'Henry');
INSERT INTO Customers VALUES ('3', 'Sam');
INSERT INTO Customers VALUES ('4', 'Max');

CREATE TABLE Orders (
Id INT,
CustomerId INT
);
INSERT INTO Orders VALUES ('1', '3');
INSERT INTO Orders VALUES ('2', '1');

SELECT * FROM Customers;
SELECT * FROM Orders;


---------------Solution 1: 481 ms
SELECT Name AS Customers FROM Customers 
WHERE Id NOT IN 
(
SELECT CustomerId FROM Orders
);

--------------Solution 2: 464 ms

SELECT Customers.Name AS Customers FROM (Customers LEFT JOIN Orders ON Customers.Id = Orders.CustomerId) WHERE Orders.CustomerId IS NULL





