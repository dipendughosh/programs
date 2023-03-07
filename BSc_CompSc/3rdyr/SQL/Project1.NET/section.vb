Option Strict Off
Option Explicit On
Friend Class Form6
	Inherits System.Windows.Forms.Form
	Dim con As New RDO.rdoConnection
	
	Private Sub Command1_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command1.Click
		Dim q As String
		q = "INSERT INTO SECTION(DNAME,CNO,SECNO,PNAME) VALUES('" & Text1.Text & "'," & Text2.Text & "," & Text3.Text & ",'" & Text4.Text & "');"
		con.Execute(q)
		Text1.Text = ""
		Text2.Text = ""
		Text3.Text = ""
		Text4.Text = ""
		Text1.Focus()
	End Sub
	
	Private Sub Command2_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command2.Click
		Hide()
		Form1.Show()
	End Sub
	
	Private Sub Command3_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command3.Click
		Dim Text6 As Object
		Dim Text5 As Object
		Text1.Text = ""
		Text2.Text = ""
		Text3.Text = ""
		Text4.Text = ""
		'UPGRADE_WARNING: Couldn't resolve default property of object Text5.Text. Click for more: 'ms-help://MS.VSCC.v90/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
		Text5.Text = ""
		'UPGRADE_WARNING: Couldn't resolve default property of object Text6.Text. Click for more: 'ms-help://MS.VSCC.v90/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
		Text6.Text = ""
		Text1.Focus()
	End Sub
	
	Private Sub Form6_Load(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles MyBase.Load
		Dim rdoNoDriverPrompt As Object
		con.Connect = "uid=dipendu08;pwd=dipendu;Driver={Oracle in oracleHome9i}"
		con.EstablishConnection(rdoNoDriverPrompt)
	End Sub
	
	Private Sub Form6_FormClosed(ByVal eventSender As System.Object, ByVal eventArgs As System.Windows.Forms.FormClosedEventArgs) Handles Me.FormClosed
		con.Close()
	End Sub
End Class