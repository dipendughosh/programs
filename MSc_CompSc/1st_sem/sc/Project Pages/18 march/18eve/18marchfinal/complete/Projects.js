var xmlhttp;
var CONF;	

function start()
{
	func1();
	ProjectsAJAX();	
}

function func1()
{
 alert("rr");
}
 	
		function ProjectsAJAX()
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
			var PR_id,PR_headname,PR_topic,PR_type,PR_fundedby,PR_status;
						
			document.getElementById('insert_response').innerHTML = "Wait...";
		
			PR_id=document.getElementById('PP_id').value;
			PR_headname=document.getElementById('PR_headname').value;
			PR_topic=document.getElementById('PR_topic').value;
			PR_type=document.getElementById('PR_type').value;
			PR_fundedby=document.getElementById('PR_fundedby').value;
			PR_status=document.getElementById('PR_status').value;
			
				
			var url="insert_into_projects.php";					
				
				url=url+"?PR_id="+PR_id+"&PR_headname="+PR_headname+"&PR_topic="+PR_topic+"&PR_type="+PR_type+"&PR_fundedby="+PR_fundedby+"&PR_status="+PR_status;				
				url=url+"&sid="+Math.random();	alert(url);
							
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
