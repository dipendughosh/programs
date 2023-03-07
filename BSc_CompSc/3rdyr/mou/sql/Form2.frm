VERSION 5.00
Begin VB.Form Form2 
   Caption         =   "Form2"
   ClientHeight    =   6060
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6435
   LinkTopic       =   "Form2"
   ScaleHeight     =   6060
   ScaleWidth      =   6435
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2 
      Caption         =   "main"
      Height          =   615
      Left            =   3360
      TabIndex        =   11
      Top             =   5040
      Width           =   1575
   End
   Begin VB.CommandButton Command1 
      Caption         =   "add"
      Height          =   615
      Left            =   600
      TabIndex        =   10
      Top             =   5040
      Width           =   1575
   End
   Begin VB.TextBox Text5 
      Height          =   735
      Left            =   3600
      TabIndex        =   9
      Top             =   3600
      Width           =   1935
   End
   Begin VB.TextBox Text4 
      Height          =   615
      Left            =   3480
      TabIndex        =   8
      Top             =   2640
      Width           =   2055
   End
   Begin VB.TextBox Text3 
      Height          =   495
      Left            =   3360
      TabIndex        =   7
      Top             =   2040
      Width           =   2055
   End
   Begin VB.TextBox Text2 
      Height          =   375
      Left            =   3240
      TabIndex        =   6
      Top             =   1320
      Width           =   1935
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   2640
      TabIndex        =   5
      Top             =   360
      Width           =   2295
   End
   Begin VB.Label Label4 
      Caption         =   "ph nmbr"
      Height          =   855
      Left            =   240
      TabIndex        =   4
      Top             =   3720
      Width           =   2895
   End
   Begin VB.Label Label3 
      Caption         =   "cst ct"
      Height          =   615
      Left            =   240
      TabIndex        =   3
      Top             =   2760
      Width           =   2895
   End
   Begin VB.Label Label2 
      Caption         =   "cst addres"
      Height          =   495
      Left            =   240
      TabIndex        =   2
      Top             =   2040
      Width           =   2775
   End
   Begin VB.Label Label1 
      Caption         =   "cut nm"
      Height          =   375
      Left            =   360
      TabIndex        =   1
      Top             =   1320
      Width           =   2415
   End
   Begin VB.Label cu 
      Caption         =   "cust id"
      Height          =   375
      Left            =   360
      TabIndex        =   0
      Top             =   480
      Width           =   2175
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
    q = "INSERT INTO CUSTOMERZ VALUES(" + Text1.Text + ",'" + Text2.Text + "','" + Text3.Text + "'," + Text4.Text + "," + Text5.Text + ");"
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
    con.Connect = "uid=moumita;pwd=moumita;Driver={Oracle in oracleHome9i}"
    con.EstablishConnection rdDriverNoPrompt
End Sub

Private Sub Form_Unload(Cancel As Integer)
    con.Close
End Sub

