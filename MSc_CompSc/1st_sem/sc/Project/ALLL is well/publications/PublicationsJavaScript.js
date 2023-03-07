var xmlhttp;
var CONF;	

 var reason = "";
function start(theForm)
{

validateFormOnSubmit(theForm);
if (reason.length =='0')
PublicationsAJAX();
}

function validateFormOnSubmit(theForm)
 {

  var x;
  var y;

  x=document.getElementById('PUB_pid').value;
  y='1';

  validateEmpty(x,y);

  

 x=document.getElementById('PUB_topic').value;
  y='2';

  validateEmpty(x,y);

  

 x=document.getElementById('PUB_volume_no').value;
  y='3';

  validateEmpty(x,y);


 x=document.getElementById('PUB_author').value;
  y= '4';
  validateEmpty(x,y);


 x=document.getElementById('PUB_conf_name').value;
  y= '5';
  validateEmpty(x,y);


 x=document.getElementById('PUB_pub_date').value;
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
    		reason += "The topic field has not been filled in.\n";	
	 }
	
	 if (x.length=='0' && y=='3')
    {	
    		reason += "The journal no field has not been filled in.\n";	
	 }
	
	if (x.length=='0' && y=='4')
    {	
    		reason += "The author field has not been filled in.\n";	
	 }
	
	if (x.length=='0' && y=='5')
    {	
    		reason += "The read in conference field has not been filled in.\n";	
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
		 document.getElementById('PUB_pid').value="";
		 document.getElementById('PUB_topic').value="";
		 document.getElementById('PUB_conf_name').value="";
		 document.getElementById('PUB_volume_no').value="";
		 document.getElementById('PUB_author').value="";
		 document.getElementById('PUB_pub_date').value="";
		}
		
