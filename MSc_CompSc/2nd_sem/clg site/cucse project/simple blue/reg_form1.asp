<!-- #include file="ShadowUploader.asp" -->
<%
Dim objUpload ,name
name=Request.Form("name")
        
If Request("action")="1" Then
	Set objUpload=New ShadowUpload
	If objUpload.GetError<>"" Then
%>
         <script language="javascript">
           <!--
           alert('File not found!');
           //-->
          </script>
 <%
	Else  

		For x=0 To objUpload.FileCount-1
			
			If ((objUpload.File(x).ImageWidth<0) or(objUpload.File(x).ContentType="image/gif")) Then
 %>
                <script language="javascript">
                 <!--
                 alert('Image File is not valid!');
                 //-->
               </script>
 <%
		    Else
			 
			   If (objUpload.File(x).ImageWidth>2000) Or (objUpload.File(x).ImageHeight>2000) Then
%>
                <script language="javascript">
                 <!--
                 alert('Image File is too big for saving.Please try again.');
                 //-->
               </script>
 <%
			    Else  
				   Call objUpload.File(x).SaveToDisk(Server.MapPath("Pics"),objUpload("name"))
 
			    End If
			End If
			
		Next
		
	End If
End If
%>