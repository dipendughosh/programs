<?php

	$con = mysql_connect("localhost","root","tiger");
	if (!$con)
	{
		die('Could not connect: ' . mysql_error());
	}  
	mysql_select_db("softball", $con);
	
	if(isset($_GET['p_id']) && isset($_GET['p_name']) && isset($_GET['team_id']) && isset($_GET['age']) && isset($_GET['dob']))
	{
		$p_id=$_GET['p_id'];
		$p_name=$_GET['p_name'];
		$team_id=$_GET['team_id'];
		$age=$_GET['age'];
		$dob=$_GET['dob'];
			
	$qsql="INSERT INTO player(p_id,p_name,team_id,age,dob) VALUES ('$p_id','$p_name','$team_id','$age','$dob')";
	//$qsql="INSERT INTO player(p_id,p_name,team_id,age,dob) VALUES ('p11','kahha','$_GET[team_id]','$_GET[age]','$_GET[dob]')";
	
	if(mysql_query($qsql))
		{
			echo "Records Added successfully";
		}
	else
		{
		 die(mysql_error());
		 echo "Error !!!";
		}
	}
	else
	{
		echo "Not set";
	}
?>
	