<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="content-type" content="text/html; charset=utf-8" />
<title>PROJECT WEBSITE BY M.Sc 1(2009)</title>
<meta name="keywords" content="" />
<meta name="PROJECT WEBSITE" content="" />
<link href="default1.css" rel="stylesheet" type="text/css" />
</head>
<body>
<form action="form2.php" method="post">
<div id="wrapper">
	<div id="header">
		<div id="logo">
			<h1><a href="#">M.Ed.</a></h1>
			<h2> Designed by M.Sc 1(2009),DEPT. OF CIS.</h2>
		</div>
		<!-- end div#logo -->
		<div id="menu">
			<ul>
				<li class="active"><a href="#">Entry</a></li>
				<li><a href="HOME.html">Home</a></li>
				<li><a href="#"></a></li>
				<li><a href="SOUMYA.HTML">Contact</a></li>
			</ul>
		</div>
		<!-- end div#menu -->
	</div>
	<!-- end div#header -->
	<div id="page">
		<div id="content">
			<div id="welcome">

<br><br><h1>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                                                       MERIT LIST </h1>


<?php
$n1=$_POST['as'];	   
$con=mysql_connect("localhost","avishek","12345");
if(!$con)
{
 die('could not connect'.mysql_error());
}
mysql_select_db("med",$con)
  or die("could not find DB");



$query="SELECT * FROM stdetail, stmarks WHERE stdetail.formno = stmarks.formno ORDER BY ttotal DESC";
$result=mysql_query($query); 
$count=mysql_num_rows($result);
if($count==0)
{
  echo "<script language=\"javascript\">\n";
		echo "alert('Sorry!your result is not found.');\n";
		echo "document.location.href='HOME.html' ";
		echo "</script>";
}
else
{
//echo"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
echo "<table border='5' align='center'>
	<tr>
	<th>SL.No</th>
	<th>FORM.No</th>
	<th>NAME</th>
	<th>CATEGORY</th>
    <th>UNIVERSITY</th>
    <th>GROUP</th>
	<th>GRAND TOTAL</th>
	
</tr>";	
$c=1;$e=0;
while($row=mysql_fetch_array($result))
{
$t1=$row['fname'];
$t2=$row['mname'];
$t3=$row['lname'];
$t4=$row['category'];
$t5=$row['univ'];
$t6=$row['phno'];
$t7=$row['sex'];
$t8=$row['ggroup'];
$t9=$row['ttotal'];
$t11=$row['formno'];

$a=explode("_",$t11);
$b=$a[0];
$d=$a[1];

if($t2=='')
 $t10=$t1." ".$t3;
else
 $t10=$t1." ".$t2." ".$t3;

if($t4=='gen')
  $t4='GENERAL';
else if($t4=='sc')
  $t4='SC';
else if($t4=='st')
  $t4='ST';
else if($t4=='obc')
  $t4='OBC';
else if($t4=='ph')
  $t4='PHYSICALLY HANDICAPPRD';

if($t8=='science')
  $t8='SCIENCE & TECH.';
else if($t8=='commerce')
  $t8='COMMERCE';
else if($t8=='language')
  $t8='LANGUAGE';


if($t7='m')
  $t7='MALE';
else
  $t7='FEMALE';

if($t5=='cu')
  $t5='UNIVERSITY OF CALCUTTA';
else
  $t5='OTHER UNIVERSITY';
if($d==$n1)
{echo "<tr>";
	echo "<td><b><font size='2'>".$c."</font></b></td>";
	echo "<td><b><font size='2'>".$b."</font></b></td>";
        echo "<td><b><font size='2'>".$t10."</font></b></td>";
        echo "<td><b><font size='2'>".$t4."</font></b></td>";
	echo "<td><b><font size='2'>".$t5."</font></b></td>";
               echo "<td><b><font size='2'>".$t8."</font></b></td>";
	echo "<td><b><font size='2'>".$t9."</font></b></td>";
	echo "</tr>";
$c++;$e++;
}

}
if($e==0)
{
  echo "<script language=\"javascript\">\n";
		echo "alert('Sorry!no entry in this academic session.');\n";
		echo "document.location.href='genmerit.html' ";
		echo "</script>";
}

echo "</table>";
}
mysql_close($con);


?>
                       

<br><br><br><br>

  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                  <INPUT TYPE="button" value="Print This Page" onClick="window.print()">





































<br><br>










					
			</div>
			<!-- end div#welcome -->
			<div id="sample1" class="boxed">
				
				
			</div>
			<!-- end div#sample1 -->
			<div id="sample2" class="boxed">
				
				
			</div>
			<!-- end div#sample2 -->
		</div>
		<!-- end div#content -->
		<div id="sidebar">
			<ul>
				<li id="submenu">
					
				</li>
				<!-- end li#submenu -->
				<li id="news">
					
				</li>
				<!-- end li#news -->
			</ul>
		</div>
		<!-- end div#sidebar -->
		<div style="clear: both; height: 1px"></div>
	</div>
	<!-- end div#page -->
	<div id="footer">
		<p id="legal"> Designed by M.Sc 1(2009),DEPT. OF CIS. RAJABAZAR SCIENCE COLLEGE.</p>
		
	</div>
	<!-- end div#footer -->
</div>
<!-- end div#wrapper -->

</form>
</body>
</html>
