<?php
	    $n1 = $_POST["formno"];
        $n2 = $_POST["as"];
        $n3 = $_POST["category"];
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
        
$n16=$n1."_".$n2;        


$n20=$n19."-".$n17."-".$n18;
        
        
$con=mysql_connect("localhost","avishek","12345");
if(!$con)
{
 die('could not connect'.mysql_error());
}
mysql_select_db("med",$con)
  or die("could not find DB");
$new_applicant_insert="INSERT INTO stdetail(formno,category,univ,sstatus,fname,mname,lname,ffname,fmname,flname,phno,sex,nationality,dob,ggroup)VALUES('$n16','$n3','$n4','$n5','$n6','$n7','$n8','$n10','$n11','$n12',$n13,'$n9','$n14','$n20','$n15')";
$q="select * from stdetail where formno='$n16'";
$result1 = mysql_query($q,$con);
$count=mysql_num_rows($result1);





if($count==0)
{ echo "<script language=\"javascript\">\n";
		echo "alert('Data inserted successfully');\n";
		echo "document.location.href='HOME.html' ";
		echo "</script>";
 } 
else
{echo "<script language=\"javascript\">\n";
		echo "alert('Formno Already inserted');\n";
		echo "document.location.href='index.html' ";
		echo "</script>";
	

}		
$query_result = mysql_query($new_applicant_insert,$con);


$new_applicant_insert1="INSERT INTO stmarks(formno,bedfm,bedm,mafm,mam,mph,phd,nnet,wwritten,ttotal)VALUES('$n16',0,0,0,0,0,0,0,0,0)";
$query_result1 = mysql_query($new_applicant_insert1,$con);


mysql_close($con);

?>
