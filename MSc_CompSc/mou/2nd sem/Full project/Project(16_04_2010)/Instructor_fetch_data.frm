VERSION 5.00
Begin VB.Form Form5 
   Caption         =   "Fetch information from instructor database"
   ClientHeight    =   7995
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8130
   LinkTopic       =   "Form5"
   ScaleHeight     =   7995
   ScaleWidth      =   8130
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "Home"
      Height          =   400
      Left            =   1080
      TabIndex        =   4
      Top             =   7440
      Width           =   1000
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Update"
      Height          =   400
      Left            =   4440
      TabIndex        =   3
      Top             =   7440
      Width           =   1000
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Reset"
      Height          =   400
      Left            =   2760
      TabIndex        =   2
      Top             =   7440
      Width           =   1000
   End
   Begin VB.TextBox Text1 
      Height          =   315
      Left            =   2040
      TabIndex        =   1
      Top             =   1080
      Width           =   1695
   End
   Begin VB.CommandButton Command4 
      Caption         =   "Search"
      Height          =   400
      Left            =   6120
      TabIndex        =   0
      Top             =   7440
      Width           =   1000
   End
   Begin VB.Label Label23 
      AutoSize        =   -1  'True
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000080&
      Height          =   300
      Left            =   4320
      TabIndex        =   29
      Top             =   5640
      Width           =   60
   End
   Begin VB.Label Label9 
      Caption         =   "Qualification:-"
      Height          =   405
      Left            =   240
      TabIndex        =   28
      Top             =   6840
      Width           =   1395
   End
   Begin VB.Label Label8 
      Caption         =   "Salary:-"
      Height          =   405
      Left            =   240
      TabIndex        =   27
      Top             =   6120
      Width           =   1395
   End
   Begin VB.Label Label7 
      Caption         =   "Gender:-"
      Height          =   405
      Left            =   240
      TabIndex        =   26
      Top             =   5400
      Width           =   1395
   End
   Begin VB.Label Label6 
      Caption         =   "Age:-"
      Height          =   405
      Left            =   4440
      TabIndex        =   25
      Top             =   3960
      Width           =   1395
   End
   Begin VB.Label Label5 
      Caption         =   "Date of Birth (DD/MM/YYYY):-"
      Height          =   405
      Left            =   240
      TabIndex        =   24
      Top             =   3960
      Width           =   1395
   End
   Begin VB.Label Label4 
      Caption         =   "Mobile No. :-"
      Height          =   405
      Left            =   240
      TabIndex        =   23
      Top             =   4680
      Width           =   1395
   End
   Begin VB.Label Label3 
      Caption         =   "Pin:-"
      Height          =   405
      Index           =   1
      Left            =   4440
      TabIndex        =   22
      Top             =   3240
      Width           =   1395
   End
   Begin VB.Label Label2 
      Caption         =   "City:-"
      Height          =   405
      Index           =   1
      Left            =   240
      TabIndex        =   21
      Top             =   3240
      Width           =   1395
   End
   Begin VB.Label Label3 
      Caption         =   "Address:-"
      Height          =   405
      Index           =   0
      Left            =   240
      TabIndex        =   20
      Top             =   2520
      Width           =   1395
   End
   Begin VB.Label Label2 
      Caption         =   "Name:-"
      Height          =   405
      Index           =   0
      Left            =   240
      TabIndex        =   19
      Top             =   1800
      Width           =   1395
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "View information from instructor database"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   600
      TabIndex        =   18
      Top             =   240
      Width           =   6975
   End
   Begin VB.Label Label10 
      Caption         =   "Instructor ID:-"
      Height          =   405
      Left            =   240
      TabIndex        =   17
      Top             =   1080
      Width           =   1395
   End
   Begin VB.Label Label11 
      Height          =   315
      Left            =   1920
      TabIndex        =   16
      Top             =   1800
      Width           =   6000
   End
   Begin VB.Label Label12 
      Height          =   315
      Left            =   1920
      TabIndex        =   15
      Top             =   2520
      Width           =   6000
   End
   Begin VB.Label Label13 
      Height          =   315
      Left            =   1920
      TabIndex        =   14
      Top             =   3360
      Width           =   1995
   End
   Begin VB.Label Label14 
      BeginProperty DataFormat 
         Type            =   1
         Format          =   "0"
         HaveTrueFalseNull=   0
         FirstDayOfWeek  =   0
         FirstWeekOfYear =   0
         LCID            =   1033
         SubFormatType   =   1
      EndProperty
      Height          =   315
      Left            =   6120
      TabIndex        =   13
      Top             =   3240
      Width           =   1875
   End
   Begin VB.Label Label15 
      Height          =   315
      Left            =   1920
      TabIndex        =   12
      Top             =   3960
      Width           =   1875
   End
   Begin VB.Label Label16 
      BeginProperty DataFormat 
         Type            =   1
         Format          =   "0"
         HaveTrueFalseNull=   0
         FirstDayOfWeek  =   0
         FirstWeekOfYear =   0
         LCID            =   1033
         SubFormatType   =   1
      EndProperty
      Height          =   315
      Left            =   6000
      TabIndex        =   11
      Top             =   3960
      Width           =   1005
   End
   Begin VB.Label Label17 
      BeginProperty DataFormat 
         Type            =   1
         Format          =   "0"
         HaveTrueFalseNull=   0
         FirstDayOfWeek  =   0
         FirstWeekOfYear =   0
         LCID            =   1033
         SubFormatType   =   1
      EndProperty
      Height          =   315
      Left            =   1920
      TabIndex        =   10
      Top             =   4680
      Width           =   1995
   End
   Begin VB.Label Label18 
      Height          =   315
      Left            =   1920
      TabIndex        =   9
      Top             =   5400
      Width           =   1500
   End
   Begin VB.Label Label19 
      BeginProperty DataFormat 
         Type            =   1
         Format          =   "0"
         HaveTrueFalseNull=   0
         FirstDayOfWeek  =   0
         FirstWeekOfYear =   0
         LCID            =   1033
         SubFormatType   =   1
      EndProperty
      Height          =   315
      Left            =   1920
      TabIndex        =   8
      Top             =   6120
      Width           =   1800
   End
   Begin VB.Label Label20 
      Height          =   315
      Left            =   1920
      TabIndex        =   7
      Top             =   6840
      Width           =   1605
   End
   Begin VB.Label Label21 
      Height          =   315
      Left            =   5280
      TabIndex        =   6
      Top             =   6840
      Width           =   2505
   End
   Begin VB.Label Label22 
      Caption         =   "Date of Joining (DD/MM/YYYY):-"
      Height          =   405
      Left            =   3720
      TabIndex        =   5
      Top             =   6840
      Width           =   1395
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
    Form14.Show
    Unload Me
End Sub

Private Sub Command2_Click()
    Text1.Text = ""
    Label11.Caption = ""
    Label12.Caption = ""
    Label13.Caption = ""
    Label14.Caption = ""
    Label15.Caption = ""
    Label16.Caption = ""
    Label17.Caption = ""
    Label18.Caption = ""
    Label19.Caption = ""
    Label20.Caption = ""
    Label21.Caption = ""
    Text1.SetFocus
    Label23.Caption = ""
End Sub

Private Sub Command3_Click()
    If Text1.Text = "" Then
        Label23.Caption = "ENTER ID"
    ElseIf Label11.Caption = "" Then
        Label23.Caption = "Click on search button"
    Else
        Label23.Caption = ""
        Form6.Show
        Hide
    End If
End Sub

Private Sub Command4_Click()
    If Text1.Text = "" Then
        Label23.Caption = "ENTER ID"
    Else
        Label23.Caption = ""
        Set rs = con.OpenResultset("SELECT * FROM INSTRUCTOR WHERE I_ID = '" + Text1.Text + "';", rdOpenStatic)
        Label11.Caption = rs.rdoColumns("I_NAME")
        Label12.Caption = rs.rdoColumns("I_ADDRESS")
        Label13.Caption = rs.rdoColumns("I_CITY")
        Label14.Caption = rs.rdoColumns("I_PIN")
        Label15.Caption = rs.rdoColumns("I_DOB")
        Label16.Caption = rs.rdoColumns("I_AGE")
        Label17.Caption = rs.rdoColumns("I_MOBILE")
        Label18.Caption = rs.rdoColumns("I_GENDER")
        Label19.Caption = rs.rdoColumns("I_SALARY")
        Label20.Caption = rs.rdoColumns("I_QUALIFICATION")
        Label21.Caption = rs.rdoColumns("I_DOJ")
        rs.Close
    End If
End Sub

Private Sub Form_Load()
    con.Connect = "uid=admin;pwd=admin;driver={Oracle in OraHome92}"
    con.EstablishConnection rdDriverNoPrompt
End Sub

Private Sub Form_Unload(Cancel As Integer)
    con.Close
End Sub

