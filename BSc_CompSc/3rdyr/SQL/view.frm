VERSION 5.00
Begin VB.Form Form9 
   Caption         =   "Form9"
   ClientHeight    =   5130
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   7500
   LinkTopic       =   "Form9"
   ScaleHeight     =   5130
   ScaleWidth      =   7500
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "VIEW"
      Height          =   255
      Left            =   3840
      TabIndex        =   7
      Top             =   600
      Width           =   2415
   End
   Begin VB.CommandButton Command2 
      Caption         =   "VIEW"
      Height          =   195
      Left            =   3840
      TabIndex        =   6
      Top             =   1200
      Width           =   2415
   End
   Begin VB.CommandButton Command3 
      Caption         =   "VIEW"
      Height          =   375
      Left            =   3720
      TabIndex        =   5
      Top             =   1560
      Width           =   2655
   End
   Begin VB.CommandButton Command4 
      Caption         =   "VIEW"
      Height          =   255
      Left            =   3720
      TabIndex        =   4
      Top             =   2160
      Width           =   2655
   End
   Begin VB.CommandButton Command5 
      Caption         =   "VIEW"
      Height          =   375
      Left            =   3720
      TabIndex        =   3
      Top             =   2640
      Width           =   2655
   End
   Begin VB.CommandButton Command6 
      Caption         =   "VIEW"
      Height          =   255
      Left            =   3720
      TabIndex        =   2
      Top             =   3240
      Width           =   2655
   End
   Begin VB.CommandButton Command7 
      Caption         =   "VIEW"
      Height          =   375
      Left            =   3720
      TabIndex        =   1
      Top             =   3840
      Width           =   2655
   End
   Begin VB.CommandButton Command8 
      Caption         =   "BACK"
      Height          =   735
      Left            =   2160
      TabIndex        =   0
      Top             =   4320
      Width           =   2775
   End
   Begin VB.Label Label8 
      Alignment       =   2  'Center
      Caption         =   "VIEW"
      Height          =   375
      Left            =   2400
      TabIndex        =   15
      Top             =   120
      Width           =   2295
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "STUDENT"
      Height          =   195
      Left            =   1200
      TabIndex        =   14
      Top             =   600
      Width           =   780
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "DEPARTMENT"
      Height          =   195
      Left            =   1200
      TabIndex        =   13
      Top             =   1080
      Width           =   1125
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "PROFESSOR"
      Height          =   195
      Left            =   1200
      TabIndex        =   12
      Top             =   1560
      Width           =   990
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "COURSE"
      Height          =   195
      Left            =   1200
      TabIndex        =   11
      Top             =   2160
      Width           =   675
   End
   Begin VB.Label Label5 
      AutoSize        =   -1  'True
      Caption         =   "MAJOR"
      Height          =   195
      Left            =   1200
      TabIndex        =   10
      Top             =   2760
      Width           =   555
   End
   Begin VB.Label Label6 
      AutoSize        =   -1  'True
      Caption         =   "SECTION"
      Height          =   195
      Left            =   1200
      TabIndex        =   9
      Top             =   3240
      Width           =   705
   End
   Begin VB.Label Label7 
      AutoSize        =   -1  'True
      Caption         =   "ENROLL"
      Height          =   195
      Left            =   1200
      TabIndex        =   8
      Top             =   3840
      Width           =   645
   End
End
Attribute VB_Name = "Form9"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    Hide
    Form16.Show
End Sub

Private Sub Command2_Click()
    Hide
    Form15.Show
End Sub

Private Sub Command3_Click()
    Hide
    Form14.Show
End Sub

Private Sub Command4_Click()
    Hide
    Form13.Show
End Sub

Private Sub Command5_Click()
    Hide
    Form12.Show
End Sub

Private Sub Command6_Click()
    Hide
    Form11.Show
End Sub

Private Sub Command7_Click()
    Hide
    Form10.Show
End Sub

Private Sub Command8_Click()
    Hide
    Form17.Show
End Sub


