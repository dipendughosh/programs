VERSION 5.00
Begin VB.Form Form15 
   Caption         =   "Log In"
   ClientHeight    =   7995
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8130
   LinkTopic       =   "Form15"
   ScaleHeight     =   7995
   ScaleWidth      =   8130
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command3 
      Caption         =   "Exit"
      Height          =   600
      Left            =   5400
      TabIndex        =   9
      Top             =   6360
      Width           =   1000
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Cancel"
      Height          =   600
      Left            =   3360
      TabIndex        =   7
      Top             =   6360
      Width           =   1000
   End
   Begin VB.CommandButton Command1 
      Caption         =   "OK"
      Height          =   600
      Left            =   1320
      TabIndex        =   5
      Top             =   6360
      Width           =   1000
   End
   Begin VB.TextBox Text2 
      Height          =   375
      IMEMode         =   3  'DISABLE
      Left            =   3120
      PasswordChar    =   "*"
      TabIndex        =   4
      Top             =   4440
      Width           =   2535
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   3120
      TabIndex        =   3
      Top             =   3120
      Width           =   2535
   End
   Begin VB.Label Label5 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      BeginProperty Font 
         Name            =   "MS Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFC0FF&
      Height          =   315
      Left            =   3960
      TabIndex        =   8
      Top             =   5760
      Width           =   60
   End
   Begin VB.Label Label4 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      BeginProperty Font 
         Name            =   "MS Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFC0FF&
      Height          =   315
      Left            =   3930
      TabIndex        =   6
      Top             =   5160
      Width           =   75
   End
   Begin VB.Label Label3 
      Alignment       =   2  'Center
      Caption         =   "Password:-"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   960
      TabIndex        =   2
      Top             =   4440
      Width           =   1815
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      Caption         =   "User ID :-"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   1080
      TabIndex        =   1
      Top             =   3120
      Width           =   1575
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Administrator Log In"
      BeginProperty Font 
         Name            =   "Modern"
         Size            =   26.25
         Charset         =   255
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   840
      TabIndex        =   0
      Top             =   1080
      Width           =   6495
   End
End
Attribute VB_Name = "Form15"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    Dim i As Long
    Dim j As Long
    If Text1.Text = "admin" And Text2.Text = "admin" Then
    'If Text1.Text = "" And Text2.Text = "" Then
        'Label4.Caption = "Success"
       ' Label5.Caption = "Wait....."
        'For i = 1 To 10000
        '    For j = 1 To 10000
         '   Next j
        'Next i
        'Text1.Text = ""
        'Text2.Text = ""
        'Text1.SetFocus
        'Label4.Caption = ""
        'Label5.Caption = ""
        'Hide
        MsgBox ("Log IN Successfull")
        Form14.Show
        Unload Me
    ElseIf Text1.Text = "ADMIN" And Text2.Text = "ADMIN" Then
        'Label4.Caption = "Success"
        'Label5.Caption = "Wait....."
        'For i = 1 To 10000
         '   For j = 1 To 10000
          '  Next j
       ' Next i
        'Form14.Show
        'Text1.Text = ""
        'Text2.Text = ""
        'Text1.SetFocus
        'Label4.Caption = ""
        'Label5.Caption = ""
        'Hide
        MsgBox ("Log IN Successfull")
        Form14.Show
        Unload Me
    Else
        'Label4.Caption = "Wrong Username or Password"
        'Label5.Caption = "Re-Enter Username and Password"
        MsgBox ("Wrong Username or Password")
        MsgBox ("Re-Enter Username and Password")
        Text1.Text = ""
        Text2.Text = ""
        Text1.SetFocus
    End If
End Sub

Private Sub Command2_Click()
    Text1.Text = ""
    Text2.Text = ""
    Text1.SetFocus
    Label4.Caption = ""
    Label5.Caption = ""
End Sub


Private Sub Command3_Click()
    Close
    Unload Form1
    Unload Form2
    Unload Form3
    Unload Form4
    Unload Form5
    Unload Form6
    Unload Form7
    Unload Form8
    Unload Form9
    Unload Form10
    Unload Form11
    Unload Form12
    Unload Form13
    Unload Form14
    Unload Me
End Sub

Private Sub Form_Load()
    'Text1.SetFocus
End Sub

