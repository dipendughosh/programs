<?php

	$con = mysql_connect("localhost","root","tiger");
	if (!$con)
	{
		die('Could not connect: ' . mysql_error());
	}  
	mysql_select_db("faculty", $con);
	
	/*if(isset($_GET['PD_name']) && isset($_GET['PD_dob']) && isset($_GET['PD_male']) && isset($_GET['PD_address']) && isset($_GET['PD_pin'])&& isset($_GET['PD_landline'])&& isset($_GET['PD_mobile'])&& isset($_GET['PD_email'])&& isset($_GET['PD_doj'])&& isset($_GET['PD_quali'])&& isset($_GET['PD_type'])&& isset($_GET['PD_post'])&& isset($_GET['PD_special']))
	{*/
	
		$PD_p_id=$_GET['PD_p_id'];
		$PD_name=$_GET['PD_name'];
		$PD_dob=$_GET['PD_dob'];
		$PD_male=$_GET['PD_male'];
		$PD_address=$_GET['PD_address'];
		$PD_pin=$_GET['PD_pin'];
		$PD_landline=$_GET['PD_landline'];
		$PD_mobile=$_GET['PD_mobile'];
		$PD_email=$_GET['PD_email'];
		$PD_doj=$_GET['PD_doj'];
		$PD_quali=$_GET['PD_quali'];
		$PD_type=$_GET['PD_type'];
		$PD_post=$_GET['PD_post'];
		$PD_special=$_GET['PD_special'];
			
	$PDsql="INSERT INTO personal_details(PD_p_id,PD_name,PD_dob,PD_male,PD_address,PD_pin,PD_landline,PD_mobile,PD_mobile,PD_email,PD_doj,PD_quali,PD_type,PD_post,PD_special) VALUES ('$PD_p_id','$PD_name','$PD_dob','$PD_male','$PD_address','$PD_pin','$PD_landline','$PD_mobile','$PD_email','$PD_doj','$PD_quali','$PD_type','$PD_post','$PD_special')";
	echo $PDsql;
	/*if(mysql_query($qsql))
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
	}*/
?> 
