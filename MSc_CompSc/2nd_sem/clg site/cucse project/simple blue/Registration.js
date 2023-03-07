
var xmlhttp;
var CONF;
var LOGIN_usrname, LOGIN_password, LIO_StatusId;
function textcheck(theForm) {
    if (start(theForm))
        return true;
    else 
        return false;
    
}

function start(theForm)
{
//alert("HELLO JS!!");
var x,y=false,flag=0;

x = document.getElementById('surname').value;
//alert(x);
y=checkName(x,flag);

if(y!=false)
{
flag=1;
x = document.getElementById('Name').value;
y=checkName(x,flag);
nam=x;
}

if(y!=false)
{
x = document.getElementById('Dob').value;
y=checkDob(x); 
}

if(y!=false)
{
flag=0;
x = document.getElementById('PrAdd').value;
y=checkPrAdd(x,flag); 
}

if(y!=false)
{
flag=0;
x = document.getElementById('PrPin').value;
y=checkPin(x,flag); 
}

if(y!=false)
{
flag=0;
x = document.getElementById('PrLandmark').value;
y=checkLandmark(x,flag); 
}

if(y!=false)
{
x = document.getElementById('Mobile').value;
y=validateMobile(x); 
}


if(y!=false)
{
flag=0;
x = document.getElementById('Std').value;
y=validateStd(x,flag); 
}


if(y!=false)
{
flag=0;
x = document.getElementById('Landline').value;
y=validateLandline(x,flag); 
}

if(y!=false)
{
flag=0;
x = document.getElementById('EmailPer').value;
y=validateEmail(x,flag); 
}

if(y!=false)
{
flag=1;
x = document.getElementById('EmailOff').value;
y=validateEmail(x,flag); 
}

if(y!=false)
{
flag=1;
x = document.getElementById('PtAdd').value;
y=checkPrAdd(x,flag); 
}


if(y!=false)
{
flag=1;
x = document.getElementById('PtPin').value;
y=checkPin(x,flag); 
}


if(y!=false)
{
flag=1;
x = document.getElementById('PtLandmark').value;
y=checkLandmark(x,flag); 
}




if(y!=false)
{
flag=0;
x = document.getElementById('YearJoin').value;
y=checkYear(x,flag); 
}


if(y!=false)
{
flag=1;
x = document.getElementById('YearPass').value;
y=checkYear(x,flag); 
}

//alert(y);
	if(occ1.checked==true || occ2.checked==true)
		{
			if(y!=false)
				{
					flag=0;
					x = document.getElementById('CurProf').value;
					y=checkCompName(x,flag);

				}

			if(y!=false)
				{
					flag=1;
					x = document.getElementById('CurDesg').value;
					y=checkCompName(x,flag);
				}

			if(y!=false)
				{
					flag=2;
					x = document.getElementById('CurCom').value;
					y=checkCompName(x,flag);
				}


			if(y!=false)
				{
					flag=2;
					x = document.getElementById('CCAdd').value;
					y=checkPrAdd(x,flag);
				}

			if(y!=false)
				{
					flag=2;
					x = document.getElementById('CCPin').value;
					y=checkPin(x,flag);
				}

			if(y!=false)
				{
					flag=2;
					x = document.getElementById('CCLandmark').value;
					y=checkLandmark(x,flag);
				}


			if(y!=false)
				{
					flag=1;
					x = document.getElementById('CCStd').value;
					y=validateStd(x,flag);
				}

			if(y!=false)
				{
					flag=1;
					x = document.getElementById('CCLand').value;
					y=validateLandline(x,flag);
				}

			if(y!=false)
				{
					flag=2;
					x = document.getElementById('CCFaxStd').value;
					y=validateStd(x,flag);
				}
//alert(y);

			if(y!=false)
				{
					flag=2;
					x = document.getElementById('CCFax').value;
					y=validateLandline(x,flag);
				}
	
	}

else if(occ3.checked==true || occ4.checked==true)
  {
		document.getElementById('CurProf').disabled=true;
		document.getElementById('CurDesg').disabled=true;
		document.getElementById('CurCom').disabled=true;
		document.getElementById('CCAdd').disabled=true;
		document.getElementById('CCPin').disabled=true;
		document.getElementById('CCLandmark').disabled=true;
		document.getElementById('CCStd').disabled=true;
		document.getElementById('CCLand').disabled=true;
		document.getElementById('CCFaxStd').disabled=true;
		document.getElementById('CCFax').disabled=true;
	y==true;
 }
 
 
 if(y!=false &&(Dec1.checked==true || Dec2.checked==true))
{ 
 if(y!=false &&(Dec1.checked==true))
   {
    alert("Insert Ajax here!!");
	insert_AJAX();
   }
  
  if(y!=false &&(Dec2.checked==true))
    {
	 alert("Check I agree !!");
	 }
}

else if(y!=false)
  {
    alert("Please read the declaration!");
	}
	
}





function checkName(x,flag)
{
var noalpha = /^[a-zA-Z]*$/;
 if(x=="")
 {
       
	   if(flag==0)
	   {
	   alert("Surname field is blank");
       surname.style.background='#AAB6C1';
	   surname.focus();
	   return false;
       }
	   
	   else if(flag==1)
	    {
		alert("Name field is blank");
        Name.style.background='#AAB6C1';
	    Name.focus();
       return false;
		}
		else
		 return true;
       
   }
   
    if (!(noalpha.test(x))) 
    {
       
	 if(flag==0)
	   {
	   alert("Error: Enter only alphabets.");
       surname.style.background='#AAB6C1';
	   surname.focus();
	   return false;
       }
	   
	   else if(flag==1)
	    {
	     alert("Error: Enter only alphabets.");
        Name.style.background='#AAB6C1';
	    Name.focus();
       return false;
		}
		else
		  return true;
       

	}

}


function checkDob(x) {
// Checks for the following valid date formats:
// MM/DD/YY   MM/DD/YYYY   MM-DD-YY   MM-DD-YYYY
// Also separates date into month, day, and year variables

var datePat = /^(\d{1,2})(\/|-)(\d{1,2})\2(\d{2}|\d{4})$/;

// To require a 4 digit year entry, use this line instead:
// var datePat = /^(\d{1,2})(\/|-)(\d{1,2})\2(\d{4})$/;

var matchArray = x.match(datePat); // is the format ok?
if (matchArray == null) {
alert("Date is not in a valid format.")
Dob.style.background='#AAB6C1';
Dob.focus();
return false;
}
month = matchArray[1]; // parse date into variables
day = matchArray[3];
year = matchArray[4];
if (month < 1 || month > 12) { // check month range
alert("Month must be between 1 and 12.");
Dob.style.background='#AAB6C1';
Dob.focus();
return false;
}
if (day < 1 || day > 31) {
alert("Day must be between 1 and 31.");
Dob.style.background='#AAB6C1';
Dob.focus();
return false;
}
if ((month==4 || month==6 || month==9 || month==11) && day==31) {
alert("Month "+month+" doesn't have 31 days!")
Dob.style.background='#AAB6C1';
Dob.focus();
return false
}
if (month == 2) { // check for february 29th
var isleap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
if (day>29 || (day==29 && !isleap)) {
alert("February " + year + " doesn't have " + day + " days!");
Dob.style.background='#AAB6C1';
Dob.focus();
return false;
   }
}
return true;  // date is valid
}


function checkPrAdd(x,flag)
 {
   if(x=="")
    {
	 
       if(flag==0)
	   {
	   alert("Highlighted Address field is blank");
	   PrAdd.style.background='#AAB6C1';
	   PrAdd.focus();
	   }
	   else if(flag==1)
	     {
		 alert("Highlighted Address field is blank");
		 PtAdd.style.background='#AAB6C1';
	     PtAdd.focus();
	    }
		else if(flag==2 && (occ1.checked==true || occ2.checked==true))
		{
		  alert("Highlighted Address field is blank");
		 CCAdd.style.background='#AAB6C1';
	     CCAdd.focus();
	    }
		 
       return false;
   }
  }

  
  
  
  
  function checkPin(x,flag)
  {
  //var stripped = x.replace(/[\(\)\.\-\ ]/g, '');  
  var nums = /^[0-9]*$/;  

   if (x == "") 
   {
       alert("You didn't enter a pin number.\n");
	   if(flag==0)
	   {
       PrPin.style.background='#AAB6C1';
	   PrPin.focus();
       }
	   else if(flag==1)
	   {
	   PtPin.style.background='#AAB6C1';
	   PtPin.focus();
	   }
	   
	   else
	   {
	   CCPin.style.background='#AAB6C1';
	   CCPin.focus();
	   }
	   
	   
	   return false;
    
    } 
	
	else if (!(nums.test(x))) 
	  {
       alert("The pin number contains illegal characters.\n");
	   if(flag==0)
	   {
       PrPin.style.background='#AAB6C1';
	   PrPin.focus();
       }
	   else if(flag==1)
	   {
	   PtPin.style.background='#AAB6C1';
	   PtPin.focus();
	   }
	  
	   else
	   {
	   CCPin.style.background='#AAB6C1';
	   CCPin.focus();
	   }
	   
	   return false;
     
	 
	 } 
	
	
	else if (!(x.length >= 6 && x.length <=10)) 
	{
        alert("The pin number is the wrong length.\n");
		if(flag==0)
	   {
       PrPin.style.background='#AAB6C1';
	   PrPin.focus();
       }
	   else if(flag==1)
	   {
	   PtPin.style.background='#AAB6C1';
	   PtPin.focus();
	   }
	   
	    else
	   {
	    CCPin.style.background='#AAB6C1';
	    CCPin.focus();
	   }
	   
	   return false;
    
    }
   
  }

  
 function checkCompName(x,flag)
{
var illegalChars = /[\W_]/; // allow only letters and numbers 
 
    if (x == "" && (occ1.checked==true || occ2.checked==true)) 
	{
       
	 if(flag==0)
	   {
		alert("Enter current profession.\n");
	   CurProf.style.background='#AAB6C1';
	   CurProf.focus();
	   document.getElementById('CurProf').disabled=false;
	   return false;
	   }
	 else if(flag==1) 
        {
       alert("Enter designation.\n");
	   CurDesg.style.background='#AAB6C1';
	   CurDesg.focus();
	   return false;
	   }
      
     else
       {
       alert("Enter a Company Name.\n");
	   CurCom.style.background='#AAB6C1';
	   CurCom.focus();
	   return false;
	    
		}	   
	 
	   }

	   
	else if (illegalChars.test(x)) 
	 {
       
	   return false;
	   if(flag==0)
	   {
		alert("Highlighted Field contains Illegal Characters.\n");
	   CurProf.style.background='#AAB6C1';
	   CurProf.focus();
	   return false;
	   }
	 else if(flag==1) 
        {
       alert("Designation Contains Illegal Characters.\n");
	   CurDesg.style.background='#AAB6C1';
	   CurDesg.focus();
	   return false;
	   }
      
     else
       {
       alert("Company Name.\n");
	   CurCom.style.background='#AAB6C1';
	   CurCom.focus();
	   return false;
	    
		}	   
	 
	   
	   }  
	  else
       {
        return true;
       }
  
}
 
  
  
  function checkLandmark(x,flag) 
  {
    var illegalChars = /[\W_]/; // allow only letters and numbers 
 
    if (x == "") 
	{
       alert("You didn't enter a landmark.\n");
	   if(flag==0)
	   {
	   PrLandmark.style.background='#AAB6C1';
	   PrLandmark.focus();
	   }
	   else if(flag==1)
	   {
	   PtLandmark.style.background='#AAB6C1';
	   PtLandmark.focus();
	   }
	   
	   else if(flag==2 && (occ1.checked==true || occ2.checked==true))
	   {
	   CCLandmark.style.background='#AAB6C1';
	   CCLandmark.focus();
	   }
	   
    return false;
	} 
	 
	 else if (illegalChars.test(x)) 
	 {
       alert("The landmark contains illegal characters.\n");
	   
	    if(flag==0)
	   {
	   PrLandmark.style.background='#AAB6C1';
	   PrLandmark.focus();
	   }
	   else if(flag==1)
	   {
	   PtLandmark.style.background='#AAB6C1';
	   PtLandmark.focus();
	   }
	    else if(flag==2 && (occ1.checked==true || occ2.checked==true))
	   {
	   CCLandmark.style.background='#AAB6C1';
	   CCLandmark.focus();
	   }
    return false;
	   } 
	
    
        //return true;

 }




 function validateMobile(x) 
   {
    //alert("MOB");
    //var stripped = x.replace(/[\(\)\.\-\ ]/g, '');    
    var nums = /^[0-9]*$/;
    
	if(x=="")
	 {
	  alert("Mobile field is blank");
        Mobile.style.background='#AAB6C1';
	    Mobile.focus();
		return false;
		}
	 
	 
      else if (!(nums.test(x))) 
	  {
     alert("Mobile Phone number contains Illegal Characters.");
     
	 Mobile.style.background='#AAB6C1';
	 Mobile.focus();
     return false;
	 
	 } 
	
	else if (!(x.length == 10)) 
	{
        alert("The mobile phone number is the wrong length.\n");
        Mobile.style.background='#AAB6C1';
	    Mobile.focus();
		return false;
        
    }
   
 
 }




function validateStd(x,flag) 
{
    alert('STD');
    //var stripped = x.replace(/[\(\)\.\-\ ]/g, '');    
    var nums = /^[0-9]*$/;
    
	if(x=="")
	 {
	  alert("Std field is blank");
	    if(flag==0)
		{
        Std.style.background='#AAB6C1';
	    Std.focus();
		return false;
		}
		 else if(flag==1 && (occ1.checked==true || occ2.checked==true))
		{
		CCStd.style.background='#AAB6C1';
		CCStd.focus();
		return false;
		}
		else if(flag==2 && (occ1.checked==true || occ2.checked==true))
		{
		CCFaxStd.style.background='#AAB6C1';
		CCFaxStd.focus();
		return false;
		}
		
		
      
	  }
	 
	 
      else if (!(nums.test(x))) 
	  {
     alert("Std contains Illegal Characters.");
     if(flag==0)
	 {
	 Std.style.background='#AAB6C1';
	 Std.focus();
	 return false;
     }
	 
	 else if(flag==1 && (occ1.checked==true || occ2.checked==true))
		{
		CCStd.style.background='#AAB6C1';
		CCStd.focus();
		return false;
		}
		
		else if(flag==2 && (occ1.checked==true || occ2.checked==true))
		{
		CCFaxStd.style.background='#AAB6C1';
		CCFaxStd.focus();
		return false;
		}
	 
	 
	 } 
	
	else if (x.length !=3) 
	{
        alert("Std number is the wrong length.\n");
		if(flag==0)
		{
        Std.style.background='#AAB6C1';
	    Std.focus();
		return false;
        }
		
		 else if(flag==1 && (occ1.checked==true || occ2.checked==true))
		{
		CCStd.style.background='#AAB6C1';
		CCStd.focus();
		return false;
		}
		
		 else if(flag==2 && (occ1.checked==true || occ2.checked==true))
		{
		CCFaxStd.style.background='#AAB6C1';
		CCFaxStd.focus();
		return false;
		}
		
		
    }
   
   else
    return true;
}  


function validateLandline(x,flag) 
{
    //alert("MOB");
    //var stripped = x.replace(/[\(\)\.\-\ ]/g, '');    
    var nums = /^[0-9]*$/;
    
	if(x=="")
	 {
	  alert("Highlighted field is blank");
	    if(flag==0)
		{
        Landline.style.background='#AAB6C1';
	    Landline.focus();
		return false;
		}
		else if(flag==1 && (occ1.checked==true || occ2.checked==true))
		 {
		 CCLand.style.background='#AAB6C1';
	    CCLand.focus();
		return false;
		 }
		 else if(flag==2 && (occ1.checked==true || occ2.checked==true))
		  {
		  CCFax.style.background='#AAB6C1';
	      CCFax.focus();
          return false;
		  }
		
      
	  }
	 
	 
      else if (!(nums.test(x))) 
	  {
     alert("Highlighted Field contains Illegal Characters.");
    if(flag==0)
		{
        Landline.style.background='#AAB6C1';
	    Landline.focus();
		return false;
		}
		else if(flag==1 && (occ1.checked==true || occ2.checked==true))
		 {
		 CCLand.style.background='#AAB6C1';
	    CCLand.focus();
		return false;
		 }
		 else if(flag==2 && (occ1.checked==true || occ2.checked==true))
		 {
		  CCFax.style.background='#AAB6C1';
	      CCFax.focus();
		  return false;
          }
		
	 } 
	
	else if (!(x.length ==8)) 
	{
        alert("Highlighted Field is the wrong length.\n");
        if(flag==0)
		{
        Landline.style.background='#AAB6C1';
	    Landline.focus();
		return false;
		}
		else if(flag==1 && (occ1.checked==true || occ2.checked==true))
		 {
		 CCLand.style.background='#AAB6C1';
	    CCLand.focus();
		return false;
		 }
		 
		else if(flag==2 && (occ1.checked==true || occ2.checked==true))
		 {
		  CCFax.style.background='#AAB6C1';
	      CCFax.focus();
          return false;
          }
		
    }
   
   else
    return true;
}  

function trim(x)
{
  return x.replace(/^\s+|\s+$/, '');
}

function validateEmail(x,flag) 
{
    //var error="";
    var tfld = trim(x);                        // value of field with whitespace trimmed off
    var emailFilter = /^[^@]+@[^@.]+\.[^@]*\w\w$/ ;
    var illegalChars= /[\(\)\<\>\,\;\:\\\"\[\]#]/ ;
   
    if (x == "") 
	{
        alert("You didn't enter an email address.\n");
		if(flag==0)
		{
		EmailPer.style.background = '#AAB6C1';
		EmailPer.focus();
		}
		else
		{
		EmailOff.style.background = '#AAB6C1';
        EmailPer.focus();
		}
		
        return false;
	} 
	else if (!emailFilter.test(tfld)) 
	{              //test email for illegal characters
         
		 alert("Please enter a valid email address.\n");
		 
		 if(flag==0)
		{
		EmailPer.style.background = '#AAB6C1';
		EmailPer.focus();
		}
		else
		{
		EmailOff.style.background = '#AAB6C1';
        EmailPer.focus();
		}
		
        return false;
		 
		 
	}
	
	else if (x.match(illegalChars)) 
	{
        alert("The email address contains illegal characters.\n");
		if(flag==0)
		{
		EmailPer.style.background = '#AAB6C1';
		EmailPer.focus();
		}
		else
		{
		EmailOff.style.background = '#AAB6C1';
        EmailPer.focus();
		}
		
        return false;
	
}

}

function checkYear(x,flag)
 {
 
 var nums = /^[0-9]*$/;  

   if (x == "") {
       alert("Enter the Year.\n");
	   if(flag==0)
	   {
       YearJoin.style.background='#AAB6C1';
	   YearJoin.focus();
       }
	   else
	   {
	   YearPass.style.background='#AAB6C1';
	   YearPass.focus();
	   }
	   return false;
    
    } 
	
	else if (!(nums.test(x))) 
	  {
       alert("The pin number contains illegal characters.\n");
	   if(flag==0)
	   {
       YearJoin.style.background='#AAB6C1';
	   YearJoin.focus();
       }
	   else
	   {
	   YearPass.style.background='#AAB6C1';
	   YearPass.focus();
	   }
	   return false;
     
	 
	 } 
	
	
	else if (!(x.length==4)) 
	{
        alert("The Year is the wrong length(YYYY).\n");
		
		if(flag==0)
		{
			YearJoin.style.background='#AAB6C1';
			YearJoin.focus();
		}
	   else
		{
			YearPass.style.background='#AAB6C1';
			YearPass.focus();
		}
	   
	   return false;
    
    }
 
 else if(x=='0000')
    {
	alert("Invalid Year!!");
	
	if(flag==0)
		{
			YearJoin.style.background='#AAB6C1';
			YearJoin.focus();
		}
	   
	   else
		{
			YearPass.style.background='#AAB6C1';
			YearPass.focus();
		}
	   return false;
	}
   else
    return true;
 }

function insert_AJAX()
{
		alert("ajax caled!!");
		xmlhttp=GetXmlHttpObject();
				if (xmlhttp==null)
				{
					alert ("Browser does not support HTTP Request");
					return;
				}

	var Surname;
	var Name,photo;
	var Sex,Dob,PrAdd,PrPin,PrLandmark,Mobile,Std,Landline,EmailPer,EmailOff,PtAdd,PtPin,PtLandmark,btech,msc,mtech,phd,YearJoin,YearPass,occ,Com,CurProf,CurDesg,CurCom,CCAdd,CCPin,CCLandmark,CCStd,CCLand,CCFaxStd,CCFax,CaFrom,CaTo,CaName,CbFrom,Cbto,CbName,Dec;
	
	Surname=document.getElementById("surname").value;
	Name=document.getElementById("Name").value;
	photo=0;
	//alert(document.getElementById("Sex1").checked);
	if(document.getElementById("Sex1").checked==true)
	{
	  Sex=document.getElementById("Sex1").value;
	  //alert(Sex);
    }
	else if(document.getElementById("Sex1").checked=true)
	{
	Sex = document.getElementById("Sex2").value;
	//alert(Sex);
	}
	
	Dob=document.getElementById("Dob").value;
	//alert (Dob);
	
	PrAdd=document.getElementById("PrAdd").value;
	PrPin=document.getElementById("PrPin").value;
	PrLandmark=document.getElementById("PrLandmark").value;
	Mobile=document.getElementById("Mobile").value;
	Std=document.getElementById("Std").value;
	Std += document.getElementById("Landline").value;
	//alert(Std);
	EmailPer=document.getElementById("EmailPer").value;
	EmailOff=document.getElementById("EmailOff").value;
	PtAdd=document.getElementById("PtAdd").value;
	PtPin=document.getElementById("PtPin").value;
	PtLandmark=document.getElementById("PtLandmark").value;
	
	if(document.getElementById("btech").checked==true)
	btech=1;
	else
	btech=0;
	if(document.getElementById("msc").checked==true)
	msc=1;
	else
	msc=0;
	
	if(document.getElementById("mtech").checked==true)
	mtech=1;
	else
	mtech=0;
	
	if(document.getElementById("phd").checked==true)
	phd=1;
    else
    phd=0;
	
	
	YearJoin=document.getElementById("YearJoin").value;
	
	YearPass=document.getElementById("YearPass").value;
	//alert(YearPass);
	
	//alert(document.getElementById("occ1").checked);
	//alert("222");
	if(document.getElementById("occ1").checked == true)
	{
	  occ=document.getElementById("occ1").value;
	  alert("111")
	   //alert(occ);
	 }
	else if(document.getElementById("occ2").checked==true)
	 {
	   occ=document.getElementById("occ2").value;
	   //alert(occ);
	  }
	else if(document.getElementById("occ3").checked==true)
	{
	occ=document.getElementById("occ3").value;
	//alert(occ);
	}
	else if(document.getElementById("occ4").checked==true)
	{
	occ=document.getElementById("occ4").value;
	//alert(occ);
	}
	
	
	if(document.getElementById("Com1").checked==true)
	{
	Com=document.getElementById("Com1").value;
	//alert(Com);
	}
	
	
	else if(document.getElementById("Com2").checked==true)
	{
	Com=document.getElementById("Com2").value;
	//alert(Com);
	}
	
	CurProf=document.getElementById("CurProf").value;
	CurDesg=document.getElementById("CurDesg").value;
	CurCom=document.getElementById("CurCom").value;
	CCAdd=document.getElementById("CCAdd").value;
	CCPin=document.getElementById("CCPin").value;
	CCLandmark=document.getElementById("CCLandmark").value;
	
	CCStd=document.getElementById("CCStd").value;
	CCStd += document.getElementById("CCLand").value;
	//alert(CCStd);
	
	CCFaxStd=document.getElementById("CCFaxStd").value;
	CCFaxStd += document.getElementById("CCFax").value;
	//alert(CCFaxStd);
	
	CaFrom=document.getElementById("CaFrom").value;
	CaTo=document.getElementById("CaTo").value;
	CaName=document.getElementById("CaName").value;
	CbFrom=document.getElementById("CbFrom").value;
	Cbto=document.getElementById("Cbto").value;
	CbName=document.getElementById("CbName").value;
	//alert(CbName);
	
	if(document.getElementById("Dec1").checked==true)
	Dec=document.getElementById("Dec1").value;
		
	if(document.getElementById("Dec2").checked==true)
	Dec=document.getElementById("Dec2").value;
	
	//alert("!!!!!");
	
	var InsertSql="Insert into prof values('"+ Surname +"','"+Name+"','"+Sex+"','"+Dob+"','"+PrAdd+"','"+PrPin+"','"+PrLandmark+"','"+PtAdd+"','"+PtPin+"','"+PtLandmark+"','"+Mobile+"','"+Std+"','"+EmailOff+"','"+EmailPer+"','"+YearJoin+"','"+YearPass+"','"+occ+"','"+btech+"','"+msc+"','"+mtech+"','"+phd+"','"+photo+"','"+CurProf+"','"+CurDesg+"','"+CurCom+"','"+CCAdd+"','"+CCPin+"','"+CCLandmark+"','"+CCStd+"','"+CCFaxStd+"','"+CaFrom+"','"+CaTo+"','"+CaName+"','"+CbFrom+"','"+Cbto+"','"+CbName+"','"+Com+"',";
    var year= document.getElementById("YearJoin").value;	

	var url="InsertIntoProfile.asp";
	url=url+"?InsertSql="+InsertSql+"&Std="+Math.random();
    alert(year);
	alert(url);
    var	Y="?year="+year;
	xmlhttp.open('GET',url,Y,true);
	xmlhttp.onreadystatechange=stateChanged;
	xmlhttp.send(null);
}

function stateChanged()
		{
			if (xmlhttp.readyState==4)
			{
				alert(xmlhttp.responseText);
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


function t()
{
    var x;
    
   
   x=Math.random();
   x=x*10000000000000000;
   x=x%100000000000000000;
	
	document.form1.name.value=document.form1.name.value+x;
	document.getElementById('disablingDiv').style.display='block';
	document.getElementById('white_content').style.display='block';
    
}
function check()
{
if(document.form1.file.value=="")
 alert('Nothing to Upload!');
 
 }
