VERSION 5.00
Begin VB.Form Form3 
   Caption         =   "Update information into student database"
   ClientHeight    =   8610
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8100
   LinkTopic       =   "Form3"
   ScaleHeight     =   8610
   ScaleWidth      =   8100
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox Text11 
      Height          =   315
      Left            =   6000
      TabIndex        =   34
      Top             =   3840
      Width           =   1935
   End
   Begin VB.TextBox Text10 
      Height          =   315
      Left            =   1920
      TabIndex        =   32
      Top             =   3840
      Width           =   2115
   End
   Begin VB.CommandButton Command5 
      Caption         =   "Back"
      Height          =   400
      Left            =   6120
      TabIndex        =   25
      Top             =   8160
      Width           =   1000
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Reset"
      Height          =   400
      Left            =   2760
      TabIndex        =   24
      Top             =   8160
      Width           =   1000
   End
   Begin VB.TextBox Text8 
      Height          =   315
      Left            =   1920
      TabIndex        =   21
      Top             =   6000
      Width           =   1500
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
      TabIndex        =   20
      Top             =   4560
      Width           =   800
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
      TabIndex        =   19
      Top             =   4560
      Width           =   2000
   End
   Begin VB.TextBox Text2 
      Height          =   315
      Left            =   1920
      TabIndex        =   7
      Top             =   2400
      Width           =   6000
   End
   Begin VB.TextBox Text1 
      Height          =   315
      Left            =   1920
      TabIndex        =   6
      Top             =   1680
      Width           =   6000
   End
   Begin VB.TextBox Text3 
      Height          =   315
      Left            =   1920
      TabIndex        =   5
      Top             =   3120
      Width           =   2000
   End
   Begin VB.TextBox Text4 
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
      Left            =   6000
      TabIndex        =   4
      Top             =   3120
      Width           =   1875
   End
   Begin VB.TextBox Text7 
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
      TabIndex        =   3
      Top             =   5280
      Width           =   2355
   End
   Begin VB.TextBox Text9 
      Height          =   315
      Left            =   1920
      TabIndex        =   2
      Top             =   6720
      Width           =   6000
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Update"
      Height          =   400
      Left            =   4440
      TabIndex        =   1
      Top             =   8160
      Width           =   1000
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Home"
      Height          =   400
      Left            =   1080
      TabIndex        =   0
      Top             =   8160
      Width           =   1000
   End
   Begin VB.Label Label17 
      Caption         =   "Police Station:-"
      Height          =   405
      Left            =   4440
      TabIndex        =   33
      Top             =   3840
      Width           =   1395
   End
   Begin VB.Label Label16 
      Caption         =   "State:-"
      Height          =   405
      Left            =   240
      TabIndex        =   31
      Top             =   3840
      Width           =   1395
   End
   Begin VB.Label Label15 
      Height          =   315
      Left            =   1920
      TabIndex        =   30
      Top             =   7440
      Width           =   1575
   End
   Begin VB.Label Label14 
      Height          =   315
      Left            =   6000
      TabIndex        =   29
      Top             =   5280
      Width           =   1095
   End
   Begin VB.Label Label24 
      Caption         =   "Fees:-"
      Height          =   405
      Left            =   4320
      TabIndex        =   28
      Top             =   5280
      Width           =   1395
   End
   Begin VB.Label Label12 
      Caption         =   "Course Name:-"
      Height          =   405
      Left            =   3720
      TabIndex        =   27
      Top             =   7440
      Width           =   1395
   End
   Begin VB.Label Label13 
      Height          =   315
      Left            =   5400
      TabIndex        =   26
      Top             =   7440
      Width           =   2640
   End
   Begin VB.Label Label11 
      Height          =   315
      Left            =   1920
      TabIndex        =   23
      Top             =   960
      Width           =   1500
   End
   Begin VB.Label Label10 
      Caption         =   "Student ID:-"
      Height          =   405
      Left            =   240
      TabIndex        =   22
      Top             =   960
      Width           =   1395
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Update information into student database"
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
   Begin VB.Label Label2 
      Caption         =   "Name:-"
      Height          =   405
      Index           =   0
      Left            =   240
      TabIndex        =   17
      Top             =   1680
      Width           =   1395
   End
   Begin VB.Label Label3 
      Caption         =   "Address:-"
      Height          =   405
      Index           =   0
      Left            =   240
      TabIndex        =   16
      Top             =   2400
      Width           =   1395
   End
   Begin VB.Label Label2 
      Caption         =   "City:-"
      Height          =   405
      Index           =   1
      Left            =   240
      TabIndex        =   15
      Top             =   3120
      Width           =   1395
   End
   Begin VB.Label Label3 
      Caption         =   "Pin:-"
      Height          =   405
      Index           =   1
      Left            =   4440
      TabIndex        =   14
      Top             =   3120
      Width           =   1395
   End
   Begin VB.Label Label4 
      Caption         =   "Mobile No. :-"
      Height          =   405
      Left            =   240
      TabIndex        =   13
      Top             =   5280
      Width           =   1395
   End
   Begin VB.Label Label5 
      Caption         =   "Date of Birth (MM/DD/YYYY):-"
      Height          =   405
      Left            =   240
      TabIndex        =   12
      Top             =   4560
      Width           =   1395
   End
   Begin VB.Label Label6 
      Caption         =   "Age:-"
      Height          =   405
      Left            =   4440
      TabIndex        =   11
      Top             =   4560
      Width           =   1395
   End
   Begin VB.Label Label7 
      Caption         =   "Gender:-"
      Height          =   405
      Left            =   240
      TabIndex        =   10
      Top             =   6000
      Width           =   1395
   End
   Begin VB.Label Label8 
      Caption         =   "Father's Name:-"
      Height          =   405
      Left            =   240
      TabIndex        =   9
      Top             =   6720
      Width           =   1395
   End
   Begin VB.Label Label9 
      Caption         =   "Course ID:-"
      Height          =   405
      Left            =   240
      TabIndex        =   8
      Top             =   7440
      Width           =   1395
   End
End
Attribute VB_Name = "Form3"
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
Private Sub Command1_Click()
    Form14.Show
    Unload Form2
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
    Text1.SetFocus
End Sub
Private Sub Command3_Click()
    Dim q As String
    Dim i As Integer
    Dim FLAGN As Integer
    Dim FLAGF As Integer
    Dim FLAGP As Integer
    Dim FLAGM As Integer
    Dim FLAGA As Integer
    Dim X As String
    FLAGN = 0
    FLAGF = 0
    FLAGP = 0
    FLAGM = 0
    FLAGA = 0
    If Len(Text1.Text) > 0 Then
        For i = 1 To Len(Text1.Text)
            X = Mid(Text1.Text, i, 1)
            If Not X Like "[A-Za-z]" Then
                If Not X Like "[ ]" Then
                    FLAGN = 1
                End If
            End If
        Next i
        If FLAGN = 1 Then
            MsgBox ("NAME has digits")
        End If
    End If
    If Len(Text4.Text) < 6 Or Len(Text4.Text) > 6 Then
        FLAGP = 1
        MsgBox ("PIN CODE must be 6 digts")
    Else
        If Len(Text4.Text) = 6 Then
            For i = 1 To Len(Text4.Text)
                X = Mid(Text4.Text, i, 1)
                If Not X Like "[0-9]" Then
                    FLAGP = 1
                End If
            Next i
        End If
        If FLAGP = 1 Then
            MsgBox ("PIN CODE has characters")
        End If
    End If
    If Len(Text6.Text) > 0 Then
        For i = 1 To Len(Text6.Text)
            X = Mid(Text6.Text, i, 1)
            If Not X Like "[0-9]" Then
                FLAGA = 1
            End If
        Next i
        If FLAGA = 1 Then
            MsgBox ("AGE has characters")
        End If
    End If
    If Len(Text7.Text) < 10 Or Len(Text7.Text) > 10 Then
        FLAGM = 1
        MsgBox ("MOBILE NO. must be 10 digts")
    Else
        If Len(Text7.Text) = 10 Then
            For i = 1 To Len(Text7.Text)
                X = Mid(Text7.Text, i, 1)
                If Not X Like "[0-9]" Then
                    FLAGM = 1
                End If
            Next i
        End If
        If FLAGM = 1 Then
            MsgBox ("MOBILE NO. has characters")
        End If
    End If
    If Len(Text9.Text) > 0 Then
        For i = 1 To Len(Text9.Text)
            X = Mid(Text9.Text, i, 1)
            If Not X Like "[A-Za-z]" Then
                If Not X Like "[ ]" Then
                    FLAGF = 1
                End If
            End If
        Next i
        If FLAGF = 1 Then
            MsgBox ("FATHER'S NAME has digits")
        End If
    End If
    If FLAGP = 0 And FLAGM = 0 And FLAGF = 0 And FLAGN = 0 And FLAGA = 0 Then
        q = "UPDATE STUDENT SET S_NAME = '" + Text1.Text + "',S_ADDRESS = '" + Text2.Text + "',S_CITY = '" + Text3.Text + "',S_PIN = " + Text4.Text + ",S_DOB = TO_DATE('" + Text5.Text + "','MM/DD/YYYY'),S_AGE = " + Text6.Text + ",S_MOBILE = " + Text7.Text + ",S_GENDER = '" + Text8.Text + "',S_FNAME = '" + Text9.Text + "',S_STATE = '" + Text10.Text + "',S_POLICE = '" + Text11.Text + "' WHERE S_ID = '" + Label11.Caption + "';"
        con.Execute q
        MsgBox ("Successfully Updated into Database")
        Form2.Text1.Text = ""
        Form2.Label11.Caption = ""
        Form2.Label12.Caption = ""
        Form2.Label13.Caption = ""
        Form2.Label14.Caption = ""
        Form2.Label15.Caption = ""
        Form2.Label16.Caption = ""
        Form2.Label17.Caption = ""
        Form2.Label18.Caption = ""
        Form2.Label19.Caption = ""
        Form2.Label20.Caption = ""
        Form2.Label21.Caption = ""
        Form2.Label25.Caption = ""
        Form2.Label27.Caption = ""
        Form2.Label28.Caption = ""
        Form2.Show
        Unload Me
    End If
End Sub
Private Sub Command5_Click()
    Form2.Text1.Text = ""
    Form2.Label11.Caption = ""
    Form2.Label12.Caption = ""
    Form2.Label13.Caption = ""
    Form2.Label14.Caption = ""
    Form2.Label15.Caption = ""
    Form2.Label16.Caption = ""
    Form2.Label17.Caption = ""
    Form2.Label18.Caption = ""
    Form2.Label19.Caption = ""
    Form2.Label20.Caption = ""
    Form2.Label21.Caption = ""
    Form2.Label25.Caption = ""
    Form2.Label27.Caption = ""
    Form2.Label28.Caption = ""
    Form2.Show
    Unload Me
End Sub
Private Sub Form_Load()
    con.Connect = "uid=admin;pwd=admin;driver={Oracle in OraHome92}"
    con.EstablishConnection rdDriverNoPrompt
    Label11.Caption = Form2.Text1.Text
    Label13.Caption = Form2.Label21.Caption
    Label14.Caption = Form2.Label25.Caption
    Label15.Caption = Form2.Label20.Caption
    Text1.Text = Form2.Label11.Caption
    Text2.Text = Form2.Label12.Caption
    Text3.Text = Form2.Label13.Caption
    Text4.Text = Form2.Label14.Caption
    Text5.Text = Form2.Label15.Caption
    Text6.Text = Form2.Label16.Caption
    Text7.Text = Form2.Label17.Caption
    Text8.Text = Form2.Label18.Caption
    Text9.Text = Form2.Label19.Caption
    Text10.Text = Form2.Label27.Caption
    Text11.Text = Form2.Label28.Caption
    temp1 = Form2.Label11.Caption
    temp2 = Form2.Label12.Caption
    temp3 = Form2.Label13.Caption
    temp4 = Form2.Label14.Caption
    temp5 = Form2.Label15.Caption
    temp6 = Form2.Label16.Caption
    temp7 = Form2.Label17.Caption
    temp8 = Form2.Label18.Caption
    temp9 = Form2.Label19.Caption
    temp10 = Form2.Label27.Caption
    temp11 = Form2.Label28.Caption
End Sub
Private Sub Form_Unload(Cancel As Integer)
    con.Close
End Sub
