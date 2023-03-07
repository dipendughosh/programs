<?php
	
   $con = mysql_connect("localhost","root","");
	if (!$con)
	{
		die('Could not connect: ' . mysql_error());
	}
	  
	mysql_select_db("faculty", $con);	
	
	//if(isset($_GET['CONF_fname'])&& isset($_GET['CONF_fid']) && isset($_GET['CONF_type'])&& isset($_GET['CONF_name'])&& isset($_GET['CONF_s_date'])&& isset($_GET['CONF_f_date']) && isset($_GET['CONF_venue_type'])&& isset($_GET['CONF_place']) & isset($GET['CONF_central_idea']))
	//{		
		$PAT_id=$_GET['PAT_id'];		
		$PAT_topic=$_GET['PAT_topic'];
		$PAT_number=$_GET['PAT_patent_no'];
		$PAT_researcher=$_GET['PAT_researcher'];		
				
	$PATsql="INSERT INTO patent VALUES ('$PAT_id','$PAT_topic','$PAT_number','$PAT_researcher');";
		
	$A = mysql_query($PATsql);
	if(! $A)
	 {
		die(mysql_error());
		echo "Error !!!";	  
	 }
	  			
	$result = mysql_query("SELECT PD_p_id FROM personal_details where PD_name='$PAT_researcher';");
	$row = mysql_fetch_array($result);
	$PD_pid_value=$row['PD_p_id'];
	$PATsql2="INSERT INTO patents_per_faculty VALUES ('$PAT_id','$PD_pid_value');";
	$B = mysql_query($PATsql2);
		
 	if($B)
			{
				echo "Records Added successfully";
			}
	else
			{
		 	die(mysql_error());
		 	echo "Error !!!";
			}
			
?>
