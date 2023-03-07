<?php

$con = mysql_connect("localhost","root","tiger");
if (!$con)
  {
  die('Could not connect: ' . mysql_error());
  }
mysql_select_db("faculty", $con);
$pid=$_GET['CONF_c_id'];
$result = mysql_query("SELECT * FROM conference where CONF_c_id='$pid';");

//Build Result String
$display_string = '<table align= center border= 2 cellspacing=2 height=20 width=500>';
$display_string .= "<tr>";
$display_string .= "<th>Id</th>";
$display_string .= "<th>Name</th>";
$display_string .= "<th>Type</th>";
$display_string .= "<th>Venue_type</th>";
$display_string .= "<th>Start_date</th>";
$display_string .= "<th>Finish_date</th>";
$display_string .= "<th>Place</th>";
$display_string .= "<th>Central_Idea</th>";
$display_string .= "</tr>";

	// Insert a new row in the table for each person returned
while($row = mysql_fetch_array($result)){
	$display_string .= "<tr>";
	$display_string .= "<td>$row[CONF_c_id]</td>";
	$display_string .= "<td>$row[CONF_name]</td>";
	$display_string .= "<td>$row[CONF_type]</td>";
	$display_string .= "<td>$row[CONF_venu_type]</td>";
	$display_string .= "<td>$row[CONF_s_date]</td>";
	$display_string .= "<td>$row[CONF_f_date]</td>";
	$display_string .= "<td>$row[CONF_place]</td>";
	$display_string .= "<td>$row[CONF_central_idea]</td>";
	$display_string .= "</tr>";
	
}
//echo "Query: " . $query . "<br />";
$display_string .= "</table>";
echo $display_string;

?>
