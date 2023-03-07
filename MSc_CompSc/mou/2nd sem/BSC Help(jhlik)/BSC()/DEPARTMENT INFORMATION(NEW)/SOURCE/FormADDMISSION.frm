VERSION 5.00
Begin VB.Form FORMADDMISSION 
   BackColor       =   &H00C0C0FF&
   Caption         =   "FORMADDMISSION"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   11010
   ScaleWidth      =   15240
   StartUpPosition =   3  'Windows Default
   WindowState     =   2  'Maximized
   Begin VB.CommandButton CMDLST 
      Caption         =   "LIST"
      Height          =   375
      Left            =   6480
      TabIndex        =   46
      Top             =   9000
      Width           =   1575
   End
   Begin VB.CommandButton CMDOK 
      Caption         =   "OK"
      Height          =   615
      Left            =   9480
      TabIndex        =   45
      Top             =   9480
      Width           =   1455
   End
   Begin VB.ComboBox CMBP1 
      Height          =   315
      Left            =   3600
      TabIndex        =   9
      Top             =   5760
      Width           =   1335
   End
   Begin VB.ComboBox CMBP2 
      Height          =   315
      Left            =   7440
      TabIndex        =   10
      Top             =   5760
      Width           =   1335
   End
   Begin VB.ComboBox CMBH 
      Height          =   315
      Left            =   7440
      TabIndex        =   8
      Top             =   5040
      Width           =   1335
   End
   Begin VB.TextBox TPH 
      Height          =   495
      Left            =   7440
      TabIndex        =   14
      Top             =   7080
      Width           =   1215
   End
   Begin VB.OptionButton OPTBYFNO 
      BackColor       =   &H00C0C0FF&
      Caption         =   "SEARCH BY FORM NO"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000080&
      Height          =   375
      Left            =   8760
      TabIndex        =   40
      Top             =   8280
      Width           =   1815
   End
   Begin VB.OptionButton OPTBYSLNO 
      BackColor       =   &H00C0C0FF&
      Caption         =   "SEARCH BY SL NO"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000080&
      Height          =   375
      Left            =   8880
      TabIndex        =   39
      Top             =   8880
      Width           =   1455
   End
   Begin VB.CommandButton CMDNT 
      Caption         =   "NEXT"
      Height          =   495
      Left            =   5040
      TabIndex        =   38
      Top             =   8280
      Width           =   735
   End
   Begin VB.CommandButton CMDPV 
      Caption         =   "PREV"
      Height          =   495
      Left            =   5760
      TabIndex        =   37
      Top             =   8280
      Width           =   735
   End
   Begin VB.CommandButton CMDLT 
      Caption         =   "LAST"
      Height          =   495
      Left            =   6480
      TabIndex        =   36
      Top             =   8280
      Width           =   735
   End
   Begin VB.CommandButton CMDFT 
      Caption         =   "FIRST"
      Height          =   495
      Left            =   4320
      TabIndex        =   35
      Top             =   8280
      Width           =   735
   End
   Begin VB.CommandButton CMDET 
      Caption         =   "EXIT"
      Height          =   495
      Left            =   2520
      TabIndex        =   34
      Top             =   7800
      Width           =   855
   End
   Begin VB.CommandButton CMDUP 
      Caption         =   "UPDATE"
      Height          =   495
      Left            =   10680
      TabIndex        =   33
      Top             =   8520
      Width           =   855
   End
   Begin VB.CommandButton CMDCL 
      Caption         =   "CLEAR"
      Height          =   495
      Left            =   3360
      TabIndex        =   32
      Top             =   7800
      Width           =   855
   End
   Begin VB.CommandButton CMDSV 
      Caption         =   "SAVE"
      Height          =   495
      Left            =   8280
      TabIndex        =   31
      Top             =   7680
      Width           =   855
   End
   Begin VB.CommandButton CMDED 
      Caption         =   "EDIT"
      Height          =   495
      Left            =   9120
      TabIndex        =   30
      Top             =   7680
      Width           =   855
   End
   Begin VB.CommandButton CMDDT 
      Caption         =   "DELETE"
      Height          =   495
      Left            =   9960
      TabIndex        =   29
      Top             =   7680
      Width           =   855
   End
   Begin VB.CommandButton CMDST 
      Caption         =   "START"
      Height          =   495
      Left            =   7440
      TabIndex        =   28
      Top             =   7680
      Width           =   855
   End
   Begin VB.TextBox TADFEE 
      Height          =   285
      Left            =   3600
      TabIndex        =   13
      Top             =   7200
      Width           =   1215
   End
   Begin VB.ComboBox CMBLANG 
      Height          =   315
      Left            =   3600
      TabIndex        =   11
      Top             =   6480
      Width           =   1215
   End
   Begin VB.ComboBox CMBYRADMIN 
      Height          =   315
      Left            =   7440
      TabIndex        =   12
      Top             =   6360
      Width           =   1215
   End
   Begin VB.TextBox TSLNO 
      Height          =   495
      Left            =   3600
      TabIndex        =   1
      Top             =   2640
      Width           =   1215
   End
   Begin VB.TextBox TFNO 
      Height          =   495
      Left            =   7440
      TabIndex        =   2
      Top             =   2520
      Width           =   1215
   End
   Begin VB.TextBox TDOA 
      Height          =   495
      Left            =   3600
      TabIndex        =   3
      Top             =   3360
      Width           =   1215
   End
   Begin VB.TextBox TROLL 
      Height          =   495
      Left            =   7440
      TabIndex        =   4
      Top             =   3240
      Width           =   1215
   End
   Begin VB.TextBox TNM 
      Height          =   495
      Left            =   3600
      TabIndex        =   5
      Top             =   4200
      Width           =   1215
   End
   Begin VB.TextBox TFNM 
      Height          =   495
      Left            =   7440
      TabIndex        =   6
      Top             =   4200
      Width           =   1215
   End
   Begin VB.TextBox TAGGM 
      Height          =   495
      Left            =   3600
      TabIndex        =   7
      Top             =   4920
      Width           =   1215
   End
   Begin VB.Timer Timer1 
      Interval        =   500
      Left            =   7560
      Top             =   120
   End
   Begin VB.Label LADD 
      BackStyle       =   0  'Transparent
      Caption         =   "FOR ADDMISION IN OUR DEPARTMENT"
      BeginProperty Font 
         Name            =   "Niagara Engraved"
         Size            =   48
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   1215
      Left            =   1080
      TabIndex        =   44
      Top             =   1200
      Width           =   9135
   End
   Begin VB.Label LPH 
      BackStyle       =   0  'Transparent
      Caption         =   "  PHONE NO                       "
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000080&
      Height          =   375
      Left            =   5760
      TabIndex        =   43
      Top             =   7200
      Width           =   1455
   End
   Begin VB.Label Ldate1 
      BackStyle       =   0  'Transparent
      BeginProperty Font 
         Name            =   "Perpetua Titling MT"
         Size            =   15.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000040C0&
      Height          =   495
      Left            =   960
      TabIndex        =   42
      Top             =   120
      Width           =   1695
   End
   Begin VB.Label LTIME 
      BackStyle       =   0  'Transparent
      BeginProperty Font 
         Name            =   "Perpetua Titling MT"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000040C0&
      Height          =   375
      Left            =   8640
      TabIndex        =   41
      Top             =   120
      Width           =   1575
   End
   Begin VB.Label LFEE 
      BackStyle       =   0  'Transparent
      Caption         =   "ADDMISSION FEE"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00004080&
      Height          =   375
      Left            =   2160
      TabIndex        =   27
      Top             =   7200
      Width           =   1215
   End
   Begin VB.Label LDATE 
      BackStyle       =   0  'Transparent
      Height          =   255
      Left            =   960
      TabIndex        =   26
      Top             =   240
      Width           =   1215
   End
   Begin VB.Label LYROFADMIN 
      BackStyle       =   0  'Transparent
      Caption         =   "  YEAR OF ADDMISSION"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00004080&
      Height          =   375
      Left            =   5760
      TabIndex        =   25
      Top             =   6360
      Width           =   1335
   End
   Begin VB.Label LFNO 
      BackStyle       =   0  'Transparent
      Caption         =   "      FORM NO"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00004080&
      Height          =   255
      Left            =   5880
      TabIndex        =   24
      Top             =   2640
      Width           =   1455
   End
   Begin VB.Label LROLL 
      BackStyle       =   0  'Transparent
      Caption         =   "             ROLL"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00004080&
      Height          =   495
      Left            =   6240
      TabIndex        =   23
      Top             =   3240
      Width           =   1215
   End
   Begin VB.Label LDADD 
      BackStyle       =   0  'Transparent
      Caption         =   "DATE OF ADMISSION"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00004080&
      Height          =   615
      Left            =   2160
      TabIndex        =   22
      Top             =   3360
      Width           =   1215
   End
   Begin VB.Label LNAME 
      BackStyle       =   0  'Transparent
      Caption         =   "NAME"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00004080&
      Height          =   255
      Left            =   2160
      TabIndex        =   21
      Top             =   4320
      Width           =   1215
   End
   Begin VB.Label LAGGM 
      BackStyle       =   0  'Transparent
      Caption         =   "AGGREGATE MARKS"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00004080&
      Height          =   495
      Left            =   2160
      TabIndex        =   20
      Top             =   4920
      Width           =   1215
   End
   Begin VB.Label LHONSSUB 
      BackStyle       =   0  'Transparent
      Caption         =   "   HONS SUB."
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00004080&
      Height          =   255
      Left            =   5760
      TabIndex        =   19
      Top             =   5040
      Width           =   1215
   End
   Begin VB.Label LPASSSUB 
      BackStyle       =   0  'Transparent
      Caption         =   "PASS SUB1"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00004080&
      Height          =   255
      Left            =   2280
      TabIndex        =   18
      Top             =   5760
      Width           =   1215
   End
   Begin VB.Label LPASSSUB2 
      BackStyle       =   0  'Transparent
      Caption         =   "   PASS SUB2"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00004080&
      Height          =   255
      Left            =   5760
      TabIndex        =   17
      Top             =   5760
      Width           =   1215
   End
   Begin VB.Label Label3 
      BackStyle       =   0  'Transparent
      Caption         =   "COMPULSARY LANGUAGE"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00004080&
      Height          =   375
      Left            =   2160
      TabIndex        =   16
      Top             =   6360
      Width           =   1215
   End
   Begin VB.Label LFNAME 
      BackStyle       =   0  'Transparent
      Caption         =   "FATHER NAME"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00004080&
      Height          =   255
      Left            =   5760
      TabIndex        =   15
      Top             =   4320
      Width           =   1575
   End
   Begin VB.Label LSL 
      BackStyle       =   0  'Transparent
      Caption         =   "SL NO"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00004080&
      Height          =   255
      Left            =   2160
      TabIndex        =   0
      Top             =   2760
      Width           =   1215
   End
End
Attribute VB_Name = "FORMADDMISSION"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim cn As ADODB.Connection, cmd As ADODB.Command
Dim rs1 As ADODB.Recordset
Dim i As Integer
Dim s As String
Dim S1 As String
Dim nID As String


Private Sub CMDCL_Click()
TSLNO.Text = ""
TFNO.Text = ""
TROLL.Text = ""
TDOA.Text = ""
TNM.Text = ""
TFNM.Text = ""
TAGGM.Text = ""
CMBH.Text = ""
CMBP1.Text = ""
CMBP2.Text = ""
CMBLANG.Text = ""
CMBYRADMIN.Text = ""
TADFEE.Text = ""
TPH.Text = ""
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
  TSLNO.Text = ""
TFNO.Text = ""
TROLL.Text = ""
TDOA.Text = ""
TNM.Text = ""
TFNM.Text = ""
TAGGM.Text = ""
CMBH.Text = ""
CMBP1.Text = ""
CMBP2.Text = ""
CMBLANG.Text = ""
CMBYRADMIN.Text = ""
TADFEE.Text = ""
TPH.Text = ""
End Sub

Private Sub CMDED_Click()
OPTBYFNO.Visible = True
OPTBYSLNO.Visible = True
CMDUP.Visible = True
End Sub

Private Sub CMDET_Click()
Unload Me
End Sub

Private Sub CMDFT_Click()
If Not rs1.EOF Then
     rs1.MoveFirst
     Display
End If
End Sub

Private Sub CMDLST_Click()
CMDOK.Visible = True
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
TFNO.Enabled = True
TDOA.Enabled = True
TROLL.Enabled = True
TNM.Enabled = True
TFNM.Enabled = True
TAGGM.Enabled = True
CMBH.Enabled = True
CMBP1.Enabled = True
CMBP2.Enabled = True
CMBLANG.Enabled = True
CMBYRADMIN.Enabled = True
TADFEE.Enabled = True
TPH.Enabled = True
TSLNO.SetFocus
End Sub

Private Sub CMDSV_Click()
Set cn = New ADODB.Connection
Set cmd = New ADODB.Command
cn.Open "dsn=project;uid=scott;pwd=tiger"
If isvalid Then
s = "insert into ADDMISSION(SLNO,FRMNO,DOA,ROLL,NAME,FTNM,AGGR_MR,HONS,PASS1,PASS2,COMP_LANG,YR_OF_ADMIN,ADD_FEE,PH_NO)values(" + TSLNO.Text + "," + TFNO.Text + ",' " + TDOA.Text + " '," + TROLL.Text + " ,' " + TNM.Text + " ',' " + TFNM.Text + " '," + TAGGM.Text + " ,' " + CMBH.Text + " ',' " + CMBP1.Text + " ',' " + CMBP2.Text + " ',' " + CMBLANG.Text + " ',' " + CMBYRADMIN.Text + " '," + TADFEE.Text + "," + TPH.Text + ")"
cmd.ActiveConnection = cn
cmd.CommandText = s
cmd.Execute
MsgBox "SUCESSFULLY INSERTED"
End If
End Sub

Private Sub CMDUP_Click()
         rs1("SLNO") = Val(TSLNO.Text)
         rs1("FRMNO") = Val(TFNO.Text)
         rs1("DOA") = TDOA.Text
         rs1("ROLL") = Val(TROLL.Text)
         rs1("NAME") = TNM.Text
         rs1("FTNM") = TFNM.Text
         rs1("AGGR_MR") = Val(TAGGM.Text)
         rs1("HONS") = CMBH.Text
         rs1("PASS1") = CMBP1.Text
         rs1("PASS2") = CMBP2.Text
         rs1("COMP_LANG") = CMBLANG.Text
         rs1("YR_OF_ADMIN") = CMBYRADMIN.Text
         rs1("ADD_FEE") = Val(TADFEE.Text)
         rs1("PH_NO") = Val(TPH.Text)
         MsgBox "SUCESSFULLY UPDATED"
 rs1.Update
 OPTBYFNO.Visible = False
OPTBYSLNO.Visible = False
CMDUP.Visible = False
OPTBYFNO = False
OPTBYSLNO = False
TSLNO.Text = ""
TFNO.Text = ""
TROLL.Text = ""
TDOA.Text = ""
TNM.Text = ""
TFNM.Text = ""
TAGGM.Text = ""
CMBH.Text = ""
CMBP1.Text = ""
CMBP2.Text = ""
CMBLANG.Text = ""
CMBYRADMIN.Text = ""
TADFEE.Text = ""
TPH.Text = ""
End Sub

Private Sub Form_Load()
Dim j As Integer
Ldate1 = Date
Set cn = New ADODB.Connection
Set cmd = New ADODB.Command
Set rs1 = New ADODB.Recordset
cn.Open "dsn=project;uid=scott;pwd=tiger"
rs1.Open "ADDMISSION", cn, adOpenDynamic, adLockOptimistic
CMBLANG.AddItem "ENGLISH,BENGALI", 0
CMBLANG.AddItem "ENGLIH,HINDI", 1
Adodc1.Visible = False
DataGrid1.Visible = False
CMBYRADMIN.AddItem "1ST", 0
CMBYRADMIN.AddItem "2ND", 1
CMBYRADMIN.AddItem "3RD", 2
CMBH.AddItem "CMSA", 0
CMBH.AddItem "PHSA", 1
CMBP1.AddItem "PHSG", 0
CMBP1.AddItem "MTMG", 1
CMBP1.AddItem "ELTG", 2
CMBP2.AddItem "PHSG", 0
CMBP2.AddItem "MTMG", 1
CMBP2.AddItem "ELTG", 2
CMDOK.Visible = False
OPTBYFNO.Visible = True
OPTBYSLNO.Visible = True
CMDUP.Visible = True
OPTBYFNO.Visible = False
OPTBYSLNO.Visible = False
TSLNO.Enabled = False
TFNO.Enabled = False
TDOA.Enabled = False
TROLL.Enabled = False
TNM.Enabled = False
TFNM.Enabled = False
TAGGM.Enabled = False
CMBH.Enabled = False
CMBP1.Enabled = False
CMBP2.Enabled = False
CMBLANG.Enabled = False
CMBYRADMIN.Enabled = False
TADFEE.Enabled = False
TPH.Enabled = False
End Sub

Private Sub OPTBYFNO_Click()
If OPTBYFNO = True Then
       Dim nFNO As Long
        nFNO = Val(InputBox("Insert appropriate telno to search"))
        rs1.Find "FRMNO=" & nFNO
        TFNO.Text = nFNO
        TSLNO.Text = CStr(rs1("SLNO"))
        TDOA.Text = rs1("DOA")
        TROLL.Text = CStr(rs1("ROLL"))
        TNM.Text = rs1("NAME")
        TFNM.Text = rs1("FTNM")
        TAGGM.Text = CStr(rs1("AGGR_MR"))
        CMBH.Text = rs1("HONS")
        CMBP1.Text = rs1("PASS1")
        CMBP2.Text = rs1("PASS2")
        CMBLANG.Text = rs1("COMP_LANG")
       CMBYRADMIN.Text = rs1("YR_OF_ADMIN")
       TADFEE.Text = CStr(rs1("ADD_FEE"))
      TPH.Text = CStr(rs1("PH_NO"))
        edit1
  End If
End Sub

Private Sub edit1()
 If MsgBox("Are you sure to edit the record?", vbQuestion + vbYesNo, App.ProductName) = vbYes Then
TSLNO.Enabled = True
TFNO.Enabled = True
TDOA.Enabled = True
TROLL.Enabled = True
TNM.Enabled = True
TFNM.Enabled = True
TAGGM.Enabled = True
CMBH.Enabled = True
CMBP1.Enabled = True
CMBP2.Enabled = True
CMBLANG.Enabled = True
CMBYRADMIN.Enabled = True
TADFEE.Enabled = True
TPH.Enabled = True
TSLNO.SetFocus
Else
        MsgBox "perform next operation"
        OPTBYFNO.Visible = False
        OPTBYSLNO.Visible = False
        CMDUP.Visible = False
        TID.Text = vbNullString
TSLNO.Text = ""
TFNO.Text = ""
TROLL.Text = ""
TDOA.Text = ""
TNM.Text = ""
TFNM.Text = ""
TAGGM.Text = ""
THSB.Text = ""
TPB1.Text = ""
TPB2.Text = ""
CMBLANG.Text = ""
CMBYRADMIN.Text = ""
TADFEE.Text = ""
TPH.Text = ""
End If

End Sub


Private Sub OPTBYSLNO_Click()
If OPTBYSLNO = True Then
       Dim nSNO As Long
        nSNO = Val(InputBox("Insert appropriate serial no to search"))
        rs1.Find "SLNO=" & nSNO
        TSLNO.Text = nSNO
        TFNO.Text = CStr(rs1("FRMNO"))
        TDOA.Text = rs1("DOA")
        TROLL.Text = CStr(rs1("ROLL"))
        TNM.Text = rs1("NAME")
        TFNM.Text = rs1("FTNM")
        TAGGM.Text = CStr(rs1("AGGR_MR"))
        CMBH.Text = rs1("HONS")
        CMBP1.Text = rs1("PASS1")
        CMBP2.Text = rs1("PASS2")
        CMBLANG.Text = rs1("COMP_LANG")
       CMBYRADMIN.Text = rs1("YR_OF_ADMIN")
       TADFEE.Text = CStr(rs1("ADD_FEE"))
      TPH.Text = CStr(rs1("PH_NO"))
        edit1
  End If
End Sub

Private Sub TADFEE_KeyPress(KeyAscii As Integer)
If (KeyAscii >= Asc("0") And KeyAscii <= Asc("9")) Then
     KeyAscii = KeyAscii
Else
      MsgBox "INSERT ANY INTEGER NUMBER"
      KeyAscii = 0
 End If
 
End Sub

Private Sub TAGGM_KeyPress(KeyAscii As Integer)
If (KeyAscii >= Asc("0") And KeyAscii <= Asc("9")) Then
     KeyAscii = KeyAscii
Else
      MsgBox "INSERT ANY INTEGER NUMBER"
      KeyAscii = 0
 End If
End Sub

Private Sub TFNO_KeyPress(KeyAscii As Integer)
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
Private Function isvalid() As Boolean

     If Len(Trim(TSLNO.Text)) = 0 Then
        isvalid = False
        MsgBox "SLNO can not be blank!"
        TSLNO.SetFocus
        Exit Function
     Else
        isvalid = True
     End If

        If Len(Trim(TFNO.Text)) = 0 Then
        isvalid = False
        MsgBox "FORMNO can not be blank!"
        TFNO.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
     If Len(Trim(TDOA.Text)) = 0 Then
        isvalid = False
        MsgBox "DATE OF ADDMISSION  can not be blank!"
        TDOA.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
     If Len(Trim(TROLL.Text)) = 0 Then
        isvalid = False
        MsgBox "ROLL can not be blank!"
        TROLL.SetFocus
        Exit Function
     Else
        isvalid = True
     End If

     If Len(Trim(TNM.Text)) = 0 Then
        isvalid = False
        MsgBox "NAME  can not be blank!"
        TNM.SetFocus
        Exit Function
     Else
        isvalid = True
     End If

     If Len(Trim(TAGGM.Text)) = 0 Then
        isvalid = False
        MsgBox "AGGREGATE MARKS can not be blank!"
        TAGGM.SetFocus
        Exit Function
     Else
        isvalid = True
     End If

    If Len(Trim(CMBH.Text)) = 0 Then
        isvalid = False
        MsgBox "HONS SUB can not be blank!"
        CMBH.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
      If Len(Trim(CMBP1.Text)) = 0 Then
        isvalid = False
        MsgBox "PASS SUB1 can not be blank!"
        CMBP1.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
      If Len(Trim(CMBP2.Text)) = 0 Then
        isvalid = False
        MsgBox "PASS SUB2 can not be blank!"
        CMBP2.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
      If Len(Trim(CMBLANG.Text)) = 0 Then
        isvalid = False
        MsgBox "COMPPULSARY LANG can not be blank!"
        CMBLANG.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
     If Len(Trim(CMBYRADMIN.Text)) = 0 Then
        isvalid = False
        MsgBox "ADDMISSION YEAR can not be blank!"
        CMBYRADMIN.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
       If Len(Trim(TADFEE.Text)) = 0 Then
        isvalid = False
        MsgBox "ADDMISSION FEE can not be blank!"
        TADFEE.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
      If Len(Trim(TPH.Text)) = 0 Then
        isvalid = False
        MsgBox "PH NO can not be blank!"
        TPH.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
End Function

Private Sub TPH_KeyPress(KeyAscii As Integer)
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
TSLNO.Text = CStr(rs1("SLNO"))
TFNO.Text = CStr(rs1("FRMNO"))
TDOA.Text = rs1("DOA")
TROLL.Text = CStr(rs1("ROLL"))
TNM.Text = rs1("NAME")
TFNM.Text = rs1("FTNM")
TAGGM.Text = CStr(rs1("AGGR_MR"))
CMBH.Text = rs1("HONS")
CMBP1.Text = rs1("PASS1")
CMBP2.Text = rs1("PASS2")
CMBLANG.Text = rs1("COMP_LANG")
CMBYRADMIN.Text = rs1("YR_OF_ADMIN")
TADFEE.Text = CStr(rs1("ADD_FEE"))
TPH.Text = CStr(rs1("PH_NO"))
End If
End Sub
