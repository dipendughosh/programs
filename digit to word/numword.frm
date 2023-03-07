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
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Function toWords(ByVal VarNum As Variant) As String
Dim intLen As Integer, strX1 As String
Dim strX2 As String, strResult1 As String
Dim intPos As Integer
'round the number to two decimal places
VarNum = Round(VarNum, 2)
'convert integer part of number to string for easy precessing
stX1 = CStr(Int(VarNum))
'find the length of the string
intLen = Len(strX1)
'initialise the variable
strResult1 = ""
'do while length of string is > 0
Do While (intLen > 0)
intLen = Len(strX1)
Select Case intLen
Case 10:
    strX2 = Mid(strX1, 1, 3)
    strResult1 = strResult1 & " " & ThreeDigitToWord(strX2)
    strResult1 = strResult1 & " " & Word(10000000)
    
    
End Function
Private Sub Form_Load()

End Sub
