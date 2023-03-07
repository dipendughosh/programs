VERSION 5.00
Begin VB.Form Form13 
   Caption         =   "Profit"
   ClientHeight    =   8610
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8100
   LinkTopic       =   "Form13"
   ScaleHeight     =   8610
   ScaleWidth      =   8100
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "Home"
      Height          =   400
      Left            =   2040
      TabIndex        =   1
      Top             =   6480
      Width           =   1000
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Print"
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
      Caption         =   "Total Gain:-"
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
      Caption         =   "Profit Amount:-"
      Height          =   405
      Index           =   0
      Left            =   1200
      TabIndex        =   5
      Top             =   4680
      Width           =   1995
   End
   Begin VB.Label Label2 
      Caption         =   "Total Paid:-"
      Height          =   405
      Index           =   0
      Left            =   1200
      TabIndex        =   4
      Top             =   3600
      Width           =   1995
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Profit"
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
      TabIndex        =   3
      Top             =   360
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
Private Sub Command1_Click()
    Form14.Show
    Unload Me
End Sub

Private Sub Command2_Click()
        'Dim newFIle AS F
        'Dim FSO
        'Set FSO = CreateObject("Scripting.FileSystemObject")
        'Set newFIle = FSO.CreateTextFile("test", True, False)
        'FSO.write "Course ID"
        'FSO.write Text1.Text
        'FSO.write "COURSE TITLE"
        'FSO.write Label4.Caption
        'FSO.write "COURSE FEES"
        'FSO.write Label5.Caption
        'FSO.write "COURSE DESCRIPTION"
        'FSO.write Label6.Caption
        'FSO.write "COURSE DURATION"
        'FSO.write Label7.Caption
End Sub

Private Sub Form_Load()
    con.Connect = "uid=admin;pwd=admin;driver={Oracle in OraHome92}"
    con.EstablishConnection rdDriverNoPrompt
    Set rs1 = con.OpenResultset("SELECT SUM(S_FEES) AS A FROM STUDENT;", rdOpenStatic)
    Set rs2 = con.OpenResultset("SELECT SUM(I_SALARY) AS B FROM INSTRUCTOR;", rdOpenStatic)
    Label5.Caption = rs1.rdoColumns("A")
    Label9.Caption = rs2.rdoColumns("B")
    Label4.Caption = Label5.Caption - Label9.Caption
    Dim q As String
    q = "INSERT INTO PROFIT(TOTAL_GAIN,TOTAL_PAID,TOTAL_AMOUNT) VALUES (" + Label5.Caption + "," + Label9.Caption + "," + Label4.Caption + ");"
    con.Execute q
End Sub

Private Sub Form_Unload(Cancel As Integer)
    rs1.Close
    rs2.Close
    con.Close
End Sub
