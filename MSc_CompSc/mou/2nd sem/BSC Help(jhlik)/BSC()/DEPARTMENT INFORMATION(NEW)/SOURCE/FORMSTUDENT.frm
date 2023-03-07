VERSION 5.00
Object = "{67397AA1-7FB1-11D0-B148-00A0C922E820}#6.0#0"; "MSADODC.OCX"
Object = "{CDE57A40-8B86-11D0-B3C6-00A0C90AEA82}#1.0#0"; "MSDATGRD.OCX"
Begin VB.Form FORMSTUDENT 
   BackColor       =   &H008080FF&
   Caption         =   "FORM STUDENT"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   11115
   ScaleWidth      =   15240
   StartUpPosition =   3  'Windows Default
   WindowState     =   2  'Maximized
   Begin VB.ComboBox CMBGEN1 
      Height          =   315
      Left            =   6600
      TabIndex        =   51
      Top             =   7200
      Width           =   1695
   End
   Begin VB.ComboBox CMBYRSTU 
      Height          =   315
      Left            =   8520
      TabIndex        =   48
      Top             =   7320
      Width           =   1695
   End
   Begin MSDataGridLib.DataGrid DataGrid5 
      Bindings        =   "FORMSTUDENT.frx":0000
      Height          =   1695
      Left            =   360
      TabIndex        =   47
      Top             =   8040
      Width           =   8775
      _ExtentX        =   15478
      _ExtentY        =   2990
      _Version        =   393216
      HeadLines       =   1
      RowHeight       =   15
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
   Begin MSDataGridLib.DataGrid DataGrid4 
      Bindings        =   "FORMSTUDENT.frx":0015
      Height          =   1695
      Left            =   360
      TabIndex        =   46
      Top             =   7920
      Width           =   8775
      _ExtentX        =   15478
      _ExtentY        =   2990
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
   Begin MSAdodcLib.Adodc Adodc5 
      Height          =   375
      Left            =   3000
      Top             =   6840
      Width           =   2175
      _ExtentX        =   3836
      _ExtentY        =   661
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
      RecordSource    =   "select * from student where gender = ' FEMALE '"
      Caption         =   "Adodc5"
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
   Begin MSAdodcLib.Adodc Adodc4 
      Height          =   375
      Left            =   3000
      Top             =   6360
      Width           =   2055
      _ExtentX        =   3625
      _ExtentY        =   661
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
      RecordSource    =   "select * from student where gender = ' MALE '"
      Caption         =   "Adodc4"
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
   Begin VB.OptionButton OPTGEN 
      BackColor       =   &H008080FF&
      Caption         =   "GENDER"
      BeginProperty Font 
         Name            =   "Rockwell Extra Bold"
         Size            =   12
         Charset         =   0
         Weight          =   800
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00C000C0&
      Height          =   375
      Left            =   6720
      TabIndex        =   45
      Top             =   7560
      Width           =   2175
   End
   Begin MSDataGridLib.DataGrid DataGrid3 
      Bindings        =   "FORMSTUDENT.frx":002A
      Height          =   1575
      Left            =   360
      TabIndex        =   44
      Top             =   7920
      Width           =   8775
      _ExtentX        =   15478
      _ExtentY        =   2778
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
   Begin MSDataGridLib.DataGrid DataGrid2 
      Bindings        =   "FORMSTUDENT.frx":003F
      Height          =   1455
      Left            =   240
      TabIndex        =   43
      Top             =   7920
      Width           =   8895
      _ExtentX        =   15690
      _ExtentY        =   2566
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
   Begin MSAdodcLib.Adodc Adodc3 
      Height          =   330
      Left            =   600
      Top             =   7560
      Width           =   2295
      _ExtentX        =   4048
      _ExtentY        =   582
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
      RecordSource    =   "select * from student where yr_of_stu = ' 3rd '"
      Caption         =   "Adodc3"
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
   Begin MSAdodcLib.Adodc Adodc2 
      Height          =   330
      Left            =   600
      Top             =   7080
      Width           =   2295
      _ExtentX        =   4048
      _ExtentY        =   582
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
      RecordSource    =   "select * from student where yr_of_stu = ' 2nd '"
      Caption         =   "Adodc2"
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
   Begin VB.OptionButton OPTYRSTU 
      BackColor       =   &H008080FF&
      Caption         =   "YR_OF_STU"
      BeginProperty Font 
         Name            =   "Rockwell Extra Bold"
         Size            =   12
         Charset         =   0
         Weight          =   800
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00C000C0&
      Height          =   375
      Left            =   4440
      TabIndex        =   42
      Top             =   7560
      Width           =   2175
   End
   Begin MSDataGridLib.DataGrid DataGrid1 
      Bindings        =   "FORMSTUDENT.frx":0054
      Height          =   1935
      Left            =   120
      TabIndex        =   41
      Top             =   7920
      Width           =   9015
      _ExtentX        =   15901
      _ExtentY        =   3413
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
   Begin MSAdodcLib.Adodc Adodc1 
      Height          =   375
      Left            =   600
      Top             =   6600
      Width           =   2175
      _ExtentX        =   3836
      _ExtentY        =   661
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
      RecordSource    =   "select * from student where yr_of_stu = ' 1st '"
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
   Begin VB.CommandButton Cmdok 
      Caption         =   "OK"
      Height          =   495
      Left            =   8280
      TabIndex        =   39
      Top             =   6360
      Width           =   1335
   End
   Begin VB.ComboBox CMBGEN 
      Height          =   315
      Left            =   9240
      TabIndex        =   6
      Top             =   2880
      Width           =   1455
   End
   Begin VB.ComboBox CMBYRADMIN 
      Height          =   315
      Left            =   6480
      TabIndex        =   10
      Top             =   4320
      Width           =   1455
   End
   Begin VB.CommandButton CMDLST 
      Caption         =   "SEARCH"
      Height          =   495
      Left            =   6120
      TabIndex        =   35
      Top             =   6360
      Width           =   1575
   End
   Begin VB.TextBox Tdob 
      Height          =   285
      Left            =   2400
      TabIndex        =   9
      Top             =   4440
      Width           =   1575
   End
   Begin VB.CommandButton CUP 
      Caption         =   "UPDATE "
      Height          =   375
      Left            =   4920
      TabIndex        =   34
      Top             =   5760
      Width           =   975
   End
   Begin VB.TextBox TCITY 
      Height          =   285
      Left            =   6240
      TabIndex        =   3
      Top             =   2160
      Width           =   1575
   End
   Begin VB.OptionButton optbyroll 
      BackColor       =   &H008080FF&
      Caption         =   "edit-by-roll"
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
      Height          =   495
      Left            =   3240
      TabIndex        =   31
      Top             =   5640
      Width           =   1815
   End
   Begin VB.OptionButton optbytelno 
      BackColor       =   &H008080FF&
      Caption         =   "edit-by-telno"
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
      Height          =   495
      Left            =   1320
      TabIndex        =   30
      Top             =   5640
      Width           =   1695
   End
   Begin VB.TextBox TPIN 
      Height          =   285
      Left            =   2400
      TabIndex        =   4
      Top             =   3120
      Width           =   1575
   End
   Begin VB.CommandButton CMDCL 
      Caption         =   "CLEAR"
      Height          =   615
      Left            =   5760
      TabIndex        =   13
      Top             =   4920
      Width           =   1215
   End
   Begin VB.CommandButton CMDEX 
      Caption         =   "EXIT"
      Height          =   615
      Left            =   4680
      TabIndex        =   27
      Top             =   4920
      Width           =   1095
   End
   Begin VB.Timer Timer1 
      Interval        =   500
      Left            =   7440
      Top             =   360
   End
   Begin VB.CommandButton CMDLT 
      Caption         =   "LAST"
      Height          =   495
      Left            =   10080
      TabIndex        =   26
      Top             =   5040
      Width           =   855
   End
   Begin VB.CommandButton CMDPV 
      Caption         =   "PREV"
      Height          =   495
      Left            =   9240
      TabIndex        =   25
      Top             =   5040
      Width           =   855
   End
   Begin VB.CommandButton CMDNT 
      Caption         =   "NEXT"
      Height          =   495
      Left            =   8400
      TabIndex        =   24
      Top             =   5040
      Width           =   855
   End
   Begin VB.CommandButton CMDFT 
      Caption         =   "FIRST"
      Height          =   495
      Left            =   7440
      TabIndex        =   23
      Top             =   5040
      Width           =   975
   End
   Begin VB.CommandButton CMDDT 
      Caption         =   "DELET"
      Height          =   615
      Left            =   3600
      TabIndex        =   22
      Top             =   4920
      Width           =   1095
   End
   Begin VB.CommandButton CMDET 
      Caption         =   "EDIT"
      Height          =   615
      Left            =   2640
      TabIndex        =   21
      Top             =   4920
      Width           =   1095
   End
   Begin VB.TextBox TPH 
      Height          =   285
      Left            =   2400
      TabIndex        =   7
      Top             =   3720
      Width           =   1575
   End
   Begin VB.TextBox TROLL 
      Height          =   315
      Left            =   2400
      TabIndex        =   0
      Top             =   1560
      Width           =   1575
   End
   Begin VB.TextBox TNM 
      Height          =   285
      Left            =   6240
      TabIndex        =   1
      Top             =   1560
      Width           =   1575
   End
   Begin VB.TextBox TADDR 
      Height          =   315
      Left            =   2400
      TabIndex        =   2
      Top             =   2280
      Width           =   1575
   End
   Begin VB.TextBox TAGE 
      Height          =   285
      Left            =   6240
      TabIndex        =   5
      Top             =   2880
      Width           =   1575
   End
   Begin VB.ComboBox CMBYR 
      Height          =   315
      Left            =   6360
      TabIndex        =   8
      Top             =   3480
      Width           =   1455
   End
   Begin VB.CommandButton CMDADD 
      Caption         =   "ADD"
      Height          =   615
      Left            =   9240
      TabIndex        =   17
      Top             =   1560
      Width           =   1215
   End
   Begin VB.CommandButton CMDSV 
      Caption         =   "SAVE"
      Height          =   615
      Left            =   1560
      TabIndex        =   12
      Top             =   4920
      Width           =   1095
   End
   Begin VB.Label LGEN 
      BackStyle       =   0  'Transparent
      Caption         =   "GENDER"
      BeginProperty Font 
         Name            =   "Rockwell Extra Bold"
         Size            =   9.75
         Charset         =   0
         Weight          =   800
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00800080&
      Height          =   255
      Left            =   6600
      TabIndex        =   50
      Top             =   6960
      Width           =   2055
   End
   Begin VB.Label LYRSTU 
      BackStyle       =   0  'Transparent
      Caption         =   "YEAR OF STUDENT"
      BeginProperty Font 
         Name            =   "Rockwell Extra Bold"
         Size            =   9.75
         Charset         =   0
         Weight          =   800
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00800080&
      Height          =   255
      Left            =   8400
      TabIndex        =   49
      Top             =   6960
      Width           =   2055
   End
   Begin VB.Label Label6 
      BackStyle       =   0  'Transparent
      Caption         =   "ROLL"
      BeginProperty Font 
         Name            =   "Times New Roman"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   375
      Left            =   960
      TabIndex        =   40
      Top             =   1560
      Width           =   1455
   End
   Begin VB.Label Label5 
      BackStyle       =   0  'Transparent
      Caption         =   "GENDER"
      BeginProperty Font 
         Name            =   "Times New Roman"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   495
      Left            =   8040
      TabIndex        =   38
      Top             =   2880
      Width           =   1215
   End
   Begin VB.Label Label3 
      BackStyle       =   0  'Transparent
      Caption         =   "YEAR OF ADDMISSION"
      BeginProperty Font 
         Name            =   "Times New Roman"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   735
      Left            =   4800
      TabIndex        =   37
      Top             =   4200
      Width           =   1575
   End
   Begin VB.Label Label13 
      BackStyle       =   0  'Transparent
      Caption         =   "FOR STUDENTS IN OUR DEPATMENT"
      BeginProperty Font 
         Name            =   "Niagara Engraved"
         Size            =   36
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000040C0&
      Height          =   855
      Left            =   2280
      TabIndex        =   36
      Top             =   360
      Width           =   6255
   End
   Begin VB.Label Label12 
      BackStyle       =   0  'Transparent
      Caption         =   "DATE OF BIRTH"
      BeginProperty Font 
         Name            =   "Times New Roman"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   735
      Left            =   360
      TabIndex        =   33
      Top             =   4440
      Width           =   2175
   End
   Begin VB.Label Label4 
      Caption         =   "Label4"
      Height          =   255
      Left            =   120
      TabIndex        =   32
      Top             =   1680
      Width           =   15
   End
   Begin VB.Label Label2 
      BackStyle       =   0  'Transparent
      Caption         =   "PIN CODE"
      BeginProperty Font 
         Name            =   "Times New Roman"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   495
      Left            =   960
      TabIndex        =   29
      Top             =   3120
      Width           =   1575
   End
   Begin VB.Label Label1 
      BackStyle       =   0  'Transparent
      Caption         =   "CITY"
      BeginProperty Font 
         Name            =   "Times New Roman"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   495
      Left            =   5040
      TabIndex        =   28
      Top             =   2280
      Width           =   1215
   End
   Begin VB.Label LTIME 
      BackStyle       =   0  'Transparent
      BeginProperty Font 
         Name            =   "Times New Roman"
         Size            =   24
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   615
      Left            =   9720
      TabIndex        =   20
      Top             =   240
      Width           =   1935
   End
   Begin VB.Label LDATE 
      BackStyle       =   0  'Transparent
      BeginProperty Font 
         Name            =   "Times New Roman"
         Size            =   24
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   615
      Left            =   0
      TabIndex        =   19
      Top             =   240
      Width           =   2415
   End
   Begin VB.Label LPH 
      BackStyle       =   0  'Transparent
      Caption         =   "PHONE NO"
      BeginProperty Font 
         Name            =   "Times New Roman"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   735
      Left            =   960
      TabIndex        =   18
      Top             =   3720
      Width           =   1575
   End
   Begin VB.Label LYR 
      BackStyle       =   0  'Transparent
      Caption         =   "YEAR OF STUDENTS"
      BeginProperty Font 
         Name            =   "Times New Roman"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   735
      Left            =   4920
      TabIndex        =   16
      Top             =   3480
      Width           =   1455
   End
   Begin VB.Label LAGE 
      BackStyle       =   0  'Transparent
      Caption         =   "AGE"
      BeginProperty Font 
         Name            =   "Times New Roman"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   375
      Left            =   5160
      TabIndex        =   15
      Top             =   2880
      Width           =   1455
   End
   Begin VB.Label LADDR 
      BackStyle       =   0  'Transparent
      Caption         =   "ADDRESS"
      BeginProperty Font 
         Name            =   "Times New Roman"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   375
      Left            =   960
      TabIndex        =   14
      Top             =   2400
      Width           =   1455
   End
   Begin VB.Label LNM 
      BackStyle       =   0  'Transparent
      Caption         =   "NAME"
      BeginProperty Font 
         Name            =   "Times New Roman"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   375
      Left            =   4920
      TabIndex        =   11
      Top             =   1560
      Width           =   1455
   End
End
Attribute VB_Name = "FORMSTUDENT"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim cn As ADODB.Connection, cmd As ADODB.Command
Dim rs As ADODB.Recordset
Dim s, S1, S2 As String
Dim i As Integer
Dim nrollno As Long
Option Compare Text


Private Sub CMBGEN1_Click()
CMDOK.Visible = True
If (CMBGEN1.Text = "MALE") Then
  DataGrid4.Visible = True
End If
If (CMBGEN1.Text = "FEMALE") Then
  DataGrid5.Visible = True
End If
End Sub

Private Sub CMBYRSTU_Click()
If (CMBYRSTU.Text = "1st") Then
DataGrid1.Visible = True
End If
If (CMBYRSTU.Text = "2nd") Then
DataGrid2.Visible = True
End If
If (CMBYRSTU.Text = "3rd") Then
DataGrid3.Visible = True
End If
End Sub

Private Sub CMDADD_Click()
TROLL.Enabled = True
TNM.Enabled = True
TADDR.Enabled = True
CMBYR.Enabled = True
TAGE.Enabled = True
TPH.Enabled = True
TCITY.Enabled = True
TPIN.Enabled = True
Tdob.Enabled = True
CMBGEN.Enabled = True
CMBYRADMIN.Enabled = True
TROLL.SetFocus
End Sub

Private Sub CMDCL_Click()
TROLL.Text = " "
TNM.Text = " "
TADDR.Text = " "
CMBYR.Text = " "
TAGE.Text = " "
TPH.Text = " "
TCITY.Text = " '"
TPIN.Text = " "
Tdob.Text = ""
CMBGEN.Text = ""
CMBYRADMIN.Text = ""
End Sub

Private Sub CMDDT_Click()
If MsgBox("Are you sure to delete the record?", vbQuestion + vbYesNo, App.ProductName) = vbYes Then
     rs.Delete adAffectCurrent
     If Not rs.EOF Then
            rs.MoveNext
     Else
            rs.MovePrevious
            Display
     End If
     Display
  End If
  TROLL.Text = " "
TNM.Text = " "
TADDR.Text = " "
CMBYR.Text = " "
TAGE.Text = " "
TPH.Text = " "
TCITY.Text = " '"
TPIN.Text = " "
Tdob.Text = ""
CMBGEN.Text = ""
CMBYRADMIN.Text = ""
End Sub

Private Sub CMDET_Click()
OPTBYTELNO.Visible = True
OPTBYROLL.Visible = True
End Sub

Private Sub CMDEX_Click()
Formmenu.Show
End Sub

Private Sub CMDFT_Click()
If Not rs.BOF Then
     rs.MoveFirst
     Display
Else
  MsgBox "u r in the 1st record"
End If

End Sub


Private Sub CMDLST_Click()
OPTYRSTU.Visible = True
OPTGEN.Visible = True
CMBYRSTU.Visible = True
LYRSTU.Visible = True
CMDOK.Visible = True
LGEN.Visible = True
CMBGEN1.Visible = True
End Sub

Private Sub CMDLT_Click()
If Not rs.EOF Then
   rs.MoveLast
   Display
   Else
    MsgBox "u are in the last record!"
    Display
 End If
End Sub

Private Sub CMDNT_Click()
If Not rs.EOF Then
     rs.MoveNext
     Display
     End If
End Sub

Private Sub CMDOK_Click()
DataGrid1.Visible = False
DataGrid2.Visible = False
DataGrid3.Visible = False
DataGrid4.Visible = False
DataGrid5.Visible = False
CMBYRSTU.Visible = False
LYRSTU.Visible = False
CMDOK.Visible = False
OPTGEN.Visible = False
OPTGEN = False
OPTYRSTU.Visible = False
OPTYRSTU = False
LGEN.Visible = False
CMBGEN1.Visible = False
CMBGEN1.Text = ""
CMBYRSTU.Text = ""
End Sub

Private Sub CMDPV_Click()
If Not rs.BOF Then
      rs.MovePrevious
      Display
      Else
        Display
    End If
End Sub


Private Sub CMDSV_Click()
Set cn = New ADODB.Connection
Set cmd = New ADODB.Command
cn.Open "dsn=project;uid=scott;pwd=tiger"
Dim s As String
If isvalid Then
s = "insert into student(roll,name,addr,city,pin,age,ph_no,yr_of_stu,dob,yr_of_admin,gender)values(" + TROLL.Text + ",' " + TNM.Text + " ',' " + TADDR.Text + " ',' " + TCITY.Text + " '," + TPIN.Text + "," + TAGE.Text + "," + TPH.Text + ",' " + CMBYR.Text + " ',' " + Tdob.Text + " '," + CMBYRADMIN.Text + ",' " + CMBGEN.Text + " ')"
cmd.ActiveConnection = cn
cmd.CommandText = s
cmd.Execute
MsgBox "SUCESSFULLY INSERTED"
End If
End Sub

Private Sub CUP_Click()
 rs("ROLL") = TROLL.Text
         rs("NAME") = TNM.Text
         rs("ADDR") = TADDR.Text
         rs("AGE") = Val(TAGE.Text)
         rs("PIN") = Val(TPIN.Text)
         rs("CITY") = TCITY.Text
         rs("PH_NO") = Val(TPH.Text)
         rs("YR_OF_STU") = CMBYR.Text
         rs("dob") = Tdob.Text
         rs("YR_OF_ADMIN") = Val(CMBYRADMIN.Text)
         rs("GENDER") = CMBGEN.Text
         MsgBox "SUCESSFULLY UPDATED"
 rs.Update
TROLL.Text = " "
TNM.Text = " "
TADDR.Text = " "
CMBYR.Text = " "
TAGE.Text = " "
TPH.Text = " "
TCITY.Text = " '"
TPIN.Text = " "
Tdob.Text = ""
CMBYRADMIN.Text = ""
CMBGEN.Text = ""
 OPTBYTELNO.Visible = False
 OPTBYROLL.Visible = False
 OPTBYROLL = False
 OPTBYTELNO = False
End Sub




Private Sub Form_Load()
Dim j As Integer
j = 0
Set cn = New ADODB.Connection
Set cmd = New ADODB.Command
Set rs = New ADODB.Recordset
cn.Open "dsn=project;uid=scott;pwd=tiger"
rs.Open "student", cn, adOpenDynamic, adLockOptimistic
CMBYR.AddItem "1st", 0
CMBYR.AddItem "2nd", 1
CMBYR.AddItem "3rd", 2
CMBGEN.AddItem "MALE", 0
CMBGEN.AddItem "FEMALE", 1
CMBGEN1.AddItem "MALE", 0
CMBGEN1.AddItem "FEMALE", 1
CMBYRSTU.AddItem "1st", 0
CMBYRSTU.AddItem "2nd", 1
CMBYRSTU.AddItem "3rd", 2
LGEN.Visible = False
CMBGEN1.Visible = False
LYRSTU.Visible = False
CMBYRSTU.Visible = False
Adodc1.Visible = False
DataGrid1.Visible = False
Adodc2.Visible = False
DataGrid2.Visible = False
Adodc3.Visible = False
DataGrid3.Visible = False
Adodc4.Visible = False
DataGrid4.Visible = False
Adodc5.Visible = False
DataGrid5.Visible = False
CMDOK.Visible = False
OPTYRSTU.Visible = False
OPTGEN.Visible = False
For i = 1950 To 2025
 CMBYRADMIN.AddItem i, j
 j = j + 1
Next i
LDATE = Date
CMDOK.Visible = False
TROLL.Enabled = False
TNM.Enabled = False
TADDR.Enabled = False
CMBYR.Enabled = False
TAGE.Enabled = False
TPH.Enabled = False
TCITY.Enabled = False
TPIN.Enabled = False
Tdob.Enabled = False
CMBGEN.Enabled = False
CMBYRADMIN.Enabled = False
OPTBYROLL.Visible = False
OPTBYTELNO.Visible = False
End Sub


Private Sub OPTBYROLL_Click()
If OPTBYROLL = True Then
        nrollno = Val(InputBox("Insert appropriate rollno to search"))
        rs.Find " ROLL like " & nrollno
        TROLL.Text = nrollno
        TNM.Text = rs("NAME")
        TADDR.Text = rs("ADDR")
        TCITY.Text = rs("CITY")
        TPIN.Text = CStr(rs("PIN"))
        TAGE.Text = CStr(rs("AGE"))
        TPH.Text = CStr(rs("PH_NO"))
        CMBYR.Text = rs("YR_OF_STU")
        Tdob.Text = rs("DOB")
        CMBYRADMIN.Text = CStr(rs("YR_OF_ADMIN"))
        CMBGEN.Text = rs("GENDER")
        edit1
 End If
End Sub

Private Sub OPTBYTELNO_Click()
If OPTBYTELNO = True Then
       Dim nTelno As Long
        nTelno = Val(InputBox("Insert appropriate telno to search"))
        rs.Find "PH_NO=" & nTelno
        TPH.Text = nTelno
        TROLL.Text = rs("ROLL")
        TNM.Text = rs("NAME")
        TADDR.Text = rs("ADDR")
        TCITY.Text = rs("CITY")
        TAGE.Text = CStr(rs("AGE"))
        TPIN.Text = CStr(rs("PIN"))
        CMBYR.Text = rs("YR_OF_STU")
         Tdob.Text = rs("DOB")
         CMBYRADMIN.Text = CStr(rs("YR_OF_ADMIN"))
         CMBGEN.Text = rs("GENDER")
        edit1
 End If
End Sub




Private Sub OPTGEN_Click()
CMDOK.Visible = True
Dim STR As String
STR = InputBox(" ENTER THE GENDER WHICH U WANT TO SEARCH")
If (STR = "MALE") Then
  DataGrid4.Visible = True
End If
If (STR = "FEMALE") Then
  DataGrid5.Visible = True
End If
End Sub

Private Sub OPTYRSTU_Click()
CMDOK.Visible = True
Dim STR As String
STR = InputBox(" ENTER THE YEAR OF STUDENT WHICH U WANT TO SEARCH")
If (STR = "1st") Then
  DataGrid1.Visible = True
End If
If (STR = "2nd") Then
  DataGrid2.Visible = True
End If
If (STR = "3rd") Then
  DataGrid3.Visible = True
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
Private Sub edit1()
 If MsgBox("Are you sure to edit the record?", vbQuestion + vbYesNo, App.ProductName) = vbYes Then
    TROLL.Enabled = True
    TNM.Enabled = True
    TADDR.Enabled = True
    TAGE.Enabled = True
    TPIN.Enabled = True
    TCITY.Enabled = True
    TPH.Enabled = True
    CMBYR.Enabled = True
    Tdob.Enabled = True
    CMBYRADMIN.Enabled = True
    CMBGEN.Enabled = True
    TROLL.SetFocus
Else
        MsgBox "perform next operation"
End If

End Sub

Private Sub Display()
If Not rs.EOF Then
      TROLL.Text = CStr(rs("ROLL"))
      TNM.Text = rs("NAME")
     TADDR.Text = rs("ADDR")
     TAGE.Text = CStr(rs("AGE"))
     TCITY.Text = rs("CITY")
     TPIN.Text = CStr(rs("PIN"))
     TPH.Text = CStr(rs("PH_NO"))
     CMBYR.Text = rs("YR_OF_STU")
     Tdob.Text = rs("DOB")
     CMBYRADMIN.Text = CStr(rs("YR_OF_ADMIN"))
     CMBGEN.Text = rs("GENDER")
End If

End Sub
Private Function isvalid() As Boolean

    
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
        MsgBox "Name can not be blank!"
        TextNAME.SetFocus
        Exit Function
     Else
        isvalid = True
     End If

     If Len(Trim(TADDR.Text)) = 0 Then
        isvalid = False
        MsgBox "Address line can not be blank!"
        TADDR.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
     If Len(Trim(TCITY.Text)) = 0 Then
        isvalid = False
        MsgBox "CITY can not be blank!"
        TCITY.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
    If Len(Trim(TPIN.Text)) = 0 Then
        isvalid = False
        MsgBox "Pin Code can not be blank!"
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
        MsgBox "PHONE line  can not be blank!"
        TPH.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
     If Len(Trim(CMBYR.Text)) = 0 Then
        isvalid = False
        MsgBox "Year of student can not be blank!"
        CMBYR.SetFocus
        Exit Function
     Else
        isvalid = True
     End If

      If Len(Trim(Tdob.Text)) = 0 Then
        isvalid = False
        MsgBox "DOB line  can not be blank!"
        Tdob.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
     If Len(Trim(CMBYRADMIN.Text)) = 0 Then
        isvalid = False
        MsgBox "YEAR OF ADDMISSION can not be blank!"
        CMBYRADMIN.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
       If Len(Trim(CMBGEN.Text)) = 0 Then
        isvalid = False
        MsgBox "GENDER of student can not be blank!"
        CMBGEN.SetFocus
        Exit Function
     Else
        isvalid = True
     End If
End Function

Private Sub TROLL_KeyPress(KeyAscii As Integer)
If (KeyAscii >= Asc("0") And KeyAscii <= Asc("9")) Then
     KeyAscii = KeyAscii
Else
      MsgBox "INSERT ANY INTEGER NUMBER"
      KeyAscii = 0
 End If
End Sub
