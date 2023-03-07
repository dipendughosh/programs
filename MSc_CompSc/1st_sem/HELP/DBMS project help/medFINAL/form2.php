
<?php

$db_connection = mysql_connect("localhost","avishek","12345")
  or die("could not connect to DB");
mysql_select_db("med",$db_connection)
  or die("could not find DB");
$temp1=$_POST['formno'];
$temp2=$_POST['as'];
$temp3=$temp1."_".$temp2;


$query="SELECT * FROM stmarks WHERE formno='$temp3'";
$result=mysql_query($query); 
$count=mysql_num_rows($result);

if($count==0)
 {
   echo "<script language=\"javascript\">\n";
	      echo "alert('No such Form No exist!');\n";
		echo "document.location.href='input.html' ";
		echo "</script>";
	
}
else {
while($row=mysql_fetch_array($result))
{
$t1=$row['formno'];
$t2=$row['bedfm'];
$t3=$row['bedm'];
$t4=$row['mafm'];
$t5=$row['mam'];
$t6=$row['mph'];
$t7=$row['phd'];
$t8=$row['nnet'];
$t9=$row['wwritten'];

}
	
}




mysql_close($db_connection);



?>



<html xmlns="http://www.w3.org/1999/xhtml">
<head>



<!--<script type="text/javascript">
function validate_required(field,alerttxt)
{
with (field)
  {
  if (value==null||value=="")
    {
    alert(alerttxt);return false;
    }
  else
    {
    return true;
    }
  }
}
function validate_form(thisform)
{
with (thisform)
  {
  if (validate_required(mph,"Qualification of M.Phil must be filled out!")==false)
  {mph.focus();return false;}
  else if (validate_required(phd,"Qualification of Ph.D must be filled out!")==false)
  {phd.focus();return false;}
  else if (validate_required(nnet,"Qualification of NET/SET must be filled out!")==false)
  {nnet.focus();return false;}
  
  }
}
</script>
-->

<script type="text/javascript">

function valbutton(thisform) {
myOption = -1;
for (i=thisform.mph.length-1; i > -1; i--) {
if (thisform.mph[i].checked) {
myOption = i; i = -1;
}
}
if (myOption == -1) {
alert("You must select a qualification for M.Phil");
return false;
}

myOption = -1;
for (i=thisform.phd.length-1; i > -1; i--) {
if (thisform.phd[i].checked) {
myOption = i; i = -1;
}
}
if (myOption == -1) {
alert("You must select a qualification for Phd");
return false;
}

myOption = -1;
for (i=thisform.nnet.length-1; i > -1; i--) {
if (thisform.nnet[i].checked) {
myOption = i; i = -1;
}
}
if (myOption == -1) {
alert("You must select a qualification for NET/SET");
return false;
}


/*alert("You selected button number " + myOption
+ " which has a value of "
+ thisform.myradiobutton[myOption].value);
*/
thisform.submit();
}
</script>



<meta http-equiv="content-type" content="text/html; charset=utf-8" />
<title>PROJECT WEBSITE BY M.Sc 1(2009)</title>
<meta name="keywords" content="" />
<meta name="PROJECT WEBSITE" content="" />
<link href="default1.css" rel="stylesheet" type="text/css" />
</head>
<body>
<form action="form3.php" name="myform" method="post">

<div id="wrapper">
	<div id="header">
		<div id="logo">
			<h1><a href="#">M.ED</a></h1>
			<h2>DESIGNED By M.Sc.1(2009), DEPT. OF CIS.</h2>
		</div>
		<!-- end div#logo -->
		<div id="menu">
			<ul>
				<li class="active"><a href="#">Entry</a></li>
				<li><a href="HOME.HTML">Home</a></li>
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
				<h1>ACADEMIC QUALIFICATIONS</h1>
			
<br><br> 
<font size=4><b>Form.No.</font>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<select name="a">
	<option value="<?=$temp3?>"><?=$temp3?>
	</select></td><BR><BR><br>	
	
	
<tr><td><font size=4 color="#000000">EXAMINATIONS PASSED     &nbsp;  |  &nbsp;  FULL MARKS  &nbsp;   |  &nbsp;  MARKS OBTAINED      </font></td><td>
<BR><BR>	
	
	
	<br><br><br>
	<font size=4><b>B.ED.</font>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type="text" name="bedfm" value="<?=$t2?>" size="4"></td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type="text" name="bedm" value="<?=$t3?>" size="4"></td><br><br><br>

<font size=4><b>M.A./M.Sc./M.COM.</font>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type="text" name="mafm" value="<?=$t4?>" size="4"></td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type="text" name="mam" value="<?=$t5?>" size="4"></td><br><br><br>

<font size=4><b>M.PHIL.</font>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;	<INPUT TYPE="radio"NAME="mph" VALUE="1" <?php if($t6==1) echo"CHECKED" ?>  ><font size=2 color="#000000">Qualified&nbsp;&nbsp;</font>
</td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<INPUT TYPE="radio"NAME="mph" VALUE="0" <?php if($t6==0) echo"CHECKED" ?>><font size=2 color="#000000">Not Qualified&nbsp;&nbsp;</font></td><br><br><br>


<font size=4><b>PHD.</font>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;	<INPUT TYPE="radio"NAME="phd" VALUE="1" <?php if($t7==1) echo"CHECKED" ?> ><font size=2 color="#000000">Qualified&nbsp;&nbsp;</font>
</td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<INPUT TYPE="radio"NAME="phd" VALUE="0" <?php if($t7==0) echo"CHECKED" ?> ><font size=2 color="#000000">Not Qualified&nbsp;&nbsp;</font></td><br><br><br>


<font size=4><b>NET./SET.</font>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;	<INPUT TYPE="radio"NAME="nnet" VALUE="1" <?php if($t8==1) echo"CHECKED" ?> ><font size=2 color="#000000">Qualified&nbsp;&nbsp;</font>
</td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<INPUT TYPE="radio"NAME="nnet" VALUE="0" <?php if($t8==0) echo"CHECKED" ?> ><font size=2 color="#000000">Not Qualified&nbsp;&nbsp;</font></td><br><br><br>
<font size=4><b>Written Examination.</font>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;50</td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type="text" name="wwritten" value="<?=$t9?>" size="4"></td><br><br><br>
&nbsp;<input type="submit" name="Submit" onclick="valbutton(myform);return false;" value="SUBMIT" style="color: #000080; font-weight: bold">



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
		<p id="legal"> Designed by M.Sc 1(2009),DEPT. OF CIS. RAJABAZAR SCIENCE COLLEGE. </p>
		
	</div>
	<!-- end div#footer -->
</div>
<!-- end div#wrapper -->
</form>
</body>
</html>
