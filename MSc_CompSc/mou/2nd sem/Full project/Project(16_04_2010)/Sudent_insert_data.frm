VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Insert information into student database"
   ClientHeight    =   8340
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8130
   LinkTopic       =   "Form1"
   ScaleHeight     =   8340
   ScaleWidth      =   8130
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox Text8 
      Height          =   315
      Left            =   1920
      TabIndex        =   27
      Top             =   840
      Width           =   1575
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Reset"
      Height          =   400
      Left            =   3840
      TabIndex        =   26
      Top             =   7800
      Width           =   1000
   End
   Begin VB.ComboBox Combo4 
      Height          =   315
      Left            =   6000
      TabIndex        =   24
      Top             =   3720
      Width           =   855
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Home"
      Height          =   400
      Left            =   2160
      TabIndex        =   23
      Top             =   7800
      Width           =   1000
   End
   Begin VB.ComboBox Combo5 
      Height          =   315
      Left            =   1920
      TabIndex        =   22
      Top             =   5160
      Width           =   1815
   End
   Begin VB.ComboBox Combo3 
      Height          =   315
      Left            =   3360
      TabIndex        =   21
      Text            =   "YYYY"
      Top             =   3720
      Width           =   855
   End
   Begin VB.ComboBox Combo2 
      Height          =   315
      Left            =   2640
      TabIndex        =   20
      Text            =   "MM"
      Top             =   3720
      Width           =   615
   End
   Begin VB.ComboBox Combo1 
      BeginProperty DataFormat 
         Type            =   0
         Format          =   "0"
         HaveTrueFalseNull=   0
         FirstDayOfWeek  =   0
         FirstWeekOfYear =   0
         LCID            =   1033
         SubFormatType   =   0
      EndProperty
      Height          =   315
      Left            =   1920
      TabIndex        =   19
      Text            =   "DD"
      Top             =   3720
      Width           =   615
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Insert"
      Height          =   400
      Left            =   5520
      TabIndex        =   18
      Top             =   7800
      Width           =   1000
   End
   Begin VB.TextBox Text7 
      Height          =   315
      Left            =   1920
      TabIndex        =   17
      Top             =   6600
      Width           =   1600
   End
   Begin VB.TextBox Text6 
      Height          =   315
      Left            =   1920
      TabIndex        =   16
      Top             =   5880
      Width           =   6000
   End
   Begin VB.TextBox Text5 
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
      TabIndex        =   15
      Top             =   4440
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
      TabIndex        =   14
      Top             =   3000
      Width           =   1875
   End
   Begin VB.TextBox Text3 
      Height          =   315
      Left            =   1920
      TabIndex        =   13
      Top             =   3000
      Width           =   2000
   End
   Begin VB.TextBox Text1 
      Height          =   315
      Left            =   1920
      TabIndex        =   12
      Top             =   1560
      Width           =   6000
   End
   Begin VB.TextBox Text2 
      Height          =   315
      Left            =   1920
      TabIndex        =   11
      Top             =   2280
      Width           =   6000
   End
   Begin VB.Label Label11 
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
      Left            =   3480
      TabIndex        =   28
      Top             =   7320
      Width           =   60
   End
   Begin VB.Label Label10 
      Caption         =   "Student ID:-"
      Height          =   405
      Left            =   240
      TabIndex        =   25
      Top             =   840
      Width           =   1395
   End
   Begin VB.Label Label9 
      Caption         =   "Course ID:-"
      Height          =   405
      Left            =   240
      TabIndex        =   10
      Top             =   6600
      Width           =   1395
   End
   Begin VB.Label Label8 
      Caption         =   "Father's Name:-"
      Height          =   405
      Left            =   240
      TabIndex        =   9
      Top             =   5880
      Width           =   1395
   End
   Begin VB.Label Label7 
      Caption         =   "Gender:-"
      Height          =   405
      Left            =   240
      TabIndex        =   8
      Top             =   5160
      Width           =   1395
   End
   Begin VB.Label Label6 
      Caption         =   "Age:-"
      Height          =   405
      Left            =   4440
      TabIndex        =   7
      Top             =   3720
      Width           =   1395
   End
   Begin VB.Label Label5 
      Caption         =   "Date of Birth (DD/MM/YYYY):-"
      Height          =   405
      Left            =   240
      TabIndex        =   6
      Top             =   3720
      Width           =   1395
   End
   Begin VB.Label Label4 
      Caption         =   "Mobile No. :-"
      Height          =   405
      Left            =   240
      TabIndex        =   5
      Top             =   4440
      Width           =   1395
   End
   Begin VB.Label Label3 
      Caption         =   "Pin:-"
      Height          =   405
      Index           =   1
      Left            =   4440
      TabIndex        =   4
      Top             =   3000
      Width           =   1395
   End
   Begin VB.Label Label2 
      Caption         =   "City:-"
      Height          =   405
      Index           =   1
      Left            =   240
      TabIndex        =   3
      Top             =   3000
      Width           =   1395
   End
   Begin VB.Label Label3 
      Caption         =   "Address:-"
      Height          =   405
      Index           =   0
      Left            =   240
      TabIndex        =   2
      Top             =   2280
      Width           =   1395
   End
   Begin VB.Label Label2 
      Caption         =   "Name:-"
      Height          =   405
      Index           =   0
      Left            =   240
      TabIndex        =   1
      Top             =   1560
      Width           =   1395
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Insert information into student database"
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
      TabIndex        =   0
      Top             =   120
      Width           =   6975
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection
Private Sub Command1_Click()
    Form14.Show
    Unload Me
End Sub
Private Sub Command2_Click()
    Text1.Text = ""
    Text2.Text = ""
    Text3.Text = ""
    Text4.Text = ""
    Text5.Text = ""
    Text6.Text = ""
    Text7.Text = ""
    Text8.Text = ""
    Combo1.Text = "DD"
    Combo2.Text = "MM"
    Combo3.Text = "YYYY"
    Combo4.Text = ""
    Combo5.Text = ""
    Text8.SetFocus
End Sub

Private Sub Command3_Click()
    Dim Q As String
    Dim D1 As String
    If Text8.Text = "" Or Text1.Text = "" Or Text2.Text = "" Or Text3.Text = "" Or Text4.Text = "" Or Text5.Text = "" Or Text6.Text = "" Or Text7.Text = "" Or Combo1.Text = "DD" Or Combo2.Text = "MM" Or Combo3.Text = "YYYY" Or Combo4.Text = "" Or Combo5 = "" Then
        Label11.Caption = "SOME FIELDS ARE EMPTY"
    Else
        Label11.Caption = ""
        D1 = Combo1.Text + "/" + Combo2.Text + "/" + Combo3.Text
        Q = "INSERT INTO STUDENT(S_ID,S_NAME,S_ADDRESS,S_CITY,S_PIN,S_DOB,S_AGE,S_MOBILE,S_GENDER,S_FNAME,S_C_ID) VALUES ('" + Text8.Text + "','" + Text1.Text + "','" + Text2.Text + "','" + Text3.Text + "'," + Text4.Text + ",TO_DATE('" + D1 + "','DD/MM/YYYY')," + Combo4.Text + "," + Text5.Text + ",'" + Combo5.Text + "','" + Text6.Text + "','" + Text7.Text + "');"
        con.Execute Q
        Text1.Text = ""
        Text2.Text = ""
        Text3.Text = ""
        Text4.Text = ""
        Text5.Text = ""
        Text6.Text = ""
        Text7.Text = ""
        Text8.Text = ""
        Combo1.Text = "DD"
        Combo2.Text = "MM"
        Combo3.Text = "YYYY"
        Combo4.Text = ""
        Combo5.Text = ""
        Text8.SetFocus
    End If
End Sub

Private Sub Form_Load()
    con.Connect = "uid=admin;pwd=admin;driver={Oracle in OraHome92}"
    con.EstablishConnection rdDriverNoPrompt
    Dim i As Integer
    i = 0
    Do Until i = 31
        i = i + 1
        Combo1.AddItem i
    Loop
    i = 0
    Do Until i = 12
        i = i + 1
        Combo2.AddItem i
    Loop
    i = 1979
    Do Until i = 2000
        i = i + 1
        Combo3.AddItem i
    Loop
    Combo5.AddItem "Male"
    Combo5.AddItem "Female"
    i = 16
    Do Until i = 30
        i = i + 1
        Combo4.AddItem i
    Loop
    'Text1.SetFocus
End Sub


Private Sub Form_Unload(Cancel As Integer)
    con.Close
End Sub
