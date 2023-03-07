 
<html>
<title>Patent page </title>
<head>
	<div style="border: 4px solid black" align= "center"><font size="10pt"> PATENT</font></div>
	<script type="text/javascript">
	
		var xmlhttp;
		var CONF;
		var choice;
		
		function get_patent(choice)
			{
			 xmlhttp=GetXmlHttpObject();
				if (xmlhttp==null)
				{
					alert ("Browser does not support HTTP Request");
					return;
				}
			connect_server_get_patent(choice);
		}
		
		function connect_server_get_patent(choice)
		{
			var PD_pid;
			PD_pid=document.getElementById('get_pid').value;
			
			var url="ShowPatentPerFaculty.php";
			url=url+"?PD_pid="+PD_pid+"&choice="+choice;
			url=url+"&sid="+Math.random(); /*alert(url);*/
			xmlhttp.open("GET",url,true);			
			xmlhttp.onreadystatechange=stateChangedGetpatent;
			xmlhttp.send(null);			
		} 
		
		function stateChangedGetpatent()
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
		
		
	function clean()
	{
		document.getElementById('get_pid').value="";	
	 }
	 	
	</script>	
</head>
<body onload="clean()">
	<br /><br />
	<h2><u><center>Show patent details</center></u></h2>
	
	<form>
	<table align="center" border="1" class="main">
	<tr>

	<td>Enter FACULTY_ID : <input type="text" name="get_pid" id="get_pid" /></td>
	<td><input type="button" onclick="get_patent(1)" value="Retrieve" /></td>	
	</tr>
	<tr><td><center>Patents For All Faculty</center></td><td><input type="button" onclick="get_patent(2)" value="Retrieve" /></td></tr>
	</table>
	</form>
	<div id="get_response"></div>
	
</body>	
</html>
	