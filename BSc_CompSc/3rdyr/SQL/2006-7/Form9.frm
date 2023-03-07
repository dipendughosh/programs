VERSION 5.00
Begin VB.Form Form9 
   Caption         =   "Form9"
   ClientHeight    =   6150
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6465
   LinkTopic       =   "Form9"
   ScaleHeight     =   6150
   ScaleWidth      =   6465
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox Text6 
      Height          =   855
      Left            =   3120
      TabIndex        =   14
      Top             =   4920
      Width           =   2175
   End
   Begin VB.TextBox Text5 
      Height          =   615
      Left            =   2880
      TabIndex        =   13
      Top             =   3840
      Width           =   1935
   End
   Begin VB.CommandButton Command2 
      Caption         =   "BACK"
      Height          =   735
      Left            =   5400
      TabIndex        =   10
      Top             =   2520
      Width           =   975
   End
   Begin VB.CommandButton Command1 
      Caption         =   "ADD"
      Height          =   615
      Left            =   5160
      TabIndex        =   9
      Top             =   1080
      Width           =   1095
   End
   Begin VB.TextBox Text4 
      Height          =   285
      Left            =   2880
      TabIndex        =   8
      Top             =   3240
      Width           =   1695
   End
   Begin VB.TextBox Text3 
      Height          =   285
      Left            =   2760
      TabIndex        =   7
      Top             =   2520
      Width           =   1575
   End
   Begin VB.TextBox Text2 
      Height          =   285
      Left            =   2640
      TabIndex        =   6
      Top             =   2040
      Width           =   1935
   End
   Begin VB.TextBox Text1 
      Height          =   495
      Left            =   2640
      TabIndex        =   5
      Top             =   1080
      Width           =   1935
   End
   Begin VB.Label Label7 
      Caption         =   "SHIP_DATE"
      Height          =   615
      Left            =   360
      TabIndex        =   12
      Top             =   5040
      Width           =   2175
   End
   Begin VB.Label Label6 
      Caption         =   "DESTINATION"
      Height          =   615
      Left            =   240
      TabIndex        =   11
      Top             =   3960
      Width           =   1935
   End
   Begin VB.Label Label1 
      Caption         =   "SHIPMENT"
      Height          =   615
      Left            =   2640
      TabIndex        =   4
      Top             =   120
      Width           =   1815
   End
   Begin VB.Label Label2 
      Caption         =   "SHIPMENT_NO"
      Height          =   735
      Left            =   240
      TabIndex        =   3
      Top             =   1080
      Width           =   1695
   End
   Begin VB.Label Label3 
      Caption         =   "CUST_ID"
      Height          =   375
      Left            =   120
      TabIndex        =   2
      Top             =   2040
      Width           =   2175
   End
   Begin VB.Label Label4 
      Caption         =   "WEIGHT"
      Height          =   375
      Left            =   120
      TabIndex        =   1
      Top             =   2640
      Width           =   2175
   End
   Begin VB.Label Label5 
      Caption         =   "TRUCK_NO"
      Height          =   255
      Left            =   120
      TabIndex        =   0
      Top             =   3360
      Width           =   2415
   End
End
Attribute VB_Name = "Form9"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim CON As New rdoConnection

Private Sub Command1_Click()
    Dim q As String
    q = "INSERT INTO SHIPMENT(SHIPMENT_NO,CUST_ID,WEIGHT,TRUCK_NO,DESTINATION,SHIP_DATE) VALUES(" + Text1.Text + ",'" + Text2.Text + "'," + Text3.Text + ",'" + Text4.Text + "','" + Text5.Text + "',TO_DATE('" + Text6.Text + "','DD/MM/YYYY'));"
    CON.Execute q
    Text1.Text = ""
    Text2.Text = ""
    Text3.Text = ""
    Text4.Text = ""
    Text5.Text = ""
    Text6.Text = ""
    Text1.SetFocus
    
    
End Sub

Private Sub Command2_Click()
    Hide
    Form3.Show
    
End Sub

Private Sub Form_Load()
    CON.Connect = "uid=dipendu06;pwd=dipendu;Driver={Oracle in oracleHome9i}"
    CON.EstablishConnection rdoDriverNoPrompt
    
End Sub

Private Sub Form_Unload(Cancel As Integer)
    CON.Close
    
End Sub

