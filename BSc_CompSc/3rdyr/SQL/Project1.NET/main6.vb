Option Strict Off
Option Explicit On
Friend Class Form17
	Inherits System.Windows.Forms.Form
	Private Sub Command1_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command1.Click
		Hide()
		Form1.Show()
	End Sub
	
	Private Sub Command2_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command2.Click
		Hide()
		Form9.Show()
	End Sub
	
	Private Sub Command3_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command3.Click
		Form16.Close()
		Form13.Close()
		Form14.Close()
		Form15.Close()
		Form11.Close()
		Form10.Close()
		Form12.Close()
		Form2.Close()
		Form3.Close()
		Form4.Close()
		Form5.Close()
		Form6.Close()
		Form7.Close()
		Form8.Close()
		Form9.Close()
		Me.Close()
	End Sub
End Class