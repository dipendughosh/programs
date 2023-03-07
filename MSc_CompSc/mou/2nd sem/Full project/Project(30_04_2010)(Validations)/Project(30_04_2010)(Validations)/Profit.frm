VERSION 5.00
Begin VB.Form Form13 
   Caption         =   "Profit"
   ClientHeight    =   8490
   ClientLeft      =   165
   ClientTop       =   555
   ClientWidth     =   8100
   LinkTopic       =   "Form13"
   Picture         =   "Profit.frx":0000
   ScaleHeight     =   8490
   ScaleWidth      =   8100
   StartUpPosition =   3  'Windows Default
   WindowState     =   2  'Maximized
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
      Left            =   2040
      TabIndex        =   1
      Top             =   6480
      Width           =   1000
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Print"
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
      Left            =   5040
      TabIndex        =   0
      Top             =   6480
      Width           =   1000
   End
   Begin VB.Label Label5 
      Height          =   405
      Left            =   4080
      TabIndex        =   8
      Top             =   2520
      Width           =   1995
   End
   Begin VB.Label Label10 
      BackColor       =   &H80000014&
      Caption         =   "        Total Gain:-"
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
      Left            =   1200
      TabIndex        =   7
      Top             =   2520
      Width           =   1995
   End
   Begin VB.Label Label9 
      Height          =   405
      Left            =   4080
      TabIndex        =   6
      Top             =   3600
      Width           =   1995
   End
   Begin VB.Label Label3 
      BackColor       =   &H80000014&
      Caption         =   "      Profit Amount:-"
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
      Left            =   1200
      TabIndex        =   5
      Top             =   4680
      Width           =   1995
   End
   Begin VB.Label Label2 
      BackColor       =   &H80000014&
      Caption         =   "       Total Paid:-"
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
      Left            =   1200
      TabIndex        =   4
      Top             =   3600
      Width           =   1995
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      BackColor       =   &H80000014&
      Caption         =   "PROFIT"
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
      TabIndex        =   3
      Top             =   480
      Width           =   6975
   End
   Begin VB.Label Label4 
      Height          =   405
      Left            =   4080
      TabIndex        =   2
      Top             =   4680
      Width           =   1995
   End
End
Attribute VB_Name = "Form13"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection
Dim rs1 As rdoResultset
Dim rs2 As rdoResultset
Dim prnt As String
Private Sub Command1_Click()
    Form14.Show
    Unload Me
End Sub

Private Sub Command2_Click()
    Const ForAppending = 8
    Set objFSO = CreateObject("Scripting.FileSystemObject")
    Set objfile = objFSO.CreateTextFile("c:\profit.txt")
    objfile.Close
    Set objTextFile = objFSO.OpenTextFile("c:\profit.txt", ForAppending, True)
    objTextFile.WriteLine (prnt)
    objTextFile.Close
End Sub

Private Sub Form_Load()
    con.Connect = "uid=scott;pwd=tiger;driver={Oracle in OraHome92}"
    con.EstablishConnection rdDriverNoPrompt
    Set rs1 = con.OpenResultset("SELECT SUM(S_FEES) AS A FROM STUDENT;", rdOpenStatic)
    Set rs2 = con.OpenResultset("SELECT SUM(I_SALARY) AS B FROM INSTRUCTOR;", rdOpenStatic)
    Label5.Caption = rs1.rdoColumns("A")
    Label9.Caption = rs2.rdoColumns("B")
    Label4.Caption = Label5.Caption - Label9.Caption
    Dim q As String
    q = "INSERT INTO PROFIT(TOTAL_GAIN,TOTAL_PAID,TOTAL_AMOUNT) VALUES (" + Label5.Caption + "," + Label9.Caption + "," + Label4.Caption + ");"
    con.Execute q
    prnt = "            Profit Details" + vbCrLf + "Total Gain : " + Label5.Caption + vbCrLf + "Total Paid : " + Label9.Caption + vbCrLf + "Profit Amount : " + Label9.Caption
End Sub

Private Sub Form_Unload(Cancel As Integer)
    rs1.Close
    rs2.Close
    con.Close
End Sub

