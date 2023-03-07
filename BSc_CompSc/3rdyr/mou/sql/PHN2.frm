VERSION 5.00
Begin VB.Form Form4 
   Caption         =   "Form4"
   ClientHeight    =   4020
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form4"
   ScaleHeight     =   4020
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2 
      Caption         =   "MAIN FORM"
      Height          =   735
      Left            =   3240
      TabIndex        =   12
      Top             =   2040
      Width           =   975
   End
   Begin VB.CommandButton Command1 
      Caption         =   "ADD"
      Height          =   615
      Left            =   3360
      TabIndex        =   11
      Top             =   600
      Width           =   1095
   End
   Begin VB.TextBox Text5 
      Height          =   285
      Left            =   1560
      TabIndex        =   10
      Top             =   3120
      Width           =   1335
   End
   Begin VB.TextBox Text4 
      Height          =   375
      Left            =   1680
      TabIndex        =   9
      Top             =   2400
      Width           =   1215
   End
   Begin VB.TextBox Text3 
      Height          =   375
      Left            =   1680
      TabIndex        =   8
      Top             =   1680
      Width           =   1215
   End
   Begin VB.TextBox Text2 
      Height          =   285
      Left            =   1440
      TabIndex        =   7
      Top             =   1080
      Width           =   1215
   End
   Begin VB.TextBox Text1 
      Height          =   285
      Left            =   1440
      TabIndex        =   6
      Top             =   480
      Width           =   1335
   End
   Begin VB.Label Label6 
      AutoSize        =   -1  'True
      Caption         =   "CALL_CHARGE:"
      Height          =   315
      Left            =   120
      TabIndex        =   5
      Top             =   3120
      Width           =   1200
   End
   Begin VB.Label Label5 
      AutoSize        =   -1  'True
      Caption         =   "CALL_DURATION:"
      Height          =   195
      Left            =   120
      TabIndex        =   4
      Top             =   2400
      Width           =   1380
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "CALL_LOCATION:"
      Height          =   195
      Left            =   120
      TabIndex        =   3
      Top             =   1680
      Width           =   1335
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "CALL TIME:"
      Height          =   315
      Left            =   120
      TabIndex        =   2
      Top             =   1080
      Width           =   870
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "CUST_ID:"
      Height          =   195
      Left            =   240
      TabIndex        =   1
      Top             =   600
      Width           =   735
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "MOBILE BILL"
      Height          =   195
      Left            =   1680
      TabIndex        =   0
      Top             =   120
      Width           =   975
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
    q = "INSERT INTO MOBILE_BILL VALUES(" + Text1.Text + "," + Text2.Text + ",'" + Text3.Text + "'," + Text4.Text + "," + Text5.Text + ");"
    con.Execute q
    Text1.Text = ""
    Text2.Text = ""
    Text3.Text = ""
    Text4.Text = ""
    Text5.Text = ""
    Text1.SetFocus
End Sub

Private Sub Command2_Click()
    Form1.Show
    Hide
End Sub

Private Sub Form_Load()
    con.Connect = "uid=moumita;pwd=moumita;driver={Oracle in oracleHome9i}"
    con.EstablishConnection rdDriverNoPrompt
End Sub

Private Sub Form_Unload(Cancel As Integer)
    con.Close

End Sub
