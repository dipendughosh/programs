VERSION 5.00
Begin VB.Form Form11 
   Caption         =   "Form11"
   ClientHeight    =   4230
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4065
   LinkTopic       =   "Form11"
   ScaleHeight     =   4230
   ScaleWidth      =   4065
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command3 
      Caption         =   "Previous"
      Height          =   495
      Left            =   2880
      TabIndex        =   5
      Top             =   3120
      Width           =   855
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Go to Main Form"
      Height          =   495
      Left            =   1560
      TabIndex        =   4
      Top             =   3120
      Width           =   855
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Next"
      Height          =   495
      Left            =   360
      TabIndex        =   3
      Top             =   3120
      Width           =   855
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "ACCOUNT TABLE"
      Height          =   195
      Left            =   1440
      TabIndex        =   9
      Top             =   240
      Width           =   1335
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "Branch Name"
      Height          =   195
      Left            =   360
      TabIndex        =   8
      Top             =   720
      Width           =   975
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "Account No"
      Height          =   195
      Left            =   360
      TabIndex        =   7
      Top             =   1560
      Width           =   855
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "Balance"
      Height          =   195
      Left            =   360
      TabIndex        =   6
      Top             =   2400
      Width           =   585
   End
   Begin VB.Label Label7 
      Height          =   255
      Left            =   1560
      TabIndex        =   2
      Top             =   2400
      Width           =   2415
   End
   Begin VB.Label Label6 
      Height          =   255
      Left            =   1560
      TabIndex        =   1
      Top             =   1560
      Width           =   2415
   End
   Begin VB.Label Label5 
      Height          =   255
      Left            =   1560
      TabIndex        =   0
      Top             =   720
      Width           =   2415
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
    Label5.Caption = rs.rdoColumns("BRANCH_NAME")
    Label6.Caption = rs.rdoColumns("ACCOUNT_NO")
    Label7.Caption = rs.rdoColumns("BALANCE")
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
    Label5.Caption = rs.rdoColumns("BRANCH_NAME")
    Label6.Caption = rs.rdoColumns("ACCOUNT_NO")
    Label7.Caption = rs.rdoColumns("BALANCE")
End Sub
Private Sub Form_Load()
    con.Connect = "uid=dipendu;pwd=dipendu;driver={Oracle in OraDb10g_home1}"
    con.EstablishConnection rdDriverNoPrompt
    Set rs = con.OpenResultset("SELECT * FROM ACCOUNT", rdOpenStatic)
    Label5.Caption = rs.rdoColumns("BRANCH_NAME")
    Label6.Caption = rs.rdoColumns("ACCOUNT_NO")
    Label7.Caption = rs.rdoColumns("BALANCE")
End Sub
Private Sub Form_Unload(Cancel As Integer)
    rs.Close
    con.Close
End Sub



