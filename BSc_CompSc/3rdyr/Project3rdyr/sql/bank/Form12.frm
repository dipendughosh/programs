VERSION 5.00
Begin VB.Form Form12 
   Caption         =   "Form12"
   ClientHeight    =   4140
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4035
   LinkTopic       =   "Form12"
   ScaleHeight     =   4140
   ScaleWidth      =   4035
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command3 
      Caption         =   "Previous"
      Height          =   495
      Left            =   2880
      TabIndex        =   5
      Top             =   3000
      Width           =   855
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Go to Main Form"
      Height          =   495
      Left            =   1560
      TabIndex        =   4
      Top             =   3000
      Width           =   855
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Next"
      Height          =   495
      Left            =   360
      TabIndex        =   3
      Top             =   3000
      Width           =   855
   End
   Begin VB.Label Label5 
      Height          =   255
      Left            =   1560
      TabIndex        =   7
      Top             =   1080
      Width           =   2415
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "BORROWER TABLE"
      Height          =   195
      Left            =   1320
      TabIndex        =   6
      Top             =   240
      Width           =   1530
   End
   Begin VB.Label Label6 
      Height          =   255
      Left            =   1560
      TabIndex        =   2
      Top             =   2160
      Width           =   2415
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "Customer Name"
      Height          =   195
      Left            =   240
      TabIndex        =   1
      Top             =   1080
      Width           =   1125
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "Loan No"
      Height          =   195
      Left            =   240
      TabIndex        =   0
      Top             =   2160
      Width           =   615
   End
End
Attribute VB_Name = "Form12"
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
    Label5.Caption = rs.rdoColumns("CUSTOMER_NAME")
    Label6.Caption = rs.rdoColumns("LOAN_NO")
End Sub

Private Sub Command2_Click()
    Form14.Show
    Hide
End Sub

Private Sub Command3_Click()
    rs.MovePrevious
    If rs.BOF = True Then
        rs.MoveLast
    End If
    Label5.Caption = rs.rdoColumns("CUSTOMER_NAME")
    Label6.Caption = rs.rdoColumns("LOAN_NO")
End Sub
Private Sub Form_Load()
    con.Connect = "uid=dipendu;pwd=dipendu;driver={Oracle in OraDb10g_home1}"
    con.EstablishConnection rdDriverNoPrompt
    Set rs = con.OpenResultset("SELECT * FROM BORROWER", rdOpenStatic)
    Label5.Caption = rs.rdoColumns("CUSTOMER_NAME")
    Label6.Caption = rs.rdoColumns("LOAN_NO")
End Sub
Private Sub Form_Unload(Cancel As Integer)
    rs.Close
    con.Close
End Sub




