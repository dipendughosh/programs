
<?php

$db_connection = mysql_connect("localhost","avishek","12345")
  or die("could not connect to DB");
mysql_select_db("med",$db_connection)
  or die("could not find DB");
$temp1=$_POST['formno'];
$temp2=$_POST['as'];
$temp3=$temp1."_".$temp2;


$query="SELECT * FROM stdetail WHERE formno='$temp3'";
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
$t2=$row['category'];
$t3=$row['univ'];
$t4=$row['sstatus'];
$t5=$row['fname'];
$t6=$row['mname'];
$t7=$row['lname'];
$t8=$row['sex'];
$t9=$row['ffname'];
$t10=$row['fmname'];
$t11=$row['flname'];
$t12=$row['phno'];
$t13=$row['nationality'];
$t14=$row['ggroup'];
$t15=$row['dd'];
$t16=$row['mm'];
$t17=$row['yyyy'];

}
	
}

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

mysql_close($db_connection);



?>





-->
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<script type="text/javascript">
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
  if (validate_required(fname,"Firstname must be filled out!")==false)
  {fname.focus();return false;}
  else if (validate_required(lname,"Lastname must be filled out!")==false)
  {lname.focus();return false;}
  else if (validate_required(ffname,"Father's Firstname must be filled out!")==false)
  {ffname.focus();return false;}
  else if (validate_required(flname,"Father's Lastname must be filled out!")==false)
  {flname.focus();return false;}
  
  }
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

 myOption = -1;
 for (i=thisform.category.length-1; i > -1; i--) {
if (thisform.category[i].checked) {
myOption = i; i = -1;
}
}
if (myOption == -1) {
alert("You must select a Category");
return false;
}

myOption = -1;
for (i=thisform.univ.length-1; i > -1; i--) {
if (thisform.univ[i].checked) {
myOption = i; i = -1;
}
}
if (myOption == -1) {
alert("You must select an University!!!");
return false;
}

myOption = -1;
for (i=thisform.sstatus.length-1; i > -1; i--) {
if (thisform.sstatus[i].checked) {
myOption = i; i = -1;
}
}
if (myOption == -1) {
alert("You must select a Status");
return false;
}


myOption = -1;
for (i=thisform.sex.length-1; i > -1; i--) {
if (thisform.sex[i].checked) {
myOption = i; i = -1;
}
}
if (myOption == -1) {
alert("You must select a Sex");
return false;
}

myOption = -1;
for (i=thisform.ggroup.length-1; i > -1; i--) {
if (thisform.ggroup[i].checked) {
myOption = i; i = -1;
}
}
if (myOption == -1) {
alert("You must select a Group at P.G level");
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
<title>Project Website  by Msc 1</title>
<meta name="keywords" content="" />
<meta name="Project Website " content="" />
<link href="default.css" rel="stylesheet" type="text/css" media="screen" />


</head>
<body>
<!-- start header -->
<form  action="form6.php" name="myform" method="post">

<div id="logo">
	<h1><a href="#">M.Ed.  </a></h1>
	<p> Designed by M.Sc 1(2009),DEPT. OF CIS.</p>
</div>
<div id="menu">
	<ul id="main">
		<li class="current_page_item"><a href="HOME.HTML">Home</a></li>
		<li><a href="#">Next Page</a></li>
		<li><a href="#">Services</a></li>
		<li><a href="#">About Us</a></li>
		<li><a href="SOUMYA.HTML">Contact Us</a></li>
	</ul>
	<ul id="feed">
		<li><a href="#">........</a></li>
		<li><a href="#">........</a></li>
	</ul>
</div>
<!-- end header -->
<div id="banner">&nbsp;</div>

<div id="wrapper">
<!-- start page -->
<div id="page">
	<!-- start content -->
	<div id="content">
		<div class="post">
			<h1 class="title"><a href="#">ENTRY FORM</a></h1>
			<p class="byline"><small>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;STARTED ON JUNE 1st, 2009 &nbsp FOR THE STUDENTS OF M.ED</small></p>
			<div class="entry">
				
			</div><marquee>

        <h2><font color="#000000"><br>Enter Student Information</b></h2>  
 </marquee><br><br>
	<tr><td><font size=4 color="#000000"><b>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FORM NO :  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</font></td><td><select name="a">
	<option value="<?=$temp3?>"><?=$temp3?>
	</select></td><br><br>
        
      
<br>
<br>

<font size=4 color="#000000"><b>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;CATEGORY 1 :            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</font>
	<INPUT TYPE="radio"NAME="category" VALUE="gen" <?php if($t2=='gen') echo"CHECKED"?> ><font size=2 color="#000000">GEN&nbsp;&nbsp;</font>
	<INPUT TYPE="radio"NAME="category" VALUE="sc"<?php if($t2=='sc') echo"CHECKED"?>><font size=2 color="#000000">SC&nbsp;&nbsp;</font>
	<INPUT TYPE="radio"NAME="category" VALUE="st" <?php if($t2=='st') echo"CHECKED"?>><font size=2 color="#000000">ST&nbsp;&nbsp;</font>
	<INPUT TYPE="radio"NAME="category" VALUE="ph" <?php if($t2=='ph') echo"CHECKED"?>><font size=2 color="#000000">PH&nbsp;&nbsp;</font>
	<INPUT TYPE="radio"NAME="category" VALUE="obc" <?php if($t2=='obc') echo"CHECKED"?>><font size=2 color="#000000">OBC&nbsp;&nbsp;</font>
<br>
<br>

<font size=4 color="#000000"><b>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;CATEGORY 2 :            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</font>
	
	<INPUT TYPE="radio"NAME="univ" VALUE="cu" <?php if($t3=='cu') echo"CHECKED"?>><font size=2 color="#000000">&nbsp;&nbsp;CALCUTTA UNIVERSITY&nbsp;&nbsp;</font>
	<INPUT TYPE="radio"NAME="univ" VALUE="ou" <?php if($t3=='ou') echo"CHECKED"?>><font size=2 color="#000000">&nbsp;&nbsp;&nbsp;OTHER UNIVERSITY</font>

<br>
<br>
<font size=4 color="#000000"><b>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;CATEGORY 3 :   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;         </font>
	<INPUT TYPE="radio"NAME="sstatus" VALUE="fresher" <?php if($t4=='fresher') echo"CHECKED"?> ><font size=2 color="#000000">&nbsp;FRESHER&nbsp;&nbsp;&nbsp;</font>
	<INPUT TYPE="radio"NAME="sstatus" VALUE="deputed" <?php if($t4=='deputed') echo"CHECKED"?>><font size=2 color="#000000">&nbsp;DEPUTED</font>
<br>
<br>











<tr><td><font size=4 color="#000000"><b>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FIRST NAME : &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</font></td><td><input type="text" name="fname" value="<?=$t5?>" size="30"></td></tr><br><br>
	<tr><td><font size=4 color="#000000"><b>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;MIDDLE NAME :  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</font></td><td><input type="text" name="mname" value="<?=$t6?>" size="30"></td></tr><br><br>
	<tr><td><font size=4 color="#000000"><b>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;LAST NAME : &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</font></td><td><input type="text" name="lname" value="<?=$t7?>" size="30"></td></tr><br><br>
	

<font size=4 color="#000000"><b>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SEX :        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;    </font>
<INPUT TYPE="RADIO"NAME="sex"VALUE="m" <?php if($t8=='m') echo"CHECKED"?>><font size=2 color="#000000">&nbsp;MALE&nbsp;&nbsp;&nbsp;</font>
	<INPUT TYPE="RADIO"NAME="sex"VALUE="f" <?php if($t8=='f') echo"CHECKED"?>><font size=2 color="#000000">&nbsp;FEMALE</font>
<br>
<br>

<tr><td><font size=4 color="#000000"><b>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FATHER'S NAME : &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</font></td><td><input type="text" name="ffname" value="<?=$t9?>" size="30"></td></tr><br><br>
	<tr><td><font size=4 color="#000000"><b>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;MIDDLE NAME :
	  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</font></td><td><input type="text" name="fmname" value="<?=$t10?>" size="30"></td></tr><br><br>
	<tr><td><font size=4 color="#000000"><b>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;LAST NAME : &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</font></td><td><input type="text" name="flname" value="<?=$t11?>" size="30"></td></tr><br><br>
	




<tr><td><font size=4 color="#000000"><b>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;PHONE NUMBER:      &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</font></td><td><input type="text" name="phno" value="<?=$t12?>" size="15"></td></tr><br><br>


<font size=4 color="#000000"><b>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;NATIONALITY :            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</font><select name="nationality">
	<option  value="indian">INDIAN
	<option value="others">OTHERS
	</select>
<br>
<br>


<font size=4 color="#000000"><b>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;DATE OF BIRTH :           &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </font><select name="dd">
	<option value="01">01
	<option value="02">02
	<option value="03">03
	<option value="04">04
	<option value="05">05
	<option value="06">06
	<option value="07">07
	<option value="08">08
	<option value="09">09
	<option value="10">10
	<option value="11">11
	<option value="12">12
	<option value="13">13
	<option value="14">14
	<option value="15">15
	<option value="16">16
	<option value="17">17
	<option value="18">18
	<option value="19">19
	<option value="20">20
	<option value="21">21
	<option value="22">22
	<option value="23">23
	<option value="24">24
	<option value="25">25
	<option value="26">26
	<option value="27">27
	<option value="28">28
	<option value="29">29
	<option value="30">30
	<option value="31">31
</select>

<select name="mm">
<option  value="01">01
<option  value="02">02
<option  value="03">03
<option  value="04">04
<option  value="05">05
<option  value="06">06
<option  value="07">07
<option  value="08">08
<option  value="09">09
<option  value="10">10
<option  value="11">11
<option  value="12">12

</select>

<select name="yyyy">
<option value="1980">1980
<option value="1981">1981
<option value="1982">1982
<option value="1983">1983
<option value="1984">1984
<option value="1985">1985
<option value="1986">1986
<option value="1987">1987
<option value="1988">1988
<option value="1989">1989
<option value="1990">1990
<option value="1991">1991

</select>
<br>
<br>


<font size=4 color="#000000"><b>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;GROUP AT POST-GRADUATION LEVEL :            </font><br><br>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<INPUT TYPE="RADIO"NAME="ggroup"VALUE="science" <?php if($t14=='science') echo"CHECKED"?>><font size=2 color="#000000">SCIENCE &TECH.</font>
	<INPUT TYPE="RADIO"NAME="ggroup"VALUE="commerce" <?php if($t14=='commerce') echo"CHECKED"?>><font size=2 color="#000000">COMMERCE</font>
	<INPUT TYPE="RADIO"NAME="ggroup"VALUE="language" <?php if($t14=='language') echo"CHECKED"?>><font size=2 color="#000000">LANGUAGE</font>
<br>
<br>

<br>
<br>




                                                                                         
                                         &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type="submit" name="Submit" value="UPDATE" onclick="validate_form(myform);return false;" style="color: #000080; font-weight: bold">
                          <marquee><h2><font color="#000000"><br>Enter The Submit Button To UPDATE Student Information</b></h2></marquee>
                                  
  
		</div>
		</div>










	<!-- end content -->
	<!-- start sidebars -->
	<div id="sidebar1" class="sidebar">
		<ul>
		</ul>
	</div>
	<div id="sidebar2" class="sidebar">
		<ul>
	
			
		</ul>
	</div>
	<!-- end sidebars -->
	<div style="clear: both;">&nbsp;</div>
</div>
<!-- end page -->
</div>
<div id="footer">
	<p> Designed by M.Sc 1(2009),DEPT. OF CIS. RAJABAZAR SCIENCE COLLEGE.</p>
</div>
</form>
</body>
</html>
