<?php
	    $n1 = $_POST["eid"];
        
$con=mysql_connect("localhost","avishek","12345");
if(!$con)
{
 die('could not connect'.mysql_error());
}
mysql_select_db("lab",$con)
  or die("could not find DB");



$query="SELECT * FROM employee WHERE eid='$n1'";
$result=mysql_query($query); 
$count=mysql_num_rows($result);
if($count==0)
{
  echo "<script language=\"javascript\">\n";
		echo "alert('Sorry!your result is not found.');\n";
		echo "document.location.href='edetails.html' ";
		echo "</script>";
}
else
{

while($row=mysql_fetch_array($result))
{
$t1=$row['eid'];
$t2=$row['fname'];
$t3=$row['lname'];
$t4=$row['desig'];

}
}
$t5=$t2." ".$t3;

mysql_close($con);


?>
<html>
<head>
<title>Test Index</title> <meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
<style>
fieldset.fld1{
	width:90%;
	border-right:none;
	border-bottom:none;
	margin-left:15px;
	padding-top:10px;
	border-top:1px solid #D36A01;
	border-left:1px solid #D36A01;
	}
fieldset.fld2{
	width:90%;
	border-right:1px solid #D36A01;
	border-bottom:none;
	margin-left:15px;
	padding-top:10px;
	border-top:1px solid #D36A01;
	border-left:none;
	}
fieldset.fldintro{
	width:95%;
	border-right:none;
	border-bottom:1px solid #C0C0C0;
	margin-left:15px;
	padding-top:2px;
	border-top:3px double #C0C0C0;
	border-left:none;
	}
h1.topm {
        margin-bottom:0px;
        font-size:11pt;
        font-weight:bold;
        padding-right:5px;
        text-transform:capitalize;
        color:#DDF6EF;
        }
h1.ind1 {
	font-family:serif;
	font-weight:bold;
	font-size:12pt;
	background:#F8EFE5;
	color:#6D570A;
	text-align:left;
	margin-left:22px;
	margin-bottom:0px;
	padding-left:5px;
	border-bottom:1px solid #c0c0c0;
	}
	
.tpm {
	border-top:1px solid black;
	border-bottom:5px solid #04AE9D;
	margin-left:5%;
	margin-right:5%;
	padding-top:5px;
	padding-bottom:2px;
	}
.tdtpm {
	background:#0A6D5C;
	}
p.nav {
	background:#DDF6EF;
	font-family:sans-serif;
	font-size:8pt;
	text-align:center;
	padding-top:2px;
	padding-bottom:2px;
	color:#0A5C65;
	border-bottom:1px solid #c0c0c0;
	}
p.nav1 {
	font-family:sans-serif;
	font-size:8pt;
	text-align:center;
	padding-top:2px;
	padding-bottom:2px;
	color:#0A5C65;
	}
.bd1 {
	background:#f7f7f7;
	font-family:sans-serif;
	font-size:8pt;
	text-align:justify;
	padding-left:15px;
	padding-right:5px;
	padding-bottom:5px;
	color:black;
	}
.bd2 {
	background:#f7f7f7;
	font-family:sans-serif;
	font-size:8pt;
	text-align:justify;
	padding-left:5px;
	padding-right:15px;
	padding-bottom:5px;
	color:black;
	}
ul.st1 {
	font-family:sanq-e iF;
	font-size:8pt;
	padding-left:1px;
	background:#F3F9EB;
	margin-top:0px;
	margin-bottom:0px;
	padding-bottom:5px;
	margin-left:20px;
	color:#EF0087;
	}
li {
	padding:0px;
	}
.fre {
	background:#EBF9F7;
	margin-left:22px;
	}
a:link {
	text-decoration:none;
        color:#0A5C65;
        }
a:visited {
	text-decoration:none;
 	color:#0A5C65;
 	}
a:hover {
	text-decoration:underline;
 	color:#E52401;
 	}
.addr {
	font-family:sans-serif;
	font-size:8pt;
	font-weight:bold;
	}
.tdst {
	border-right:1px solid #c0c0c0;
	}
.hd2 {
	font-family:serif;
	font-size:13pt;
	letter-spacing:3pt;
	font-weight:1200;
	color:#894808;
	}
address {
	        color:turquoise;
		font-size:9pt;
		letter-spacing:0.24em;
		font-style:normal;
		margin-top:3px;
		margin-bottom:3px;
	}
	

</style>
</head>

<body bgcolor="#FFFFFF" >
<table width=90% height=40px align=center border=0>
<tr>
<td width=20%>&nbsp;</td>
<td width=10%>&nbsp;</td>
<td width=70%>&nbsp;</td>
</tr>
</table>
<!-- main body starts here -->
<div class=tpm>
<table width=90% border=0 cellspacing=0 height=45px>
<tr>
<td align=right class=tdtpm ><img border="0" src="imgs/name5.jpg" width="200" height="45"><img src="imgs/CULOGO1A.jpg" border=0 width="116" height="45">

</td>
</tr>
</table>
</div>
<table width=90% border=0 align=center cellspacing=0 cellpadding=0 style="border-bottom:2px solid #F6E1DD;" >
<tr>
<td width=5% colspan=5 align=center><a class=nav href=home.html>Home</a> | <a class=nav href=abt_colg.html>About College</a> | <a class=nav href=a_cal.html>Academic Calendar</a> | <a class=nav href=placement.html>Campus Recruitment</a> | College Rules | <a class=nav href=contact.html>Contact Us</a></td>

</tr>
 <!--#EBF9F0-->
<tr>
<td width=10% bgcolor=#F4EBBE rowspan=3>&nbsp;</td>
 <td  colspan=2 align=left valign=middle>
 <fieldset name=myfl1 class=fldintro>
 <legend align=center>Employee Details</legend>

<pre>



<i><font color="#0000FF" size="4"><span style="background-color: #FFFFFF"><b>
    Employee id No:</b></span></font></i><font color="#0000FF" size="4"><i><b><?=$t1?></b></i></font>



<i><font color="#0000FF" size="4"><span style="background-color: #FFFFFF"><b>
    Name    :</b></span></font></i><font color="#0000FF" size="4"><i><b><?=$t5?></b></i></font>



<i><font color="#0000FF" size="4"><span style="background-color: #FFFFFF"><b>
    Designation  :</b></span></font></i><font color="#0000FF" size="4"><i><b><?=$t4?></b></i></font>



</pre>
</fieldset>
 </td>

<table width=90% cellpadding=0 cellspacing=0 border=0 align=center style="margin-top:2px;">
<tr bgcolor=#0A6D5C>
<td align=center>
<marquee><address>Site developed by <b><a href=# style="color:turquoise;">ARC and is Best Viewed with 1024 by 768 pixels Resolution.</a></b></address></marquee>
</td>
</tr>
</table>
</center>
</body>
</html>

