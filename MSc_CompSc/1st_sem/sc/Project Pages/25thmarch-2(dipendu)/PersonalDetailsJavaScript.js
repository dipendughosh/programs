var xmlhttp;
var CONF;	
var reason = "";
var FLAG;

function start()
{
	FLAG=1;
	validateFormOnSubmit(theForm);
	if(FLAG == 1)
	{
		PersonalDetailsAJAX();
	}	
}

/*function func1()
{
 alert("rr");
}*/

function validateFormOnSubmit(theForm)
 {
  
 var x;
		x=document.getElementById('PD_p_id').value;
validateEmpty(x);
	if(FLAG == 0)
	{
		alert("Some fields need correction:\n" + reason);
		return;
	}


		 x=document.getElementById('PD_name').value;
validateEmpty(x);
	if(FLAG == 0)
	{
		alert("Some fields need correction:\n" + reason);
		return;
	}

		 x=document.getElementById('PD_dob').value;
validateEmpty(x);
	if(FLAG == 0)
	{
		alert("Some fields need correction:\n" + reason);
		return;
	}

		 x=document.getElementById('PD_sex').value;
validateEmpty(x);
	if(FLAG == 0)
	{
		alert("Some fields need correction:\n" + reason);
		return;
	}

		 x=document.getElementById('PD_address').value;
validateEmpty(x);
	if(FLAG == 0)
	{
		alert("Some fields need correction:\n" + reason);
		return;
	}

		 x=document.getElementById('PD_pin').value;
validateEmpty(x);
	if(FLAG == 0)
	{
		alert("Some fields need correction:\n" + reason);
		return;
	}

		 x=document.getElementById('PD_landline').value;
validateEmpty(x);
	if(FLAG == 0)
	{
		alert("Some fields need correction:\n" + reason);
		return;
	}

		 x=document.getElementById('PD_mobile').value;
validateEmpty(x);
	if(FLAG == 0)
	{
		alert("Some fields need correction:\n" + reason);
		return;
	}

		 x=document.getElementById('PD_email').value;
validateEmpty(x);
	if(FLAG == 0)
	{
		alert("Some fields need correction:\n" + reason);
		return;
	}

		 x=document.getElementById('PD_doj').value;		
validateEmpty(x);
	if(FLAG == 0)
	{
		alert("Some fields need correction:\n" + reason);
		return;
	}

		 x=document.getElementById('PD_quali').value;
validateEmpty(x);
	if(FLAG == 0)
	{
		alert("Some fields need correction:\n" + reason);
		return;
	}

		 x=document.getElementById('PD_type').value;
validateEmpty(x);
	if(FLAG == 0)
	{
		alert("Some fields need correction:\n" + reason);
		return;
	}

		 x=document.getElementById('PD_post').value;
validateEmpty(x);
	if(FLAG == 0)
	{
		alert("Some fields need correction:\n" + reason);
		return;
	}

		 x=document.getElementById('PD_special').value;	
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
 
	
		function PersonalDetailsAJAX()
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
			var 		PD_p_id,PD_name,PD_dob,PD_sex,PD_address,PD_pin,PD_landline,PD_mobile,PD_email,PD_doj,PD_quali,PD_type,PD_post,PD_special;
						
			document.getElementById('insert_response').innerHTML = "Wait...";
		
			PD_p_id=document.getElementById('PD_p_id').value;
			PD_name=document.getElementById('PD_name').value;
			PD_dob=document.getElementById('PD_dob').value;
			PD_sex=document.getElementById('PD_sex').value;
			PD_address=document.getElementById('PD_address').value;
			PD_pin=document.getElementById('PD_pin').value;
			PD_landline=document.getElementById('PD_landline').value;
			PD_mobile=document.getElementById('PD_mobile').value;
			PD_email=document.getElementById('PD_email').value;
			PD_doj=document.getElementById('PD_doj').value;		
			PD_quali=document.getElementById('PD_quali').value;
			PD_type=document.getElementById('PD_type').value;
			PD_post=document.getElementById('PD_post').value;
			PD_special=document.getElementById('PD_special').value;	

			var url="insert_into_personal_details.php";					
				
			url=url+"?PD_p_id="+PD_p_id+"&PD_name="+PD_name+"&PD_dob="+PD_dob+"&PD_sex="+PD_sex		+"&PD_address="+PD_address+"&PD_pin="+PD_pin+"&PD_landline="+PD_landline+"&PD_mobile="+PD_mobile+"&PD_email="+PD_email+"&PD_doj="+PD_doj+"&PD_quali="+PD_quali+"&PD_type="+PD_type+"&PD_post="+PD_post+"&PD_special="+PD_special;

				url=url+"&sid="+Math.random();							
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
		 document.getElementById('PD_p_id').value="";
		 document.getElementById('PD_name').value="";
		 document.getElementById('PD_dob').value="";
		 document.getElementById('PD_sex').value="";
		 document.getElementById('PD_address').value="";
		 document.getElementById('PD_pin').value="";
		 document.getElementById('PD_landline').value="";
		 document.getElementById('PD_mobile').value="";
		 document.getElementById('PD_email').value="";
		 document.getElementById('PD_doj').value="";		
		 document.getElementById('PD_quali').value="";
		 document.getElementById('PD_type').value="";
		 document.getElementById('PD_post').value="";
		 document.getElementById('PD_special').value="";	
		}
		 
