<html>
<head>
<title>Faculty Programme Details</title>
<!-- <div style="border: 4px solid black" align= "center"><font size="5pt"> FACULTY INFORMATION SHEET </font></div> -->
<link href="styles.css" rel="stylesheet" type="text/css">
<script type="text/javascript">

var xmlhttp,xmlhttp1,CONF,choice,choice2;

function show_conference(choice)
{			
		/*alert("k");*/
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
			url=url+"&sid="+Math.random(); /*alert(url);*/
			
			xmlhttp.open("GET",url,true);			
			xmlhttp.onreadystatechange=stateChanged;
			xmlhttp.send(null);			
		} 
		
		function stateChanged()
		{
			if (xmlhttp.readyState==4)
			{
				
			/*	var display_setting="toolbar=yes,location=no,directories=yes,menubar=yes,";				
				display_setting+="scrollbars=yes,width=750, height=600, left=100, top=25";
				var document_print=window.open("","",display_setting);				
				document_print.document.open();
				document_print.document.write('<html><head><title>Print using javascript </title></head><body></body></html>');
				document_print.document.write(xmlhttp.responseText);
			*/	
			
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
		
	function check_box()
		{			
			if(document.form3.cbox1.checked == true)
					document.form3.fname.disabled=false;			
			else
					document.form3.fname.disabled=true;
			
		}
		
	function CONF_detail_reports(choice2)
		{			
			switch(choice2)
			{
				case 'FDProg':
					alert(choice2);
					AJAXforDetailReports(choice2);
					break;
				case 'Workshops' :
					alert(choice2);
					AJAXforDetailReports(choice2);
					break;
				case 'Conferences' :
					alert(choice2);
					AJAXforDetailReports(choice2);
					break;
				case 'SDTProg' :
					alert(choice2);
					AJAXforDetailReports(choice2);
					break;
				case 'FTProg' :
					alert(choice2);
					AJAXforDetailReports(choice2);
					break;
				case 'PUNI' :
					alert(choice2);
					AJAXforDetailReports(choice2);
					break;				
			}											
		}
		
		function AJAXforDetailReports(choice2)
		{
			xmlhttp=GetXmlHttpObject();
			
			var url1="show_comference.php"
			url1=url1+"?CONF_type="+choice2+"&sid="+Math.random();
			alert(url1);			
			xmlhttp.open("GET",url1,true);			
			xmlhttp.onreadystatechange=stateChanged;
			xmlhttp.send(null);		
		}
		
				
</script>
</head>

<body>

<form>
<img src="cuimg.jpg" />
</form>

<form>
<table width="60%" div align="center" border="0" cellspacing="0" cellpadding="5" class="main">
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
   </form>
   
   <form>     	
	<table width="60%" border="0" cellspacing="3" cellpadding="3" align="center" class="forms">
	<th colspan="2" align="left">Enter The Date Range</th>
	<tr><td width="30%">From :<input name="VW_CONF_FROM_date" id="VW_CONF_FROM_date" type="text" size="10"/></td>
	<td>To :<input name="VW_CONF_TO_date" id="VW_CONF_TO_date" type="text" size="10"/></td>	
	</tr></table>
	</form>
	
	<form>
	<br>
	<table width="60%" border="0" cellspacing="3" cellpadding="3" align="center" class="forms">
	<th colspan="2" align="left">Summary Reports</th>
		<tr><td width="30%"><input type="button" onclick="show_conference(1)" value="Date Wise Details" /></td>
		<td><input type="button" onclick="show_conference(2)" value="Details Per Faculty" /></td>     
		</tr>
	</table>
	</form>
	
	<form name="form3">	
	<br>
	<table width="60%" border="0" cellspacing="3" cellpadding="3" align="center" class="forms">
	<th colspan="2" align="left">Detailed Reports</th>
	<tr><td><input type="checkbox" name="cbox1" onclick="check_box()" /> Faculty Name <input type="text" name="fname" disabled="true" /></td></tr>
	<tr><td><input type="button" onclick="CONF_detail_reports('FDProg')" value="Faculty Development Programe" /></td></tr>
	<tr><td><input type="button" onclick="CONF_detail_reports('Workshops')" value="Workshops" /></td></tr>
	<tr><td><input type="button" onclick="CONF_detail_reports('Conferences')" value="Conferences" /></td></tr>
	<tr><td><input type="button" onclick="CONF_detail_reports('SDTProg')" value="Staff Development Training Programe" /></td></tr>
	<tr><td><input type="button" onclick="CONF_detail_reports('FTProg')" value="Foreign Training Programe" /></td></tr>
	<tr><td><input type="button" onclick="CONF_detail_reports('PUNI')" value="Programes Under Networking Of Institutions" /></td></tr>
		
	</table>
</form>

<!-- Show Message for AJAX response -->
<div id="get_response"></div>
</body>
</html>