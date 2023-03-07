VERSION 5.00
Begin VB.Form FORMFACULTY 
   BackColor       =   &H8000000A&
   Caption         =   "FormFACULTY"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   WindowState     =   2  'Maximized
   Begin VB.CommandButton CMDOK 
      Caption         =   "OK"
      Height          =   615
      Left            =   9600
      TabIndex        =   42
      Top             =   9600
      Width           =   975
   End
   Begin VB.CommandButton CMDALL 
      Caption         =   "ALL"
      Height          =   615
      Left            =   7440
      TabIndex        =   41
      Top             =   8040
      Width           =   2295
   End
   Begin VB.TextBox TDOJ 
      Height          =   285
      Left            =   7080
      TabIndex        =   12
      Top             =   5400
      Width           =   1575
   End
   Begin VB.Timer Timer1 
      Interval        =   500
      Left            =   8520
      Top             =   120
   End
   Begin VB.ComboBox CMBGEN 
      Height          =   315
      Left            =   7080
      TabIndex        =   8
      Top             =   4200
      Width           =   1575
   End
   Begin VB.OptionButton OPTBYID 
      BackColor       =   &H8000000B&
      Caption         =   "SEARCH BY ID"
      BeginProperty Font 
         Name            =   "Lucida Sans Unicode"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   5160
      TabIndex        =   35
      Top             =   7080
      Width           =   2055
   End
   Begin VB.OptionButton OPTBYTELNO 
      BackColor       =   &H8000000B&
      Caption         =   "SEARCH BY TEL NO"
      BeginProperty Font 
         Name            =   "Lucida Sans Unicode"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   5160
      TabIndex        =   34
      Top             =   6720
      Width           =   2175
   End
   Begin VB.CommandButton CMDCL 
      Caption         =   "CLEAR"
      BeginProperty Font 
         Name            =   "OCR A Extended"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   2760
      TabIndex        =   33
      Top             =   6720
      Width           =   1215
   End
   Begin VB.CommandButton CMDET 
      Caption         =   "EXIT"
      BeginProperty Font 
         Name            =   "OCR A Extended"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   1560
      TabIndex        =   32
      Top             =   6720
      Width           =   1215
   End
   Begin VB.CommandButton CMDUP 
      Caption         =   "UPDATE"
      BeginProperty Font 
         Name            =   "OCR A Extended"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   7800
      TabIndex        =   31
      Top             =   6840
      Width           =   1215
   End
   Begin VB.CommandButton CMDPV 
      Caption         =   "PREV"
      BeginProperty Font 
         Name            =   "Times New Roman"
         Size            =   9
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   3480
      TabIndex        =   30
      Top             =   7680
      Width           =   1215
   End
   Begin VB.CommandButton CMDLT 
      Caption         =   "LAST"
      BeginProperty Font 
         Name            =   "Times New Roman"
         Size            =   9
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   4680
      TabIndex        =   29
      Top             =   7680
      Width           =   1215
   End
   Begin VB.CommandButton CMDNT 
      Caption         =   "NEXT"
      BeginProperty Font 
         Name            =   "Times New Roman"
         Size            =   9
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   2280
      TabIndex        =   28
      Top             =   7680
      Width           =   1215
   End
   Begin VB.CommandButton CMDFT 
      Caption         =   "FIRST"
      BeginProperty Font 
         Name            =   "Times New Roman"
         Size            =   9
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   1080
      TabIndex        =   27
      Top             =   7680
      Width           =   1215
   End
   Begin VB.CommandButton CMDSV 
      Caption         =   "SAVE"
      BeginProperty Font 
         Name            =   "OCR A Extended"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   1920
      TabIndex        =   26
      Top             =   6240
      Width           =   1215
   End
   Begin VB.CommandButton CMDED 
      Caption         =   "EDIT"
      BeginProperty Font 
         Name            =   "OCR A Extended"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   5040
      TabIndex        =   25
      Top             =   6120
      Width           =   1215
   End
   Begin VB.CommandButton CMDDT 
      Caption         =   "DELETE"
      BeginProperty Font 
         Name            =   "OCR A Extended"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   3120
      TabIndex        =   24
      Top             =   6240
      Width           =   1215
   End
   Begin VB.CommandButton CMDST 
      Caption         =   "START"
      BeginProperty Font 
         Name            =   "OCR A Extended"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   960
      TabIndex        =   23
      Top             =   6240
      Width           =   975
   End
   Begin VB.TextBox TNM 
      Height          =   285
      Left            =   7080
      TabIndex        =   2
      Top             =   2520
      Width           =   1695
   End
   Begin VB.TextBox TDEG 
      Height          =   405
      Left            =   2640
      TabIndex        =   11
      Top             =   5520
      Width           =   1215
   End
   Begin VB.TextBox TST 
      Height          =   285
      Left            =   7080
      TabIndex        =   10
      Top             =   4800
      Width           =   1575
   End
   Begin VB.TextBox TAGE 
      Height          =   285
      Left            =   7080
      TabIndex        =   6
      Top             =   3600
      Width           =   1695
   End
   Begin VB.TextBox TCITY 
      Height          =   285
      Left            =   7080
      TabIndex        =   4
      Top             =   3000
      Width           =   1695
   End
   Begin VB.TextBox TADDR 
      Height          =   285
      Left            =   2640
      TabIndex        =   3
      Top             =   3240
      Width           =   1695
   End
   Begin VB.TextBox TPIN 
      Height          =   285
      Left            =   2640
      TabIndex        =   5
      Top             =   3720
      Width           =   1215
   End
   Begin VB.TextBox TPH 
      Height          =   285
      Left            =   2640
      TabIndex        =   7
      Top             =   4320
      Width           =   1215
   End
   Begin VB.TextBox TSAL 
      Height          =   375
      Left            =   2640
      TabIndex        =   9
      Top             =   4920
      Width           =   1215
   End
   Begin VB.TextBox TID 
      Height          =   285
      Left            =   2640
      TabIndex        =   1
      Top             =   2640
      Width           =   1695
   End
   Begin VB.Label Label12 
      BackStyle       =   0  'Transparent
      Caption         =   "DETAILS OF FACULTIES  IN OUR DEPARMENT"
      BeginProperty Font 
         Name            =   "Rockwell Condensed"
         Size            =   18
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00C000C0&
      Height          =   495
      Left            =   2040
      TabIndex        =   40
      Top             =   1200
      Width           =   9135
   End
   Begin VB.Label Label11 
      BackStyle       =   0  'Transparent
      Caption         =   "                       ALL * FIELDS ARE MANDATARY"
      BeginProperty Font 
         Name            =   "Times New Roman"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   375
      Left            =   2280
      TabIndex        =   39
      Top             =   1920
      Width           =   6015
   End
   Begin VB.Label LTIME 
      BackStyle       =   0  'Transparent
      BeginProperty Font 
         Name            =   "Times New Roman"
         Size            =   15.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H008080FF&
      Height          =   375
      Left            =   9600
      TabIndex        =   38
      Top             =   120
      Width           =   1455
   End
   Begin VB.Label LDATE 
      BackStyle       =   0  'Transparent
      BeginProperty Font 
         Name            =   "Times New Roman"
         Size            =   14.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H008080FF&
      Height          =   375
      Left            =   720
      TabIndex        =   37
      Top             =   240
      Width           =   1695
   End
   Begin VB.Label LGEN 
      BackStyle       =   0  'Transparent
      Caption         =   " GENDER"
      BeginProperty Font 
         Name            =   "Verdana"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000C0&
      Height          =   495
      Left            =   5760
      TabIndex        =   36
      Top             =   4320
      Width           =   1215
   End
   Begin VB.Label LADDR 
      BackStyle       =   0  'Transparent
      Caption         =   "  ADDRESS"
      BeginProperty Font 
         Name            =   "Verdana"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000C0&
      Height          =   255
      Left            =   1200
      TabIndex        =   22
      Top             =   3240
      Width           =   1455
   End
   Begin VB.Label LCTY 
      BackStyle       =   0  'Transparent
      Caption         =   "   CITY"
      BeginProperty Font 
         Name            =   "Verdana"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000C0&
      Height          =   255
      Left            =   5880
      TabIndex        =   21
      Top             =   3120
      Width           =   1215
   End
   Begin VB.Label LPIN 
      BackStyle       =   0  'Transparent
      Caption         =   "  PIN_NO"
      BeginProperty Font 
         Name            =   "Verdana"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000C0&
      Height          =   255
      Left            =   1320
      TabIndex        =   20
      Top             =   3840
      Width           =   1215
   End
   Begin VB.Label LAGE 
      BackStyle       =   0  'Transparent
      Caption         =   "         AGE"
      BeginProperty Font 
         Name            =   "Verdana"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000C0&
      Height          =   255
      Left            =   5640
      TabIndex        =   19
      Top             =   3720
      Width           =   1215
   End
   Begin VB.Label LPH 
      BackStyle       =   0  'Transparent
      Caption         =   "   PH_NO"
      BeginProperty Font 
         Name            =   "Verdana"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000C0&
      Height          =   255
      Left            =   1320
      TabIndex        =   18
      Top             =   4440
      Width           =   1215
   End
   Begin VB.Label LDTJOIN 
      BackStyle       =   0  'Transparent
      Caption         =   "DATE_OF_JOIN"
      BeginProperty Font 
         Name            =   "Verdana"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000C0&
      Height          =   495
      Left            =   5160
      TabIndex        =   17
      Top             =   5400
      Width           =   2175
   End
   Begin VB.Label LSAL 
      BackStyle       =   0  'Transparent
      Caption         =   "  SALARY"
      BeginProperty Font 
         Name            =   "Verdana"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000C0&
      Height          =   255
      Left            =   1320
      TabIndex        =   16
      Top             =   5040
      Width           =   1215
   End
   Begin VB.Label LST 
      BackStyle       =   0  'Transparent
      Caption         =   "DESIGNATION"
      BeginProperty Font 
         Name            =   "Verdana"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000C0&
      Height          =   255
      Left            =   5280
      TabIndex        =   15
      Top             =   4920
      Width           =   1575
   End
   Begin VB.Label LDEGREE 
      BackStyle       =   0  'Transparent
      Caption         =   "DEGREE"
      BeginProperty Font 
         Name            =   "Verdana"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000C0&
      Height          =   255
      Left            =   1560
      TabIndex        =   14
      Top             =   5640
      Width           =   975
   End
   Begin VB.Label LNM 
      BackStyle       =   0  'Transparent
      Caption         =   "  NAME"
      BeginProperty Font 
         Name            =   "Verdana"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000C0&
      Height          =   255
      Left            =   5880
      TabIndex        =   13
      Top             =   2520
      Width           =   1215
   End
   Begin VB.Label LID 
      BackStyle       =   0  'Transparent
      Caption         =   "            ID"
      BeginProperty Font 
         Name            =   "Verdana"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000C0&
      Height          =   255
      Left            =   1200
      TabIndex        =   0
      Top             =   2640
      Width           =   1215
   End
End
Attribute VB_Name = "FORMFACULTY"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim cn As ADODB.Connection, cmd As ADODB.Command
Dim rs1 As ADODB.Recordset
Dim s As String
Dim nID As String

Private Sub CMDALL_Click()
 DataGrid1.Columns(0) = Adodc1.Recordset.Fields(0)
 DataGrid1.Columns(1) = Adodc1.Recordset.Fields(1)
DataGrid1.Visible = True
End Sub

Private Sub CMDCL_Click()
TID.Text = vbNullString
TNM.Text = vbNullString
TADDR.Text = vbNullString
CMBGEN.Text = vbNullString
TAGE.Text = vbNullString
TPH.Text = vbNullString
TCITY.Text = vbNullString
TPIN.Text = vbNullString
TSAL.Text = vbNullString
TST.Text = vbNullString
TDEG.Text = vbNullString
TDOJ.Text = ""
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
  TID.Text = vbNullString
TNM.Text = vbNullString
TADDR.Text = vbNullString
CMBGEN.Text = vbNullString
TAGE.Text = vbNullString
TPH.Text = vbNullString
TCITY.Text = vbNullString
TPIN.Text = vbNullString
TSAL.Text = vbNullString
TST.Text = vbNullString
TDEG.Text = vbNullString
TDOJ.Text = ""
End Sub

Private Sub CMDED_Click()
OPTBYTELNO.Visible = True
OPTBYID.Visible = True
CMDUP.Visible = True
End Sub

Private Sub CMDET_Click()
Formmenu.Show
End Sub

Private Sub CMDOK_Click()
DataGrid1.Visible = False
End Sub

Private Sub CMDST_Click()
TID.Enabled = True
TNM.Enabled = True
TADDR.Enabled = True
TPIN.Enabled = True
TAGE.Enabled = True
TPH.Enabled = True
CMBGEN.Enabled = True
TSAL.Enabled = True
TST.Enabled = True
TDEG.Enabled = True
TDOJ.Enabled = True
TCITY.Enabled = True
TID.SetFocus
End Sub

Private Sub CMDSV_Click()
Set cn = New ADODB.Connection
Set cmd = New ADODB.Command
cn.Open "dsn=project;uid=scott;pwd=tiger"
Dim s As String
If isvalid Then
s = "insert into FACULTY(ID,NAME,ADDR,CITY,PIN,AGE,PH_NO,GENDER,SALARY,DESG,DEGREE,DOJ)VALUES(' " + TID.Text + " ',' " + TNM.Text + " ',' " + TADDR.Text + " ',' " + TCITY.Text + " '," + TPIN.Text + "," + TAGE.Text + "," + TPH.Text + ",' " + CMBGEN.Text + " '," + TSAL.Text + ",' " + TST.Text + " ',' " + TDEG.Text + " ',' " + TDOJ.Text + " ')"
cmd.ActiveConnection = cn
cmd.CommandText = s
cmd.Execute
MsgBox "SUCESSFULLY INSERTED"
End If
End Sub

Private Sub CMDUP_Click()
         rs1("ID") = Val(TID.Text)
         rs1("NAME") = TNM.Text
         rs1("ADDR") = TADDR.Text
         rs1("CITY") = TCITY.Text
         rs1("PIN") = Val(TPIN.Text)
         rs1("AGE") = Val(TAGE.Text)
         rs1("PH_NO") = Val(TPH.Text)
         rs1("GENDER") = CMBGEN.Text
          rs1("SALARY") = Val(TSAL.Text)
         rs1("DESG") = TST.Text
         rs1("DEGREE") = TDEG.Text
         rs1("DOJ") = TDOJ.Text
         MsgBox "SUCESSFULLY UPDATED"
 rs1.Update
 OPTBYTELNO.Visible = False
 OPTBYID.Visible = False
 OPTBYTELNO = False
 OPTBYID = False
 TID.Text = vbNullString
TNM.Text = vbNullString
TADDR.Text = vbNullString
CMBGEN.Text = vbNullString
TAGE.Text = vbNullString
TPH.Text = vbNullString
TCITY.Text = vbNullString
TPIN.Text = vbNullString
TSAL.Text = vbNullString
TST.Text = vbNullString
TDEG.Text = vbNullString
TDOJ.Text = ""
End Sub

Private Sub Form_Load()
Set cn = New ADODB.Connection
Set cmd = New ADODB.Command
Set rs1 = New ADODB.Recordset
cn.Open "dsn=project;uid=scott;pwd=tiger"
rs1.Open "FACULTY", cn, adOpenDynamic, adLockOptimistic
CMBGEN.AddItem "MALE", 0
CMBGEN.AddItem "FEMALE", 1
LDATE = Date
'Adodc1.Visible = False
'DataGrid1.Visible = False
OPTBYTELNO.Visible = False
OPTBYID.Visible = False
TID.Enabled = False
TNM.Enabled = False
TADDR.Enabled = False
CMBGEN.Enabled = False
TAGE.Enabled = False
TPH.Enabled = False
TCITY.Enabled = False
TPIN.Enabled = False
TSAL.Enabled = False
TST.Enabled = False
TDEG.Enabled = False
TDOJ.Enabled = False
CMDUP.Visible = False
End Sub
Private Function isvalid() As Boolean

     If Len(Trim(TID.Text)) = 0 Then
        isvalid = False
        MsgBox "ID can not be blank!"
        TID.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
     
     If Len(Trim(TNM.Text)) = 0 Then
        isvalid = False
        MsgBox "Name can not be blank!"
        TextNAME.SetFocus
        Exit Function
     Else
        isvalid = True
     End If

        If Len(Trim(TADDR.Text)) = 0 Then
        isvalid = False
        MsgBox "ADDRESS can not be blank!"
        TADDR.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
     If Len(Trim(TCITY.Text)) = 0 Then
        isvalid = False
        MsgBox "CITY line can not be blank!"
        TCITY.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
     If Len(Trim(TPIN.Text)) = 0 Then
        isvalid = False
        MsgBox "PIN line can not be blank!"
        TPIN.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
     If Len(Trim(TAGE.Text)) = 0 Then
        isvalid = False
        MsgBox "AGE line  can not be blank!"
        TAGE.SetFocus
        Exit Function
     Else
        isvalid = True
     End If

     If Len(Trim(TPH.Text)) = 0 Then
        isvalid = False
        MsgBox "PHONE NO Code can not be blank!"
        TPH.SetFocus
        Exit Function
     Else
        isvalid = True
     End If

     If Len(Trim(CMBGEN.Text)) = 0 Then
        isvalid = False
        MsgBox "GENDER can not be blank!"
        TGEN.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
   If Len(Trim(TSAL.Text)) = 0 Then
        isvalid = False
        MsgBox "SALARY can not be blank!"
        TSAL.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
   If Len(Trim(TST.Text)) = 0 Then
        isvalid = False
        MsgBox "DESIGNATION can not be blank!"
        TST.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
     If Len(Trim(TDEG.Text)) = 0 Then
        isvalid = False
        MsgBox "DEGREE can not be blank!"
        TDEG.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
     If Len(Trim(TDOJ.Text)) = 0 Then
        isvalid = False
        MsgBox "DATE OF JOIN can not be blank!"
        TDOJ.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
End Function

Private Sub OPTBYID_Click()
If OPTBYID = True Then
'      Rs.Find "NAME like '" & nName & "' "
        nID = InputBox("Insert appropriate ID to search")
        rs1.Find "ID=" & nID
        TID.Text = nID
        TNM.Text = rs1("NAME")
        TADDR.Text = rs1("ADDR")
        TCITY.Text = rs1("CITY")
        TPIN.Text = CStr(rs1("PIN"))
        TAGE.Text = CStr(rs1("AGE"))
        TPH.Text = CStr(rs1("PH_NO"))
        CMBGEN.Text = rs1("GENDER")
        TSAL.Text = CStr(rs1("SALARY"))
        TCITY.Text = rs1("CITY")
        TST.Text = rs1("DESG")
        TDEG.Text = rs1("DEGREE")
        TDOJ.Text = rs1("DOJ")
        
        
        edit1
   End If
End Sub

Private Sub OPTBYTELNO_Click()
If OPTBYTELNO = True Then
       Dim nTelno As Long
        nTelno = Val(InputBox("Insert appropriate telno to search"))
        rs1.Find "PH_NO=" & nTelno
        TPH.Text = nTelno
        TID.Text = rs1("ID")
        TNM.Text = rs1("NAME")
        TADDR.Text = rs1("ADDR")
        TPIN.Text = CStr(rs1("PIN"))
        TAGE.Text = CStr(rs1("AGE"))
        TPH.Text = CStr(rs1("PH_NO"))
        CMBGEN.Text = rs1("GENDER")
        TSAL.Text = CStr(rs1("SALARY"))
        TCITY.Text = rs1("CITY")
        TST.Text = rs1("DESG")
        TDEG.Text = rs1("DEGREE")
        TDOJ.Text = rs1("DOJ")
        TCITY.Text = rs1("CITY")
        edit1
  End If
End Sub

Private Sub TAGE_KeyPress(KeyAscii As Integer)
If (KeyAscii >= Asc("0") And KeyAscii <= Asc("9")) Then
     KeyAscii = KeyAscii
Else
      MsgBox "INSERT ANY INTEGER NUMBER"
      KeyAscii = 0
 End If
End Sub




Private Sub Timer1_Timer()
If LTIME.Caption <> CStr(Time) Then
    LTIME.Caption = Time
End If
End Sub

Private Sub TPH_KeyPress(KeyAscii As Integer)
If (KeyAscii >= Asc("0") And KeyAscii <= Asc("9")) Then
     KeyAscii = KeyAscii
Else
      MsgBox "INSERT ANY INTEGER NUMBER"
      KeyAscii = 0
 End If
End Sub

Private Sub TPIN_KeyPress(KeyAscii As Integer)
If (KeyAscii >= Asc("0") And KeyAscii <= Asc("9")) Then
     KeyAscii = KeyAscii
Else
      MsgBox "INSERT ANY INTEGER NUMBER"
      KeyAscii = 0
 End If
 
End Sub


Private Sub TSAL_KeyPress(KeyAscii As Integer)
If (KeyAscii >= Asc("0") And KeyAscii <= Asc("9")) Then
     KeyAscii = KeyAscii
Else
      MsgBox "INSERT ANY INTEGER NUMBER"
      KeyAscii = 0
 End If
End Sub

Private Sub Display()
If Not rs1.EOF Then
        TID.Text = CStr(rs1("ID"))
        TNM.Text = rs1("NAME")
        TADDR.Text = rs1("ADDR")
        TCITY.Text = rs1("CITY")
        TPIN.Text = CStr(rs1("PIN"))
        TAGE.Text = CStr(rs1("AGE"))
        TPH.Text = CStr(rs1("PH_NO"))
        CMBGEN.Text = rs1("GENDER")
        TSAL.Text = CStr(rs1("SALARY"))
        TST.Text = rs1("DESG")
        TDEG.Text = rs1("DEGREE")
        TDOJ.Text = rs1("DOJ")
        
 
     
End If
End Sub
Private Sub CMDFT_Click()
If Not rs1.EOF Then
     rs1.MoveFirst
     Display
End If
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
     End If
End Sub

Private Sub CMDPV_Click()
If Not rs1.BOF Then
      rs1.MovePrevious
      Display
      Else
        Display
    End If
End Sub
Private Sub edit1()
 If MsgBox("Are you sure to edit the record?", vbQuestion + vbYesNo, App.ProductName) = vbYes Then
    TID.Enabled = True
TNM.Enabled = True
TADDR.Enabled = True
CMBGEN.Enabled = True
TAGE.Enabled = True
TPH.Enabled = True
TCITY.Enabled = True
TPIN.Enabled = True
TSAL.Enabled = True
TST.Enabled = True
TDEG.Enabled = True
TDOJ.Enabled = True
TID.SetFocus
Else
        MsgBox "perform next operation"
        OPTBYTELNO.Visible = False
        OPTBYID.Visible = False
        CMDUP.Visible = False
        TID.Text = vbNullString
TNM.Text = vbNullString
TADDR.Text = vbNullString
CMBGEN.Text = vbNullString
TAGE.Text = vbNullString
TPH.Text = vbNullString
TCITY.Text = vbNullString
TPIN.Text = vbNullString
TSAL.Text = vbNullString
TST.Text = vbNullString
TDEG.Text = vbNullString
TDOJ.Text = vbNullString
End If

End Sub
