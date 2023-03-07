var reason = "";
var xmlhttp,CONF;
var FLAG;

function strt(theForm)
{	
	FLAG = 1;
	validateFormOnSubmit(theForm);
/*alert(FLAG);*/   
   
   if(FLAG == 1)
   {
	   get();
	}  
}

function validateFormOnSubmit(theForm)
 {
  var x;
  x=document.getElementById('PD_p_id').value;
  validateUsername(x);
if (reason.length != '0')
  {
    alert("Some fields need correction:\n" + reason);FLAG = 0;
  }
  else
  {
   /* alert("All fields are filled correctly");*/
  }
}

function validateEmpty(x)
{
    var error = "";    
    if (x.length=='0')
    {		  
        reason += "The  heighlighted field has not been filled in.\n";
    }
}

function validateUsername(x) 
{
    var error = "";
    var illegalChars = /\W/; // allow letters, numbers, and underscores
 
    if (x == "") {
         
        reason += "You didn't enter a username.\n";
    } else if ((x.length >= 5)) {
        
        reason += "The username is the wrong length.\n";
    } else if (illegalChars.test(x)) {
         
        reason += "The username contains illegal characters.\n";
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
			var PD_p_id;			
			
			PD_p_id=document.getElementById('PD_p_id').value;
			var url="show_personal details.php";
			url=url+"?PD_p_id="+PD_p_id;
			url=url+"&sid="+Math.random(); /*alert(url);*/
			xmlhttp.open("GET",url,true);
			xmlhttp.onreadystatechange=stateChanged;
			xmlhttp.send(null);			
		} 
		
		function stateChanged()
		{
			if (xmlhttp.readyState==4)
			{
				document.getElementById("get_response").innerHTML=xmlhttp.responseText;
				//document.myForm.time.value = xmlhttp.responseText;	
			}
		}