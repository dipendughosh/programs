VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Main"
   ClientHeight    =   5205
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6600
   LinkTopic       =   "Form1"
   ScaleHeight     =   5205
   ScaleWidth      =   6600
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command7 
      Caption         =   "M A I N  M E N U"
      Height          =   735
      Left            =   2040
      TabIndex        =   13
      Top             =   4080
      Width           =   2295
   End
   Begin VB.CommandButton Command6 
      Caption         =   "Insert into Depositor"
      Height          =   255
      Left            =   3600
      TabIndex        =   12
      Top             =   3480
      Width           =   1695
   End
   Begin VB.CommandButton Command5 
      Caption         =   "Insert into Borrower"
      Height          =   255
      Left            =   3600
      TabIndex        =   11
      Top             =   3000
      Width           =   1695
   End
   Begin VB.CommandButton Command4 
      Caption         =   "Insert Into Account"
      Height          =   255
      Left            =   3600
      TabIndex        =   10
      Top             =   2520
      Width           =   1695
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Insert Into Loan"
      Height          =   255
      Left            =   3600
      TabIndex        =   9
      Top             =   2040
      Width           =   1695
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Insert Into Customer"
      Height          =   255
      Left            =   3600
      TabIndex        =   8
      Top             =   1560
      Width           =   1695
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Insert Into Branch"
      Height          =   255
      Left            =   3600
      TabIndex        =   7
      Top             =   1080
      Width           =   1695
   End
   Begin VB.Label Label8 
      AutoSize        =   -1  'True
      Caption         =   "  I N S E R T"
      Height          =   195
      Left            =   2640
      TabIndex        =   14
      Top             =   360
      Width           =   915
   End
   Begin VB.Label Label7 
      AutoSize        =   -1  'True
      Caption         =   "DEPOSITOR Table"
      Height          =   195
      Left            =   960
      TabIndex        =   6
      Top             =   3480
      Width           =   1395
   End
   Begin VB.Label Label6 
      AutoSize        =   -1  'True
      Caption         =   "BORROWER Table"
      Height          =   195
      Left            =   960
      TabIndex        =   5
      Top             =   3000
      Width           =   1425
   End
   Begin VB.Label Label5 
      AutoSize        =   -1  'True
      Caption         =   "ACCOUNT Table"
      Height          =   195
      Left            =   960
      TabIndex        =   4
      Top             =   2520
      Width           =   1230
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "LOAN Table"
      Height          =   195
      Left            =   960
      TabIndex        =   3
      Top             =   2040
      Width           =   885
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "CUSTOMER Table"
      Height          =   195
      Left            =   960
      TabIndex        =   2
      Top             =   1560
      Width           =   1365
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "BRANCH Table"
      Height          =   195
      Left            =   960
      TabIndex        =   1
      Top             =   1080
      Width           =   1125
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "M A I N  F O R M"
      Height          =   195
      Left            =   2520
      TabIndex        =   0
      Top             =   720
      Width           =   1230
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub Command1_Click()
    Form2.Show
    Hide
End Sub

Private Sub Command2_Click()
    Form3.Show
    Hide
End Sub

Private Sub Command3_Click()
    Form4.Show
    Hide
End Sub

Private Sub Command4_Click()
    Form5.Show
    Hide
End Sub

Private Sub Command5_Click()
    Form6.Show
    Hide
End Sub

Private Sub Command6_Click()
    Form7.Show
    Hide
End Sub

Private Sub Command7_Click()
    Form15.Show
    Hide
End Sub
