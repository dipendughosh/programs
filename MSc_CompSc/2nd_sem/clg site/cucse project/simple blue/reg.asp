<!-- #include file="ShadowUploader.asp" -->
<%
Dim objUpload

        
If Request("action")="1" Then
	Set objUpload=New ShadowUpload
	If objUpload.GetError<>"" Then
%>
         <script language="javascript">
           <!--
             alert('File not found!');
           //-->
          </script>
 <%
	Else  

		For x=0 To objUpload.FileCount-1
			
			If ((objUpload.File(x).ImageWidth<0) or(objUpload.File(x).ContentType="image/gif")) Then
 %>
                <script language="javascript">
                 <!--
                    alert('Image File is not valid!');
                 //-->
               </script>
 <%
		    Else
			 
			   If (objUpload.File(x).ImageWidth>2000) Or (objUpload.File(x).ImageHeight>2000) Then
%>
                <script language="javascript">
                 <!--
                    alert('Image File is too big for saving.Please try again.');
                 //-->
               </script>
 <%
			    Else  
				   Call objUpload.File(x).SaveToDisk(Server.MapPath("Pics"),objUpload("name"))
 
			    End If
			End If
			
		Next
		
	End If
End If

%>


<html><head>

<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>New User Registration</title>

<link rel="stylesheet" href="reg_files/style.css" type="text/css">

<style>
<!--	
A 		{ color: #C0C0C0; font-weight:bold; text-decoration: none; }		
A:link		{ color: #C0C0C0; font-weight:bold; text-decoration: none; }
A:visited		{ color: #C0C0C0; font-weight:bold; text-decoration: none; }	
A:active		{ color: #358391; font-weight:bold; text-decoration: none;  }	
A:hover		{ color: #358391; font-weight:bold; text-decoration: none;  }

body, td, tr{		
font-family: verdana;		
color:#FFFFFF;		
font-size:11;		
font-weight:normal;
}

//-->
.style1 {
	margin-left: 40px;
}
.style4 {
	text-align: left;
}
.style6 {
	text-align: left;
	margin-left: 40px;
}
.style7 {
	text-align: left;
	margin-left: 80px;
}
.style9 {
	font-family: Verdana, Geneva, Tahoma, sans-serif;
	font-size: xx-small;
}
.style10 {
	font-size: xx-small;
}
.style13 {
	margin-left: 40px;
}
.style14 {
	font-size: small;
}
.style15 {
	font-size: 0.8em;
}
.style16 {
	text-align: center;
}
.style17 {
	border-style: solid;
	border-width: 0px;
}
.picloc {
	border: thick solid #000080;
	padding: 3px;
	margin: 0px;
}
.style18 {
	font-family: "Times New Roman";
	font-size: 40px;
}
.style19 {
	font-size: x-large;
}
</style>
<style type="text/css">
#disablingDiv
{
   /* Do not display it on entry */
    display: none;
    /* Display it on the layer with index 1001.
       Make sure this is the highest z-index value
       used by layers on that page */
    z-index:1001;
    
    /* make it cover the whole screen */
    position: absolute;
    top: 0%;
    left: 0%;
    width: 100%;
    height: 100%;
 
    /* make it white but fully transparent */
	background-color: black;
    opacity:.50;
    filter: alpha(opacity=00);
}
#white_content { 
     display: none; 
     position: absolute; 
     top: 30%; 
     left: 30%; 
     width: 40%; 
     height: 40%; 
     padding: 8px; 
     border: 10px solid orange; 
     background-color: white; 
     z-index:1002; 
     overflow: auto;
   } 
</style>
<style type="text/css">
<!--

.style2 {color: #000000}
-->
</style>

<script type="text/javascript">
var xmlhttp;
var CONF;	
var password;

function start()
{	
	alert("llll");
	insert_AJAX();
}
function insert_AJAX()
{
		alert("llll");
		xmlhttp=GetXmlHttpObject();
				if (xmlhttp==null)
				{
					alert ("Browser does not support HTTP Request");
					return;
				}

	var Surname;
	var Name;
	var Sex,Dob,PrAdd,PrPin,PrLandmark,Mobile,Std,Landline,EmailPer,EmailOff,PtAdd,PtPin,PtLandmark,btech,msc,mtech,phd,YearJoin,YearPass,occ,Com,CurProf,CurDesg,CurCom,CCAdd,CCPin,CCLandmark,CCStd,CCLand,CCFaxStd,CCFax,CaFrom,CaTo,CaName,CbFrom,Cbto,CbName,Dec;
	
	Surname=document.getElementById("surname").value;
	Name=document.getElementById("Name").value;
	
	//alert(document.getElementById("Sex1").checked);
	if(document.getElementById("Sex1").checked==true)
	{
	  Sex=document.getElementById("Sex1").value;
	  //alert(Sex);
    }
	else if(document.getElementById("Sex1").checked=true)
	{
	Sex = document.getElementById("Sex2").value;
	//alert(Sex);
	}
	
	Dob=document.getElementById("Dob").value;
	//alert (Dob);
	
	PrAdd=document.getElementById("PrAdd").value;
	PrPin=document.getElementById("PrPin").value;
	PrLandmark=document.getElementById("PrLandmark").value;
	Mobile=document.getElementById("Mobile").value;
	Std=document.getElementById("Std").value;
	Std += document.getElementById("Landline").value;
	//alert(Std);
	EmailPer=document.getElementById("EmailPer").value;
	EmailOff=document.getElementById("EmailOff").value;
	PtAdd=document.getElementById("PtAdd").value;
	PtPin=document.getElementById("PtPin").value;
	PtLandmark=document.getElementById("PtLandmark").value;
	
	if(document.getElementById("btech").checked==true)
	btech=1;
	else
	btech=0;
	if(document.getElementById("msc").checked==true)
	msc=1;
	else
	msc=0;
	
	if(document.getElementById("mtech").checked==true)
	mtech=1;
	else
	mtech=0;
	
	if(document.getElementById("phd").checked==true)
	phd=1;
    else
    phd=0;
	
	
	YearJoin=document.getElementById("YearJoin").value;
	YearPass=document.getElementById("YearPass").value;
	//alert(YearPass);
	
	//alert(document.getElementById("occ1").checked);
	//alert("222");
	if(document.getElementById("occ1").checked == true)
	{
	  occ=document.getElementById("occ1").value;
	  alert("111")
	   //alert(occ);
	 }
	else if(document.getElementById("occ2").checked==true)
	 {
	   occ=document.getElementById("occ2").value;
	   //alert(occ);
	  }
	else if(document.getElementById("occ3").checked==true)
	{
	occ=document.getElementById("occ3").value;
	//alert(occ);
	}
	else if(document.getElementById("occ4").checked==true)
	{
	occ=document.getElementById("occ4").value;
	//alert(occ);
	}
	
	
	if(document.getElementById("Com1").checked==true)
	{
	Com=document.getElementById("Com1").value;
	//alert(Com);
	}
	
	
	else if(document.getElementById("Com2").checked==true)
	{
	Com=document.getElementById("Com2").value;
	//alert(Com);
	}
	
	CurProf=document.getElementById("CurProf").value;
	CurDesg=document.getElementById("CurDesg").value;
	CurCom=document.getElementById("CurCom").value;
	CCAdd=document.getElementById("CCAdd").value;
	CCPin=document.getElementById("CCPin").value;
	CCLandmark=document.getElementById("CCLandmark").value;
	
	CCStd=document.getElementById("CCStd").value;
	CCStd += document.getElementById("CCLand").value;
	//alert(CCStd);
	
	CCFaxStd=document.getElementById("CCFaxStd").value;
	CCFaxStd += document.getElementById("CCFax").value;
	//alert(CCFaxStd);
	
	CaFrom=document.getElementById("CaFrom").value;
	CaTo=document.getElementById("CaTo").value;
	CaName=document.getElementById("CaName").value;
	CbFrom=document.getElementById("CbFrom").value;
	Cbto=document.getElementById("Cbto").value;
	CbName=document.getElementById("CbName").value;
	//alert(CbName);
	
	if(document.getElementById("Dec1").checked==true)
	Dec=document.getElementById("Dec1").value;
		
	if(document.getElementById("Dec2").checked==true)
	Dec=document.getElementById("Dec2").value;
	
	//alert("!!!!!");
	
	var InsertSql="Insert into profile values('"+ Surname +"','"+Name+"','"+Sex+"','"+Dob+"','"+PrAdd+"','"+PrPin+"','"+PrLandmark+"','"+PtAdd+"','"+PtPin+"','"+PtLandmark+"','"+Mobile+"','"+Std+"','"+EmailOff+"','"+EmailPer+"','"+YearJoin+"','"+YearPass+"','"+occ+"','"+btech+"','"+msc+"','"+mtech+"','"+phd+"','"+CurProf+"','"+CurDesg+"','"+CurCom+"','"+CCAdd+"','"+CCPin+"','"+CCLandmark+"','"+CCStd+"','"+CCFaxStd+"','"+CaFrom+"','"+CaTo+"','"+CaName+"','"+CbFrom+"','"+Cbto+"','"+CbName+"','"+Com+"',";
	
	var url="InsertIntoProfile.asp";
	url=url+"?InsertSql="+InsertSql+"&YearJoin="+YearJoin+"&password="+password+"&Std="+Math.random();	 
	alert(url);
	xmlhttp.open('GET',url,true);
	xmlhttp.onreadystatechange=stateChanged;
	xmlhttp.send(null);
}

function stateChanged()
		{
			if (xmlhttp.readyState==4)
			{
				alert(xmlhttp.responseText);
			}	
		}

		function GetXmlHttpObject()
		{
			if (window.XMLHttpRequest)
			{
				// code for IE7+, Firefox, Chrome, Opera, Safari
				return new XMLHttpRequest();
			}
			if (window.ActiveXObject)
			{
				// code for IE6, IE5
				return new ActiveXObject("Microsoft.XMLHTTP");
			}
		return null;
		}
		
function t()
{
 var x;
   if(document.reg.Name.value=="")
   alert('Please Enter Name first!');
   else
   {
   x=Math.random();
   x=x*10000000000000000;
   x=x%100000000000000000;
	document.form1.name.value=document.reg.Name.value;
	document.form1.name.value=document.form1.name.value+x;
	document.getElementById('disablingDiv').style.display='block';
	document.getElementById('white_content').style.display='block';
    }
}
function check()
{
if(document.form1.file.value=="")
 alert('Nothing to Upload!');
 
 }
</script>

<script language="JavaScript" type="text/JavaScript" src="reg_files/javascript.js"></script>
<script type="text/javascript" language="JavaScript" src="reg_files/base.js"></script>
<script language="JavaScript" src="reg_files/tabel.js" type="text/javascript"></script>
<script language="javascript" type="text/javascript" src="reg_files/proff.htm"></script>
<link rel="SHORTCUT ICON" type="picture" title="SHORTCUT ICON" href="http://www.veebimaja.net/vm01.png">
</head><body topmargin="0" leftmargin="0" background="reg_files/bg.gif" bgcolor="#202020">

<center>
<table bgcolor="#202020" border="0" cellpadding="0" cellspacing="0" height="100%" width="776">
<tbody><tr>
<td bgcolor="#ffffff" width="3"></td>
<td valign="top" width="770">
 
    <table bgcolor="#202020" border="0" cellpadding="0" cellspacing="0" width="770">
    <tbody><tr>
    <td align="right" height="32" valign="middle">Contact: <a href="mailto:yourmail@domain.com">yourmail@domain.com</a> &nbsp;</td> 
    </tr>
    <tr>
    <td align="left" background="reg_files/alumnibanner.jpg" height="132" valign="middle">
	<font size="5">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </font>
	<span class="style18">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; CUCSE 
	ALUMNI PAGES</span><br class="style19"></td> 
    </tr>
    <tr>
    <td height="10"></td> 
    </tr>
    <tr>
    <td align="left" background="reg_files/bluebg.gif" height="32" valign="middle">&nbsp;&nbsp;&nbsp;&nbsp; <a href="#">Link 001</a> | <a href="#">Link 002</a> | <a href="#">Link 003</a> | <a href="#">Link 004</a> | <a href="#">Link 005</a></td> 
    </tr>
    </tbody></table>
     
    <table bgcolor="#464646" border="0" cellpadding="0" cellspacing="0" height="350" width="770">
    <tbody><tr>
    <td class="style16" bgcolor="#202020" valign="top" width="222">
    
        
     <form name= "pic">
    <br><br><div id="picloc">	<img alt="" class="style17" src="Thumbs/mona_thumb.jpg" height="123" width="124">&nbsp;<p><a href = "javascript:void(0)" onclick ="t()">Picture Upload</a></p></div>
     <div id="disablingDiv" ></div>
      </form>
      <div id="white_content"><a href = "javascript:void(0)" onclick = "document.getElementById('white_content').style.display='none'; 
document.getElementById('disablingDiv').style.display='none'">close</a>

<form name = "form1" action="<%=Request.ServerVariables( "Script_Name" )%>?action=1" enctype="multipart/form-data" method="POST">

	  <h3><span class="style2">Please upload a recent picture.</span></h3>
      <h3><span class="style2">After you have finished Uploading,</span></h3>
      <h3><span class="style2">please click on the close button on the Left Upper Corner</span></h3>
	  <br>
      <input name="file" type="file" size="30">
	  <input type="hidden" name="name">
      <br>
      <br>
      <br>
      <input name="upload" type="submit" value="Upload">
  
</form>
</div>
    <td align="right" bgcolor="#ffffff" valign="top" width="3"></td>
    <td style="width: 10px;" align="left" valign="top"><img src="reg_files/shadow1.gif" border="0" height="32" width="10"></td> 
    <td valign="top" width="525"><img src="reg_files/shadow1.gif" border="0" height="32" width="525"><br>
    <strong><span class="style14">New Member Registration Form (Under 
	COnstruction)</span></strong><form name="reg" action="" method="post">
	
		<table style="width: 99%; height: 35px;" class="style10" cellpadding="3">
			<tbody><tr>
				<td class="style6" style="width: 255px;">Surname</td>
				<td style="width: 633px;" class="style13">
				<input name="Surname" style="height: 20px; width: 170px;" size="20" type="text">&nbsp;</td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px;">Name</td>
				<td style="width: 633px;" class="style13">
				<input name="Name" style="height: 20px; width: 170px;" size="20" type="text">&nbsp;</td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px;">Sex</td>
				<td style="width: 633px;" class="style13">
				<input checked="true" name="Sex" value="m" type="radio">Male&nbsp;&nbsp;
				<input name="Sex" value="f" type="radio">&nbsp;Female</td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px;">Date of Birth</td>
				<td style="width: 633px;" class="style13">
				<input name="Dob" style="width: 70px; height: 20px;" size="20" type="text">&nbsp;(mm/dd/yyyy)</td>
			</tr>
			
			<tr>
				<td class="style6" style="width: 255px;">Present Address</td>
				<td style="width: 633px;">
				<input name="PrAdd" style="width: 250px; height: 20px;" size="20" type="text">&nbsp;</td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Pincode</td>
				<td style="width: 633px; height: 17px;" class="style1">
				<input name="PrPin" style="width: 70px; height: 20px;" size="20" type="text">&nbsp;&nbsp; 
				Landmark&nbsp;
				<input name="PrLandmark" style="width: 102px; height: 18px;" size="20" type="text"></td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Mobile</td>
				<td style="width: 633px; height: 17px;">
				<input name="Mobile" style="width: 85px; height: 20px;" size="20" type="text"> 
				(prefix 0 in number belongs to outside West Bengal)</td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Landline</td>
				<td style="width: 633px; height: 17px;" class="style1">
				<input name="Std" style="width: 52px; height: 21px;" size="20" type="text">&nbsp;
				<input name="Landline" style="width: 90px; height: 20px;" size="20" type="text"> 
				(attach STD code)</td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Email ID&nbsp; 
				Personal</td>
				<td style="width: 633px; height: 17px;">
				<input name="EmailPer" style="width: 150px; height: 20px;" size="20" type="text"></td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Email ID&nbsp; 
				Official</td>
				<td style="width: 633px; height: 17px;" class="style1">
				<input name="EmailOff" style="width: 150px; height: 20px;" size="20" type="text">&nbsp;</td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Permanent 
				Address</td>
				<td style="width: 633px; height: 17px;">
				<input name="PtAdd" style="width: 250px; height: 20px;" size="20" type="text">&nbsp;</td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Pincode</td>
				<td style="width: 633px; height: 17px;" class="style1">
				<input name="PtPin" style="width: 85px; height: 20px;" size="20" type="text">&nbsp;&nbsp; 
				Landmark&nbsp;
				<input name="PtLandmark" style="width: 89px; height: 20px;" size="20" type="text"></td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Course 
				Studied in CUCSE</td>
				<td style="width: 633px; height: 17px;" class="style13">
                BTech<input name="btech" value="1" type="checkbox">&nbsp;&nbsp;&nbsp; 
				MSc<input name="msc" value="1" type="checkbox">&nbsp;&nbsp;&nbsp; 
				Mtech<input name="mtech" value="1" type="checkbox">&nbsp;&nbsp;&nbsp; 
				Phd<input name="phd" value="1" type="checkbox"></td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Year of 
				Joining CUCSE</td>
				<td style="width: 633px; height: 17px;" class="style13">
				<input name="YearJoin" style="width: 60px; height: 20px;" size="20" type="text"></td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Year of 
				Passing CUCSE</td>
				<td style="width: 633px; height: 17px;" class="style13">
				<input name="YearPass" style="width: 60px; height: 20px;" size="20" type="text"></td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Occupational Status</td>
				<td style="width: 633px; height: 17px;" class="style13">
				Self-Employed<input name="occ" value="semp" type="radio">&nbsp;&nbsp; 
				Salaried<input name="occ" value="slr" type="radio">&nbsp;&nbsp; 
				Retired<input name="occ" value="rtd" type="radio">&nbsp;&nbsp; 
				Others<input name="occ" value="oth" type="radio"> </td>
			</tr>
            
			<tr>
				<td class="style4" style="height: 17px; width: 132px;">Preferred Way of 
				Communication</td>
				<td class="style7" style="height: 17px;">
				<input name="Com" value="phone" type="radio">&nbsp;Phone&nbsp;&nbsp;&nbsp;
				<input name="Com" value="email" type="radio">Email</td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Current 
				Profession</td>
				<td style="width: 633px; height: 17px;" class="style1">
				<input name="CurProf" style="width: 150px; height: 20px;" size="20" type="text"></td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Current 
				Designation</td>
				<td style="width: 633px; height: 17px;" class="style1">
				<input name="CurDesg" style="width: 150px; height: 20px;" size="20" type="text"></td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Name of 
				Current Company/College/ Institute/Organization</td>
				<td style="width: 633px; height: 17px;" class="style1">
				<input name="CurCom" style="width: 150px; height: 20px;" size="20" type="text">&nbsp; 
				(Initals not allowed)</td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Address 
				of Company/College/ Institute/Organization</td>
				<td style="width: 633px; height: 17px;" class="style1">
				<input name="CCAdd" style="width: 250px; height: 20px;" size="20" type="text">&nbsp;</td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Pincode</td>
				<td style="width: 633px; height: 17px;" class="style1">
				<input name="CCPin" style="width: 85px; height: 20px;" size="20" type="text">&nbsp;&nbsp; 
				Landmark&nbsp;
				<input name="CCLandmark" style="width: 89px; height: 20px;" size="20" type="text"></td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Company 
				Contact Number</td>
				<td style="width: 633px; height: 17px;" class="style1">
				<input name="CCStd" style="width: 52px; height: 20px;" size="20" type="text">&nbsp;
				<input name="CCLand" style="width: 90px; height: 19px;" size="20" type="text">&nbsp; 
				(attach STD code)</td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Company 
				Fax Number</td>
				<td style="width: 633px; height: 17px;" class="style1">
				<input name="CCFaxStd" style="width: 52px; height: 20px;" size="20" type="text">&nbsp;
				<input name="CCFax" style="width: 90px; height: 20px;" size="20" type="text">&nbsp; 
				(attach STD code)</td>
			</tr>
			<tr>
				<td class="style2" style="height: 17px;" colspan="2">If you have 
				been an employee in a company for less than one year (unless you 
				have joined the service in the current year), please furnish the 
				last TWO company/college/institute/organization details for 
				which you had been working:</td>
			</tr>
			<tr>
				<td class="style4" style="height: 17px;">
				<p>(a) From (specify year)</p>
				</td>
				<td class="style7" style="height: 17px;">
				<input name="CaFrom" style="width: 52px; height: 20px;" size="20" type="text">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
				To (specify year)&nbsp;&nbsp;&nbsp;
				<input name="CaTo" style="width: 52px; height: 20px;" size="20" type="text"></td>
			</tr>
			<tr>
				<td class="style4" style="height: 17px;">Name of&nbsp; 
				Company/College/ Institute/Organization</td>
				<td class="style7" style="height: 17px;">
				<input name="CaName" style="width: 150px; height: 20px;" size="20" type="text">&nbsp;</td>
			</tr>
			<tr>
				<td class="style4" style="height: 17px;">(b) From (specify year)</td>
				<td class="style7" style="height: 17px;">
				<input name="CbFrom" style="width: 52px; height: 20px;" size="20" type="text">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
				To (specify year)&nbsp;&nbsp;&nbsp;
				<input name="Cbto" style="width: 52px; height: 20px;" size="20" type="text"></td>
			</tr>
			<tr>
				<td class="style4" style="height: 17px;">Name of&nbsp; 
				Company/College/ Institute/Organization</td>
				<td class="style7" style="height: 17px;">
				<input name="CbName" style="width: 150px; height: 20px;" size="20" type="text">&nbsp;</td>
			</tr>
			<tr>
				<td class="style4" style="height: 17px;" colspan="2">
				<textarea class="style9" name="TextArea1" style="width: 463px; height: 76px;" rows="1" cols="20">SELF
DECLARATION
I owe allegiance to the Department of Computer Science &amp;
Engineering, and have not purposely or mistakenly filled up the form
with other identity. The information given by me in this form is true
to the best of my believe and I am solely responsible for its accuracy.
I am aware that it is an offence to furnish any false information or to
suppress any material information with a view to obtain the facilities
of being an alumni and I agree that my registration may be withdrawn or
cancelled if any false or suppressed information is produced.</textarea>&nbsp;</td>
			</tr>
			<tr>
				<td class="style4" style="height: 17px;" colspan="2">
				<input name="Dec" value="y" type="radio">I Agree&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
				<input name="Dec" value="n" type="radio">I Disagree</td>
			</tr>
			<tr>
				<td class="style4" style="height: 17px;" colspan="2">
				<input class="style10" name="Submit1" style="width: 68px; height: 21px;" value="Submit" type="submit"></td>
			</tr>
		</tbody></table>
	
	</form>
    </td>  
    <td align="left" valign="top" width="10"><img src="reg_files/shadow1.gif" border="0" height="32" width="10"></td> 
    </tr>
    </tbody></table> 
 
    <table bgcolor="#464646" border="0" cellpadding="0" cellspacing="0" height="32" width="770">
    <tbody><tr>
    <td align="left" bgcolor="#202020" valign="top" width="222"></td>
    <td align="right" bgcolor="#ffffff" valign="top" width="3"></td>
    <td align="left" valign="top" width="10"><img src="reg_files/shadow2.gif" border="0" height="32" width="10"></td> 
    <td align="left" valign="top" width="525"><img src="reg_files/shadow2.gif" border="0" height="32" width="525"></td>  
    <td align="left" valign="top" width="10"><img src="reg_files/shadow2.gif" border="0" height="32" width="10"></td> 
    </tr>
    </tbody></table>
 
    <table bgcolor="#202020" border="0" cellpadding="0" cellspacing="0" width="770">
    <tbody><tr>
    <td align="left" background="reg_files/bluebg.gif" height="32" valign="middle" width="30"><img src="reg_files/pixel.gif" border="0" height="1" width="5"></td>
    <td align="right" background="reg_files/bluebg.gif" height="32" valign="middle" width="740">© 2007 - ... yourdomain.com &nbsp; </td> 
    </tr>
    </tbody></table>  

</td>
<td bgcolor="#ffffff" width="3"></td>
</tr>
</tbody></table>
</center>


<div style="text-align: center; margin-top: 1em; margin-bottom: 1em;" class="style15">
<a href="http://alumni.cucse.org/">	www.cucse.org</a></div>
</body></html>