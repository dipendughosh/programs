VERSION 5.00
Begin VB.Form Form7 
   Caption         =   "Insert information into course database"
   ClientHeight    =   8610
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8100
   LinkTopic       =   "Form7"
   ScaleHeight     =   8610
   ScaleWidth      =   8100
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox Text5 
      Height          =   315
      Left            =   1920
      TabIndex        =   13
      Top             =   1800
      Width           =   1575
   End
   Begin VB.TextBox Text4 
      Height          =   315
      Left            =   1920
      TabIndex        =   12
      Top             =   5640
      Width           =   1815
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
      TabIndex        =   5
      Top             =   3720
      Width           =   2000
   End
   Begin VB.TextBox Text1 
      Height          =   315
      Left            =   1920
      TabIndex        =   4
      Top             =   2760
      Width           =   6000
   End
   Begin VB.TextBox Text3 
      Height          =   315
      Left            =   1920
      TabIndex        =   3
      Top             =   4680
      Width           =   6000
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Reset"
      Height          =   400
      Left            =   3480
      TabIndex        =   2
      Top             =   6960
      Width           =   1000
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Insert"
      Height          =   400
      Left            =   5160
      TabIndex        =   1
      Top             =   6960
      Width           =   1000
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Home"
      Height          =   400
      Left            =   1800
      TabIndex        =   0
      Top             =   6960
      Width           =   1000
   End
   Begin VB.Label Label4 
      Caption         =   "Duration:-"
      Height          =   405
      Left            =   240
      TabIndex        =   11
      Top             =   5640
      Width           =   1395
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Insert information into course database"
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
      TabIndex        =   10
      Top             =   480
      Width           =   6975
   End
   Begin VB.Label Label2 
      Caption         =   "Title:-"
      Height          =   405
      Index           =   0
      Left            =   240
      TabIndex        =   9
      Top             =   2760
      Width           =   1395
   End
   Begin VB.Label Label3 
      Caption         =   "Fees:-"
      Height          =   405
      Index           =   0
      Left            =   240
      TabIndex        =   8
      Top             =   3720
      Width           =   1395
   End
   Begin VB.Label Label2 
      Caption         =   "Description:-"
      Height          =   405
      Index           =   1
      Left            =   240
      TabIndex        =   7
      Top             =   4680
      Width           =   1395
   End
   Begin VB.Label Label10 
      Caption         =   "Course ID:-"
      Height          =   405
      Left            =   240
      TabIndex        =   6
      Top             =   1800
      Width           =   1395
   End
End
Attribute VB_Name = "Form7"
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
    Text5.SetFocus
End Sub
Private Sub Command3_Click()
    Dim q As String
    Dim N As Integer
    Dim i As Integer
    Dim TEMP As String
    Dim FLAG1 As Integer
    Dim FLAGF As Integer
    If Text5.Text = "" Or Text1.Text = "" Or Text2.Text = "" Or Text3.Text = "" Or Text4.Text = "" Then
        MsgBox ("Some FIELDS are EMPTY")
    Else
        FLAG1 = 0
        FLAGF = 0
        If Len(Text2.Text) > 0 Then
            For i = 1 To Len(Text2.Text)
                X = Mid(Text2.Text, i, 1)
                If Not X Like "[0-9]" Then
                    FLAGF = 1
                End If
            Next i
            If FLAGF = 1 Then
                MsgBox ("FEES has characters")
            End If
        End If
        Set rs = con.OpenResultset("SELECT COUNT(*) AS C FROM COURSE;", rdOpenStatic)
        N = rs.rdoColumns("C")
        rs.Close
        Set rs1 = con.OpenResultset("SELECT C_ID FROM COURSE;", rdOpenStatic)
        For i = 1 To N
            TEMP = rs1.rdoColumns("C_ID")
            If Text5.Text = TEMP Then
                FLAG1 = 1
            End If
            rs1.MoveNext
        Next i
        rs1.Close
        If FLAG1 = 1 Then
            MsgBox ("CourseID provided EXITS")
        ElseIf FLAGF = 0 Then
            q = "INSERT INTO COURSE(C_ID,C_TITLE,C_FEES,C_DESCRIPTION,C_DURATION) VALUES ('" + Text5.Text + "','" + Text1.Text + "'," + Text2.Text + ",'" + Text3.Text + "','" + Text4.Text + "');"
            con.Execute q
            MsgBox ("Successfully Entered into Database")
            Text1.Text = ""
            Text2.Text = ""
            Text3.Text = ""
            Text4.Text = ""
            Text5.Text = ""
            Text5.SetFocus
        End If
    End If
End Sub
Private Sub Form_Load()
    con.Connect = "uid=admin;pwd=admin;driver={Oracle in OraHome92}"
    con.EstablishConnection rdDriverNoPrompt
End Sub
Private Sub Form_Unload(Cancel As Integer)
    con.Close
End Sub
