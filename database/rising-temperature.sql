/* URL: https://leetcode.com/problems/rising-temperature/

Given a Weather table, write a SQL query to find all dates' Ids with higher
 temperature compared to its previous (yesterday's) dates.
+---------+------------+------------------+
| Id(INT) | Date(DATE) | Temperature(INT) |
+---------+------------+------------------+
|       1 | 2015-01-01 |               10 |
|       2 | 2015-01-02 |               25 |
|       3 | 2015-01-03 |               20 |
|       4 | 2015-01-04 |               30 |
+---------+------------+------------------+
For example, return the following Ids for the above Weather table:
+----+
| Id |
+----+
|  2 |
|  4 |
+----+


*/

DROP TABLE IF EXISTS Weather;
CREATE TABLE  IF NOT EXISTS Weather(
Id INT NOT NULL AUTO_INCREMENT,
Date DATE,
Temperature INT,
PRIMARY KEY(Id)
);

INSERT INTO Weather 
VALUES ('1', '2015-01-01', '10') ;
INSERT INTO Weather 
VALUES ('2', '2015-01-02', '25') ;                                   
INSERT INTO Weather 
VALUES ('3', '2015-01-03', '20') ;
INSERT INTO Weather 
VALUES ('4', '2015-01-04', '40') ;

SELECT * FROM Weather;



/*SELECT Id, DATE_FORMAT(Date,'%Y%m%d'), Temperature FROM Weather; 
*/

/* S1: use TO_DAYS */
SELECT B.Id  FROM  Weather AS A , Weather AS B WHERE 
TO_DAYS(B.Date) - TO_DAYS(A.Date) =1 AND B.Temperature > A.Temperature;


/* S2: Wrong Answer:  DATE_FORMAT instead of TO_DAYS, got error  */
SELECT B.Id  FROM  Weather AS A , Weather AS B WHERE 
DATE_FORMAT(B.Date,'%Y%m%d') - DATE_FORMAT(A.Date,'%Y%m%d') =1 AND B.Temperature > A.Temperature;


/*S3: use DATEDIFF*/

SELECT B.Id  FROM  Weather AS A , Weather AS B WHERE
DATEDIFF(B.Date, A.Date) =1 AND B.Temperature > A.Temperature;


/*S4: use ADDDATE, also look up to  DATE_ADD(), DATE_SUB() and so on. 
reference: https://dev.mysql.com/doc/refman/5.7/en/date-and-time-functions.html#function_adddate*/ 
SELECT B.Id  FROM  Weather AS A , Weather AS B WHERE
ADDDATE(A.Date, 1) = B.Date AND B.Temperature > A.Temperature;

