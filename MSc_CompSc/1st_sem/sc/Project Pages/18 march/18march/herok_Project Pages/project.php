<?php

	$con = mysql_connect("localhost","root","tiger");
	if (!$con)
	{
		die('Could not connect: ' . mysql_error());
	}  
	mysql_select_db("faculty", $con);
	
	if(isset($_GET['PR_project_id']) && isset($_GET['PR_head_name']) && isset($_GET['PR_topic']) && isset($_GET['PR_type']) && isset($_GET['PR_funded_by']) && isset($_GET['PR_status']))
	{
		$PR_project_id=$_GET['PR-project_id'];
		$PR_head_name=$_GET['PR_head_name'];
		$PR_topic=$_GET['PR_topic'];
		$PR_type=$_GET['PR_type'];
		$PR_funded_by=$_GET['PR_funded_by'];
                $PR_status=$_GET['PR_status'];
			
	$qsql="INSERT INTO project(PR_project_id,PR_head_name,PR_topic,ag,dob) VALUES ('$p_id','$p_name','$team_id','$age','$dob')";
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
	 
