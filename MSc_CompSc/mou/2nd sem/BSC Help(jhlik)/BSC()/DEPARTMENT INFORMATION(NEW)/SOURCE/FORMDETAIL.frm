VERSION 5.00
Begin VB.Form FORMDETAIL 
   BackColor       =   &H00C0FFFF&
   Caption         =   "FormDETAIL"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   11010
   ScaleWidth      =   15240
   StartUpPosition =   3  'Windows Default
   WindowState     =   2  'Maximized
   Begin VB.CommandButton CMDEX 
      Caption         =   "EXIT"
      Height          =   975
      Left            =   3240
      TabIndex        =   9
      Top             =   7440
      Width           =   3375
   End
   Begin VB.Frame Frame4 
      BackColor       =   &H00FFC0C0&
      Caption         =   "Frame4"
      Height          =   1335
      Left            =   6600
      TabIndex        =   5
      Top             =   2280
      Width           =   3855
      Begin VB.Label Label4 
         BackStyle       =   0  'Transparent
         Caption         =   "FORMFACULTY"
         BeginProperty Font 
            Name            =   "Niagara Engraved"
            Size            =   36
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00FF0000&
         Height          =   615
         Left            =   480
         TabIndex        =   6
         Top             =   360
         Width           =   2895
      End
   End
   Begin VB.Frame Frame3 
      BackColor       =   &H0080C0FF&
      Caption         =   "Frame1"
      Height          =   1335
      Left            =   1320
      TabIndex        =   2
      Top             =   4920
      Width           =   3855
      Begin VB.Label Label3 
         BackStyle       =   0  'Transparent
         Caption         =   "FORM ADDMISSION"
         BeginProperty Font 
            Name            =   "Onyx"
            Size            =   27.75
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H000040C0&
         Height          =   735
         Left            =   480
         TabIndex        =   7
         Top             =   360
         Width           =   3375
      End
   End
   Begin VB.Frame Frame2 
      BackColor       =   &H0080FF80&
      Caption         =   "Frame1"
      Height          =   1335
      Left            =   6600
      TabIndex        =   1
      Top             =   4920
      Width           =   3855
      Begin VB.Label Label5 
         BackStyle       =   0  'Transparent
         Caption         =   "FORMRESULT"
         BeginProperty Font 
            Name            =   "Palatino Linotype"
            Size            =   24
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00008000&
         Height          =   735
         Left            =   240
         TabIndex        =   8
         Top             =   360
         Width           =   3615
      End
   End
   Begin VB.Frame Frame1 
      BackColor       =   &H008080FF&
      Caption         =   "Frame1"
      Height          =   1335
      Left            =   1440
      TabIndex        =   0
      Top             =   2280
      Width           =   3855
      Begin VB.Label Label1 
         BackStyle       =   0  'Transparent
         Caption         =   "FORMSTUDENT"
         BeginProperty Font 
            Name            =   "Times New Roman"
            Size            =   21.75
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H000000FF&
         Height          =   615
         Left            =   360
         TabIndex        =   3
         Top             =   360
         Width           =   3375
      End
   End
   Begin VB.Label Label2 
      Caption         =   "Label1"
      Height          =   615
      Left            =   7080
      TabIndex        =   4
      Top             =   5400
      Width           =   2895
   End
End
Attribute VB_Name = "FORMDETAIL"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub CMDEX_Click()
Formmenu.Show
End Sub

Private Sub Label1_Click()
FORMSTUDENT.Show
End Sub

Private Sub Label3_Click()
FORMFACULTY.Show
End Sub

Private Sub Label4_Click()
FORMFACULTY.Show
End Sub

Private Sub Label5_Click()
FORMRESULT.Show
End Sub
