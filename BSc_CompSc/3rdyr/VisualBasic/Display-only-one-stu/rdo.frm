VERSION 5.00
Begin VB.Form Form1 
   ClientHeight    =   4905
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4695
   LinkTopic       =   "Form1"
   ScaleHeight     =   4905
   ScaleWidth      =   4695
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "Connect"
      Height          =   735
      Left            =   720
      TabIndex        =   6
      Top             =   2760
      Width           =   1815
   End
   Begin VB.Label Label6 
      Height          =   255
      Left            =   2040
      TabIndex        =   5
      Top             =   1920
      Width           =   1215
   End
   Begin VB.Label Label5 
      Height          =   255
      Left            =   2040
      TabIndex        =   4
      Top             =   1080
      Width           =   1215
   End
   Begin VB.Label Label4 
      Height          =   255
      Left            =   2040
      TabIndex        =   3
      Top             =   240
      Width           =   1215
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "Marks:-"
      Height          =   195
      Left            =   360
      TabIndex        =   2
      Top             =   1920
      Width           =   525
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "Name:-"
      Height          =   195
      Left            =   360
      TabIndex        =   1
      Top             =   1080
      Width           =   510
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "Roll:-"
      Height          =   195
      Index           =   0
      Left            =   360
      TabIndex        =   0
      Top             =   240
      Width           =   360
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    Dim con As New rdoConnection
    Dim rs As rdoResultset
    con.Connect = "uid=scott;pwd=tiger;Driver={Oracle in oracleHome9i}"
    con.EstablishConnection rdDriverNoPrompt
    Set rs = con.OpenResultset("SELECT * FROM STU", rdOpenStatic)
    Label4.Caption = rs.rdoColumns("ROLL")
    Label5.Caption = rs.rdoColumns("NAME")
    Label6.Caption = rs.rdoColumns("MARKS")
    rs.Close
    con.Close
End Sub

