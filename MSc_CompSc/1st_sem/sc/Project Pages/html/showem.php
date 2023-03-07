<?php

	$con = mysql_connect("localhost","root","");
	if(!$con)
		die("Could Not Connect : " . mysql_error());
	
	mysql_select_db("test",$con);
	
	$A = $_POST[empid];
	$result = mysql_query("select * from emp where empid = '$A';");
	$row=mysql_fetch_array($result);
	//echo ($row[empid] '.' 
	echo $row[empname];
	?>
	