<?php

$con = mysql_connect("localhost","root","tiger");
if (!$con)
  {
  die('Could not connect: ' . mysql_error());
  }
mysql_select_db("faculty", $con);
$pid=$_GET['PR_id'];
$result = mysql_query("SELECT * FROM projects where PR_id='$pid';");

//Build Result String
$display_string = '<table align= center border= 2 cellspacing=2 height=20 width=500>';
$display_string .= "<tr>";
$display_string .= "<th>ID</th>";
$display_string .= "<th>Topic</th>";
$display_string .= "<th>Headname</th>";
$display_string .= "<th>FundedBy</th>";
$display_string .= "<th>Type_of_project</th>";
$display_string .= "<th>Type_of_project</th>";
$display_string .= "</tr>";

	// Insert a new row in the table for each person returned
while($row = mysql_fetch_array($result)){
	$display_string .= "<tr>";
	$display_string .= "<td>$row[PR_id]</td>";
	$display_string .= "<td>$row[PR_topic]</td>";
	$display_string .= "<td>$row[PR_headname]</td>";
	$display_string .= "<td>$row[PR_fundedby]</td>";
	$display_string .= "<td>$row[PR_typeofproject]</td>";
	$display_string .= "<td>$row[PR_status]</td>";
	$display_string .= "</tr>";
	
}
//echo "Query: " . $query . "<br />";
$display_string .= "</table>";
echo $display_string;

?>
