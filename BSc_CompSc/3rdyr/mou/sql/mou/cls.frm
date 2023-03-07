VERSION 5.00
Begin VB.Form CLS1 
   Caption         =   "CLASS"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form3"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   WindowState     =   2  'Maximized
   Begin VB.CommandButton Cmd3 
      Caption         =   "EXIT"
      Height          =   495
      Left            =   6480
      TabIndex        =   10
      Top             =   6360
      Width           =   1215
   End
   Begin VB.CommandButton Cmd2 
      Caption         =   "CANCEL"
      Height          =   495
      Left            =   3840
      TabIndex        =   9
      Top             =   6360
      Width           =   1215
   End
   Begin VB.CommandButton Cmd1 
      Caption         =   "INSERT"
      Height          =   495
      Left            =   1440
      TabIndex        =   8
      Top             =   6360
      Width           =   1215
   End
   Begin VB.TextBox Text4 
      Height          =   495
      Left            =   3480
      TabIndex        =   7
      Top             =   4680
      Width           =   3015
   End
   Begin VB.TextBox Text3 
      Height          =   495
      Left            =   3540
      TabIndex        =   6
      Top             =   3120
      Width           =   3015
   End
   Begin VB.TextBox Text2 
      Height          =   495
      Left            =   3480
      TabIndex        =   5
      Top             =   1920
      Width           =   3015
   End
   Begin VB.TextBox Text1 
      Height          =   495
      Left            =   3480
      TabIndex        =   4
      Top             =   600
      Width           =   3015
   End
   Begin VB.Label Label4 
      Caption         =   "FACULTY_ID"
      Height          =   495
      Left            =   1440
      TabIndex        =   3
      Top             =   4680
      Width           =   1215
   End
   Begin VB.Label Label3 
      Caption         =   "ROOM"
      Height          =   495
      Left            =   1440
      TabIndex        =   2
      Top             =   3120
      Width           =   1215
   End
   Begin VB.Label Label2 
      Caption         =   "TIME_SCHEDULE"
      Height          =   495
      Left            =   1200
      TabIndex        =   1
      Top             =   1920
      Width           =   1455
   End
   Begin VB.Label Label1 
      Caption         =   "CNUM"
      Height          =   495
      Left            =   1440
      TabIndex        =   0
      Top             =   480
      Width           =   1215
   End
End
Attribute VB_Name = "CLS1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection
Dim q As String
Private Sub Cmd1_Click()
q = "INSERT INTO CLASS(CNUM,TIME_SCHEDULE,ROOM,FACULTY_ID) VALUES ('" + Text1.Text + "','" + Text2.Text + "','" + Text3.Text + "','" + Text4.Text + "')"
con.Execute q

Text1.Text = ""
Text2.Text = ""
Text3.Text = ""
Text4.Text = ""
MsgBox ("SUCCESSFULLY INSERTED TO THE TABLE")

End Sub

Private Sub Cmd2_Click()
Text1.Text = ""
Text2.Text = ""
Text3.Text = ""
Text4.Text = ""

End Sub

Private Sub Cmd3_Click()
Unload Me

End Sub

Private Sub Form_Load()
con.Connect = "uid=scott;pwd=tiger;driver={Oracle in OraHome92}"
con.EstablishConnection rdDriverNoPrompt
End Sub
