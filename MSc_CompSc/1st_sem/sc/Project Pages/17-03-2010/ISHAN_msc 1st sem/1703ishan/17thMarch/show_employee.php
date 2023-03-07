<html>
<head>
<title>Show Employee Records</title></head>
<?php
$con = mysql_connect("localhost","root","tiger");
if (!$con)
  {
  die('Could not connect: ' . mysql_error());
  }
mysql_select_db("softball", $con);
$result = mysql_query("SELECT * FROM employee");

echo '<table border= 4 align=center border color=black cellspacing=20 height=150 width=300>
	 <caption><font size= "10pt">Employee Table</font></caption>
	 <tr>
	 <th>E_ID</th>
	 <th>P_ID</th>
	 </tr>';
	 
 while($row = mysql_fetch_array($result))
  {
  echo "<tr>";
  echo "<td><strong>" . $row['e_id'] . "</strong></td>";
  echo "<td><strong>" . $row['p_id'] . "</strong></td>";
  echo "</tr>";
  }
echo "</table>";
mysql_close($con);
echo '<font size= "5pt"><a href="http://localhost/softball_home.html">Home</a></font>
		<pre>&#9</pre>
	  <font size= "5pt"><a href="http://localhost/employee.php">Previous Page</a></font>';	
?>
</html>

	 
