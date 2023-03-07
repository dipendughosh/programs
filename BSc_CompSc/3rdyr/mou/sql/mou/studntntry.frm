VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2 
      Caption         =   "CLOSE"
      Height          =   855
      Left            =   3480
      TabIndex        =   7
      Top             =   1800
      Width           =   975
   End
   Begin VB.CommandButton Command1 
      Caption         =   "NEXT"
      Height          =   735
      Left            =   3480
      TabIndex        =   6
      Top             =   360
      Width           =   975
   End
   Begin VB.TextBox Text3 
      Height          =   375
      Left            =   1200
      TabIndex        =   5
      Text            =   "Text3"
      Top             =   2280
      Width           =   1695
   End
   Begin VB.TextBox Text2 
      Height          =   495
      Left            =   1200
      TabIndex        =   4
      Text            =   "Text2"
      Top             =   1080
      Width           =   1695
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   1200
      TabIndex        =   3
      Text            =   "Text1"
      Top             =   240
      Width           =   1695
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "MARKS:"
      Height          =   195
      Left            =   120
      TabIndex        =   2
      Top             =   2280
      Width           =   615
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "NAME:"
      Height          =   195
      Left            =   120
      TabIndex        =   1
      Top             =   1200
      Width           =   510
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "ROLL:"
      Height          =   195
      Left            =   120
      TabIndex        =   0
      Top             =   240
      Width           =   465
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection

Private Sub Command1_Click()
    Dim q As String
    q = "INSERT INTO STUDENT(ROLL,NAME,MARKS)VALUES(" + Text1.Text + ",'" + Text2.Text + "'," + Text3.Text + ")"
    con.Execute q
    Text1.Text = ""
    Text2.Text = ""
    Text3.Text = ""
    Text1.SetFocus
End Sub

Private Sub Command2_Click()
    MsgBox "close", vbOKCancel
    Unload Me
End Sub

Private Sub Form_Load()
    con.Connect = "uid=scott;pwd=tiger,driver={Oracle in oracle9i1}"
    con.EstablishConnection rdDriverNoPrompt
End Sub

Private Sub Form_Unload(Cancel As Integer)
    con.Close
End Sub
