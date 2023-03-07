VERSION 5.00
Begin VB.Form Form4 
   Caption         =   "Form4"
   ClientHeight    =   4665
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   5925
   LinkTopic       =   "Form4"
   ScaleHeight     =   4665
   ScaleWidth      =   5925
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command3 
      Caption         =   "back"
      Height          =   615
      Left            =   4680
      TabIndex        =   11
      Top             =   2760
      Width           =   1095
   End
   Begin VB.CommandButton Command2 
      Caption         =   "previous"
      Height          =   495
      Left            =   4680
      TabIndex        =   10
      Top             =   2040
      Width           =   975
   End
   Begin VB.CommandButton Command1 
      Caption         =   "next"
      Height          =   615
      Left            =   4680
      TabIndex        =   9
      Top             =   1200
      Width           =   975
   End
   Begin VB.Label Label9 
      Height          =   495
      Left            =   2880
      TabIndex        =   8
      Top             =   3600
      Width           =   1455
   End
   Begin VB.Label Label8 
      Height          =   495
      Left            =   2760
      TabIndex        =   7
      Top             =   2760
      Width           =   1695
   End
   Begin VB.Label Label7 
      Height          =   375
      Left            =   2640
      TabIndex        =   6
      Top             =   2040
      Width           =   1575
   End
   Begin VB.Label Label6 
      Height          =   615
      Left            =   2520
      TabIndex        =   5
      Top             =   1080
      Width           =   1695
   End
   Begin VB.Label Label1 
      Caption         =   "CUSTOMER"
      Height          =   615
      Left            =   2760
      TabIndex        =   4
      Top             =   120
      Width           =   1815
   End
   Begin VB.Label Label2 
      Caption         =   "CUST_ID"
      Height          =   735
      Left            =   360
      TabIndex        =   3
      Top             =   1080
      Width           =   1695
   End
   Begin VB.Label Label3 
      Caption         =   "CUST_NAME"
      Height          =   375
      Left            =   240
      TabIndex        =   2
      Top             =   2040
      Width           =   2175
   End
   Begin VB.Label Label4 
      Caption         =   "ANNUAL REVENUE"
      Height          =   615
      Left            =   240
      TabIndex        =   1
      Top             =   2640
      Width           =   2175
   End
   Begin VB.Label Label5 
      Caption         =   "CUSTOMER TYPE"
      Height          =   615
      Left            =   240
      TabIndex        =   0
      Top             =   3600
      Width           =   2415
   End
End
Attribute VB_Name = "Form4"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection
Dim rs As rdoResultset

Private Sub Command1_Click()
    rs.MoveNext
    If rs.EOF = True Then
        rs.MoveFirst
    End If
    Label6.Caption = rs.rdoColumns("CUST_ID")
    Label7.Caption = rs.rdoColumns("CUST_NAME")
    Label8.Caption = rs.rdoColumns("ANNUAL_REVENUE")
    Label9.Caption = rs.rdoColumns("CUST_TYPE")
End Sub

Private Sub Command2_Click()
    rs.MovePrevious
    If rs.BOF = True Then
        rs.MoveLast
    End If
    Label6.Caption = rs.rdoColumns("CUST_ID")
    Label7.Caption = rs.rdoColumns("CUST_NAME")
    Label8.Caption = rs.rdoColumns("ANNUAL_REVENUE")
    Label9.Caption = rs.rdoColumns("CUST_TYPE")
End Sub

Private Sub Command3_Click()
    Hide
    Form3.Show
    
    
End Sub

Private Sub Form_Load()
    con.Connect = "uid=dipendu06;pwd=dipendu;Driver={Oracle in oracleHome9i}"
    con.EstablishConnection rdoDriverNoPrompt
    Set rs = con.OpenResultset("select * from customer", rdOpenStatic)
    Label6.Caption = rs.rdoColumns("CUST_ID")
    Label7.Caption = rs.rdoColumns("CUST_NAME")
    Label8.Caption = rs.rdoColumns("ANNUAL_REVENUE")
    Label9.Caption = rs.rdoColumns("CUST_TYPE")
    
    
    
End Sub

Private Sub Form_Unload(Cancel As Integer)
    rs.Close
    con.Close

    
End Sub
