Option Strict Off
Option Explicit On
Friend Class Form13
	Inherits System.Windows.Forms.Form
	Dim con As New RDO.rdoConnection
	Dim rs As RDO.rdoResultset
	
	Private Sub Command1_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command1.Click
		rs.MoveNext()
		If rs.EOF = True Then
			rs.MoveFirst()
		End If
		Label8.Text = rs.rdoColumns("DNAME").Value
		Label9.Text = rs.rdoColumns("CNO").Value
		Label10.Text = rs.rdoColumns("CNAME").Value
	End Sub
	
	
	Private Sub Command2_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command2.Click
		rs.MovePrevious()
		If rs.BOF = True Then
			rs.MoveLast()
		End If
		Label8.Text = rs.rdoColumns("DNAME").Value
		Label9.Text = rs.rdoColumns("CNO").Value
		Label10.Text = rs.rdoColumns("CNAME").Value
	End Sub
	
	Private Sub Command3_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command3.Click
		Hide()
		Form9.Show()
	End Sub
	
	Private Sub Form13_Load(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles MyBase.Load
		Dim rdoDriverNoPrompt As Object
		con.Connect = "uid=dipendu08;pwd=dipendu;Driver={Oracle in oracleHome9i}"
		con.EstablishConnection(rdoDriverNoPrompt)
		rs = con.OpenResultset("SELECT * FROM COURSE", RDO.ResultsetTypeConstants.rdOpenStatic)
		Label8.Text = rs.rdoColumns("DNAME").Value
		Label9.Text = rs.rdoColumns("CNO").Value
		Label10.Text = rs.rdoColumns("CNAME").Value
	End Sub
End Class