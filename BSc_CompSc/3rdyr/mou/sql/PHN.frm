VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   5340
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   5340
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command4 
      Caption         =   "EXIT"
      Height          =   615
      Left            =   4320
      TabIndex        =   7
      Top             =   840
      Width           =   735
   End
   Begin VB.CommandButton Command3 
      Caption         =   "INSERT"
      Height          =   375
      Left            =   2040
      TabIndex        =   6
      Top             =   2280
      Width           =   1815
   End
   Begin VB.CommandButton Command2 
      Caption         =   "INSERT"
      Height          =   375
      Left            =   2040
      TabIndex        =   5
      Top             =   1320
      Width           =   1935
   End
   Begin VB.CommandButton Command1 
      Caption         =   "INSERT"
      Height          =   255
      Left            =   2160
      TabIndex        =   4
      Top             =   600
      Width           =   1695
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "MOBILE BILL TABLE"
      Height          =   195
      Left            =   120
      TabIndex        =   3
      Top             =   2400
      Width           =   1530
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "CITY TABLE"
      Height          =   195
      Left            =   120
      TabIndex        =   2
      Top             =   1440
      Width           =   915
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "CUSTOMERZ  TABLE"
      Height          =   195
      Left            =   120
      TabIndex        =   1
      Top             =   600
      Width           =   1620
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "MAIN FORM"
      Height          =   195
      Left            =   1560
      TabIndex        =   0
      Top             =   120
      Width           =   915
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection

Private Sub Command1_Click()
    Form2.Show
    Hide
End Sub

Private Sub Command2_Click()
    Form3.Show
    Hide
End Sub

Private Sub Command3_Click()
    Form4.Show
    Hide
End Sub

Private Sub Command4_Click()
    Unload Form2
    Unload Form3
    Unload Form4
    Unload Me
End Sub

Private Sub Form_Load()
    con.Connect = "uid=moumita;pwd=moumita;driver={Oracle in oracleHome9i}"
    con.EstablishConnection rdDriverNoPrompt
End Sub

Private Sub Form_Unload(Cancel As Integer)
    con.Close
End Sub
