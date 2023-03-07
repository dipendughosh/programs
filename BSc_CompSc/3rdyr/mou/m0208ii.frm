VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3420
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   5250
   LinkTopic       =   "Form1"
   ScaleHeight     =   3420
   ScaleWidth      =   5250
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command4 
      Caption         =   "EXIT"
      Height          =   495
      Left            =   3720
      TabIndex        =   7
      Top             =   1320
      Width           =   1335
   End
   Begin VB.CommandButton Command3 
      Caption         =   "INSERT INTO WORKS1"
      Height          =   495
      Left            =   1440
      TabIndex        =   6
      Top             =   2160
      Width           =   1815
   End
   Begin VB.CommandButton Command2 
      Caption         =   "INSERT INTO DEPT1"
      Height          =   375
      Left            =   1320
      TabIndex        =   5
      Top             =   1440
      Width           =   1935
   End
   Begin VB.CommandButton Command1 
      Caption         =   "INSERT INTO EMP1"
      Height          =   375
      Left            =   1440
      TabIndex        =   4
      Top             =   720
      Width           =   1815
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "WORKS1"
      Height          =   195
      Left            =   240
      TabIndex        =   3
      Top             =   2280
      Width           =   705
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "DEPT1:"
      Height          =   195
      Left            =   240
      TabIndex        =   2
      Top             =   1560
      Width           =   570
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "EMP1:"
      Height          =   195
      Left            =   240
      TabIndex        =   1
      Top             =   840
      Width           =   480
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "MAIN FORM"
      Height          =   195
      Left            =   1560
      TabIndex        =   0
      Top             =   240
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
End Sub

Private Sub Form_Load()
    con.Connect = "uid=moumita;pwd=moumita;Driver={Oracle in oracle9i1}"
    con.EstablishConnection rdDriverNoPrompt
End Sub

Private Sub Form_Unload(Cancel As Integer)
    con.Close
End Sub
