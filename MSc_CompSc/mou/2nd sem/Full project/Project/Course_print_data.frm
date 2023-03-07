VERSION 5.00
Begin VB.Form Form9 
   Caption         =   "Print information of course database"
   ClientHeight    =   7995
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8130
   LinkTopic       =   "Form9"
   ScaleHeight     =   7995
   ScaleWidth      =   8130
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "Home"
      Height          =   400
      Left            =   1080
      TabIndex        =   12
      Top             =   6840
      Width           =   1000
   End
   Begin VB.CommandButton Command4 
      Caption         =   "Print"
      Height          =   400
      Left            =   6120
      TabIndex        =   11
      Top             =   6840
      Width           =   1000
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Reset"
      Height          =   400
      Left            =   2760
      TabIndex        =   10
      Top             =   6840
      Width           =   1000
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Search"
      Height          =   400
      Left            =   4440
      TabIndex        =   9
      Top             =   6840
      Width           =   1000
   End
   Begin VB.TextBox Text1 
      Height          =   315
      Left            =   1920
      TabIndex        =   8
      Top             =   1800
      Width           =   2000
   End
   Begin VB.Label Label8 
      AutoSize        =   -1  'True
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000080&
      Height          =   300
      Left            =   2520
      TabIndex        =   15
      Top             =   6360
      Width           =   60
   End
   Begin VB.Label Label7 
      Height          =   315
      Left            =   1920
      TabIndex        =   14
      Top             =   5640
      Width           =   1695
   End
   Begin VB.Label Label11 
      Caption         =   "Duration:-"
      Height          =   405
      Left            =   240
      TabIndex        =   13
      Top             =   5640
      Width           =   1395
   End
   Begin VB.Label Label6 
      Height          =   315
      Left            =   1920
      TabIndex        =   7
      Top             =   4680
      Width           =   6000
   End
   Begin VB.Label Label5 
      Height          =   315
      Left            =   1920
      TabIndex        =   6
      Top             =   3720
      Width           =   1995
   End
   Begin VB.Label Label4 
      Height          =   315
      Left            =   1920
      TabIndex        =   5
      Top             =   2760
      Width           =   6000
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Print information of course database"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   600
      TabIndex        =   4
      Top             =   480
      Width           =   6975
   End
   Begin VB.Label Label2 
      Caption         =   "Title:-"
      Height          =   405
      Index           =   0
      Left            =   240
      TabIndex        =   3
      Top             =   2760
      Width           =   1395
   End
   Begin VB.Label Label3 
      Caption         =   "Fees:-"
      Height          =   405
      Index           =   0
      Left            =   240
      TabIndex        =   2
      Top             =   3720
      Width           =   1395
   End
   Begin VB.Label Label2 
      Caption         =   "Description:-"
      Height          =   405
      Index           =   1
      Left            =   240
      TabIndex        =   1
      Top             =   4680
      Width           =   1395
   End
   Begin VB.Label Label10 
      Caption         =   "Course ID:-"
      Height          =   405
      Left            =   240
      TabIndex        =   0
      Top             =   1800
      Width           =   1395
   End
End
Attribute VB_Name = "Form9"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection
Dim rs As rdoResultset
Private Sub Command1_Click()
    Form14.Show
    'Hide
    Unload Me
End Sub

Private Sub Command2_Click()
    Text1.Text = ""
    Label4.Caption = ""
    Label5.Caption = ""
    Label6.Caption = ""
    Label7.Caption = ""
    Text1.SetFocus
    Label8.Caption = ""
End Sub

Private Sub Command3_Click()
    If Text1.Text = "" Then
        Label8.Caption = "SOME FIELDS ARE EMPTY"
    Else
        Label8.Caption = ""
        Set rs = con.OpenResultset("SELECT * FROM COURSE WHERE C_ID = '" + Text1.Text + "';", rdOpenStatic)
        Label4.Caption = rs.rdoColumns("C_TITLE")
        Label5.Caption = rs.rdoColumns("C_FEES")
        Label6.Caption = rs.rdoColumns("C_DESCRIPTION")
        Label7.Caption = rs.rdoColumns("C_DURATION")
    End If
End Sub

Private Sub Form_Load()
    con.Connect = "uid=admin;pwd=admin;driver={Oracle in OraHome92}"
    con.EstablishConnection rdDriverNoPrompt
    'Text1.SetFocus
End Sub


Private Sub Form_Unload(Cancel As Integer)
    rs.Close
    con.Close
End Sub

