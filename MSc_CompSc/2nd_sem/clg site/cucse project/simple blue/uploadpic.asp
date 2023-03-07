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
<HTML>
<HEAD>
<meta http-equiv=Content-Type content="text/html;  charset=ISO-8859-1">
<TITLE>New User Registration</TITLE>

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

<script language="JavaScript" type="text/JavaScript" src="java/javascript.js"></script>
<SCRIPT TYPE="text/javascript" LANGUAGE="JavaScript" SRC="java/base.js"></SCRIPT>
<script language="JavaScript" src="java/tabel.js" type="text/javascript"></script>
<script language="javascript" type="text/javascript" src="java/proff.js"></script>
<script type="text/javascript" >
    function t() {
        var x;


        x = Math.random();
        x = x * 10000000000000000;
        x = x % 100000000000000000;

        document.form.name.value = document.form.name.value + x;
        document.getElementById('disablingDiv').style.display = 'block';
        document.getElementById('white_content').style.display = 'block';

    }
    function check() {
        if (document.form.file.value == "")
            alert('Nothing to Upload!');

    }
</script>


</HEAD>
<BODY background="img/bg.gif" bgcolor="#202020" topmargin="0" leftmargin="0">

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
    <td height="32" align="left" valign="middle" background="img/bluebg.gif"><img src="img/pixel.gif" border="0" width="15" height="1"><a href="#">Link 001</a> | <a href="#">Link 002</a> | <a href="#">Link 003</a> | <a href="#">Link 004</a> | <a href="#">Link 005</a></td> 
    </tr>
    </table>
 
    <table bgcolor="#464646" width="770" height="350" border="0" cellspacing="0" cellpadding="0">
    <tr>
    <td width="222" bgcolor="#202020" valign="top" class="style16">
    
        

     
    <br><br><div id="picloc">	<img alt="" class="style17" src="Thumbs/mona_thumb.jpg" height="123" width="124">&nbsp;<p><a href = "javascript:void(0)" onclick ="t()">Picture Upload</a></p></div>
     <div id="disablingDiv" ></div>
      
      <div id="white_content"><a  href = "javascript:void(0)" onclick = "document.getElementById('white_content').style.display='none'; 
document.getElementById('disablingDiv').style.display='none'" style="text-align:right">close</a>

<form name = "form" action="<%=Request.ServerVariables( "Script_Name" )%>?action=1" enctype="multipart/form-data" method="POST">

	  <h3><span class="style2">Please upload a recent picture.</span></h3>
      <h3><span class="style2">After you have finished Uploading,</span></h3>
      <h3><span class="style2">please click on the close button on the Left Upper Corner</span></h3>
	  <h3><span class="style2"><a href="http://resizr.lord-lance.com/default.asp?e=4" target="_blank">Resize Here(External Link)</a></span></h3>
      <br>
      <input name="file" type="file" size="30">
	  <input type="hidden" name="name">
      <br>
      <br>
      <br>
      <input name="upload" type="submit" onclick="check()" value="Upload">
  
</form>
</div>
        </td>  
    
    </table> 
 
    <table bgcolor="#464646" width="770" height="32" border="0" cellspacing="0" cellpadding="0">
    <tr>
    <td width="3" bgcolor="#FFFFFF" align="right" valign="top"></td>
    <td width="10" align="left" valign="top"><img src="img/shadow2.gif" border="0" width="10" height="32"></td> 
    <td width="525" align="left" valign="top"><img src="img/shadow2.gif" border="0" width="770" height="32"></td>  
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