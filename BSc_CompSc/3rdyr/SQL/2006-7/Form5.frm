VERSION 5.00
Begin VB.Form Form5 
   Caption         =   "Form5"
   ClientHeight    =   6810
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8190
   LinkTopic       =   "Form5"
   ScaleHeight     =   6810
   ScaleWidth      =   8190
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command3 
      Caption         =   "back"
      Height          =   615
      Left            =   6000
      TabIndex        =   15
      Top             =   3840
      Width           =   1575
   End
   Begin VB.CommandButton Command2 
      Caption         =   "previous"
      Height          =   495
      Left            =   5880
      TabIndex        =   14
      Top             =   2880
      Width           =   1455
   End
   Begin VB.CommandButton Command1 
      Caption         =   "next"
      Height          =   615
      Left            =   5880
      TabIndex        =   13
      Top             =   1800
      Width           =   1575
   End
   Begin VB.Label Label13 
      Height          =   615
      Left            =   3360
      TabIndex        =   12
      Top             =   5640
      Width           =   2415
   End
   Begin VB.Label Label12 
      Height          =   615
      Left            =   3240
      TabIndex        =   11
      Top             =   4560
      Width           =   2295
   End
   Begin VB.Label Label11 
      Height          =   255
      Left            =   3240
      TabIndex        =   10
      Top             =   3840
      Width           =   2175
   End
   Begin VB.Label Label10 
      Height          =   375
      Left            =   3120
      TabIndex        =   9
      Top             =   3240
      Width           =   2175
   End
   Begin VB.Label Label9 
      Height          =   495
      Left            =   3120
      TabIndex        =   8
      Top             =   2520
      Width           =   2055
   End
   Begin VB.Label Label8 
      Height          =   615
      Left            =   3120
      TabIndex        =   7
      Top             =   1560
      Width           =   1815
   End
   Begin VB.Label Label5 
      Caption         =   "TRUCK_NO"
      Height          =   255
      Left            =   600
      TabIndex        =   6
      Top             =   3840
      Width           =   2415
   End
   Begin VB.Label Label4 
      Caption         =   "WEIGHT"
      Height          =   375
      Left            =   600
      TabIndex        =   5
      Top             =   3120
      Width           =   2175
   End
   Begin VB.Label Label3 
      Caption         =   "CUST_ID"
      Height          =   375
      Left            =   600
      TabIndex        =   4
      Top             =   2520
      Width           =   2175
   End
   Begin VB.Label Label2 
      Caption         =   "SHIPMENT_NO"
      Height          =   735
      Left            =   720
      TabIndex        =   3
      Top             =   1560
      Width           =   1695
   End
   Begin VB.Label Label1 
      Caption         =   "SHIPMENT"
      Height          =   615
      Left            =   3120
      TabIndex        =   2
      Top             =   600
      Width           =   1815
   End
   Begin VB.Label Label6 
      Caption         =   "DESTINATION"
      Height          =   615
      Left            =   720
      TabIndex        =   1
      Top             =   4440
      Width           =   1935
   End
   Begin VB.Label Label7 
      Caption         =   "SHIP_DATE"
      Height          =   615
      Left            =   840
      TabIndex        =   0
      Top             =   5520
      Width           =   2175
   End
End
Attribute VB_Name = "Form5"
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
    Label8.Caption = rs.rdoColumns("SHIPMENT_NO")
    Label9.Caption = rs.rdoColumns("CUST_ID")
    Label10.Caption = rs.rdoColumns("WEIGHT")
    Label11.Caption = rs.rdoColumns("TRUCK_NO")
    Label12.Caption = rs.rdoColumns("DESTINATION")
    Label13.Caption = rs.rdoColumns("SHIP_DATE")
    
End Sub

Private Sub Command2_Click()
    rs.MovePrevious
    If rs.BOF = True Then
        rs.MoveLast
    End If
    Label8.Caption = rs.rdoColumns("SHIPMENT_NO")
    Label9.Caption = rs.rdoColumns("CUST_ID")
    Label10.Caption = rs.rdoColumns("WEIGHT")
    Label11.Caption = rs.rdoColumns("TRUCK_NO")
    Label12.Caption = rs.rdoColumns("DESTINATION")
    Label13.Caption = rs.rdoColumns("SHIP_DATE")
    
End Sub

Private Sub Command3_Click()
    Hide
    Form3.Show
    
    
End Sub

Private Sub Form_Load()
    con.Connect = "uid=dipendu06;pwd=dipendu;Driver={Oracle in oracleHome9i}"
    con.EstablishConnection rdoDriverNoPrompt
    Set rs = con.OpenResultset("select * from shipment", rdOpenStatic)
    Label8.Caption = rs.rdoColumns("SHIPMENT_NO")
    Label9.Caption = rs.rdoColumns("CUST_ID")
    Label10.Caption = rs.rdoColumns("WEIGHT")
    Label11.Caption = rs.rdoColumns("TRUCK_NO")
    Label12.Caption = rs.rdoColumns("DESTINATION")
    Label13.Caption = rs.rdoColumns("SHIP_DATE")
    
    
    
End Sub

Private Sub Form_Unload(Cancel As Integer)
    rs.Close
    con.Close

    
End Sub

