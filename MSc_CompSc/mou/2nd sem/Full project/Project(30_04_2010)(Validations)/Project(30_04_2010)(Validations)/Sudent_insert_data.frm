VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Insert information into student database"
   ClientHeight    =   9030
   ClientLeft      =   165
   ClientTop       =   555
   ClientWidth     =   8340
   LinkTopic       =   "Form1"
   Picture         =   "Sudent_insert_data.frx":0000
   ScaleHeight     =   9030
   ScaleWidth      =   8340
   StartUpPosition =   3  'Windows Default
   WindowState     =   2  'Maximized
   Begin VB.ComboBox Combo7 
      Height          =   315
      Left            =   1920
      Sorted          =   -1  'True
      TabIndex        =   32
      Text            =   "<--------------CITY-------------->"
      Top             =   3000
      Width           =   2175
   End
   Begin VB.ComboBox Combo6 
      Height          =   315
      Left            =   1920
      Sorted          =   -1  'True
      TabIndex        =   31
      Text            =   "<------------STATE------------>"
      Top             =   3720
      Width           =   2175
   End
   Begin VB.TextBox Text10 
      Height          =   315
      Left            =   6000
      TabIndex        =   30
      Top             =   3720
      Width           =   1935
   End
   Begin VB.TextBox Text8 
      Height          =   315
      Left            =   1920
      TabIndex        =   26
      Top             =   840
      Width           =   1575
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Reset"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   400
      Left            =   3840
      TabIndex        =   25
      Top             =   8160
      Width           =   1000
   End
   Begin VB.ComboBox Combo4 
      Height          =   315
      Left            =   6000
      TabIndex        =   23
      Top             =   4440
      Width           =   855
   End
   Begin VB.CommandButton Command1 
      BackColor       =   &H80000009&
      Caption         =   "Home"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   400
      Left            =   2160
      TabIndex        =   22
      Top             =   8160
      Width           =   1000
   End
   Begin VB.ComboBox Combo5 
      Height          =   315
      Left            =   1920
      TabIndex        =   21
      Top             =   5880
      Width           =   1815
   End
   Begin VB.ComboBox Combo3 
      Height          =   315
      Left            =   3360
      TabIndex        =   20
      Text            =   "YYYY"
      Top             =   4440
      Width           =   855
   End
   Begin VB.ComboBox Combo2 
      Height          =   315
      Left            =   1920
      TabIndex        =   19
      Text            =   "MM"
      Top             =   4440
      Width           =   615
   End
   Begin VB.ComboBox Combo1 
      BeginProperty DataFormat 
         Type            =   0
         Format          =   "0"
         HaveTrueFalseNull=   0
         FirstDayOfWeek  =   0
         FirstWeekOfYear =   0
         LCID            =   1033
         SubFormatType   =   0
      EndProperty
      Height          =   315
      Left            =   2640
      TabIndex        =   18
      Text            =   "DD"
      Top             =   4440
      Width           =   615
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Insert"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   400
      Left            =   5520
      TabIndex        =   17
      Top             =   8160
      Width           =   1000
   End
   Begin VB.TextBox Text7 
      Height          =   315
      Left            =   1920
      TabIndex        =   16
      Top             =   7320
      Width           =   1600
   End
   Begin VB.TextBox Text6 
      Height          =   315
      Left            =   1920
      TabIndex        =   15
      Top             =   6600
      Width           =   6000
   End
   Begin VB.TextBox Text5 
      BeginProperty DataFormat 
         Type            =   0
         Format          =   "0"
         HaveTrueFalseNull=   0
         FirstDayOfWeek  =   0
         FirstWeekOfYear =   0
         LCID            =   1033
         SubFormatType   =   0
      EndProperty
      Height          =   315
      Left            =   1920
      TabIndex        =   14
      Top             =   5160
      Width           =   2475
   End
   Begin VB.TextBox Text4 
      BeginProperty DataFormat 
         Type            =   0
         Format          =   "0"
         HaveTrueFalseNull=   0
         FirstDayOfWeek  =   0
         FirstWeekOfYear =   0
         LCID            =   1033
         SubFormatType   =   0
      EndProperty
      Height          =   315
      Left            =   6000
      TabIndex        =   13
      Top             =   3000
      Width           =   1875
   End
   Begin VB.TextBox Text1 
      Height          =   315
      Left            =   1920
      TabIndex        =   12
      Top             =   1560
      Width           =   6000
   End
   Begin VB.TextBox Text2 
      Height          =   315
      Left            =   1920
      TabIndex        =   11
      Top             =   2280
      Width           =   6000
   End
   Begin VB.Label Label13 
      BackColor       =   &H80000014&
      Caption         =   "Police Station:-"
      Height          =   405
      Left            =   4440
      TabIndex        =   29
      Top             =   3720
      Width           =   1395
   End
   Begin VB.Label Label12 
      BackColor       =   &H80000014&
      Caption         =   "State:-"
      Height          =   405
      Left            =   240
      TabIndex        =   28
      Top             =   3720
      Width           =   1395
   End
   Begin VB.Label Label11 
      Height          =   135
      Left            =   8160
      TabIndex        =   27
      Top             =   8880
      Width           =   255
   End
   Begin VB.Label Label10 
      BackColor       =   &H80000014&
      Caption         =   "Student ID:-"
      Height          =   405
      Left            =   240
      TabIndex        =   24
      Top             =   840
      Width           =   1395
   End
   Begin VB.Label Label9 
      BackColor       =   &H80000014&
      Caption         =   "Course ID:-"
      Height          =   405
      Left            =   240
      TabIndex        =   10
      Top             =   7320
      Width           =   1395
   End
   Begin VB.Label Label8 
      BackColor       =   &H80000014&
      Caption         =   "Father's Name:-"
      Height          =   405
      Left            =   240
      TabIndex        =   9
      Top             =   6600
      Width           =   1395
   End
   Begin VB.Label Label7 
      BackColor       =   &H80000014&
      Caption         =   "Gender:-"
      Height          =   405
      Left            =   240
      TabIndex        =   8
      Top             =   5880
      Width           =   1395
   End
   Begin VB.Label Label6 
      BackColor       =   &H80000014&
      Caption         =   "Age:-"
      Height          =   405
      Left            =   4440
      TabIndex        =   7
      Top             =   4440
      Width           =   1395
   End
   Begin VB.Label Label5 
      BackColor       =   &H80000014&
      Caption         =   "Date of Birth (MM/DD/YYYY):-"
      Height          =   405
      Left            =   240
      TabIndex        =   6
      Top             =   4440
      Width           =   1395
   End
   Begin VB.Label Label4 
      BackColor       =   &H80000014&
      Caption         =   "Mobile No. :-"
      Height          =   405
      Left            =   240
      TabIndex        =   5
      Top             =   5160
      Width           =   1395
   End
   Begin VB.Label Label3 
      BackColor       =   &H80000014&
      Caption         =   "Pin:-"
      Height          =   405
      Index           =   1
      Left            =   4440
      TabIndex        =   4
      Top             =   3000
      Width           =   1395
   End
   Begin VB.Label Label2 
      BackColor       =   &H80000014&
      Caption         =   "City:-"
      Height          =   405
      Index           =   1
      Left            =   240
      TabIndex        =   3
      Top             =   3000
      Width           =   1395
   End
   Begin VB.Label Label3 
      BackColor       =   &H80000014&
      Caption         =   "Address:-"
      Height          =   405
      Index           =   0
      Left            =   240
      TabIndex        =   2
      Top             =   2280
      Width           =   1395
   End
   Begin VB.Label Label2 
      BackColor       =   &H80000014&
      Caption         =   "Name:-"
      Height          =   405
      Index           =   0
      Left            =   240
      TabIndex        =   1
      Top             =   1560
      Width           =   1395
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      BackColor       =   &H80000014&
      Caption         =   "INSERT INFORMATION INTO STUDENT DATABASE"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   855
      Left            =   600
      TabIndex        =   0
      Top             =   0
      Width           =   6975
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection
Dim rs As rdoResultset
Dim rs1 As rdoResultset
Dim rs2 As rdoResultset
Dim rs3 As rdoResultset

Private Sub Command1_Click()
    Form14.Show
    Unload Me
End Sub
Private Sub Command2_Click()
    Text1.Text = ""
    Text2.Text = ""
    Combo7.Text = "<--------------CITY-------------->"
    Text4.Text = ""
    Text5.Text = ""
    Text6.Text = ""
    Text7.Text = ""
    Text8.Text = ""
    Combo6.Text = "<------------STATE------------>"
    Text10.Text = ""
    Combo1.Text = "DD"
    Combo2.Text = "MM"
    Combo3.Text = "YYYY"
    Combo4.Text = ""
    Combo5.Text = ""
    Text8.SetFocus
End Sub

Private Sub Command3_Click()
    Dim q As String
    Dim D1 As String
    Dim N As Integer
    Dim i As Integer
    Dim TEMP As String
    Dim FLAG1 As Integer
    Dim FLAG2 As Integer
    Dim FLAGN As Integer
    Dim FLAGF As Integer
    Dim FLAGP As Integer
    Dim FLAGM As Integer
    Dim X As String
    If Text8.Text = "" Or Text1.Text = "" Or Text2.Text = "" Or Combo7.Text = "<--------------CITY-------------->" Or Text4.Text = "" Or Text5.Text = "" Or Text6.Text = "" Or Text7.Text = "" Or Combo1.Text = "DD" Or Combo2.Text = "MM" Or Combo3.Text = "YYYY" Or Combo4.Text = "" Or Combo5 = "" Or Combo6.Text = "<------------STATE------------>" Or Text10.Text = "" Then
        MsgBox ("Some FIELDS are EMPTY")
    Else
        FLAG1 = 0
        FLAG2 = 0
        FLAGN = 0
        FLAGF = 0
        FLAGP = 0
        FLAGM = 0
        If Len(Text1.Text) > 0 Then
            For i = 1 To Len(Text1.Text)
                X = Mid(Text1.Text, i, 1)
                If Not X Like "[A-Za-z]" Then
                    If Not X Like "[ ]" Then
                        FLAGN = 1
                    End If
                End If
            Next i
            If FLAGN = 1 Then
                MsgBox ("NAME has digits")
            End If
        End If
        If Len(Text4.Text) < 6 Or Len(Text4.Text) > 6 Then
            FLAGP = 1
            MsgBox ("PIN CODE must be 6 digts")
        Else
            If Len(Text4.Text) = 6 Then
                For i = 1 To Len(Text4.Text)
                    X = Mid(Text4.Text, i, 1)
                    If Not X Like "[0-9]" Then
                        FLAGP = 1
                    End If
                Next i
            End If
            If FLAGP = 1 Then
                MsgBox ("PIN CODE has characters")
            End If
        End If
        If Len(Text5.Text) < 10 Or Len(Text5.Text) > 10 Then
            FLAGM = 1
            MsgBox ("MOBILE NO. must be 10 digts")
        Else
            If Len(Text5.Text) = 10 Then
                For i = 1 To Len(Text5.Text)
                    X = Mid(Text5.Text, i, 1)
                    If Not X Like "[0-9]" Then
                        FLAGM = 1
                    End If
                Next i
            End If
            If FLAGM = 1 Then
                MsgBox ("MOBILE NO. has characters")
            End If
        End If
        If Len(Text6.Text) > 0 Then
            For i = 1 To Len(Text6.Text)
                X = Mid(Text6.Text, i, 1)
                If Not X Like "[A-Za-z]" Then
                    If Not X Like "[ ]" Then
                        FLAGF = 1
                    End If
                End If
            Next i
            If FLAGF = 1 Then
                MsgBox ("FATHER'S NAME has digits")
            End If
        End If
        Set rs = con.OpenResultset("SELECT COUNT(*) AS C FROM STUDENT;", rdOpenStatic)
        N = rs.rdoColumns("C")
        rs.Close
        Set rs1 = con.OpenResultset("SELECT S_ID FROM STUDENT;", rdOpenStatic)
        For i = 1 To N
            TEMP = rs1.rdoColumns("S_ID")
            If Text8.Text = TEMP Then
                FLAG1 = 1
            End If
            rs1.MoveNext
        Next i
        rs1.Close
        Set rs2 = con.OpenResultset("SELECT COUNT(*) AS C FROM COURSE;", rdOpenStatic)
        N = rs2.rdoColumns("C")
        rs2.Close
        Set rs3 = con.OpenResultset("SELECT C_ID FROM COURSE;", rdOpenStatic)
        For i = 1 To N
            TEMP = rs3.rdoColumns("C_ID")
            If Text7.Text = TEMP Then
                FLAG2 = 1
            End If
            rs3.MoveNext
        Next i
        rs3.Close
        If FLAG1 = 1 Then
            MsgBox ("StudentID provided EXITS")
        ElseIf FLAG2 = 0 Then
            MsgBox ("CourseID provided is wrong")
        ElseIf FLAGN = 0 And FLAGF = 0 And FLAGP = 0 And FLAGM = 0 Then
            D1 = Combo1.Text + "/" + Combo2.Text + "/" + Combo3.Text
            Set rs = con.OpenResultset("SELECT * FROM COURSE WHERE C_ID = '" + Text7.Text + "';", rdOpenStatic)
            Label11.Caption = rs.rdoColumns("C_FEES")
            rs.Close
            q = "INSERT INTO STUDENT(S_ID,S_NAME,S_ADDRESS,S_CITY,S_PIN,S_DOB,S_AGE,S_MOBILE,S_GENDER,S_FNAME,S_C_ID,S_FEES,S_STATE,S_POLICE) VALUES ('" + Text8.Text + "','" + Text1.Text + "','" + Text2.Text + "','" + Combo7.Text + "'," + Text4.Text + ",TO_DATE('" + D1 + "','DD/MM/YYYY')," + Combo4.Text + "," + Text5.Text + ",'" + Combo5.Text + "','" + Text6.Text + "','" + Text7.Text + "'," + Label11.Caption + ",'" + Combo6.Text + "','" + Text10.Text + "');"
            con.Execute q
            Label11.Caption = ""
            MsgBox ("Successfully Entered into Database")
            Text1.Text = ""
            Text2.Text = ""
            Combo7.Text = "<--------------CITY-------------->"
            Text4.Text = ""
            Text5.Text = ""
            Text6.Text = ""
            Text7.Text = ""
            Text8.Text = ""
            Combo6.Text = "<------------STATE------------>"
            Text10.Text = ""
            Combo1.Text = "DD"
            Combo2.Text = "MM"
            Combo3.Text = "YYYY"
            Combo4.Text = ""
            Combo5.Text = ""
            Text8.SetFocus
        End If
    End If
End Sub

Private Sub Form_Load()
    con.Connect = "uid=scott;pwd=tiger;driver={Oracle in OraHome92}"
    con.EstablishConnection rdDriverNoPrompt
    Dim i As Integer
    i = 0
    Do Until i = 31
        i = i + 1
        Combo1.AddItem i
    Loop
    i = 0
    Do Until i = 12
        i = i + 1
        Combo2.AddItem i
    Loop
    i = 1979
    Do Until i = 2000
        i = i + 1
        Combo3.AddItem i
    Loop
    Combo5.AddItem "Male"
    Combo5.AddItem "Female"
    i = 16
    Do Until i = 30
        i = i + 1
        Combo4.AddItem i
    Loop
    Combo6.AddItem "AndhraPradesh"
    Combo6.AddItem "ArunachalPradesh"
    Combo6.AddItem "Assam"
    Combo6.AddItem "Bihar"
    Combo6.AddItem "Chhatisgarh"
    Combo6.AddItem "Goa"
    Combo6.AddItem "Gujarat"
    Combo6.AddItem "Haryana"
    Combo6.AddItem "HimachalPradesh"
    Combo6.AddItem "Jammu&Kashmir"
    Combo6.AddItem "Jharkhand"
    Combo6.AddItem "Karnataka"
    Combo6.AddItem "Kerala"
    Combo6.AddItem "MadhyaPradesh"
    Combo6.AddItem "Maharashtra"
    Combo6.AddItem "Manipur"
    Combo6.AddItem "Meghalaya"
    Combo6.AddItem "Mizoram"
    Combo6.AddItem "Nagaland"
    Combo6.AddItem "Orissa"
    Combo6.AddItem "Punjab"
    Combo6.AddItem "Rajasthan"
    Combo6.AddItem "Sikkim"
    Combo6.AddItem "TamilNadu"
    Combo6.AddItem "Tripura"
    Combo6.AddItem "UttarPradesh"
    Combo6.AddItem "Uttaranchal"
    Combo6.AddItem "WestBengal"
    '''''''
    Combo7.AddItem "Abohar"
    Combo7.AddItem "Achalpur"
    Combo7.AddItem "Adipur"
    Combo7.AddItem "Agartala"
    Combo7.AddItem "Agra"
    Combo7.AddItem "Ahmedabad"
    Combo7.AddItem "Ahmednagar"
    Combo7.AddItem "Aizawl"
    Combo7.AddItem "Ajmer"
    Combo7.AddItem "Akola"
    Combo7.AddItem "Aligarh"
    Combo7.AddItem "Allahabad"
    Combo7.AddItem "Alwar"
    Combo7.AddItem "Ambala"
    Combo7.AddItem "Amethi"
    Combo7.AddItem "Ammakandakara"
    Combo7.AddItem "Amravati"
    Combo7.AddItem "Amreli"
    Combo7.AddItem "Amritsar"
    Combo7.AddItem "Anand"
    Combo7.AddItem "Anantapur"
    Combo7.AddItem "Angul"
    Combo7.AddItem "Anklesvar"
    Combo7.AddItem "Anuppur"
    Combo7.AddItem "Arakkonam"
    Combo7.AddItem "Araria"
    Combo7.AddItem "Arcot"
    Combo7.AddItem "Arrah"
    Combo7.AddItem "Aruppukkottai"
    Combo7.AddItem "Asansol"
    Combo7.AddItem "AshokNagar"
    Combo7.AddItem "Ashtamichira"
    Combo7.AddItem "Aurangabad"
    Combo7.AddItem "Bihar"
    Combo7.AddItem "Asurbandh"
    Combo7.AddItem "Azamgarh"
    Combo7.AddItem "Bahadurgarh"
    Combo7.AddItem "Baharampur"
    Combo7.AddItem "Bahraich"
    Combo7.AddItem "Balaghat"
    Combo7.AddItem "Balasore"
    Combo7.AddItem "Bali"
    Combo7.AddItem "Ballabhgarh"
    Combo7.AddItem "Ballia"
    Combo7.AddItem "Balrampur"
    Combo7.AddItem "Banda"
    Combo7.AddItem "Banganapalle"
    Combo7.AddItem "Banswara"
    Combo7.AddItem "Banur"
    Combo7.AddItem "Bapatla"
    Combo7.AddItem "Baramati"
    Combo7.AddItem "Baran"
    Combo7.AddItem "Bardhaman"
    Combo7.AddItem "Bareilly"
    Combo7.AddItem "Bargarh"
    Combo7.AddItem "Barh"
    Combo7.AddItem "Baripada"
    Combo7.AddItem "Barmer"
    Combo7.AddItem "Barnala"
    Combo7.AddItem "Barrackpur"
    Combo7.AddItem "Barwani"
    Combo7.AddItem "Bawal"
    Combo7.AddItem "Beawar"
    Combo7.AddItem "Belgaum"
    Combo7.AddItem "Bellary"
    Combo7.AddItem "Bengaluru"
    Combo7.AddItem "Berhampur"
    Combo7.AddItem "Betul"
    Combo7.AddItem "Betul"
    Combo7.AddItem "Bhagalpur"
    Combo7.AddItem "Bhavani"
    Combo7.AddItem "Bhandara"
    Combo7.AddItem "Bhajanpura"
    Combo7.AddItem "Bharatpur"
    Combo7.AddItem "Bharuch"
    Combo7.AddItem "Bhavnagar"
    Combo7.AddItem "Bhilai"
    Combo7.AddItem "Bhilwara"
    Combo7.AddItem "Bhimavaram"
    Combo7.AddItem "Bhinmal"
    Combo7.AddItem "Bhiwandi"
    Combo7.AddItem "Bhiwani"
    Combo7.AddItem "Bhopal"
    Combo7.AddItem "Bhubaneswar"
    Combo7.AddItem "Bhuj"
    Combo7.AddItem "Bhusawal"
    Combo7.AddItem "Bidar"
    Combo7.AddItem "BiharSharif"
    Combo7.AddItem "Bijnaur"
    Combo7.AddItem "Bikaner"
    Combo7.AddItem "Bilara"
    Combo7.AddItem "Bilaspur"
    Combo7.AddItem "Bilaspur"
    Combo7.AddItem "BodhGaya"
    Combo7.AddItem "BokaroSteelCity"
    Combo7.AddItem "Balangir"
    Combo7.AddItem "Bongaigaon"
    Combo7.AddItem "Buxar"
    Combo7.AddItem "Calicut"
    Combo7.AddItem "Cambay"
    Combo7.AddItem "Champawat"
    Combo7.AddItem "Chamrajnagar"
    Combo7.AddItem "Chandannagar"
    Combo7.AddItem "Chandigarh"
    Combo7.AddItem "Chapirevula"
    Combo7.AddItem "Chapra"
    Combo7.AddItem "Charkhari"
    Combo7.AddItem "CharkhiDadri"
    Combo7.AddItem "Chandrapur"
    Combo7.AddItem "Chengalpattu"
    Combo7.AddItem "Chennai"
    Combo7.AddItem "Chhatarpur"
    Combo7.AddItem "Chhindwara"
    Combo7.AddItem "Chikmagalur"
    Combo7.AddItem "Chiplun"
    Combo7.AddItem "Chirala"
    Combo7.AddItem "Chitradurga"
    Combo7.AddItem "Chitrakoot"
    Combo7.AddItem "Chittoor"
    Combo7.AddItem "Cochin"
    Combo7.AddItem "Coimbatore"
    Combo7.AddItem "Contai"
    Combo7.AddItem "CoochBehar"
    Combo7.AddItem "Coonoor"
    Combo7.AddItem "Cuddalore"
    Combo7.AddItem "Cuddapah"
    Combo7.AddItem "Cuttack"
    Combo7.AddItem "Dabra"
    Combo7.AddItem "Dahod"
    Combo7.AddItem "Daltonganj"
    Combo7.AddItem "Daman"
    Combo7.AddItem "Damoh"
    Combo7.AddItem "Darbhanga"
    Combo7.AddItem "Darjeeling"
    Combo7.AddItem "Datia"
    Combo7.AddItem "Davanagere"
    Combo7.AddItem "Dehgam"
    Combo7.AddItem "Dehradun"
    Combo7.AddItem "Deoghar"
    Combo7.AddItem "Deoria"
    Combo7.AddItem "Dewas"
    Combo7.AddItem "Delhi"
    Combo7.AddItem "Dhamtari"
    Combo7.AddItem "Dhanbad"
    Combo7.AddItem "Dhar"
    Combo7.AddItem "Dharampur"
    Combo7.AddItem "Dharamsala"
    Combo7.AddItem "Dharwad"
    Combo7.AddItem "Dhenkanal"
    Combo7.AddItem "Dholka"
    Combo7.AddItem "Dhule"
    Combo7.AddItem "Dhulian"
    Combo7.AddItem "Dhuri"
    Combo7.AddItem "Dibrugarh"
    Combo7.AddItem "Dispur"
    Combo7.AddItem "Dindigul"
    Combo7.AddItem "Diu"
    Combo7.AddItem "Dombivli"
    Combo7.AddItem "Dumdum"
    Combo7.AddItem "Durg"
    Combo7.AddItem "Durgapur"
    Combo7.AddItem "Durgapur"
    Combo7.AddItem "Dwarka"
    Combo7.AddItem "Dadri"
    Combo7.AddItem "Ernakulam"
    Combo7.AddItem "Erode"
    Combo7.AddItem "Etah"
    Combo7.AddItem "Etawah"
    Combo7.AddItem "Eluru"
    Combo7.AddItem "Faizabad"
    Combo7.AddItem "Falna"
    Combo7.AddItem "Faridabad"
    Combo7.AddItem "Faridkot"
    Combo7.AddItem "Farrukhabad"
    Combo7.AddItem "Fatehabad"
    Combo7.AddItem "Fatehgarh"
    Combo7.AddItem "FatehpurSikri"
    Combo7.AddItem "Fatehpur"
    Combo7.AddItem "Fazilka"
    Combo7.AddItem "Firozabad"
    Combo7.AddItem "Gadag"
    Combo7.AddItem "Gadchiroli"
    Combo7.AddItem "Gandhidham"
    Combo7.AddItem "Gandhinagar"
    Combo7.AddItem "Gangtok"
    Combo7.AddItem "Ganjam"
    Combo7.AddItem "Gaya"
    Combo7.AddItem "Ghatampur"
    Combo7.AddItem "Ghaziabad"
    Combo7.AddItem "Ghazipur"
    Combo7.AddItem "GoaVelha"
    Combo7.AddItem "Godhra"
    Combo7.AddItem "Gondiya"
    Combo7.AddItem "Gorakhpur"
    Combo7.AddItem "GreaterNoida"
    Combo7.AddItem "Gudalur"
    Combo7.AddItem "Gudalur"
    Combo7.AddItem "Gudalur"
    Combo7.AddItem "Gudivada"
    Combo7.AddItem "Gulbarga"
    Combo7.AddItem "Gumla"
    Combo7.AddItem "Guna"
    Combo7.AddItem "Gundlupet"
    Combo7.AddItem "Guntur"
    Combo7.AddItem "Gurgaon"
    Combo7.AddItem "Guwahati"
    Combo7.AddItem "Gwalior"
    Combo7.AddItem "Godda"
    Combo7.AddItem "Hoshiarpur"
    Combo7.AddItem "Haldia"
    Combo7.AddItem "Haldwani"
    Combo7.AddItem "Hamirpur"
    Combo7.AddItem "Hanumangarh"
    Combo7.AddItem "Howrah"
    Combo7.AddItem "Hodal"
    Combo7.AddItem "Harda"
    Combo7.AddItem "Hardoi"
    Combo7.AddItem "Harsawa"
    Combo7.AddItem "Haridwar"
    Combo7.AddItem "Hubli"
    Combo7.AddItem "Hassan"
    Combo7.AddItem "Hastinapur"
    Combo7.AddItem "Hathras"
    Combo7.AddItem "Himatnagar"
    Combo7.AddItem "Hisar"
    Combo7.AddItem "Hansi"
    Combo7.AddItem "Hyderabad"
    Combo7.AddItem "Halisahar"
    Combo7.AddItem "Indore"
    Combo7.AddItem "Imphal"
    Combo7.AddItem "Itanagar"
    Combo7.AddItem "Idar"
    Combo7.AddItem "Jabalpur"
    Combo7.AddItem "Jalandhar"
    Combo7.AddItem "Jagdalpur"
    Combo7.AddItem "Jaipur"
    Combo7.AddItem "Jais"
    Combo7.AddItem "Jaisalmer"
    Combo7.AddItem "Jaitaran"
    Combo7.AddItem "Jalalabad"
    Combo7.AddItem "Jalgaon"
    Combo7.AddItem "Jagadhri"
    Combo7.AddItem "Jagraon"
    Combo7.AddItem "Jagtial"
    Combo7.AddItem "Jalore"
    Combo7.AddItem "Jamakhandi"
    Combo7.AddItem "Jammu"
    Combo7.AddItem "Jamnagar"
    Combo7.AddItem "Jamshedpur"
    Combo7.AddItem "Jaunpur"
    Combo7.AddItem "Jhabua"
    Combo7.AddItem "Jhajjar"
    Combo7.AddItem "Jhalawar"
    Combo7.AddItem "Jhansi"
    Combo7.AddItem "Jhunjhunu"
    Combo7.AddItem "Jodhpur"
    Combo7.AddItem "Jorhat"
    Combo7.AddItem "Junagadh"
    Combo7.AddItem "Kadapa"
    Combo7.AddItem "Kailaras"
    Combo7.AddItem "Kakinada"
    Combo7.AddItem "Kalburgi"
    Combo7.AddItem "Kalyan"
    Combo7.AddItem "Kamthi"
    Combo7.AddItem "Kanchipuram"
    Combo7.AddItem "Kanker"
    Combo7.AddItem "Kannur"
    Combo7.AddItem "Kanpur"
    Combo7.AddItem "Kapurthala"
    Combo7.AddItem "Karad"
    Combo7.AddItem "Karimganj"
    Combo7.AddItem "Karimnagar"
    Combo7.AddItem "Karur"
    Combo7.AddItem "Karwar"
    Combo7.AddItem "Katihar"
    Combo7.AddItem "Katni"
    Combo7.AddItem "Khagaria"
    Combo7.AddItem "Kharagpur"
    Combo7.AddItem "Kochi"
    Combo7.AddItem "Kolar"
    Combo7.AddItem "Kolhapur"
    Combo7.AddItem "Kolkata"
    Combo7.AddItem "Kondagaon"
    Combo7.AddItem "Konnagar"
    Combo7.AddItem "Kota"
    Combo7.AddItem "Kotdwara"
    Combo7.AddItem "Kotma"
    Combo7.AddItem "Kottayam"
    Combo7.AddItem "Krishnanaga"
    Combo7.AddItem "Kurnool"
    Combo7.AddItem "Ladwa"
    Combo7.AddItem "Lakhisarai"
    Combo7.AddItem "Lalitpur"
    Combo7.AddItem "Lamka"
    Combo7.AddItem "Latur"
    Combo7.AddItem "Leh"
    Combo7.AddItem "Lonavla"
    Combo7.AddItem "Lucknow"
    Combo7.AddItem "Ludhiana"
    Combo7.AddItem "Modasa"
    Combo7.AddItem "Mithapur"
    Combo7.AddItem "Madanapalle"
    Combo7.AddItem "Madgaon"
    Combo7.AddItem "Madikeri"
    Combo7.AddItem "Madurai"
    Combo7.AddItem "Mahabaleswar"
    Combo7.AddItem "Mahabubnagar"
    Combo7.AddItem "Mahe"
    Combo7.AddItem "Mahoba"
    Combo7.AddItem "Mahwa"
    Combo7.AddItem "Mahuva"
    Combo7.AddItem "Malout"
    Combo7.AddItem "Malegaon"
    Combo7.AddItem "Mancherial"
    Combo7.AddItem "Mandla"
    Combo7.AddItem "Mandsaur"
    Combo7.AddItem "Mandya"
    Combo7.AddItem "Manesar"
    Combo7.AddItem "Mangalagiri"
    Combo7.AddItem "Mangalore"
    Combo7.AddItem "Mapusa"
    Combo7.AddItem "Marmagao"
    Combo7.AddItem "Mathura"
    Combo7.AddItem "Machilipatnam"
    Combo7.AddItem "Mahad"
    Combo7.AddItem "Meerut"
    Combo7.AddItem "Mehsana"
    Combo7.AddItem "Mira-Bhayandar"
    Combo7.AddItem "Miraj"
    Combo7.AddItem "Mirzapur"
    Combo7.AddItem "Moga"
    Combo7.AddItem "Mohali"
    Combo7.AddItem "Mohania"
    Combo7.AddItem "Mokama"
    Combo7.AddItem "Moradabad"
    Combo7.AddItem "Morshi"
    Combo7.AddItem "Motihari"
    Combo7.AddItem "MountAbu"
    Combo7.AddItem "Mukatsar"
    Combo7.AddItem "Mullanpur"
    Combo7.AddItem "Mumbai"
    Combo7.AddItem "Mussoorie"
    Combo7.AddItem "Murwara"
    Combo7.AddItem "Murshidabad"
    Combo7.AddItem "Muzaffarnagar"
    Combo7.AddItem "Muzaffarpur"
    Combo7.AddItem "Mysore"
    Combo7.AddItem "Manavadar"
    Combo7.AddItem "Nadiad"
    Combo7.AddItem "Nagapattinam"
    Combo7.AddItem "Nagarkurnool"
    Combo7.AddItem "Nagaur"
    Combo7.AddItem "Nagercoil"
    Combo7.AddItem "Nagpur"
    Combo7.AddItem "Nainital"
    Combo7.AddItem "Nalagarh"
    Combo7.AddItem "Nalgonda"
    Combo7.AddItem "Namakkal"
    Combo7.AddItem "Nanded"
    Combo7.AddItem "Nandyal"
    Combo7.AddItem "Nandurbar"
    Combo7.AddItem "Nangal"
    Combo7.AddItem "Narasaraopet"
    Combo7.AddItem "Narnaul"
    Combo7.AddItem "Narsimhapur"
    Combo7.AddItem "Narsinghgarh"
    Combo7.AddItem "Narsingarh"
    Combo7.AddItem "Nashik"
    Combo7.AddItem "NaviMumbai"
    Combo7.AddItem "Navsari"
    Combo7.AddItem "Nawalgarh"
    Combo7.AddItem "Neemuch"
    Combo7.AddItem "Nellore"
    Combo7.AddItem "NewDelhi"
    Combo7.AddItem "NewGuntur"
    Combo7.AddItem "NOIDA"
    Combo7.AddItem "Nizamabad"
    Combo7.AddItem "Ongole"
    Combo7.AddItem "Ootacamund"
    Combo7.AddItem "Orai"
    Combo7.AddItem "Palai"
    Combo7.AddItem "Palakkad"
    Combo7.AddItem "Palanpur"
    Combo7.AddItem "Pali"
    Combo7.AddItem "Palwal"
    Combo7.AddItem "Panaji"
    Combo7.AddItem "Panchkula"
    Combo7.AddItem "Pandharpur"
    Combo7.AddItem "Panipat"
    Combo7.AddItem "Panna"
    Combo7.AddItem "Panvel"
    Combo7.AddItem "Paratwada"
    Combo7.AddItem "Patan"
    Combo7.AddItem "Pathankot"
    Combo7.AddItem "Patiala"
    Combo7.AddItem "Patna"
    Combo7.AddItem "Patratu"
    Combo7.AddItem "Piduguralla"
    Combo7.AddItem "Pithoragarh"
    Combo7.AddItem "PimpriChinchwad"
    Combo7.AddItem "Ponda"
    Combo7.AddItem "Pollachi"
    Combo7.AddItem "Pokaran"
    Combo7.AddItem "Puducherry"
    Combo7.AddItem "Porbandar"
    Combo7.AddItem "PortBlair"
    Combo7.AddItem "Pratapgarh"
    Combo7.AddItem "Pratapgarh"
    Combo7.AddItem "Pratapgarh"
    Combo7.AddItem "Pune"
    Combo7.AddItem "Puri"
    Combo7.AddItem "Purnia"
    Combo7.AddItem "Pushkar"
    Combo7.AddItem "Punalur"
    Combo7.AddItem "Quilon"
    Combo7.AddItem "Raichur"
    Combo7.AddItem "Raigarh"
    Combo7.AddItem "Raipur"
    Combo7.AddItem "Rairangpur"
    Combo7.AddItem "Raisen"
    Combo7.AddItem "Rajahmundry"
    Combo7.AddItem "Rajampet"
    Combo7.AddItem "Rajgarh"
    Combo7.AddItem "Rajgir"
    Combo7.AddItem "Rajkot"
    Combo7.AddItem "Rajnandgaon"
    Combo7.AddItem "Ramanathapuram"
    Combo7.AddItem "Rameshwaram"
    Combo7.AddItem "RamGarh"
    Combo7.AddItem "Rampur"
    Combo7.AddItem "Ramnagar"
    Combo7.AddItem "Ramanagara"
    Combo7.AddItem "Ranaghat"
    Combo7.AddItem "Rani"
    Combo7.AddItem "Ranchi"
    Combo7.AddItem "Ranikhet"
    Combo7.AddItem "Raniwara"
    Combo7.AddItem "Rasheed"
    Combo7.AddItem "Ratangarh"
    Combo7.AddItem "Ratangarh"
    Combo7.AddItem "Ratlam"
    Combo7.AddItem "Ratnagiri"
    Combo7.AddItem "RaeBareli"
    Combo7.AddItem "Ravulapalem"
    Combo7.AddItem "Renukoot"
    Combo7.AddItem "Rishra"
    Combo7.AddItem "Rishikesh"
    Combo7.AddItem "Roorkee"
    Combo7.AddItem "Rewari"
    Combo7.AddItem "Rourkela"
    Combo7.AddItem "Sadri"
    Combo7.AddItem "Sagar"
    Combo7.AddItem "Saharanpur"
    Combo7.AddItem "Salem"
    Combo7.AddItem "Samastipur"
    Combo7.AddItem "Sambalpur"
    Combo7.AddItem "Sanawad"
    Combo7.AddItem "Sanchore"
    Combo7.AddItem "Sangli"
    Combo7.AddItem "Sangamner"
    Combo7.AddItem "Sangrur"
    Combo7.AddItem "Sardarshahar"
    Combo7.AddItem "Sathyamangalam"
    Combo7.AddItem "Satara"
    Combo7.AddItem "Satna"
    Combo7.AddItem "Sehore"
    Combo7.AddItem "Seoni"
    Combo7.AddItem "Shahada"
    Combo7.AddItem "Shajapur"
    Combo7.AddItem "Shegaon"
    Combo7.AddItem "Sheopur"
    Combo7.AddItem "Shevgaon"
    Combo7.AddItem "Shillong"
    Combo7.AddItem "Shimla"
    Combo7.AddItem "Shimoga"
    Combo7.AddItem "Shirala"
    Combo7.AddItem "Shivani"
    Combo7.AddItem "Sholapur"
    Combo7.AddItem "Shrigonda"
    Combo7.AddItem "Shrirampur"
    Combo7.AddItem "Shrivardhan"
    Combo7.AddItem "Siddipet"
    Combo7.AddItem "Sihor"
    Combo7.AddItem "Sikar'"
    Combo7.AddItem "Silchar"
    Combo7.AddItem "Siliguri"
    Combo7.AddItem "Silvassa"
    Combo7.AddItem "Sindhanur"
    Combo7.AddItem "Sinnar"
    Combo7.AddItem "Sitapur"
    Combo7.AddItem "Singrauli"
    Combo7.AddItem "Sirohi"
    Combo7.AddItem "Sironj"
    Combo7.AddItem "Sirsa"
    Combo7.AddItem "Sirsa"
    Combo7.AddItem "Sitamarhi"
    Combo7.AddItem "Sivakasi"
    Combo7.AddItem "Siwan"
    Combo7.AddItem "Sojat"
    Combo7.AddItem "Sonipat"
    Combo7.AddItem "Sriganganagar"
    Combo7.AddItem "Srikakulam"
    Combo7.AddItem "Srikalahasti"
    Combo7.AddItem "Srinagar"
    Combo7.AddItem "Surat"
    Combo7.AddItem "Sumerpur"
    Combo7.AddItem "Suratgarh"
    Combo7.AddItem "Surendranagar"
    Combo7.AddItem "Suri"
    Combo7.AddItem "Suryapet"
    Combo7.AddItem "Secundrabad"
    Combo7.AddItem "Takhatgarh"
    Combo7.AddItem "Tanuku"
    Combo7.AddItem "Talwara"
    Combo7.AddItem "Tamluk"
    Combo7.AddItem "Tandur"
    Combo7.AddItem "Tellicherry"
    Combo7.AddItem "Tezpur"
    Combo7.AddItem "Tenali"
    Combo7.AddItem "Thane"
    Combo7.AddItem "Thanjavur"
    Combo7.AddItem "Thathawata"
    Combo7.AddItem "Thiruvallur"
    Combo7.AddItem "Thrikkannamangal"
    Combo7.AddItem "Thrissur"
    Combo7.AddItem "Thodupuzha"
    Combo7.AddItem "Thoothukudi"
    Combo7.AddItem "Tindivanam"
    Combo7.AddItem "Tinsukia"
    Combo7.AddItem "Tirupattur"
    Combo7.AddItem "Tiruchengode"
    Combo7.AddItem "Tiruchirappalli"
    Combo7.AddItem "Tirunelveli"
    Combo7.AddItem "Tirupati"
    Combo7.AddItem "Tirupur"
    Combo7.AddItem "Tiruvannamalai"
    Combo7.AddItem "Tiruvarur"
    Combo7.AddItem "Tikamgarh"
    Combo7.AddItem "Thirthahalli"
    Combo7.AddItem "Thiruvananthapuram"
    Combo7.AddItem "Tumkur"
    Combo7.AddItem "Udaipur"
    Combo7.AddItem "Udhampur"
    Combo7.AddItem "Udupi"
    Combo7.AddItem "Udhagamandalam"
    Combo7.AddItem "Ujjain"
    Combo7.AddItem "Ulhasnagar"
    Combo7.AddItem "Umred"
    Combo7.AddItem "Unnao"
    Combo7.AddItem "Uttarpara"
    Combo7.AddItem "Vadodara"
    Combo7.AddItem "Vatakara"
    Combo7.AddItem "VallabhVidhyanagar"
    Combo7.AddItem "Valsad"
    Combo7.AddItem "Vandavasi"
    Combo7.AddItem "Vapi"
    Combo7.AddItem "Varanasi"
    Combo7.AddItem "Vasai"
    Combo7.AddItem "VascodaGama"
    Combo7.AddItem "Vellore"
    Combo7.AddItem "Vidisha"
    Combo7.AddItem "Vijayawada"
    Combo7.AddItem "Viluppuram"
    Combo7.AddItem "Virar"
    Combo7.AddItem "Visakhapatnam"
    Combo7.AddItem "Vizianagaram"
    Combo7.AddItem "Virudhachalam"
    Combo7.AddItem "Vyara"
    Combo7.AddItem "Wadi"
    Combo7.AddItem "Warangal"
    Combo7.AddItem "Wardha"
    Combo7.AddItem "Yamunanagar"
    Combo7.AddItem "Yavatmal"
    Combo7.AddItem "Zira"
    Combo7.AddItem "Ziro"


End Sub
Private Sub Form_Unload(Cancel As Integer)
    con.Close
End Sub
