<?php

$db_connection = mysql_connect("localhost","avishek","12345")
  or die("could not connect to DB");
mysql_select_db("med",$db_connection)
  or die("could not find DB");
$temp1=$_POST['formno'];
$temp2=$_POST['as'];
$temp3=$temp1."_".$temp2;
 
$q="SELECT * FROM stdetail WHERE formno='$temp3'";
$r=mysql_query($q); 
$count=mysql_num_rows($r);





$query="DELETE FROM stmarks WHERE formno='$temp3'";
$result=mysql_query($query); 

$query1="DELETE  FROM stdetail WHERE formno='$temp3'";
$result1=mysql_query($query1); 

if($count==0)
 {
   echo "<script language=\"javascript\">\n";
	      echo "alert('No such Form No exist!');\n";
		echo "document.location.href='home.html' ";
		echo "</script>";
	
}
else
 {
 echo "<script language=\"javascript\">\n";
	      echo "alert('Data Successfully Deleted!');\n";
		echo "document.location.href='home.html' ";
		echo "</script>";
	
  }
mysql_close($db_connection);



?>
