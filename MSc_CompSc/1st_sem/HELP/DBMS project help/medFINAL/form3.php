<?php

$db_connection = mysql_connect("localhost","avishek","12345")
  or die("could not connect to DB");
mysql_select_db("med",$db_connection)
  or die("could not find DB");
$n1=$_POST['a'];
$n2=$_POST['bedfm'];
$n3=$_POST['bedm'];
$n4=$_POST['mafm'];
$n5=$_POST['mam'];
$n6=$_POST['mph'];
$n7=$_POST['phd'];
$n8=$_POST['nnet'];
$n9=$_POST['wwritten'];


if($n3>$n2 || $n5>$n4 || $n9>50)
{
   echo "<script language=\"javascript\">\n";
	      echo "alert('OBTAINED MARKS OUT OF LIMIT!');\n";
		echo "document.location.href='input.html' ";
		echo "</script>";
}
else
{




$bt=($n3/$n2)*15;
$mt=($n5/$n4)*15;

if($n7==1 || $n8==1)
  $t=8;
else if($n6 ==1)
  $t=4;
else
   $t=0;     
     
$total=$bt+$mt+$t+$n9;


$query="UPDATE stmarks SET bedfm=$n2,bedm=$n3,mafm=$n4,mam=$n5,mph=$n6,phd=$n7,nnet=$n8,wwritten=$n9,ttotal=$total WHERE formno='$n1'";
$result=mysql_query($query); 

	
   echo "<script language=\"javascript\">\n";
	      echo "alert('Data Updated Successfully!');\n";
		echo "document.location.href='HOME.html' ";
		echo "</script>";








mysql_close($db_connection);

}
?>