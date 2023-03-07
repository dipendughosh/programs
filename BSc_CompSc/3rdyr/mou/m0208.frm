VERSION 5.00
Begin VB.Form Form3 
   Caption         =   "Form3"
   ClientHeight    =   3585
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   5085
   LinkTopic       =   "Form3"
   ScaleHeight     =   3585
   ScaleWidth      =   5085
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2 
      Caption         =   "MAIN MENU"
      Height          =   855
      Left            =   3960
      TabIndex        =   10
      Top             =   2040
      Width           =   975
   End
   Begin VB.CommandButton Command1 
      Caption         =   "ADD"
      Height          =   375
      Left            =   4080
      TabIndex        =   9
      Top             =   720
      Width           =   975
   End
   Begin VB.TextBox Text4 
      Height          =   375
      Left            =   1920
      TabIndex        =   8
      Top             =   2880
      Width           =   1695
   End
   Begin VB.TextBox Text3 
      Height          =   375
      Left            =   2040
      TabIndex        =   7
      Top             =   2160
      Width           =   1575
   End
   Begin VB.TextBox Text2 
      Height          =   375
      Left            =   2040
      TabIndex        =   6
      Top             =   1440
      Width           =   1575
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   2040
      TabIndex        =   5
      Top             =   720
      Width           =   1575
   End
   Begin VB.Label Label5 
      AutoSize        =   -1  'True
      Caption         =   "FLOOR_NUM:"
      Height          =   195
      Left            =   240
      TabIndex        =   4
      Top             =   2880
      Width           =   1050
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "MANAGER_ID:"
      Height          =   195
      Left            =   240
      TabIndex        =   3
      Top             =   2160
      Width           =   1110
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "D_NAME:"
      Height          =   195
      Left            =   240
      TabIndex        =   2
      Top             =   1440
      Width           =   720
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "D_ID:"
      Height          =   195
      Left            =   240
      TabIndex        =   1
      Top             =   720
      Width           =   420
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "DEPT1 TABLE"
      Height          =   195
      Left            =   1680
      TabIndex        =   0
      Top             =   120
      Width           =   1080
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
    Q = "INSERT INTO dept1(D_ID,D_NAME,MANAGER_ID,FLOOR_NUM)VALUES(" + Text1.Text + ",'" + Text2.Text + "'," + Text3.Text + ",'" + Text4.Text + "')"
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
    con.Connect = "uid=moumita;pwd=moumita;Driver={Oracle in Oracle9i1}"
    con.EstablishConnection rdDriverNoPrompt
End Sub
