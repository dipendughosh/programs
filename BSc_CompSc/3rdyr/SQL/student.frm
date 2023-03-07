VERSION 5.00
Begin VB.Form Form2 
   Caption         =   "Form2"
   ClientHeight    =   4740
   ClientLeft      =   12630
   ClientTop       =   690
   ClientWidth     =   6240
   LinkTopic       =   "Form2"
   ScaleHeight     =   4740
   ScaleWidth      =   6240
   Begin VB.CommandButton Command3 
      Caption         =   "CLEAR"
      Height          =   615
      Left            =   5040
      TabIndex        =   15
      Top             =   3480
      Width           =   855
   End
   Begin VB.CommandButton Command2 
      Caption         =   "BACK"
      Height          =   615
      Left            =   4920
      TabIndex        =   14
      Top             =   2520
      Width           =   975
   End
   Begin VB.CommandButton Command1 
      Caption         =   "NEXT"
      Height          =   735
      Left            =   4920
      TabIndex        =   13
      Top             =   960
      Width           =   975
   End
   Begin VB.TextBox Text6 
      Height          =   375
      Left            =   2040
      TabIndex        =   12
      Top             =   3840
      Width           =   2535
   End
   Begin VB.TextBox Text5 
      Height          =   375
      Left            =   2040
      TabIndex        =   11
      Top             =   3120
      Width           =   2535
   End
   Begin VB.TextBox Text4 
      Height          =   375
      Left            =   2040
      TabIndex        =   10
      Top             =   2520
      Width           =   2535
   End
   Begin VB.TextBox Text3 
      Height          =   285
      Left            =   2040
      TabIndex        =   9
      Top             =   2040
      Width           =   2415
   End
   Begin VB.TextBox Text2 
      Height          =   375
      Left            =   2040
      TabIndex        =   8
      Top             =   1440
      Width           =   2535
   End
   Begin VB.TextBox Text1 
      Height          =   285
      Left            =   2040
      TabIndex        =   7
      Top             =   840
      Width           =   2535
   End
   Begin VB.Label Label7 
      AutoSize        =   -1  'True
      Caption         =   "GPA"
      Height          =   195
      Left            =   480
      TabIndex        =   6
      Top             =   3960
      Width           =   330
   End
   Begin VB.Label Label6 
      AutoSize        =   -1  'True
      Caption         =   "YEAR"
      Height          =   195
      Left            =   480
      TabIndex        =   5
      Top             =   3240
      Width           =   435
   End
   Begin VB.Label Label5 
      AutoSize        =   -1  'True
      Caption         =   "AGE"
      Height          =   195
      Left            =   480
      TabIndex        =   4
      Top             =   2640
      Width           =   330
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "SEX"
      Height          =   195
      Left            =   480
      TabIndex        =   3
      Top             =   2160
      Width           =   315
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "SNAME"
      Height          =   195
      Left            =   480
      TabIndex        =   2
      Top             =   1560
      Width           =   570
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "SID"
      Height          =   195
      Left            =   480
      TabIndex        =   1
      Top             =   840
      Width           =   270
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "STUDENT"
      Height          =   195
      Left            =   2280
      TabIndex        =   0
      Top             =   120
      Width           =   780
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection

Private Sub Command1_Click()
    Dim q As String
    q = "INSERT INTO STUDENT(SID,SNAME,SEX,AGE,YEAR,GPA) VALUES(" + Text1.Text + ",'" + Text2.Text + "','" + Text3.Text + "'," + Text4.Text + "," + Text5.Text + ",'" + Text6.Text + "');"
    con.Execute q
    Text1.Text = ""
    Text2.Text = ""
    Text3.Text = ""
    Text4.Text = ""
    Text5.Text = ""
    Text6.Text = ""
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
