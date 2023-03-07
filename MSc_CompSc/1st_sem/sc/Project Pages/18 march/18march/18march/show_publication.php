<?php

$con = mysql_connect("localhost","root","");
if (!$con)
  {
  die('Could not connect: ' . mysql_error());
  }
mysql_select_db("faculty", $con);
$pid=$_GET['PUB_id'];
$result = mysql_query("SELECT * FROM Publication where PUB_id='$pid';");

//Build Result String
$display_string = '<table align= center border= 2 cellspacing=2 height=20 width=500>';
$display_string .= "<tr>";
$display_string .= "<th>ID</th>";
$display_string .= "<th>Topic</th>";
$display_string .= "<th>Read_Conference</th>";
$display_string .= "<th>Volume_Number</th>";
$display_string .= "<th>Published_Date</th>";
$display_string .= "</tr>";

	// Insert a new row in the table for each person returned
while($row = mysql_fetch_array($result)){
	$display_string .= "<tr>";
	$display_string .= "<td>$row[PUB_id]</td>";
	$display_string .= "<td>$row[PUB_topic]</td>";
	$display_string .= "<td>$row[PUB_read_conference]</td>";
	$display_string .= "<td>$row[PUB_volume_no]</td>";
	$display_string .= "<td>$row[PUB_pub_date]</td>";
	$display_string .= "</tr>";
	
}
//echo "Query: " . $query . "<br />";
$display_string .= "</table>";
echo $display_string;

?>
