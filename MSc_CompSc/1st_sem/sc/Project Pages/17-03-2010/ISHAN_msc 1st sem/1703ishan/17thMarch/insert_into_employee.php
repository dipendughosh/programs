<html>
<title>Insert in to employee database</table>
<?php
$con = mysql_connect("localhost","root","tiger");
if (!$con)
  {
  die('Could not connect: ' . mysql_error());
  }  
mysql_select_db("softball", $con);
$sql="INSERT INTO employee(e_id,p_id) VALUES ('$_POST[e_id]','$_POST[p_id]')";
if(mysql_query($sql))
	{
		echo '<br>
			  <div align="center" style=""border: 2px solid black">
			  <font size="10pt">Values Entered successfully</font>
			  </div>' ;	
	}	
echo '<pre>
	  <font size="3pt">
	  <a href="http://localhost/employee.php">previous page</a></font>
	  <font size="3pt"><a href="http://localhost/softball_home.html">Home page</a></font>
	  </pre>';	
?>
</html>