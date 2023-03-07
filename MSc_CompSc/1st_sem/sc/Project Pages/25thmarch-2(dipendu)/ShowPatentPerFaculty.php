<?php

//$display_string = '';

function c1($PD_pid)
{
	global $display_string;	 	$result1 = mysql_query("select A.PAT_pid 'PATPID' ,PAT_topic,PAT_patent_no from patent A,patents_per_faculty B where A.PAT_pid=B.pat_pid and B.PD_p_id='$PD_pid';");
		
	$display_string = '<table align= center border= 2 cellspacing=2 height=20 width=500>';
	$display_string .= "<tr>";
	$display_string .= "<th>ID</th>";
	$display_string .= "<th>Topic</th>";
	$display_string .= "<th>Number</th>";
	$display_string .= "</tr>";

	// Insert a new row in the table for each person returned
	while($row1 = mysql_fetch_array($result1))
	{
		$display_string .= "<tr>";
		$display_string .= "<td>$row1[PATPID]</td>";
		$display_string .= "<td>$row1[PAT_topic]</td>";
		$display_string .= "<td>$row1[PAT_patent_no]</td>";
		$display_string .= "</tr>";
	}
	
$display_string .= "</table>";
echo $display_string;

}


function c2()
{
	global $display_string;
	$display_string='';	
	
	$result2 = mysql_query("SELECT PD_name,NUMBER from personal_details A,(select PD_p_id,count(*) 'NUMBER' from patents_per_faculty group by PD_p_id) B where A.PD_p_id=B.PD_p_id;");
	$display_string = '<table align= center border= 2 cellspacing=2 height=20 width=500>';
	$display_string .= "<tr>";
	$display_string .= "<th>Researcher</th>";
	$display_string .= "<th>NO_of_Patents</th>";
	$display_string .= "</tr>";

	while($row2 = mysql_fetch_array($result2))
	{
		$display_string .= "<tr>";
		$display_string .= "<td>$row2[PD_name]</td>";
		$display_string .= "<td>$row2[NUMBER]</td>";
		$display_string .= "</tr>";
	}

	$display_string .= "</table>";
	echo $display_string;
}


$con = mysql_connect("localhost","root","");
if (!$con)
  {
  die('Could not connect: ' . mysql_error());
  }
mysql_select_db("faculty", $con);

$choice=$_GET['choice'];
$PD_pid=$_GET['PD_pid'];

if($choice==1)
{
 c1($PD_pid);
}
else
{
 c2();
}
 

	/*$display_string='';
	echo $PD_pid;	
	$result1 = mysql_query("select A.PAT_pid 'PATPID' ,PAT_topic,PAT_patent_no from patent A,patents_per_faculty B where A.PAT_pid=B.pat_pid and B.PD_p_id='$PD_pid';");
		
	$display_string = '<table align= center border= 2 cellspacing=2 height=20 width=500>';
	$display_string .= "<tr>";
	$display_string .= "<th>ID</th>";
	$display_string .= "<th>Topic</th>";
	$display_string .= "<th>Number</th>";
	$display_string .= "</tr>";

	
	while($row1 = mysql_fetch_array($result1))
	{
		$display_string .= "<tr>";
		$display_string .= "<td>$row1[PATPID]</td>";
		$display_string .= "<td>$row1[PAT_topic]</td>";
		$display_string .= "<td>$row1[PAT_patent_no]</td>";
		$display_string .= "</tr>";
	}
		
	$display_string .= "</table>";
	echo $display_string;*/

?>
