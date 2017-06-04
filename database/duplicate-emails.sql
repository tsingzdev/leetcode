/* URL: https://leetcode.com/problems/duplicate-emails/*/
/*Write a SQL query to find all duplicate emails in a table named Person.
 
 +----+---------+
 | Id | Email   |
 +----+---------+
 | 1  | a@b.com |
 | 2  | c@d.com |
 | 3  | a@b.com |
 +----+---------+
 For example, your query should return the following for the above table:
 
 +---------+
 | Email   |
 +---------+
 | a@b.com |
 +---------+*/
 

------------Solution 1 : 639ms
SELECT Email FROM person
GROUP BY Email HAVING COUNT(*) >=2;

------------Solution 2 : 671ms
 
SELECT DISTINCT p1.Email FROM person p1
JOIN person p2 ON p1.Email = p2.Email
WHERE p1.Id != p2.Id;

--------------------702ms
SELECT DISTINCT p1.Email FROM person p1
JOIN person p2 ON p1.Email = p2.Email
WHERE p1.Id <> p2.Id;


------------Solution 3 : 694ms
select distinct A.Email  from Person A, Person B
where A.Id != B.Id and A.Email = B.Email;
