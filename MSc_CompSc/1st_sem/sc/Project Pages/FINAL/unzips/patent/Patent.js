var xmlhttp;
var CONF;	
var reason = "";
var FLAG;


function start(theForm)
{
FLAG=1;

validateFormOnSubmit(theForm);
if(FLAG == 1)
	{
	PatentAJAX();
	}
}

function validateFormOnSubmit(theForm)
 {
  
 var x;
  x=document.getElementById('PAT_id').value;
  validateEmpty(x);

 x=document.getElementById('PAT_topic').value;
  validateEmpty(x);

 x=document.getElementById('PAT_patent_no').value;
  validateEmpty(x);

 x=document.getElementById('PAT_researcher').value;
  validateEmpty(x);

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
			
				var url="insert_into_patent.php";					
				
				url=url+"?PAT_id="+PAT_id+"&PAT_topic="+PAT_topic+"&PAT_patent_no="+PAT_patent_no+"&PAT_researcher="+PAT_researcher;				
				url=url+"&sid="+Math.random();
							
				xmlhttp.open('get',url,true);
				xmlhttp.onreadystatechange=stateChanged;
				xmlhttp.send(null);
		}
		
		function stateChanged()
		{
			if (xmlhttp.readyState==4)
			{
				document.getElementById("insert_response").innerHTML="";
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
			document.getElementById('PAT_id').value="";			
			document.getElementById('PAT_topic').value="";
			document.getElementById('PAT_patent_no').value="";
			document.getElementById('PAT_researcher').value="";
}
