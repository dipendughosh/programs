alert("a");
var xmlhttp;
var CONF;
		
		function InsertProgramme(<!-- insert arguments here -->) 
		{
			
			xmlhttp=GetXmlHttpObject();
				if (xmlhttp==null)
				{
					alert ("Browser does not support HTTP Request");
					return;
				}
			connect_server();
		}
		
		function connect_server()
		{
			document.getElementById('insert_response').innerHTML = "Wait...";
			var url="insert_into_player.php";
				url=url+"?p_id="+p_id+"&p_name="+p_name+"&team_id="+team_id+"&age="+age+"&dob="+dob;
				url=url+"&sid="+Math.random();				
				xmlhttp.open('get',url,true);
				xmlhttp.onreadystatechange=stateChanged;
				xmlhttp.send(null);
		}
		
		function stateChanged()
		{
			if (xmlhttp.readyState==4)
			{
				document.getElementById("insert_response").innerHTML=xmlhttp.responseText;
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


