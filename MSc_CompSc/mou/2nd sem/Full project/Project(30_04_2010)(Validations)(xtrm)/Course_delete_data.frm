VERSION 5.00
Begin VB.Form Form16 
   Caption         =   "Delete information of course database"
   ClientHeight    =   8490
   ClientLeft      =   165
   ClientTop       =   555
   ClientWidth     =   8100
   LinkTopic       =   "Form16"
   Picture         =   "Course_delete_data.frx":0000
   ScaleHeight     =   8490
   ScaleWidth      =   8100
   StartUpPosition =   3  'Windows Default
   WindowState     =   2  'Maximized
   Begin VB.TextBox Text1 
      Height          =   315
      Left            =   1920
      TabIndex        =   4
      Top             =   1800
      Width           =   2000
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Search"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   400
      Left            =   4440
      TabIndex        =   3
      Top             =   6840
      Width           =   1000
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Reset"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   400
      Left            =   2760
      TabIndex        =   2
      Top             =   6840
      Width           =   1000
   End
   Begin VB.CommandButton Command4 
      Caption         =   "Delete"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   400
      Left            =   6120
      TabIndex        =   1
      Top             =   6840
      Width           =   1000
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Home"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   400
      Left            =   1080
      TabIndex        =   0
      Top             =   6840
      Width           =   1000
   End
   Begin VB.Label Label10 
      BackColor       =   &H80000009&
      Caption         =   "   Course ID:-"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   405
      Left            =   360
      TabIndex        =   14
      Top             =   1800
      Width           =   1395
   End
   Begin VB.Label Label2 
      BackColor       =   &H80000009&
      Caption         =   "   Description:-"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   405
      Index           =   1
      Left            =   360
      TabIndex        =   13
      Top             =   4680
      Width           =   1395
   End
   Begin VB.Label Label3 
      BackColor       =   &H80000009&
      Caption         =   "    Fees:-"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   405
      Index           =   0
      Left            =   360
      TabIndex        =   12
      Top             =   3720
      Width           =   1395
   End
   Begin VB.Label Label2 
      BackColor       =   &H80000009&
      Caption         =   "     Title:-"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   405
      Index           =   0
      Left            =   360
      TabIndex        =   11
      Top             =   2760
      Width           =   1395
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      BackColor       =   &H80000009&
      Caption         =   "DELETE INFORMATION FROM COURSE DATABSE"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   975
      Left            =   600
      TabIndex        =   10
      Top             =   360
      Width           =   6975
   End
   Begin VB.Label Label4 
      Height          =   315
      Left            =   1920
      TabIndex        =   9
      Top             =   2760
      Width           =   6000
   End
   Begin VB.Label Label5 
      Height          =   315
      Left            =   1920
      TabIndex        =   8
      Top             =   3720
      Width           =   1995
   End
   Begin VB.Label Label6 
      Height          =   315
      Left            =   1920
      TabIndex        =   7
      Top             =   4680
      Width           =   6000
   End
   Begin VB.Label Label11 
      BackColor       =   &H80000009&
      Caption         =   "     Duration:-"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   405
      Left            =   360
      TabIndex        =   6
      Top             =   5640
      Width           =   1395
   End
   Begin VB.Label Label7 
      Height          =   315
      Left            =   1920
      TabIndex        =   5
      Top             =   5640
      Width           =   1695
   End
End
Attribute VB_Name = "Form16"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection
Dim rs As rdoResultset
Dim rs1 As rdoResultset
Dim rs2 As rdoResultset
Private Sub Command1_Click()
    Form14.Show
    Unload Me
End Sub
Private Sub Command2_Click()
    Text1.Text = ""
    Label4.Caption = ""
    Label5.Caption = ""
    Label6.Caption = ""
    Label7.Caption = ""
    Text1.SetFocus
End Sub

Private Sub Command3_Click()
    Dim N As Integer
    Dim i As Integer
    Dim TEMP As String
    Dim FLAG1 As Integer
    FLAG1 = 0
    Set rs2 = con.OpenResultset("SELECT COUNT(*) AS C FROM COURSE;", rdOpenStatic)
    N = rs2.rdoColumns("C")
    rs2.Close
    Set rs1 = con.OpenResultset("SELECT C_ID FROM COURSE;", rdOpenStatic)
    For i = 1 To N
        TEMP = rs1.rdoColumns("C_ID")
        If Text1.Text = TEMP Then
            FLAG1 = 1
        End If
        rs1.MoveNext
    Next i
    rs1.Close
    If Text1.Text = "" Then
        MsgBox ("Enter CourseID")
    ElseIf FLAG1 = 0 Then
        MsgBox ("CourseID provided is Absent")
    Else
        Set rs = con.OpenResultset("SELECT * FROM COURSE WHERE C_ID = '" + Text1.Text + "';", rdOpenStatic)
        Label4.Caption = rs.rdoColumns("C_TITLE")
        Label5.Caption = rs.rdoColumns("C_FEES")
        Label6.Caption = rs.rdoColumns("C_DESCRIPTION")
        Label7.Caption = rs.rdoColumns("C_DURATION")
        rs.Close
    End If
End Sub

Private Sub Command4_Click()
    If Text1.Text = "" Then
        MsgBox ("Enter ID")
    ElseIf Label4.Caption = "" Then
        MsgBox ("Click on SEARCH then on DELETE")
    Else
        Dim response
        response = MsgBox("Are you sure to remove the course?", vbYesNo)
        If response = vbYes Then
            Dim q As String
            q = "DELETE FROM COURSE Where C_ID = '" + Text1.Text + "';"
            con.Execute q
            MsgBox ("Course Removed successsfully")
            Text1.Text = ""
            Label4.Caption = ""
            Label5.Caption = ""
            Label6.Caption = ""
            Label7.Caption = ""
            Text1.SetFocus
        End If
    End If
End Sub

Private Sub Form_Load()
    con.Connect = "uid=scott;pwd=tiger;driver={Oracle in OraHome92}"
    con.EstablishConnection rdDriverNoPrompt
End Sub


Private Sub Form_Unload(Cancel As Integer)
    con.Close
End Sub


