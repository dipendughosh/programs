VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   4665
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6120
   LinkTopic       =   "Form1"
   ScaleHeight     =   4665
   ScaleWidth      =   6120
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command4 
      Caption         =   "INSRT INTO RESERV"
      Height          =   375
      Left            =   2160
      TabIndex        =   7
      Top             =   2040
      Width           =   2415
   End
   Begin VB.CommandButton Command3 
      Caption         =   "INSRT INTO BOATS1"
      Height          =   375
      Left            =   2160
      TabIndex        =   6
      Top             =   1320
      Width           =   2415
   End
   Begin VB.CommandButton Command2 
      Caption         =   "INSERT INTO SAILOR"
      Height          =   495
      Left            =   2280
      TabIndex        =   5
      Top             =   600
      Width           =   2415
   End
   Begin VB.CommandButton Command1 
      Caption         =   "EXIT"
      Height          =   495
      Left            =   1080
      TabIndex        =   3
      Top             =   2880
      Width           =   1935
   End
   Begin VB.Label Label7 
      AutoSize        =   -1  'True
      Caption         =   "MAIN FORM"
      Height          =   195
      Left            =   1680
      TabIndex        =   4
      Top             =   240
      Width           =   915
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "RESERVES:"
      Height          =   555
      Left            =   240
      TabIndex        =   2
      Top             =   2040
      Width           =   915
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "BOATS:"
      Height          =   435
      Left            =   360
      TabIndex        =   1
      Top             =   1320
      Width           =   585
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "SAILOR:"
      Height          =   315
      Left            =   240
      TabIndex        =   0
      Top             =   600
      Width           =   630
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection
Private Sub Command1_Click()
    Unload Form2
    Unload Form3
    Unload Form4
    Unload Me
    
End Sub
Private Sub Command2_Click()
    Form2.Show
    Hide
End Sub

Private Sub Command3_Click()
    Form3.Show
    Hide
End Sub

Private Sub Command4_Click()
    Form4.Show
    Hide
End Sub

Private Sub Form_Load()
    con.Connect = "uid=scott;pwd=tiger;driver={Oracle in oracle9i1}"
    con.EstablishConnection rdDriverNoPrompt
End Sub

Private Sub Form_Unload(Cancel As Integer)
    con.Close
End Sub

