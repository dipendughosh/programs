VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton okbtn 
      Caption         =   "Ok"
      Height          =   495
      Left            =   240
      TabIndex        =   2
      ToolTipText     =   "ok"
      Top             =   2400
      Width           =   1215
   End
   Begin VB.CommandButton Exitbtn 
      Caption         =   "Exit"
      Height          =   495
      Left            =   1800
      TabIndex        =   1
      ToolTipText     =   "exit"
      Top             =   2400
      Width           =   1215
   End
   Begin VB.CommandButton Cancelbtn 
      Caption         =   "Cancel"
      Height          =   495
      Left            =   3240
      TabIndex        =   0
      ToolTipText     =   "cancel"
      Top             =   2400
      Width           =   1215
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub Cancelbtn_Click()
    Cls
End Sub

Private Sub Exitbtn_Click()
    Unload Me
End Sub

Private Sub okbtn_Click()
    Dim a As Integer, b As Integer, c As Integer
    a = InputBox("Enter a value-")
    b = InputBox("Enter a value-")
    c = a + b
    Print "Sum of " + Str(a) + "+" + Str(b) + " = " + Str(c)
End Sub
