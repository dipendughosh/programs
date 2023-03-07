<?php
	    $n1 = $_POST["labid"];
        $n2 = $_POST["class"];
        $n3 = $_POST["sirid"];
        $n4 = $_POST["asstime"];
        $n5 = $_POST["assday"];
        $n6 = $_POST["subject"];
               
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

$q1="select * from employee where eid='$n3' and desig='proffessor'";
$result2 = mysql_query($q1,$con);
$count1=mysql_num_rows($result2);

$q2="select * from labass where labid='$n1' and asstime='$n4' and assday='$n5'";
$result3 = mysql_query($q2,$con);
$count2=mysql_num_rows($result3);

if($count!=0 and $count1!=0 and $count2==0)
{ 
$new_applicant_insert="INSERT INTO labass(labid,class,sirid,asstime,assday,subject)VALUES('$n1','$n2','$n3','$n4','$n5','$n6')";
echo "<script language=\"javascript\">\n";
		echo "alert('Data inserted successfully');\n";
		echo "document.location.href='labass.html' ";
		echo "</script>";
 } 
else
{echo "<script language=\"javascript\">\n";
		echo "alert('Data not inserted');\n";
		echo "document.location.href='labass.html' ";
		echo "</script>";
	

}		
$query_result = mysql_query($new_applicant_insert,$con);
mysql_close($con);

?>
