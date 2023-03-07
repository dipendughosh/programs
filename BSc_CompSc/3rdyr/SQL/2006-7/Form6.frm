VERSION 5.00
Begin VB.Form Form6 
   Caption         =   "Form6"
   ClientHeight    =   5490
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   7395
   LinkTopic       =   "Form6"
   ScaleHeight     =   5490
   ScaleWidth      =   7395
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command3 
      Caption         =   "back"
      Height          =   735
      Left            =   3960
      TabIndex        =   7
      Top             =   4200
      Width           =   975
   End
   Begin VB.CommandButton Command1 
      Caption         =   "next"
      Height          =   615
      Left            =   5160
      TabIndex        =   1
      Top             =   1680
      Width           =   1095
   End
   Begin VB.CommandButton Command2 
      Caption         =   "previous"
      Height          =   735
      Left            =   5400
      TabIndex        =   0
      Top             =   3120
      Width           =   975
   End
   Begin VB.Label Label5 
      Height          =   495
      Left            =   2760
      TabIndex        =   6
      Top             =   2640
      Width           =   1935
   End
   Begin VB.Label Label4 
      Height          =   615
      Left            =   2640
      TabIndex        =   5
      Top             =   1680
      Width           =   1815
   End
   Begin VB.Label Label3 
      Caption         =   "DRIVER_NAME"
      Height          =   375
      Left            =   120
      TabIndex        =   4
      Top             =   2640
      Width           =   2175
   End
   Begin VB.Label Label2 
      Caption         =   "TRUCK_NO"
      Height          =   735
      Left            =   240
      TabIndex        =   3
      Top             =   1680
      Width           =   1695
   End
   Begin VB.Label Label1 
      Caption         =   "TRUCK"
      Height          =   615
      Left            =   2640
      TabIndex        =   2
      Top             =   720
      Width           =   1815
   End
End
Attribute VB_Name = "Form6"
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
    Label4.Caption = rs.rdoColumns("TRUCK_NO")
    Label5.Caption = rs.rdoColumns("DRIVER_NAME")
End Sub

Private Sub Command2_Click()
    rs.MovePrevious
    If rs.BOF = True Then
        rs.MoveLast
    End If
    Label4.Caption = rs.rdoColumns("TRUCK_NO")
    Label5.Caption = rs.rdoColumns("DRIVER_NAME")
End Sub

Private Sub Command3_Click()
    Hide
    Form3.Show
    
    
End Sub

Private Sub Form_Load()
    con.Connect = "uid=dipendu06;pwd=dipendu;Driver={Oracle in oracleHome9i}"
    con.EstablishConnection rdoDriverNoPrompt
    Set rs = con.OpenResultset("select * from truck", rdOpenStatic)
    Label4.Caption = rs.rdoColumns("TRUCK_NO")
    Label5.Caption = rs.rdoColumns("DRIVER_NAME")
    
    
    
    
End Sub

Private Sub Form_Unload(Cancel As Integer)
    rs.Close
    con.Close

    
End Sub

