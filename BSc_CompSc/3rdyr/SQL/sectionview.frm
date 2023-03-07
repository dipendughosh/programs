VERSION 5.00
Begin VB.Form Form11 
   Caption         =   "Form11"
   ClientHeight    =   5025
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   7320
   LinkTopic       =   "Form11"
   ScaleHeight     =   5025
   ScaleWidth      =   7320
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command3 
      Caption         =   "BACK"
      Height          =   735
      Left            =   5760
      TabIndex        =   11
      Top             =   3240
      Width           =   975
   End
   Begin VB.CommandButton Command2 
      Caption         =   "PREVIOUS"
      Height          =   615
      Left            =   5760
      TabIndex        =   10
      Top             =   2040
      Width           =   975
   End
   Begin VB.CommandButton Command1 
      Caption         =   "NEXT"
      Height          =   735
      Left            =   5760
      TabIndex        =   9
      Top             =   960
      Width           =   975
   End
   Begin VB.Label Label11 
      Height          =   495
      Left            =   2280
      TabIndex        =   8
      Top             =   3000
      Width           =   2895
   End
   Begin VB.Label Label10 
      Height          =   495
      Left            =   2400
      TabIndex        =   7
      Top             =   2280
      Width           =   2655
   End
   Begin VB.Label Label9 
      Height          =   495
      Left            =   2520
      TabIndex        =   6
      Top             =   1560
      Width           =   2415
   End
   Begin VB.Label Label8 
      Height          =   375
      Left            =   2640
      TabIndex        =   5
      Top             =   840
      Width           =   2175
   End
   Begin VB.Label Label5 
      AutoSize        =   -1  'True
      Caption         =   "PNAME"
      Height          =   195
      Left            =   600
      TabIndex        =   4
      Top             =   3240
      Width           =   570
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "SECNO"
      Height          =   195
      Left            =   600
      TabIndex        =   3
      Top             =   2400
      Width           =   555
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "CNO"
      Height          =   195
      Left            =   600
      TabIndex        =   2
      Top             =   1680
      Width           =   345
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "DNAME"
      Height          =   195
      Left            =   600
      TabIndex        =   1
      Top             =   840
      Width           =   585
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "SECTION"
      Height          =   195
      Left            =   2640
      TabIndex        =   0
      Top             =   120
      Width           =   705
   End
End
Attribute VB_Name = "Form11"
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
    Label8.Caption = rs.rdoColumns("DNAME")
    Label9.Caption = rs.rdoColumns("CNO")
    Label10.Caption = rs.rdoColumns("SECNO")
    Label11.Caption = rs.rdoColumns("PNAME")
End Sub


Private Sub Command2_Click()
    rs.MovePrevious
    If rs.BOF = True Then
        rs.MoveLast
    End If
    Label8.Caption = rs.rdoColumns("DNAME")
    Label9.Caption = rs.rdoColumns("CNO")
    Label10.Caption = rs.rdoColumns("SECNO")
    Label11.Caption = rs.rdoColumns("PNAME")
End Sub

Private Sub Command3_Click()
    Hide
    Form9.Show
End Sub

Private Sub Form_Load()
    con.Connect = "uid=dipendu08;pwd=dipendu;Driver={Oracle in oracleHome9i}"
    con.EstablishConnection rdoDriverNoPrompt
    Set rs = con.OpenResultset("SELECT * FROM SECTION", rdOpenStatic)
    Label8.Caption = rs.rdoColumns("DNAME")
    Label9.Caption = rs.rdoColumns("CNO")
    Label10.Caption = rs.rdoColumns("SECNO")
    Label11.Caption = rs.rdoColumns("PNAME")
End Sub

