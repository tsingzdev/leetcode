/* url: http://www.folkstalk.com/2013/03/grouped-dense-rank-function-mysql-sql-query.html   */

create table employees (
dept_id int,
salary varchar(200)
);

insert into employees 
values ('10', '10000');
insert into employees 
values ('10', '20000');
insert into employees 
values ('10', '20000');
insert into employees 
values ('10', '30000');
insert into employees 
values ('20', '50000');
insert into employees 
values ('20', '50000');

select * from employees;
# 

set @pk1 ='';
set @rn1 =1;
set @sal ='';
set @val =1;

SELECT  dept_id,
        salary,
        denseRank
FROM
(
  SELECT  dept_id,
          salary,
          @rn1 := if(@pk1=dept_id, if(@sal=salary, @rn1, @rn1+@val),1) as denseRank,
          @val := if(@pk1=dept_id, if(@sal=salary, @val+1, 1),1) as value,
          @pk1 := dept_id,
          @sal := salary     
  FROM
  (
    SELECT  dept_id,
            salary
    FROM    employees
    ORDER BY dept_id,salary
) A
) B;





# 只对salary进行排序
set @rn1 =0;
set @sal ='';

SELECT 
        salary,
        denseRank
FROM
(
  SELECT  
          salary,
          @rn1 :=  if(@sal=salary, @rn1, @rn1+1)  as denseRank,
          @sal := salary     
  FROM
  (
    SELECT  
            salary
    FROM    employees
    ORDER BY salary DESC
) A
) B;
