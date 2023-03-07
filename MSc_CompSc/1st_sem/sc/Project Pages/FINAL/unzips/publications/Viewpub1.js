 var reason = "";
 var xmlhttp,CONF;
 
function strt(theForm)
{
validateFormOnSubmit(theForm);
show();
}

function validateFormOnSubmit(theForm)
 {
  
 var x;
  x=document.getElementById('PUB_view1_from_date').value;
  checkDate(x);

 x=document.getElementById('PUB_view1_to_date').value;
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




function show()
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
			var PUB_view1_from_date,PUB_view1_to_date;
			
			PUB_view1_from_date=document.getElementById('PUB_view1_from_date').value;
			PUB_view1_to_date=document.getElementById('PUB_view1_to_date').value;
			
			var url="show_pubT.php";
			
			url=url+"?PUB_view1_from_date="+PUB_view1_from_date+"&PUB_view1_to_date="+PUB_view1_to_date;
			url=url+"&sid="+Math.random(); alert(url);
			
			xmlhttp.open("get",url,true);			
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
