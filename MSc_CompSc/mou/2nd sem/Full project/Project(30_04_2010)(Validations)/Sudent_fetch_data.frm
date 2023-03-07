VERSION 5.00
Begin VB.Form Form2 
   Caption         =   "Fetch student data from database"
   ClientHeight    =   8610
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   8100
   LinkTopic       =   "Form2"
   ScaleHeight     =   8610
   ScaleWidth      =   8100
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command4 
      Caption         =   "Search"
      Height          =   400
      Left            =   6120
      TabIndex        =   16
      Top             =   8160
      Width           =   1000
   End
   Begin VB.TextBox Text1 
      Height          =   315
      Left            =   2040
      TabIndex        =   15
      Top             =   1080
      Width           =   1695
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Reset"
      Height          =   400
      Left            =   2760
      TabIndex        =   2
      Top             =   8160
      Width           =   1000
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Update"
      Height          =   400
      Left            =   4440
      TabIndex        =   1
      Top             =   8160
      Width           =   1000
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Home"
      Height          =   400
      Left            =   1080
      TabIndex        =   0
      Top             =   8160
      Width           =   1000
   End
   Begin VB.Label Label28 
      Height          =   405
      Left            =   6000
      TabIndex        =   34
      Top             =   3960
      Width           =   1935
   End
   Begin VB.Label Label27 
      Height          =   405
      Left            =   1920
      TabIndex        =   33
      Top             =   3960
      Width           =   2055
   End
   Begin VB.Label Label26 
      Caption         =   "Police Station:-"
      Height          =   405
      Left            =   4440
      TabIndex        =   32
      Top             =   3960
      Width           =   1395
   End
   Begin VB.Label Label23 
      Caption         =   "State:-"
      Height          =   405
      Left            =   240
      TabIndex        =   31
      Top             =   3960
      Width           =   1395
   End
   Begin VB.Label Label25 
      Height          =   315
      Left            =   6000
      TabIndex        =   30
      Top             =   5400
      Width           =   1005
   End
   Begin VB.Label Label24 
      Caption         =   "Fees:-"
      Height          =   405
      Left            =   4440
      TabIndex        =   29
      Top             =   5400
      Width           =   1395
   End
   Begin VB.Label Label22 
      Caption         =   "Course Name:-"
      Height          =   405
      Left            =   3720
      TabIndex        =   28
      Top             =   7560
      Width           =   1395
   End
   Begin VB.Label Label21 
      Height          =   315
      Left            =   5280
      TabIndex        =   27
      Top             =   7560
      Width           =   2505
   End
   Begin VB.Label Label20 
      Height          =   315
      Left            =   1920
      TabIndex        =   26
      Top             =   7560
      Width           =   1605
   End
   Begin VB.Label Label19 
      Height          =   315
      Left            =   1920
      TabIndex        =   25
      Top             =   6840
      Width           =   6000
   End
   Begin VB.Label Label18 
      Height          =   315
      Left            =   1920
      TabIndex        =   24
      Top             =   6120
      Width           =   1500
   End
   Begin VB.Label Label17 
      Height          =   315
      Left            =   1920
      TabIndex        =   23
      Top             =   5400
      Width           =   1995
   End
   Begin VB.Label Label16 
      Height          =   315
      Left            =   6000
      TabIndex        =   22
      Top             =   4680
      Width           =   1005
   End
   Begin VB.Label Label15 
      Height          =   315
      Left            =   1920
      TabIndex        =   21
      Top             =   4680
      Width           =   1875
   End
   Begin VB.Label Label14 
      Height          =   315
      Left            =   6120
      TabIndex        =   20
      Top             =   3240
      Width           =   1875
   End
   Begin VB.Label Label13 
      Height          =   315
      Left            =   1920
      TabIndex        =   19
      Top             =   3240
      Width           =   1995
   End
   Begin VB.Label Label12 
      Height          =   315
      Left            =   1920
      TabIndex        =   18
      Top             =   2520
      Width           =   6000
   End
   Begin VB.Label Label11 
      Height          =   315
      Left            =   1920
      TabIndex        =   17
      Top             =   1800
      Width           =   6000
   End
   Begin VB.Label Label10 
      Caption         =   "Student ID:-"
      Height          =   405
      Left            =   240
      TabIndex        =   14
      Top             =   1080
      Width           =   1395
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "View information from student database"
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
      TabIndex        =   13
      Top             =   240
      Width           =   6975
   End
   Begin VB.Label Label2 
      Caption         =   "Name:-"
      Height          =   405
      Index           =   0
      Left            =   240
      TabIndex        =   12
      Top             =   1800
      Width           =   1395
   End
   Begin VB.Label Label3 
      Caption         =   "Address:-"
      Height          =   405
      Index           =   0
      Left            =   240
      TabIndex        =   11
      Top             =   2520
      Width           =   1395
   End
   Begin VB.Label Label2 
      Caption         =   "City:-"
      Height          =   405
      Index           =   1
      Left            =   240
      TabIndex        =   10
      Top             =   3240
      Width           =   1395
   End
   Begin VB.Label Label3 
      Caption         =   "Pin:-"
      Height          =   405
      Index           =   1
      Left            =   4440
      TabIndex        =   9
      Top             =   3240
      Width           =   1395
   End
   Begin VB.Label Label4 
      Caption         =   "Mobile No. :-"
      Height          =   405
      Left            =   240
      TabIndex        =   8
      Top             =   5400
      Width           =   1395
   End
   Begin VB.Label Label5 
      Caption         =   "Date of Birth (MM/DD/YYYY):-"
      Height          =   405
      Left            =   240
      TabIndex        =   7
      Top             =   4680
      Width           =   1395
   End
   Begin VB.Label Label6 
      Caption         =   "Age:-"
      Height          =   405
      Left            =   4440
      TabIndex        =   6
      Top             =   4680
      Width           =   1395
   End
   Begin VB.Label Label7 
      Caption         =   "Gender:-"
      Height          =   405
      Left            =   240
      TabIndex        =   5
      Top             =   6120
      Width           =   1395
   End
   Begin VB.Label Label8 
      Caption         =   "Father's Name:-"
      Height          =   405
      Left            =   240
      TabIndex        =   4
      Top             =   6840
      Width           =   1395
   End
   Begin VB.Label Label9 
      Caption         =   "Course ID:-"
      Height          =   405
      Left            =   240
      TabIndex        =   3
      Top             =   7560
      Width           =   1395
   End
End
Attribute VB_Name = "Form2"
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
    Label11.Caption = ""
    Label12.Caption = ""
    Label13.Caption = ""
    Label14.Caption = ""
    Label15.Caption = ""
    Label16.Caption = ""
    Label17.Caption = ""
    Label18.Caption = ""
    Label19.Caption = ""
    Label20.Caption = ""
    Label21.Caption = ""
    Label25.Caption = ""
    Label27.Caption = ""
    Label28.Caption = ""
    Text1.SetFocus
End Sub
Private Sub Command3_Click()
    If Text1.Text = "" Then
        MsgBox ("Enter ID")
    ElseIf Label11.Caption = "" Then
        MsgBox ("Click on SEARCH then on UPDATE")
    Else
        Form3.Show
        Hide
    End If
End Sub
Private Sub Command4_Click()
    Dim N As Integer
    Dim i As Integer
    Dim TEMP As String
    Dim FLAG1 As Integer
    FLAG1 = 0
    Set rs2 = con.OpenResultset("SELECT COUNT(*) AS C FROM STUDENT;", rdOpenStatic)
    N = rs2.rdoColumns("C")
    rs2.Close
    Set rs1 = con.OpenResultset("SELECT S_ID FROM STUDENT;", rdOpenStatic)
    For i = 1 To N
        TEMP = rs1.rdoColumns("S_ID")
        If Text1.Text = TEMP Then
            FLAG1 = 1
        End If
        rs1.MoveNext
    Next i
    rs1.Close
    If Text1.Text = "" Then
        MsgBox ("Enter StudentID")
    ElseIf FLAG1 = 0 Then
        MsgBox ("StudentID provided is Absent")
    Else
        Set rs = con.OpenResultset("SELECT * FROM STUDENT WHERE S_ID = '" + Text1.Text + "';", rdOpenStatic)
        Label11.Caption = rs.rdoColumns("S_NAME")
        Label12.Caption = rs.rdoColumns("S_ADDRESS")
        Label13.Caption = rs.rdoColumns("S_CITY")
        Label14.Caption = rs.rdoColumns("S_PIN")
        Label15.Caption = rs.rdoColumns("S_DOB")
        Label16.Caption = rs.rdoColumns("S_AGE")
        Label17.Caption = rs.rdoColumns("S_MOBILE")
        Label18.Caption = rs.rdoColumns("S_GENDER")
        Label19.Caption = rs.rdoColumns("S_FNAME")
        Label20.Caption = rs.rdoColumns("S_C_ID")
        Label25.Caption = rs.rdoColumns("S_FEES")
        Label27.Caption = rs.rdoColumns("S_STATE")
        Label28.Caption = rs.rdoColumns("S_POLICE")
        rs.Close
        Set rs1 = con.OpenResultset("SELECT * FROM COURSE WHERE C_ID = '" + Label20.Caption + "';", rdOpenStatic)
        Label21.Caption = rs1.rdoColumns("C_TITLE")
        rs1.Close
    End If
End Sub
Private Sub Form_Load()
    con.Connect = "uid=admin;pwd=admin;driver={Oracle in OraHome92}"
    con.EstablishConnection rdDriverNoPrompt
End Sub
Private Sub Form_Unload(Cancel As Integer)
    con.Close
End Sub

