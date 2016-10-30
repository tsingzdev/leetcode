/* URL: https://leetcode.com/problems/duplicate-emails/*/
/*Reference: http://stackoverflow.com/questions/854128/find-duplicate-records-in-mysql*/  

 
create table person (
Id  int,
Emial varchar(200)
); 

Insert into person 
values 
('1', 'a@b.com');

Insert into person 
values 
('2', 'c@d.com');

Insert into person 
values 
('3', 'a@b.com');

select * from person;


SELECT Emial FROM person
GROUP BY Emial HAVING COUNT(*) >=2;

 
SELECT DISTINCT p1.Emial FROM person p1
JOIN person p2 ON p1.Emial = p2.Emial
WHERE p1.Id <> p2.Id;

