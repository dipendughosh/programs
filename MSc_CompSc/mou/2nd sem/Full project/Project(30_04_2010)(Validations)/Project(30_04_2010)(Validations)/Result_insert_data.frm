VERSION 5.00
Begin VB.Form Form10 
   Caption         =   "Insert information into result database"
   ClientHeight    =   8490
   ClientLeft      =   165
   ClientTop       =   555
   ClientWidth     =   8100
   LinkTopic       =   "Form10"
   Picture         =   "Result_insert_data.frx":0000
   ScaleHeight     =   8490
   ScaleWidth      =   8100
   StartUpPosition =   3  'Windows Default
   WindowState     =   2  'Maximized
   Begin VB.CommandButton Command4 
      Caption         =   "Check"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   400
      Left            =   6120
      TabIndex        =   14
      Top             =   7560
      Width           =   1000
   End
   Begin VB.TextBox Text2 
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
      TabIndex        =   4
      Top             =   3240
      Width           =   2000
   End
   Begin VB.TextBox Text1 
      Height          =   315
      Left            =   1920
      TabIndex        =   3
      Top             =   1320
      Width           =   1920
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Reset"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   400
      Left            =   2760
      TabIndex        =   2
      Top             =   7560
      Width           =   1000
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Insert"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   400
      Left            =   4440
      TabIndex        =   1
      Top             =   7560
      Width           =   1000
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Home"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   400
      Left            =   1080
      TabIndex        =   0
      Top             =   7560
      Width           =   1000
   End
   Begin VB.Label Label5 
      Height          =   315
      Left            =   1920
      TabIndex        =   16
      Top             =   5160
      Width           =   1455
   End
   Begin VB.Label Label7 
      Height          =   315
      Left            =   1920
      TabIndex        =   15
      Top             =   4320
      Width           =   1335
   End
   Begin VB.Label Label13 
      Height          =   315
      Left            =   1920
      TabIndex        =   13
      Top             =   6120
      Width           =   6000
   End
   Begin VB.Label Label4 
      BackColor       =   &H80000014&
      Caption         =   "Course Name:-"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   405
      Left            =   240
      TabIndex        =   12
      Top             =   6120
      Width           =   1395
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      BackColor       =   &H80000014&
      Caption         =   "INSERT INFORMATION INTO RESULT DATABASE"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   975
      Left            =   600
      TabIndex        =   11
      Top             =   120
      Width           =   6975
   End
   Begin VB.Label Label2 
      BackColor       =   &H80000014&
      Caption         =   "Name:-"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   405
      Index           =   0
      Left            =   240
      TabIndex        =   10
      Top             =   2280
      Width           =   1395
   End
   Begin VB.Label Label3 
      BackColor       =   &H80000014&
      Caption         =   "Marks:-"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   405
      Index           =   0
      Left            =   240
      TabIndex        =   9
      Top             =   3240
      Width           =   1395
   End
   Begin VB.Label Label2 
      BackColor       =   &H80000014&
      Caption         =   "Grade:-"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   405
      Index           =   1
      Left            =   240
      TabIndex        =   8
      Top             =   4200
      Width           =   1395
   End
   Begin VB.Label Label9 
      BackColor       =   &H80000014&
      Caption         =   "Course ID:-"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   405
      Left            =   240
      TabIndex        =   7
      Top             =   5160
      Width           =   1395
   End
   Begin VB.Label Label10 
      BackColor       =   &H80000014&
      Caption         =   "Student ID:-"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   405
      Left            =   240
      TabIndex        =   6
      Top             =   1320
      Width           =   1395
   End
   Begin VB.Label Label11 
      Height          =   315
      Left            =   1920
      TabIndex        =   5
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
    Unload Me
End Sub

Private Sub Command2_Click()
    Text1.Text = ""
    Text2.Text = ""
    Label5.Caption = ""
    Label11.Caption = ""
    Label7.Caption = ""
    Label13.Caption = ""
    Text1.SetFocus
End Sub

Private Sub Command3_Click()
    Dim q As String
    Dim i As Integer
    Dim FLAGM As Integer
    Dim X As String
    If Text1.Text = "" Or Text2.Text = "" Then
        MsgBox ("Some FIELDS are EMPTY")
    Else
        FLAGM = 0
        If Len(Text2.Text) > 0 Then
            For i = 1 To Len(Text2.Text)
                X = Mid(Text2.Text, i, 1)
                If Not X Like "[0-9]" Then
                    FLAGM = 1
                End If
            Next i
        End If
        If FLAGM = 1 Then
            MsgBox ("MARKS has characters")
        End If
        If Label11.Caption = "" Or Label7.Caption = "" Or Label13.Caption = "" Then
            MsgBox ("Click on CHECK then on INSERT")
        ElseIf FLAGM = 0 Then
            q = "INSERT INTO RESULT(R_S_ID,R_S_NAME,R_MARKS,R_GRADE,R_C_ID) VALUES ('" + Text1.Text + "','" + Label11.Caption + "'," + Text2.Text + ",'" + Label7.Caption + "','" + Label5.Caption + "');"
            con.Execute q
            MsgBox ("Successfully Entered into Database")
            Text1.Text = ""
            Text2.Text = ""
            Label5.Caption = ""
            Label11.Caption = ""
            Label7.Caption = ""
            Label13.Caption = ""
            Text1.SetFocus
        End If
    End If
End Sub

Private Sub Command4_Click()
    Dim i As Integer
    Dim FLAGM As Integer
    Dim X As String
    If Text1.Text = "" Or Text2.Text = "" Then
        MsgBox ("Some FIELDS are EMPTY")
    Else
        FLAGM = 0
        Set rs1 = con.OpenResultset("SELECT * FROM STUDENT WHERE S_ID = '" + Text1.Text + "';", rdOpenStatic)
        Label11.Caption = rs1.rdoColumns("S_NAME")
        Label5.Caption = rs1.rdoColumns("S_C_ID")
        Set rs2 = con.OpenResultset("SELECT * FROM COURSE WHERE C_ID = '" + Label5.Caption + "';", rdOpenStatic)
        Label13.Caption = rs2.rdoColumns("C_TITLE")
        rs1.Close
        rs2.Close
        If Len(Text2.Text) > 0 Then
            For i = 1 To Len(Text2.Text)
                X = Mid(Text2.Text, i, 1)
                If Not X Like "[0-9]" Then
                    FLAGM = 1
                End If
            Next i
        End If
        If FLAGM = 1 Then
            MsgBox ("MARKS has characters")
        Else
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
        End If
    End If
End Sub

Private Sub Form_Load()
    con.Connect = "uid=scott;pwd=tiger;driver={Oracle in OraHome92}"
    con.EstablishConnection rdDriverNoPrompt
End Sub
Private Sub Form_Unload(Cancel As Integer)
    con.Close
End Sub

