VERSION 5.00
Begin VB.Form Form4 
   Caption         =   "Insert information into instructor database"
   ClientHeight    =   8130
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8130
   LinkTopic       =   "Form4"
   ScaleHeight     =   8130
   ScaleWidth      =   8130
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox Text8 
      Height          =   315
      Left            =   1920
      TabIndex        =   31
      Top             =   840
      Width           =   1575
   End
   Begin VB.ComboBox Combo8 
      Height          =   315
      Left            =   7200
      TabIndex        =   30
      Text            =   "YYYY"
      Top             =   6600
      Width           =   855
   End
   Begin VB.ComboBox Combo7 
      Height          =   315
      Left            =   6480
      TabIndex        =   29
      Text            =   "MM"
      Top             =   6600
      Width           =   615
   End
   Begin VB.ComboBox Combo6 
      Height          =   315
      Left            =   5760
      TabIndex        =   28
      Text            =   "DD"
      Top             =   6600
      Width           =   615
   End
   Begin VB.TextBox Text2 
      Height          =   315
      Left            =   1920
      TabIndex        =   14
      Top             =   2280
      Width           =   6000
   End
   Begin VB.TextBox Text1 
      Height          =   315
      Left            =   1920
      TabIndex        =   13
      Top             =   1560
      Width           =   6000
   End
   Begin VB.TextBox Text3 
      Height          =   315
      Left            =   1920
      TabIndex        =   12
      Top             =   3000
      Width           =   2000
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
      TabIndex        =   11
      Top             =   3000
      Width           =   1875
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
      TabIndex        =   10
      Top             =   4440
      Width           =   2475
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
      Left            =   1920
      TabIndex        =   9
      Top             =   5880
      Width           =   1800
   End
   Begin VB.TextBox Text7 
      Height          =   315
      Left            =   1920
      TabIndex        =   8
      Top             =   6600
      Width           =   1965
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Reset"
      Height          =   400
      Left            =   3600
      TabIndex        =   7
      Top             =   7560
      Width           =   1000
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Insert"
      Height          =   400
      Left            =   5280
      TabIndex        =   6
      Top             =   7560
      Width           =   1000
   End
   Begin VB.ComboBox Combo1 
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
      TabIndex        =   5
      Text            =   "DD"
      Top             =   3720
      Width           =   615
   End
   Begin VB.ComboBox Combo2 
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
      Left            =   2640
      TabIndex        =   4
      Text            =   "MM"
      Top             =   3720
      Width           =   615
   End
   Begin VB.ComboBox Combo3 
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
      Left            =   3360
      TabIndex        =   3
      Text            =   "YYYY"
      Top             =   3720
      Width           =   855
   End
   Begin VB.ComboBox Combo5 
      Height          =   315
      Left            =   1920
      TabIndex        =   2
      Top             =   5160
      Width           =   1815
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Home"
      Height          =   400
      Left            =   1920
      TabIndex        =   1
      Top             =   7560
      Width           =   1000
   End
   Begin VB.ComboBox Combo4 
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
      TabIndex        =   0
      Top             =   3720
      Width           =   855
   End
   Begin VB.Label Label12 
      Caption         =   "Date of Joining (DD/MM/YYYY):-"
      Height          =   405
      Left            =   4080
      TabIndex        =   27
      Top             =   6600
      Width           =   1395
   End
   Begin VB.Label Label10 
      Caption         =   "Instructor ID:-"
      Height          =   405
      Left            =   240
      TabIndex        =   26
      Top             =   840
      Width           =   1395
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Insert information into instructor database"
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
      TabIndex        =   25
      Top             =   120
      Width           =   6975
   End
   Begin VB.Label Label2 
      Caption         =   "Name:-"
      Height          =   405
      Index           =   0
      Left            =   240
      TabIndex        =   24
      Top             =   1560
      Width           =   1395
   End
   Begin VB.Label Label3 
      Caption         =   "Address:-"
      Height          =   405
      Index           =   0
      Left            =   240
      TabIndex        =   23
      Top             =   2280
      Width           =   1395
   End
   Begin VB.Label Label2 
      Caption         =   "City:-"
      Height          =   405
      Index           =   1
      Left            =   240
      TabIndex        =   22
      Top             =   3000
      Width           =   1395
   End
   Begin VB.Label Label3 
      Caption         =   "Pin:-"
      Height          =   405
      Index           =   1
      Left            =   4440
      TabIndex        =   21
      Top             =   3000
      Width           =   1395
   End
   Begin VB.Label Label4 
      Caption         =   "Mobile No. :-"
      Height          =   405
      Left            =   240
      TabIndex        =   20
      Top             =   4440
      Width           =   1395
   End
   Begin VB.Label Label5 
      Caption         =   "Date of Birth (DD/MM/YYYY):-"
      Height          =   405
      Left            =   240
      TabIndex        =   19
      Top             =   3720
      Width           =   1395
   End
   Begin VB.Label Label6 
      Caption         =   "Age:-"
      Height          =   405
      Left            =   4440
      TabIndex        =   18
      Top             =   3720
      Width           =   1395
   End
   Begin VB.Label Label7 
      Caption         =   "Gender:-"
      Height          =   405
      Left            =   240
      TabIndex        =   17
      Top             =   5160
      Width           =   1395
   End
   Begin VB.Label Label8 
      Caption         =   "Salary:-"
      Height          =   405
      Left            =   240
      TabIndex        =   16
      Top             =   5880
      Width           =   1395
   End
   Begin VB.Label Label9 
      Caption         =   "Qualification:-"
      Height          =   405
      Left            =   240
      TabIndex        =   15
      Top             =   6600
      Width           =   1395
   End
End
Attribute VB_Name = "Form4"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection
Dim rs As rdoResultset
Dim rs1 As rdoResultset
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
    Combo6.Text = "DD"
    Combo7.Text = "MM"
    Combo8.Text = "YYYY"
    Text8.SetFocus
End Sub

Private Sub Command3_Click()
    Dim Q As String
    Dim D1 As String
    Dim D2 As String
    Dim N As Integer
    Dim I As Integer
    Dim TEMP As String
    Dim FLAG1 As Integer
    FLAG1 = 0
    Set rs = con.OpenResultset("SELECT COUNT(*) AS C FROM INSTRUCTOR;", rdOpenStatic)
    N = rs.rdoColumns("C")
    rs.Close
    Set rs1 = con.OpenResultset("SELECT I_ID FROM INSTRUCTOR;", rdOpenStatic)
    For I = 1 To N
        TEMP = rs1.rdoColumns("I_ID")
        If Text8.Text = TEMP Then
            FLAG1 = 1
        End If
        rs1.MoveNext
    Next I
    rs1.Close
    If Text8.Text = "" Or Text1.Text = "" Or Text2.Text = "" Or Text3.Text = "" Or Text4.Text = "" Or Text5.Text = "" Or Text6.Text = "" Or Text7.Text = "" Or Combo1.Text = "DD" Or Combo2.Text = "MM" Or Combo3.Text = "YYYY" Or Combo4.Text = "" Or Combo5 = "" Or Combo6.Text = "DD" Or Combo7.Text = "MM" Or Combo8.Text = "YYYY" Then
        MsgBox ("Some FIELDS are EMPTY")
    ElseIf FLAG1 = 1 Then
        MsgBox ("InstructorID provided EXITS")
    Else
        D1 = Combo1.Text + "/" + Combo2.Text + "/" + Combo3.Text
        D2 = Combo6.Text + "/" + Combo7.Text + "/" + Combo8.Text
        Q = "INSERT INTO INSTRUCTOR(I_ID,I_NAME,I_ADDRESS,I_CITY,I_PIN,I_DOB,I_AGE,I_MOBILE,I_GENDER,I_SALARY,I_QUALIFICATION,I_DOJ) VALUES ('" + Text8.Text + "','" + Text1.Text + "','" + Text2.Text + "','" + Text3.Text + "'," + Text4.Text + ",TO_DATE('" + D1 + "','DD/MM/YYYY')," + Combo4.Text + "," + Text5.Text + ",'" + Combo5.Text + "'," + Text6.Text + ",'" + Text7.Text + "',TO_DATE('" + D2 + "','DD/MM/YYYY'));"
        con.Execute Q
        MsgBox ("Successfully Entered into Database")
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
        Combo6.Text = "DD"
        Combo7.Text = "MM"
        Combo8.Text = "YYYY"
        Text8.SetFocus
    End If
End Sub

Private Sub Form_Load()
    con.Connect = "uid=admin;pwd=admin;driver={Oracle in OraHome92}"
    con.EstablishConnection rdDriverNoPrompt
    Dim I As Integer
    I = 0
    Do Until I = 31
        I = I + 1
        Combo1.AddItem I
    Loop
    I = 0
    Do Until I = 12
        I = I + 1
        Combo2.AddItem I
    Loop
    I = 1940
    Do Until I = 1990
        I = I + 1
        Combo3.AddItem I
    Loop
    Combo5.AddItem "Male"
    Combo5.AddItem "Female"
    I = 24
    Do Until I = 65
        I = I + 1
        Combo4.AddItem I
    Loop
    I = 0
    Do Until I = 31
        I = I + 1
        Combo6.AddItem I
    Loop
    I = 0
    Do Until I = 12
        I = I + 1
        Combo7.AddItem I
    Loop
    I = 1975
    Do Until I = 2010
        I = I + 1
        Combo8.AddItem I
    Loop
End Sub

Private Sub Form_Unload(Cancel As Integer)
    con.Close
End Sub

