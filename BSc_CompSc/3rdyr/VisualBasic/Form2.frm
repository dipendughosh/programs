VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   4665
   ClientLeft      =   120
   ClientTop       =   420
   ClientWidth     =   6000
   LinkTopic       =   "Form1"
   ScaleHeight     =   4665
   ScaleWidth      =   6000
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox Text3 
      Height          =   285
      Left            =   960
      TabIndex        =   6
      Top             =   1320
      Width           =   1455
   End
   Begin VB.TextBox Text2 
      Height          =   375
      Left            =   960
      TabIndex        =   5
      Top             =   840
      Width           =   1455
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   1080
      TabIndex        =   4
      Top             =   360
      Width           =   1215
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Add"
      Height          =   615
      Left            =   3480
      TabIndex        =   3
      Top             =   1800
      Width           =   855
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "Marks"
      Height          =   195
      Left            =   480
      TabIndex        =   2
      Top             =   1320
      Width           =   435
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "Name"
      Height          =   195
      Left            =   480
      TabIndex        =   1
      Top             =   840
      Width           =   420
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "Roll:"
      Height          =   195
      Left            =   480
      TabIndex        =   0
      Top             =   360
      Width           =   315
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection

Private Sub Command2_Click()
    Dim Q As String
    Q = "INSERT INTO STU(ROLL,NAME,MARKS) VALUES (" _
    + Text1.Text + ",'" + Text2.Text + "'," + Text3.Text + ")"
    con.Execute Q
    Text1.Text = ""
    Text2.Text = ""
    Text3.Text = ""
End Sub

Private Sub Form_Load()
    con.Connect = "uid=scott;pwd=tiger;Driver={Oracle in OraDb10g_home1}"
    con.EstablishConnection rdDriverNoPrompt
End Sub

Private Sub Form_QueryUnload(Cancel As Integer, UnloadMode As Integer)
    con.Close
End Sub
