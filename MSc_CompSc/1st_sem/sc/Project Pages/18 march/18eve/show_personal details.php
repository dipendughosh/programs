<?php

$con = mysql_connect("localhost","root","tiger");
if (!$con)
  {
  die('Could not connect: ' . mysql_error());
  }
mysql_select_db("faculty", $con);
$pid=$_GET['PD_p_id'];
$result = mysql_query("SELECT * FROM personal_details where PD_p_id='$pid';");

//Build Result String
$display_string = '<table align= center border= 2 cellspacing=2 height=20 width=500>';
$display_string .= "<tr>";
$display_string .= "<th>P_ID</th>";
$display_string .= "<th>Name</th>";
$display_string .= "<th>Date_of_Birth</th>";
$display_string .= "<th>Sex</th>";
$display_string .= "<th>Address</th>";
$display_string .= "<th>Pin</th>";
$display_string .= "<th>LandNumber</th>";
$display_string .= "<th>MobileNumber</th>";
$display_string .= "<th>Email</th>";
$display_string .= "<th>Date_of_Joining</th>";
$display_string .= "<th>Qualification</th>";
$display_string .= "<th>Type</th>";
$display_string .= "<th>Post</th>";
$display_string .= "<th>Specialisation</th>";
$display_string .= "</tr>";

	// Insert a new row in the table for each person returned
while($row = mysql_fetch_array($result)){
	$display_string .= "<tr>";
	$display_string .= "<td>$row[PD_p_id]</td>";
	$display_string .= "<td>$row[PD_name]</td>";
	$display_string .= "<td>$row[PD_dob]</td>";
	$display_string .= "<td>$row[PD_male]</td>";
	$display_string .= "<td>$row[PD_address]</td>";
	$display_string .= "<td>$row[PD_pin]</td>";
	$display_string .= "<td>$row[PD_landline]</td>";
	$display_string .= "<td>$row[PD_mobile]</td>";
	$display_string .= "<td>$row[PD_email]</td>";
	$display_string .= "<td>$row[PD_doj]</td>";
	$display_string .= "<td>$row[PD_quali]</td>";
	$display_string .= "<td>$row[PD_type]</td>";
	$display_string .= "<td>$row[PD_post]</td>";
	$display_string .= "<td>$row[PD_special]</td>";
	$display_string .= "</tr>";
	
}
//echo "Query: " . $query . "<br />";
$display_string .= "</table>";
echo $display_string;

?>
