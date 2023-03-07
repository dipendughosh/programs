
<%
Dim strImageName, strThumbName, objXML
strImageName = "me.jpeg"
strThumbName = "me_thumb.jpeg"
Set objXML = Server.CreateObject("Microsoft.XMLHTTP")
objXML.Open "GET", "http://localhost/alumni/ImageResizer.aspx?image=" & Server.MapPath(strImageName) & "&thumb=" & Server.MapPath(strThumbName) & "&width=200&height=200", True
objXML.Send
Set objXML=Nothing

%>