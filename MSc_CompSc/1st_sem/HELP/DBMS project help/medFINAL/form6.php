<?php

$db_connection = mysql_connect("localhost","avishek","12345")
  or die("could not connect to DB");
mysql_select_db("med",$db_connection)
  or die("could not find DB");
$n1=$_POST['a'];
$n2=$_POST['category'];
$n3=$_POST['sstatus'];
$n4=$_POST['fname'];
$n5=$_POST['mname'];
$n6=$_POST['lname'];
$n7=$_POST['sex'];
$n8=$_POST['ffname'];
$n9=$_POST['fmname'];
$n10=$_POST['flname'];
$n11=$_POST['phno'];
$n12=$_POST['nationality'];
$n13=$_POST['ggroup'];
$n14=$_POST['dd'];
$n15=$_POST['mm'];
$n16=$_POST['yyyy'];
$n18=$_POST['univ'];
$n17=$n16."-".$n14."-".$n15;
/*$bt=($n3/$n2)*15;
$mt=($n5/$n4)*15;

if($n7==1 || $n8==1)
  $t=8;
else if($n6 ==1)
  $t=4;
else
   $t=0;     
     
$total=$bt+$mt+$t+$n9;*/
/*$n3 = $_POST["category"];
        $n4 = $_POST["univ"];
        $n5 = $_POST["sstatus"];
        $n6 = $_POST["fname"];
        $n7 = $_POST["mname"];
        $n8 = $_POST["lname"];
        $n9 = $_POST["sex"];
        $n10 = $_POST["ffname"];
        $n11= $_POST["fmname"];
        $n12 = $_POST["flname"];
        $n13 = $_POST["phno"];
        $n14= $_POST["nationality"];
        $n15 = $_POST["ggroup"];
        $n17 = $_POST["dd"];
        $n18= $_POST["mm"];
        $n19 = $_POST["yyyy"];
        

*/

$query="UPDATE stdetail SET category='$n2',univ='$n18',sstatus='$n3',fname='$n4',mname='$n5',lname='$n6',sex='$n7',ffname='$n8',fmname='$n9',flname='$n10',phno=$n11,nationality='$n12',ggroup='$n13',dob='$n17' WHERE formno='$n1'";
$result=mysql_query($query); 

	
   echo "<script language=\"javascript\">\n";
	      echo "alert('Data Updated Successfully!');\n";
		echo "document.location.href='HOME.html' ";
		echo "</script>";








mysql_close($db_connection);


?>