*SPICE SIMULATION OF DIFFERENTIAL COMPARATOR
*    SOURCE: MARK MORAES, UNIVERSITY OF TORONTO {...!decwrl!utcsri!moraes}
*
* LABELS
**************************************
*
* VDD =  +5.0 volt supply (analog vdd)
* Vdgt = +5.0 volt supply (digital vdd)
* VSS =   0.0 volt supply (analog gnd)
* Vpos = positive input
* Vneg = negative input
*
* vphi1 = PHI1 input clock
* vphi2 = PHI2 input clock
* vphi3 = PHI3 input clock
*
* phi1b = #PHI1 input clock (PHI1 bar)
* phi2b = #PHI2 input clock (PHI2 bar)
* phi3b = #PHI3 input clock (PHI3 bar)
*
*************************************
* VOLTAGE SOURCES *******************
*************************************
VDD 1 0 DC 5.0V
VSS 4 0 DC 0.0V
Vdgt 27 0 DC 5.0V
*
VPOS 13 0 PULSE(-10.0E-5 10.0E-5 0 10NS 10NS 990NS 2000NS)
VNEG 19 0 PULSE(10.0E-5 -10.0E-5 0 10NS 10NS 990NS 2000NS)
*
Vphi1 14 0 PULSE(5.0 0.0 250NS 10NS 10NS 730NS 1000NS)
Vphi2 18 0 PULSE(0.0 5.0 260NS 10NS 10NS 710NS 1000NS)
Vphi3 26 0 PULSE(0.0 5.0 670NS 10NS 10NS 300NS 1000NS)
*
Vphi1b 16 0 PULSE(0.0 5.0 250NS 10NS 10NS 730NS 1000NS)
Vphi2b 20 0 PULSE(5.0 0.0 260NS 10NS 10NS 710NS 1000NS)
Vphi3b 8 0 PULSE(5.0 0.0 670NS 10NS 10NS 300NS 1000NS)
*
*************************
* LABELS
* ************************
* Vout+ = node 24
* Vout- = node 6
* Vpos  = node 13
* Vphi1  = node 14
* Vphi2  = node 18
* Vphi3  = node 26
**************************
*************************************
* TRANSISTOR MODELS FOR CMOS3 DEVICES 
****************************************
.MODEL nm NMOS  LEVEL=3      TOX=.50E-7   LD=0.26U    UO=785
+                 PHI=0.73     KAPPA=1.0      RSH=26      CGSO=3E-10
+                 CGDO=3E-10   CGBO=2E-10   CJSW=5.6E-10 MJSW=.5
+                 CJ=8E-4      MJ=.5        VMAX=1E5   
+                 THETA=.110   VTO=0.90     GAMMA=1.15  NSUB=4.0E16
.MODEL pm PMOS  LEVEL=3      TOX=.50E-7   LD=0.17U    UO=265
+                 PHI=0.65     KAPPA=1.0      RSH=80      CGSO=3E-10
+                 CGDO=3E-10   CGBO=2E-10   CJSW=3.4E-10 MJSW=.5
+                 CJ=3.6E-4    MJ=.5        VMAX=6.6E4 
+                 THETA=.135   VTO=-0.74    GAMMA=0.40  NSUB=6E15

M1 6 5 4 0 nm L=3.0U W=21.0U
M2 4 5 6 0 nm L=3.0U W=21.0U
M3 6 5 4 0 nm L=3.0U W=21.0U
M4 4 5 6 0 nm L=3.0U W=21.0U
M5 6 8 7 1 pm L=3.0U W=13.5U
M6 4 10 9 0 nm L=3.0U W=18.0U
M7 9 12 11 1 pm L=3.0U W=24.0U
M8 11 12 9 1 pm L=3.0U W=36.0U
M9 9 12 11 1 pm L=3.0U W=36.0U
M10 11 12 9 1 pm L=3.0U W=36.0U
M11 9 12 11 1 pm L=3.0U W=36.0U
M12 11 12 9 1 pm L=3.0U W=36.0U
M13 9 12 11 1 pm L=3.0U W=36.0U
M14 15 14 13 0 nm L=3.0U W=6.0U
M15 15 16 13 1 pm L=3.0U W=13.5U
M16 17 9 4 0 nm L=3.0U W=4.5U
M17 19 18 15 0 nm L=3.0U W=6.0U
M18 19 20 15 1 pm L=3.0U W=13.5U
M19 6 16 5 1 pm L=3.0U W=13.5U
M20 1 17 17 1 pm L=3.0U W=6.0U
M21 1 21 6 1 pm L=3.0U W=21.0U
M22 6 21 1 1 pm L=3.0U W=21.0U
M23 1 21 6 1 pm L=3.0U W=21.0U
M24 6 21 1 1 pm L=3.0U W=21.0U
M25 10 17 1 1 pm L=6.0U W=6.0U
M26 1 21 11 1 pm L=3.2U W=119.9U
M27 4 22 17 0 nm L=3.0U W=4.5U
M28 23 18 13 0 nm L=3.0U W=6.0U
M29 23 20 13 1 pm L=3.0U W=13.5U
M30 24 16 7 1 pm L=3.0U W=13.5U
M31 1 21 24 1 pm L=3.0U W=21.0U
M32 24 21 1 1 pm L=3.0U W=21.0U
M33 1 21 24 1 pm L=3.0U W=21.0U
M34 24 21 1 1 pm L=3.0U W=21.0U
M35 4 10 10 0 nm L=3.0U W=4.5U
M36 21 4 4 1 pm L=58.5U W=6.0U
M37 19 14 23 0 nm L=3.0U W=6.0U
M38 19 16 23 1 pm L=3.0U W=13.5U
M39 22 10 4 0 nm L=3.0U W=18.0U
M40 1 21 21 1 pm L=3.0U W=6.0U
M41 22 25 11 1 pm L=3.0U W=24.0U
M42 11 25 22 1 pm L=3.0U W=36.0U
M43 22 25 11 1 pm L=3.0U W=36.0U
M44 11 25 22 1 pm L=3.0U W=36.0U
M45 22 25 11 1 pm L=3.0U W=36.0U
M46 11 25 22 1 pm L=3.0U W=36.0U
M47 22 25 11 1 pm L=3.0U W=36.0U
M48 5 8 24 1 pm L=3.0U W=13.5U
M49 24 7 4 0 nm L=3.0U W=21.0U
M50 4 7 24 0 nm L=3.0U W=21.0U
M51 24 7 4 0 nm L=3.0U W=21.0U
M52 4 7 24 0 nm L=3.0U W=21.0U
M53 24 26 5 0 nm L=3.0U W=6.0U
M54 24 14 7 0 nm L=3.0U W=6.0U
C55 16 25 7.0F
M56 22 14 25 0 nm L=3.0U W=12.0U
C57 7 22 1006.0F
C58 23 25 2071.0F
C59 16 12 7.0F
M60 9 14 12 0 nm L=3.0U W=12.0U
M61 6 26 7 0 nm L=3.0U W=6.0U
C62 15 12 2071.0F
C63 5 9 1006.0F
M64 6 14 5 0 nm L=3.0U W=6.0U
C65 4 0 674.0F
C66 16 0 441.0F
C67 14 0 326.0F
C68 27 0 1163.0F
C69 25 0 605.0F
C70 22 0 417.0F
C71 23 0 237.0F
C72 7 0 285.0F
C73 24 0 127.0F
C74 26 0 119.0F
C75 5 0 293.0F
C76 8 0 74.0F
C77 11 0 240.0F
C78 1 0 412.0F
C79 21 0 181.0F
C80 18 0 159.0F
C81 20 0 58.0F
C82 19 0 64.0F
C83 10 0 61.0F
C84 13 0 63.0F
C85 17 0 76.0F
C86 6 0 125.0F
C87 9 0 418.0F
C88 15 0 238.0F
C89 12 0 607.0F
***************************
* ADD LOAD CAPACITORS
*
CL1 24 0 1.0P
CL2 6 0 1.0P
*
**************************
*
.TRAN 10NS 2000NS
.OPTIONS ACCT
.PRINT TRAN V(24,6) V(26) V(13,19)
.PRINT TRAN V(24) V(6) V(26) V(13) V(19)
.END
