Option Strict Off
Option Explicit On
Friend Class Form2
	Inherits System.Windows.Forms.Form
	Dim con As New RDO.rdoConnection
	
	Private Sub Command1_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command1.Click
		Dim q As String
		q = "INSERT INTO STUDENT(SID,SNAME,SEX,AGE,YEAR,GPA) VALUES(" & Text1.Text & ",'" & Text2.Text & "','" & Text3.Text & "'," & Text4.Text & "," & Text5.Text & ",'" & Text6.Text & "');"
		con.Execute(q)
		Text1.Text = ""
		Text2.Text = ""
		Text3.Text = ""
		Text4.Text = ""
		Text5.Text = ""
		Text6.Text = ""
		Text1.Focus()
	End Sub
	
	Private Sub Command2_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command2.Click
		Hide()
		Form1.Show()
	End Sub
	
	Private Sub Command3_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command3.Click
		Text1.Text = ""
		Text2.Text = ""
		Text3.Text = ""
		Text4.Text = ""
		Text5.Text = ""
		Text6.Text = ""
		Text1.Focus()
	End Sub
	
	Private Sub Form2_Load(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles MyBase.Load
		Dim rdoNoDriverPrompt As Object
		con.Connect = "uid=dipendu08;pwd=dipendu;Driver={Oracle in oracleHome9i}"
		con.EstablishConnection(rdoNoDriverPrompt)
	End Sub
	
	Private Sub Form2_FormClosed(ByVal eventSender As System.Object, ByVal eventArgs As System.Windows.Forms.FormClosedEventArgs) Handles Me.FormClosed
		con.Close()
	End Sub
End Class