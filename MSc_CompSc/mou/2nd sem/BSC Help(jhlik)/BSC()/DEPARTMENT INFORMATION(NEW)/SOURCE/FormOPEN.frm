VERSION 5.00
Begin VB.Form FormOPEN 
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   Picture         =   "FormOPEN.frx":0000
   ScaleHeight     =   11115
   ScaleWidth      =   15240
   StartUpPosition =   3  'Windows Default
   WindowState     =   2  'Maximized
   Begin VB.TextBox T2 
      Height          =   495
      Left            =   9000
      TabIndex        =   19
      Top             =   5520
      Width           =   1215
   End
   Begin VB.TextBox T1 
      Height          =   495
      Left            =   9000
      TabIndex        =   18
      Top             =   4680
      Width           =   1215
   End
   Begin VB.CommandButton CMDOK 
      Caption         =   "CHANGE"
      Height          =   495
      Left            =   8040
      TabIndex        =   17
      Top             =   8880
      Width           =   1455
   End
   Begin VB.OptionButton OPTPWD 
      BackColor       =   &H00FFC0C0&
      Caption         =   "PASSWORD"
      BeginProperty Font 
         Name            =   "Perpetua"
         Size            =   18
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   8760
      TabIndex        =   16
      Top             =   8160
      Width           =   2175
   End
   Begin VB.OptionButton OPTID 
      BackColor       =   &H00FFC0C0&
      Caption         =   "ID"
      BeginProperty Font 
         Name            =   "Palatino Linotype"
         Size            =   15.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   7200
      TabIndex        =   15
      Top             =   8160
      Width           =   1215
   End
   Begin VB.CommandButton CMDED 
      Caption         =   "EDIT"
      Height          =   615
      Left            =   7920
      TabIndex        =   14
      Top             =   7440
      Width           =   1575
   End
   Begin VB.Timer Timer6 
      Interval        =   500
      Left            =   120
      Top             =   4200
   End
   Begin VB.Timer Timer5 
      Interval        =   500
      Left            =   840
      Top             =   4560
   End
   Begin VB.Timer Timer4 
      Interval        =   300
      Left            =   480
      Top             =   4200
   End
   Begin VB.Timer Timer3 
      Interval        =   300
      Left            =   840
      Top             =   4200
   End
   Begin VB.Timer Timer2 
      Interval        =   1000
      Left            =   480
      Top             =   4560
   End
   Begin VB.Timer Timer1 
      Interval        =   1000
      Left            =   120
      Top             =   4560
   End
   Begin VB.CommandButton CMDET 
      Caption         =   "EXIT"
      Height          =   495
      Left            =   9840
      TabIndex        =   7
      Top             =   10200
      Width           =   1215
   End
   Begin VB.CommandButton CMDSUB 
      Caption         =   "SUBMIT"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   24
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1095
      Left            =   3240
      TabIndex        =   6
      Top             =   7920
      Width           =   2535
   End
   Begin VB.CommandButton CMDCL 
      Caption         =   "CANCEL"
      Height          =   495
      Left            =   8640
      TabIndex        =   5
      Top             =   10200
      Width           =   1215
   End
   Begin VB.CommandButton CMDADD 
      Caption         =   "START"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1455
      Left            =   10320
      TabIndex        =   4
      Top             =   5160
      Width           =   1695
   End
   Begin VB.TextBox TPWD 
      Height          =   615
      IMEMode         =   3  'DISABLE
      Left            =   5520
      PasswordChar    =   "*"
      TabIndex        =   1
      Top             =   6240
      Width           =   2295
   End
   Begin VB.TextBox TID 
      Height          =   615
      Left            =   5520
      TabIndex        =   0
      Top             =   4560
      Width           =   2295
   End
   Begin VB.Label Label1 
      BackStyle       =   0  'Transparent
      Caption         =   "WELCOME TO OUR PROJECT FOR  DEPARTMENTAL INFORMATION SYTEM"
      BeginProperty Font 
         Name            =   "Times New Roman"
         Size            =   18
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000040C0&
      Height          =   735
      Left            =   1680
      TabIndex        =   13
      Top             =   2160
      Width           =   9735
   End
   Begin VB.Label Label6 
      BackStyle       =   0  'Transparent
      Caption         =   "DEPARTMENT : COMPUTER SCIENCE"
      BeginProperty Font 
         Name            =   "Niagara Engraved"
         Size            =   36
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   2760
      TabIndex        =   12
      Top             =   1080
      Width           =   8655
   End
   Begin VB.Label Label5 
      BackStyle       =   0  'Transparent
      Caption         =   "10,RAJA NABAKRISHNA STREET, KOLKATA :700015"
      BeginProperty Font 
         Name            =   "Times New Roman"
         Size            =   18
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Left            =   2040
      TabIndex        =   11
      Top             =   600
      Width           =   9015
   End
   Begin VB.Label Label4 
      BackColor       =   &H00FFFF00&
      BackStyle       =   0  'Transparent
      Caption         =   "S.A.JAIPURIA COLLEGE"
      BeginProperty Font 
         Name            =   "Times New Roman"
         Size            =   21.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   3000
      TabIndex        =   10
      Top             =   120
      Width           =   7455
   End
   Begin VB.Label Label3 
      BackStyle       =   0  'Transparent
      Caption         =   "ENTER CORRECT USER-ID AND PASWORD"
      BeginProperty Font 
         Name            =   "Times New Roman"
         Size            =   20.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF00FF&
      Height          =   495
      Left            =   1680
      TabIndex        =   9
      Top             =   3600
      Width           =   9495
   End
   Begin VB.Label Label2 
      Caption         =   "Label2"
      Height          =   375
      Left            =   600
      TabIndex        =   8
      Top             =   3120
      Width           =   1575
   End
   Begin VB.Label LPWD 
      BackStyle       =   0  'Transparent
      Caption         =   "PASSWORD"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   615
      Left            =   2760
      TabIndex        =   3
      Top             =   6360
      Width           =   2175
   End
   Begin VB.Label LID 
      BackStyle       =   0  'Transparent
      Caption         =   "USER-ID"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   615
      Left            =   2880
      TabIndex        =   2
      Top             =   4680
      Width           =   1815
   End
End
Attribute VB_Name = "FormOPEN"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim A, B As String
Dim nID, npwd As String
Option Compare Text
Dim cn As ADODB.Connection
Dim rs3 As ADODB.Recordset
Private Sub CMDADD_Click()
TID.Enabled = True
TPWD.Enabled = True
TID.SetFocus
A = TID.Text
B = TPWD.Text
End Sub

Private Sub CMDCL_Click()
TID.Text = ""
TPWD.Text = ""
End Sub

Private Sub CMDED_Click()
OPTID.Visible = True
OPTPWD.Visible = True
Cmdok.Visible = True
End Sub

Private Sub CMDET_Click()
Unload Me
End Sub

Private Sub CMDOK_Click()
rs3("ID") = TID.Text
rs3("PWD") = TPWD.Text
TID.Enabled = True
TPWD.Enabled = True
MsgBox "SUCESSFULLY UPDATED"
 rs3.Update
TID.Text = " "
TPWD.Text = " "
 OPTID.Visible = False
 OPTPWD.Visible = False
 Cmdok.Visible = False
 OPTID = False
 OPTID = False
End Sub

Private Sub CMDSUB_Click()
Dim S1, S2 As String
S1 = TID.Text
S2 = TPWD.Text
If (T1.Text = TID.Text) Then
   MsgBox "userid accepted"
  Else
  MsgBox "PLEASE ENTER CORRECT id"
    TID.Text = ""
    TID.SetFocus
End If
If (T2.Text = TPWD.Text) Then
      MsgBox "password accepted"
 Else
  MsgBox "PLEASE ENTER CORRECT  PASSWORD"
    TPWD.Text = ""
    TPWD.SetFocus
  End If
 If ((T1.Text = TID.Text) And (T2.Text = TPWD.Text)) Then
  Formmenu.Show
   End If
End Sub

Private Sub Form_Load()
Set rs3 = New ADODB.Recordset
Set cn = New ADODB.Connection
Set cmd = New ADODB.Command
cn.Open "dsn=project;uid=scott;pwd=tiger"
rs3.Open "OPEN", cn, adOpenDynamic, adLockOptimistic
Label2.Visible = False
T1.Visible = False
T2.Visible = False
T1.Text = rs3("ID")
T2.Text = rs3("PWD")
TID.Enabled = False
TPWD.Enabled = False
OPTID.Visible = False
OPTPWD.Visible = False
Cmdok.Visible = False
End Sub


Private Sub OPTID_Click()
If OPTID = True Then
        nID = InputBox("Insert CURRENT ID")
        rs3.Find "ID='" & nID & "' "
        TID.Text = nID
        TPWD.Text = rs3("PWD")
         edit1
 End If
End Sub

Private Sub OPTPWD_Click()
If OPTPWD = True Then
        npwd = InputBox("Insert CURRENT PASSWORD")
        rs3.Find "PWD='" & npwd & " ' "
        TPWD.Text = npwd
        TID.Text = rs3("ID")
         edit1
 End If
End Sub

Private Sub Timer1_Timer()
Dim i As Integer
i = 0
Label1.Left = 0
While Label1.Left <= Screen.Width
     While i <> 50
         i = i + 1
     Wend
    Label1.Left = Label1.Left + 1
     i = 0
   Wend
End Sub

Private Sub Timer2_Timer()
Label3.Visible = True
Label2.Visible = False
Timer3.Enabled = True
Timer2.Enabled = False
End Sub

Private Sub Timer3_Timer()
Label3.ForeColor = RGB(Rnd * 255, Rnd * 255, Rnd * 255)
Label3.Visible = True
Timer2.Enabled = True
Timer3.Enabled = False
End Sub

Private Sub Timer4_Timer()
Label4.ForeColor = RGB(Rnd * 255, Rnd * 255, Rnd * 255)
End Sub

Private Sub Timer5_Timer()
Label5.ForeColor = RGB(Rnd * 255, Rnd * 255, Rnd * 255)
End Sub

Private Sub Timer6_Timer()
Label6.ForeColor = RGB(Rnd * 255, Rnd * 255, Rnd * 255)
End Sub
Private Sub edit1()
 If MsgBox("Are you sure to edit the record?", vbQuestion + vbYesNo, App.ProductName) = vbYes Then
  If (OPTID = True) Then
    TID.Enabled = True
     TID.SetFocus
  Else
    TPWD.Enabled = True
     TPWD.SetFocus
  End If
Else
        MsgBox "perform next operation"
End If
End Sub

