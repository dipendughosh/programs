
delimiter $$
create function func (str char(20))	returns char(50)
begin
	return concat('Welcome To ',str,'!');
end $$
delimiter ;
/*
create table Product
(
	p_id varchar(3),
	p_name varchar(10),
	p_cost int(8)
);
*/
/*
delimiter $$
drop procedure product_ins;
create procedure product_ins( in id varchar(3),in name varchar(10),in cost int)
begin
	if cost > 500 then	
		insert into Product values (id,name,cost);
	else
		select 'Data cannot be inserted...';
	end if;
	
	select * from Product;
end $$
delimiter ;
*/


