VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   4935
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6660
   LinkTopic       =   "Form1"
   ScaleHeight     =   4935
   ScaleWidth      =   6660
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command3 
      Caption         =   "EXIT"
      Height          =   1095
      Left            =   2280
      TabIndex        =   2
      Top             =   2880
      Width           =   2295
   End
   Begin VB.CommandButton Command2 
      Caption         =   "INSERT"
      Height          =   1215
      Left            =   3840
      TabIndex        =   1
      Top             =   840
      Width           =   2055
   End
   Begin VB.CommandButton Command1 
      Caption         =   "VIEW"
      Height          =   1215
      Left            =   600
      TabIndex        =   0
      Top             =   840
      Width           =   2055
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      Caption         =   "MAIN"
      Height          =   195
      Left            =   3030
      TabIndex        =   3
      Top             =   240
      Width           =   435
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    Form2.Show
    Hide
    
End Sub

Private Sub Command2_Click()
    Form3.Show
    Hide
    
End Sub

Private Sub Command3_Click()
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
    Unload Me
    
    
End Sub
