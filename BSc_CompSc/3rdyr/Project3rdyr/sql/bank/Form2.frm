VERSION 5.00
Begin VB.Form Form2 
   Caption         =   "Branch"
   ClientHeight    =   4140
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   3975
   LinkTopic       =   "Form2"
   ScaleHeight     =   4140
   ScaleWidth      =   3975
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2 
      Caption         =   "Go to Main Form"
      Height          =   495
      Left            =   1920
      TabIndex        =   8
      Top             =   3240
      Width           =   1335
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Add"
      Height          =   495
      Left            =   600
      TabIndex        =   7
      Top             =   3240
      Width           =   735
   End
   Begin VB.TextBox Text3 
      Height          =   285
      Left            =   2160
      TabIndex        =   6
      Top             =   2400
      Width           =   855
   End
   Begin VB.TextBox Text2 
      Height          =   285
      Left            =   2160
      TabIndex        =   5
      Top             =   1560
      Width           =   855
   End
   Begin VB.TextBox Text1 
      Height          =   285
      Left            =   2160
      TabIndex        =   4
      Top             =   840
      Width           =   855
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "Assets"
      Height          =   195
      Left            =   600
      TabIndex        =   3
      Top             =   2520
      Width           =   465
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "Branch City"
      Height          =   195
      Left            =   600
      TabIndex        =   2
      Top             =   1680
      Width           =   810
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "Branch Name"
      Height          =   195
      Left            =   600
      TabIndex        =   1
      Top             =   840
      Width           =   975
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "BRANCH TABLE"
      Height          =   195
      Left            =   1320
      TabIndex        =   0
      Top             =   360
      Width           =   1230
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
    Q = "INSERT INTO BRANCH(BRANCH_NAME,BRANCH_CITY,ASSETS) VALUES ('" + Text1.Text + "','" + _
    Text2.Text + "'," + Text3.Text + ")"
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
    con.Connect = "uid=dipendu;pwd=dipendu;driver={Oracle in OraDb10g_home1}"
    con.EstablishConnection rdDriverNoPrompt
End Sub

Private Sub Form_Unload(Cancel As Integer)
    con.Close
End Sub




