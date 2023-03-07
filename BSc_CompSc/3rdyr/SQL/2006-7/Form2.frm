VERSION 5.00
Begin VB.Form Form2 
   Caption         =   "Form2"
   ClientHeight    =   4200
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6390
   LinkTopic       =   "Form2"
   ScaleHeight     =   4200
   ScaleWidth      =   6390
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command5 
      Caption         =   "BACK"
      Height          =   855
      Left            =   2520
      TabIndex        =   5
      Top             =   2160
      Width           =   2055
   End
   Begin VB.CommandButton Command4 
      Caption         =   "CITY"
      Height          =   735
      Left            =   480
      TabIndex        =   4
      Top             =   2160
      Width           =   1575
   End
   Begin VB.CommandButton Command3 
      Caption         =   "TRUCK"
      Height          =   615
      Left            =   4200
      TabIndex        =   3
      Top             =   1320
      Width           =   1575
   End
   Begin VB.CommandButton Command2 
      Caption         =   "SHIPMENT"
      Height          =   615
      Left            =   2280
      TabIndex        =   2
      Top             =   1200
      Width           =   1575
   End
   Begin VB.CommandButton Command1 
      Caption         =   "CUSTOMER"
      Height          =   735
      Left            =   480
      TabIndex        =   1
      Top             =   1080
      Width           =   1455
   End
   Begin VB.Label Label1 
      Caption         =   "VIEW"
      Height          =   735
      Left            =   2040
      TabIndex        =   0
      Top             =   120
      Width           =   2295
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    Hide
    Form4.Show
    
End Sub

Private Sub Command2_Click()
    Hide
    Form5.Show
    
End Sub

Private Sub Command3_Click()
    Hide
    Form6.Show
    
End Sub

Private Sub Command4_Click()
    Hide
    Form7.Show
    
End Sub

Private Sub Command5_Click()
    Hide
    Form1.Show
    
End Sub
