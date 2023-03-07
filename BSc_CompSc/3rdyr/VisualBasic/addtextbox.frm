VERSION 5.00
Begin VB.Form Form1 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Form1"
   ClientHeight    =   3930
   ClientLeft      =   45
   ClientTop       =   435
   ClientWidth     =   4560
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3930
   ScaleWidth      =   4560
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton ClearBtn 
      Caption         =   "&Clear"
      Height          =   495
      Left            =   1440
      TabIndex        =   8
      ToolTipText     =   "Clear All"
      Top             =   3360
      Width           =   1215
   End
   Begin VB.CommandButton ExitBtn 
      Cancel          =   -1  'True
      Caption         =   "E&xit"
      Height          =   375
      Left            =   2280
      TabIndex        =   4
      ToolTipText     =   "Exit"
      Top             =   2880
      Width           =   1575
   End
   Begin VB.CommandButton GoBtn 
      Caption         =   "&Go"
      Default         =   -1  'True
      Height          =   375
      Left            =   240
      TabIndex        =   3
      ToolTipText     =   "Start:"
      Top             =   2880
      Width           =   1575
   End
   Begin VB.TextBox Txtbox3 
      Alignment       =   1  'Right Justify
      Height          =   375
      Left            =   2280
      Locked          =   -1  'True
      TabIndex        =   2
      Text            =   "0"
      Top             =   2040
      Width           =   1575
   End
   Begin VB.TextBox Txtbox2 
      Alignment       =   1  'Right Justify
      Height          =   375
      Left            =   2280
      TabIndex        =   1
      ToolTipText     =   "Enter Number:"
      Top             =   1320
      Width           =   1575
   End
   Begin VB.TextBox Txtbox1 
      Alignment       =   1  'Right Justify
      Height          =   375
      Left            =   2280
      TabIndex        =   0
      ToolTipText     =   "Enter Number:"
      Top             =   600
      Width           =   1575
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "Result"
      Height          =   195
      Left            =   240
      TabIndex        =   7
      Top             =   2040
      Width           =   450
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "Input 2"
      Height          =   195
      Left            =   240
      TabIndex        =   6
      Top             =   1320
      Width           =   495
   End
   Begin VB.Label label1 
      AutoSize        =   -1  'True
      Caption         =   "Input 1"
      Height          =   195
      Left            =   240
      TabIndex        =   5
      Top             =   600
      Width           =   495
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub ClearBtn_Click()
    Txtbox1.Text = " "
    Txtbox2.Text = " "
    Txtbox3.Text = "0"
End Sub

Private Sub ExitBtn_Click()
    If MsgBox("Are U Sure?", vbYesNoCancel) = vbYes Then
        Unload Me
    End If
End Sub

Private Sub GoBtn_Click()
    Dim a As Double, b As Double, r As Double
    d1 = Val(Txtbox1.Text)
    d2 = Val(Txtbox2.Text)
    r = d1 + d2
    Txtbox3.Text = Str(r)
End Sub
