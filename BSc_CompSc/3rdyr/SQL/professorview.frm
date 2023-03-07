VERSION 5.00
Begin VB.Form Form14 
   Caption         =   "Form14"
   ClientHeight    =   5220
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   7710
   LinkTopic       =   "Form14"
   ScaleHeight     =   5220
   ScaleWidth      =   7710
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command3 
      Caption         =   "BACK"
      Height          =   735
      Left            =   5880
      TabIndex        =   7
      Top             =   3360
      Width           =   975
   End
   Begin VB.CommandButton Command2 
      Caption         =   "PREVIOUS"
      Height          =   615
      Left            =   5880
      TabIndex        =   6
      Top             =   2160
      Width           =   975
   End
   Begin VB.CommandButton Command1 
      Caption         =   "NEXT"
      Height          =   735
      Left            =   5880
      TabIndex        =   5
      Top             =   1080
      Width           =   975
   End
   Begin VB.Label Label9 
      Height          =   495
      Left            =   2640
      TabIndex        =   4
      Top             =   1680
      Width           =   2415
   End
   Begin VB.Label Label8 
      Height          =   375
      Left            =   2760
      TabIndex        =   3
      Top             =   960
      Width           =   2175
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "DNAME"
      Height          =   195
      Left            =   720
      TabIndex        =   2
      Top             =   1800
      Width           =   585
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "PNAME"
      Height          =   195
      Left            =   720
      TabIndex        =   1
      Top             =   960
      Width           =   570
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "PROFESSOR"
      Height          =   195
      Left            =   2760
      TabIndex        =   0
      Top             =   240
      Width           =   990
   End
End
Attribute VB_Name = "Form14"
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
    Label8.Caption = rs.rdoColumns("PNAME")
    Label9.Caption = rs.rdoColumns("DNAME")
End Sub


Private Sub Command2_Click()
    rs.MovePrevious
    If rs.BOF = True Then
        rs.MoveLast
    End If
    Label8.Caption = rs.rdoColumns("PNAME")
    Label9.Caption = rs.rdoColumns("DNAME")
End Sub

Private Sub Command3_Click()
    Hide
    Form9.Show
End Sub

Private Sub Form_Load()
    con.Connect = "uid=dipendu08;pwd=dipendu;Driver={Oracle in oracleHome9i}"
    con.EstablishConnection rdoDriverNoPrompt
    Set rs = con.OpenResultset("SELECT * FROM PROFESSOR", rdOpenStatic)
    Label8.Caption = rs.rdoColumns("PNAME")
    Label9.Caption = rs.rdoColumns("DNAME")
End Sub

