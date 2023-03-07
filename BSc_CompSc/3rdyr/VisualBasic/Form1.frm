VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   4665
   ClientLeft      =   120
   ClientTop       =   420
   ClientWidth     =   6000
   LinkTopic       =   "Form1"
   ScaleHeight     =   4665
   ScaleWidth      =   6000
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command3 
      Caption         =   "Prev"
      Height          =   495
      Left            =   3480
      TabIndex        =   7
      Top             =   2640
      Width           =   855
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Next"
      Height          =   615
      Left            =   3480
      TabIndex        =   6
      Top             =   1800
      Width           =   855
   End
   Begin VB.Label Label6 
      BorderStyle     =   1  'Fixed Single
      Caption         =   "Label3"
      Height          =   375
      Left            =   1080
      TabIndex        =   5
      Top             =   1320
      Width           =   1575
   End
   Begin VB.Label Label5 
      BorderStyle     =   1  'Fixed Single
      Caption         =   "Label3"
      Height          =   375
      Left            =   1080
      TabIndex        =   4
      Top             =   840
      Width           =   1575
   End
   Begin VB.Label Label3 
      BorderStyle     =   1  'Fixed Single
      Caption         =   "Label3"
      Height          =   375
      Left            =   1080
      TabIndex        =   3
      Top             =   360
      Width           =   1575
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "Marks"
      Height          =   195
      Left            =   480
      TabIndex        =   2
      Top             =   1320
      Width           =   435
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "Name"
      Height          =   195
      Left            =   480
      TabIndex        =   1
      Top             =   840
      Width           =   420
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "Roll:"
      Height          =   195
      Left            =   480
      TabIndex        =   0
      Top             =   360
      Width           =   315
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection
Dim rs As rdoResultset

Private Sub Command2_Click()
    rs.MoveNext
    If rs.EOF = True Then
        rs.MoveFirst
    End If
    Label3.Caption = rs.rdoColumns("roll")
    Label5.Caption = rs.rdoColumns("name")
    Label6.Caption = rs.rdoColumns("marks")
End Sub

Private Sub Command3_Click()
    rs.MovePrevious
    If rs.BOF = True Then
        rs.MoveLast
    End If
    Label3.Caption = rs.rdoColumns("roll")
    Label5.Caption = rs.rdoColumns("name")
    Label6.Caption = rs.rdoColumns("marks")
End Sub

Private Sub Form_Load()
    con.Connect = "uid=scott;pwd=tiger;Driver={Oracle in OraDb10g_home1}"
    con.EstablishConnection rdDriverNoPrompt
    Set rs = con.OpenResultset("SELECT * FROM STU", rdOpenStatic)
    Label3.Caption = rs.rdoColumns("roll")
    Label5.Caption = rs.rdoColumns("name")
    Label6.Caption = rs.rdoColumns("marks")
End Sub

Private Sub Form_QueryUnload(Cancel As Integer, UnloadMode As Integer)
    rs.Close
    con.Close
End Sub
