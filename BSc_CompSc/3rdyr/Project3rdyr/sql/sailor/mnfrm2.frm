VERSION 5.00
Begin VB.Form Form2 
   Caption         =   "AGE:"
   ClientHeight    =   3510
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   5295
   LinkTopic       =   "Form2"
   ScaleHeight     =   3510
   ScaleWidth      =   5295
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2 
      Caption         =   "MAIN MENU"
      Height          =   495
      Left            =   4080
      TabIndex        =   9
      Top             =   1920
      Width           =   975
   End
   Begin VB.CommandButton Command1 
      Caption         =   "ADD"
      Height          =   375
      Left            =   4080
      TabIndex        =   8
      Top             =   600
      Width           =   975
   End
   Begin VB.TextBox Text4 
      Height          =   375
      Left            =   1320
      TabIndex        =   7
      Top             =   2640
      Width           =   2295
   End
   Begin VB.TextBox Text3 
      Height          =   375
      Left            =   1320
      TabIndex        =   6
      Top             =   1920
      Width           =   2295
   End
   Begin VB.TextBox Text2 
      Height          =   495
      Left            =   1320
      TabIndex        =   5
      Top             =   960
      Width           =   2295
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   1320
      TabIndex        =   4
      Top             =   240
      Width           =   2295
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "AGE:"
      Height          =   195
      Left            =   240
      TabIndex        =   3
      Top             =   2760
      Width           =   375
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "RATING:"
      Height          =   195
      Left            =   240
      TabIndex        =   2
      Top             =   1920
      Width           =   660
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "S_NAME:"
      Height          =   195
      Left            =   240
      TabIndex        =   1
      Top             =   1080
      Width           =   705
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "SID:"
      Height          =   195
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   315
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection

Private Sub Command1_Click()
    Dim Q As String
    Q = "INSERT INTO SAILORS(SID,S_NAME,RATING,AGE)VALUES(" + Text1.Text + ",'" + Text2.Text + "'," + Text3.Text + "," + Text4.Text + ")"
    con.Execute Q
    Text1.Text = ""
    Text2.Text = ""
    Text3.Text = ""
    Text4.Text = ""
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
