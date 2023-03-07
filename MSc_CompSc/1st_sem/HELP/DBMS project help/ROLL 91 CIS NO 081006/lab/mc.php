<?php
	    $n1 = $_POST["mid"];
        $n2 = $_POST["apos"];
        $n3 = $_POST["cpos"];
        $n4 = $_POST["status"];
        $n5 = $_POST["company"];
        $n6 = $_POST["model"];        
$con=mysql_connect("localhost","avishek","12345");
if(!$con)
{
 die('could not connect'.mysql_error());
}
mysql_select_db("lab",$con)
  or die("could not find DB");
$new_applicant_insert="INSERT INTO machine(mid,apos,cpos,status,company,model)VALUES('$n1','$n2','$n3','$n4','$n5','$n6')";
$q="select * from labdetail where labid='$n2'";
$result1 = mysql_query($q,$con);
$count=mysql_num_rows($result1);

$q2="select * from labdetail where labid='$n3'";
$result3 = mysql_query($q2,$con);
$count2=mysql_num_rows($result3);

$q1="select * from machine where mid='$n1'";
$result2 = mysql_query($q1,$con);
$count1=mysql_num_rows($result2);

if($count1==0 and $count!=0 and $count2!=0)
{ echo "<script language=\"javascript\">\n";
		echo "alert('Data inserted successfully');\n";
		echo "document.location.href='mc.html' ";
		echo "</script>";
 } 
else
{echo "<script language=\"javascript\">\n";
		echo "alert('Data not inserted');\n";
		echo "document.location.href='mc.html' ";
		echo "</script>";
	

}		
$query_result = mysql_query($new_applicant_insert,$con);
mysql_close($con);

?>
