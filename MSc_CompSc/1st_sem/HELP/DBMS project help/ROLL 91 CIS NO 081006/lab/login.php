




<?php
$con=mysql_connect("localhost","avishek","12345");
if(!$con)
{
 die('could not connect'.mysql_error());
}
mysql_select_db("lab",$con)
  or die("could not find DB");




$temp1=$_POST['uname'];
$temp2=$_POST['pass'];
if($temp1=="administrator" and $temp2=="admin")
   {
     echo "<script language=\"javascript\">\n";
		echo "document.location.href='home.html' ";
		echo "</script>";
	
     }
	
	
	else
	{
		echo "<script language=\"javascript\">\n";
		echo "alert('wrong id or password');\n";
		echo "document.location.href='starting.html' ";
		echo "</script>";
		
	}
 mysql_close($con);


?>
