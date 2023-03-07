var xmlhttp;
var CONF;	
var reason = "";


function start(theForm)
{
    
	validateFormOnSubmit(theForm);
  	if (reason.length =='0')
	PersonalDetailsAJAX();

}

function validateFormOnSubmit(theForm)
 {

  var x;
  var y;

  
  x=document.getElementById('PD_p_id').value;
  y ='1';
  validateEmpty(x,y);
  
  x=document.getElementById('PD_name').value;
  y ='2';
  validateEmpty(x,y);
  
  x=document.getElementById('PD_dob').value;
checkDate(x);

x=document.getElementById('PD_sex').value;
  y ='3';
  validateEmpty(x,y);

 x=document.getElementById('PD_address').value;
  y ='4';
  validateEmpty(x,y);
  
  x=document.getElementById('PD_pin').value;
  validatePin(x);
 
 x=document.getElementById('PD_mobile').value;
  validatePhone(x);
 
 x=document.getElementById('PD_doj').value;
checkDate(x);



  
  
  if (reason.length != '0')
  {
    alert("Some fields need correction:\n" + reason);
  }
  else
  {
    alert("All fields are filled correctly");
      }
}

function validateEmpty(x,y)
{
    var error = "";
    
	if (x.length=='0' && y=='1')
    {	
    		reason += "The id field has not been filled in.\n";	
	 }
	
	if (x.length=='0' && y=='2')
    {	
    		reason += "The name field has not been filled in.\n";	
	 }
	
	if (x.length=='0' && y=='3')
    {	
    		reason += "The sex field has not been filled in.\n";	
	 }
	
if (x.length=='0' && y=='4')
    {	
    		reason += "The address field has not been filled in.\n";	
	 }
	
	}


function check_date (x)
{
  var datePattern = /^\d{4}-\d{2}-\d{2}$/gi;
  var testDate = true;
  if (String(x).match(datePattern) == null) testDate = false;

  if (testDate)
  {
   var theDate, theMonth, theYear;
     
   theDate = parseInt(x.substr(8,2));
   theMonth = parseInt(x.substr(5,2));
   theYear = parseInt(x.substr(0,4));
     
   if (theMonth < 0 || theMonth > 12) reason += "Month is invalid\n";
   if (theDate < 0 || theDate > 31)  reason += "Date is invalid\n";  
   
   if (theDate >= 1 && theDate <= 31)
   {
    if (theMonth == 2)
    {
     if (theYear % 4 == 0)
     {
      if (theDate < 0 || theDate > 29) reason += "Date is invalid\n";
     }
     else
     {
      if (theDate < 0 || theDate > 28) reason += "Date is invalid\n";
     }
    }
   }
  }
  else
  {
   reason += "Date format is invalid\n";
  }
}

function checkDate(x)
{
	var valid_date = check_date(x);
	if (valid_date == "")
           {
		reason += "Valid Date";
	}
}

 function validatePin(x) {
    
    var stripped = x.replace(/[\(\)\.\-\ ]/g, '');    

   if (x == "") {
        reason += "You didn't enter a pin number.\n";
        
    } else if (isNaN(parseInt(stripped))) {
        reason += "The pin number contains illegal characters.\n";
        
    } else if (!(stripped.length == 10)) {
        reason += "The pin number is the wrong length.\n";
        
    }
   
}

function validatePhone(x) {
    
    var stripped = x.replace(/[\(\)\.\-\ ]/g, '');    

     if (isNaN(parseInt(stripped))) {
        reason += "The mobile phone number contains illegal characters.\n";
        
    } else if (!(stripped.length == 10)) {
        reason += "The mobile phone number is the wrong length.\n";
        
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
		 
