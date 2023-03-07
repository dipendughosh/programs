VERSION 5.00
Begin VB.Form Form8 
   Caption         =   "Form8"
   ClientHeight    =   4860
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6765
   LinkTopic       =   "Form8"
   ScaleHeight     =   4860
   ScaleWidth      =   6765
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2 
      Caption         =   "BACK"
      Height          =   735
      Left            =   5520
      TabIndex        =   10
      Top             =   2520
      Width           =   975
   End
   Begin VB.CommandButton Command1 
      Caption         =   "ADD"
      Height          =   615
      Left            =   5280
      TabIndex        =   9
      Top             =   1080
      Width           =   1095
   End
   Begin VB.TextBox Text4 
      Height          =   615
      Left            =   3000
      TabIndex        =   8
      Top             =   3720
      Width           =   1695
   End
   Begin VB.TextBox Text3 
      Height          =   495
      Left            =   2880
      TabIndex        =   7
      Top             =   2760
      Width           =   1575
   End
   Begin VB.TextBox Text2 
      Height          =   495
      Left            =   2760
      TabIndex        =   6
      Top             =   2040
      Width           =   1935
   End
   Begin VB.TextBox Text1 
      Height          =   735
      Left            =   2760
      TabIndex        =   5
      Top             =   1080
      Width           =   1935
   End
   Begin VB.Label Label5 
      Caption         =   "CUSTOMER TYPE"
      Height          =   615
      Left            =   240
      TabIndex        =   4
      Top             =   3600
      Width           =   2415
   End
   Begin VB.Label Label4 
      Caption         =   "ANNUAL REVENUE"
      Height          =   615
      Left            =   240
      TabIndex        =   3
      Top             =   2640
      Width           =   2175
   End
   Begin VB.Label Label3 
      Caption         =   "CUST_NAME"
      Height          =   375
      Left            =   240
      TabIndex        =   2
      Top             =   2040
      Width           =   2175
   End
   Begin VB.Label Label2 
      Caption         =   "CUST_ID"
      Height          =   735
      Left            =   360
      TabIndex        =   1
      Top             =   1080
      Width           =   1695
   End
   Begin VB.Label Label1 
      Caption         =   "CUSTOMER"
      Height          =   615
      Left            =   2760
      TabIndex        =   0
      Top             =   120
      Width           =   1815
   End
End
Attribute VB_Name = "Form8"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim CON As New rdoConnection

Private Sub Command1_Click()
    Dim q As String
    q = "INSERT INTO CUSTOMER(CUST_ID,CUST_NAME,ANNUAL_REVENUE,CUST_TYPE) VALUES('" + Text1.Text + "','" + Text2.Text + "'," + Text3.Text + ",'" + Text4.Text + "');"
    CON.Execute q
    Text1.Text = ""
    Text2.Text = ""
    Text3.Text = ""
    Text4.Text = ""
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
