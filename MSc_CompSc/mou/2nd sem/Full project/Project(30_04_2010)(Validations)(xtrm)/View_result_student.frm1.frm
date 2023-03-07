VERSION 5.00
Begin VB.Form Form11 
   Caption         =   "View result student performance wise"
   ClientHeight    =   7995
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8130
   LinkTopic       =   "Form11"
   ScaleHeight     =   7995
   ScaleWidth      =   8130
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2 
      Caption         =   "Print"
      Height          =   400
      Left            =   5160
      TabIndex        =   14
      Top             =   7440
      Width           =   1000
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Home"
      Height          =   400
      Left            =   2160
      TabIndex        =   13
      Top             =   7440
      Width           =   1000
   End
   Begin VB.ListBox List6 
      Columns         =   10000
      Height          =   5520
      Left            =   6600
      TabIndex        =   12
      Top             =   1680
      Width           =   1455
   End
   Begin VB.ListBox List5 
      Columns         =   10000
      Height          =   5520
      Left            =   5520
      TabIndex        =   11
      Top             =   1680
      Width           =   975
   End
   Begin VB.ListBox List4 
      Columns         =   10000
      Height          =   5520
      Left            =   4680
      TabIndex        =   10
      Top             =   1680
      Width           =   735
   End
   Begin VB.ListBox List3 
      Columns         =   10000
      Height          =   5520
      Left            =   3720
      TabIndex        =   9
      Top             =   1680
      Width           =   855
   End
   Begin VB.ListBox List2 
      Columns         =   10000
      Height          =   5520
      Left            =   1200
      TabIndex        =   8
      Top             =   1680
      Width           =   2400
   End
   Begin VB.ListBox List1 
      Columns         =   10000
      Height          =   5520
      Left            =   120
      TabIndex        =   7
      Top             =   1680
      Width           =   885
   End
   Begin VB.Label Label4 
      Caption         =   "Course Name:-"
      Height          =   405
      Left            =   6600
      TabIndex        =   6
      Top             =   1080
      Width           =   1365
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "View result student performance wise"
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
      Caption         =   "Name:-"
      Height          =   405
      Index           =   0
      Left            =   1200
      TabIndex        =   4
      Top             =   1080
      Width           =   2325
   End
   Begin VB.Label Label3 
      Caption         =   "Marks:-"
      Height          =   405
      Index           =   0
      Left            =   3720
      TabIndex        =   3
      Top             =   1080
      Width           =   765
   End
   Begin VB.Label Label2 
      Caption         =   "Grade:-"
      Height          =   405
      Index           =   1
      Left            =   4680
      TabIndex        =   2
      Top             =   1080
      Width           =   645
   End
   Begin VB.Label Label9 
      Caption         =   "Course ID:-"
      Height          =   405
      Left            =   5520
      TabIndex        =   1
      Top             =   1080
      Width           =   885
   End
   Begin VB.Label Label10 
      Caption         =   "Student ID:-"
      Height          =   405
      Left            =   120
      TabIndex        =   0
      Top             =   1080
      Width           =   885
   End
End
Attribute VB_Name = "Form11"
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
    i = 0
    Const ForAppending = 8
    Set objFSO = CreateObject("Scripting.FileSystemObject")
    Set objfile = objFSO.CreateTextFile("c:\result_student.txt")
    objfile.Close
    Set objTextFile = objFSO.OpenTextFile("c:\result_student.txt", ForAppending, True)
    objTextFile.WriteLine ("View result student performance wise")
    For i = 0 To N
        objTextFile.WriteLine (prnt(i))
    Next i
    objTextFile.Close
End Sub

Private Sub Form_Load()
    Dim m As Integer
    Dim i As Integer
    Dim t1 As String
    Dim t2 As String
    Dim t3 As String
    Dim t4 As String
    Dim t5 As String
    Dim t6 As String
    N = 1
    prnt(0) = "Student ID" + vbTab + "Student Name" + vbTab + "Marks" + vbTab + "Grade" + vbTab + "Course ID" + vbTab + "Course Title"
    con.Connect = "uid=scott;pwd=tiger;driver={Oracle in OraHome92}"
    con.EstablishConnection rdDriverNoPrompt
    Set rs = con.OpenResultset("SELECT COUNT(*) AS C FROM RESULT;", rdOpenStatic)
    m = rs.rdoColumns("C")
    rs.Close
    Set rs1 = con.OpenResultset("SELECT * FROM RESULT;", rdOpenStatic)
    For i = 1 To m
        Set rs2 = con.OpenResultset("SELECT * FROM COURSE WHERE C_ID = '" + rs1.rdoColumns("R_C_ID") + "';", rdOpenStatic)
        List1.AddItem rs1.rdoColumns("R_S_ID")
        List2.AddItem rs1.rdoColumns("R_S_NAME")
        List3.AddItem rs1.rdoColumns("R_MARKS")
        List4.AddItem rs1.rdoColumns("R_GRADE")
        List5.AddItem rs1.rdoColumns("R_C_ID")
        List6.AddItem rs2.rdoColumns("C_TITLE")
        t1 = rs1.rdoColumns("R_S_ID")
        t2 = rs1.rdoColumns("R_S_NAME")
        t3 = rs1.rdoColumns("R_MARKS")
        t4 = rs1.rdoColumns("R_GRADE")
        t5 = rs1.rdoColumns("R_C_ID")
        t6 = rs2.rdoColumns("C_TITLE")
        prnt(N) = t1 + vbTab + t2 + vbTab + t3 + vbTab + t4 + vbTab + t5 + vbTab + t6
        rs2.Close
        rs1.MoveNext
        N = N + 1
    Next i
    rs1.Close
End Sub

Private Sub Form_Unload(Cancel As Integer)
    con.Close
End Sub

Private Sub List7_Click()

End Sub
