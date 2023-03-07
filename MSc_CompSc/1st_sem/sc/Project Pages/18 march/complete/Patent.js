var xmlhttp;
var CONF;	

function start()
{
	func1();
	PatentAJAX();	
}

function func1()
{
 alert("rr");
}
 
	
		function PatentAJAX()
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
			var PAT_id,PAT_topic,PAT_patent_no,PAT_researcher;
						
			document.getElementById('insert_response').innerHTML = "Wait...";
		
			PAT_id=document.getElementById('PAT_id').value;
			PAT_topic=document.getElementById('PAT_topic').value;
			PAT_patent_no=document.getElementById('PAT_patent_no').value;
			PAT_researcher=document.getElementById('PAT_researcher').value;
			
			var url="insert_into_personal_details.php";					
				
				url=url+"?PAT_id="+PAT_id+"&PAT_topic="+PAT_topic+"&PAT_patent_no="+PAT_patent_no+"&PAT_researcher="+PAT_researcher;				
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
