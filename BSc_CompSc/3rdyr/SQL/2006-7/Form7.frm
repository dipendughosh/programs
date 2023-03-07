VERSION 5.00
Begin VB.Form Form7 
   Caption         =   "Form7"
   ClientHeight    =   5040
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   7350
   LinkTopic       =   "Form7"
   ScaleHeight     =   5040
   ScaleWidth      =   7350
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command3 
      Caption         =   "back"
      Height          =   735
      Left            =   3840
      TabIndex        =   7
      Top             =   4080
      Width           =   1335
   End
   Begin VB.CommandButton Command1 
      Caption         =   "next"
      Height          =   615
      Left            =   5400
      TabIndex        =   1
      Top             =   1800
      Width           =   1095
   End
   Begin VB.CommandButton Command2 
      Caption         =   "previous"
      Height          =   735
      Left            =   5640
      TabIndex        =   0
      Top             =   3240
      Width           =   975
   End
   Begin VB.Label Label5 
      Height          =   735
      Left            =   2880
      TabIndex        =   6
      Top             =   2760
      Width           =   1815
   End
   Begin VB.Label Label4 
      Height          =   495
      Left            =   2760
      TabIndex        =   5
      Top             =   1800
      Width           =   1455
   End
   Begin VB.Label Label3 
      Caption         =   "POPULATION"
      Height          =   375
      Left            =   360
      TabIndex        =   4
      Top             =   2760
      Width           =   2175
   End
   Begin VB.Label Label2 
      Caption         =   "CITY_NAME"
      Height          =   735
      Left            =   480
      TabIndex        =   3
      Top             =   1800
      Width           =   1695
   End
   Begin VB.Label Label1 
      Caption         =   "CITY"
      Height          =   615
      Left            =   2880
      TabIndex        =   2
      Top             =   840
      Width           =   1815
   End
End
Attribute VB_Name = "Form7"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection
Dim rs As rdoResultset

Private Sub Command1_Click()
    rs.MoveNext
    If rs.EOF = True Then
        rs.MoveFirst
    End If
    Label4.Caption = rs.rdoColumns("CITY_NAME")
    Label5.Caption = rs.rdoColumns("POPULATION")
End Sub

Private Sub Command2_Click()
    rs.MovePrevious
    If rs.BOF = True Then
        rs.MoveLast
    End If
    Label4.Caption = rs.rdoColumns("CITY_NAME")
    Label5.Caption = rs.rdoColumns("POPULATION")
End Sub

Private Sub Command3_Click()
    Hide
    Form3.Show
    
    
End Sub

Private Sub Form_Load()
    con.Connect = "uid=dipendu06;pwd=dipendu;Driver={Oracle in oracleHome9i}"
    con.EstablishConnection rdoDriverNoPrompt
    Set rs = con.OpenResultset("select * from city", rdOpenStatic)
    Label4.Caption = rs.rdoColumns("CITY_NAME")
    Label5.Caption = rs.rdoColumns("POPULATION")
    
    
    
    
End Sub

Private Sub Form_Unload(Cancel As Integer)
    rs.Close
    con.Close

    
End Sub


