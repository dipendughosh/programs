<%
   Response.AddHeader "Pragma", "no-cache"
   Response.Buffer = True
   Response.ExpiresAbsolute = Now() - 1
   Response.Expires = 0
   Response.CacheControl = "no-cache"
   
	Dim Connection
	Dim ConnString
	Dim Recordset
	Dim sql

ConnString="DRIVER={SQL Server};SERVER=cucse.org;UID=admincucse;" & _
"PWD=cucse123;DATABASE=cucse"

'sql="SELECT * FROM login where alumni_id='" & Request.querystring("LOGIN_usrname") & "' and LIO_StatusId='" & Request.querystring("LIO_StatusId") & "'"
sql="SELECT * FROM login where alumni_id='" & Request.querystring("LOGIN_usrname") & "' and LIO_StatusId <> '0'"

Set Connection = Server.CreateObject("ADODB.Connection")
Set Recordset = Server.CreateObject("ADODB.Recordset")
Connection.Open ConnString
Recordset.Open sql,Connection

If Recordset.EOF Then
	Recordset.Close
	Set Recordset=nothing
	Connection.Close
	Set Connection=nothing
	Response.redirect "index.html"
End If

%>
<HTML>
<HEAD>
<meta http-equiv=Content-Type content="text/html;  charset=ISO-8859-1">
<meta http-equiv="expires" value="Thu, 16 Mar 2000 
11:00:00 GMT" />
<meta http-equiv="pragma" content="no-cache" />
<TITLE>ALUMNI CUCSE</TITLE>

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
</style>

<!--<script language="JavaScript" type="text/JavaScript" src="java/javascript.js"></script>
<SCRIPT TYPE="text/javascript" LANGUAGE="JavaScript" SRC="java/base.js"></SCRIPT>
<script language="JavaScript" src="java/tabel.js" type="text/javascript"></script>-->
<script type="text/javascript">
var xmlhttp;
var CONF;	
var std;

function authenticate()
	{	
	xmlhttp=GetXmlHttpObject();
				if (xmlhttp==null)
				{
					alert ("Browser does not support HTTP Request");
					return;
				}
				
		var url="authenticate.asp";
		url=url+"?H_user=<% Response.Write (Request.querystring("LOGIN_usrname"))%>&Std="+Math.random();	 
		xmlhttp.open('get',url,true);
		xmlhttp.onreadystatechange=stateChanged;
		xmlhttp.send(null);
		
	}
	function stateChanged()
		{
			if (xmlhttp.readyState==4)
			{	
				if(xmlhttp.responseText=="NO")
					window.location = "http://alumni.cucse.org/index.html";					
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
		
</script>

</HEAD>

<BODY background="img/bg.gif" bgcolor="#202020" topmargin="0" leftmargin="0" onload="authenticate()">
<center>
<table bgcolor="#202020" width="776" height="100%" border="0" cellspacing="0" cellpadding="0">
<tr>
<td width="3" bgcolor="#FFFFFF"></td>
<td width="770" valign="top">
 
    <table bgcolor="#202020" width="770" border="0" cellspacing="0" cellpadding="0">
    <tr>
    <td height="32" align="right" valign="middle" background="img/bluebg.gif"><marquee>Welcome To The Alumni Association Of CUCSE</marquee></td> 
    </tr>
    <tr>
    <td height="132" align="left" valign="middle" ><img src="img/pixel.gif" border="0" width="15" height="1"><font size=5>ALUMNI ASSOCIATION OFFICIAL WEBSITE</font><br><img src="img/pixel.gif" border="0" width="15" height="1">Department Of Computer Science And Engeneering<br><img src="img/pixel.gif" border="0" width="15" height="1">University Of Calcutta<br></td> 
    </tr>
    <tr>
    <td height="10"></td> 
    </tr>
    <tr>
    <td height="32" align="right" valign="middle" background="img/bluebg.gif" style="font-family:verdana;font-size:10px;"><img src="img/pixel.gif" border="0" width="15" height="1"><a href="PostFile.aspx">Search Alumni CUCSE(uploadtest)</a> | <a href="#">Change Password</a> | <a href="logout.asp?LOGIN_usrname=<% Response.Write(Request.querystring("LOGIN_usrname"))%>">Sign Out</a>&nbsp;</td> 
    </tr>
    </table>
 
    <table bgcolor="#464646" width="770" height="350" border="0" cellspacing="0" cellpadding="0">
    <tr>
    <td width="222" bgcolor="#202020" align="left" valign="top">
    
        <table width="222" border="0" cellspacing="0" cellpadding="0" bgcolor="#202020">
        <tr>
        <td height="24" width="222" valign=middle>&nbsp; <b>Sub-menu:</b></td>
        </tr>
       <!-- <tr>
        <td width="222" height=3 bgcolor="#ffffff"></td>
        </tr>
        <tr>
        <td height="24" width="222" valign=middle onMouseOver="javascript:taust(this,'#0F363F')" onMouseOut="javascript:taust(this,'#202020')">&nbsp; <a href="#">� Sub-link 001</a></td>
        </tr>
        <tr>
        <td width="222" height=3 bgcolor="#ffffff"></td>
        </tr>
        <tr>
        <td height="24" width="222" valign=middle onMouseOver="javascript:taust(this,'#0F363F')" onMouseOut="javascript:taust(this,'#202020')">&nbsp; <a href="#">� Sub-link 002</a></td>
        </tr>
        <tr>
        <td width="222" height=3 bgcolor="#ffffff"></td>
        </tr>
        <tr>
        <td height="24" width="222" valign=middle onMouseOver="javascript:taust(this,'#0F363F')" onMouseOut="javascript:taust(this,'#202020')">&nbsp; <a href="#">� Sub-link 003</a></td>
        </tr>
        <tr>
        <td width="222" height=3 bgcolor="#ffffff"></td>
        </tr>
        <tr>
        <td height="24" width="222" valign=middle onMouseOver="javascript:taust(this,'#0F363F')" onMouseOut="javascript:taust(this,'#202020')">&nbsp; <a href="#">� Sub-link 004</a></td>
        </tr>
        <tr>
        <td width="222" height=3 bgcolor="#ffffff"></td>
        </tr>
        <tr>
        <td height="24" width="222" valign=middle onMouseOver="javascript:taust(this,'#0F363F')" onMouseOut="javascript:taust(this,'#202020')">&nbsp; <a href="#">� Sub-link 005</a></td>
        </tr>
        <tr>
        <td width="222" height=3 bgcolor="#ffffff"></td>
        </tr>-->
        </table>

    </td>
    <td width="3" bgcolor="#FFFFFF" align="right" valign="top"></td>
    <td width="10" align="left" valign="top"><img src="img/shadow1.gif" border="0" width="10" height="32"></td> 
    <td width="525" align="left" valign="top"><img src="img/shadow1.gif" border="0" width="525" height="32"><br>
	
	Thank you <%Response.Write (Request.querystring("LOGIN_usrname"))%> for logging in

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
    <td height="32" width="740" align="right" valign="middle" background="img/bluebg.gif">Rules and Regulations&nbsp; | Contact : admin@cucse.org&nbsp;</td> 
    </tr>
    </table>  

</td>
<td width="3" bgcolor="#FFFFFF"></td>
</tr>
</table>
</center>


<div style="font-size: 0.8em; text-align: center; margin-top: 1.0em; margin-bottom: 1.0em;">www.cucse.org</div>
</body>
</HTML>