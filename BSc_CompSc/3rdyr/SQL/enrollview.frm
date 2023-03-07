VERSION 5.00
Begin VB.Form Form10 
   Caption         =   "Form10"
   ClientHeight    =   5055
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8535
   LinkTopic       =   "Form10"
   ScaleHeight     =   5055
   ScaleWidth      =   8535
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command3 
      Caption         =   "BACK"
      Height          =   735
      Left            =   6360
      TabIndex        =   13
      Top             =   3120
      Width           =   975
   End
   Begin VB.CommandButton Command2 
      Caption         =   "PREVIOUS"
      Height          =   615
      Left            =   6360
      TabIndex        =   12
      Top             =   1920
      Width           =   975
   End
   Begin VB.CommandButton Command1 
      Caption         =   "NEXT"
      Height          =   735
      Left            =   6360
      TabIndex        =   11
      Top             =   840
      Width           =   975
   End
   Begin VB.Label Label12 
      Height          =   375
      Left            =   2880
      TabIndex        =   10
      Top             =   3720
      Width           =   3015
   End
   Begin VB.Label Label11 
      Height          =   495
      Left            =   2880
      TabIndex        =   9
      Top             =   2880
      Width           =   2895
   End
   Begin VB.Label Label10 
      Height          =   495
      Left            =   3000
      TabIndex        =   8
      Top             =   2160
      Width           =   2655
   End
   Begin VB.Label Label9 
      Height          =   495
      Left            =   3120
      TabIndex        =   7
      Top             =   1440
      Width           =   2415
   End
   Begin VB.Label Label8 
      Height          =   375
      Left            =   3240
      TabIndex        =   6
      Top             =   720
      Width           =   2175
   End
   Begin VB.Label Label6 
      AutoSize        =   -1  'True
      Caption         =   "GRADE"
      Height          =   195
      Left            =   1200
      TabIndex        =   5
      Top             =   3720
      Width           =   570
   End
   Begin VB.Label Label5 
      AutoSize        =   -1  'True
      Caption         =   "SECNO"
      Height          =   195
      Left            =   1200
      TabIndex        =   4
      Top             =   3120
      Width           =   555
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "CNO"
      Height          =   195
      Left            =   1200
      TabIndex        =   3
      Top             =   2280
      Width           =   345
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "DNAME"
      Height          =   195
      Left            =   1200
      TabIndex        =   2
      Top             =   1560
      Width           =   585
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "SID"
      Height          =   195
      Left            =   1200
      TabIndex        =   1
      Top             =   720
      Width           =   270
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "ENROLL"
      Height          =   195
      Left            =   3240
      TabIndex        =   0
      Top             =   0
      Width           =   645
   End
End
Attribute VB_Name = "Form10"
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
    Label8.Caption = rs.rdoColumns("SID")
    Label9.Caption = rs.rdoColumns("DNAME")
    Label10.Caption = rs.rdoColumns("CNO")
    Label11.Caption = rs.rdoColumns("SECNO")
    Label12.Caption = rs.rdoColumns("GRADE")
End Sub


Private Sub Command2_Click()
    rs.MovePrevious
    If rs.BOF = True Then
        rs.MoveLast
    End If
    Label8.Caption = rs.rdoColumns("SID")
    Label9.Caption = rs.rdoColumns("DNAME")
    Label10.Caption = rs.rdoColumns("CNO")
    Label11.Caption = rs.rdoColumns("SECNO")
    Label12.Caption = rs.rdoColumns("GRADE")
End Sub

Private Sub Command3_Click()
    Hide
    Form9.Show
End Sub

Private Sub Form_Load()
    con.Connect = "uid=dipendu08;pwd=dipendu;Driver={Oracle in oracleHome9i}"
    con.EstablishConnection rdoDriverNoPrompt
    Set rs = con.OpenResultset("SELECT * FROM ENROLL", rdOpenStatic)
    Label8.Caption = rs.rdoColumns("SID")
    Label9.Caption = rs.rdoColumns("DNAME")
    Label10.Caption = rs.rdoColumns("CNO")
    Label11.Caption = rs.rdoColumns("SECNO")
    Label12.Caption = rs.rdoColumns("GRADE")
End Sub

