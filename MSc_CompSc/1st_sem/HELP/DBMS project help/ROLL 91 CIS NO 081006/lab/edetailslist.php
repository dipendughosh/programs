<?php
	   
$con=mysql_connect("localhost","avishek","12345");
if(!$con)
{
 die('could not connect'.mysql_error());
}
mysql_select_db("lab",$con)
  or die("could not find DB");



$query="SELECT * FROM employee ORDER BY eid";
$result=mysql_query($query); 
$count=mysql_num_rows($result);
if($count==0)
{
  echo "<script language=\"javascript\">\n";
		echo "alert('Sorry!your result is not found.');\n";
		echo "document.location.href='home.html' ";
		echo "</script>";
}
else
{
echo"<body bgcolor=#00FFFF>";
echo"<br><br><br><br><br><br><br>";
echo "<table align='center' border='5'>
	<tr>
	<th>EMPLOYEE ID</th>
	<th>NAME</th>
        <th>DESIGNATION</th>
        
</tr>";	

while($row=mysql_fetch_array($result))
{
$t1=$row['eid'];
$t2=$row['fname'];
$t3=$row['lname'];
$t4=$row['desig'];
$t5=$t2." ".$t3;
echo "<tr>";
	echo "<td><b>".$t1."</b></td>";
        echo "<td><b>".$t5."</b></td>";
        echo "<td><b>".$t4."</b></td>";
	
echo "</tr>";
}
echo "</table>";
}
mysql_close($con);


?>
<html>
<body>
<pre>













                                                             <a href="home.html">HOME</a>
</pre>
</body>
</html>