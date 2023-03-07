VERSION 5.00
Begin VB.Form Form14 
   Caption         =   "Form14"
   ClientHeight    =   5265
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6705
   LinkTopic       =   "Form14"
   ScaleHeight     =   5265
   ScaleWidth      =   6705
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command7 
      Caption         =   "M A I N  M E N U"
      Height          =   735
      Left            =   2040
      TabIndex        =   6
      Top             =   4080
      Width           =   2295
   End
   Begin VB.CommandButton Command6 
      Caption         =   "View Depositor"
      Height          =   255
      Left            =   3600
      TabIndex        =   5
      Top             =   3480
      Width           =   1695
   End
   Begin VB.CommandButton Command5 
      Caption         =   "View Borrower"
      Height          =   255
      Left            =   3600
      TabIndex        =   4
      Top             =   3000
      Width           =   1695
   End
   Begin VB.CommandButton Command4 
      Caption         =   "View Account"
      Height          =   255
      Left            =   3600
      TabIndex        =   3
      Top             =   2520
      Width           =   1695
   End
   Begin VB.CommandButton Command3 
      Caption         =   "View Loan"
      Height          =   255
      Left            =   3600
      TabIndex        =   2
      Top             =   2040
      Width           =   1695
   End
   Begin VB.CommandButton Command2 
      Caption         =   "View Customer"
      Height          =   255
      Left            =   3600
      TabIndex        =   1
      Top             =   1560
      Width           =   1695
   End
   Begin VB.CommandButton Command1 
      Caption         =   "View Branch"
      Height          =   255
      Left            =   3600
      TabIndex        =   0
      Top             =   1080
      Width           =   1695
   End
   Begin VB.Label Label8 
      AutoSize        =   -1  'True
      Caption         =   "V I E W"
      Height          =   195
      Left            =   2880
      TabIndex        =   14
      Top             =   360
      Width           =   555
   End
   Begin VB.Label Label7 
      AutoSize        =   -1  'True
      Caption         =   "DEPOSITOR Table"
      Height          =   195
      Left            =   960
      TabIndex        =   13
      Top             =   3480
      Width           =   1395
   End
   Begin VB.Label Label6 
      AutoSize        =   -1  'True
      Caption         =   "BORROWER Table"
      Height          =   195
      Left            =   960
      TabIndex        =   12
      Top             =   3000
      Width           =   1425
   End
   Begin VB.Label Label5 
      AutoSize        =   -1  'True
      Caption         =   "ACCOUNT Table"
      Height          =   195
      Left            =   960
      TabIndex        =   11
      Top             =   2520
      Width           =   1230
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "LOAN Table"
      Height          =   195
      Left            =   960
      TabIndex        =   10
      Top             =   2040
      Width           =   885
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "CUSTOMER Table"
      Height          =   195
      Left            =   960
      TabIndex        =   9
      Top             =   1560
      Width           =   1365
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "BRANCH Table"
      Height          =   195
      Left            =   960
      TabIndex        =   8
      Top             =   1080
      Width           =   1125
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "M A I N  F O R M"
      Height          =   195
      Left            =   2520
      TabIndex        =   7
      Top             =   720
      Width           =   1230
   End
End
Attribute VB_Name = "Form14"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    Form8.Show
    Hide
End Sub

Private Sub Command2_Click()
    Form9.Show
    Hide
End Sub

Private Sub Command3_Click()
    Form10.Show
    Hide
End Sub

Private Sub Command4_Click()
    Form11.Show
    Hide
End Sub

Private Sub Command5_Click()
    Form12.Show
    Hide
End Sub

Private Sub Command6_Click()
    Form13.Show
    Hide
End Sub

Private Sub Command7_Click()
    Form15.Show
    Hide
End Sub


