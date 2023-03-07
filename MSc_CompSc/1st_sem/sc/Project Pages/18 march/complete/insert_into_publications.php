<?php
	
   $con = mysql_connect("localhost","root","");
	if (!$con)
	{
		die('Could not connect: ' . mysql_error());
	}
	  
	mysql_select_db("faculty", $con);	
	
	//if(isset($_GET['CONF_fname'])&& isset($_GET['CONF_fid']) && isset($_GET['CONF_type'])&& isset($_GET['CONF_name'])&& isset($_GET['CONF_s_date'])&& isset($_GET['CONF_f_date']) && isset($_GET['CONF_venue_type'])&& isset($_GET['CONF_place']) & isset($GET['CONF_central_idea']))
	//{
		
		$PUB_id=$_GET['PUB_id'];
		$PUB_topic=$_GET['PUB_topic'];
		$PUB_read_conference=$_GET['PUB_read_conference'];
		$PUB_volume_no=$_GET['PUB_volume_no'];
		$PUB_author=$_GET['PUB_author'];
		$PUB_pub_date=$_GET['PUB_pub_date'];


	$PUBsql="INSERT INTO publications(PUB_id,PUB_topic,PUB_read_conference,PUB_volume_no,PUB_author,PUB_pub_date) VALUES ('$PUB_id','$PUB_topic','$PUB_read_conference','$PUB_volume_no','$PUB_author','$PUB_pub_date')";
	echo $PUBsql;
	
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
