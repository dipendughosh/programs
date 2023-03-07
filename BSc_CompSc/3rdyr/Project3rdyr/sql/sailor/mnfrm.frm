VERSION 5.00
Begin VB.Form Form3 
   Caption         =   "Form3"
   ClientHeight    =   3135
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4965
   LinkTopic       =   "Form3"
   ScaleHeight     =   3135
   ScaleWidth      =   4965
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2 
      Caption         =   "MAIN MENU"
      Height          =   615
      Left            =   3840
      TabIndex        =   7
      Top             =   1680
      Width           =   855
   End
   Begin VB.CommandButton Command1 
      Caption         =   "ADD"
      Height          =   495
      Left            =   3840
      TabIndex        =   6
      Top             =   480
      Width           =   855
   End
   Begin VB.TextBox Text3 
      Height          =   495
      Left            =   1440
      TabIndex        =   5
      Top             =   1920
      Width           =   1935
   End
   Begin VB.TextBox Text2 
      Height          =   495
      Left            =   1440
      TabIndex        =   4
      Top             =   1080
      Width           =   1935
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   1440
      TabIndex        =   3
      Top             =   240
      Width           =   1935
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "COLOUR:"
      Height          =   195
      Left            =   240
      TabIndex        =   2
      Top             =   2040
      Width           =   720
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "B_NAME:"
      Height          =   195
      Left            =   240
      TabIndex        =   1
      Top             =   1080
      Width           =   705
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "BID:"
      Height          =   195
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   315
   End
End
Attribute VB_Name = "Form3"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection

Private Sub Command1_Click()
    Dim Q As String
    Q = "INSERT INTO BOATS1 VALUES(" + Text1.Text + ",'" + Text2.Text + "','" + Text3.Text + "')"
    con.Execute Q
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
    con.Connect = "uid=scott;pwd=tiger;driver={Oracle in oracle9i1}"
    con.EstablishConnection rdDriverNoPrompt
End Sub
