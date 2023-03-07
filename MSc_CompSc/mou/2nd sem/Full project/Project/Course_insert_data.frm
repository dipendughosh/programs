VERSION 5.00
Begin VB.Form Form7 
   Caption         =   "Insert information into course database"
   ClientHeight    =   8295
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8130
   LinkTopic       =   "Form7"
   ScaleHeight     =   8295
   ScaleWidth      =   8130
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox Text5 
      Height          =   315
      Left            =   1920
      TabIndex        =   13
      Top             =   1800
      Width           =   1575
   End
   Begin VB.TextBox Text4 
      Height          =   315
      Left            =   1920
      TabIndex        =   12
      Top             =   5640
      Width           =   1815
   End
   Begin VB.TextBox Text2 
      BeginProperty DataFormat 
         Type            =   1
         Format          =   "0"
         HaveTrueFalseNull=   0
         FirstDayOfWeek  =   0
         FirstWeekOfYear =   0
         LCID            =   1033
         SubFormatType   =   1
      EndProperty
      Height          =   315
      Left            =   1920
      TabIndex        =   5
      Top             =   3720
      Width           =   2000
   End
   Begin VB.TextBox Text1 
      Height          =   315
      Left            =   1920
      TabIndex        =   4
      Top             =   2760
      Width           =   6000
   End
   Begin VB.TextBox Text3 
      Height          =   315
      Left            =   1920
      TabIndex        =   3
      Top             =   4680
      Width           =   6000
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Reset"
      Height          =   400
      Left            =   3480
      TabIndex        =   2
      Top             =   7080
      Width           =   1000
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Insert"
      Height          =   400
      Left            =   5160
      TabIndex        =   1
      Top             =   7080
      Width           =   1000
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Home"
      Height          =   400
      Left            =   1800
      TabIndex        =   0
      Top             =   7080
      Width           =   1000
   End
   Begin VB.Label Label11 
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
      TabIndex        =   14
      Top             =   6360
      Width           =   60
   End
   Begin VB.Label Label4 
      Caption         =   "Duration:-"
      Height          =   405
      Left            =   240
      TabIndex        =   11
      Top             =   5640
      Width           =   1395
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Insert information into course database"
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
      TabIndex        =   10
      Top             =   480
      Width           =   6975
   End
   Begin VB.Label Label2 
      Caption         =   "Title:-"
      Height          =   405
      Index           =   0
      Left            =   240
      TabIndex        =   9
      Top             =   2760
      Width           =   1395
   End
   Begin VB.Label Label3 
      Caption         =   "Fees:-"
      Height          =   405
      Index           =   0
      Left            =   240
      TabIndex        =   8
      Top             =   3720
      Width           =   1395
   End
   Begin VB.Label Label2 
      Caption         =   "Description:-"
      Height          =   405
      Index           =   1
      Left            =   240
      TabIndex        =   7
      Top             =   4680
      Width           =   1395
   End
   Begin VB.Label Label10 
      Caption         =   "Course ID:-"
      Height          =   405
      Left            =   240
      TabIndex        =   6
      Top             =   1800
      Width           =   1395
   End
End
Attribute VB_Name = "Form7"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection
Private Sub Command1_Click()
    Form14.Show
    'Hide
    Unload Me
End Sub

Private Sub Command2_Click()
    Text1.Text = ""
    Text2.Text = ""
    Text3.Text = ""
    Text4.Text = ""
    Text5.Text = ""
    Text5.SetFocus
    Label11.Caption = ""
End Sub

Private Sub Command3_Click()
    Dim Q As String
    If Text5.Text = "" Or Text1.Text = "" Or Text2.Text = "" Or Text3.Text = "" Or Text4.Text = "" Then
        Label11.Caption = "SOME FIELDS ARE EMPTY"
    Else
        Label11.Caption = ""
        Q = "INSERT INTO COURSE(C_ID,C_TITLE,C_FEES,C_DESCRIPTION,C_DURATION) VALUES ('" + Text5.Text + "','" + Text1.Text + "'," + Text2.Text + ",'" + Text3.Text + "','" + Text4.Text + "');"
        con.Execute Q
        Text1.Text = ""
        Text2.Text = ""
        Text3.Text = ""
        Text4.Text = ""
        Text5.Text = ""
        Text5.SetFocus
    End If
End Sub

Private Sub Form_Load()
    con.Connect = "uid=admin;pwd=admin;driver={Oracle in OraHome92}"
    con.EstablishConnection rdDriverNoPrompt
    'Text1.SetFocus
End Sub

Private Sub Form_Unload(Cancel As Integer)
    con.Close
End Sub
