
function AddOption_List()
{
		
	for (var i=0; i < 31 ;++i)
	{
		var optn = document.createElement('option');
		optn.text = i;		
		optn.value = i;
		strt_dt.options.add(optn);
	   <!--finsh_dt.options.add(optn);-->
	}


 var month = new Array("January","February","March","April","May","June","July","August","September","October","November","December");
 
 
 for (var j=0; j < month.length;++j)
 {
   var optnM=document.createElement('option'); 
   optnM.text=month[j];
   optnM.value=j; 
   month_list.options.add(optnM);
   <!--Fmonth_list.options.add(optnM);-->
 }
 
 for (var k=0;k<= 100; ++k)
 	{
 			var yr; 			
	 		var optnY = document.createElement('option');
	 		yr=2008+k;
			optnY.text = yr;		
			optnY.value = yr;
			year_list.options.add(optnY);
			<!--Fyear_list.options.add(optnY);-->
	}		
}


function AddOption_List2()
{
		
	for (var i=0; i < 31 ;++i)
	{
		var optn = document.createElement('option');
		optn.text = i;		
		optn.value = i;
		finsh_dt.options.add(optn);	        
	}

 var month = new Array("January","February","March","April","May","June","July","August","September","October","November","December");
 
 
 for (var j=0; j < month.length;++j)
 {
   var optnM=document.createElement('option'); 
   optnM.text=month[j];
   optnM.value=j;    
   Fmonth_list.options.add(optnM);
 }
 
 for (var k=0;k<= 100; ++k)
 	{
 			var yr; 			
	 		var optnY = document.createElement('option');
	 		yr=2008+k;
			optnY.text = yr;		
			optnY.value = yr;			
			Fyear_list.options.add(optnY);
	}		
}


function start()
{
  AddOption_List();
  AddOption_List2();
}
window.onload = start;