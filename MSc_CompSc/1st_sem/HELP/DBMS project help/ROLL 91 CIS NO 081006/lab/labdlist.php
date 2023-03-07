<?php
	   
$con=mysql_connect("localhost","avishek","12345");
if(!$con)
{
 die('could not connect'.mysql_error());
}
mysql_select_db("lab",$con)
  or die("could not find DB");



$query="SELECT * FROM labdetail ORDER BY labid";
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
	<th>Laboratory ID</th>
	<th>Laboratory NAME</th>
        <th>Lab Incharge ID</th>
        <th>No Of Machines</th>

</tr>";	

while($row=mysql_fetch_array($result))
{
$t1=$row['labid'];
$t2=$row['labname'];
$t3=$row['inchargeid'];
$t4=$row['no_machine'];
echo "<tr>";
	echo "<td><b>".$t1."</b></td>";
        echo "<td><b>".$t2."</b></td>";
        echo "<td><b>".$t3."</b></td>";
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
         







