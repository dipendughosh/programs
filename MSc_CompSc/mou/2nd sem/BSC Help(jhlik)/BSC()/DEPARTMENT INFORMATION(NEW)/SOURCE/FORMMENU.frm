VERSION 5.00
Begin VB.Form FORMMENU 
   BackColor       =   &H0080C0FF&
   Caption         =   "FORMMENU"
   ClientHeight    =   3090
   ClientLeft      =   165
   ClientTop       =   855
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   10710
   ScaleWidth      =   15240
   StartUpPosition =   3  'Windows Default
   WindowState     =   2  'Maximized
   Begin VB.Menu FORMDETAILS 
      Caption         =   "FORMDETAILS"
      Begin VB.Menu ALLFORM 
         Caption         =   "ALLFORM"
      End
      Begin VB.Menu STUDENT 
         Caption         =   "STUDENT"
      End
      Begin VB.Menu FACULTY 
         Caption         =   "FACULTY"
      End
      Begin VB.Menu ADDMISSION 
         Caption         =   "ADDMISSION"
      End
      Begin VB.Menu RESULT 
         Caption         =   "RESULT"
      End
   End
   Begin VB.Menu EXIT 
      Caption         =   "EXIT"
   End
End
Attribute VB_Name = "Formmenu"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub ADDMISSION_Click()
FORMADDMISSION.Visible = True
End Sub

Private Sub ALLFORM_Click()
FORMDETAIL.Show
End Sub

Private Sub EXIT_Click()
FormOPEN.Show
End Sub

Private Sub FACULTY_Click()
FORMFACULTY.Visible = True
End Sub

Private Sub RESULT_Click()
FORMRESULT.Visible = True
End Sub

Private Sub STUDENT_Click()
FORMSTUDENT.Visible = True
End Sub
