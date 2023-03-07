var xmlhttp;
var CONF;
var reason = "";
var FLAG;
	

/*function start()
{
	//func1();
	sAJAX();	
}*/

/*function func1()
{
 alert("rr");
}*/
 
function start(theForm)
{
FLAG=1;

validateFormOnSubmit(theForm);
if(FLAG == 1)
	{
	ProjectsAJAX();
	}
}

function validateFormOnSubmit(theForm)
 {
  
 var x;
  x=document.getElementById('PR_id').value;
  validateEmpty(x);
	if(FLAG == 0)
	{
		alert("Some fields need correction:\n" + reason);
		return;
	}


 x=document.getElementById(('PR_headname').value;
  validateEmpty(x);
	if(FLAG == 0)
	{
		alert("Some fields need correction:\n" + reason);
		return;
	}

 x=document.getElementById('PR_topic').value;
  validateEmpty(x);
	if(FLAG == 0)
	{
		alert("Some fields need correction:\n" + reason);
		return;
	}

 x=document.getElementById('PR_fundedby').value;
  validateEmpty(x);
	if(FLAG == 0)
	{
		alert("Some fields need correction:\n" + reason);
		return;
	}

x=document.getElementById('PR_status').value;
  validateEmpty(x);
	if(FLAG == 0)
	{
		alert("Some fields need correction:\n" + reason);
		return;
	}


  if (reason.length != '0')
  {
    alert("Some fields need correction:\n" + reason);
  }
  else
  {
    alert("All fields are filled correctly");
      }
}
 


function validateEmpty(x)
{
    var error = "";
    
    
    if (x.length=='0')
    {	
    		FLAG = 0;
        reason += "The  heighlighted field has not been filled in.\n";	
		  alert(reason);
    }
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
		
			PR_id=document.getElementById('PR_id').value;
			alert(PR_id);
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
				//document.getElementById("insert_response").innerHTML=xmlhttp.responseText;
				alert(xmlhttp.responseText);
				clean();
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
		 document.getElementById('PR_id').value="";
		 document.getElementById('PR_headname').value="";
		 document.getElementById('PR_topic').value="";
		 document.getElementById('PR_fundedby').value="";
		 document.getElementById('PR_status').value="";
		}
		 
