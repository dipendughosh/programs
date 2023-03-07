<?php
	    $n1 = $_POST["labid"];
        $n2 = $_POST["labname"];
        $n3 = $_POST["inchargeid"];
        $n5 = $_POST["no_machine"];
        
$con=mysql_connect("localhost","avishek","12345");
if(!$con)
{
 die('could not connect'.mysql_error());
}
mysql_select_db("lab",$con)
  or die("could not find DB");
$q="select * from labdetail where labid='$n1'";
$result1 = mysql_query($q,$con);
$count=mysql_num_rows($result1);

$q1="select * from employee where eid='$n3' and desig='clerk'";
$result2 = mysql_query($q1,$con);
$count1=mysql_num_rows($result2);

if($count==0 and $count1!=0)
{$new_applicant_insert="INSERT INTO labdetail(labid,labname,inchargeid,no_machine)VALUES('$n1','$n2','$n3',$n5)";

 echo "<script language=\"javascript\">\n";
		echo "alert('Data inserted successfully');\n";
		echo "document.location.href='lab.html' ";
		echo "</script>";
 } 
else
{echo "<script language=\"javascript\">\n";
		echo "alert('Data not inserted');\n";
		echo "document.location.href='lab.html' ";
		echo "</script>";
	

}		
$query_result = mysql_query($new_applicant_insert,$con);
mysql_close($con);

?>
