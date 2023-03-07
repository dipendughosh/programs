VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   6240
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   10560
   LinkTopic       =   "Form1"
   PaletteMode     =   1  'UseZOrder
   ScaleHeight     =   6240
   ScaleWidth      =   10560
   StartUpPosition =   3  'Windows Default
   Begin VB.FileListBox File1 
      Height          =   5550
      Left            =   3240
      Pattern         =   "*.jpg;*.bmp"
      TabIndex        =   2
      Top             =   480
      Width           =   2655
   End
   Begin VB.DirListBox Dir1 
      Height          =   4815
      Left            =   120
      TabIndex        =   1
      Top             =   1200
      Width           =   2895
   End
   Begin VB.DriveListBox Drive1 
      Height          =   315
      Left            =   120
      TabIndex        =   0
      Top             =   480
      Width           =   2895
   End
   Begin VB.Image Image1 
      Height          =   5535
      Left            =   6120
      Stretch         =   -1  'True
      Top             =   480
      Width           =   4335
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Dir1_Change()
    File1.Path = Dir1.Path
End Sub

Private Sub Drive1_Change()
    Dir1.Path = Drive1.Drive
End Sub

Private Sub File1_Click()
    Image1.Picture = LoadPicture(File1.Path + "\" + File1.FileName)
End Sub
