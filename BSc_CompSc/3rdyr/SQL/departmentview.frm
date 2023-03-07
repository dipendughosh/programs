VERSION 5.00
Begin VB.Form Form15 
   Caption         =   "Form15"
   ClientHeight    =   5250
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   7035
   LinkTopic       =   "Form15"
   ScaleHeight     =   5250
   ScaleWidth      =   7035
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command3 
      Caption         =   "BACK"
      Height          =   735
      Left            =   5640
      TabIndex        =   7
      Top             =   3120
      Width           =   975
   End
   Begin VB.CommandButton Command2 
      Caption         =   "PREVIOUS"
      Height          =   615
      Left            =   5640
      TabIndex        =   6
      Top             =   1920
      Width           =   975
   End
   Begin VB.CommandButton Command1 
      Caption         =   "NEXT"
      Height          =   735
      Left            =   5640
      TabIndex        =   5
      Top             =   840
      Width           =   975
   End
   Begin VB.Label Label9 
      Height          =   495
      Left            =   2400
      TabIndex        =   4
      Top             =   1440
      Width           =   2415
   End
   Begin VB.Label Label8 
      Height          =   375
      Left            =   2520
      TabIndex        =   3
      Top             =   720
      Width           =   2175
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "NUMBER OF PHD'S"
      Height          =   195
      Left            =   480
      TabIndex        =   2
      Top             =   1560
      Width           =   1485
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
      Caption         =   "DEPARTMENT"
      Height          =   195
      Left            =   2520
      TabIndex        =   0
      Top             =   0
      Width           =   1125
   End
End
Attribute VB_Name = "Form15"
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
    Label9.Caption = rs.rdoColumns("NUMBER_OF_PHDS")
End Sub


Private Sub Command2_Click()
    rs.MovePrevious
    If rs.BOF = True Then
        rs.MoveLast
    End If
    Label8.Caption = rs.rdoColumns("DNAME")
    Label9.Caption = rs.rdoColumns("NUMBER_OF_PHDS")
End Sub

Private Sub Command3_Click()
    Hide
    Form9.Show
End Sub

Private Sub Form_Load()
    con.Connect = "uid=dipendu08;pwd=dipendu;Driver={Oracle in oracleHome9i}"
    con.EstablishConnection rdoDriverNoPrompt
    Set rs = con.OpenResultset("SELECT * FROM DEPARTMENT", rdOpenStatic)
    Label8.Caption = rs.rdoColumns("DNAME")
    Label9.Caption = rs.rdoColumns("NUMBER_OF_PHDS")
End Sub

