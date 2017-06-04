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


/*----------------------------Solution 1: 1117 ms  --------------------------*/
SELECT DISTINCT l1.Num  as ConsecutiveNums
FROM Logs l1, Logs l2, Logs l3  
WHERE l1.Id + 1 = l2.Id AND l2.Id + 1 = l3.Id AND l1.Num = l2.Num AND l2.Num = l3.Num 


