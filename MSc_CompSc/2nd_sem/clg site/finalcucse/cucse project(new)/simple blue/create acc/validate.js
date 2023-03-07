

function start(theForm)
 {
    var x;
	var y;
    
	//document.getElementById("conf_password").disable=true;
	x=document.getElementById('new_password').value;
	checkPassword1(x);
	//document.theForm.conf_password.disable=false;
    y=document.getElementById('conf_password').value;
	
	checkBoth(x,y);
 }


 function checkPassword1(x)
{

   var iChars = "!@$%^&*,."; //allowed special characters
   var flag;
        
		for (var i = 0; i < x.length; i++) {
                if (iChars.indexOf(x.charAt(i)) != -1) {
                //alert ("The box has special characters. \nThese are not allowed.\n");
               // return true;
				flag = 1;
              }
           }
   
   if(flag!=1 && x != "")
    {
	alert("Please enter one special special in the Password!");
	new_password.style.background='#AAB6C1';
	new_password.focus();
	}
   
  var iChar = "-_#";  //characters nt allowed

        for (i = 0; i < x.length; i++) 
		{
                if (iChar.indexOf(x.charAt(i)) != -1) 
				 {
                alert ("The box has either a '-' or an '_' or a '#' character. \nThese are not allowed.\n");
				new_password.style.background='#AAB6C1';
				new_password.focus();
                //return false;
			
                  }
        }  
   

	if(x!= "") 
	{
	
      if(x.length < 8)   //password length min 8 constraint1. 
	  {
        alert("Error: Password must contain at least eight characters!");
        new_password.style.background='#AAB6C1';
		new_password.focus();
		return false;
      }
     
      re = /[0-9]/;  //password must contain a nueric character
      if(!re.test(x)) {
        alert("Error: password must contain at least one number (0-9)!");
		new_password.style.background='#AAB6C1';
		new_password.focus();
        return false;
      }
      re = /[a-z]/;  //password must contain a lowercase
      if(!re.test(x)) {
        alert("Error: password must contain at least one lowercase letter (a-z)!");
        new_password.style.background='#AAB6C1';
		new_password.focus();
        return false;
      }
      re = /[A-Z]/;    //password must contain an upper case
      if(!re.test(x)) {
        alert("Error: password must contain at least one uppercase letter (A-Z)!");
        new_password.style.background='#AAB6C1';
		new_password.focus();
        return false;
      }
	  
	
  }

 else if(x == "")
  {
  alert("Please enter password!"); 
  new_password.style.background='#AAB6C1';
  new_password.focus();
  }  

 }

 
 function checkBoth(x,y)
  {
    
	if(x!=y)
	  {
       alert("Confirm Password does not match the entered Password!");
	   conf_password.style.background='#AAB6C1';
       conf_password.focus();
   }
}
	  
	  
