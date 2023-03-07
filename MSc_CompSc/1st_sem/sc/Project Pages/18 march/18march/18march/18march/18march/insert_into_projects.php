<?php
	
   $con = mysql_connect("localhost","root","");
	if (!$con)
	{
		die('Could not connect: ' . mysql_error());
	}
	  
	mysql_select_db("faculty", $con);	
	
	//if(isset($_GET['CONF_fname'])&& isset($_GET['CONF_fid']) && isset($_GET['CONF_type'])&& isset($_GET['CONF_name'])&& isset($_GET['CONF_s_date'])&& isset($_GET['CONF_f_date']) && isset($_GET['CONF_venue_type'])&& isset($_GET['CONF_place']) & isset($GET['CONF_central_idea']))
	//{
		$PR_id=$_GET['PR_id'];
		$PR_topic=$_GET['PR_topic'];
		$PR_headname=$_GET['PR_headname'];
		$PR_fundedby=$_GET['PR_fundedby'];
		$PR_typeofproject=$_GET['PR_typeofproject'];
		$PR_status=$_GET['PR_status'];
				
		$PRsql="INSERT INTO projects(PR_id,PR_topic,PR_headname,PR_fundedby,PR_typeofproject,PR_status) VALUES ('$PR_id','$PR_topic','$PR_headname','$PR_fundedby','$PR_typeofproject','$PR_status')";
		echo $PRsql;
	   
	/*if(mysql_query($qsql))
		{
			echo "Records Added successfully";
		}
	else
		{
		 die(mysql_error());
		 echo "Error !!!";
		}
	}*/	
?>
