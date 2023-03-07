<?php

$con = mysql_connect("localhost","root","tiger");
if (!$con)
  {
  die('Could not connect: ' . mysql_error());
  }
mysql_select_db("softball", $con);
$pid=$_GET['p_id'];
$result = mysql_query("SELECT * FROM player where p_id='$pid';");

//Build Result String
$display_string = '<table align= center border= 2 cellspacing=2 height=20 width=500>';
$display_string .= "<tr>";
$display_string .= "<th>P_ID</th>";
$display_string .= "<th>Name</th>";
$display_string .= "<th>Team_id</th>";
$display_string .= "<th>Age</th>";
$display_string .= "<th>Dob</th>";
$display_string .= "</tr>";

	// Insert a new row in the table for each person returned
while($row = mysql_fetch_array($result)){
	$display_string .= "<tr>";
	$display_string .= "<td>$row[p_id]</td>";
	$display_string .= "<td>$row[p_name]</td>";
	$display_string .= "<td>$row[team_id]</td>";
	$display_string .= "<td>$row[age]</td>";
	$display_string .= "<td>$row[dob]</td>";
	$display_string .= "</tr>";
	
}
//echo "Query: " . $query . "<br />";
$display_string .= "</table>";
echo $display_string;

?> 
