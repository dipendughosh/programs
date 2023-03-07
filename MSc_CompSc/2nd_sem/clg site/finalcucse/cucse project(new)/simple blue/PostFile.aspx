<%@ Page Language="VBscripts"%>
<script runat="server">
   Protected Sub 
   Button1_Click(ByVal sender As Object, ByVal e As System.EventArgs)
        If FileUpload1.HasFile Then
            Try
                FileUpload1.SaveAs("/cucse/wwwroot/alumni/AspFileUpload/FileUpload1.FileName)
                Label1.Text = "File name: " & _
                   FileUpload1.PostedFile.FileName & "<br>" & _
                   "File Size: " & _
                   FileUpload1.PostedFile.ContentLength & " kb<br>" & _
                   "Content type: " & _
                   FileUpload1.PostedFile.ContentType
            Catch ex As Exception
                Label1.Text = "ERROR: " & ex.Message.ToString()
            End Try
        Else
            Label1.Text = "You have not specified a file."
        End If
   End Sub

</script>
<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>FileUpload Server Control</title>
</head>
<body>
    <form id="form1" runat="server">

        <asp:FileUpload ID="FileUpload1" runat="server" />
        <p>
        <asp:Button ID="Button1" runat="server" Text="Upload" 
         OnClick="Button1_Click" /></p>
        <p>
        <asp:Label ID="Label1" runat="server"></asp:Label></p>

    </form>
</body>
</html>