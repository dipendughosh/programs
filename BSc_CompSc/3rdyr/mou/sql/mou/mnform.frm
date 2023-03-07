VERSION 5.00
Begin VB.Form Form4 
   Caption         =   "Form4"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form4"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2 
      Caption         =   "MAIN MENU"
      Height          =   615
      Left            =   3480
      TabIndex        =   7
      Top             =   1680
      Width           =   975
   End
   Begin VB.CommandButton Command1 
      Caption         =   "ADD"
      Height          =   615
      Left            =   3480
      TabIndex        =   6
      Top             =   360
      Width           =   855
   End
   Begin VB.TextBox Text3 
      Height          =   495
      Left            =   960
      TabIndex        =   5
      Top             =   2160
      Width           =   1935
   End
   Begin VB.TextBox Text2 
      Height          =   495
      Left            =   960
      TabIndex        =   4
      Top             =   1200
      Width           =   1935
   End
   Begin VB.TextBox Text1 
      Height          =   495
      Left            =   960
      TabIndex        =   3
      Top             =   240
      Width           =   1935
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "SID:"
      Height          =   195
      Left            =   120
      TabIndex        =   2
      Top             =   360
      Width           =   315
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "DAY:"
      Height          =   195
      Left            =   120
      TabIndex        =   1
      Top             =   2160
      Width           =   375
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "BID:"
      Height          =   195
      Left            =   120
      TabIndex        =   0
      Top             =   1200
      Width           =   315
   End
End
Attribute VB_Name = "Form4"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection

Private Sub Command1_Click()
    Dim Q As String
    Q = "INSERT INTO RESERVES VALUES(" + Text1.Text + "," + Text2.Text + ",'" + Text3.Text + "')"
    Text1.Text = ""
    Text2.Text = ""
    Text3.Text = ""
    Text1.SetFocus
End Sub

Private Sub Command2_Click()
    Form1.Show
    Hide
End Sub

Private Sub Form_Load()
    con.Connect = "uid=scott;pwd=tiger;driver={Oracle in oracle 9i1}"
    con.EstablishConnection rdDriverNoPrompt
End Sub
