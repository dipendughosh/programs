<?php
	
   $con = mysql_connect("localhost","root","");
	if (!$con)
	{
		die('Could not connect: ' . mysql_error());
	}
	  
	mysql_select_db("faculty", $con);	
	
	//if(isset($_GET['CONF_fname'])&& isset($_GET['CONF_fid']) && isset($_GET['CONF_type'])&& isset($_GET['CONF_name'])&& isset($_GET['CONF_s_date'])&& isset($_GET['CONF_f_date']) && isset($_GET['CONF_venue_type'])&& isset($_GET['CONF_place']) & isset($GET['CONF_central_idea']))
	//{
	
		$CONF_fname=$_GET['CONF_fname'];
		$CONF_fid=$_GET['CONF_fid'];
		
		$CONF_type=$_GET['CONF_type'];
		$CONF_name=$_GET['CONF_name'];
		$CONF_s_date=$_GET['CONF_s_date'];
		$CONF_f_date=$_GET['CONF_f_date'];		
		$CONF_venue_type=$_GET['CONF_venue_type'];
		$CONF_place=$_GET['CONF_place'];		
		$CONF_central_idea=$_GET['CONF_central_idea'];
		$CONF_c_id=$CONF_name.$CONF_s_date;		
				
	$qsql="INSERT INTO conference(CONF_c_id,CONF_name,CONF_type,CONF_venue_type,CONF_s_date,CONF_f_date,CONF_place,CONF_central_idea) VALUES ('$CONF_c_id','$CONF_name','$CONF_type','$CONF_venue_type','$CONF_s_date','$CONF_f_date','$CONF_place','$CONF_central_idea');";
//echo $qsql; 

//mysql_query($qsql);	
   //insert into participate table//
	
	if(mysql_query($qsql))
		{
			echo "Records Added successfully";
		}
	else
		{
		 die(mysql_error());
		 echo "Error !!!";
		}
	//}	
?>
	 
