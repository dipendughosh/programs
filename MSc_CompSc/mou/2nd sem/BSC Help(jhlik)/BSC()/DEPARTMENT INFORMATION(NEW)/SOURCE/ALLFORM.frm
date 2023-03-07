VERSION 5.00
Begin VB.Form ALLFORM 
   BackColor       =   &H008080FF&
   Caption         =   "FormDETAIL"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   11010
   ScaleWidth      =   15240
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "EXIT"
      Height          =   855
      Left            =   4200
      TabIndex        =   4
      Top             =   6360
      Width           =   2775
   End
   Begin VB.Label LST 
      BackColor       =   &H00FF0000&
      Caption         =   "                      FORM STUDENT"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H008080FF&
      Height          =   1455
      Left            =   1680
      TabIndex        =   3
      Top             =   1680
      Width           =   3255
   End
   Begin VB.Label LFT 
      BackColor       =   &H00FF8080&
      Caption         =   "                                             FORM FACULTY"
      BeginProperty Font 
         Name            =   "Haettenschweiler"
         Size            =   24
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00C000C0&
      Height          =   1455
      Left            =   6840
      TabIndex        =   2
      Top             =   1680
      Width           =   3375
   End
   Begin VB.Label LADD 
      BackColor       =   &H0000FF00&
      Caption         =   "           FORM ADDMISSION"
      BeginProperty Font 
         Name            =   "Rockwell"
         Size            =   21.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1575
      Left            =   1680
      TabIndex        =   1
      Top             =   3720
      Width           =   3375
   End
   Begin VB.Label LRT 
      BackColor       =   &H0080C0FF&
      Caption         =   "                                          FORM RESULT"
      BeginProperty Font 
         Name            =   "Niagara Engraved"
         Size            =   27.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H000000FF&
      Height          =   1695
      Left            =   6840
      TabIndex        =   0
      Top             =   3600
      Width           =   3495
   End
End
Attribute VB_Name = "ALLFORM"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Formmenu.Show
End Sub
