VERSION 5.00
Begin VB.Form Form16 
   Caption         =   "Form16"
   ClientHeight    =   5055
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6690
   LinkTopic       =   "Form16"
   ScaleHeight     =   5055
   ScaleWidth      =   6690
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command3 
      Caption         =   "BACK"
      Height          =   735
      Left            =   5520
      TabIndex        =   15
      Top             =   3240
      Width           =   975
   End
   Begin VB.CommandButton Command2 
      Caption         =   "PREVIOUS"
      Height          =   615
      Left            =   5520
      TabIndex        =   14
      Top             =   2040
      Width           =   975
   End
   Begin VB.CommandButton Command1 
      Caption         =   "NEXT"
      Height          =   735
      Left            =   5520
      TabIndex        =   13
      Top             =   960
      Width           =   975
   End
   Begin VB.Label Label13 
      Height          =   375
      Left            =   1920
      TabIndex        =   12
      Top             =   4440
      Width           =   3135
   End
   Begin VB.Label Label12 
      Height          =   375
      Left            =   2040
      TabIndex        =   11
      Top             =   3840
      Width           =   3015
   End
   Begin VB.Label Label11 
      Height          =   495
      Left            =   2040
      TabIndex        =   10
      Top             =   3000
      Width           =   2895
   End
   Begin VB.Label Label10 
      Height          =   495
      Left            =   2160
      TabIndex        =   9
      Top             =   2280
      Width           =   2655
   End
   Begin VB.Label Label9 
      Height          =   495
      Left            =   2280
      TabIndex        =   8
      Top             =   1560
      Width           =   2415
   End
   Begin VB.Label Label8 
      Height          =   375
      Left            =   2400
      TabIndex        =   7
      Top             =   840
      Width           =   2175
   End
   Begin VB.Label Label7 
      AutoSize        =   -1  'True
      Caption         =   "GPA"
      Height          =   195
      Left            =   360
      TabIndex        =   6
      Top             =   4440
      Width           =   330
   End
   Begin VB.Label Label6 
      AutoSize        =   -1  'True
      Caption         =   "YEAR"
      Height          =   195
      Left            =   360
      TabIndex        =   5
      Top             =   3840
      Width           =   435
   End
   Begin VB.Label Label5 
      AutoSize        =   -1  'True
      Caption         =   "AGE"
      Height          =   195
      Left            =   360
      TabIndex        =   4
      Top             =   3240
      Width           =   330
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "SEX"
      Height          =   195
      Left            =   360
      TabIndex        =   3
      Top             =   2400
      Width           =   315
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "SNAME"
      Height          =   195
      Left            =   360
      TabIndex        =   2
      Top             =   1680
      Width           =   570
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "SID"
      Height          =   195
      Left            =   360
      TabIndex        =   1
      Top             =   840
      Width           =   270
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "STUDENT"
      Height          =   195
      Left            =   2400
      TabIndex        =   0
      Top             =   120
      Width           =   780
   End
End
Attribute VB_Name = "Form16"
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
    Label9.Caption = rs.rdoColumns("SNAME")
    Label10.Caption = rs.rdoColumns("SEX")
    Label11.Caption = rs.rdoColumns("AGE")
    Label12.Caption = rs.rdoColumns("YEAR")
    Label13.Caption = rs.rdoColumns("GPA")
End Sub


Private Sub Command2_Click()
    rs.MovePrevious
    If rs.BOF = True Then
        rs.MoveLast
    End If
    Label8.Caption = rs.rdoColumns("SID")
    Label9.Caption = rs.rdoColumns("SNAME")
    Label10.Caption = rs.rdoColumns("SEX")
    Label11.Caption = rs.rdoColumns("AGE")
    Label12.Caption = rs.rdoColumns("YEAR")
    Label13.Caption = rs.rdoColumns("GPA")
End Sub

Private Sub Command3_Click()
    Hide
    Form9.Show
End Sub

Private Sub Form_Load()
    con.Connect = "uid=dipendu08;pwd=dipendu;Driver={Oracle in oracleHome9i}"
    con.EstablishConnection rdoDriverNoPrompt
    Set rs = con.OpenResultset("SELECT * FROM STUDENT", rdOpenStatic)
    Label8.Caption = rs.rdoColumns("SID")
    Label9.Caption = rs.rdoColumns("SNAME")
    Label10.Caption = rs.rdoColumns("SEX")
    Label11.Caption = rs.rdoColumns("AGE")
    Label12.Caption = rs.rdoColumns("YEAR")
    Label13.Caption = rs.rdoColumns("GPA")
End Sub
