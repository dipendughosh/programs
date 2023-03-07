<?php

$con = mysql_connect("localhost","root","");
if (!$con)
  {
  die('Could not connect: ' . mysql_error());
  }
mysql_select_db("faculty", $con);

$PUB_view2_fac_name = $_GET['PUB_view2_fac_name'];
$result = mysql_query("SELECT PUB_pid,PUB_topic,PUB_read_conference,PUB_pub_date from publications where PUB_author='$PUB_view2_fac_name';");

//Build Result String
$display_string = '<table align= center border= 2 cellspacing=2 height=20 width=500>';
$display_string .= "<tr>";
$display_string .= "<th>PUB_pid</th>";
$display_string .= "<th>PUB_topic</th>";
$display_string .= "<th>Published in Conference</th>";
$display_string .= "<th>Publishing Date</th>";
$display_string .= "</tr>";

	// Insert a new row in the table for each person returned
while($row = mysql_fetch_array($result))
{	
	$display_string .= "<tr>";
	$display_string .= "<td>$row[PUB_pid]</td>";
	$display_string .= "<td>$row[PUB_topic]</td>";
	$display_string .= "<td>$row[PUB_read_conference]</td>";
	$display_string .= "<td>$row[PUB_pub_date]</td>";	
	$display_string .= "</tr>";	
}

$display_string .= "</table>";
echo $display_string;

?>
