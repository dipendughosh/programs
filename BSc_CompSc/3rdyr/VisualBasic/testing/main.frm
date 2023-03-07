VERSION 5.00
Begin VB.Form main 
   Caption         =   "main"
   ClientHeight    =   3165
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4410
   LinkTopic       =   "Form1"
   ScaleHeight     =   3165
   ScaleWidth      =   4410
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command3 
      Caption         =   "close"
      Height          =   495
      Left            =   1920
      TabIndex        =   2
      Top             =   1800
      Width           =   1095
   End
   Begin VB.CommandButton Command2 
      Caption         =   "details"
      Height          =   495
      Left            =   1920
      TabIndex        =   1
      Top             =   1080
      Width           =   1095
   End
   Begin VB.CommandButton Command1 
      Caption         =   "student"
      Height          =   495
      Left            =   1920
      TabIndex        =   0
      Top             =   360
      Width           =   1095
   End
End
Attribute VB_Name = "main"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    student.Show
    main.Hide
End Sub

Private Sub Command2_Click()
    details.Show
    main.Hide
End Sub

Private Sub Command3_Click()
    Unload Me
    Unload student
    Unload details
    
End Sub
