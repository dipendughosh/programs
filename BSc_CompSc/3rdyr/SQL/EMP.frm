VERSION 5.00
Begin VB.Form Form2 
   Caption         =   "Form2"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form2"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2 
      Caption         =   "TO MAIN MENU"
      Height          =   375
      Left            =   2400
      TabIndex        =   7
      Top             =   2520
      Width           =   1935
   End
   Begin VB.CommandButton Command1 
      Caption         =   "ADD TO TABLE"
      Height          =   375
      Left            =   480
      TabIndex        =   6
      Top             =   2520
      Width           =   1455
   End
   Begin VB.TextBox Text3 
      Height          =   285
      Left            =   1560
      TabIndex        =   5
      Top             =   1920
      Width           =   2895
   End
   Begin VB.TextBox Text2 
      Height          =   285
      Left            =   1560
      TabIndex        =   4
      Top             =   1320
      Width           =   2895
   End
   Begin VB.TextBox Text1 
      Height          =   285
      Left            =   1560
      TabIndex        =   3
      Top             =   720
      Width           =   2895
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "EMPLOYEE TABLE DATA INSERT"
      Height          =   195
      Left            =   1080
      TabIndex        =   8
      Top             =   120
      Width           =   2550
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "SALARY"
      Height          =   195
      Left            =   480
      TabIndex        =   2
      Top             =   1920
      Width           =   630
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "NAME"
      Height          =   195
      Left            =   480
      TabIndex        =   1
      Top             =   1320
      Width           =   465
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "E-ID"
      Height          =   195
      Left            =   480
      TabIndex        =   0
      Top             =   720
      Width           =   315
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim CON As New rdoConnection

Private Sub Command1_Click()
    Dim Q As String
    Q = "INSERT INTO EMP(E_id,E_name,Salary) VALUES('" + Text1.Text + "','" + Text2.Text + "'," + Text3.Text + ");"
    CON.Execute Q
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
    CON.Connect = "UID=DIPENDU08;PWD=DIPENDU;Driver={Oracle in oracleHome9i}"
    CON.EstablishConnection rdDriverNoPrompt
End Sub
Private Sub Form_Unload(Cancel As Integer)
    CON.Close
End Sub
