
function validateFormOnSubmit(theForm)
 {
var reason = "";
  alert("oo");
  var x;
  x=document.getElementById('PB_pid').value;
  reason += validateEmpty(x);
 x=document.getElementById('PB_topic').value;
  reason += validateEmpty(x);
 x=document.getElementById('PB_journal_no').value;
  reason += validateEmpty(x);
 x=document.getElementById('PB_author').value;
  reason += validateEmpty(x);
 x=document.getElementById('PB_conf_name').value;
  reason += validateEmpty(x);
 x=document.getElementById('PB_date').value;
  reason += validate_date(x);
alert(reason);
 
      
  if (reason != "") {
    alert("Some fields need correction:\n" + reason);
    return false;
  }

  alert("All fields are filled correctly");
  return false;
}

function validateEmpty(x) {
    var error = "";
    alert(x);
    if (x=="" || x== NULL)
    {	
	alert(x.length);
        x.style.background = 'olive';  
        error = "The  heighlighted field has not been filled in.\n"
    } else {
        x.style.background = 'White';
    }
    return error;  
}

function validate_date (d)
{
  var strMistakes="";

  var datePattern = /^\d{4}-\d{2}-\d{2}$/gi;
  var testDate = true;
  if (String(d).match(datePattern) == null) testDate = false;

  if (testDate)
  {
   var theDate, theMonth, theYear
     
   theDate = parseInt(d.substr(8,2));
   theMonth = parseInt(d.substr(5,2));
   theYear = parseInt(d.substr(0,4));
     
   if (theMonth < 0 || theMonth > 12) strMistakes = "Month is invalid\n";
   if (theDate < 0 || theDate > 31) strMistakes = "Date is invalid\n";  
   
   if (theDate >= 1 && theDate <= 31)
   {
    if (theMonth == 2)
    {
     if (theYear % 4 == 0)
     {
      if (theDate < 0 || theDate > 29) strMistakes = "Date is invalid\n";
     }
     else
     {
      if (theDate < 0 || theDate > 28) strMistakes = "Date is invalid\n";
     }
    }
   }
  }
  else
  {
   strMistakes = "Date format is invalid\n";
  }
  return strMistakes;
}

function checkDate(d){
	var valid_date = check_date(d);
	if (valid_date == "") {
		alert("Valid Date");
	} else {
		alert(valid_date)
	}
}



