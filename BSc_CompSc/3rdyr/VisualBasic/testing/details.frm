VERSION 5.00
Begin VB.Form details 
   Caption         =   "details"
   ClientHeight    =   3360
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4830
   LinkTopic       =   "Form3"
   ScaleHeight     =   3360
   ScaleWidth      =   4830
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2 
      Caption         =   "close"
      Height          =   615
      Left            =   1080
      TabIndex        =   1
      Top             =   2040
      Width           =   1695
   End
   Begin VB.CommandButton Command1 
      Caption         =   "return"
      Height          =   855
      Left            =   1080
      TabIndex        =   0
      Top             =   720
      Width           =   2055
   End
End
Attribute VB_Name = "details"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub Command1_Click()
    details.Hide
    main.Show
End Sub

Private Sub Command2_Click()
    Unload Me
End Sub


Private Sub Form_Load()

End Sub


