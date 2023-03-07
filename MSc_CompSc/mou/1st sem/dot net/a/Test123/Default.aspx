<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
        <div id="Div1">
            <%-- Create Table for Labels  --%>
            <table width="100%" cellpadding="0" cellspacing="0" border="0">
                <tr align="center" bgcolor="white">
                    <td align="center" width="15%">
                    </td>
                    <td align="center" width="15%">
                        <asp:Label Font-Bold="true" ID="L1" Text="Name" runat="server"></asp:Label>
                    </td>
                    <td align="center" width="15%">
                        <asp:Label Font-Bold="true" ID="L2" Text="Age" runat="server"></asp:Label>
                    </td>
                    <td align="center" width="15%">
                        <asp:Label Font-Bold="true" ID="L3" Text="Sex" runat="server"></asp:Label>
                    </td>
                    <td align="center" width="15%">
                        <asp:Label Font-Bold="true" ID="L4" Text="Address" runat="server"></asp:Label>
                    </td>
                    <td align="center" width="15%">
                        <asp:Label Font-Bold="true" ID="L5" Text="Salary" runat="server"></asp:Label>
                    </td>
                    <td align="center" width="15%">
                        <asp:Label Font-Bold="true" ID="L6" Text="Grade" runat="server"></asp:Label>
                    </td>
                </tr>
            </table>
            <%--Create Table for Initial TextBox and DropDownList--%>
            <table width="100%" border="1" id="TextTbl" cellpadding="0" cellspacing="0" bgcolor="#ffff99">
                <tr align="center" bgcolor="#ffff99" style="table-layout: auto; border-collapse: separate;">
                    <%--Create Button for Delete Row--%>
                    <td align="center" width="15%">
                        <input type="button" id="btn1" onclick="DeleteRow(this)" value="Delete" />
                    </td>
                    <%--Create TextBoxes for Initial Display of Texts--%>
                    <td align="center" width="15%">
                        <asp:TextBox ID="t1" Text="" runat="server">
                        </asp:TextBox>
                    </td>
                    <td align="center" width="15%">
                        <asp:TextBox ID="t2" Text="" runat="server">
                        </asp:TextBox>
                    </td>
                    <td align="center" width="15%">
                        <asp:TextBox ID="t3" Text="" runat="server">
                        </asp:TextBox>
                    </td>
                    <td align="center" width="15%">
                        <asp:TextBox ID="t4" Text="" runat="server">
                        </asp:TextBox>
                    </td>
                    <td align="center" width="15%">
                        <asp:TextBox ID="t5" Text="" runat="server">
                        </asp:TextBox>
                    </td>
                    <%--Create DropDownLists for Initial Display of Grade--%>
                    <td align="center" width="15%">
                        <asp:DropDownList ID="DropDownList1" runat="server">
                            <asp:ListItem>A</asp:ListItem>
                            <asp:ListItem>B</asp:ListItem>
                        </asp:DropDownList>
                    </td>
                </tr>
            </table>
        </div>
        <%--Create Button for Addition of moreRows--%>
        <input id="Button1" type="button" size="100%" onclick="AddMoreRows()" value="Click Here"
            runat="server" />
        <%--Create Button for Display the Added Rows--%>
        <input id="add1" onclick="Display()" type="button" value="Show" runat="server" />
        <%--Create Button for Submit the Result to Server Side/Data Base--%>
        <%--            <input  onserverclick ="submit" type="button" value = "Go and Save" id ="S1" runat="server"  /> 
--%>
        <!-- Show List-->
        <table width="100%" runat="server">
            <tr>
                <td align="center" width="50%" runat="server">
                    <asp:Label Text=" " runat="server">Show List</asp:Label>
                </td>
                <td width="50%" align="right" runat="server">
                </td>
            </tr>
        </table>
        <%--DIV(d1) Display the Added Rows         --%>
        <div id="d1"
        </div>
    </form>
</body>
</html>
<!-- JS - Script -->

<script type="text/javascript" language="javascript">

headerRender = false;
var ObjTbody = null;

// This function Add the Repeatitive Rows -- Selected By The User
function AddMoreRows()
{
      debugger;    // Exeption 
  try
  {
         // Create the object for DIV with "Div1" id  that holds the Lables,Initial Texts,Buttons,Added Texts
            var objDiv = document.getElementById("Div1");     
         // Create the object for TABLE with "TextTbl" id that holds Initial TextBox and DropDownList
            var objTable = document.getElementById("TextTbl");
         // Create the object for New TABLE that holds Initial TextBox and DropDownList repeatedly with te help of 'cloneNode' of previous one
            var objNewTable = objTable.cloneNode(true);
            
         // Get the value of inserted rows from 'objNewTable' in DIV > TR > TD > item fasion for Name,Age,Sex,Sal,Grade   
                objNewTable.childNodes[0].childNodes[0].childNodes[1].childNodes[0].value = ""	;
                objNewTable.childNodes[0].childNodes[0].childNodes[2].childNodes[0].value = ""	;		
                objNewTable.childNodes[0].childNodes[0].childNodes[3].childNodes[0].value = ""	;		
                objNewTable.childNodes[0].childNodes[0].childNodes[4].childNodes[0].value = ""	;		
                objNewTable.childNodes[0].childNodes[0].childNodes[5].childNodes[0].value = ""	;	
                
         // Get the values in DIV with appendChild of 'objNewTable'
	            objDiv.appendChild(objNewTable);
    
  }
  
        // For Error Handling Purpose
  catch(e)
  {
                alert(e.message);
  }
  
}

// This Function Delete The Seleted Rows
function DeleteRow(elembutton)
{
debugger;
   var returnValue= confirm("Do you really want to delete this row??");
   if(returnValue)
   {
       if(elembutton.parentElement.parentElement.parentElement.parentElement.parentElement.childNodes.length == 2)
       {
         alert("You can not delete all rows")
         return;
       }
        
      elembutton.parentElement.parentElement.parentElement.parentElement.parentElement.removeChild(elembutton.parentElement.parentElement.parentElement.parentElement)
  }
}

// This Function Display the Added Rows in the another DIV("d1")
function Display()
{debugger;
    // define the 'objDiv' that holds the "Div1" for accessing the initial DIV
    var objDiv = document.getElementById("Div1");
   // define the 'objDiv1' that holds the "d1" for holding the elements of "Display function"
    var objDiv1 = document.getElementById("d1");
   // define the 'ObjTable' for rendering the newly generated table
    var ObjTable = document.createElement ("TABLE");
    
   // Rendering the newly created table 
    if(!headerRender)
    {
                          // Table formatting
            headerRender  = true;
            objDiv1.appendChild(ObjTable );
            ObjTable.style.width = "100%";
            ObjTable.setAttribute("border","2px"); 
            ObjTbody = document.createElement("TBODY");
            ObjTbody .style.border = "2px"; 
            ObjTbody.style.color="Blue";
            ObjTable.appendChild(ObjTbody );

            var ObjTr = document.createElement("TR");
            ObjTbody .appendChild(ObjTr);

            var ObjTd1 = document.createElement("TD");
            ObjTd1 .innerText = "Name";
            ObjTd1.style.width = "30%" ;
            ObjTr.appendChild(ObjTd1);

            var ObjTd2 = document.createElement("TD");
            ObjTd1.style.width = "30%" ;
            ObjTd2.innerText = "Age";
            ObjTr.appendChild(ObjTd2);
         
            var ObjTd3 = document.createElement("TD");
            ObjTd1.style.width = "30%" ;
            ObjTd3 .innerText = "Sex";
            ObjTr.appendChild(ObjTd3);
            
            var ObjTd4 = document.createElement("TD");
            ObjTd1.style.width = "30%"; 
            ObjTd4 .innerText = "Address";
            ObjTr.appendChild(ObjTd4);
            
            
            var ObjTd5 = document.createElement("TD");
            ObjTd1.style.width = "30%" ;
            ObjTd5 .innerText = "Salary";
            ObjTr.appendChild(ObjTd5);
            
            
            var ObjTd6_DropDownList = document.createElement("TD");
            ObjTd1.style.width = "30%"; 
            ObjTd6_DropDownList.innerText = "Grade";
            ObjTr.appendChild(ObjTd6_DropDownList);  
            
    } 
debugger;    
              // Declare the arrays for Populating the items into the new table  
            var arrname = new Array();
            var arrage = new Array();
            var arrsex  = new Array();
            var arraddr = new Array();
            var arrsal = new Array();
            var arrgrade = new Array(); 
            
            // Getting the values in DIV > TR > TD > item fasion as Name,Age,Sex,Sal,Grade and populate them         
            for (var i = 1; i < objDiv.childNodes.length; i++)
            {
              var objNewTable = objDiv.childNodes[i];
                  arrname[arrname.length] = objNewTable.childNodes[0].childNodes[0].childNodes[1].childNodes[0].value ;
	              arrage[arrage.length] = objNewTable.childNodes[0].childNodes[0].childNodes[2].childNodes[0].value	;		
	              arrsex[arrsex.length] = objNewTable.childNodes[0].childNodes[0].childNodes[3].childNodes[0].value ;		
	              arraddr[arraddr.length] = objNewTable.childNodes[0].childNodes[0].childNodes[4].childNodes[0].value ;			  
	              arrsal[arrsal.length] = objNewTable.childNodes[0].childNodes[0].childNodes[5].childNodes[0].value ;	
	              arrgrade[arrgrade.length] = objNewTable.childNodes[0].childNodes[0].childNodes[6].childNodes[0].value	;	
             
            }
           // Rendering the Values into the newly Created Table
        for (var j = 0; j < /*objDiv.childNodes.length;*/arrname.length ; j++)
        {
                   var ObjTr1 = document.createElement("TR");
                   ObjTbody.appendChild(ObjTr1);
                   
                   var ObjTd7 = document.createElement("TD");
                       ObjTd7 .innerText = arrname[j];
                       ObjTd7.style.width = "30%" ;
                       ObjTr1.appendChild(ObjTd7);
                       
                   var ObjTd8 = document.createElement("TD");
                       ObjTd8 .innerText = arrage[j];
                       ObjTd8.style.width = "30%" ;
                       ObjTr1.appendChild(ObjTd8);
                       
                   var ObjTd9 = document.createElement("TD");
                       ObjTd9 .innerText = arrsex[j];
                       ObjTd9.style.width = "30%" ;
                       ObjTr1.appendChild(ObjTd9);
                       
                   var ObjTd10 = document.createElement("TD");
                       ObjTd10 .innerText = arraddr[j];
                       ObjTd10.style.width = "30%" ;
                       ObjTr1.appendChild(ObjTd10);
                       
                   var ObjTd11 = document.createElement("TD");
                       ObjTd11 .innerText = arrsal[j];
                       ObjTd11.style.width = "30%" ;
                       ObjTr1.appendChild(ObjTd11);
                       
                   var ObjTd12 = document.createElement("TD");
                       ObjTd12 .innerText = arrgrade[j];
                       ObjTd12.style.width = "30%" ;
                       ObjTr1.appendChild(ObjTd12);
                                       
          }            
                           
        }                    
</script>

