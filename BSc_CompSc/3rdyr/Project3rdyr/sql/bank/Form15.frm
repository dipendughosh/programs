VERSION 5.00
Begin VB.Form Form15 
   Caption         =   "Form15"
   ClientHeight    =   5250
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6705
   LinkTopic       =   "Form15"
   ScaleHeight     =   5250
   ScaleWidth      =   6705
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command3 
      Caption         =   "E X I T"
      Height          =   1095
      Left            =   2160
      TabIndex        =   2
      Top             =   3480
      Width           =   2055
   End
   Begin VB.CommandButton Command2 
      Caption         =   "V I E W  D A T A"
      Height          =   1095
      Left            =   2160
      TabIndex        =   1
      Top             =   1920
      Width           =   2055
   End
   Begin VB.CommandButton Command1 
      Caption         =   "I N S E R T  D A T A"
      Height          =   1095
      Left            =   2160
      TabIndex        =   0
      Top             =   600
      Width           =   2055
   End
End
Attribute VB_Name = "Form15"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    Form1.Show
    Hide
End Sub
Private Sub Command2_Click()
    Form14.Show
    Hide
End Sub
Private Sub Command3_Click()
    Close
    Unload Form1
    Unload Form2
    Unload Form3
    Unload Form4
    Unload Form5
    Unload Form6
    Unload Form7
    Unload Form8
    Unload Form9
    Unload Form10
    Unload Form11
    Unload Form12
    Unload Form13
    Unload Form14
    Unload Me
End Sub
