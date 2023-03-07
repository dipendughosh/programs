VERSION 5.00
Begin VB.Form Form13 
   Caption         =   "Form13"
   ClientHeight    =   5040
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   7305
   LinkTopic       =   "Form13"
   ScaleHeight     =   5040
   ScaleWidth      =   7305
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command3 
      Caption         =   "BACK"
      Height          =   735
      Left            =   5640
      TabIndex        =   9
      Top             =   3120
      Width           =   975
   End
   Begin VB.CommandButton Command2 
      Caption         =   "PREVIOUS"
      Height          =   615
      Left            =   5640
      TabIndex        =   8
      Top             =   1920
      Width           =   975
   End
   Begin VB.CommandButton Command1 
      Caption         =   "NEXT"
      Height          =   735
      Left            =   5640
      TabIndex        =   7
      Top             =   840
      Width           =   975
   End
   Begin VB.Label Label10 
      Height          =   495
      Left            =   2280
      TabIndex        =   6
      Top             =   2160
      Width           =   2655
   End
   Begin VB.Label Label9 
      Height          =   495
      Left            =   2400
      TabIndex        =   5
      Top             =   1440
      Width           =   2415
   End
   Begin VB.Label Label8 
      Height          =   375
      Left            =   2520
      TabIndex        =   4
      Top             =   720
      Width           =   2175
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "CNAME"
      Height          =   195
      Left            =   480
      TabIndex        =   3
      Top             =   2280
      Width           =   570
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "CNO"
      Height          =   195
      Left            =   480
      TabIndex        =   2
      Top             =   1560
      Width           =   345
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "DNAME"
      Height          =   195
      Left            =   480
      TabIndex        =   1
      Top             =   720
      Width           =   585
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "COURSE"
      Height          =   195
      Left            =   2520
      TabIndex        =   0
      Top             =   0
      Width           =   675
   End
End
Attribute VB_Name = "Form13"
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
    Label10.Caption = rs.rdoColumns("CNAME")
End Sub


Private Sub Command2_Click()
    rs.MovePrevious
    If rs.BOF = True Then
        rs.MoveLast
    End If
    Label8.Caption = rs.rdoColumns("DNAME")
    Label9.Caption = rs.rdoColumns("CNO")
    Label10.Caption = rs.rdoColumns("CNAME")
End Sub

Private Sub Command3_Click()
    Hide
    Form9.Show
End Sub

Private Sub Form_Load()
    con.Connect = "uid=dipendu08;pwd=dipendu;Driver={Oracle in oracleHome9i}"
    con.EstablishConnection rdoDriverNoPrompt
    Set rs = con.OpenResultset("SELECT * FROM COURSE", rdOpenStatic)
    Label8.Caption = rs.rdoColumns("DNAME")
    Label9.Caption = rs.rdoColumns("CNO")
    Label10.Caption = rs.rdoColumns("CNAME")
End Sub

