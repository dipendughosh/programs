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
		$PAT_patent_no=$GET['PAT_patent_no'];
		$PAT_researcher=$GET['PAT_researcher'];
				
	$PATsql="INSERT INTO patent(PAT_id,PAT_topic,PAT_patent_no,PAT_researcher) VALUES ('$PAT_id','$PAT_topic','$PAT_patent_no','$PAT_researcher')";
	echo $PATsql;
	
   //insert into participate table//
	
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
