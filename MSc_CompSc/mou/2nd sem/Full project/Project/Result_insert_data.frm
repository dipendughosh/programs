VERSION 5.00
Begin VB.Form Form10 
   Caption         =   "Insert information into result database"
   ClientHeight    =   8295
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8130
   LinkTopic       =   "Form10"
   ScaleHeight     =   8295
   ScaleWidth      =   8130
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command4 
      Caption         =   "Check"
      Height          =   400
      Left            =   6120
      TabIndex        =   15
      Top             =   7560
      Width           =   1000
   End
   Begin VB.TextBox Text2 
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
      Top             =   3240
      Width           =   2000
   End
   Begin VB.TextBox Text1 
      Height          =   315
      Left            =   1920
      TabIndex        =   4
      Top             =   1320
      Width           =   1920
   End
   Begin VB.TextBox Text3 
      Height          =   315
      Left            =   1920
      TabIndex        =   3
      Top             =   5160
      Width           =   1600
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Reset"
      Height          =   400
      Left            =   2760
      TabIndex        =   2
      Top             =   7560
      Width           =   1000
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Insert"
      Height          =   400
      Left            =   4440
      TabIndex        =   1
      Top             =   7560
      Width           =   1000
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Home"
      Height          =   400
      Left            =   1080
      TabIndex        =   0
      Top             =   7560
      Width           =   1000
   End
   Begin VB.Label Label7 
      Height          =   315
      Left            =   1920
      TabIndex        =   18
      Top             =   4320
      Width           =   1335
   End
   Begin VB.Label Label6 
      AutoSize        =   -1  'True
      BeginProperty Font 
         Name            =   "MV Boli"
         Size            =   15.75
         Charset         =   1
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00008000&
      Height          =   360
      Left            =   1800
      TabIndex        =   17
      Top             =   6960
      Width           =   150
   End
   Begin VB.Label Label5 
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
      Left            =   2520
      TabIndex        =   16
      Top             =   6600
      Width           =   60
   End
   Begin VB.Label Label13 
      Height          =   315
      Left            =   1920
      TabIndex        =   14
      Top             =   6120
      Width           =   6000
   End
   Begin VB.Label Label4 
      Caption         =   "Course Name:-"
      Height          =   405
      Left            =   240
      TabIndex        =   13
      Top             =   6120
      Width           =   1395
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Insert information into result database"
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
      TabIndex        =   12
      Top             =   360
      Width           =   6975
   End
   Begin VB.Label Label2 
      Caption         =   "Name:-"
      Height          =   405
      Index           =   0
      Left            =   240
      TabIndex        =   11
      Top             =   2280
      Width           =   1395
   End
   Begin VB.Label Label3 
      Caption         =   "Marks:-"
      Height          =   405
      Index           =   0
      Left            =   240
      TabIndex        =   10
      Top             =   3240
      Width           =   1395
   End
   Begin VB.Label Label2 
      Caption         =   "Grade:-"
      Height          =   405
      Index           =   1
      Left            =   240
      TabIndex        =   9
      Top             =   4200
      Width           =   1395
   End
   Begin VB.Label Label9 
      Caption         =   "Course ID:-"
      Height          =   405
      Left            =   240
      TabIndex        =   8
      Top             =   5160
      Width           =   1395
   End
   Begin VB.Label Label10 
      Caption         =   "Student ID:-"
      Height          =   405
      Left            =   240
      TabIndex        =   7
      Top             =   1320
      Width           =   1395
   End
   Begin VB.Label Label11 
      Height          =   315
      Left            =   1920
      TabIndex        =   6
      Top             =   2280
      Width           =   6000
   End
End
Attribute VB_Name = "Form10"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection
Dim rs1 As rdoResultset
Dim rs2 As rdoResultset
Private Sub Command1_Click()
    Form14.Show
    'Hide
    Unload Me
End Sub

Private Sub Command2_Click()
    Text1.Text = ""
    Text2.Text = ""
    Text3.Text = ""
    Label11.Caption = ""
    Label7.Caption = ""
    Label13.Caption = ""
    Label6.Caption = ""
    Text1.SetFocus
End Sub

Private Sub Command3_Click()
    Dim Q As String
    If Text1.Text = "" Or Text2.Text = "" Or Text3.Text = "" Then
        Label6.Caption = "SOME FIELDS ARE EMPTY"
    ElseIf Label11.Caption = "" Or Label7.Caption = "" Or Label13.Caption = "" Then
        Label6.Caption = "CLICK ON CHECK THEN ON INSERT"
    Else
        Label6.Caption = ""
        Q = "INSERT INTO RESULT(R_S_ID,R_S_NAME,R_MARKS,R_GRADE,R_C_ID) VALUES ('" + Text1.Text + "','" + Label11.Caption + "'," + Text2.Text + ",'" + Label7.Caption + "','" + Text3.Text + "');"
        con.Execute Q
        Text1.Text = ""
        Text2.Text = ""
        Text3.Text = ""
        Label11.Caption = ""
        Label7.Caption = ""
        Label13.Caption = ""
        Text1.SetFocus
    End If
End Sub

Private Sub Command4_Click()
    If Text1.Text = "" Or Text2.Text = "" Or Text3.Text = "" Then
        Label6.Caption = "SOME FIELDS ARE EMPTY"
    Else
        Label6.Caption = ""
        Set rs1 = con.OpenResultset("SELECT * FROM STUDENT WHERE S_ID = '" + Text1.Text + "';", rdOpenStatic)
        Label11.Caption = rs1.rdoColumns("S_NAME")
        Set rs2 = con.OpenResultset("SELECT * FROM COURSE WHERE C_ID = '" + Text3.Text + "';", rdOpenStatic)
        Label13.Caption = rs2.rdoColumns("C_TITLE")
    End If
    If Text2.Text >= "90" Then
        Label7.Caption = "A+"
    ElseIf Text2.Text >= "80" And Text2.Text < "90" Then
        Label7.Caption = "A"
    ElseIf Text2.Text >= "70" And Text2.Text < "80" Then
        Label7.Caption = "B"
    ElseIf Text2.Text >= "60" And Text2.Text < "70" Then
        Label7.Caption = "C"
    ElseIf Text2.Text >= "50" And Text2.Text < "60" Then
        Label7.Caption = "D"
    ElseIf Text2.Text >= "40" And Text2.Text < "50" Then
        Label7.Caption = "E"
    ElseIf Text2.Text < "40" Then
        Label7.Caption = "F"
    End If
End Sub

Private Sub Form_Load()
    con.Connect = "uid=admin;pwd=admin;driver={Oracle in OraHome92}"
    con.EstablishConnection rdDriverNoPrompt
    'Text1.SetFocus
End Sub
Private Sub Form_Unload(Cancel As Integer)
    rs1.Close
    rs2.Close
    con.Close
End Sub
