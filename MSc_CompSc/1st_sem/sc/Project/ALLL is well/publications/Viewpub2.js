 var reason = "";
function strt(theForm)
{
validateFormOnSubmit(theForm);
get();
}

function validateFormOnSubmit(theForm)
 {
  
 var x;
  x=document.getElementById('PUB_view2_fac_name').value;
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



function validateEmpty(x) {
    var error = "";
 
    if (x.length == 0) {
        
        reason += "The required field has not been filled in.\n"
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
		
		function get()
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
			var PUB_view2_fac_name;
			
			PUB_view2_fac_name=document.getElementById('PUB_view2_fac_name').value;
			
			var url="showPubT2.php";
			url=url+"?PUB_view2_fac_name="+PUB_view2_fac_name;
			url=url+"&sid="+Math.random();alert(url);
			
			xmlhttp.open("GET",url,true);
			xmlhttp.onreadystatechange=stateChangedGetPlayer;
			xmlhttp.send(null);			
		} 
		
		function stateChangedGetPlayer()
		{
			if (xmlhttp.readyState==4)
			{
				document.getElementById("get_response").innerHTML=xmlhttp.responseText;
				//document.myForm.time.value = xmlhttp.responseText;	
			}
		}