VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   5145
   ClientLeft      =   1485
   ClientTop       =   930
   ClientWidth     =   6570
   LinkTopic       =   "Form1"
   ScaleHeight     =   5145
   ScaleWidth      =   6570
   Begin VB.CommandButton Command8 
      Caption         =   "BACK"
      Height          =   735
      Left            =   1440
      TabIndex        =   14
      Top             =   4320
      Width           =   2775
   End
   Begin VB.CommandButton Command7 
      Caption         =   "INSERT"
      Height          =   375
      Left            =   3000
      TabIndex        =   13
      Top             =   3840
      Width           =   2655
   End
   Begin VB.CommandButton Command6 
      Caption         =   "INSERT"
      Height          =   255
      Left            =   3000
      TabIndex        =   12
      Top             =   3240
      Width           =   2655
   End
   Begin VB.CommandButton Command5 
      Caption         =   "INSERT"
      Height          =   375
      Left            =   3000
      TabIndex        =   11
      Top             =   2640
      Width           =   2655
   End
   Begin VB.CommandButton Command4 
      Caption         =   "INSERT"
      Height          =   255
      Left            =   3000
      TabIndex        =   10
      Top             =   2160
      Width           =   2655
   End
   Begin VB.CommandButton Command3 
      Caption         =   "INSERT"
      Height          =   375
      Left            =   3000
      TabIndex        =   9
      Top             =   1560
      Width           =   2655
   End
   Begin VB.CommandButton Command2 
      Caption         =   "INSERT"
      Height          =   195
      Left            =   3120
      TabIndex        =   8
      Top             =   1200
      Width           =   2415
   End
   Begin VB.CommandButton Command1 
      Caption         =   "INSERT"
      Height          =   255
      Left            =   3120
      TabIndex        =   7
      Top             =   600
      Width           =   2415
   End
   Begin VB.Label Label8 
      Alignment       =   2  'Center
      Caption         =   "INSERT"
      Height          =   375
      Left            =   1680
      TabIndex        =   15
      Top             =   120
      Width           =   2295
   End
   Begin VB.Label Label7 
      AutoSize        =   -1  'True
      Caption         =   "ENROLL"
      Height          =   195
      Left            =   480
      TabIndex        =   6
      Top             =   3840
      Width           =   645
   End
   Begin VB.Label Label6 
      AutoSize        =   -1  'True
      Caption         =   "SECTION"
      Height          =   195
      Left            =   480
      TabIndex        =   5
      Top             =   3240
      Width           =   705
   End
   Begin VB.Label Label5 
      AutoSize        =   -1  'True
      Caption         =   "MAJOR"
      Height          =   195
      Left            =   480
      TabIndex        =   4
      Top             =   2760
      Width           =   555
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "COURSE"
      Height          =   195
      Left            =   480
      TabIndex        =   3
      Top             =   2160
      Width           =   675
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "PROFESSOR"
      Height          =   195
      Left            =   480
      TabIndex        =   2
      Top             =   1560
      Width           =   990
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "DEPARTMENT"
      Height          =   195
      Left            =   480
      TabIndex        =   1
      Top             =   1080
      Width           =   1125
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "STUDENT"
      Height          =   195
      Left            =   480
      TabIndex        =   0
      Top             =   600
      Width           =   780
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    Hide
    Form2.Show
End Sub

Private Sub Command2_Click()
    Hide
    Form8.Show
End Sub

Private Sub Command3_Click()
    Hide
    Form3.Show
End Sub

Private Sub Command4_Click()
    Hide
    Form4.Show
End Sub

Private Sub Command5_Click()
    Hide
    Form5.Show
End Sub

Private Sub Command6_Click()
    Hide
    Form6.Show
End Sub

Private Sub Command7_Click()
    Hide
    Form7.Show
End Sub

Private Sub Command8_Click()
    Hide
    Form17.Show
End Sub

