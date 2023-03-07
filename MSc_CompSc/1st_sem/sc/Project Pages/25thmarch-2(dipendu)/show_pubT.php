<?php

$con=mysql_connect("localhost","root","");
if (!$con)
  {
  die('Could not connect: ' . mysql_error());
  }
  
	mysql_select_db("faculty", $con);

	$PUB_view1_from_date=$_GET['PUB_view1_from_date'];
	$PUB_view1_to_date=$_GET['PUB_view1_to_date'];

	$result = mysql_query("SELECT PUB_author,count(*) 'NUMBER' from publications where PUB_pub_date >='$PUB_view1_from_date' and PUB_pub_date <='$PUB_view1_to_date' GROUP BY PUB_author;");
	 
	$display_string  ='<table align="center" border="2" cellspacing="2" height="20" width="500" class="main">';
	$display_string .= "<tr>";
	$display_string .= "<th>Name Of The Author</th>";
	$display_string .= "<th>Number Of New Publications</th>";
	$display_string .= "</tr>";	

 	while($row = mysql_fetch_array($result))
	{	
		$display_string .= "<tr>";
		$display_string .= "<td width='70%'>$row[PUB_author]</td>";
		$display_string .= "<td width='30%'>$row[NUMBER]</td>";
		$display_string .= "</tr>";	
	}
	$display_string .='</table>';
	echo $display_string;
	

?>
	
