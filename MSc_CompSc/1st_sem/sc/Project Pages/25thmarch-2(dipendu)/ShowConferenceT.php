<?php

/*Global*/
$display_string = '';


function choice1($VW_CONF_FROM_date,$VW_CONF_TO_date)
{	
	/*National Part */	
	$result = mysql_query("SELECT CONF_type,count(*) 'NUMBER' FROM conference where CONF_s_date >='$VW_CONF_FROM_date' and CONF_s_date <='$VW_CONF_TO_date' and CONF_venue_type='National' GROUP BY CONF_type;");		
	$display_string  ='<table align="center" border="2" cellspacing="2" height="20" width="500" class="main">';
	$display_string .='<tr><td><center>National</center></td></tr></table>';							
	$display_string .= '<table align= center border= 2 cellspacing=2 height=20 width=500 class="main">';	
	$display_string .= "<tr>";
	$display_string .= "<th>TYPE OF PROGRAMME</th>";
	$display_string .= "<th>NUMBER OF SUCH PROGRAMMES</th>";
	$display_string .= "</tr>";	

	while($row = mysql_fetch_array($result))
	{	
		$display_string .= "<tr>";
		$display_string .= "<td width='70%'>$row[CONF_type]</td>";
		$display_string .= "<td width='30%'>$row[NUMBER]</td>";
		$display_string .= "</tr>";	
	}
	$display_string .='</table>';

	/* International Part */
	
	$result = mysql_query("SELECT CONF_type,count(*) 'NUMBER' FROM conference where CONF_s_date >='$VW_CONF_FROM_date' and CONF_s_date <='$VW_CONF_TO_date' and CONF_venue_type='International' GROUP BY CONF_type;");	
	$display_string .='<table align="center" border="2" cellspacing="2" height="20" width="500" class="main">';
	$display_string .='<tr><td><center>International</center></td></tr></table>';							
	$display_string .= '<table align= center border= 2 cellspacing=2 height=20 width=500 class="main">';	
	
	while($row = mysql_fetch_array($result))
	{
		$display_string .= "<tr>";
		$display_string .= "<td width='70%'>$row[CONF_type]</td>";
		$display_string .= "<td width='30%'>$row[NUMBER]</td>";
		$display_string .= "</tr>";	
	}
	$display_string .= "</table>";
	echo $display_string;
}//function choice1();


function choice2($VW_CONF_FROM_date,$VW_CONF_TO_date)
{	
	
	global $display_string;	
	
	$display_string  = '<table align= center border= 2 cellspacing=2 height=20 width=500 class="main">';
	$display_string .="<tr><td><center>National</center></td></tr></table>";
	$display_string .='<table align= center border= 2 cellspacing=2 height=20 width=500 class="main">';
	$display_string .= "<tr>";
	$display_string .= '<th>Name of Faculty</th>';
	$display_string .= "<th>Faculty Development Programe</th>";
	$display_string .= "<th>Workshops</th>";
	$display_string .= "<th>Conferences</th>";
	$display_string .= "<th>Staff Development Training Programe</th>";
	$display_string .= "<th>Foreign Training Programe</th>";
	$display_string .= "<th>Programes Under Networking Of Institutions</th>";
	$display_string .= "<th>Total Activities</th>";
	$display_string .= "</tr>";

/* NATIONAL */
		$RESULT_PD_p_id = mysql_query("SELECT PD_p_id,PD_name from personal_details where PD_p_id in(select PD_p_id from conference_attended where CONF_c_id in (select CONF_c_id from conference where CONF_s_date >='$VW_CONF_FROM_date' and CONF_s_date <='$VW_CONF_TO_date' and CONF_venue_type='national'));");		
		BuildOutput($RESULT_PD_p_id,$VW_CONF_FROM_date,$VW_CONF_TO_date,$p);
		$display_string .= "</table>";
			
/* INTERNATIONAL */
	
		$display_string .= '<table align= center border= 2 cellspacing=2 height=20 width=500 class="main">';
		$display_string .= "<tr><td with='100%'><center>International</center></td></tr></table>";
		$display_string .= '<table align= center border= 2 cellspacing=2 height=20 width=500 class="main">';
		$RESULT_PD_p_id=mysql_query("SELECT PD_p_id,PD_name from personal_details where PD_p_id in(select PD_p_id from conference_attended where CONF_c_id in (select CONF_c_id from conference where CONF_s_date >='$VW_CONF_FROM_date' and CONF_s_date <='$VW_CONF_TO_date' and CONF_venue_type='International'));");
		$p=2;	
		BuildOutput($RESULT_PD_p_id,$VW_CONF_FROM_date,$VW_CONF_TO_date,$p);
		$display_string .= "</table>";
		
 /* output*/ 		
		
		echo $display_string;	
}


function BuildOutput($RESULT_PD_p_id,$VW_CONF_FROM_date,$VW_CONF_TO_date,$p)
{	
	global $display_string;
		
	while($PD_p_id_row = mysql_fetch_array($RESULT_PD_p_id))
	{		
		
		/*FACULTY DEVELOPMENT PROGRAME */
		$FDProg = mysql_query("SELECT count(*) 'NUMBER' from conference_attended where CONF_c_id in( select CONF_c_id from conference where CONF_type = 'FDProg' and CONF_s_date >='$VW_CONF_FROM_date' and CONF_s_date <='$VW_CONF_TO_date') and PD_p_id='$PD_p_id_row[PD_p_id]';");
		$FDProgRow = mysql_fetch_array($FDProg);		
		$display_string .= "<tr>";
		$display_string .= "<td>$PD_p_id_row[PD_name]</td>";
		$display_string .= "<td>$FDProgRow[NUMBER]</td>";
		echo $p;
		echo $PD_p_id_row[PD_name];	
		/* WORKSHOP */
		$WORKshop = mysql_query("SELECT count(*) 'NUMBER' from conference_attended where CONF_c_id in( select CONF_c_id from conference where CONF_type = 'workshop' and CONF_s_date >='$VW_CONF_FROM_date' and CONF_s_date <='$VW_CONF_TO_date') and PD_p_id='$PD_p_id_row[PD_p_id]';");		
		$WORKshopRow = mysql_fetch_array($WORKshop);		
		$display_string .= "<td width='30%'>$WORKshopRow[NUMBER]</td>";	
		
		/*Conferences*/
		$CONFerences = mysql_query("SELECT count(*) 'NUMBER' from conference_attended where CONF_c_id in( select CONF_c_id from conference where CONF_type = 'Conferences' and CONF_s_date >='$VW_CONF_FROM_date' and CONF_s_date <='$VW_CONF_TO_date') and PD_p_id='$PD_p_id_row[PD_p_id]';");
		$CONFerencesRow = mysql_fetch_array($CONFerences);		
		$display_string .= "<td width='30%'>$CONFerencesRow[NUMBER]</td>";
		
		/*Staff Development Training Program*/
		$SDTProg = mysql_query("SELECT count(*) 'NUMBER' from conference_attended where CONF_c_id in( select CONF_c_id from conference where CONF_type = 'SDTProg' and CONF_s_date >='$VW_CONF_FROM_date' and CONF_s_date <='$VW_CONF_TO_date') and PD_p_id='$PD_p_id_row[PD_p_id]';");
		$SDTProgRow = mysql_fetch_array($SDTProg);		
		$display_string .= "<td width='30%'>$SDTProgRow[NUMBER]</td>";
		
		/* Foreign Training Programme */
		$FTProg = mysql_query("SELECT count(*) 'NUMBER' from conference_attended where CONF_c_id in( select CONF_c_id from conference where CONF_type = 'FTProg' and CONF_s_date >='$VW_CONF_FROM_date' and CONF_s_date <='$VW_CONF_TO_date') and PD_p_id='$PD_p_id_row[PD_p_id]';");
		$FTProgRow = mysql_fetch_array($FTProg);		
		$display_string .= "<td width='30%'>$FTProgRow[NUMBER]</td>";
		
		/*Programes Under Networking Of Instututions */
		$PUNI = mysql_query("SELECT count(*) 'NUMBER' from conference_attended where CONF_c_id in( select CONF_c_id from conference where CONF_type = 'PUNI' and CONF_s_date >='$VW_CONF_FROM_date' and CONF_s_date <='$VW_CONF_TO_date') and PD_p_id='$PD_p_id_row[PD_p_id]';");
		$PUNIRow = mysql_fetch_array($PUNI);		
		$display_string .= "<td width='30%'>$PUNIRow[NUMBER]</td>";
	
		/*Total activities */
		$TOTAL=$FDProgRow[NUMBER]+$WORKshopRow[NUMBER]+$CONFerencesRow[NUMBER]+$SDTProgRow[NUMBER]+$FTProgRow[NUMBER]+$PUNIRow[NUMBER];
		$display_string .= "<td width='30%'>$TOTAL</td>";		
		$display_string .= "</tr>";	
 	}
}

	
$con = mysql_connect("localhost","root","");
if (!$con)
  {
  die('Could not connect: ' . mysql_error());
  }
  
mysql_select_db("faculty", $con);
$VW_CONF_FROM_date=$_GET['VW_CONF_FROM_date'];
$VW_CONF_TO_date=$_GET['VW_CONF_TO_date'];
$choice=$_GET['choice'];

if($choice==1)
 {	
 	choice1($VW_CONF_FROM_date,$VW_CONF_TO_date);
 }
else
 {
 	choice2($VW_CONF_FROM_date,$VW_CONF_TO_date);
 }	 
 	
?>