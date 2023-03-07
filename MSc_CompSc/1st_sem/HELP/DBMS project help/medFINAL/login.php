




<?php
$con=mysql_connect("localhost","debraj","12345");
if(!$con)
{
 die('could not connect'.mysql_error());
}
mysql_select_db("med",$con)
  or die("could not find DB");




$temp1=$_POST['uname'];
$temp2=$_POST['pass'];
if($temp1=="administrator" and $temp2=="admin")
   {
     echo "<script language=\"javascript\">\n";
		echo "document.location.href='HOME.html' ";
		echo "</script>";
	
     }
	
	
	else
	{
		echo "<script language=\"javascript\">\n";
		echo "alert('wrong id or password');\n";
		echo "document.location.href='login.html' ";
		echo "</script>";
		
	}
 mysql_close($con);


?>
