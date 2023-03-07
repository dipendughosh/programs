VERSION 5.00
Begin VB.Form Form3 
   Caption         =   "Form3"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form3"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox Text4 
      Height          =   285
      Left            =   1560
      TabIndex        =   10
      Top             =   2040
      Width           =   2895
   End
   Begin VB.TextBox Text1 
      Height          =   285
      Left            =   1560
      TabIndex        =   4
      Top             =   480
      Width           =   2895
   End
   Begin VB.TextBox Text2 
      Height          =   285
      Left            =   1560
      TabIndex        =   3
      Top             =   960
      Width           =   2895
   End
   Begin VB.TextBox Text3 
      Height          =   285
      Left            =   1560
      TabIndex        =   2
      Top             =   1560
      Width           =   2895
   End
   Begin VB.CommandButton Command1 
      Caption         =   "ADD TO TABLE"
      Height          =   375
      Left            =   480
      TabIndex        =   1
      Top             =   2640
      Width           =   1455
   End
   Begin VB.CommandButton Command2 
      Caption         =   "TO MAIN MENU"
      Height          =   375
      Left            =   2400
      TabIndex        =   0
      Top             =   2640
      Width           =   1935
   End
   Begin VB.Label Label5 
      AutoSize        =   -1  'True
      Caption         =   "FLOOR"
      Height          =   195
      Left            =   480
      TabIndex        =   9
      Top             =   2040
      Width           =   540
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "DEPARTMENT TABLE DATA INSERT"
      Height          =   195
      Left            =   1080
      TabIndex        =   8
      Top             =   120
      Width           =   2805
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "D-ID"
      Height          =   195
      Left            =   480
      TabIndex        =   7
      Top             =   480
      Width           =   330
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "NAME"
      Height          =   195
      Left            =   480
      TabIndex        =   6
      Top             =   960
      Width           =   465
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "MANAGER-ID"
      Height          =   195
      Left            =   480
      TabIndex        =   5
      Top             =   1560
      Width           =   1020
   End
End
Attribute VB_Name = "Form3"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim CON As New rdoConnection

Private Sub Command1_Click()
    Dim Q As String
    Q = "INSERT INTO DEPT(D_id,D_name,Manager_id,Floor_num) VALUES('" + Text1.Text + "','" + Text2.Text + "','" + Text3.Text + "','" + Text4.Text + "');"
    CON.Execute Q
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
    CON.Connect = "UID=DIPENDU08;PWD=DIPENDU;Driver={Oracle in oracleHome9i}"
    CON.EstablishConnection rdDriverNoPrompt
End Sub
Private Sub Form_Unload(Cancel As Integer)
    CON.Close
End Sub

