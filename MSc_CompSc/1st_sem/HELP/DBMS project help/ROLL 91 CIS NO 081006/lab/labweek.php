<?php
	    $n1 = $_POST["labid"];
        
$con=mysql_connect("localhost","avishek","12345");
if(!$con)
{
 die('could not connect'.mysql_error());
}
mysql_select_db("lab",$con)
  or die("could not find DB");



$query="SELECT * FROM labass WHERE labid='$n1'";
$result=mysql_query($query); 
$count=mysql_num_rows($result);
if($count==0)
{
  echo "<script language=\"javascript\">\n";
		echo "alert('Sorry!your result is not found.');\n";
		echo "document.location.href='labweek.html' ";
		echo "</script>";
}


else
{
echo"<body bgcolor=#00FFFF></body>";
echo"<br><br><br><br><br>";
echo"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font size='4'>                            WEEKLY LAB ASSIGNMENT FOR LAB ID:$n1</font><br>";
echo "<table border='5' align='center'>
	<tr>
	<th>BATCH</th>
        <th>PROFESSOR ID</th>
        <th>TIME</th>
        <th>DAY</th>
        <th>SUBJECT</th>
        
</tr>";	

while($row=mysql_fetch_array($result))
{
$t1=$row['class'];
$t2=$row['sirid'];
$t3=$row['asstime'];
$t4=$row['assday'];
$t5=$row['subject'];

echo "<tr>";
	echo "<td><b>".$t1."</b></td>";
        echo "<td><b>".$t2."</b></td>";
        echo "<td><b>".$t3."</b></td>";
	echo "<td><b>".$t4."</b></td>";
        echo "<td><b>".$t5."</b></td>";
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