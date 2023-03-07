VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   5385
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   5040
   LinkTopic       =   "Form1"
   ScaleHeight     =   5385
   ScaleWidth      =   5040
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command3 
      Caption         =   "Close"
      Height          =   735
      Left            =   1440
      TabIndex        =   8
      Top             =   4080
      Width           =   1455
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Previous"
      Height          =   495
      Left            =   2520
      TabIndex        =   7
      Top             =   3240
      Width           =   1575
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Next"
      Height          =   495
      Left            =   360
      TabIndex        =   6
      Top             =   3240
      Width           =   1575
   End
   Begin VB.Label Label6 
      Height          =   375
      Left            =   2760
      TabIndex        =   5
      Top             =   2160
      Width           =   855
   End
   Begin VB.Label Label5 
      Height          =   375
      Left            =   2760
      TabIndex        =   4
      Top             =   1200
      Width           =   855
   End
   Begin VB.Label Label4 
      Height          =   375
      Left            =   2760
      TabIndex        =   3
      Top             =   360
      Width           =   855
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "Marks:-"
      Height          =   195
      Left            =   480
      TabIndex        =   2
      Top             =   2160
      Width           =   525
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "Name:-"
      Height          =   195
      Left            =   480
      TabIndex        =   1
      Top             =   1200
      Width           =   510
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "Roll:-"
      Height          =   195
      Left            =   480
      TabIndex        =   0
      Top             =   360
      Width           =   360
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection
Dim rs As rdoResultset
Private Sub Command1_Click()
    rs.MoveNext
    If rs.EOF = True Then
        rs.MoveFirst
    End If
    Label4.Caption = rs.rdoColumns("ROLL")
    Label5.Caption = rs.rdoColumns("NAME")
    Label6.Caption = rs.rdoColumns("MARKS")
End Sub

Private Sub Command2_Click()
    rs.MovePrevious
    If rs.BOF = True Then
        rs.MoveLast
    End If
    Label4.Caption = rs.rdoColumns("ROLL")
    Label5.Caption = rs.rdoColumns("NAME")
    Label6.Caption = rs.rdoColumns("MARKS")
End Sub

Private Sub Command3_Click()
    Unload Me
End Sub

Private Sub Form_Load()
    con.Connect = "uid=dipendu;pwd=dipendu;Driver={Oracle in oracleHome9i}"
    con.EstablishConnection rdDriverNoPrompt
    Set rs = con.OpenResultset("SELECT * FROM STU", rdOpenStatic)
    Label4.Caption = rs.rdoColumns("ROLL")
    Label5.Caption = rs.rdoColumns("NAME")
    Label6.Caption = rs.rdoColumns("MARKS")
End Sub
Private Sub Form_Unload(Cancel As Integer)
    rs.Close
    con.Close
End Sub
