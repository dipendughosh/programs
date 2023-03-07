VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   4680
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4995
   LinkTopic       =   "Form1"
   ScaleHeight     =   4680
   ScaleWidth      =   4995
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2 
      Caption         =   "Close"
      Height          =   735
      Left            =   2760
      TabIndex        =   7
      Top             =   3360
      Width           =   1575
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Next"
      Height          =   735
      Left            =   480
      TabIndex        =   6
      Top             =   3360
      Width           =   1575
   End
   Begin VB.TextBox Text3 
      Height          =   375
      Left            =   2640
      TabIndex        =   5
      Top             =   2160
      Width           =   1095
   End
   Begin VB.TextBox Text2 
      Height          =   375
      Left            =   2640
      TabIndex        =   4
      Top             =   1200
      Width           =   1935
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   2640
      TabIndex        =   3
      Top             =   240
      Width           =   1095
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "MARKS :-"
      Height          =   195
      Left            =   840
      TabIndex        =   2
      Top             =   2160
      Width           =   705
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "NAME :-"
      Height          =   195
      Left            =   840
      TabIndex        =   1
      Top             =   1200
      Width           =   600
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "ROLL No. :-"
      Height          =   195
      Left            =   840
      TabIndex        =   0
      Top             =   360
      Width           =   855
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection

Private Sub Command1_Click()
    Dim Q As String
    Q = "INSERT INTO STU(ROLL,NAME,MARKS) VALUES (" + Text1.Text + ",'" + _
    Text2.Text + "'," + Text3.Text + ")"
    con.Execute Q
    Text1.Text = ""
    Text2.Text = ""
    Text3.Text = ""
    Text1.SetFocus
End Sub

Private Sub Command2_Click()
    MsgBox "close", vbOKCancel
    Unload Me
End Sub

Private Sub Form_Load()
    con.Connect = "uid=dipendu;pwd=dipendu;driver={Oracle in oracleHome9i}"
    con.EstablishConnection rdDriverNoPrompt
End Sub

Private Sub Form_Unload(Cancel As Integer)
    con.Close
End Sub
