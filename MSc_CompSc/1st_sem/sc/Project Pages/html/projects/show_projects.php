<?php

$con = mysql_connect("localhost","root","");
if (!$con)
  {
  die('Could not connect: ' . mysql_error());
  }
mysql_select_db("faculty", $con);

$choice=$_GET['choice'];
$pname=$_GET['p_name'];

if($choice==1)
{
	choice1();
}
else
{
	choice2($pname);
}

function choice1()
{
	$resultAll = mysql_query("select PR_headname,PR_topic,PR_fundedby from projects where PR_status='Complete';");
	
	//$display_string  = '<table align= center border= 2 cellspacing=2 height=20 width=500>';
	//$display_string .="<tr><td>COMPLETED</td></tr></table>";
	$display_string ="<table align= center border= 2 cellspacing=2 height=20 width=500>";
	$display_string .="<tr><th colspan=3 style='background-color:#E4F8FA'>COMPLETED</th></tr>";
	$display_string .="<tr>";
	$display_string .="<th style='background-color:#E4F8FA'>Head Name</th>";
	$display_string .="<th style='background-color:#E4F8FA'>Topic</th>";
	$display_string .="<th style='background-color:#E4F8FA'>Funded BY</th>";
	$display_string .="</tr>";
	
	while($row = mysql_fetch_array($resultAll))
	{
		$display_string .= "<tr>";
		$display_string .= "<td>$row[PR_headname]</td>";
		$display_string .= "<td>$row[PR_topic]</td>";
		$display_string .= "<td>$row[PR_fundedby]</td>";
		$display_string .= "</tr>";
  }	
	$display_string .="</table>";
	//echo $display_string;	
	
	$resultAll = mysql_query("select PR_headname,PR_topic,PR_fundedby from projects where PR_status='Not Complete';");
	//$display_string .= '<table align= center border= 2 cellspacing=2 height=20 width=500>';
	//$display_string .="<tr><td>INCOMPLETE</td></tr></table>";
	$display_string .="<table align= center border= 2 cellspacing=2 height=20 width=500>";
	$display_string .="<tr><th colspan=3 style='background-color:#E4F8FA'>INCOMPLETE</th></tr>";
	
	while($row = mysql_fetch_array($resultAll))
	{
		$display_string .= "<tr>";
		$display_string .= "<td>$row[PR_headname]</td>";
		$display_string .= "<td>$row[PR_topic]</td>";
		$display_string .= "<td>$row[PR_fundedby]</td>";
		$display_string .= "</tr>";
  }
	$display_string .= "</table>";
	echo $display_string;	
}

function choice2($pname)
{
	$result = mysql_query("SELECT * FROM projects where PR_headname='$pname';");
	//Build Result String
	$display_string = '<table align= center border= 2 cellspacing=2 height=20 width=500>';
	$display_string .= "<tr>";
	$display_string .= "<th>ID</th>";
	$display_string .= "<th>Topic</th>";
	$display_string .= "<th>Headname</th>";
	$display_string .= "<th>FundedBy</th>";
	$display_string .= "<th>Type_of_project</th>";
	$display_string .= "<th>Type_of_Status</th>";
	$display_string .= "</tr>";
	
	while($row = mysql_fetch_array($result))
	{
		$display_string .= "<tr>";
		$display_string .= "<td>$row[PR_id]</td>";
		$display_string .= "<td>$row[PR_topic]</td>";
		$display_string .= "<td>$row[PR_headname]</td>";
		$display_string .= "<td>$row[PR_fundedby]</td>";
		$display_string .= "<td>$row[PR_type]</td>";
		$display_string .= "<td>$row[PR_status]</td>";
		$display_string .= "</tr>";
  }$display_string .= "</table>";
echo $display_string;
}

?>
