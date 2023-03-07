var xmlhttp;
var CONF;	

function start()
{
	//func1();
	PublicationsAJAX();	
}

function func1()
{
 alert("rr");
}
 
	
		function PublicationsAJAX()
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
			var PUB_pid,PUB_topic,PUB_conf_name,PUB_volume_no,PUB_pub_date,PUB_author;
					
			document.getElementById('insert_response').innerHTML = "Wait...";
		
			PUB_pid=document.getElementById('PUB_pid').value;			
			PUB_topic=document.getElementById('PUB_topic').value;
			PUB_conf_name=document.getElementById('PUB_conf_name').value;			
			PUB_volume_no=document.getElementById('PUB_volume_no').value;			
			PUB_author=document.getElementById('PUB_author').value;			
			PUB_pub_date=document.getElementById('PUB_pub_date').value;		
			alert(PUB_pub_date);
			
			var url="insert_into_publications.php";					
				
				url=url+"?PUB_pid="+PUB_pid+"&PUB_topic="+PUB_topic+"&PUB_conf_name="+PUB_conf_name+"&PUB_volume_no="+PUB_volume_no+"&PUB_author="+PUB_author+"&PUB_pub_date="+PUB_pub_date;
				url=url+"&sid="+Math.random();alert(url);
				xmlhttp.open('get',url,true);
				xmlhttp.onreadystatechange=stateChanged;
				xmlhttp.send(null);
		}
		
		function stateChanged()
		{
			if (xmlhttp.readyState==4)
			{
				//document.getElementById("insert_response").innerHTML=xmlhttp.responseText;
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
 
