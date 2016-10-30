/* 
URL: https://leetcode.com/problems/consecutive-numbers/

REFERENCE: 

http://dba.stackexchange.com/questions/89493/find-all-numbers-that-appear-at-least-three-times-consecutively
http://stackoverflow.com/questions/31577623/write-a-sql-query-to-find-all-numbers-that-appear-at-least-three-times

Write a SQL query to find all numbers that appear at least three times consecutively.
+----+-----+
| Id | Num |
+----+-----+
| 1  |  1  |
| 2  |  1  |
| 3  |  1  |
| 4  |  2  |
| 5  |  1  |
| 6  |  2  |
| 7  |  2  |
+----+-----+
For example, given the above Logs table, 1 is the only number that appears consecutively 
for at least three times.
 
*/ 
DROP TABLE IF EXISTS Logs;

CREATE TABLE IF NOT EXISTS Logs (
Id INT NOT NULL AUTO_INCREMENT,
Num INT NOT NULL,
PRIMARY KEY (Id)
);

INSERT INTO Logs(Num) VALUES (1),(1),(1),(2),(1),(2),(2);

SELECT * FROM Logs;


/*--------------------------Solution1: ------------------------*/

SET @curnum = -999;
SET @same=1;
SET @group=0;

SELECT DISTINCT A.num FROM (

SELECT grp, num, MAX(samecount) same FROM (
 
SELECT 
	(@group :=@group + IF(@curnum=num, 0,1)) grp,
    (@same := IF(@curnum=Num, @same+1, 1)) samecount,
    (@curnum :=Num) num
FROM Logs ORDER BY Id 

) AA  GROUP BY grp, num having same>=3

) A;


/*----------------------------Solution2: --------------------------*/

SELECT Num FROM Logs; 
WHERE 





;



