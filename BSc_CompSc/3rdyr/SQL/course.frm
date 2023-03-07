VERSION 5.00
Begin VB.Form Form4 
   Caption         =   "Form4"
   ClientHeight    =   4335
   ClientLeft      =   7170
   ClientTop       =   690
   ClientWidth     =   6270
   LinkTopic       =   "Form4"
   ScaleHeight     =   4335
   ScaleWidth      =   6270
   Begin VB.CommandButton Command3 
      Caption         =   "CLEAR"
      Height          =   615
      Left            =   4920
      TabIndex        =   9
      Top             =   3360
      Width           =   975
   End
   Begin VB.CommandButton Command2 
      Caption         =   "BACK"
      Height          =   615
      Left            =   4800
      TabIndex        =   8
      Top             =   2400
      Width           =   975
   End
   Begin VB.CommandButton Command1 
      Caption         =   "NEXT"
      Height          =   735
      Left            =   4800
      TabIndex        =   7
      Top             =   840
      Width           =   975
   End
   Begin VB.TextBox Text3 
      Height          =   285
      Left            =   1920
      TabIndex        =   6
      Top             =   1920
      Width           =   2415
   End
   Begin VB.TextBox Text2 
      Height          =   375
      Left            =   1920
      TabIndex        =   5
      Top             =   1320
      Width           =   2535
   End
   Begin VB.TextBox Text1 
      Height          =   285
      Left            =   1920
      TabIndex        =   4
      Top             =   720
      Width           =   2535
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "CNAME"
      Height          =   195
      Left            =   360
      TabIndex        =   3
      Top             =   2040
      Width           =   570
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "CNO"
      Height          =   195
      Left            =   360
      TabIndex        =   2
      Top             =   1440
      Width           =   345
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "DNAME"
      Height          =   195
      Left            =   360
      TabIndex        =   1
      Top             =   720
      Width           =   585
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "COURSE"
      Height          =   195
      Left            =   2160
      TabIndex        =   0
      Top             =   0
      Width           =   675
   End
End
Attribute VB_Name = "Form4"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection

Private Sub Command1_Click()
    Dim q As String
    q = "INSERT INTO COURSE(DNAME,CNO,CNAME) VALUES('" + Text1.Text + "'," + Text2.Text + ",'" + Text3.Text + "');"
    con.Execute q
    Text1.Text = ""
    Text2.Text = ""
    Text3.Text = ""
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

