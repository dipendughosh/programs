<html>
<head>
<title>Faculty Programme Details</title>
<div style="border: 4px solid black" align= "center"><font size="5pt"> FACULTY INFORMATION SHEET </font></div>
<link href="styles.css" rel="stylesheet" type="text/css">
<script type="text/javascript">

var xmlhttp,CONF,choice;

function show_conference(choice)
{			
		alert("k");
		xmlhttp=GetXmlHttpObject();
				if (xmlhttp==null)
				{
					alert ("Browser does not support HTTP Request");
					return;
				}
			connect_server(choice);
}
		
function connect_server(choice)
		{
			var VW_CONF_FROM_date,VW_CONF_TO_date;
			VW_CONF_FROM_date=document.getElementById('VW_CONF_FROM_date').value;
			VW_CONF_TO_date=document.getElementById('VW_CONF_TO_date').value;
			
			var url="ShowConferenceT.php";
			
			url=url+"?VW_CONF_FROM_date="+VW_CONF_FROM_date+"&VW_CONF_TO_date="+VW_CONF_TO_date+"&choice="+choice;
			url=url+"&sid="+Math.random(); alert(url);
			
			xmlhttp.open("GET",url,true);			
			xmlhttp.onreadystatechange=stateChanged;
			xmlhttp.send(null);			
		} 
		
		function stateChanged()
		{
			if (xmlhttp.readyState==4)
			{
				document.getElementById("get_response").innerHTML=xmlhttp.responseText;
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
</head>

<body>
<form>
<table width="100%" div align="center" border="0" cellspacing="0" cellpadding="5" class="main">
  <tr><td colspan="3">&nbsp;</td></tr>
  <tr><td width="160" valign="top"><p>&nbsp;</p>
  		<p>&nbsp; </p>
  		<p>&nbsp;</p>
      <p>&nbsp;</p>
      <p>&nbsp;</p></td>
  <td width="732" valign="top"><p>
  </p>
      <h3 class="titlehdr">View Details</h3>
      <p>Please Enter The faculty training Details 
        Please note that fields marked <span class="required">*</span> 
        are required.</p></tr>
	</table>   
        	
	<table width="95%" border="0" cellspacing="3" cellpadding="3" align="center" class="forms">
	
	<tr><td width="30%">From :<input name="VW_CONF_FROM_date" id="VW_CONF_FROM_date" type="text" size="10"/></td>
	<td>To :<input name="VW_CONF_TO_date" id="VW_CONF_TO_date" type="text" size="10"/></td>	
	</tr>
		<tr><td width="30%"><input type="button" onclick="show_conference(1)" value="Date Wise Details" /></td>
		<td><input type="button" onclick="show_conference(2)" value="Details Per Faculty" /></td>     
		</tr>	
</table>	
</form>

<!-- Show Message for AJAX response -->
<div id="get_response"></div>	
</body>
</html>