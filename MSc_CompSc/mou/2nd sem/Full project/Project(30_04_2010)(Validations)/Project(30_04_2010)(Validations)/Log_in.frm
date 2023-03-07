VERSION 5.00
Begin VB.Form Form15 
   BackColor       =   &H00C0C0C0&
   Caption         =   "Log In"
   ClientHeight    =   9270
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   13140
   LinkTopic       =   "Form15"
   Picture         =   "Log_in.frx":0000
   ScaleHeight     =   9270
   ScaleWidth      =   13140
   StartUpPosition =   3  'Windows Default
   WindowState     =   2  'Maximized
   Begin VB.CommandButton Command3 
      BackColor       =   &H80000004&
      Caption         =   "Exit"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   600
      Left            =   8640
      MaskColor       =   &H00E0E0E0&
      TabIndex        =   9
      Top             =   5760
      Width           =   1000
   End
   Begin VB.CommandButton Command2 
      BackColor       =   &H80000004&
      Caption         =   "Cancel"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   600
      Left            =   6240
      MaskColor       =   &H00E0E0E0&
      TabIndex        =   7
      Top             =   5760
      Width           =   1000
   End
   Begin VB.CommandButton Command1 
      BackColor       =   &H80000004&
      Caption         =   "OK"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   600
      Left            =   3600
      MaskColor       =   &H00E0E0E0&
      TabIndex        =   5
      Top             =   5760
      Width           =   1000
   End
   Begin VB.TextBox Text2 
      BackColor       =   &H80000004&
      Height          =   375
      IMEMode         =   3  'DISABLE
      Left            =   6720
      PasswordChar    =   "X"
      TabIndex        =   4
      Top             =   3720
      Width           =   2535
   End
   Begin VB.TextBox Text1 
      BackColor       =   &H80000004&
      Height          =   375
      Left            =   6720
      TabIndex        =   3
      Top             =   2640
      Width           =   2535
   End
   Begin VB.Label Label8 
      BackColor       =   &H00FFFF00&
      Caption         =   "                                                                      COMPUTER WIZARD"
      BeginProperty Font 
         Name            =   "Arial Black"
         Size            =   18
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1335
      Left            =   2640
      TabIndex        =   12
      Top             =   480
      Width           =   7575
   End
   Begin VB.Label Label7 
      BackColor       =   &H80000009&
      Caption         =   "    PASSWORD"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Left            =   4680
      TabIndex        =   11
      Top             =   3600
      Width           =   1215
   End
   Begin VB.Label Label6 
      BackColor       =   &H80000009&
      Caption         =   " USER NAME"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Left            =   4680
      TabIndex        =   10
      Top             =   2520
      Width           =   1215
   End
   Begin VB.Image Image1 
      Height          =   18000
      Left            =   -120
      Picture         =   "Log_in.frx":12491
      Top             =   0
      Width           =   24000
   End
   Begin VB.Label Label5 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      BackColor       =   &H80000004&
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
      Left            =   3600
      TabIndex        =   8
      Top             =   5040
      Width           =   60
   End
   Begin VB.Label Label4 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      BackColor       =   &H80000004&
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
      Left            =   3570
      TabIndex        =   6
      Top             =   4440
      Width           =   75
   End
   Begin VB.Label Label3 
      Alignment       =   2  'Center
      BackColor       =   &H80000004&
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
      Left            =   1200
      TabIndex        =   2
      Top             =   3720
      Width           =   1815
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      BackColor       =   &H80000004&
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
      Left            =   1320
      TabIndex        =   1
      Top             =   2400
      Width           =   1575
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      BackColor       =   &H80000004&
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
      Left            =   240
      TabIndex        =   0
      Top             =   360
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
        MsgBox ("Log IN Successfull")
        Form14.Show
        Unload Me
    ElseIf Text1.Text = "ADMIN" And Text2.Text = "ADMIN" Then
        MsgBox ("Log IN Successfull")
        Form14.Show
        Unload Me
    Else
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


