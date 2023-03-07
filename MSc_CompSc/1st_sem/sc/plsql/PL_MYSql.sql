/*-------------DEMONSTRATING ONLY THE CONTROL STRUCTURES---------------------*/
/*
delimiter $$
drop procedure ABC;
create procedure ABC()  /*----------------How to use the ITERATE keyword ----------------------*/
begin
	declare a int default 0;
	loop1:loop
	set a=a+1;
	select a;
	if a=5 then
		leave loop1;
	end if;
	iterate loop1;
	end loop;
end $$
delimiter ;
*/
/*
delimiter $$
drop procedure sp_rep;
create procedure sp_rep()/*-----------How to use the untill keyword for looping-------------*/
begin
	declare a int default 0;
  repeat
	select a;
	set a=a+1;
	until a>10
	end repeat;
end $$
delimiter ;

*/
/*
delimiter $$
create procedure sp_loop_wh(in lim1 int )  /*-----How to use the while keyword--------------*/
begin
 declare i int default 1;
 while (i<=lim1)
 do
   select i;
   set i=i+1;
 end while;
 select 'Hello..';
end $$
delimiter ;
*/
/*
delimiter $$
create procedure sp_loop_case(in var1 int) /*-----------How to use CASE keyword----------------*/
begin
 case var1
   when 1 then select '1st case';
   when 2 then select '2nd case';
   else   select 'Other case';
 end case;
end $$
delimiter ;
*/
/*
delimiter $$
create procedure sp_cur()/*-----------------------To print tuple count------------------*/
begin
	declare i int;
	select count(*) into i
	from help_keyword;
	select 'Total tuples is: ';
	select i;
end $$
delimiter ;

*/
