VERSION 5.00
Object = "{67397AA1-7FB1-11D0-B148-00A0C922E820}#6.0#0"; "MSADODC.OCX"
Object = "{CDE57A40-8B86-11D0-B3C6-00A0C90AEA82}#1.0#0"; "MSDATGRD.OCX"
Begin VB.Form FORMRESULT 
   BackColor       =   &H00C0C000&
   Caption         =   "FORMRESULT"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   WindowState     =   2  'Maximized
   Begin MSAdodcLib.Adodc Adodc1 
      Height          =   855
      Left            =   960
      Top             =   8400
      Width           =   2895
      _ExtentX        =   5106
      _ExtentY        =   1508
      ConnectMode     =   0
      CursorLocation  =   3
      IsolationLevel  =   -1
      ConnectionTimeout=   15
      CommandTimeout  =   30
      CursorType      =   3
      LockType        =   3
      CommandType     =   8
      CursorOptions   =   0
      CacheSize       =   50
      MaxRecords      =   0
      BOFAction       =   0
      EOFAction       =   0
      ConnectStringType=   3
      Appearance      =   1
      BackColor       =   -2147483643
      ForeColor       =   -2147483640
      Orientation     =   0
      Enabled         =   -1
      Connect         =   "DSN=project"
      OLEDBString     =   ""
      OLEDBFile       =   ""
      DataSourceName  =   "project"
      OtherAttributes =   ""
      UserName        =   "scott"
      Password        =   "tiger"
      RecordSource    =   "select * from result where grade = '2ND' "
      Caption         =   "Adodc1"
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      _Version        =   393216
   End
   Begin MSDataGridLib.DataGrid DataGrid1 
      Bindings        =   "FormRESULT.frx":0000
      Height          =   1815
      Left            =   1320
      TabIndex        =   36
      Top             =   9720
      Width           =   7575
      _ExtentX        =   13361
      _ExtentY        =   3201
      _Version        =   393216
      AllowUpdate     =   -1  'True
      HeadLines       =   1
      RowHeight       =   15
      AllowAddNew     =   -1  'True
      AllowDelete     =   -1  'True
      BeginProperty HeadFont {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ColumnCount     =   2
      BeginProperty Column00 
         DataField       =   ""
         Caption         =   ""
         BeginProperty DataFormat {6D835690-900B-11D0-9484-00A0C91110ED} 
            Type            =   0
            Format          =   ""
            HaveTrueFalseNull=   0
            FirstDayOfWeek  =   0
            FirstWeekOfYear =   0
            LCID            =   1033
            SubFormatType   =   0
         EndProperty
      EndProperty
      BeginProperty Column01 
         DataField       =   ""
         Caption         =   ""
         BeginProperty DataFormat {6D835690-900B-11D0-9484-00A0C91110ED} 
            Type            =   0
            Format          =   ""
            HaveTrueFalseNull=   0
            FirstDayOfWeek  =   0
            FirstWeekOfYear =   0
            LCID            =   1033
            SubFormatType   =   0
         EndProperty
      EndProperty
      SplitCount      =   1
      BeginProperty Split0 
         BeginProperty Column00 
         EndProperty
         BeginProperty Column01 
         EndProperty
      EndProperty
   End
   Begin VB.CommandButton CMDLST 
      Caption         =   "LIST"
      Height          =   495
      Left            =   6360
      TabIndex        =   34
      Top             =   9000
      Width           =   2175
   End
   Begin VB.CommandButton CMDOK 
      Caption         =   "OK"
      Height          =   735
      Left            =   9000
      TabIndex        =   33
      Top             =   9960
      Width           =   1815
   End
   Begin VB.OptionButton OPTBYROLL 
      BackColor       =   &H00C0C000&
      Caption         =   "CHANGE BY ROLL"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   255
      Left            =   5400
      TabIndex        =   32
      Top             =   8040
      Width           =   2175
   End
   Begin VB.ComboBox CMBYRPASS 
      Height          =   315
      Left            =   6240
      TabIndex        =   6
      Top             =   4200
      Width           =   1335
   End
   Begin VB.TextBox TREG 
      Height          =   495
      Left            =   2880
      TabIndex        =   5
      Top             =   4200
      Width           =   1335
   End
   Begin VB.Timer Timer1 
      Interval        =   500
      Left            =   4320
      Top             =   240
   End
   Begin VB.CommandButton CMDUP 
      BackColor       =   &H00000080&
      Caption         =   "UPDATE"
      Height          =   375
      Left            =   7560
      TabIndex        =   28
      Top             =   7680
      Width           =   855
   End
   Begin VB.CommandButton CMDET 
      Caption         =   "EXIT"
      Height          =   495
      Left            =   9480
      TabIndex        =   27
      Top             =   7080
      Width           =   735
   End
   Begin VB.CommandButton CMDCL 
      Caption         =   "RESET"
      Height          =   495
      Left            =   8760
      TabIndex        =   26
      Top             =   7080
      Width           =   735
   End
   Begin VB.OptionButton OPTBYSL 
      BackColor       =   &H00C0C000&
      Caption         =   "CHANGE BY SLNO"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   255
      Left            =   5400
      TabIndex        =   25
      Top             =   7680
      Width           =   2175
   End
   Begin VB.CommandButton CMDFT 
      Caption         =   "FIRST"
      Height          =   495
      Left            =   5040
      TabIndex        =   24
      Top             =   8280
      Width           =   1215
   End
   Begin VB.CommandButton CMDNT 
      Caption         =   "NEXT"
      Height          =   495
      Left            =   6240
      TabIndex        =   23
      Top             =   8280
      Width           =   1215
   End
   Begin VB.CommandButton CMDPV 
      Caption         =   "PREV"
      Height          =   495
      Left            =   7440
      TabIndex        =   22
      Top             =   8280
      Width           =   1215
   End
   Begin VB.CommandButton CMDLT 
      Caption         =   "LAST"
      Height          =   495
      Left            =   8640
      TabIndex        =   21
      Top             =   8280
      Width           =   1215
   End
   Begin VB.CommandButton CMDSV 
      Caption         =   "SAVE"
      Height          =   495
      Left            =   3960
      TabIndex        =   20
      Top             =   7080
      Width           =   1215
   End
   Begin VB.CommandButton CMDED 
      Caption         =   "EDIT"
      Height          =   495
      Left            =   5280
      TabIndex        =   19
      Top             =   7080
      Width           =   1215
   End
   Begin VB.CommandButton CMDDT 
      Caption         =   "DELETE"
      Height          =   495
      Left            =   6480
      TabIndex        =   18
      Top             =   7080
      Width           =   1215
   End
   Begin VB.CommandButton CMDST 
      Caption         =   "START"
      Height          =   495
      Left            =   2760
      TabIndex        =   17
      Top             =   7080
      Width           =   1215
   End
   Begin VB.ComboBox CMBGRD 
      Height          =   315
      Left            =   4560
      TabIndex        =   9
      Top             =   6120
      Width           =   1215
   End
   Begin VB.ComboBox CMBDEPT 
      Height          =   315
      Left            =   3000
      TabIndex        =   3
      Top             =   3360
      Width           =   1215
   End
   Begin VB.ComboBox CMBYROFSTU 
      Height          =   315
      Left            =   2880
      TabIndex        =   7
      Top             =   5160
      Width           =   1215
   End
   Begin VB.TextBox TMARK 
      Height          =   495
      Left            =   6360
      TabIndex        =   8
      Top             =   5160
      Width           =   1215
   End
   Begin VB.TextBox TROLL 
      Height          =   495
      Left            =   6120
      TabIndex        =   4
      Top             =   3240
      Width           =   1215
   End
   Begin VB.TextBox TNM 
      Height          =   495
      Left            =   6120
      TabIndex        =   2
      Top             =   2400
      Width           =   1215
   End
   Begin VB.TextBox TSLNO 
      Height          =   495
      Left            =   3000
      TabIndex        =   1
      Top             =   2400
      Width           =   1215
   End
   Begin VB.Label Label1 
      BackStyle       =   0  'Transparent
      Caption         =   "FORM FOR RESULT OF DEPARTMENTAL STUDENT"
      BeginProperty Font 
         Name            =   "Haettenschweiler"
         Size            =   27.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0080FF80&
      Height          =   855
      Left            =   1440
      TabIndex        =   35
      Top             =   1320
      Width           =   8415
   End
   Begin VB.Label LREG 
      BackStyle       =   0  'Transparent
      Caption         =   "REGISTRATION NO"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   11.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00C00000&
      Height          =   495
      Left            =   960
      TabIndex        =   31
      Top             =   4320
      Width           =   1815
   End
   Begin VB.Label LTIME 
      BackStyle       =   0  'Transparent
      BeginProperty Font 
         Name            =   "Palatino Linotype"
         Size            =   14.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF00FF&
      Height          =   375
      Left            =   5160
      TabIndex        =   30
      Top             =   240
      Width           =   1095
   End
   Begin VB.Label LDATE 
      BackStyle       =   0  'Transparent
      BeginProperty Font 
         Name            =   "Palatino Linotype"
         Size            =   14.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF00FF&
      Height          =   375
      Left            =   840
      TabIndex        =   29
      Top             =   240
      Width           =   1455
   End
   Begin VB.Label LGRADE 
      BackStyle       =   0  'Transparent
      Caption         =   "GRADE"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   11.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   495
      Left            =   3240
      TabIndex        =   16
      Top             =   6120
      Width           =   1215
   End
   Begin VB.Label LTLMARKS 
      BackStyle       =   0  'Transparent
      Caption         =   "TOTAL MARKS"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   11.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   495
      Left            =   5040
      TabIndex        =   15
      Top             =   5160
      Width           =   1215
   End
   Begin VB.Label LYROFSTU 
      BackStyle       =   0  'Transparent
      Caption         =   "YEAR OF STUDENT"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   11.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   495
      Left            =   1440
      TabIndex        =   14
      Top             =   5160
      Width           =   1215
   End
   Begin VB.Label LYROFPASS 
      BackStyle       =   0  'Transparent
      Caption         =   "YEAR OF PASSING"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   11.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   495
      Left            =   5040
      TabIndex        =   13
      Top             =   4200
      Width           =   1215
   End
   Begin VB.Label LROLL 
      BackStyle       =   0  'Transparent
      Caption         =   "ROLL"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   11.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   495
      Left            =   5280
      TabIndex        =   12
      Top             =   3360
      Width           =   1215
   End
   Begin VB.Label LDEPT 
      BackStyle       =   0  'Transparent
      Caption         =   "DEPARMENT"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   11.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   495
      Left            =   1320
      TabIndex        =   11
      Top             =   3360
      Width           =   1695
   End
   Begin VB.Label LNAME 
      BackStyle       =   0  'Transparent
      Caption         =   "NAME"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   11.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   495
      Left            =   5160
      TabIndex        =   10
      Top             =   2520
      Width           =   1215
   End
   Begin VB.Label LSLNO 
      BackStyle       =   0  'Transparent
      Caption         =   "SL NO"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   11.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   495
      Left            =   1800
      TabIndex        =   0
      Top             =   2400
      Width           =   1215
   End
End
Attribute VB_Name = "FORMRESULT"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim cn As ADODB.Connection, cmd As ADODB.Command
Dim rs1 As ADODB.Recordset
Dim s As String
Dim nID As Long




Private Sub CMDCL_Click()
TSLNO.Text = " "
TNM.Text = " "
CMBDEPT.Text = ""
TROLL.Text = ""
TREG.Text = ""
CMBYRPASS.Text = ""
CMBYROFSTU.Text = ""
TMARK.Text = ""
CMBGRD.Text = ""
End Sub

Private Sub CMDDT_Click()
If MsgBox("Are you sure to delete the record?", vbQuestion + vbYesNo, App.ProductName) = vbYes Then
     rs1.Delete adAffectCurrent
     If Not rs1.EOF Then
            rs1.MoveNext
     Else
            rs1.MovePrevious
            Display
     End If
  MsgBox "SUCCESSFULLY DELETED"
     Display
  End If
  TSLNO.Text = " "
TNM.Text = " "
CMBDEPT.Text = ""
TROLL.Text = ""
TREG.Text = ""
CMBYRPASS.Text = ""
CMBYROFSTU.Text = ""
TMARK.Text = ""
End Sub

Private Sub CMDED_Click()
OPTBYSL.Visible = True
OPTBYROLL.Visible = True
CMDUP.Visible = True
End Sub

Private Sub CMDET_Click()
Formmenu.Show
End Sub

Private Sub CMDFT_Click()
If Not rs1.EOF Then
     rs1.MoveFirst
     Display
End If
End Sub

Private Sub CMDLIST_Click()
DataGrid1.Visible = True
CMDOK.Visible = True
End Sub

Private Sub CMDLST_Click()
DataGrid1.Visible = True
End Sub

Private Sub CMDLT_Click()
If Not rs1.BOF Then
   rs1.MoveLast
   Display
   Else
    MsgBox "u are in the last record!"
    Display
 End If
End Sub

Private Sub CMDNT_Click()
If Not rs1.EOF Then
      rs1.MoveNext
      Display
      Else
        Display
    End If
End Sub

Private Sub CMDOK_Click()
DataGrid1.Visible = False
CMDOK.Visible = False
End Sub

Private Sub CMDPV_Click()
If Not rs1.BOF Then
      rs1.MovePrevious
      Display
      Else
        Display
    End If
End Sub

Private Sub CMDST_Click()
TSLNO.Enabled = True
TNM.Enabled = True
CMBDEPT.Enabled = True
TROLL.Enabled = True
TREG.Enabled = True
CMBYRPASS.Enabled = True
CMBYROFSTU.Enabled = True
TMARK.Enabled = True
CMBGRD.Enabled = True
TSLNO.SetFocus
End Sub

Private Sub CMDSV_Click()
Set cn = New ADODB.Connection
Set cmd = New ADODB.Command
cn.Open "dsn=project;uid=scott;pwd=tiger"
Dim s As String
If isvalid Then
s = "insert into RESULT(SL_NO,NAME,DEPT,ROLL,REG_NO,YR_OF_PASS,YR_OF_STU,TOTAL_MARKS,GRADE)VALUES(" + TSLNO.Text + ",' " + TNM.Text + " ',' " + CMBDEPT.Text + " '," + TROLL.Text + ",' " + TREG.Text + " ' ," + CMBYRPASS.Text + ",' " + CMBYROFSTU.Text + " '," + TMARK.Text + ",' " + CMBGRD.Text + " ')"
cmd.ActiveConnection = cn
cmd.CommandText = s
cmd.Execute
MsgBox "SUCESSFULLY INSERTED"
End If
End Sub

Private Sub CMDUP_Click()
          rs1("SL_NO") = Val(TSLNO.Text)
         rs1("NAME") = TNM.Text
         rs1("DEPT") = CMBDEPT.Text
         rs1("ROLL") = TROLL.Text
         rs1("REG_NO") = TREG.Text
         rs1("YR_OF_PASS") = CMBYRPASS.Text
         rs1("YR_OF_STU") = CMBYROFSTU.Text
         rs1("TOTAL_MARKS") = Val(TMARK.Text)
         rs1("GRADE") = CMBGRD.Text
         MsgBox "SUCESSFULLY UPDATED"
 rs1.Update
 OPTBYSL.Visible = False
OPTBYROLL.Visible = False
CMDUP.Visible = False
OPTBYROLL = False
OPTBYSL = False
TSLNO.Text = " "
TNM.Text = " "
CMBDEPT.Text = ""
TROLL.Text = ""
TREG.Text = ""
CMBYRPASS.Text = ""
CMBYROFSTU.Text = ""
TMARK.Text = ""
CMBGRD.Text = ""
End Sub


Private Sub Form_Load()
Dim i, j As Integer
Set cn = New ADODB.Connection
Set cmd = New ADODB.Command
Set rs1 = New ADODB.Recordset
cn.Open "dsn=project;uid=scott;pwd=tiger"
rs1.Open "RESULT", cn, adOpenDynamic, adLockOptimistic
TSLNO.Enabled = False
TNM.Enabled = False
CMBDEPT.Enabled = False
TROLL.Enabled = False
TREG.Enabled = False
CMBYRPASS.Enabled = False
CMBYROFSTU.Enabled = False
TMARK.Enabled = False
CMBGRD.Enabled = False
DataGrid1.Visible = False
CMDOK.Visible = False
Adodc1.Visible = False
j = 0
For i = 1950 To 2020
 CMBYRPASS.AddItem i, j
j = j + 1
Next i
OPTBYSL.Visible = False
OPTBYROLL.Visible = False
CMDUP.Visible = False
CMBDEPT.AddItem "COMPUTER SCIENCE", 0
CMBDEPT.AddItem "PHYSICS", 1
CMBYROFSTU.AddItem "1ST", 0
CMBYROFSTU.AddItem "2ND", 1
CMBYROFSTU.AddItem "3RD", 2
CMBGRD.AddItem "1ST", 0
CMBGRD.AddItem "2ND", 1
CMBGRD.AddItem "3RD", 2
LDATE.Caption = Date
End Sub
Private Function isvalid() As Boolean
     
     If Len(Trim(TSLNO.Text)) = 0 Then
        isvalid = False
        MsgBox "SLNO can not be blank!"
        TSLNO.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
     
        If Len(Trim(TNM.Text)) = 0 Then
        isvalid = False
        MsgBox "NAME can not be blank!"
        TNM.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
     If Len(Trim(CMBDEPT.Text)) = 0 Then
        isvalid = False
        MsgBox "DEPARTMENT can not be blank!"
        CMBDEPT.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
     If Len(Trim(TROLL.Text)) = 0 Then
        isvalid = False
        MsgBox "Roll can not be blank!"
        TROLL.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
     
     If Len(Trim(TREG.Text)) = 0 Then
        isvalid = False
        MsgBox "REG NO can not be blank!"
        TREG.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
     If Len(Trim(CMBYRPASS.Text)) = 0 Then
        isvalid = False
        MsgBox "YEAR OF PASSING can not be blank!"
        CMBYRPASS.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
     If Len(Trim(CMBYROFSTU.Text)) = 0 Then
        isvalid = False
        MsgBox "Year of student can not be blank!"
        CMBYROFSTU.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
     
      If Len(Trim(TMARK.Text)) = 0 Then
        isvalid = False
        MsgBox "TOTAL MARKS can not be blank!"
        TMARK.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
     If Len(Trim(CMBGRD.Text)) = 0 Then
        isvalid = False
        MsgBox "Grade can not be blank!"
        CMBGRD.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
End Function


Private Sub OPTBYROLL_Click()
If OPTBYROLL = True Then
       Dim nRLNO As Long
        nRLNO = Val(InputBox("Insert appropriate ROLL NO to search"))
        rs1.Find "ROLL=" & nRLNO
        TROLL.Text = nRLNO
        TSLNO.Text = CStr(rs1("SL_NO"))
        TNM.Text = rs1("NAME")
        CMBDEPT.Text = rs1("DEPT")
        TREG.Text = CStr(rs1("REG_NO"))
        CMBYRPASS.Text = CStr(rs1("YR_OF_PASS"))
         CMBYROFSTU.Text = CStr(rs1("YR_OF_STU"))
         TMARK.Text = CStr(rs1("TOTAL_MARKS"))
        CMBGRD.Text = rs1("GRADE")
        edit1
'         Else
'        MsgBox "PERFORM NEXT OPERATION"
'        OPTBYSL.Visible = False
'        OPTBYROLL.Visible = False
'      CMDUP.Visible = False
'      OPTBYSL = False
'      OPTBYROLL = False
'    End If
  End If
End Sub

Private Sub OPTBYSL_Click()
If OPTBYSL = True Then
       Dim nSLNO As Long
        nSLNO = Val(InputBox("Insert appropriate SERAIL NO to search"))
        rs1.Find "SL_NO=" & nSLNO
        TSLNO.Text = nSLNO
        TNM.Text = rs1("NAME")
        CMBDEPT.Text = rs1("DEPT")
        TROLL.Text = CStr(rs1("ROLL"))
        TREG.Text = CStr(rs1("REG_NO"))
        CMBYRPASS.Text = CStr(rs1("YR_OF_PASS"))
         CMBYROFSTU.Text = CStr(rs1("YR_OF_STU"))
         TMARK.Text = CStr(rs1("TOTAL_MARKS"))
        CMBGRD.Text = rs1("GRADE")
        edit1
'      Else
'        MsgBox "PERFORM NEXT OPERATION"
'        OPTBYSL.Visible = False
'     OPTBYROLL.Visible = False
'      CMDUP.Visible = False
'      OPTBYSL = False
'      OPTBYROLL = False
'End If
  End If
End Sub

Private Sub Timer1_Timer()
If LTIME.Caption <> CStr(Time) Then
    LTIME.Caption = Time
End If
End Sub

Private Sub TMARK_KeyPress(KeyAscii As Integer)
If (KeyAscii >= Asc("0") And KeyAscii <= Asc("9")) Then
     KeyAscii = KeyAscii
Else
      MsgBox "INSERT ANY INTEGER NUMBER"
      KeyAscii = 0
 End If
End Sub

Private Sub TROLL_KeyPress(KeyAscii As Integer)
If (KeyAscii >= Asc("0") And KeyAscii <= Asc("9")) Then
     KeyAscii = KeyAscii
Else
      MsgBox "INSERT ANY INTEGER NUMBER"
      KeyAscii = 0
 End If
 
End Sub

Private Sub TSLNO_KeyPress(KeyAscii As Integer)
If (KeyAscii >= Asc("0") And KeyAscii <= Asc("9")) Then
     KeyAscii = KeyAscii
Else
      MsgBox "INSERT ANY INTEGER NUMBER"
      KeyAscii = 0
 End If
End Sub

Private Sub Display()
If Not rs1.EOF Then
TSLNO.Text = CStr(rs1("SL_NO"))
TNM.Text = rs1("NAME")
CMBDEPT.Text = rs1("DEPT")
TROLL.Text = CStr(rs1("ROLL"))
TREG.Text = CStr(rs1("REG_NO"))
CMBYRPASS.Text = CStr(rs1("YR_OF_PASS"))
CMBYROFSTU.Text = rs1("YR_OF_STU")
TMARK.Text = CStr(rs1("TOTAL_MARKS"))
CMBGRD.Text = rs1("GRADE")
End If
End Sub
Private Sub edit1()
 If MsgBox("Are you sure to edit the record?", vbQuestion + vbYesNo, App.ProductName) = vbYes Then
   TSLNO.Enabled = True
TNM.Enabled = True
CMBDEPT.Enabled = True
TROLL.Enabled = True
TREG.Enabled = True
CMBYRPASS.Enabled = True
CMBYROFSTU.Enabled = True
TMARK.Enabled = True
CMBGRD.Enabled = True
TSLNO.SetFocus
Else
        MsgBox "perform next operation"
OPTBYSL.Visible = False
OPTBYROLL.Visible = False
CMDUP.Visible = False
TSLNO.Text = " "
TNM.Text = " "
CMBDEPT.Text = ""
TROLL.Text = ""
TREG.Text = ""
CMBYRPASS.Text = ""
CMBYROFSTU.Text = ""
TMARK.Text = ""
CMBGRD.Text = ""
End If

End Sub

