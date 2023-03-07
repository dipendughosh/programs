<?php
	$con = mysql_connect("localhost","root","");
	if(!$con)
		die('Could not connect' . mysql_error());
	mysql_select_db("test",$con);
	
	$empid=$_POST['Empid'];
	$empname=$_POST['Empname'];
	
	$sqlq="insert into emp values('$empid','$empname');";
	mysql_query($sqlq);
?>
	