VERSION 5.00
Begin VB.Form Form3 
   Caption         =   "Form3"
   ClientHeight    =   4590
   ClientLeft      =   1725
   ClientTop       =   8130
   ClientWidth     =   6405
   LinkTopic       =   "Form3"
   ScaleHeight     =   4590
   ScaleWidth      =   6405
   Begin VB.CommandButton Command3 
      Caption         =   "CLEAR"
      Height          =   615
      Left            =   4920
      TabIndex        =   7
      Top             =   3360
      Width           =   975
   End
   Begin VB.CommandButton Command2 
      Caption         =   "BACK"
      Height          =   615
      Left            =   4920
      TabIndex        =   6
      Top             =   2400
      Width           =   975
   End
   Begin VB.CommandButton Command1 
      Caption         =   "NEXT"
      Height          =   735
      Left            =   4920
      TabIndex        =   5
      Top             =   840
      Width           =   975
   End
   Begin VB.TextBox Text2 
      Height          =   375
      Left            =   2040
      TabIndex        =   4
      Top             =   1320
      Width           =   2535
   End
   Begin VB.TextBox Text1 
      Height          =   285
      Left            =   2040
      TabIndex        =   3
      Top             =   720
      Width           =   2535
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "PNAME"
      Height          =   195
      Left            =   480
      TabIndex        =   2
      Top             =   1440
      Width           =   570
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "DNMAE"
      Height          =   195
      Left            =   480
      TabIndex        =   1
      Top             =   720
      Width           =   585
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "PROFESSOR"
      Height          =   195
      Left            =   2280
      TabIndex        =   0
      Top             =   0
      Width           =   990
   End
End
Attribute VB_Name = "Form3"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection

Private Sub Command1_Click()
    Dim q As String
    q = "INSERT INTO PROFESSOR(PNAME,DNAME) VALUES('" + Text1.Text + "','" + Text2.Text + "');"
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

