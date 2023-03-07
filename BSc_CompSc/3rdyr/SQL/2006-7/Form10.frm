VERSION 5.00
Begin VB.Form Form10 
   Caption         =   "Form10"
   ClientHeight    =   6285
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   7515
   LinkTopic       =   "Form10"
   ScaleHeight     =   6285
   ScaleWidth      =   7515
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2 
      Caption         =   "BACK"
      Height          =   735
      Left            =   5520
      TabIndex        =   6
      Top             =   3120
      Width           =   975
   End
   Begin VB.CommandButton Command1 
      Caption         =   "ADD"
      Height          =   615
      Left            =   5280
      TabIndex        =   5
      Top             =   1680
      Width           =   1095
   End
   Begin VB.TextBox Text2 
      Height          =   495
      Left            =   2760
      TabIndex        =   4
      Top             =   2640
      Width           =   1935
   End
   Begin VB.TextBox Text1 
      Height          =   735
      Left            =   2760
      TabIndex        =   3
      Top             =   1680
      Width           =   1935
   End
   Begin VB.Label Label1 
      Caption         =   "TRUCK"
      Height          =   615
      Left            =   2760
      TabIndex        =   2
      Top             =   720
      Width           =   1815
   End
   Begin VB.Label Label2 
      Caption         =   "TRUCK_NO"
      Height          =   735
      Left            =   360
      TabIndex        =   1
      Top             =   1680
      Width           =   1695
   End
   Begin VB.Label Label3 
      Caption         =   "DRIVER_NAME"
      Height          =   375
      Left            =   240
      TabIndex        =   0
      Top             =   2640
      Width           =   2175
   End
End
Attribute VB_Name = "Form10"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim CON As New rdoConnection

Private Sub Command1_Click()
    Dim q As String
    q = "INSERT INTO TRUCK(TRUCK_NO,DRIVER_NAME) VALUES('" + Text1.Text + "','" + Text2.Text + "');"
    CON.Execute q
    Text1.Text = ""
    Text2.Text = ""
    Text1.SetFocus
    
    
End Sub

Private Sub Command2_Click()
    Hide
    Form3.Show
    
End Sub

Private Sub Form_Load()
    CON.Connect = "uid=dipendu06;pwd=dipendu;Driver={Oracle in oracleHome9i}"
    CON.EstablishConnection rdoDriverNoPrompt
    
End Sub

Private Sub Form_Unload(Cancel As Integer)
    CON.Close
    
End Sub


