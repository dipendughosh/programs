VERSION 5.00
Begin VB.Form Form14 
   Caption         =   "Main"
   ClientHeight    =   7995
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8130
   LinkTopic       =   "Form14"
   ScaleHeight     =   7995
   ScaleWidth      =   8130
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "E    X    I    T"
      BeginProperty Font 
         Name            =   "Monotype Corsiva"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   2040
      TabIndex        =   6
      Top             =   7440
      Width           =   3855
   End
   Begin VB.Frame Frame5 
      Caption         =   "Profit Database"
      BeginProperty Font 
         Name            =   "Modern"
         Size            =   9.75
         Charset         =   255
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   855
      Left            =   360
      TabIndex        =   5
      Top             =   6240
      Width           =   7335
      Begin VB.CommandButton Command12 
         Caption         =   "View Profit"
         BeginProperty Font 
            Name            =   "MS Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   2520
         TabIndex        =   17
         Top             =   360
         Width           =   2415
      End
   End
   Begin VB.Frame Frame4 
      Caption         =   "Result Database"
      BeginProperty Font 
         Name            =   "Modern"
         Size            =   9.75
         Charset         =   255
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   855
      Left            =   360
      TabIndex        =   4
      Top             =   5040
      Width           =   7335
      Begin VB.CommandButton Command11 
         Caption         =   "View Course Wise Result"
         BeginProperty Font 
            Name            =   "MS Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   5040
         TabIndex        =   16
         Top             =   360
         Width           =   2150
      End
      Begin VB.CommandButton Command10 
         Caption         =   "View Student Wise Result"
         BeginProperty Font 
            Name            =   "MS Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   2640
         TabIndex        =   15
         Top             =   360
         Width           =   2150
      End
      Begin VB.CommandButton Command9 
         Caption         =   "Insert Result Details"
         BeginProperty Font 
            Name            =   "MS Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   240
         TabIndex        =   14
         Top             =   360
         Width           =   2150
      End
   End
   Begin VB.Frame Frame3 
      Caption         =   "Course Database"
      BeginProperty Font 
         Name            =   "Modern"
         Size            =   9.75
         Charset         =   255
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   855
      Left            =   360
      TabIndex        =   3
      Top             =   3840
      Width           =   7335
      Begin VB.CommandButton Command8 
         Caption         =   "Update Course Details"
         BeginProperty Font 
            Name            =   "MS Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   2760
         TabIndex        =   13
         Top             =   360
         Width           =   1950
      End
      Begin VB.CommandButton Command7 
         Caption         =   "Print Course Details"
         BeginProperty Font 
            Name            =   "MS Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   5040
         TabIndex        =   12
         Top             =   360
         Width           =   1950
      End
      Begin VB.CommandButton Command6 
         Caption         =   "Insert Course Details"
         BeginProperty Font 
            Name            =   "MS Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   600
         TabIndex        =   11
         Top             =   360
         Width           =   1950
      End
   End
   Begin VB.Frame Frame2 
      Caption         =   "Instructor Database"
      BeginProperty Font 
         Name            =   "Modern"
         Size            =   9.75
         Charset         =   255
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   855
      Left            =   360
      TabIndex        =   2
      Top             =   2640
      Width           =   7335
      Begin VB.CommandButton Command5 
         Caption         =   "View Instructor Details"
         BeginProperty Font 
            Name            =   "MS Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   4680
         TabIndex        =   10
         Top             =   360
         Width           =   2150
      End
      Begin VB.CommandButton Command4 
         Caption         =   "Insert Instructor Details"
         BeginProperty Font 
            Name            =   "MS Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   600
         TabIndex        =   9
         Top             =   360
         Width           =   2150
      End
   End
   Begin VB.Frame Frame1 
      Caption         =   "Student Database"
      BeginProperty Font 
         Name            =   "Modern"
         Size            =   9.75
         Charset         =   255
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   855
      Left            =   360
      TabIndex        =   1
      Top             =   1440
      Width           =   7335
      Begin VB.CommandButton Command3 
         Caption         =   "View Student Details"
         BeginProperty Font 
            Name            =   "MS Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   4680
         TabIndex        =   8
         Top             =   360
         Width           =   2055
      End
      Begin VB.CommandButton Command2 
         Caption         =   "Insert Student Details"
         BeginProperty Font 
            Name            =   "MS Serif"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Left            =   600
         TabIndex        =   7
         Top             =   360
         Width           =   2055
      End
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Computer Wizard"
      BeginProperty Font 
         Name            =   "Monotype Corsiva"
         Size            =   27.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   855
      Left            =   720
      TabIndex        =   0
      Top             =   240
      Width           =   6735
   End
End
Attribute VB_Name = "Form14"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    Close
    Unload Form1
    Unload Form2
    Unload Form3
    Unload Form4
    Unload Form5
    Unload Form6
    MsgBox ("Exiting............")
    Unload Me
End Sub



Private Sub Command12_Click()
    Form13.Show
    Hide
End Sub

Private Sub Command2_Click()
    Form1.Show
    Hide
End Sub

Private Sub Command3_Click()
    Form2.Show
    Hide
End Sub

Private Sub Command4_Click()
    Form4.Show
    Hide
End Sub

Private Sub Command5_Click()
    Form5.Show
    Hide
End Sub

Private Sub Command6_Click()
    Form7.Show
    Hide
End Sub

Private Sub Command7_Click()
    Form9.Show
    Hide
End Sub

Private Sub Command8_Click()
    Form8.Show
    Hide
End Sub

