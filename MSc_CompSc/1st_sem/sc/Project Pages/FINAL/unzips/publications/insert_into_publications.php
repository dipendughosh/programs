<?php
	
   $con = mysql_connect("localhost","root","");
	if (!$con)
	{
		die('Could not connect: ' . mysql_error());
	}
	  
	mysql_select_db("faculty", $con);	
	
	//if(isset($_GET['CONF_fname'])&& isset($_GET['CONF_fid']) && isset($_GET['CONF_type'])&& isset($_GET['CONF_name'])&& isset($_GET['CONF_s_date'])&& isset($_GET['CONF_f_date']) && isset($_GET['CONF_venue_type'])&& isset($_GET['CONF_place']) & isset($GET['CONF_central_idea']))
	//{
		
		$PUB_id=$_GET['PUB_pid'];
		$PUB_topic=$_GET['PUB_topic'];
		$PUB_conf_name=$_GET['PUB_conf_name'];
		$PUB_volume_no=$_GET['PUB_volume_no'];
		$PUB_author=$_GET['PUB_author'];
		$PUB_pub_date=$_GET['PUB_pub_date'];
		

	$PUBsql="INSERT INTO publications VALUES ('$PUB_id','$PUB_topic','$PUB_conf_name','$PUB_volume_no','$PUB_author','$PUB_pub_date');";
	mysql_query($PUBsql);
	
	$result=mysql_query("select PD_p_id from personal_details where PD_name='$PUB_author';");
	$row = mysql_fetch_array($result);
	$PD_p_id_value =$row['PD_p_id'];
	$PUBsql2="INSERT INTO publication_per_faculty VALUES ('$PUB_id','$PD_p_id_value');";
	
	mysql_query($PUBsql2);
	echo "Records Added successfully";
	
	
	/*if(mysql_query($qsql) && mysql_query($PUBsql))
		{
			
		}
	else
		{
		 die(mysql_error());
		 echo "Error !!!";
		}*/
?>
