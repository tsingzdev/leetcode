/* 
URL: https://leetcode.com/problems/trips-and-users/


The Trips table holds all taxi trips. Each trip has a unique Id, while Client_Id and Driver_Id
are both foreign keys to the Users_Id at the Users table. Status is an ENUM type of
(‘completed’, ‘cancelled_by_driver’, ‘cancelled_by_client’).

+----+-----------+-----------+---------+--------------------+----------+
| Id | Client_Id | Driver_Id | City_Id |        Status      |Request_at|
+----+-----------+-----------+---------+--------------------+----------+
| 1  |     1     |    10     |    1    |     completed      |2013-10-01|
| 2  |     2     |    11     |    1    | cancelled_by_driver|2013-10-01|
| 3  |     3     |    12     |    6    |     completed      |2013-10-01|
| 4  |     4     |    13     |    6    | cancelled_by_client|2013-10-01|
| 5  |     1     |    10     |    1    |     completed      |2013-10-02| 
| 6  |     2     |    11     |    6    |     completed      |2013-10-02|
| 7  |     3     |    12     |    6    |     completed      |2013-10-02|
| 8  |     2     |    12     |    12   |     completed      |2013-10-03|
| 9  |     3     |    10     |    12   |     completed      |2013-10-03|
| 10 |     4     |    13     |    12   | cancelled_by_driver|2013-10-03|
+----+-----------+-----------+---------+--------------------+----------+

The Users table holds all users. Each user has an unique Users_Id, and Role is an ENUM type of 
 (‘client’, ‘driver’, ‘partner’).

+----------+--------+--------+
| Users_Id | Banned |  Role  |
+----------+--------+--------+
|    1     |   No   | client |
|    2     |   Yes  | client |
|    3     |   No   | client |
|    4     |   No   | client |
|    10    |   No   | driver |
|    11    |   No   | driver |
|    12    |   No   | driver |
|    13    |   No   | driver |
+----------+--------+--------+
Write a SQL query to find the cancellation rate of requests made by unbanned clients 
between Oct 1, 2013 and Oct 3, 2013. For the above tables, your SQL query should return 
the following rows with the cancellation rate being rounded to two decimal places.

+------------+-------------------+
|     Day    | Cancellation Rate |
+------------+-------------------+
| 2013-10-01 |       0.33        |
| 2013-10-02 |       0.00        |
| 2013-10-03 |       0.50        |
+------------+-------------------+

*/

/*--------------------------------Create Table ------------------------------*/

DROP TABLE IF EXISTS Trips;

CREATE TABLE Trips (
Id  INT, Client_Id INT, Driver_Id  INT, City_Id  INT, 
Status ENUM('completed', 'cancelled_by_driver', 'cancelled_by_client'),  Request_at  DATE
);

INSERT INTO Trips VALUES ('1', '1', '10', '1', 'completed', '2013-10-01' );
INSERT INTO Trips VALUES ('2', '2', '11', '1', 'cancelled_by_driver', '2013-10-01' );
INSERT INTO Trips VALUES ('3', '3', '12', '6', 'completed', '2013-10-01' );
INSERT INTO Trips VALUES ('4', '4', '13', '6', 'cancelled_by_client', '2013-10-01' );
INSERT INTO Trips VALUES ('5', '1', '10', '1', 'completed', '2013-10-02' );
INSERT INTO Trips VALUES ('6', '2', '11', '6', 'completed', '2013-10-02' );
INSERT INTO Trips VALUES ('7', '3', '12', '6', 'completed', '2013-10-02' );
INSERT INTO Trips VALUES ('8', '2', '12', '12', 'completed', '2013-10-03' );
INSERT INTO Trips VALUES ('9', '3', '10', '12', 'completed', '2013-10-03' );
INSERT INTO Trips VALUES ('10', '4', '13', '12', 'cancelled_by_driver', '2013-10-03' );

SELECT * FROM Trips;

DROP TABLE IF EXISTS Users;

CREATE TABLE IF NOT EXISTS Users (
Users_Id INT NOT NULL, 
Banned VARCHAR(4),
Role ENUM('client', 'driver', 'partner'),
PRIMARY KEY (Users_Id)
);

INSERT INTO Users VALUES ('1', 'No', 'client');
INSERT INTO Users VALUES ('2', 'Yes', 'client');
INSERT INTO Users VALUES ('3', 'No', 'client');
INSERT INTO Users VALUES ('4', 'No', 'client');
INSERT INTO Users VALUES ('10', 'No', 'driver');
INSERT INTO Users VALUES ('11', 'No', 'driver');
INSERT INTO Users VALUES ('12', 'No', 'driver');
INSERT INTO Users VALUES ('13', 'No', 'driver');

SELECT * FROM Users;

/*------------------------ Slution 1: ------------------------*/
/*url: https://discuss.leetcode.com/topic/57860/129-ms-solution 
*/

select Day, round(avg(cnt), 2) as 'Cancellation Rate'
from 
(   select a.request_at as Day, 
    @cnt := IF(a.Status = 'completed', 0, 1) as cnt
    from Trips a, Users b
    where a.Client_Id = b.Users_Id and b.Banned = 'No'
) c
where Day BETWEEN '2013-10-01' AND '2013-10-03'
group by Day; 


/*------------------------Solution 2-----------------------------
url: https://discuss.leetcode.com/topic/54119/187-ms-answer
*/

select Request_at as 'Day', ROUND(COUNT(if(a.`Status` <> 'completed',1,null))/COUNT(*),2) as 'Cancellation Rate'
from Trips a
inner join Users b on a.Client_Id=b.Users_Id and b.Role='client'
where b.Banned='No' and a.Request_at>='2013-10-01' and a.Request_at<='2013-10-03'
group by a.Request_at;


/*-------------------------Solution 3------------------------------ 用了IF ()
url: https://discuss.leetcode.com/topic/42188/solution-without-join/3
*/
SELECT Request_at as Day,
       ROUND(COUNT(IF(Status != 'completed', TRUE, NULL)) / COUNT(*), 2) AS 'Cancellation Rate'
FROM Trips
WHERE (Request_at BETWEEN '2013-10-01' AND '2013-10-03')
      AND Client_id NOT IN (SELECT Users_Id FROM Users WHERE Banned = 'Yes')
GROUP BY Request_at;


/*------------------------Solution 4------------------------------ 用了case when 
https://discuss.leetcode.com/topic/21729/sharing-my-solution
*/

select t.Request_at Day, 
round(sum(case when t.Status like 'cancelled_%' then 1 else 0 end)/count(*),2) Rate
from Trips t 
inner join Users u 
on t.Client_Id = u.Users_Id and u.Banned='No'
where t.Request_at between '2013-10-01' and '2013-10-03'
group by t.Request_at;

