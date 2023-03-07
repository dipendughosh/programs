<?php
	    $n1 = $_POST["eid"];
        $n2 = $_POST["fname"];
        $n3 = $_POST["lname"];
        $n4 = $_POST["desig"];
        
$con=mysql_connect("localhost","avishek","12345");
if(!$con)
{
 die('could not connect'.mysql_error());
}
mysql_select_db("lab",$con)
  or die("could not find DB");
$new_applicant_insert="INSERT INTO employee(eid,fname,lname,desig)VALUES('$n1','$n2','$n3','$n4')";
$q="select * from employee where eid='$n1'";
$result1 = mysql_query($q,$con);
$count=mysql_num_rows($result1);

if($count==0)
{ echo "<script language=\"javascript\">\n";
		echo "alert('Data inserted successfully');\n";
		echo "document.location.href='employee.html' ";
		echo "</script>";
 } 
else
{echo "<script language=\"javascript\">\n";
		echo "alert('Data not inserted');\n";
		echo "document.location.href='employee.html' ";
		echo "</script>";
	

}		
$query_result = mysql_query($new_applicant_insert,$con);
mysql_close($con);

?>
