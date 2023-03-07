VERSION 5.00
Begin VB.Form Form3 
   Caption         =   "Form3"
   ClientHeight    =   4470
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6870
   LinkTopic       =   "Form3"
   ScaleHeight     =   4470
   ScaleWidth      =   6870
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command5 
      Caption         =   "BACK"
      Height          =   855
      Left            =   2760
      TabIndex        =   5
      Top             =   2880
      Width           =   2055
   End
   Begin VB.CommandButton Command4 
      Caption         =   "CITY"
      Height          =   735
      Left            =   720
      TabIndex        =   4
      Top             =   2880
      Width           =   1575
   End
   Begin VB.CommandButton Command3 
      Caption         =   "TRUCK"
      Height          =   615
      Left            =   4440
      TabIndex        =   3
      Top             =   2040
      Width           =   1575
   End
   Begin VB.CommandButton Command2 
      Caption         =   "SHIPMENT"
      Height          =   615
      Left            =   2520
      TabIndex        =   2
      Top             =   1920
      Width           =   1575
   End
   Begin VB.CommandButton Command1 
      Caption         =   "CUSTOMER"
      Height          =   735
      Left            =   720
      TabIndex        =   1
      Top             =   1800
      Width           =   1455
   End
   Begin VB.Label Label1 
      Caption         =   "INSERT"
      Height          =   735
      Left            =   2280
      TabIndex        =   0
      Top             =   840
      Width           =   2295
   End
End
Attribute VB_Name = "Form3"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    Hide
    Form8.Show
    
End Sub

Private Sub Command2_Click()
    Hide
    Form9.Show
    
End Sub

Private Sub Command3_Click()
    Hide
    Form10.Show
    
End Sub

Private Sub Command4_Click()
    Hide
    Form11.Show
    
End Sub

Private Sub Command5_Click()
    Hide
    Form1.Show
    
End Sub

