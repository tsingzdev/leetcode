/*
URL: https://leetcode.com/problems/rank-scores/

Write a SQL query to rank scores. If there is a tie between two scores, both 
should have the same ranking. Note that after a tie, the next ranking number 
should be the next consecutive integer value. In other words, there should be
 no "holes" between ranks.

+----+-------+
| Id | Score |
+----+-------+
| 1  | 3.50  |
| 2  | 3.65  |
| 3  | 4.00  |
| 4  | 3.85  |
| 5  | 4.00  |
| 6  | 3.65  |
+----+-------+
For example, given the above Scores table, your query should generate the 
following report (order by highest score):
+-------+------+
| Score | Rank |
+-------+------+
| 4.00  | 1    |
| 4.00  | 1    |
| 3.85  | 2    |
| 3.65  | 3    |
| 3.65  | 3    |
| 3.50  | 4    |
+-------+------+
*/

DROP table Scores;

CREATE TABLE Scores 
(
Id int,
Score varchar(255) 
);


INSERT INTO Scores (Id, Score )
VALUES ('1', '3.5');
INSERT INTO Scores (Id, Score )
VALUES ('2', '3.65');
INSERT INTO Scores (Id, Score )
VALUES ('3', '4.00');
INSERT INTO Scores (Id, Score )
VALUES ('4', '4.00');
INSERT INTO Scores (Id, Score )
VALUES ('5', '3.65');
INSERT INTO Scores (Id, Score )
VALUES ('6', '3.85');

select * from Scores;

/* dense_rank in MySQL  example 0 */

set @rn1 =0;
set @sal ='';
SELECT Score, Rank
FROM
(
  SELECT  Score,
          @rn1 :=  if(@sal=Score, @rn1, @rn1+1)  as Rank,
          @sal := Score     
  FROM
  ( SELECT  Score
    FROM    Scores
    ORDER BY Score DESC
) A
) B;


/***  dense_rank in MySQL  example 1 */
set @Score:=''; 
set @Rank:=0; 
select  @Rank:=case when @Score=Score then @Rank else @Rank+1 end as Rank, @Score:=Score as Score    from Scores
order by Score DESC;

/* BELOW reference: http://www.cnblogs.com/grandyang/p/5351611.html */
/* https://discuss.leetcode.com/topic/16097/simple-short-fast/3  */

/* Solution 1  */
SELECT Score, 
(SELECT COUNT(DISTINCT Score)  FROM Scores WHERE Score >= s.Score 
) Rank 
FROM Scores s ORDER BY Score DESC;


/* Solution 2  , 782ms */
SELECT Score, 
(
SELECT COUNT(*) FROM ( SELECT DISTINCT Score s FROM Scores) t 
WHERE s>=Score 
) Rank
FROM Scores ORDER BY Score DESC;


/* Solution 3  , 1237ms */ 
SELECT s.Score, COUNT(DISTINCT t.Score) Rank
FROM Scores s JOIN Scores t ON s.Score <= t.Score
GROUP BY s.Id ORDER BY s.Score DESC;


SELECT COUNT(DISTINCT t.Score) from Scores t;



/* Solution 4  */
SELECT Score,
@rank := @rank + (@pre <> (@pre := Score)) Rank
FROM Scores, (SELECT @rank := 0, @pre := -1) INIT 
ORDER BY Score DESC;


/*  reference: https://helloacm.com/sql-coding-exercise-rank-scores/
*/





