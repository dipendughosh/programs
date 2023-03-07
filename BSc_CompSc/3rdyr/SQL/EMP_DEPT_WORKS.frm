VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command4 
      Caption         =   "CLOSE AND EXIT"
      Height          =   615
      Left            =   600
      TabIndex        =   6
      Top             =   2160
      Width           =   3615
   End
   Begin VB.CommandButton Command3 
      Caption         =   "INSERT INTO WORKS"
      Height          =   195
      Left            =   1920
      TabIndex        =   5
      Top             =   1560
      Width           =   2655
   End
   Begin VB.CommandButton Command2 
      Caption         =   "INSERT INTO DEPARTMENTS"
      Height          =   195
      Left            =   1920
      TabIndex        =   4
      Top             =   960
      Width           =   2655
   End
   Begin VB.CommandButton Command1 
      Caption         =   "INSRT INTO EMPLOYEE"
      Height          =   195
      Left            =   1920
      TabIndex        =   3
      Top             =   360
      Width           =   2655
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "WOKRS"
      Height          =   195
      Left            =   360
      TabIndex        =   2
      Top             =   1560
      Width           =   615
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "DEPARTMENTS"
      Height          =   195
      Left            =   360
      TabIndex        =   1
      Top             =   960
      Width           =   1230
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "EMPLOYEE"
      Height          =   195
      Left            =   360
      TabIndex        =   0
      Top             =   360
      Width           =   870
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
    Form4.Show
    Hide
End Sub

Private Sub Command4_Click()
    Unload Form2
    Unload Form3
    Unload Form4
    Unload Me
End Sub
