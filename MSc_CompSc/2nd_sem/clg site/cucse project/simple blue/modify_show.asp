<HTML>
<HEAD>

<%
'declare the variables
Dim Connection
Dim ConnString
Dim sql2
Dim userId
Dim Recordset

'define the connection string, specify database driver
ConnString="DRIVER={SQL Server};SERVER=cucse.org;UID=admincucse;" & _
"PWD=cucse123;DATABASE=cucse"

'create an instance of the ADO connection and recordset objects
Set Connection = Server.CreateObject("ADODB.Connection")
Set Recordset = Server.CreateObject("ADODB.Recordset")

'declare the SQL statement that will query the database
sql2="Select * from prof where alumni_id='ALCUCSE10'"

'Open the connection to the database
Connection.Open ConnString

Recordset.Open sql2,Connection

if  Recordset.EOF Then
	Recordset.Close
	Set Recordset=nothing
	Connection.Close
	Set Connection=nothing
end if	

%>


<meta http-equiv=Content-Type content="text/html;  charset=ISO-8859-1">
<TITLE>Modify User's Information</TITLE>

<link rel="stylesheet" href="style.css" type="text/css">

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
</style>

<!--<script language="JavaScript" type="text/JavaScript" src="java/javascript.js"></script>
<SCRIPT TYPE="text/javascript" LANGUAGE="JavaScript" SRC="java/base.js"></SCRIPT>
<script language="JavaScript" src="java/tabel.js" type="text/javascript"></script>
<script language="javascript" type="text/javascript" src="java/proff.js"></script>-->
<script type="text/javascript">
var xmlhttp;
var CONF;	

function start()
{	
	//alert("llll");
	modify_AJAX();
}
function modify_AJAX()
{
		//alert("llll");
		xmlhttp=GetXmlHttpObject();
				if (xmlhttp==null)
				{
					alert ("Browser does not support HTTP Request");
					return;
				}

	var Surname;
	var Name;
	var Sex,Dob,PrAdd,PrPin,PrLandmark,Mobile,Std,EmailPer,EmailOff,PtAdd,PtPin,PtLandmark,btech,msc,mtech,phd,YearJoin,YearPass,occ,Com,CurProf,CurDesg,CurCom,CCAdd,CCPin,CCLandmark,CCStd,CCLand,CCFaxStd,CCFax,CaFrom,CaTo,CaName,CbFrom,Cbto,CbName,Dec;
	
	Surname=document.getElementById("surname").value;
	Name=document.getElementById("Name").value;
	
	//alert(document.getElementById("Sex1").checked);
	if(document.getElementById("Sex1").checked==true)
	{
	  Sex=document.getElementById("Sex1").value;
	  //alert(Sex);
    }
	else if(document.getElementById("Sex2").checked==true)
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
	Std= document.getElementById("Landline").value;
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

	CCStd= document.getElementById("CCLand").value;
	//alert(CCStd);
	
	CCFaxStd= document.getElementById("CCFax").value;
	//alert(CCFaxStd);
	
	CaFrom=document.getElementById("CaFrom").value;
	CaTo=document.getElementById("CaTo").value;
	CaName=document.getElementById("CaName").value;
	CbFrom=document.getElementById("CbFrom").value;
	Cbto=document.getElementById("Cbto").value;
	CbName=document.getElementById("CbName").value;
	//alert(CbName);
	
	var ModifySql="Update prof set surname='"+ Surname +"',name='"+Name+"',sex='"+Sex+"',date_of_birth='"+Dob+"',present_address='"+PrAdd+"',present_pin='"+PrPin+"',present_landmark='"+PrLandmark+"',permanent_address='"+PtAdd+"',permanent_pin='"+PtPin+"',permanent_landmark='"+PtLandmark+"',mobile_no='"+Mobile+"',landline='"+Std+"',office_email='"+EmailOff+"',personal_email='"+EmailPer+"',yoj='"+YearJoin+"',yop='"+YearPass+"',occ_stat='"+occ+"',course_btech='"+btech+"',course_msc='"+msc+"',course_mtech='"+mtech+"',course_phd='"+phd+"',curr_prof='"+CurProf+"',curr_desg='"+CurDesg+"',curr_comp='"+CurCom+"',comp_add='"+CCAdd+"',comp_pin='"+CCPin+"',comp_landmark='"+CCLandmark+"',comp_cont_no='"+CCStd+"',comp_fax='"+CCFaxStd+"',comp1_frm_yr='"+CaFrom+"',comp1_to_yr='"+CaTo+"',name_comp1='"+CaName+"',comp2_frm_yr='"+CbFrom+"',comp2_to_yr='"+Cbto+"',name_comp2='"+CbName+"',pref_comm='"+Com+"'";
	//alert(ModifySql);
	var url="modify.asp";
	url=url+"?ModifySql="+ModifySql+"&Std="+Math.random();	 
	//alert(url);
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
		
		function check()
		{
			var sex,occ_stat,pref_comm,course;
			sex=<%=Recordset("sex")%>;
			alert(sex);
			if(sex=="m")
			{
				document.getElementById("Sex1").checked==true;
			}
			else
			{
				document.getElementById("Sex2").checked==true;
			}
		}
			
		
</script>
</HEAD>
<BODY background="img/bg.gif" bgcolor="#202020" topmargin="0" leftmargin="0" onload="javascript:check()">

<center>
<table bgcolor="#202020" width="776" height="100%" border="0" cellspacing="0" cellpadding="0">
<tr>
<td width="3" bgcolor="#FFFFFF"></td>
<td width="770" valign="top">
 
    <table bgcolor="#202020" width="770" border="0" cellspacing="0" cellpadding="0">
    <tr>
    <td height="32" align="right" valign="middle">Contact: <a href="mailto:yourmail@domain.com">yourmail@domain.com</a> &nbsp;</td> 
    </tr>
    <tr>
    <td height="132" align="left" valign="middle" background="img/headerback.jpg"><img src="img/pixel.gif" border="0" width="15" height="1"><font size="5">CUCSE 
	ALUMNI REGISTRATION</font><br><img src="img/pixel.gif" border="0" width="15" height="1"></td> 
    </tr>
    <tr>
    <td height="10"></td> 
    </tr>
    <tr>
    <td height="32" align="left" valign="middle" background="img/bluebg.gif"><img src="img/pixel.gif" border="0" width="15" height="1"></td> 
    </tr>
    </table>
 
    <table bgcolor="#464646" width="770" height="350" border="0" cellspacing="0" cellpadding="0">
    <tr>
	<td width="150" bgcolor="#202020" align="left" valign="top">
    
        <table width="150" border="0" cellspacing="0" cellpadding="0" bgcolor="#202020">
        <tr>
        <td height="24" width="222" valign="middle" onMouseOver="javascript:taust(this,'#0F363F')" onMouseOut="javascript:taust(this,'#202020')">&nbsp; <a href="#"><img src="indexfiles/pic/myphoto.jpg" border="1" align="left" hspace="5" vspace="5"></a></td>
        </tr>
        </table>
    </td>
	
    <td width="222" bgcolor="#202020" valign="top" class="style16">
    
        
<!---
    <br><br><div id="picloc">	<img alt="" class="style17" height="123" src="../../Documents/Downloads/default_profile.jpg" width="124">&nbsp;</td>
</div>--->
    <td width="3" bgcolor="#FFFFFF" align="right" valign="top"></td>
    <td align="left" valign="top" style="width: 10px"><img src="img/shadow1.gif" border="0" width="10" height="32"></td>		
    <td width="525" valign="top"><img src="img/shadow1.gif" border="0" width="525" height="32"><br>
    <strong><span class="style14">Member's Information Update Form</span></strong>
	<form name="modify">
	
		<table style="width: 99%; height: 35" cellpadding="3" class="style10">
			<tr>
				<td class="style6" style="width: 255px">Surname</td>
				<td style="width: 633px" class="style13">
				<input name="Surname" id="surname" style="height: 20px; width: 270px;" type="text" value="<%Response.write Recordset("Surname")%>" />&nbsp;</td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px">Name</td>
				<td style="width: 633px" class="style13">
				<input name="Name" id="Name" style="height: 20px; width: 270px;" type="text" value="<%Response.write Recordset("name")%>" />&nbsp;</td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px">Sex</td>
				<td style="width: 633px" class="style13">
				
				<input name="Sex" checked="checked" id="Sex1" type="radio" value="m" />Male&nbsp;&nbsp;
				<input name="Sex" checked="checked" id="Sex2" type="radio" value="f" />&nbsp;Female</td>
				
			</tr>
			<tr>
				<td class="style6" style="width: 255px">Date of Birth</td>
				<td style="width: 633px" class="style13">
				<input name="Dob" id="Dob" style="width: 70px; height: 20px" type="text"  value="<%Response.write Recordset("date_of_birth")%>" />&nbsp;(mm/dd/yyyy)</td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px">Present Address</td>
				<td style="width: 633px">
				<input name="PrAdd" id="PrAdd" style="width: 250px; height: 20px" type="text" value="<%Response.write Recordset("Present_address")%>"/>&nbsp;</td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Pincode</td>
				<td style="width: 633px; height: 17px;" class="style1">
				<input name="PrPin" id="PrPin" style="width: 70px; height: 20px" type="text" value="<%Response.write Recordset("present_pin")%>" />&nbsp;&nbsp; 
				Landmark&nbsp;
				<input name="PrLandmark" id="PrLandmark" style="width: 102px; height: 18px" type="text" value="<%Response.write Recordset("present_landmark")%>" /></td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Mobile</td>
				<td style="width: 633px; height: 17px;">
				<input name="Mobile" id="Mobile" style="width: 85px; height: 20px" type="text" value="<%Response.write Recordset("mobile_no")%>" /> 
				(prefix 0 in number belongs to outside West Bengal)</td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Landline</td>
				<td style="width: 633px; height: 17px;" class="style1">
				<input name="Landline" id="Landline" style="width: 90px; height: 20px" type="text" value="<%Response.write Recordset("landline")%>"/> 
				(attach STD code)</td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Email ID&nbsp; 
				Personal</td>
				<td style="width: 633px; height: 17px;">
				<input name="EmailPer" id="EmailPer" style="width: 150px; height: 20px" type="text" value="<%Response.write Recordset("personal_email")%>" /></td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Email ID&nbsp; 
				Official</td>
				<td style="width: 633px; height: 17px;" class="style1">
				<input name="EmailOff" id="EmailOff" style="width: 150px; height: 20px" type="text" value="<%Response.write Recordset("office_email")%>" />&nbsp;</td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Permanent 
				Address</td>
				<td style="width: 633px; height: 17px;">
				<input name="PtAdd" id="PtAdd" style="width: 250px; height: 20px" type="text" value="<%Response.write Recordset("permanent_address")%>" />&nbsp;</td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Pincode</td>
				<td style="width: 633px; height: 17px;" class="style1">
				<input name="PtPin" id="PtPin" style="width: 85px; height: 20px" type="text" value="<%Response.write Recordset("permanent_pin")%>" />&nbsp;&nbsp; 
				Landmark&nbsp;
				<input name="PtLandmark" id="PtLandmark" style="width: 89px; height: 20px" type="text" value="<%Response.write Recordset("permanent_landmark")%>"/></td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17;">Course 
				Studied in CUCSE</td>
				<td style="width: 633px; height: 17;" class="style13">
				BTech<input name="btech"  id="btech" type="checkbox" value="0" checked="unchecked" />&nbsp;&nbsp;&nbsp;
				MSc<input name="msc" id="msc" type="checkbox" value="0" checked="unchecked" />&nbsp;&nbsp;&nbsp;
				Mtech<input name="mtech" id="mtech"  type="checkbox" value="0" checked="unchecked"/>
				Phd<input name="phd" id="phd" type="checkbox" value="0" checked="unchecked" /></td>
				
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17;">Year of 
				Joining CUCSE</td>
				<td style="width: 633px; height: 17;" class="style13">
				<input name="YearJoin" id="YearJoin" style="width: 60px; height: 20px" type="text" value="<%Response.write Recordset("yoj")%>" /></td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17;">Year of 
				Passing CUCSE</td>
				<td style="width: 633px; height: 17;" class="style13">
				<input name="YearPass" id="YearPass" style="width: 60px; height: 20px" type="text" value="<%Response.write Recordset("yop")%>" /></td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17;">Occupational Status</td>
				<td style="width: 633px; height: 17;" class="style13">
				
				Self-Employed<input name="occ" checked="checked" id="occ1" type="radio" value="semp" />&nbsp;&nbsp; 
				Salaried<input name="occ" checked="checked" id="occ2" type="radio" value="slr" />&nbsp;&nbsp; 
				Retired<input name="occ" checked="checked" id="occ3" type="radio" value="rtd" />&nbsp;&nbsp; 
				Others<input name="occ" checked="checked" id="occ4" type="radio" value="oth" /> </td>
			</tr>
            
			<tr>
				<td class="style4" style="height: 17px; width: 132px;">Preferred Way of 
				Communication</td>
				<td class="style7" style="height: 17px;">
				<input name="Com" checked="checked" id="Com1" type="radio" value="phone" />&nbsp;Phone&nbsp;&nbsp;&nbsp;
				<input name="Com" checked="checked" id="Com2" type="radio" value="email" />Email</td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Current 
				Profession</td>
				<td style="width: 633px; height: 17px;" class="style1">
				<input name="CurProf" id="CurProf" style="width: 150px; height: 20px" type="text" value="<%Response.write Recordset("curr_prof")%>"/></td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Current 
				Designation</td>
				<td style="width: 633px; height: 17px;" class="style1">
				<input name="CurDesg" id="CurDesg" style="width: 150px; height: 20px" type="text" value="<%Response.write Recordset("curr_desg")%>" /></td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Name of 
				Current Company/College/ Institute/Organization</td>
				<td style="width: 633px; height: 17px;" class="style1">
				<input name="CurCom" id="CurCom" style="width: 150px; height: 20px" type="text" value="<%Response.write Recordset("curr_comp")%>" />&nbsp; 
				(Initals not allowed)</td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Address 
				of Company/College/ Institute/Organization</td>
				<td style="width: 633px; height: 17px;" class="style1">
				<input name="CCAdd" id="CCAdd" style="width: 250px; height: 20px" type="text" value="<%Response.write Recordset("comp_add")%>"/>&nbsp;</td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Pincode</td>
				<td style="width: 633px; height: 17px;" class="style1">
				<input name="CCPin" id="CCPin" style="width: 85px; height: 20px" type="text" value="<%Response.write Recordset("comp_pin")%>" />&nbsp;&nbsp; 
				Landmark&nbsp;
				<input name="CCLandmark" id="CCLandmark" style="width: 89px; height: 20px" type="text" value="<%Response.write Recordset("comp_landmark")%>" /></td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Company 
				Contact Number</td>
				<td style="width: 633px; height: 17px;" class="style1">
				<input name="CCLand" id="CCLand" style="width: 90px; height: 19px" type="text" value="<%Response.write Recordset("comp_cont_no")%>" />&nbsp; 
				(attach STD code)</td>
			</tr>
			<tr>
				<td class="style6" style="width: 255px; height: 17px;">Company 
				Fax Number</td>
				<td style="width: 633px; height: 17px;" class="style1">
				<input name="CCFax" id="CCFax" style="width: 90px; height: 20px" type="text" value="<%Response.write Recordset("comp_fax")%>" />&nbsp; 
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
				<input name="CaFrom" id="CaFrom" style="width: 52px; height: 20px" type="text" value="<%Response.write Recordset("comp1_frm_yr")%>" />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
				To (specify year)&nbsp;&nbsp;&nbsp;
				<input name="CaTo" id="CaTo" style="width: 52px; height: 20px" type="text" value="<%Response.write Recordset("comp1_to_yr")%>" /></td>
			</tr>
			<tr>
				<td class="style4" style="height: 17px;">Name of&nbsp; 
				Company/College/ Institute/Organization</td>
				<td class="style7" style="height: 17px;">
				<input name="CaName" id="CaName" style="width: 150px; height: 20px" type="text" value="<%Response.write Recordset("name_comp1")%>" />&nbsp;</td>
			</tr>
			<tr>
				<td class="style4" style="height: 17px;">(b) From (specify year)</td>
				<td class="style7" style="height: 17px;">
				<input name="CbFrom" id="CbFrom" style="width: 52px; height: 20px" type="text" value="<%Response.write Recordset("comp2_frm_yr")%>" />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
				To (specify year)&nbsp;&nbsp;&nbsp;
				<input name="Cbto" id="Cbto" style="width: 52px; height: 20px" type="text" value="<%Response.write Recordset("comp2_to_yr")%>" /></td>
			</tr>
			<tr>
				<td class="style4" style="height: 17px;">Name of&nbsp; 
				Company/College/ Institute/Organization</td>
				<td class="style7" style="height: 17px;">
				<input name="CbName" id="CbName" style="width: 150px; height: 20px" type="text" value="<%Response.write Recordset("name_comp2")%>"/>&nbsp;</td>
			</tr>
			<tr></tr>
			<tr></tr>
			<tr></tr>
			<tr>
				<td class="style4" style="height: 17px;" colspan="2">
				<input class="style10" name="Submit1" style="width: 68px; height: 21px" type="button" value="Submit" onclick="start()" />
			</tr>
		</table>
	
	</form>
    </td>  
    <td width="10" align="left" valign="top"><img src="img/shadow1.gif" border="0" width="10" height="32"></td> 
    </tr>
    </table> 
 
    <table bgcolor="#464646" width="770" height="32" border="0" cellspacing="0" cellpadding="0">
    <tr>
    <td width="222" bgcolor="#202020" align="left" valign="top"></td>
    <td width="3" bgcolor="#FFFFFF" align="right" valign="top"></td>
    <td width="10" align="left" valign="top"><img src="img/shadow2.gif" border="0" width="10" height="32"></td> 
    <td width="525" align="left" valign="top"><img src="img/shadow2.gif" border="0" width="525" height="32"></td>  
    <td width="10" align="left" valign="top"><img src="img/shadow2.gif" border="0" width="10" height="32"></td> 
    </tr>
    </table>
 
    <table bgcolor="#202020" width="770" border="0" cellspacing="0" cellpadding="0">
    <tr>
    <td height="32" width="30" align="left" valign="middle" background="img/bluebg.gif"><img src="img/pixel.gif" border="0" width="5" height="1"></td>
    <td height="32" width="740" align="right" valign="middle" background="img/bluebg.gif">&copy; 2007 - ... yourdomain.com &nbsp; </td> 
    </tr>
    </table>  

</td>
<td width="3" bgcolor="#FFFFFF"></td>
</tr>
</table>
</center>


<div style="text-align: center; margin-top: 1.0em; margin-bottom: 1.0em;" class="style15">
<a href="http://alumni.cucse.org">	www.cucse.org</a></div>
</body>
</HTML>