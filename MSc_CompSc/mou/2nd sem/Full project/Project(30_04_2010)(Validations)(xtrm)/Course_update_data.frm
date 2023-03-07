VERSION 5.00
Begin VB.Form Form8 
   Caption         =   "UPDATE COURSE DETAILS"
   ClientHeight    =   8490
   ClientLeft      =   165
   ClientTop       =   555
   ClientWidth     =   8100
   LinkTopic       =   "Form8"
   Picture         =   "Course_update_data.frx":0000
   ScaleHeight     =   8490
   ScaleWidth      =   8100
   StartUpPosition =   3  'Windows Default
   WindowState     =   2  'Maximized
   Begin VB.TextBox Text5 
      Height          =   315
      Left            =   1920
      TabIndex        =   14
      Top             =   5640
      Width           =   1815
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
      Left            =   1200
      TabIndex        =   12
      Top             =   6840
      Width           =   1000
   End
   Begin VB.CommandButton Command4 
      Caption         =   "Update"
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
      Left            =   6240
      TabIndex        =   11
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
      Left            =   2880
      TabIndex        =   10
      Top             =   6840
      Width           =   1000
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
      Left            =   4560
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
   Begin VB.TextBox Text3 
      BeginProperty DataFormat 
         Type            =   0
         Format          =   "0"
         HaveTrueFalseNull=   0
         FirstDayOfWeek  =   0
         FirstWeekOfYear =   0
         LCID            =   1033
         SubFormatType   =   0
      EndProperty
      Height          =   315
      Left            =   1920
      TabIndex        =   2
      Top             =   3720
      Width           =   2000
   End
   Begin VB.TextBox Text2 
      Height          =   315
      Left            =   1920
      TabIndex        =   1
      Top             =   2760
      Width           =   6000
   End
   Begin VB.TextBox Text4 
      Height          =   315
      Left            =   1920
      TabIndex        =   0
      Top             =   4680
      Width           =   6000
   End
   Begin VB.Label Label23 
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
      Left            =   2640
      TabIndex        =   15
      Top             =   6240
      Width           =   60
   End
   Begin VB.Label Label4 
      BackColor       =   &H80000009&
      Caption         =   "      Duration:-"
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
      Left            =   240
      TabIndex        =   13
      Top             =   5640
      Width           =   1395
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      BackColor       =   &H80000009&
      Caption         =   "UPDATE COURSE DETAILS"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   600
      TabIndex        =   7
      Top             =   480
      Width           =   6975
   End
   Begin VB.Label Label2 
      BackColor       =   &H80000009&
      Caption         =   "       Title:-"
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
      Left            =   240
      TabIndex        =   6
      Top             =   2760
      Width           =   1395
   End
   Begin VB.Label Label3 
      BackColor       =   &H80000009&
      Caption         =   "        Fees:-"
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
      Left            =   240
      TabIndex        =   5
      Top             =   3720
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
      Left            =   240
      TabIndex        =   4
      Top             =   4680
      Width           =   1395
   End
   Begin VB.Label Label10 
      BackColor       =   &H80000009&
      Caption         =   "    Course ID:-"
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
      Left            =   240
      TabIndex        =   3
      Top             =   1800
      Width           =   1395
   End
End
Attribute VB_Name = "Form8"
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
    Text2.Text = ""
    Text3.Text = ""
    Text4.Text = ""
    Text5.Text = ""
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
        Text2.Text = rs.rdoColumns("C_TITLE")
        Text3.Text = rs.rdoColumns("C_FEES")
        Text4.Text = rs.rdoColumns("C_DESCRIPTION")
        Text5.Text = rs.rdoColumns("C_DURATION")
        rs.Close
    End If
End Sub
Private Sub Command4_Click()
    Dim q As String
    Dim i As Integer
    Dim FLAGF As Integer
    FLAGF = 0
    If Len(Text3.Text) > 0 Then
        For i = 1 To Len(Text3.Text)
            X = Mid(Text3.Text, i, 1)
            If Not X Like "[0-9]" Then
                FLAGF = 1
            End If
        Next i
        If FLAGF = 1 Then
            MsgBox ("FEES has characters")
        End If
    End If
    If Text1.Text = "" Then
        MsgBox ("Enter ID")
    ElseIf Text2.Text = "" Then
        MsgBox ("Click on SEARCH then on UPDATE")
    ElseIf FLAGF = 0 Then
        q = "UPDATE COURSE SET C_TITLE = '" + Text2.Text + "',C_FEES = " + Text3.Text + ",C_DESCRIPTION = '" + Text4.Text + "',C_DURATION = '" + Text5.Text + "' WHERE C_ID = '" + Text1.Text + "';"
        con.Execute q
        MsgBox ("Successfully Updated into Database")
        Form14.Show
        Unload Me
    End If
End Sub
Private Sub Form_Load()
    con.Connect = "uid=scott;pwd=tiger;driver={Oracle in OraHome92}"
    con.EstablishConnection rdDriverNoPrompt
End Sub
Private Sub Form_Unload(Cancel As Integer)
    con.Close
End Sub

