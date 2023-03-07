VERSION 5.00
Begin VB.Form Form12 
   Caption         =   "View result course wise"
   ClientHeight    =   7995
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8130
   LinkTopic       =   "Form12"
   ScaleHeight     =   7995
   ScaleWidth      =   8130
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2 
      Caption         =   "Print"
      Height          =   400
      Left            =   5280
      TabIndex        =   12
      Top             =   7440
      Width           =   1000
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Home"
      Height          =   400
      Left            =   2280
      TabIndex        =   11
      Top             =   7440
      Width           =   1000
   End
   Begin VB.ListBox List5 
      Height          =   5520
      Left            =   6720
      TabIndex        =   10
      Top             =   1680
      Width           =   975
   End
   Begin VB.ListBox List4 
      Height          =   5520
      Left            =   5520
      TabIndex        =   9
      Top             =   1680
      Width           =   735
   End
   Begin VB.ListBox List3 
      Height          =   5520
      Left            =   4200
      TabIndex        =   8
      Top             =   1680
      Width           =   855
   End
   Begin VB.ListBox List2 
      Height          =   5520
      Left            =   1560
      TabIndex        =   7
      Top             =   1680
      Width           =   2160
   End
   Begin VB.ListBox List1 
      Height          =   5520
      Left            =   240
      TabIndex        =   6
      Top             =   1680
      Width           =   885
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "View result course wise"
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
      TabIndex        =   5
      Top             =   360
      Width           =   6975
   End
   Begin VB.Label Label2 
      Caption         =   "Course Name:-"
      Height          =   405
      Index           =   0
      Left            =   1560
      TabIndex        =   4
      Top             =   1080
      Width           =   2085
   End
   Begin VB.Label Label3 
      Caption         =   "No. of Students:-"
      Height          =   405
      Index           =   0
      Left            =   4080
      TabIndex        =   3
      Top             =   1080
      Width           =   1005
   End
   Begin VB.Label Label2 
      Caption         =   "Highest Marks:-"
      Height          =   405
      Index           =   1
      Left            =   5520
      TabIndex        =   2
      Top             =   1080
      Width           =   765
   End
   Begin VB.Label Label9 
      Caption         =   "No. of Passed Students:-"
      Height          =   405
      Left            =   6720
      TabIndex        =   1
      Top             =   1080
      Width           =   1035
   End
   Begin VB.Label Label10 
      Caption         =   "Course ID:-"
      Height          =   405
      Left            =   240
      TabIndex        =   0
      Top             =   1080
      Width           =   885
   End
End
Attribute VB_Name = "Form12"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection
Dim rs As rdoResultset
Dim rs1 As rdoResultset
Dim rs2 As rdoResultset
Dim prnt(0 To 100) As String
Dim N As Integer
Private Sub Command1_Click()
    Form14.Show
    Unload Me
End Sub
Private Sub Command2_Click()
    Dim i As Integer
    Dim t As String
    i = 0
    Const ForAppending = 8
    Set objFSO = CreateObject("Scripting.FileSystemObject")
    Set objfile = objFSO.CreateTextFile("f:\result_course.txt")
    objfile.Close
    Set objTextFile = objFSO.OpenTextFile("f:\result_course.txt", ForAppending, True)
    objTextFile.WriteLine ("View result course wise")
    For i = 0 To N
        objTextFile.WriteLine (prnt(i))
    Next i
    objTextFile.Close
End Sub
Private Sub Form_Load()
    Dim t1 As String
    Dim t2 As String
    Dim t3 As String
    Dim t4 As String
    Dim t5 As String
    N = 1
    prnt(0) = "Course ID" + vbTab + "Course Title" + vbTab + "No. of Students" + vbTab + "Highest Marks" + vbTab + "No. of Passed Students"
    con.Connect = "uid=admin;pwd=admin;driver={Oracle in OraHome92}"
    con.EstablishConnection rdDriverNoPrompt
    Set rs = con.OpenResultset("SELECT R_C_ID,COUNT(*) AS C,MAX(R_MARKS) AS M FROM RESULT GROUP BY R_C_ID;", rdOpenStatic)
    While rs.EOF = False
        Set rs1 = con.OpenResultset("SELECT COUNT(*) AS A FROM RESULT WHERE R_MARKS > 40 GROUP BY R_C_ID;", rdOpenStatic)
        Set rs2 = con.OpenResultset("SELECT C_TITLE FROM COURSE WHERE C_ID = '" + rs.rdoColumns("R_C_ID") + "';", rdOpenStatic)
        List1.AddItem rs.rdoColumns("R_C_ID")
        List2.AddItem rs2.rdoColumns("C_TITLE")
        List3.AddItem rs.rdoColumns("C")
        List4.AddItem rs.rdoColumns("M")
        List5.AddItem rs1.rdoColumns("A")
        t1 = rs.rdoColumns("R_C_ID")
        t2 = rs2.rdoColumns("C_TITLE")
        t3 = rs.rdoColumns("C")
        t4 = rs.rdoColumns("M")
        t5 = rs1.rdoColumns("A")
        prnt(N) = t1 + vbTab + t2 + vbTab + t3 + vbTab + t4 + vbTab + t5
        rs1.Close
        rs2.Close
        rs.MoveNext
        N = N + 1
    Wend
    rs.Close
End Sub
Private Sub Form_Unload(Cancel As Integer)
    con.Close
End Sub

