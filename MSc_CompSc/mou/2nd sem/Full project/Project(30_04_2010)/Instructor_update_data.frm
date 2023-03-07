VERSION 5.00
Begin VB.Form Form6 
   Caption         =   "Update information into instructor database"
   ClientHeight    =   8610
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8100
   LinkTopic       =   "Form6"
   ScaleHeight     =   8610
   ScaleWidth      =   8100
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox Text13 
      Height          =   315
      Left            =   1920
      TabIndex        =   30
      Top             =   3840
      Width           =   2115
   End
   Begin VB.TextBox Text12 
      Height          =   315
      Left            =   6000
      TabIndex        =   29
      Top             =   3840
      Width           =   1935
   End
   Begin VB.CommandButton Command4 
      Caption         =   "Back"
      Height          =   400
      Left            =   6120
      TabIndex        =   28
      Top             =   8160
      Width           =   1000
   End
   Begin VB.TextBox Text11 
      BeginProperty DataFormat 
         Type            =   1
         Format          =   "M/d/yyyy"
         HaveTrueFalseNull=   0
         FirstDayOfWeek  =   0
         FirstWeekOfYear =   0
         LCID            =   1033
         SubFormatType   =   3
      EndProperty
      Height          =   315
      Left            =   5760
      TabIndex        =   27
      Top             =   7440
      Width           =   2000
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Home"
      Height          =   400
      Left            =   1080
      TabIndex        =   12
      Top             =   8160
      Width           =   1000
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Update"
      Height          =   400
      Left            =   4440
      TabIndex        =   11
      Top             =   8160
      Width           =   1000
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Reset"
      Height          =   400
      Left            =   2760
      TabIndex        =   10
      Top             =   8160
      Width           =   1000
   End
   Begin VB.TextBox Text10 
      Height          =   315
      Left            =   1920
      TabIndex        =   9
      Top             =   7440
      Width           =   1965
   End
   Begin VB.TextBox Text9 
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
      Top             =   6720
      Width           =   1800
   End
   Begin VB.TextBox Text7 
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
      TabIndex        =   7
      Top             =   5280
      Width           =   2475
   End
   Begin VB.TextBox Text4 
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
      TabIndex        =   6
      Top             =   3120
      Width           =   1875
   End
   Begin VB.TextBox Text3 
      Height          =   315
      Left            =   1920
      TabIndex        =   5
      Top             =   3120
      Width           =   2000
   End
   Begin VB.TextBox Text1 
      Height          =   315
      Left            =   1920
      TabIndex        =   4
      Top             =   1680
      Width           =   6000
   End
   Begin VB.TextBox Text2 
      Height          =   315
      Left            =   1920
      TabIndex        =   3
      Top             =   2400
      Width           =   6000
   End
   Begin VB.TextBox Text5 
      BeginProperty DataFormat 
         Type            =   1
         Format          =   "M/d/yyyy"
         HaveTrueFalseNull=   0
         FirstDayOfWeek  =   0
         FirstWeekOfYear =   0
         LCID            =   1033
         SubFormatType   =   3
      EndProperty
      Height          =   315
      Left            =   1920
      TabIndex        =   2
      Top             =   4560
      Width           =   2000
   End
   Begin VB.TextBox Text6 
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
      TabIndex        =   1
      Top             =   4560
      Width           =   800
   End
   Begin VB.TextBox Text8 
      Height          =   315
      Left            =   1920
      TabIndex        =   0
      Top             =   6000
      Width           =   1500
   End
   Begin VB.Label Label16 
      Caption         =   "State:-"
      Height          =   405
      Left            =   240
      TabIndex        =   32
      Top             =   3840
      Width           =   1395
   End
   Begin VB.Label Label17 
      Caption         =   "Police Station:-"
      Height          =   405
      Left            =   4440
      TabIndex        =   31
      Top             =   3840
      Width           =   1395
   End
   Begin VB.Label Label12 
      Caption         =   "Date of Joining (MM/DD/YYYY):-"
      Height          =   405
      Left            =   4080
      TabIndex        =   26
      Top             =   7440
      Width           =   1395
   End
   Begin VB.Label Label9 
      Caption         =   "Qualification:-"
      Height          =   405
      Left            =   240
      TabIndex        =   25
      Top             =   7440
      Width           =   1395
   End
   Begin VB.Label Label8 
      Caption         =   "Salary:-"
      Height          =   405
      Left            =   240
      TabIndex        =   24
      Top             =   6720
      Width           =   1395
   End
   Begin VB.Label Label7 
      Caption         =   "Gender:-"
      Height          =   405
      Left            =   240
      TabIndex        =   23
      Top             =   6000
      Width           =   1395
   End
   Begin VB.Label Label6 
      Caption         =   "Age:-"
      Height          =   405
      Left            =   4440
      TabIndex        =   22
      Top             =   4560
      Width           =   1395
   End
   Begin VB.Label Label5 
      Caption         =   "Date of Birth (MM/DD/YYYY):-"
      Height          =   405
      Left            =   240
      TabIndex        =   21
      Top             =   4560
      Width           =   1395
   End
   Begin VB.Label Label4 
      Caption         =   "Mobile No. :-"
      Height          =   405
      Left            =   240
      TabIndex        =   20
      Top             =   5280
      Width           =   1395
   End
   Begin VB.Label Label3 
      Caption         =   "Pin:-"
      Height          =   405
      Index           =   1
      Left            =   4440
      TabIndex        =   19
      Top             =   3120
      Width           =   1395
   End
   Begin VB.Label Label2 
      Caption         =   "City:-"
      Height          =   405
      Index           =   1
      Left            =   240
      TabIndex        =   18
      Top             =   3120
      Width           =   1395
   End
   Begin VB.Label Label3 
      Caption         =   "Address:-"
      Height          =   405
      Index           =   0
      Left            =   240
      TabIndex        =   17
      Top             =   2400
      Width           =   1395
   End
   Begin VB.Label Label2 
      Caption         =   "Name:-"
      Height          =   405
      Index           =   0
      Left            =   240
      TabIndex        =   16
      Top             =   1680
      Width           =   1395
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Update information into instructor database"
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
      TabIndex        =   15
      Top             =   240
      Width           =   6975
   End
   Begin VB.Label Label10 
      Caption         =   "Instructor ID:-"
      Height          =   405
      Left            =   240
      TabIndex        =   14
      Top             =   960
      Width           =   1395
   End
   Begin VB.Label Label11 
      Height          =   315
      Left            =   1920
      TabIndex        =   13
      Top             =   960
      Width           =   1500
   End
End
Attribute VB_Name = "Form6"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection
Dim temp1 As String
Dim temp2 As String
Dim temp3 As String
Dim temp4 As String
Dim temp5 As String
Dim temp6 As String
Dim temp7 As String
Dim temp8 As String
Dim temp9 As String
Dim temp10 As String
Dim temp11 As String
Dim temp12 As String
Dim temp13 As String
Private Sub Command1_Click()
    Form14.Show
    Unload Form5
    Unload Me
End Sub

Private Sub Command2_Click()
    Text1.Text = temp1
    Text2.Text = temp2
    Text3.Text = temp3
    Text4.Text = temp4
    Text5.Text = temp5
    Text6.Text = temp6
    Text7.Text = temp7
    Text8.Text = temp8
    Text9.Text = temp9
    Text10.Text = temp10
    Text11.Text = temp11
    Text12.Text = temp13
    Text13.Text = temp12
    Text1.SetFocus
End Sub

Private Sub Command3_Click()
    Dim q As String
    q = "UPDATE INSTRUCTOR SET I_NAME = '" + Text1.Text + "',I_ADDRESS = '" + Text2.Text + "',I_CITY = '" + Text3.Text + "',I_PIN = " + Text4.Text + ",I_DOB = TO_DATE('" + Text5.Text + "','MM/DD/YYYY'),I_AGE = " + Text6.Text + ",I_MOBILE = " + Text7.Text + ",I_GENDER = '" + Text8.Text + "',I_SALARY = " + Text9.Text + ",I_QUALIFICATION = '" + Text10.Text + "',I_DOJ = TO_DATE('" + Text11.Text + "','MM/DD/YYYY'),I_STATE = '" + Text13.Text + "',I_POLICE = '" + Text12.Text + "' WHERE I_ID = '" + Label11.Caption + "';"
    con.Execute q
    MsgBox ("Successfully Updated into Database")
    Form5.Text1.Text = ""
    Form5.Label11.Caption = ""
    Form5.Label12.Caption = ""
    Form5.Label13.Caption = ""
    Form5.Label14.Caption = ""
    Form5.Label15.Caption = ""
    Form5.Label16.Caption = ""
    Form5.Label17.Caption = ""
    Form5.Label18.Caption = ""
    Form5.Label19.Caption = ""
    Form5.Label20.Caption = ""
    Form5.Label21.Caption = ""
    Form5.Label27.Caption = ""
    Form5.Label28.Caption = ""
    Form5.Show
    Unload Me
End Sub

Private Sub Command4_Click()
    Form5.Text1.Text = ""
    Form5.Label11.Caption = ""
    Form5.Label12.Caption = ""
    Form5.Label13.Caption = ""
    Form5.Label14.Caption = ""
    Form5.Label15.Caption = ""
    Form5.Label16.Caption = ""
    Form5.Label17.Caption = ""
    Form5.Label18.Caption = ""
    Form5.Label19.Caption = ""
    Form5.Label20.Caption = ""
    Form5.Label21.Caption = ""
    Form5.Label27.Caption = ""
    Form5.Label28.Caption = ""
    Form5.Show
    Unload Me
End Sub

Private Sub Form_Load()
    con.Connect = "uid=admin;pwd=admin;driver={Oracle in OraHome92}"
    con.EstablishConnection rdDriverNoPrompt
    Label11.Caption = Form5.Text1.Text
    Text1.Text = Form5.Label11.Caption
    Text2.Text = Form5.Label12.Caption
    Text3.Text = Form5.Label13.Caption
    Text4.Text = Form5.Label14.Caption
    Text5.Text = Form5.Label15.Caption
    Text6.Text = Form5.Label16.Caption
    Text7.Text = Form5.Label17.Caption
    Text8.Text = Form5.Label18.Caption
    Text9.Text = Form5.Label19.Caption
    Text10.Text = Form5.Label20.Caption
    Text11.Text = Form5.Label21.Caption
    Text12.Text = Form5.Label28.Caption
    Text13.Text = Form5.Label27.Caption
    temp1 = Form5.Label11.Caption
    temp2 = Form5.Label12.Caption
    temp3 = Form5.Label13.Caption
    temp4 = Form5.Label14.Caption
    temp5 = Form5.Label15.Caption
    temp6 = Form5.Label16.Caption
    temp7 = Form5.Label17.Caption
    temp8 = Form5.Label18.Caption
    temp9 = Form5.Label19.Caption
    temp10 = Form5.Label20.Caption
    temp11 = Form5.Label21.Caption
    temp12 = Form5.Label27.Caption
    temp13 = Form5.Label28.Caption
End Sub

Private Sub Form_Unload(Cancel As Integer)
    con.Close
End Sub
