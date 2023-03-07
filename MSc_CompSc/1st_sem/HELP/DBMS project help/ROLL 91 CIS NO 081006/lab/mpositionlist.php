<?php
	   
$con=mysql_connect("localhost","avishek","12345");
if(!$con)
{
 die('could not connect'.mysql_error());
}
mysql_select_db("lab",$con)
  or die("could not find DB");



$query="SELECT * FROM machine ORDER BY mid";
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
echo"<body bgcolor=#00FFFF></body>";
echo"<br><br><br><br><br><br><br>";
echo "<table border='5' align='center'>
	<tr>
	<th>MACHINE ID</th>
	<th>CURRENT POSITION</th>
        <th>CORRECT POSITION</th>
        <th>STATUS</th>
        <th>COMPANY</th>
        <th>MODEL</th>
        
</tr>";	

while($row=mysql_fetch_array($result))
{
$t1=$row['mid'];
$t2=$row['apos'];
$t3=$row['cpos'];
$t4=$row['status'];
$t5=$row['company'];
$t6=$row['model'];

echo "<tr>";
	echo "<td><b>".$t1."</b></td>";
        echo "<td><b>".$t2."</b></td>";
        echo "<td><b>".$t3."</b></td>";
	echo "<td><b>".$t4."</b></td>";
        echo "<td><b>".$t5."</b></td>";
        echo "<td><b>".$t6."</b></td>";
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
         







