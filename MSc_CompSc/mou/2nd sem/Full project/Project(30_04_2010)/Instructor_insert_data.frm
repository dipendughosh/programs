VERSION 5.00
Begin VB.Form Form4 
   Caption         =   "Insert information into instructor database"
   ClientHeight    =   8610
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8100
   LinkTopic       =   "Form4"
   ScaleHeight     =   8610
   ScaleWidth      =   8100
   StartUpPosition =   3  'Windows Default
   Begin VB.ComboBox Combo10 
      Height          =   315
      Left            =   1920
      Sorted          =   -1  'True
      TabIndex        =   35
      Text            =   "<------------STATE------------>"
      Top             =   3720
      Width           =   2175
   End
   Begin VB.ComboBox Combo9 
      Height          =   315
      Left            =   1920
      Sorted          =   -1  'True
      TabIndex        =   34
      Text            =   "<--------------CITY-------------->"
      Top             =   3000
      Width           =   2175
   End
   Begin VB.TextBox Text10 
      Height          =   315
      Left            =   6000
      TabIndex        =   31
      Top             =   3720
      Width           =   1935
   End
   Begin VB.TextBox Text8 
      Height          =   315
      Left            =   1920
      TabIndex        =   30
      Top             =   840
      Width           =   1575
   End
   Begin VB.ComboBox Combo8 
      Height          =   315
      Left            =   7200
      TabIndex        =   29
      Text            =   "YYYY"
      Top             =   7320
      Width           =   855
   End
   Begin VB.ComboBox Combo7 
      Height          =   315
      Left            =   6480
      TabIndex        =   28
      Text            =   "MM"
      Top             =   7320
      Width           =   615
   End
   Begin VB.ComboBox Combo6 
      Height          =   315
      Left            =   5760
      TabIndex        =   27
      Text            =   "DD"
      Top             =   7320
      Width           =   615
   End
   Begin VB.TextBox Text2 
      Height          =   315
      Left            =   1920
      TabIndex        =   13
      Top             =   2280
      Width           =   6000
   End
   Begin VB.TextBox Text1 
      Height          =   315
      Left            =   1920
      TabIndex        =   12
      Top             =   1560
      Width           =   6000
   End
   Begin VB.TextBox Text4 
      BeginProperty DataFormat 
         Type            =   1
         Format          =   "0"
         HaveTrueFalseNull=   0
         FirstDayOfWeek  =   0
         FirstWeekOfYear =   0
         LCID            =   1033
         SubFormatType   =   1
      EndProperty
      Height          =   315
      Left            =   6000
      TabIndex        =   11
      Top             =   3000
      Width           =   1875
   End
   Begin VB.TextBox Text5 
      BeginProperty DataFormat 
         Type            =   1
         Format          =   "0"
         HaveTrueFalseNull=   0
         FirstDayOfWeek  =   0
         FirstWeekOfYear =   0
         LCID            =   1033
         SubFormatType   =   1
      EndProperty
      Height          =   315
      Left            =   1920
      TabIndex        =   10
      Top             =   5160
      Width           =   2475
   End
   Begin VB.TextBox Text6 
      BeginProperty DataFormat 
         Type            =   1
         Format          =   "0"
         HaveTrueFalseNull=   0
         FirstDayOfWeek  =   0
         FirstWeekOfYear =   0
         LCID            =   1033
         SubFormatType   =   1
      EndProperty
      Height          =   315
      Left            =   1920
      TabIndex        =   9
      Top             =   6600
      Width           =   1800
   End
   Begin VB.TextBox Text7 
      Height          =   315
      Left            =   1920
      TabIndex        =   8
      Top             =   7320
      Width           =   1965
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Reset"
      Height          =   400
      Left            =   3600
      TabIndex        =   7
      Top             =   8160
      Width           =   1000
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Insert"
      Height          =   400
      Left            =   5280
      TabIndex        =   6
      Top             =   8160
      Width           =   1000
   End
   Begin VB.ComboBox Combo1 
      BeginProperty DataFormat 
         Type            =   1
         Format          =   "0"
         HaveTrueFalseNull=   0
         FirstDayOfWeek  =   0
         FirstWeekOfYear =   0
         LCID            =   1033
         SubFormatType   =   1
      EndProperty
      Height          =   315
      Left            =   1920
      TabIndex        =   5
      Text            =   "DD"
      Top             =   4440
      Width           =   615
   End
   Begin VB.ComboBox Combo2 
      BeginProperty DataFormat 
         Type            =   1
         Format          =   "0"
         HaveTrueFalseNull=   0
         FirstDayOfWeek  =   0
         FirstWeekOfYear =   0
         LCID            =   1033
         SubFormatType   =   1
      EndProperty
      Height          =   315
      Left            =   2640
      TabIndex        =   4
      Text            =   "MM"
      Top             =   4440
      Width           =   615
   End
   Begin VB.ComboBox Combo3 
      BeginProperty DataFormat 
         Type            =   1
         Format          =   "0"
         HaveTrueFalseNull=   0
         FirstDayOfWeek  =   0
         FirstWeekOfYear =   0
         LCID            =   1033
         SubFormatType   =   1
      EndProperty
      Height          =   315
      Left            =   3360
      TabIndex        =   3
      Text            =   "YYYY"
      Top             =   4440
      Width           =   855
   End
   Begin VB.ComboBox Combo5 
      Height          =   315
      Left            =   1920
      TabIndex        =   2
      Top             =   5880
      Width           =   1815
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Home"
      Height          =   400
      Left            =   1920
      TabIndex        =   1
      Top             =   8160
      Width           =   1000
   End
   Begin VB.ComboBox Combo4 
      BeginProperty DataFormat 
         Type            =   1
         Format          =   "0"
         HaveTrueFalseNull=   0
         FirstDayOfWeek  =   0
         FirstWeekOfYear =   0
         LCID            =   1033
         SubFormatType   =   1
      EndProperty
      Height          =   315
      Left            =   6000
      TabIndex        =   0
      Top             =   4440
      Width           =   855
   End
   Begin VB.Label Label11 
      Caption         =   "State:-"
      Height          =   405
      Left            =   240
      TabIndex        =   33
      Top             =   3720
      Width           =   1395
   End
   Begin VB.Label Label13 
      Caption         =   "Police Station:-"
      Height          =   405
      Left            =   4440
      TabIndex        =   32
      Top             =   3720
      Width           =   1395
   End
   Begin VB.Label Label12 
      Caption         =   "Date of Joining (DD/MM/YYYY):-"
      Height          =   405
      Left            =   4080
      TabIndex        =   26
      Top             =   7320
      Width           =   1395
   End
   Begin VB.Label Label10 
      Caption         =   "Instructor ID:-"
      Height          =   405
      Left            =   240
      TabIndex        =   25
      Top             =   840
      Width           =   1395
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Insert information into instructor database"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   600
      TabIndex        =   24
      Top             =   120
      Width           =   6975
   End
   Begin VB.Label Label2 
      Caption         =   "Name:-"
      Height          =   405
      Index           =   0
      Left            =   240
      TabIndex        =   23
      Top             =   1560
      Width           =   1395
   End
   Begin VB.Label Label3 
      Caption         =   "Address:-"
      Height          =   405
      Index           =   0
      Left            =   240
      TabIndex        =   22
      Top             =   2280
      Width           =   1395
   End
   Begin VB.Label Label2 
      Caption         =   "City:-"
      Height          =   405
      Index           =   1
      Left            =   240
      TabIndex        =   21
      Top             =   3000
      Width           =   1395
   End
   Begin VB.Label Label3 
      Caption         =   "Pin:-"
      Height          =   405
      Index           =   1
      Left            =   4440
      TabIndex        =   20
      Top             =   3000
      Width           =   1395
   End
   Begin VB.Label Label4 
      Caption         =   "Mobile No. :-"
      Height          =   405
      Left            =   240
      TabIndex        =   19
      Top             =   5160
      Width           =   1395
   End
   Begin VB.Label Label5 
      Caption         =   "Date of Birth (DD/MM/YYYY):-"
      Height          =   405
      Left            =   240
      TabIndex        =   18
      Top             =   4440
      Width           =   1395
   End
   Begin VB.Label Label6 
      Caption         =   "Age:-"
      Height          =   405
      Left            =   4440
      TabIndex        =   17
      Top             =   4440
      Width           =   1395
   End
   Begin VB.Label Label7 
      Caption         =   "Gender:-"
      Height          =   405
      Left            =   240
      TabIndex        =   16
      Top             =   5880
      Width           =   1395
   End
   Begin VB.Label Label8 
      Caption         =   "Salary:-"
      Height          =   405
      Left            =   240
      TabIndex        =   15
      Top             =   6600
      Width           =   1395
   End
   Begin VB.Label Label9 
      Caption         =   "Qualification:-"
      Height          =   405
      Left            =   240
      TabIndex        =   14
      Top             =   7320
      Width           =   1395
   End
End
Attribute VB_Name = "Form4"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim con As New rdoConnection
Dim rs As rdoResultset
Dim rs1 As rdoResultset
Private Sub Command1_Click()
    Form14.Show
    Unload Me
End Sub

Private Sub Command2_Click()
    Text1.Text = ""
    Text2.Text = ""
    Combo9.Text = "<--------------CITY-------------->"
    Text4.Text = ""
    Text5.Text = ""
    Text6.Text = ""
    Text7.Text = ""
    Text8.Text = ""
    Combo10.Text = "<------------STATE------------>"
    Text10.Text = ""
    Combo1.Text = "DD"
    Combo2.Text = "MM"
    Combo3.Text = "YYYY"
    Combo4.Text = ""
    Combo5.Text = ""
    Combo6.Text = "DD"
    Combo7.Text = "MM"
    Combo8.Text = "YYYY"
    Text8.SetFocus
End Sub

Private Sub Command3_Click()
    Dim Q As String
    Dim D1 As String
    Dim D2 As String
    Dim N As Integer
    Dim i As Integer
    Dim TEMP As String
    Dim FLAG1 As Integer
    FLAG1 = 0
    Set rs = con.OpenResultset("SELECT COUNT(*) AS C FROM INSTRUCTOR;", rdOpenStatic)
    N = rs.rdoColumns("C")
    rs.Close
    Set rs1 = con.OpenResultset("SELECT I_ID FROM INSTRUCTOR;", rdOpenStatic)
    For i = 1 To N
        TEMP = rs1.rdoColumns("I_ID")
        If Text8.Text = TEMP Then
            FLAG1 = 1
        End If
        rs1.MoveNext
    Next i
    rs1.Close
    If Text8.Text = "" Or Text1.Text = "" Or Text2.Text = "" Or Combo9.Text = "<--------------CITY-------------->" Or Text4.Text = "" Or Text5.Text = "" Or Text6.Text = "" Or Text7.Text = "" Or Combo1.Text = "DD" Or Combo2.Text = "MM" Or Combo3.Text = "YYYY" Or Combo4.Text = "" Or Combo5 = "" Or Combo6.Text = "DD" Or Combo7.Text = "MM" Or Combo8.Text = "YYYY" Or Combo10.Text = "<------------STATE------------>" Or Text10.Text = "" Then
        MsgBox ("Some FIELDS are EMPTY")
    ElseIf FLAG1 = 1 Then
        MsgBox ("InstructorID provided EXITS")
    Else
        D1 = Combo1.Text + "/" + Combo2.Text + "/" + Combo3.Text
        D2 = Combo6.Text + "/" + Combo7.Text + "/" + Combo8.Text
        Q = "INSERT INTO INSTRUCTOR(I_ID,I_NAME,I_ADDRESS,I_CITY,I_PIN,I_DOB,I_AGE,I_MOBILE,I_GENDER,I_SALARY,I_QUALIFICATION,I_DOJ,I_STATE,I_POLICE) VALUES ('" + Text8.Text + "','" + Text1.Text + "','" + Text2.Text + "','" + Combo9.Text + "'," + Text4.Text + ",TO_DATE('" + D1 + "','DD/MM/YYYY')," + Combo4.Text + "," + Text5.Text + ",'" + Combo5.Text + "'," + Text6.Text + ",'" + Text7.Text + "',TO_DATE('" + D2 + "','DD/MM/YYYY'),'" + Combo10.Text + "','" + Text10.Text + "');"
        con.Execute Q
        MsgBox ("Successfully Entered into Database")
        Text1.Text = ""
        Text2.Text = ""
        Combo9.Text = "<--------------CITY-------------->"
        Text4.Text = ""
        Text5.Text = ""
        Text6.Text = ""
        Text7.Text = ""
        Text8.Text = ""
        Combo10.Text = "<------------STATE------------>"
        Text10.Text = ""
        Combo1.Text = "DD"
        Combo2.Text = "MM"
        Combo3.Text = "YYYY"
        Combo4.Text = ""
        Combo5.Text = ""
        Combo6.Text = "DD"
        Combo7.Text = "MM"
        Combo8.Text = "YYYY"
        Text8.SetFocus
    End If
End Sub

Private Sub Form_Load()
    con.Connect = "uid=admin;pwd=admin;driver={Oracle in OraHome92}"
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
    i = 1940
    Do Until i = 1990
        i = i + 1
        Combo3.AddItem i
    Loop
    Combo5.AddItem "Male"
    Combo5.AddItem "Female"
    i = 24
    Do Until i = 65
        i = i + 1
        Combo4.AddItem i
    Loop
    i = 0
    Do Until i = 31
        i = i + 1
        Combo6.AddItem i
    Loop
    i = 0
    Do Until i = 12
        i = i + 1
        Combo7.AddItem i
    Loop
    i = 1975
    Do Until i = 2010
        i = i + 1
        Combo8.AddItem i
    Loop
        Combo10.AddItem "AndhraPradesh"
    Combo10.AddItem "ArunachalPradesh"
    Combo10.AddItem "Assam"
    Combo10.AddItem "Bihar"
    Combo10.AddItem "Chhatisgarh"
    Combo10.AddItem "Goa"
    Combo10.AddItem "Gujarat"
    Combo10.AddItem "Haryana"
    Combo10.AddItem "HimachalPradesh"
    Combo10.AddItem "Jammu&Kashmir"
    Combo10.AddItem "Jharkhand"
    Combo10.AddItem "Karnataka"
    Combo10.AddItem "Kerala"
    Combo10.AddItem "MadhyaPradesh"
    Combo10.AddItem "Maharashtra"
    Combo10.AddItem "Manipur"
    Combo10.AddItem "Meghalaya"
    Combo10.AddItem "Mizoram"
    Combo10.AddItem "Nagaland"
    Combo10.AddItem "Orissa"
    Combo10.AddItem "Punjab"
    Combo10.AddItem "Rajasthan"
    Combo10.AddItem "Sikkim"
    Combo10.AddItem "TamilNadu"
    Combo10.AddItem "Tripura"
    Combo10.AddItem "UttarPradesh"
    Combo10.AddItem "Uttaranchal"
    Combo10.AddItem "WestBengal"
    ''''''''''''''
        Combo9.AddItem "Abohar"
    Combo9.AddItem "Achalpur"
    Combo9.AddItem "Adipur"
    Combo9.AddItem "Agartala"
    Combo9.AddItem "Agra"
    Combo9.AddItem "Ahmedabad"
    Combo9.AddItem "Ahmednagar"
    Combo9.AddItem "Aizawl"
    Combo9.AddItem "Ajmer"
    Combo9.AddItem "Akola"
    Combo9.AddItem "Aligarh"
    Combo9.AddItem "Allahabad"
    Combo9.AddItem "Alwar"
    Combo9.AddItem "Ambala"
    Combo9.AddItem "Amethi"
    Combo9.AddItem "Ammakandakara"
    Combo9.AddItem "Amravati"
    Combo9.AddItem "Amreli"
    Combo9.AddItem "Amritsar"
    Combo9.AddItem "Anand"
    Combo9.AddItem "Anantapur"
    Combo9.AddItem "Angul"
    Combo9.AddItem "Anklesvar"
    Combo9.AddItem "Anuppur"
    Combo9.AddItem "Arakkonam"
    Combo9.AddItem "Araria"
    Combo9.AddItem "Arcot"
    Combo9.AddItem "Arrah"
    Combo9.AddItem "Aruppukkottai"
    Combo9.AddItem "Asansol"
    Combo9.AddItem "AshokNagar"
    Combo9.AddItem "Ashtamichira"
    Combo9.AddItem "Aurangabad"
    Combo9.AddItem "Bihar"
    Combo9.AddItem "Asurbandh"
    Combo9.AddItem "Azamgarh"
    Combo9.AddItem "Bahadurgarh"
    Combo9.AddItem "Baharampur"
    Combo9.AddItem "Bahraich"
    Combo9.AddItem "Balaghat"
    Combo9.AddItem "Balasore"
    Combo9.AddItem "Bali"
    Combo9.AddItem "Ballabhgarh"
    Combo9.AddItem "Ballia"
    Combo9.AddItem "Balrampur"
    Combo9.AddItem "Banda"
    Combo9.AddItem "Banganapalle"
    Combo9.AddItem "Banswara"
    Combo9.AddItem "Banur"
    Combo9.AddItem "Bapatla"
    Combo9.AddItem "Baramati"
    Combo9.AddItem "Baran"
    Combo9.AddItem "Bardhaman"
    Combo9.AddItem "Bareilly"
    Combo9.AddItem "Bargarh"
    Combo9.AddItem "Barh"
    Combo9.AddItem "Baripada"
    Combo9.AddItem "Barmer"
    Combo9.AddItem "Barnala"
    Combo9.AddItem "Barrackpur"
    Combo9.AddItem "Barwani"
    Combo9.AddItem "Bawal"
    Combo9.AddItem "Beawar"
    Combo9.AddItem "Belgaum"
    Combo9.AddItem "Bellary"
    Combo9.AddItem "Bengaluru"
    Combo9.AddItem "Berhampur"
    Combo9.AddItem "Betul"
    Combo9.AddItem "Betul"
    Combo9.AddItem "Bhagalpur"
    Combo9.AddItem "Bhavani"
    Combo9.AddItem "Bhandara"
    Combo9.AddItem "Bhajanpura"
    Combo9.AddItem "Bharatpur"
    Combo9.AddItem "Bharuch"
    Combo9.AddItem "Bhavnagar"
    Combo9.AddItem "Bhilai"
    Combo9.AddItem "Bhilwara"
    Combo9.AddItem "Bhimavaram"
    Combo9.AddItem "Bhinmal"
    Combo9.AddItem "Bhiwandi"
    Combo9.AddItem "Bhiwani"
    Combo9.AddItem "Bhopal"
    Combo9.AddItem "Bhubaneswar"
    Combo9.AddItem "Bhuj"
    Combo9.AddItem "Bhusawal"
    Combo9.AddItem "Bidar"
    Combo9.AddItem "BiharSharif"
    Combo9.AddItem "Bijnaur"
    Combo9.AddItem "Bikaner"
    Combo9.AddItem "Bilara"
    Combo9.AddItem "Bilaspur"
    Combo9.AddItem "Bilaspur"
    Combo9.AddItem "BodhGaya"
    Combo9.AddItem "BokaroSteelCity"
    Combo9.AddItem "Balangir"
    Combo9.AddItem "Bongaigaon"
    Combo9.AddItem "Buxar"
    Combo9.AddItem "Calicut"
    Combo9.AddItem "Cambay"
    Combo9.AddItem "Champawat"
    Combo9.AddItem "Chamrajnagar"
    Combo9.AddItem "Chandannagar"
    Combo9.AddItem "Chandigarh"
    Combo9.AddItem "Chapirevula"
    Combo9.AddItem "Chapra"
    Combo9.AddItem "Charkhari"
    Combo9.AddItem "CharkhiDadri"
    Combo9.AddItem "Chandrapur"
    Combo9.AddItem "Chengalpattu"
    Combo9.AddItem "Chennai"
    Combo9.AddItem "Chhatarpur"
    Combo9.AddItem "Chhindwara"
    Combo9.AddItem "Chikmagalur"
    Combo9.AddItem "Chiplun"
    Combo9.AddItem "Chirala"
    Combo9.AddItem "Chitradurga"
    Combo9.AddItem "Chitrakoot"
    Combo9.AddItem "Chittoor"
    Combo9.AddItem "Cochin"
    Combo9.AddItem "Coimbatore"
    Combo9.AddItem "Contai"
    Combo9.AddItem "CoochBehar"
    Combo9.AddItem "Coonoor"
    Combo9.AddItem "Cuddalore"
    Combo9.AddItem "Cuddapah"
    Combo9.AddItem "Cuttack"
    Combo9.AddItem "Dabra"
    Combo9.AddItem "Dahod"
    Combo9.AddItem "Daltonganj"
    Combo9.AddItem "Daman"
    Combo9.AddItem "Damoh"
    Combo9.AddItem "Darbhanga"
    Combo9.AddItem "Darjeeling"
    Combo9.AddItem "Datia"
    Combo9.AddItem "Davanagere"
    Combo9.AddItem "Dehgam"
    Combo9.AddItem "Dehradun"
    Combo9.AddItem "Deoghar"
    Combo9.AddItem "Deoria"
    Combo9.AddItem "Dewas"
    Combo9.AddItem "Delhi"
    Combo9.AddItem "Dhamtari"
    Combo9.AddItem "Dhanbad"
    Combo9.AddItem "Dhar"
    Combo9.AddItem "Dharampur"
    Combo9.AddItem "Dharamsala"
    Combo9.AddItem "Dharwad"
    Combo9.AddItem "Dhenkanal"
    Combo9.AddItem "Dholka"
    Combo9.AddItem "Dhule"
    Combo9.AddItem "Dhulian"
    Combo9.AddItem "Dhuri"
    Combo9.AddItem "Dibrugarh"
    Combo9.AddItem "Dispur"
    Combo9.AddItem "Dindigul"
    Combo9.AddItem "Diu"
    Combo9.AddItem "Dombivli"
    Combo9.AddItem "Dumdum"
    Combo9.AddItem "Durg"
    Combo9.AddItem "Durgapur"
    Combo9.AddItem "Durgapur"
    Combo9.AddItem "Dwarka"
    Combo9.AddItem "Dadri"
    Combo9.AddItem "Ernakulam"
    Combo9.AddItem "Erode"
    Combo9.AddItem "Etah"
    Combo9.AddItem "Etawah"
    Combo9.AddItem "Eluru"
    Combo9.AddItem "Faizabad"
    Combo9.AddItem "Falna"
    Combo9.AddItem "Faridabad"
    Combo9.AddItem "Faridkot"
    Combo9.AddItem "Farrukhabad"
    Combo9.AddItem "Fatehabad"
    Combo9.AddItem "Fatehgarh"
    Combo9.AddItem "FatehpurSikri"
    Combo9.AddItem "Fatehpur"
    Combo9.AddItem "Fazilka"
    Combo9.AddItem "Firozabad"
    Combo9.AddItem "Gadag"
    Combo9.AddItem "Gadchiroli"
    Combo9.AddItem "Gandhidham"
    Combo9.AddItem "Gandhinagar"
    Combo9.AddItem "Gangtok"
    Combo9.AddItem "Ganjam"
    Combo9.AddItem "Gaya"
    Combo9.AddItem "Ghatampur"
    Combo9.AddItem "Ghaziabad"
    Combo9.AddItem "Ghazipur"
    Combo9.AddItem "GoaVelha"
    Combo9.AddItem "Godhra"
    Combo9.AddItem "Gondiya"
    Combo9.AddItem "Gorakhpur"
    Combo9.AddItem "GreaterNoida"
    Combo9.AddItem "Gudalur"
    Combo9.AddItem "Gudalur"
    Combo9.AddItem "Gudalur"
    Combo9.AddItem "Gudivada"
    Combo9.AddItem "Gulbarga"
    Combo9.AddItem "Gumla"
    Combo9.AddItem "Guna"
    Combo9.AddItem "Gundlupet"
    Combo9.AddItem "Guntur"
    Combo9.AddItem "Gurgaon"
    Combo9.AddItem "Guwahati"
    Combo9.AddItem "Gwalior"
    Combo9.AddItem "Godda"
    Combo9.AddItem "Hoshiarpur"
    Combo9.AddItem "Haldia"
    Combo9.AddItem "Haldwani"
    Combo9.AddItem "Hamirpur"
    Combo9.AddItem "Hanumangarh"
    Combo9.AddItem "Howrah"
    Combo9.AddItem "Hodal"
    Combo9.AddItem "Harda"
    Combo9.AddItem "Hardoi"
    Combo9.AddItem "Harsawa"
    Combo9.AddItem "Haridwar"
    Combo9.AddItem "Hubli"
    Combo9.AddItem "Hassan"
    Combo9.AddItem "Hastinapur"
    Combo9.AddItem "Hathras"
    Combo9.AddItem "Himatnagar"
    Combo9.AddItem "Hisar"
    Combo9.AddItem "Hansi"
    Combo9.AddItem "Hyderabad"
    Combo9.AddItem "Halisahar"
    Combo9.AddItem "Indore"
    Combo9.AddItem "Imphal"
    Combo9.AddItem "Itanagar"
    Combo9.AddItem "Idar"
    Combo9.AddItem "Jabalpur"
    Combo9.AddItem "Jalandhar"
    Combo9.AddItem "Jagdalpur"
    Combo9.AddItem "Jaipur"
    Combo9.AddItem "Jais"
    Combo9.AddItem "Jaisalmer"
    Combo9.AddItem "Jaitaran"
    Combo9.AddItem "Jalalabad"
    Combo9.AddItem "Jalgaon"
    Combo9.AddItem "Jagadhri"
    Combo9.AddItem "Jagraon"
    Combo9.AddItem "Jagtial"
    Combo9.AddItem "Jalore"
    Combo9.AddItem "Jamakhandi"
    Combo9.AddItem "Jammu"
    Combo9.AddItem "Jamnagar"
    Combo9.AddItem "Jamshedpur"
    Combo9.AddItem "Jaunpur"
    Combo9.AddItem "Jhabua"
    Combo9.AddItem "Jhajjar"
    Combo9.AddItem "Jhalawar"
    Combo9.AddItem "Jhansi"
    Combo9.AddItem "Jhunjhunu"
    Combo9.AddItem "Jodhpur"
    Combo9.AddItem "Jorhat"
    Combo9.AddItem "Junagadh"
    Combo9.AddItem "Kadapa"
    Combo9.AddItem "Kailaras"
    Combo9.AddItem "Kakinada"
    Combo9.AddItem "Kalburgi"
    Combo9.AddItem "Kalyan"
    Combo9.AddItem "Kamthi"
    Combo9.AddItem "Kanchipuram"
    Combo9.AddItem "Kanker"
    Combo9.AddItem "Kannur"
    Combo9.AddItem "Kanpur"
    Combo9.AddItem "Kapurthala"
    Combo9.AddItem "Karad"
    Combo9.AddItem "Karimganj"
    Combo9.AddItem "Karimnagar"
    Combo9.AddItem "Karur"
    Combo9.AddItem "Karwar"
    Combo9.AddItem "Katihar"
    Combo9.AddItem "Katni"
    Combo9.AddItem "Khagaria"
    Combo9.AddItem "Kharagpur"
    Combo9.AddItem "Kochi"
    Combo9.AddItem "Kolar"
    Combo9.AddItem "Kolhapur"
    Combo9.AddItem "Kolkata"
    Combo9.AddItem "Kondagaon"
    Combo9.AddItem "Konnagar"
    Combo9.AddItem "Kota"
    Combo9.AddItem "Kotdwara"
    Combo9.AddItem "Kotma"
    Combo9.AddItem "Kottayam"
    Combo9.AddItem "Krishnanaga"
    Combo9.AddItem "Kurnool"
    Combo9.AddItem "Ladwa"
    Combo9.AddItem "Lakhisarai"
    Combo9.AddItem "Lalitpur"
    Combo9.AddItem "Lamka"
    Combo9.AddItem "Latur"
    Combo9.AddItem "Leh"
    Combo9.AddItem "Lonavla"
    Combo9.AddItem "Lucknow"
    Combo9.AddItem "Ludhiana"
    Combo9.AddItem "Modasa"
    Combo9.AddItem "Mithapur"
    Combo9.AddItem "Madanapalle"
    Combo9.AddItem "Madgaon"
    Combo9.AddItem "Madikeri"
    Combo9.AddItem "Madurai"
    Combo9.AddItem "Mahabaleswar"
    Combo9.AddItem "Mahabubnagar"
    Combo9.AddItem "Mahe"
    Combo9.AddItem "Mahoba"
    Combo9.AddItem "Mahwa"
    Combo9.AddItem "Mahuva"
    Combo9.AddItem "Malout"
    Combo9.AddItem "Malegaon"
    Combo9.AddItem "Mancherial"
    Combo9.AddItem "Mandla"
    Combo9.AddItem "Mandsaur"
    Combo9.AddItem "Mandya"
    Combo9.AddItem "Manesar"
    Combo9.AddItem "Mangalagiri"
    Combo9.AddItem "Mangalore"
    Combo9.AddItem "Mapusa"
    Combo9.AddItem "Marmagao"
    Combo9.AddItem "Mathura"
    Combo9.AddItem "Machilipatnam"
    Combo9.AddItem "Mahad"
    Combo9.AddItem "Meerut"
    Combo9.AddItem "Mehsana"
    Combo9.AddItem "Mira-Bhayandar"
    Combo9.AddItem "Miraj"
    Combo9.AddItem "Mirzapur"
    Combo9.AddItem "Moga"
    Combo9.AddItem "Mohali"
    Combo9.AddItem "Mohania"
    Combo9.AddItem "Mokama"
    Combo9.AddItem "Moradabad"
    Combo9.AddItem "Morshi"
    Combo9.AddItem "Motihari"
    Combo9.AddItem "MountAbu"
    Combo9.AddItem "Mukatsar"
    Combo9.AddItem "Mullanpur"
    Combo9.AddItem "Mumbai"
    Combo9.AddItem "Mussoorie"
    Combo9.AddItem "Murwara"
    Combo9.AddItem "Murshidabad"
    Combo9.AddItem "Muzaffarnagar"
    Combo9.AddItem "Muzaffarpur"
    Combo9.AddItem "Mysore"
    Combo9.AddItem "Manavadar"
    Combo9.AddItem "Nadiad"
    Combo9.AddItem "Nagapattinam"
    Combo9.AddItem "Nagarkurnool"
    Combo9.AddItem "Nagaur"
    Combo9.AddItem "Nagercoil"
    Combo9.AddItem "Nagpur"
    Combo9.AddItem "Nainital"
    Combo9.AddItem "Nalagarh"
    Combo9.AddItem "Nalgonda"
    Combo9.AddItem "Namakkal"
    Combo9.AddItem "Nanded"
    Combo9.AddItem "Nandyal"
    Combo9.AddItem "Nandurbar"
    Combo9.AddItem "Nangal"
    Combo9.AddItem "Narasaraopet"
    Combo9.AddItem "Narnaul"
    Combo9.AddItem "Narsimhapur"
    Combo9.AddItem "Narsinghgarh"
    Combo9.AddItem "Narsingarh"
    Combo9.AddItem "Nashik"
    Combo9.AddItem "NaviMumbai"
    Combo9.AddItem "Navsari"
    Combo9.AddItem "Nawalgarh"
    Combo9.AddItem "Neemuch"
    Combo9.AddItem "Nellore"
    Combo9.AddItem "NewDelhi"
    Combo9.AddItem "NewGuntur"
    Combo9.AddItem "NOIDA"
    Combo9.AddItem "Nizamabad"
    Combo9.AddItem "Ongole"
    Combo9.AddItem "Ootacamund"
    Combo9.AddItem "Orai"
    Combo9.AddItem "Palai"
    Combo9.AddItem "Palakkad"
    Combo9.AddItem "Palanpur"
    Combo9.AddItem "Pali"
    Combo9.AddItem "Palwal"
    Combo9.AddItem "Panaji"
    Combo9.AddItem "Panchkula"
    Combo9.AddItem "Pandharpur"
    Combo9.AddItem "Panipat"
    Combo9.AddItem "Panna"
    Combo9.AddItem "Panvel"
    Combo9.AddItem "Paratwada"
    Combo9.AddItem "Patan"
    Combo9.AddItem "Pathankot"
    Combo9.AddItem "Patiala"
    Combo9.AddItem "Patna"
    Combo9.AddItem "Patratu"
    Combo9.AddItem "Piduguralla"
    Combo9.AddItem "Pithoragarh"
    Combo9.AddItem "PimpriChinchwad"
    Combo9.AddItem "Ponda"
    Combo9.AddItem "Pollachi"
    Combo9.AddItem "Pokaran"
    Combo9.AddItem "Puducherry"
    Combo9.AddItem "Porbandar"
    Combo9.AddItem "PortBlair"
    Combo9.AddItem "Pratapgarh"
    Combo9.AddItem "Pratapgarh"
    Combo9.AddItem "Pratapgarh"
    Combo9.AddItem "Pune"
    Combo9.AddItem "Puri"
    Combo9.AddItem "Purnia"
    Combo9.AddItem "Pushkar"
    Combo9.AddItem "Punalur"
    Combo9.AddItem "Quilon"
    Combo9.AddItem "Raichur"
    Combo9.AddItem "Raigarh"
    Combo9.AddItem "Raipur"
    Combo9.AddItem "Rairangpur"
    Combo9.AddItem "Raisen"
    Combo9.AddItem "Rajahmundry"
    Combo9.AddItem "Rajampet"
    Combo9.AddItem "Rajgarh"
    Combo9.AddItem "Rajgir"
    Combo9.AddItem "Rajkot"
    Combo9.AddItem "Rajnandgaon"
    Combo9.AddItem "Ramanathapuram"
    Combo9.AddItem "Rameshwaram"
    Combo9.AddItem "RamGarh"
    Combo9.AddItem "Rampur"
    Combo9.AddItem "Ramnagar"
    Combo9.AddItem "Ramanagara"
    Combo9.AddItem "Ranaghat"
    Combo9.AddItem "Rani"
    Combo9.AddItem "Ranchi"
    Combo9.AddItem "Ranikhet"
    Combo9.AddItem "Raniwara"
    Combo9.AddItem "Rasheed"
    Combo9.AddItem "Ratangarh"
    Combo9.AddItem "Ratangarh"
    Combo9.AddItem "Ratlam"
    Combo9.AddItem "Ratnagiri"
    Combo9.AddItem "RaeBareli"
    Combo9.AddItem "Ravulapalem"
    Combo9.AddItem "Renukoot"
    Combo9.AddItem "Rishra"
    Combo9.AddItem "Rishikesh"
    Combo9.AddItem "Roorkee"
    Combo9.AddItem "Rewari"
    Combo9.AddItem "Rourkela"
    Combo9.AddItem "Sadri"
    Combo9.AddItem "Sagar"
    Combo9.AddItem "Saharanpur"
    Combo9.AddItem "Salem"
    Combo9.AddItem "Samastipur"
    Combo9.AddItem "Sambalpur"
    Combo9.AddItem "Sanawad"
    Combo9.AddItem "Sanchore"
    Combo9.AddItem "Sangli"
    Combo9.AddItem "Sangamner"
    Combo9.AddItem "Sangrur"
    Combo9.AddItem "Sardarshahar"
    Combo9.AddItem "Sathyamangalam"
    Combo9.AddItem "Satara"
    Combo9.AddItem "Satna"
    Combo9.AddItem "Sehore"
    Combo9.AddItem "Seoni"
    Combo9.AddItem "Shahada"
    Combo9.AddItem "Shajapur"
    Combo9.AddItem "Shegaon"
    Combo9.AddItem "Sheopur"
    Combo9.AddItem "Shevgaon"
    Combo9.AddItem "Shillong"
    Combo9.AddItem "Shimla"
    Combo9.AddItem "Shimoga"
    Combo9.AddItem "Shirala"
    Combo9.AddItem "Shivani"
    Combo9.AddItem "Sholapur"
    Combo9.AddItem "Shrigonda"
    Combo9.AddItem "Shrirampur"
    Combo9.AddItem "Shrivardhan"
    Combo9.AddItem "Siddipet"
    Combo9.AddItem "Sihor"
    Combo9.AddItem "Sikar'"
    Combo9.AddItem "Silchar"
    Combo9.AddItem "Siliguri"
    Combo9.AddItem "Silvassa"
    Combo9.AddItem "Sindhanur"
    Combo9.AddItem "Sinnar"
    Combo9.AddItem "Sitapur"
    Combo9.AddItem "Singrauli"
    Combo9.AddItem "Sirohi"
    Combo9.AddItem "Sironj"
    Combo9.AddItem "Sirsa"
    Combo9.AddItem "Sirsa"
    Combo9.AddItem "Sitamarhi"
    Combo9.AddItem "Sivakasi"
    Combo9.AddItem "Siwan"
    Combo9.AddItem "Sojat"
    Combo9.AddItem "Sonipat"
    Combo9.AddItem "Sriganganagar"
    Combo9.AddItem "Srikakulam"
    Combo9.AddItem "Srikalahasti"
    Combo9.AddItem "Srinagar"
    Combo9.AddItem "Surat"
    Combo9.AddItem "Sumerpur"
    Combo9.AddItem "Suratgarh"
    Combo9.AddItem "Surendranagar"
    Combo9.AddItem "Suri"
    Combo9.AddItem "Suryapet"
    Combo9.AddItem "Secundrabad"
    Combo9.AddItem "Takhatgarh"
    Combo9.AddItem "Tanuku"
    Combo9.AddItem "Talwara"
    Combo9.AddItem "Tamluk"
    Combo9.AddItem "Tandur"
    Combo9.AddItem "Tellicherry"
    Combo9.AddItem "Tezpur"
    Combo9.AddItem "Tenali"
    Combo9.AddItem "Thane"
    Combo9.AddItem "Thanjavur"
    Combo9.AddItem "Thathawata"
    Combo9.AddItem "Thiruvallur"
    Combo9.AddItem "Thrikkannamangal"
    Combo9.AddItem "Thrissur"
    Combo9.AddItem "Thodupuzha"
    Combo9.AddItem "Thoothukudi"
    Combo9.AddItem "Tindivanam"
    Combo9.AddItem "Tinsukia"
    Combo9.AddItem "Tirupattur"
    Combo9.AddItem "Tiruchengode"
    Combo9.AddItem "Tiruchirappalli"
    Combo9.AddItem "Tirunelveli"
    Combo9.AddItem "Tirupati"
    Combo9.AddItem "Tirupur"
    Combo9.AddItem "Tiruvannamalai"
    Combo9.AddItem "Tiruvarur"
    Combo9.AddItem "Tikamgarh"
    Combo9.AddItem "Thirthahalli"
    Combo9.AddItem "Thiruvananthapuram"
    Combo9.AddItem "Tumkur"
    Combo9.AddItem "Udaipur"
    Combo9.AddItem "Udhampur"
    Combo9.AddItem "Udupi"
    Combo9.AddItem "Udhagamandalam"
    Combo9.AddItem "Ujjain"
    Combo9.AddItem "Ulhasnagar"
    Combo9.AddItem "Umred"
    Combo9.AddItem "Unnao"
    Combo9.AddItem "Uttarpara"
    Combo9.AddItem "Vadodara"
    Combo9.AddItem "Vatakara"
    Combo9.AddItem "VallabhVidhyanagar"
    Combo9.AddItem "Valsad"
    Combo9.AddItem "Vandavasi"
    Combo9.AddItem "Vapi"
    Combo9.AddItem "Varanasi"
    Combo9.AddItem "Vasai"
    Combo9.AddItem "VascodaGama"
    Combo9.AddItem "Vellore"
    Combo9.AddItem "Vidisha"
    Combo9.AddItem "Vijayawada"
    Combo9.AddItem "Viluppuram"
    Combo9.AddItem "Virar"
    Combo9.AddItem "Visakhapatnam"
    Combo9.AddItem "Vizianagaram"
    Combo9.AddItem "Virudhachalam"
    Combo9.AddItem "Vyara"
    Combo9.AddItem "Wadi"
    Combo9.AddItem "Warangal"
    Combo9.AddItem "Wardha"
    Combo9.AddItem "Yamunanagar"
    Combo9.AddItem "Yavatmal"
    Combo9.AddItem "Zira"
    Combo9.AddItem "Ziro"

End Sub

Private Sub Form_Unload(Cancel As Integer)
    con.Close
End Sub

