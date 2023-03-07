VERSION 5.00
Begin VB.Form Form17 
   Caption         =   "Form17"
   ClientHeight    =   3630
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   5505
   LinkTopic       =   "Form17"
   ScaleHeight     =   3630
   ScaleWidth      =   5505
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command3 
      Caption         =   "exit"
      Height          =   1335
      Left            =   720
      TabIndex        =   2
      Top             =   1920
      Width           =   4215
   End
   Begin VB.CommandButton Command2 
      Caption         =   "view"
      Height          =   855
      Left            =   2760
      TabIndex        =   1
      Top             =   600
      Width           =   2415
   End
   Begin VB.CommandButton Command1 
      Caption         =   "insert"
      Height          =   855
      Left            =   720
      TabIndex        =   0
      Top             =   480
      Width           =   1695
   End
End
Attribute VB_Name = "Form17"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    Hide
    Form1.Show
End Sub

Private Sub Command2_Click()
    Hide
    Form9.Show
End Sub

Private Sub Command3_Click()
    Unload Form16
    Unload Form13
    Unload Form14
    Unload Form15
    Unload Form11
    Unload Form10
    Unload Form12
    Unload Form2
    Unload Form3
    Unload Form4
    Unload Form5
    Unload Form6
    Unload Form7
    Unload Form8
    Unload Form9
    Unload Me
End Sub


