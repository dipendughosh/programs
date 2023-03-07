VERSION 5.00
Begin VB.Form Form5 
   Caption         =   "Form5"
   ClientHeight    =   4785
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6930
   LinkTopic       =   "Form5"
   ScaleHeight     =   4785
   ScaleWidth      =   6930
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command3 
      Caption         =   "CLEAR"
      Height          =   735
      Left            =   5400
      TabIndex        =   7
      Top             =   3720
      Width           =   1215
   End
   Begin VB.CommandButton Command2 
      Caption         =   "BACK"
      Height          =   615
      Left            =   5400
      TabIndex        =   6
      Top             =   2760
      Width           =   975
   End
   Begin VB.CommandButton Command1 
      Caption         =   "NEXT"
      Height          =   735
      Left            =   5400
      TabIndex        =   5
      Top             =   1200
      Width           =   975
   End
   Begin VB.TextBox Text2 
      Height          =   375
      Left            =   2520
      TabIndex        =   4
      Top             =   1680
      Width           =   2535
   End
   Begin VB.TextBox Text1 
      Height          =   285
      Left            =   2520
      TabIndex        =   3
      Top             =   1080
      Width           =   2535
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "SID"
      Height          =   195
      Left            =   960
      TabIndex        =   2
      Top             =   1800
      Width           =   270
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "DNAME"
      Height          =   195
      Left            =   960
      TabIndex        =   1
      Top             =   1080
      Width           =   585
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "MAJOR"
      Height          =   195
      Left            =   2760
      TabIndex        =   0
      Top             =   360
      Width           =   555
   End
End
Attribute VB_Name = "Form5"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection

Private Sub Command1_Click()
    Dim q As String
    q = "INSERT INTO MAJOR(DNAME,SID) VALUES('" + Text1.Text + "'," + Text2.Text + ");"
    con.Execute q
    Text1.Text = ""
    Text2.Text = ""

    Text1.SetFocus
End Sub

Private Sub Command2_Click()
    Hide
    Form1.Show
End Sub

Private Sub Command3_Click()
    Text1.Text = ""
    Text2.Text = ""
    Text3.Text = ""
    Text4.Text = ""
    Text5.Text = ""
    Text6.Text = ""
    Text1.SetFocus
End Sub

Private Sub Form_Load()
    con.Connect = "uid=dipendu08;pwd=dipendu;Driver={Oracle in oracleHome9i}"
    con.EstablishConnection rdoNoDriverPrompt
End Sub

Private Sub Form_Unload(Cancel As Integer)
    con.Close
End Sub


