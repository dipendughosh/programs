XNOR simulation
*
************************************************************************
*	Simulation Model For 4-Input xnor
************************************************************************
*	SCCS ID: %W% %G%
*	SCCS ID: %W% %G%
*
*	From Verions 3.4 models, parameters replaced by tt values.
*
*******************************************************************************
*
*         SUN MICROSYSTERMS INC. CONFIDENTIAL INFORMATION
*
*  This document contains proprietary information of Sun Microsysterms
*  Inc.  The information contained herein is not to be reproduced
*  or disclosed to third parties without the express permission of an officer
*  of Sun Microsysterms Inc.
*
*  Sun makes no warranty for the use of this information and assumes no
*  responsibility for any errors which may appear in this document nor does
*  it make any commitment to update the information contained herein.
*
*  This information should be considered PRELIMINARY and pertains only to
*  typical operation.
*
*******************************************************************************

.model jfet15 njf 
+ vto=-0.479 beta=2.72e-04 rsh=604 gamds=-0.006 is=3.88e-12 n=1.224 ldel=-0.400u
+ vgexp=2.55 alpha=3.94 ucrit=0.051 lambda=0.127 satexp=3.68
+ ng=1.100 nd=0.200 k1=0.200 eg=876e-03 gap1=1e-06 gap2=10 d=13.1 
+ gcap=2.1e-3 crat=0.666 wdel=-0.525u
+ level=3 capop=1 sat=3
+ acm=1 hdif=2.615u rshl=0 rs=0 rd=0 xti=2 tlev=2 
+ trs=2.24e-03 trd=2.24e-03 bex=481e-03 tcv=290e-06

.model jfet16 njf 
+ vto=-0.896 beta=3.08e-04 rsh=1042 gamds=-0.075 is=7.66e-2 n=1.383 ldel=-0.400u
+ vgexp=2.04 alpha=3.91 ucrit=0.88 lambda=0.037 satexp=2.58
+ ng=1.100 nd=0.250 k1=0.200 eg=865e-03 gap1=1e-06 gap2=10 d=13.1 
+ gcap=2.1e-3 crat=0.666 wdel=-0.525u
+ level=3 capop=1 sat=3
+ acm=1 hdif=0.815u rshl=0 rs=0 rd=0 xti=2 tlev=2 
+ trs=548e-06 trd=548e-06 bex=-249e-03 tcv=599e-06

.model jfet19 njf 
+ vto=-0.819 beta=2.83e-04 rsh=668 gamds=-0.041 is=1.10e-1 n=1.326 ldel=-0.400u
+ vgexp=2.15 alpha=3.51 ucrit=0.176 lambda=0.083 satexp=2.92
+ ng=1.100 nd=0.250 k1=0.200 eg=845e-03 gap1=27e-06 gap2=210 d=13.1 
+ gcap=2.1e-3 crat=0.666 wdel=-0.525u
+ level=3 capop=1 sat=3
+ acm=1 hdif=1.615u rshl=0 rs=0 rd=0 xti=2 tlev=2 
+ trs=3.22e-03 trd=3.22e-03 bex=155e-03 tcv=882e-06

.model jfet20 njf 
+ vto=-0.798 beta=3.14e-04 rsh=604 gamds=-0.006 is=3.88e-2 n=1.224 ldel=-0.400u
+ vgexp=2.55 alpha=3.94 ucrit=0.051 lambda=0.127 satexp=3.68
+ ng=1.100 nd=0.250 k1=0.200 eg=876e-03 gap1=1e-06 gap2=10 d=13.1 
+ gcap=2.1e-3 crat=0.666 wdel=-0.525u
+ level=3 capop=1 sat=3
+ acm=1 hdif=2.615u rshl=0 rs=0 rd=0 xti=2 tlev=2 
+ trs=2.24e-03 trd=2.24e-03 bex=481e-03 tcv=290e-06

.model jfet04 njf 
+ vto=0.227 beta=3.16e-04 rsh=1736 gamds=-0.041 is=1.02e-2 n=1.227 ldel=-0.400u
+ vgexp=2.35 alpha=6.53 ucrit=1e-4 lambda=0.072 satexp=3.29
+ ng=1.100 nd=0.200 k1=0.200 eg=917e-03 gap1=1e-06 gap2=10 d=13.1
+ gcap=1.5e-3 crat=0.666
+ level=3 capop=1 sat=3
+ acm=1 hdif=0.815u rshl=0 rs=0 rd=0 xti=2 tlev=2 
+ trs=-1.17e-03 trd=-1.17e-03 bex=-2 tcv=1.64e-03

.model jfet10 njf 
+ vto=0.276 beta=3.38e-04 rsh=1496 gamds=-0.024 is=1.10e-2 n=1.215 ldel=-0.400u
+ vgexp=2.38 alpha=6.28 ucrit=1e-4 lambda=0.091 satexp=3.01
+ ng=1.100 nd=0.200 k1=0.200 eg=946e-03 gap1=1e-06 gap2=10 d=13.1 
+ gcap=1.5e-3 crat=0.666
+ level=3 capop=1 sat=3
+ acm=1 hdif=1.115u rshl=0 rs=0 rd=0 xti=2 tlev=2 
+ trs=6.1e-03 trd=6.1e-03 bex=500e-03 tcv=476e-06

.model dio16 njf 
+ rsh=1575 is=5.04e-2 n=1.253 ldel=-0.400u
+ eg=831e-03 gap1=54e-06 gap2=210 d=13.1
+ gcap=2.1e-3 crat=0.666
+ level=3 capop=1 sat=3
+ acm=1 hdif=0.815u rshl=0 rs=0 rd=0 
+ xti=2 tlev=2
+ trs=-1.98e-03 trd=-1.98e-03 

.model dio19 njf 
+ rsh=759 is=1.12e-1 n=1.225 ldel=-0.400u
+ eg=821e-03 gap1=232e-06 gap2=210 d=13.1 
+ gcap=2.1e-3 crat=0.666
+ level=3 capop=1 sat=3
+ acm=1 hdif=1.615u rshl=0 rs=0 rd=0 
+ xti=2 tlev=2
+ trs=-1.79e-03 trd=-1.79e-03 

.model dio20 njf 
+ rsh=499 is=6.53e-2 n=1.220 ldel=-0.400u
+ eg=814e-03 gap1=305e-06 gap2=210 d=13.1 
+ gcap=2.1e-3 crat=0.666
+ level=3 capop=1 sat=3
+ acm=1 hdif=2.615u rshl=0 rs=0 rd=0 
+ xti=2 tlev=2
+ trs=-1.78e-03 trd=-1.78e-03 

.model dio04 njf 
+ rsh=2292 is=1.93e-2 n=1.207 ldel=-0.400u
+ eg=848e-03 gap1=319e-06 gap2=10 d=13.1 
+ gcap=1.5e-3 crat=0.666
+ level=3 capop=1 sat=3
+ acm=1 hdif=0.815u rshl=0 rs=0 rd=0 
+ xti=2 tlev=2
+ trs=-1.68e-03 trd=-1.68e-03

.model dio10 njf 
+ rsh=1724 is=1.80e-2 n=1.205 ldel=-0.400u
+ eg=840e-03 gap1=333e-06 gap2=210 d=13.1 
+ gcap=1.5e-3 crat=0.666
+ level=3 capop=1 sat=3
+ acm=1 hdif=1.115u rshl=0 rs=0 rd=0 
+ xti=2 tlev=2
+ trs=-1.34e-03 trd=-1.34e-03 
*	Nominal conditions



*	SCCS ID: %W% %G%
*
*.OPTIONS NODE NOPAGE INGOLD=2 POST NOMOD
*.WIDTH OUT=80
*.TEMP 25.0

*#include '/home/roberty/cazm/vsc3.4/lib/wires'

*	Geometries for vsc3.4 (from Jason R.)
*	SCCS ID: @(#)jfets	1.8 1/8/91
****************************************************************************
*	Basic JFET models
****************************************************************************
*	Enhancement Devices:
*	    je_p5x 
*	    je_p7x 
*	    je_1x 
*	    je_1p3x 
*	    je_2x 
*	    je_3x 
*	    je_4x 
*	    je_6x 
*	    je_8x 
*	    je_10x 
*	    je_12x 
*	    je_14x 
*	    je_16x 
*	    je_18x 
*	    je_20x 
*	    je_22x 
*	    je_24x 
*
*	Depletion Devices:
*	    jd_p5x 
*	    jd_p7x 
*	    jd_1x 
*	    jd_1p3x
*	    jd_2x 
*	    jd_3x 
*	    jd_4x 
*	    jd_6x 
*	    jd_8x 
*	    jd_10x 
*	    jd_12x 
*	    jd_14x 
*	    jd_16x 
*	    jd_18x 
*	    jd_20x 
*	    jd_22x 
*	    jd_24x 
*
*	Diode Devices:
*	    dio_p5x 
*	    dio_p7x 
*	    dio_1x 
*	    dio_1p3x 
*	    dio_2x 
*	    dio_3x 
*	    dio_4x 
*	    dio_6x 
*	    dio_8x 
*	    dio_10x 
*	    dio_12x 
*	    dio_14x 
*	    dio_16x 
*	    dio_18x 
*	    dio_20x 
*	    dio_22x 
*	    dio_24x 
*

****************************************************************************
*	EFETs
****************************************************************************

*	1/2x (50uA)
.subckt je_p5x drain gate source
je drain gate source VBG jfet04 W=3.4u L=1.0u
.ends

*	2/3x (67uA)
.subckt je_p7x drain gate source
je drain gate source VBG jfet04 W=4.3u L=1.0u
.ends

*	1x (100uA)
.subckt je_1x drain gate source
je drain gate source VBG jfet04 W=6.5u L=1.0u
.ends

*	4/3x (133uA)
.subckt je_1p3x drain gate source
je drain gate source VBG jfet04 W=8.6u L=1.0u
.ends

*	2x (200uA)
.subckt je_2x drain gate source
je drain gate source VBG jfet04 W=13.0u L=1.0u
.ends

*	3x (300uA)
.subckt je_3x drain gate source
je drain gate source VBG jfet04 W=19.5u L=1.0u
.ends

*	4x (400uA)
.subckt je_4x drain gate source
je drain gate source VBG jfet04 W=26.0u L=1.0u
.ends

*	6x (600uA)
.subckt je_6x drain gate source
je drain gate source VBG jfet04 W=6.5u L=1.0u M=6
.ends

*	8x (800uA)
.subckt je_8x drain gate source
je drain gate source VBG jfet04 W=6.5u L=1.0u M=8
.ends

*	10x (1000uA)
.subckt je_10x drain gate source
je drain gate source VBG jfet04 W=6.5u L=1.0u M=10
.ends

*	12x (1200uA)
.subckt je_12x drain gate source
je drain gate source VBG jfet04 W=6.5u L=1.0u M=12
.ends

*	14x (1400uA)
.subckt je_14x drain gate source
je drain gate source VBG jfet04 W=6.5u L=1.0u M=14
.ends

*	16x (1600uA)
.subckt je_16x drain gate source
je drain gate source VBG jfet04 W=6.5u L=1.0u M=16
.ends

*	18x (1800uA)
.subckt je_18x drain gate source
je drain gate source VBG jfet04 W=6.5u L=1.0u M=18
.ends

*	20x (2000uA)
.subckt je_20x drain gate source
je drain gate source VBG jfet04 W=6.5u L=1.0u M=20
.ends

*	22x (2200uA)
.subckt je_22x drain gate source
je drain gate source VBG jfet04 W=6.5u L=1.0u M=22
.ends

*	24x (2400uA)
.subckt je_24x drain gate source
je drain gate source VBG jfet04 W=6.5u L=1.0u M=24
.ends

****************************************************************************
*	DFETs
****************************************************************************

*	1/2x (50uA)
.subckt jd_p5x drain gate source
jdfet drain gate source VBG jfet20 W=2.0u L=5.4u
.ends

*	2/3x (67uA)
.subckt jd_p7x drain gate source
jdfet drain gate source VBG jfet20 W=2.0u L=3.8u
.ends

*	1x (100uA)
.subckt jd_1x drain gate source
jdfet drain gate source VBG jfet19 W=1.8u L=2.4u
.ends

*	4/3x (100uA)
.subckt jd_1p3x drain gate source
jdfet drain gate source VBG jfet19 W=2.2u L=2.4u
.ends

*	2x (200uA)
.subckt jd_2x drain gate source
jdfet drain gate source VBG jfet19 W=3.1u L=2.4u
.ends

*	3x (300uA)
.subckt jd_3x drain gate source
jdfet drain gate source VBG jfet19 W=4.3u L=2.4u
.ends

*	4x (400uA)
.subckt jd_4x drain gate source
jdfet drain gate source VBG jfet19 W=5.6u L=2.4u
.ends

*	6x (600uA)
.subckt jd_6x drain gate source
jdfet drain gate source VBG jfet16 W=3.1u L=2.4u M=3
.ends

*	8x (800uA)
.subckt jd_8x drain gate source
jdfet drain gate source VBG jfet16 W=3.1u L=2.4u M=4
.ends

*	10x (1000uA)
.subckt jd_10x drain gate source
jdfet drain gate source VBG jfet16 W=3.1u L=2.4u M=5
.ends

*	12x (1200uA)
.subckt jd_12x drain gate source
jdfet drain gate source VBG jfet16 W=3.1u L=2.4u M=6
.ends

*	14x (1400uA)
.subckt jd_14x drain gate source
jdfet drain gate source VBG jfet16 W=3.1u L=2.4u M=7
.ends

*	16x (1600uA)
.subckt jd_16x drain gate source
jdfet drain gate source VBG jfet16 W=3.1u L=2.4u M=8
.ends

*	18x (1800uA)
.subckt jd_18x drain gate source
jdfet drain gate source VBG jfet16 W=3.1u L=2.4u M=9
.ends

*	20x (2000uA)
.subckt jd_20x drain gate source
jdfet drain gate source VBG jfet16 W=3.1u L=2.4u M=10
.ends

*	22x (2200uA)
.subckt jd_22x drain gate source
jdfet drain gate source VBG jfet16 W=3.1u L=2.4u M=11
.ends

*	24x (2400uA)
.subckt jd_24x drain gate source
jdfet drain gate source VBG jfet16 W=3.1u L=2.4u M=12
.ends

****************************************************************************
*	DIODES
****************************************************************************

*	1/2x (50uA)
.subckt dio_p5x npos nneg
jdiode nneg npos nneg VBG dio20 W=2.0u L=5.4u
.ends

*	2/3x (67uA)
.subckt dio_p7x npos nneg
jdiode nneg npos nneg VBG dio20 W=2.0u L=3.8u
.ends

*	1x (100uA)
.subckt dio_1x npos nneg
jdiode nneg npos nneg VBG dio19 W=1.8u L=2.4u
.ends

*	4/3x (100uA)
.subckt dio_1p3x npos nneg
jdiode nneg npos nneg VBG dio19 W=2.2u L=2.4u
.ends

*	2x (200uA)
.subckt dio_2x npos nneg
jdiode nneg npos nneg VBG dio19 W=3.1u L=2.4u
.ends

*	3x (300uA)
.subckt dio_3x npos nneg
jdiode nneg npos nneg VBG dio19 W=4.3u L=2.4u
.ends

*	4x (400uA)
.subckt dio_4x npos nneg
jdiode nneg npos nneg VBG dio19 W=5.6u L=2.4u
.ends

*	6x (600uA)
.subckt dio_6x npos nneg
jdiode nneg npos nneg VBG dio16 W=3.1u L=2.4u M=3
.ends

*	8x (800uA)
.subckt dio_8x npos nneg
jdiode nneg npos nneg VBG dio16 W=3.1u L=2.4u M=4
.ends

*	10x (1000uA)
.subckt dio_10x npos nneg
jdiode nneg npos nneg VBG dio16 W=3.1u L=2.4u M=5
.ends

*	12x (1200uA)
.subckt dio_12x npos nneg
jdiode nneg npos nneg VBG dio16 W=3.1u L=2.4u M=6
.ends

*	14x (1400uA)
.subckt dio_14x npos nneg
jdiode nneg npos nneg VBG dio16 W=3.1u L=2.4u M=7
.ends

*	16x (1600uA)
.subckt dio_16x npos nneg
jdiode nneg npos nneg VBG dio16 W=3.1u L=2.4u M=8
.ends

*	18x (1800uA)
.subckt dio_18x npos nneg
jdiode nneg npos nneg VBG dio16 W=3.1u L=2.4u M=9
.ends

*	20x (2000uA)
.subckt dio_20x npos nneg
jdiode nneg npos nneg VBG dio16 W=3.1u L=2.4u M=10
.ends

*	22x (2200uA)
.subckt dio_22x npos nneg
jdiode nneg npos nneg VBG dio16 W=3.1u L=2.4u M=11
.ends

*	24x (2400uA)
.subckt dio_24x npos nneg
jdiode nneg npos nneg VBG dio16 W=3.1u L=2.4u M=12
.ends
*	SCCS ID: %W% %G%
****************************************************************************
*	JFET Gate Capacitance models
****************************************************************************
*	Enhancement Devices:
*	    ce_p5x 
*	    ce_p7x 
*	    ce_1x 
*	    ce_1p3x 
*	    ce_2x 
*	    ce_3x 
*	    ce_4x 
*	    ce_6x 
*	    ce_8x 
*	    ce_10x 
*	    ce_12x 
*	    ce_14x 
*	    ce_16x 
*	    ce_18x 
*	    ce_20x 
*	    ce_22x 
*	    ce_24x 
*
*	Depletion Devices:
*	    cd_p5x 
*	    cd_p7x 
*	    cd_1x 
*	    cd_1p3x
*	    cd_2x 
*	    cd_3x 
*	    cd_4x 
*	    cd_6x 
*	    cd_8x 
*	    cd_10x 
*	    cd_12x 
*	    cd_14x 
*	    cd_16x 
*	    cd_18x 
*	    cd_20x 
*	    cd_22x 
*	    cd_24x 
*

****************************************************************************
*	EFET Caps
****************************************************************************

*	1/2x (50uA)
.subckt ce_p5x na nc
cg na nc 1.36f
.ends

*	2/3x (67uA)
.subckt ce_p7x na nc
cg na nc 1.72f
.ends

*	1x (100uA)
.subckt ce_1x na nc
cg na nc 2.6f
.ends

*	4/3x (133uA)
.subckt ce_1p3x na nc
cg na nc 3.44f
.ends

*	2x (200uA)
.subckt ce_2x na nc
cg na nc 5.2f
.ends

*	3x (300uA)
.subckt ce_3x na nc
cg na nc 7.8f
.ends

*	4x (400uA)
.subckt ce_4x na nc
cg na nc 10.4f
.ends

*	6x (600uA)
.subckt ce_6x na nc
cg na nc 15.6f
.ends

*	8x (800uA)
.subckt ce_8x na nc
cg na nc 20.8f
.ends

*	10x (1000uA)
.subckt ce_10x na nc
cg na nc 26f
.ends

*	12x (1200uA)
.subckt ce_12x na nc
cg na nc 31.2f
.ends

*	14x (1400uA)
.subckt ce_14x na nc
cg na nc 36.4f
.ends

*	16x (1600uA)
.subckt ce_16x na nc
cg na nc 41.6f
.ends

*	18x (1800uA)
.subckt ce_18x na nc
cg na nc 46.8f
.ends

*	20x (2000uA)
.subckt ce_20x na nc
cg na nc 52f
.ends

*	22x (2200uA)
.subckt ce_22x na nc
cg na nc 57.2f
.ends

*	24x (2400uA)
.subckt ce_24x na nc
cg na nc 62.4f
.ends

****************************************************************************
*	DFETs
****************************************************************************

*	1/2x (50uA)
.subckt cd_p5x na nc
cg na nc .8f
.ends

*	2/3x (67uA)
.subckt cd_p7x na nc
cg na nc .8f
.ends

*	1x (100uA)
.subckt cd_1x na nc
cg na nc .72f
.ends

*	4/3x (100uA)
.subckt cd_1p3x na nc
cg na nc .88f
.ends

*	2x (200uA)
.subckt cd_2x na nc
cg na nc 1.24f
.ends

*	3x (300uA)
.subckt cd_3x na nc
cg na nc 1.72f
.ends

*	4x (400uA)
.subckt cd_4x na nc
cg na nc 2.24f
.ends

*	6x (600uA)
.subckt cd_6x na nc
cg na nc 3.72f
.ends

*	8x (800uA)
.subckt cd_8x na nc
cg na nc 4.96f
.ends

*	10x (1000uA)
.subckt cd_10x na nc
cg na nc 6.2f
.ends

*	12x (1200uA)
.subckt cd_12x na nc
cg na nc 7.44f
.ends

*	14x (1400uA)
.subckt cd_14x na nc
cg na nc 8.68f
.ends

*	16x (1600uA)
.subckt cd_16x na nc
cg na nc 9.92f
.ends

*	18x (1800uA)
.subckt cd_18x na nc
cg na nc 11.16f
.ends

*	20x (2000uA)
.subckt cd_20x na nc
cg na nc 12.4f
.ends

*	22x (2200uA)
.subckt cd_22x na nc
cg na nc 13.64f
.ends

*	24x (2400uA)
.subckt cd_24x na nc
cg na nc 14.88f
.ends
*	SCCS ID: @(#)voltage.sources	1.8 1/11/91
**************************************************************
*	Standard voltage sources
**************************************************************
*	Globals:
*	    Vcc		= supply
*	    VBG		= backgate
*	    low		= VOL
*	    high	= VOH
*	    unknown	= trigger point

**************************************************************
*	SUPPLY VOLTAGE SOURCES
**************************************************************
.global Vcc
.global VBG
Vcc  Vcc 0 dc 2.0
VBG  VBG 0 dc 0.6
rbg  VBG 0 10k

**************************************************************
*	TRIGGER POINT
*************************************************************
x_trig_jd Vcc trigger_point trigger_point jd_1x
x_trig_je trigger_point trigger_point 0   je_1x

* From Hang
**************************************************************
*	HIGH/LOW/UNKNOWN LOGIC LEVEL VOLTAGE SOURCES
*************************************************************
*	high and low level sources (convenient for testing gates)

.global high 
.global low
.global unknown

*	start with an approximation
vlow vlow_approx 0 dc 0.1v

*	buffer it for accuracy under different processes and temperatures
x_ref_1 vhigh_approx vlow_approx  not_1x
x_ref_2 vlow_unbuf   vhigh_approx not_1x
x_ref_3 vhigh_unbuf  vlow_unbuf   not_1x
x_ref_4 0 vhigh_unbuf not_1x

*	use voltage-controlled voltage source to get infinite buffering
e_high_buffer high 0 vhigh_unbuf 0 1.0
rhigh high 0 1Meg
e_low_buffer  low  0 vlow_unbuf  0 1.0
rlow low 0 1Meg
e_unknown_buffer unknown 0 trigger_point 0 1.0
rtrig unknown 0 1Meg
*	SCCS ID: %W% %G%
*************************************************************
*	PRIMITIVE LOGIC GATES--Use these to construct leaf cells
*************************************************************
*	Index:
*	    not_p5x
*	    not_p7x
*	    not_1x
*	    not_1p3x
*	    not_2x
*	    not_3x
*	    not_4x
*	    not_6x
*	    not_8x
*	    not_10x
*	    not_12x
*	    not_14x
*	    not_16x
*	    not_18x
*	    not_22x
*	    not_24x
*
*	    nor2_p5x
*	    nor2_p7x
*	    nor2_1x
*	    nor2_1p3x
*	    nor2_2x
*	    nor2_3x
*	    nor2_4x
*	    nor2_6x
*	    nor2_8x
*	    nor2_10x
*	    nor2_12x
*	    nor2_14x
*	    nor2_16x
*	    nor2_18x
*	    nor2_22x
*	    nor2_24x
*
*	    nor3_p5x
*	    nor3_p7x
*	    nor3_1x
*	    nor3_1p3x
*	    nor3_2x
*	    nor3_3x
*	    nor3_4x
*	    nor3_6x
*	    nor3_8x
*	    nor3_10x
*	    nor3_12x
*	    nor3_14x
*	    nor3_16x
*	    nor3_18x
*	    nor3_22x
*	    nor3_24x
*
*	    nor4_p5x
*	    nor4_p7x
*	    nor4_1x
*	    nor4_1p3x
*	    nor4_2x
*	    nor4_3x
*	    nor4_4x
*	    nor4_6x
*	    nor4_8x
*	    nor4_10x
*	    nor4_12x
*	    nor4_14x
*	    nor4_16x
*	    nor4_18x
*	    nor4_22x
*	    nor4_24x
*
*	SQUIRT BUFFERS (INVERTING)
*		not_sb_p7x2x 	also nor2, nor3, nor4
*		not_sb_1x2x 	also nor2, nor3, nor4
*		not_sb_1x3x 	also nor2, nor3, nor4
*		not_sb_1p3x4x 	also nor2, nor3, nor4
*		not_sb_2x4x 	also nor2, nor3, nor4
*		not_sb_2x6x 	also nor2, nor3, nor4
*		not_sb_3x6x 	also nor2, nor3, nor4
*		not_sb_3x8x 	also nor2, nor3, nor4
*		not_sb_4x10x 	also nor2, nor3, nor4
*		not_sb_4x12x 	also nor2, nor3, nor4
*		not_sb_6x16x 	also nor2, nor3, nor4
*		not_sb_6x20x 	also nor2, nor3, nor4
*		not_sb_8x24x 	also nor2, nor3, nor4
*
*	FEED-FORWARD BUFFERS (NON_INVERTING)
*		buf_fb_p7x2x 
*		buf_fb_1x3x 
*		buf_fb_1x4x 
*		buf_fb_1p3x4x 
*		buf_fb_2x6x 
*		buf_fb_2x8x 
*		buf_fb_3x8x 
*		buf_fb_3x10x 
*		buf_fb_4x10x 
*		buf_fb_3x12x 
*		buf_fb_4x12x 
*		buf_fb_6x16x 
*		buf_fb_6x20x 
*		buf_fb_8x20x 
*		buf_fb_8x24x 
*
*
*	LOAD GATES
*	    load_p5x
*	    load_p7x
*	    load_1x
*	    load_1p3x
*	    load_2x
*	    load_3x
*	    load_4x
*
*************************************************************

.subckt not_p5x out in
xjd1 Vcc out out jd_p5x
xje1 out in  0 je_p5x
xcin   in  0 ce_p5x
xcout1 out 0 cd_p5x
xcout2 out 0 ce_p5x
.ends

.subckt not_p7x out in
xjd1 Vcc out out jd_p7x
xje1 out in  0 je_p7x
xcin   in  0 ce_p7x
xcout1 out 0 cd_p7x
xcout2 out 0 ce_p7x
.ends

.subckt not_1x out in
xjd1 Vcc out out jd_1x
xje1 out in  0 je_1x
xcin   in  0 ce_1x
xcout1 out 0 cd_1x
xcout2 out 0 ce_1x
.ends

.subckt not_1p3x out in
xjd1 Vcc out out jd_1p3x
xje1 out in  0 je_1p3x
xcin   in  0 ce_1p3x
xcout1 out 0 cd_1p3x
xcout2 out 0 ce_1p3x
.ends

.subckt not_2x out in
xjd1 Vcc out out jd_2x
xje1 out in  0 je_2x
xcin   in  0 ce_2x
xcout1 out 0 cd_2x
xcout2 out 0 ce_2x
.ends

.subckt not_3x out in
xjd1 Vcc out out jd_3x
xje1 out in  0 je_3x
xcin   in  0 ce_3x
xcout1 out 0 cd_3x
xcout2 out 0 ce_3x
.ends

.subckt not_4x out in
xjd1 Vcc out out jd_4x
xje1 out in  0 je_4x
xcin   in  0 ce_4x
xcout1 out 0 cd_4x
xcout2 out 0 ce_4x
.ends

.subckt not_6x out in
xjd1 Vcc out out jd_6x
xje1 out in  0 je_6x
xcin   in  0 ce_6x
xcout1 out 0 cd_6x
xcout2 out 0 ce_6x
.ends

.subckt not_8x out in
xjd1 Vcc out out jd_8x
xje1 out in  0 je_8x
xcin   in  0 ce_8x
xcout1 out 0 cd_8x
xcout2 out 0 ce_8x
.ends

.subckt not_10x out in
xjd1 Vcc out out jd_10x
xje1 out in  0 je_10x
xcin   in  0 ce_10x
xcout1 out 0 cd_10x
xcout2 out 0 ce_10x
.ends

.subckt not_12x out in
xjd1 Vcc out out jd_12x
xje1 out in  0 je_12x
xcin   in  0 ce_12x
xcout1 out 0 cd_12x
xcout2 out 0 ce_12x
.ends

.subckt not_14x out in
xjd1 Vcc out out jd_14x
xje1 out in  0 je_14x
xcin   in  0 ce_14x
xcout1 out 0 cd_14x
xcout2 out 0 ce_14x
.ends

.subckt not_16x out in
xjd1 Vcc out out jd_16x
xje1 out in  0 je_16x
xcin   in  0 ce_16x
xcout1 out 0 cd_16x
xcout2 out 0 ce_16x
.ends

.subckt not_18x out in
xjd1 Vcc out out jd_18x
xje1 out in  0 je_18x
xcin   in  0 ce_18x
xcout1 out 0 cd_18x
xcout2 out 0 ce_18x
.ends

.subckt not_20x out in
xjd1 Vcc out out jd_20x
xje1 out in  0 je_20x
xcin   in  0 ce_20x
xcout1 out 0 cd_20x
xcout2 out 0 ce_20x
.ends

.subckt not_22x out in
xjd1 Vcc out out jd_22x
xje1 out in  0 je_22x
xcin   in  0 ce_22x
xcout1 out 0 cd_22x
xcout2 out 0 ce_22x
.ends

.subckt not_24x out in
xjd1 Vcc out out jd_24x
xje1 out in  0 je_24x
xcin   in  0 ce_24x
xcout1 out 0 cd_24x
xcout2 out 0 ce_24x
.ends


.subckt nor2_p5x out in1 in2
xj1 Vcc out out jd_p5x
xj2 out in1 0 je_p5x
xj3 out in2 0 je_p5x
xcin1  in1 0 ce_p5x
xcin2  in2 0 ce_p5x
xcoutd out 0 cd_p5x
xcoute out 0 ce_p5x M=2
.ends

.subckt nor2_p7x out in1 in2
xj1 Vcc out out jd_p7x
xj2 out in1 0 je_p7x
xj3 out in2 0 je_p7x
xcin1  in1 0 ce_p7x
xcin2  in2 0 ce_p7x
xcoutd out 0 cd_p7x
xcoute out 0 ce_p7x M=2
.ends

.subckt nor2_1x out in1 in2
xj1 Vcc out out jd_1x
xj2 out in1 0 je_1x
xj3 out in2 0 je_1x
xcin1  in1 0 ce_1x
xcin2  in2 0 ce_1x
xcoutd out 0 cd_1x
*wrr
*xcoute out 0 ce_1x M=2
xcoute out 0 ce_1x
.ends

.subckt nor2_1p3x out in1 in2
xj1 Vcc out out jd_1p3x
xj2 out in1 0 je_1p3x
xj3 out in2 0 je_1p3x
xcin1  in1 0 ce_1p3x
xcin2  in2 0 ce_1p3x
xcoutd out 0 cd_1p3x
xcoute out 0 ce_1p3x M=2
.ends

.subckt nor2_2x out in1 in2
xj1 Vcc out out jd_2x
xj2 out in1 0 je_2x
xj3 out in2 0 je_2x
xcin1  in1 0 ce_2x
xcin2  in2 0 ce_2x
xcoutd out 0 cd_2x
xcoute out 0 ce_2x M=2
.ends

.subckt nor2_3x out in1 in2
xj1 Vcc out out jd_3x
xj2 out in1 0 je_3x
xj3 out in2 0 je_3x
xcin1  in1 0 ce_3x
xcin2  in2 0 ce_3x
xcoutd out 0 cd_3x
xcoute out 0 ce_3x M=2
.ends

.subckt nor2_4x out in1 in2
xj1 Vcc out out jd_4x
xj2 out in1 0 je_4x
xj3 out in2 0 je_4x
xcin1  in1 0 ce_4x
xcin2  in2 0 ce_4x
xcoutd out 0 cd_4x
xcoute out 0 ce_4x M=2
.ends

.subckt nor2_6x out in1 in2
xj1 Vcc out out jd_6x
xj2 out in1 0 je_6x
xj3 out in2 0 je_6x
xcin1  in1 0 ce_6x
xcin2  in2 0 ce_6x
xcoutd out 0 cd_6x
xcoute out 0 ce_6x M=2
.ends

.subckt nor2_8x out in1 in2
xj1 Vcc out out jd_8x
xj2 out in1 0 je_8x
xj3 out in2 0 je_8x
xcin1  in1 0 ce_8x
xcin2  in2 0 ce_8x
xcoutd out 0 cd_8x
xcoute out 0 ce_8x M=2
.ends

.subckt nor2_10x out in1 in2
xj1 Vcc out out jd_10x
xj2 out in1 0 je_10x
xj3 out in2 0 je_10x
xcin1  in1 0 ce_10x
xcin2  in2 0 ce_10x
xcoutd out 0 cd_10x
xcoute out 0 ce_10x M=2
.ends

.subckt nor2_12x out in1 in2
xj1 Vcc out out jd_12x
xj2 out in1 0 je_12x
xj3 out in2 0 je_12x
xcin1  in1 0 ce_12x
xcin2  in2 0 ce_12x
xcoutd out 0 cd_12x
xcoute out 0 ce_12x M=2
.ends

.subckt nor2_14x out in1 in2
xj1 Vcc out out jd_14x
xj2 out in1 0 je_14x
xj3 out in2 0 je_14x
xcin1  in1 0 ce_14x
xcin2  in2 0 ce_14x
xcoutd out 0 cd_14x
xcoute out 0 ce_14x M=2
.ends

.subckt nor2_16x out in1 in2
xj1 Vcc out out jd_16x
xj2 out in1 0 je_16x
xj3 out in2 0 je_16x
xcin1  in1 0 ce_16x
xcin2  in2 0 ce_16x
xcoutd out 0 cd_16x
xcoute out 0 ce_16x M=2
.ends

.subckt nor2_18x out in1 in2
xj1 Vcc out out jd_18x
xj2 out in1 0 je_18x
xj3 out in2 0 je_18x
xcin1  in1 0 ce_18x
xcin2  in2 0 ce_18x
xcoutd out 0 cd_18x
xcoute out 0 ce_18x M=2
.ends

.subckt nor2_20x out in1 in2
xj1 Vcc out out jd_20x
xj2 out in1 0 je_20x
xj3 out in2 0 je_20x
xcin1  in1 0 ce_20x
xcin2  in2 0 ce_20x
xcoutd out 0 cd_20x
xcoute out 0 ce_20x M=2
.ends

.subckt nor2_22x out in1 in2
xj1 Vcc out out jd_22x
xj2 out in1 0 je_22x
xj3 out in2 0 je_22x
xcin1  in1 0 ce_22x
xcin2  in2 0 ce_22x
xcoutd out 0 cd_22x
xcoute out 0 ce_22x M=2
.ends

.subckt nor2_24x out in1 in2
xj1 Vcc out out jd_24x
xj2 out in1 0 je_24x
xj3 out in2 0 je_24x
xcin1  in1 0 ce_24x
xcin2  in2 0 ce_24x
xcoutd out 0 cd_24x
xcoute out 0 ce_24x M=2
.ends


.subckt nor3_p5x out in1 in2 in3
xj1 Vcc out out jd_p5x
xj2 out in1 0 je_p5x
xj3 out in2 0 je_p5x
xj4 out in3 0 je_p5x
xcin1  in1 0 ce_p5x
xcin2  in2 0 ce_p5x
xcin3  in3 0 ce_p5x
xcoutd out 0 cd_p5x
xcoute out 0 ce_p5x M=3
.ends

.subckt nor3_p7x out in1 in2 in3
xj1 Vcc out out jd_p7x
xj2 out in1 0 je_p7x
xj3 out in2 0 je_p7x
xj4 out in3 0 je_p7x
xcin1  in1 0 ce_p7x
xcin2  in2 0 ce_p7x
xcin3  in3 0 ce_p7x
xcoutd out 0 cd_p7x
xcoute out 0 ce_p7x M=3
.ends

.subckt nor3_1x out in1 in2 in3
xj1 Vcc out out jd_1x
xj2 out in1 0 je_1x
xj3 out in2 0 je_1x
xj4 out in3 0 je_1x
xcin1  in1 0 ce_1x
xcin2  in2 0 ce_1x
xcin3  in3 0 ce_1x
xcoutd out 0 cd_1x
xcoute out 0 ce_1x M=3
.ends

.subckt nor3_1p3x out in1 in2 in3
xj1 Vcc out out jd_1p3x
xj2 out in1 0 je_1p3x
xj3 out in2 0 je_1p3x
xj4 out in3 0 je_1p3x
xcin1  in1 0 ce_1p3x
xcin2  in2 0 ce_1p3x
xcin3  in3 0 ce_1p3x
xcoutd out 0 cd_1p3x
xcoute out 0 ce_1p3x M=3
.ends

.subckt nor3_2x out in1 in2 in3
xj1 Vcc out out jd_2x
xj2 out in1 0 je_2x
xj3 out in2 0 je_2x
xj4 out in3 0 je_2x
xcin1  in1 0 ce_2x
xcin2  in2 0 ce_2x
xcin3  in3 0 ce_2x
xcoutd out 0 cd_2x
xcoute out 0 ce_2x M=3
.ends

.subckt nor3_3x out in1 in2 in3
xj1 Vcc out out jd_3x
xj2 out in1 0 je_3x
xj3 out in2 0 je_3x
xj4 out in3 0 je_3x
xcin1  in1 0 ce_3x
xcin2  in2 0 ce_3x
xcin3  in3 0 ce_3x
xcoutd out 0 cd_3x
xcoute out 0 ce_3x M=3
.ends

.subckt nor3_4x out in1 in2 in3
xj1 Vcc out out jd_4x
xj2 out in1 0 je_4x
xj3 out in2 0 je_4x
xj4 out in3 0 je_4x
xcin1  in1 0 ce_4x
xcin2  in2 0 ce_4x
xcin3  in3 0 ce_4x
xcoutd out 0 cd_4x
xcoute out 0 ce_4x M=3
.ends

.subckt nor3_6x out in1 in2 in3
xj1 Vcc out out jd_6x
xj2 out in1 0 je_6x
xj3 out in2 0 je_6x
xj4 out in3 0 je_6x
xcin1  in1 0 ce_6x
xcin2  in2 0 ce_6x
xcin3  in3 0 ce_6x
xcoutd out 0 cd_6x
xcoute out 0 ce_6x M=3
.ends

.subckt nor3_8x out in1 in2 in3
xj1 Vcc out out jd_8x
xj2 out in1 0 je_8x
xj3 out in2 0 je_8x
xj4 out in3 0 je_8x
xcin1  in1 0 ce_8x
xcin2  in2 0 ce_8x
xcin3  in3 0 ce_8x
xcoutd out 0 cd_8x
xcoute out 0 ce_8x M=3
.ends

.subckt nor3_10x out in1 in2 in3
xj1 Vcc out out jd_10x
xj2 out in1 0 je_10x
xj3 out in2 0 je_10x
xj4 out in3 0 je_10x
xcin1  in1 0 ce_10x
xcin2  in2 0 ce_10x
xcin3  in3 0 ce_10x
xcoutd out 0 cd_10x
xcoute out 0 ce_10x M=3
.ends

.subckt nor3_12x out in1 in2 in3
xj1 Vcc out out jd_12x
xj2 out in1 0 je_12x
xj3 out in2 0 je_12x
xj4 out in3 0 je_12x
xcin1  in1 0 ce_12x
xcin2  in2 0 ce_12x
xcin3  in3 0 ce_12x
xcoutd out 0 cd_12x
xcoute out 0 ce_12x M=3
.ends

.subckt nor3_14x out in1 in2 in3
xj1 Vcc out out jd_14x
xj2 out in1 0 je_14x
xj3 out in2 0 je_14x
xj4 out in3 0 je_14x
xcin1  in1 0 ce_14x
xcin2  in2 0 ce_14x
xcin3  in3 0 ce_14x
xcoutd out 0 cd_14x
xcoute out 0 ce_14x M=3
.ends

.subckt nor3_16x out in1 in2 in3
xj1 Vcc out out jd_16x
xj2 out in1 0 je_16x
xj3 out in2 0 je_16x
xj4 out in3 0 je_16x
xcin1  in1 0 ce_16x
xcin2  in2 0 ce_16x
xcin3  in3 0 ce_16x
xcoutd out 0 cd_16x
xcoute out 0 ce_16x M=3
.ends

.subckt nor3_18x out in1 in2 in3
xj1 Vcc out out jd_18x
xj2 out in1 0 je_18x
xj3 out in2 0 je_18x
xj4 out in3 0 je_18x
xcin1  in1 0 ce_18x
xcin2  in2 0 ce_18x
xcin3  in3 0 ce_18x
xcoutd out 0 cd_18x
xcoute out 0 ce_18x M=3
.ends

.subckt nor3_20x out in1 in2 in3
xj1 Vcc out out jd_20x
xj2 out in1 0 je_20x
xj3 out in2 0 je_20x
xj4 out in3 0 je_20x
xcin1  in1 0 ce_20x
xcin2  in2 0 ce_20x
xcin3  in3 0 ce_20x
xcoutd out 0 cd_20x
xcoute out 0 ce_20x M=3
.ends

.subckt nor3_22x out in1 in2 in3
xj1 Vcc out out jd_22x
xj2 out in1 0 je_22x
xj3 out in2 0 je_22x
xj4 out in3 0 je_22x
xcin1  in1 0 ce_22x
xcin2  in2 0 ce_22x
xcin3  in3 0 ce_22x
xcoutd out 0 cd_22x
xcoute out 0 ce_22x M=3
.ends

.subckt nor3_24x out in1 in2 in3
xj1 Vcc out out jd_24x
xj2 out in1 0 je_24x
xj3 out in2 0 je_24x
xj4 out in3 0 je_24x
xcin1  in1 0 ce_24x
xcin2  in2 0 ce_24x
xcin3  in3 0 ce_24x
xcoutd out 0 cd_24x
xcoute out 0 ce_24x M=3
.ends


.subckt nor4_p5x out in1 in2 in3 in4
xj1 Vcc out out jd_p5x
xj2 out in1 0 je_p5x
xj3 out in2 0 je_p5x
xj4 out in3 0 je_p5x
xj5 out in4 0 je_p5x
xcin1  in1 0 ce_p5x
xcin2  in2 0 ce_p5x
xcin3  in3 0 ce_p5x
xcin4  in4 0 ce_p5x
xcoutd out 0 cd_p5x
xcoute out 0 ce_p5x M=4
.ends

.subckt nor4_p7x out in1 in2 in3 in4
xj1 Vcc out out jd_p7x
xj2 out in1 0 je_p7x
xj3 out in2 0 je_p7x
xj4 out in3 0 je_p7x
xj5 out in4 0 je_p7x
xcin1  in1 0 ce_p7x
xcin2  in2 0 ce_p7x
xcin3  in3 0 ce_p7x
xcin4  in4 0 ce_p7x
xcoutd out 0 cd_p7x
xcoute out 0 ce_p7x M=4
.ends

.subckt nor4_1x out in1 in2 in3 in4
xj1 Vcc out out jd_1x
xj2 out in1 0 je_1x
xj3 out in2 0 je_1x
xj4 out in3 0 je_1x
xj5 out in4 0 je_1x
xcin1  in1 0 ce_1x
xcin2  in2 0 ce_1x
xcin3  in3 0 ce_1x
xcin4  in4 0 ce_1x
xcoutd out 0 cd_1x
xcoute out 0 ce_1x M=4
.ends

.subckt nor4_1p3x out in1 in2 in3 in4
xj1 Vcc out out jd_1p3x
xj2 out in1 0 je_1p3x
xj3 out in2 0 je_1p3x
xj4 out in3 0 je_1p3x
xj5 out in4 0 je_1p3x
xcin1  in1 0 ce_1p3x
xcin2  in2 0 ce_1p3x
xcin3  in3 0 ce_1p3x
xcin4  in4 0 ce_1p3x
xcoutd out 0 cd_1p3x
xcoute out 0 ce_1p3x M=4
.ends

.subckt nor4_2x out in1 in2 in3 in4
xj1 Vcc out out jd_2x
xj2 out in1 0 je_2x
xj3 out in2 0 je_2x
xj4 out in3 0 je_2x
xj5 out in4 0 je_2x
xcin1  in1 0 ce_2x
xcin2  in2 0 ce_2x
xcin3  in3 0 ce_2x
xcin4  in4 0 ce_2x
xcoutd out 0 cd_2x
xcoute out 0 ce_2x M=4
.ends

.subckt nor4_3x out in1 in2 in3 in4
xj1 Vcc out out jd_3x
xj2 out in1 0 je_3x
xj3 out in2 0 je_3x
xj4 out in3 0 je_3x
xj5 out in4 0 je_3x
xcin1  in1 0 ce_3x
xcin2  in2 0 ce_3x
xcin3  in3 0 ce_3x
xcin4  in4 0 ce_3x
xcoutd out 0 cd_3x
xcoute out 0 ce_3x M=4
.ends

.subckt nor4_4x out in1 in2 in3 in4
xj1 Vcc out out jd_4x
xj2 out in1 0 je_4x
xj3 out in2 0 je_4x
xj4 out in3 0 je_4x
xj5 out in4 0 je_4x
xcin1  in1 0 ce_4x
xcin2  in2 0 ce_4x
xcin3  in3 0 ce_4x
xcin4  in4 0 ce_4x
xcoutd out 0 cd_4x
xcoute out 0 ce_4x M=4
.ends

.subckt nor4_6x out in1 in2 in3 in4
xj1 Vcc out out jd_6x
xj2 out in1 0 je_6x
xj3 out in2 0 je_6x
xj4 out in3 0 je_6x
xj5 out in4 0 je_6x
xcin1  in1 0 ce_6x
xcin2  in2 0 ce_6x
xcin3  in3 0 ce_6x
xcin4  in4 0 ce_6x
xcoutd out 0 cd_6x
xcoute out 0 ce_6x M=4
.ends

.subckt nor4_8x out in1 in2 in3 in4
xj1 Vcc out out jd_8x
xj2 out in1 0 je_8x
xj3 out in2 0 je_8x
xj4 out in3 0 je_8x
xj5 out in4 0 je_8x
xcin1  in1 0 ce_8x
xcin2  in2 0 ce_8x
xcin3  in3 0 ce_8x
xcin4  in4 0 ce_8x
xcoutd out 0 cd_8x
xcoute out 0 ce_8x M=4
.ends

.subckt nor4_10x out in1 in2 in3 in4
xj1 Vcc out out jd_10x
xj2 out in1 0 je_10x
xj3 out in2 0 je_10x
xj4 out in3 0 je_10x
xj5 out in4 0 je_10x
xcin1  in1 0 ce_10x
xcin2  in2 0 ce_10x
xcin3  in3 0 ce_10x
xcin4  in4 0 ce_10x
xcoutd out 0 cd_10x
xcoute out 0 ce_10x M=4
.ends

.subckt nor4_12x out in1 in2 in3 in4
xj1 Vcc out out jd_12x
xj2 out in1 0 je_12x
xj3 out in2 0 je_12x
xj4 out in3 0 je_12x
xj5 out in4 0 je_12x
xcin1  in1 0 ce_12x
xcin2  in2 0 ce_12x
xcin3  in3 0 ce_12x
xcin4  in4 0 ce_12x
xcoutd out 0 cd_12x
xcoute out 0 ce_12x M=4
.ends

.subckt nor4_14x out in1 in2 in3 in4
xj1 Vcc out out jd_14x
xj2 out in1 0 je_14x
xj3 out in2 0 je_14x
xj4 out in3 0 je_14x
xj5 out in4 0 je_14x
xcin1  in1 0 ce_14x
xcin2  in2 0 ce_14x
xcin3  in3 0 ce_14x
xcin4  in4 0 ce_14x
xcoutd out 0 cd_14x
xcoute out 0 ce_14x M=4
.ends

.subckt nor4_16x out in1 in2 in3 in4
xj1 Vcc out out jd_16x
xj2 out in1 0 je_16x
xj3 out in2 0 je_16x
xj4 out in3 0 je_16x
xj5 out in4 0 je_16x
xcin1  in1 0 ce_16x
xcin2  in2 0 ce_16x
xcin3  in3 0 ce_16x
xcin4  in4 0 ce_16x
xcoutd out 0 cd_16x
xcoute out 0 ce_16x M=4
.ends

.subckt nor4_18x out in1 in2 in3 in4
xj1 Vcc out out jd_18x
xj2 out in1 0 je_18x
xj3 out in2 0 je_18x
xj4 out in3 0 je_18x
xj5 out in4 0 je_18x
xcin1  in1 0 ce_18x
xcin2  in2 0 ce_18x
xcin3  in3 0 ce_18x
xcin4  in4 0 ce_18x
xcoutd out 0 cd_18x
xcoute out 0 ce_18x M=4
.ends

.subckt nor4_20x out in1 in2 in3 in4
xj1 Vcc out out jd_20x
xj2 out in1 0 je_20x
xj3 out in2 0 je_20x
xj4 out in3 0 je_20x
xj5 out in4 0 je_20x
xcin1  in1 0 ce_20x
xcin2  in2 0 ce_20x
xcin3  in3 0 ce_20x
xcin4  in4 0 ce_20x
xcoutd out 0 cd_20x
xcoute out 0 ce_20x M=4
.ends

.subckt nor4_22x out in1 in2 in3 in4
xj1 Vcc out out jd_22x
xj2 out in1 0 je_22x
xj3 out in2 0 je_22x
xj4 out in3 0 je_22x
xj5 out in4 0 je_22x
xcin1  in1 0 ce_22x
xcin2  in2 0 ce_22x
xcin3  in3 0 ce_22x
xcin4  in4 0 ce_22x
xcoutd out 0 cd_22x
xcoute out 0 ce_22x M=4
.ends

.subckt nor4_24x out in1 in2 in3 in4
xj1 Vcc out out jd_24x
xj2 out in1 0 je_24x
xj3 out in2 0 je_24x
xj4 out in3 0 je_24x
xj5 out in4 0 je_24x
xcin1  in1 0 ce_24x
xcin2  in2 0 ce_24x
xcin3  in3 0 ce_24x
xcin4  in4 0 ce_24x
xcoutd out 0 cd_24x
xcoute out 0 ce_24x M=4
.ends



*************************************************************************
* LOAD GATES:  make it easy to load a test circuit
*************************************************************************

.subckt load_p5x node
xje n1 node 0 je_p5x
xjd Vcc n1 n1 jd_p5x
xd1 n1 0 dio_p5x
.ends

.subckt load_p7x node
xje1 n1 node 0 je_p7x
xjd Vcc n1 n1 jd_p7x
xd1 n1 0 dio_p7x
.ends

.subckt load_1x node
xje1 n1 node 0 je_1x
xjd Vcc n1 n1 jd_1x
xd1 n1 0 dio_1x
.ends

.subckt load_1p3x node
xje1 n1 node 0 jei_1p3x
xjd Vcc n1 n1 jd_1p3x
xd1 n1 0 dio_1p3x
.ends

.subckt load_2x node
xje1 n1 node 0 jei_2x
xjd Vcc n1 n1 jd_2x
xd1 n1 0 dio_2x
.ends

.subckt load_3x node
xje1 n1 node 0 je_3x
xjd Vcc n1 n1 jd_3x
xd1 n1 0 dio_3x
.ends

.subckt load_4x node
xje1 n1 node 0 je_4x
xjd Vcc n1 n1 jd_4x
xd1 n1 0 dio_4x
.ends


*************************************************************************
* FEED-FORWARD BUFFER
*************************************************************************

.subckt buf_fb_p7x2x out in
* small devices
xj1 n1 in 0 je_p7x
xj2 Vcc n1 n1 jd_p7x
xcj1g in 0 ce_p7x
xcj1d n1 0 ce_p7x
xcj2s n1 0 cd_p7x
* large devices
xj3 out n1 0 je_2x
xj4 Vcc in out jd_2x
xcj3g n1 0 ce_2x
xcj3d out 0 ce_2x
xcj4g in 0 cd_2x
xcj4s out 0 cd_2x
.ends

.subckt buf_fb_1x3x out in
* small devices
xj1 n1 in 0 je_1x
xj2 Vcc n1 n1 jd_1x
xcj1g in 0 ce_1x
xcj1d n1 0 ce_1x
xcj2s n1 0 cd_1x
* large devices
xj3 out n1 0 je_3x
xj4 Vcc in out jd_3x
xcj3g n1 0 ce_3x
xcj3d out 0 ce_3x
xcj4g in 0 cd_3x
xcj4s out 0 cd_3x
.ends

.subckt buf_fb_1x4x out in
* small devices
xj1 n1 in 0 je_1x
xj2 Vcc n1 n1 jd_1x
xcj1g in 0 ce_1x
xcj1d n1 0 ce_1x
xcj2s n1 0 cd_1x
* large devices
xj3 out n1 0 je_4x
xj4 Vcc in out jd_4x
xcj3g n1 0 ce_4x
xcj3d out 0 ce_4x
xcj4g in 0 cd_4x
xcj4s out 0 cd_4x
.ends

.subckt buf_fb_1p3x4x out in
* small devices
xj1 n1 in 0 je_1p3x
xj2 Vcc n1 n1 jd_1p3x
xcj1g in 0 ce_1p3x
xcj1d n1 0 ce_1p3x
xcj2s n1 0 cd_1p3x
* large devices
xj3 out n1 0 je_4x
xj4 Vcc in out jd_4x
xcj3g n1 0 ce_4x
xcj3d out 0 ce_4x
xcj4g in 0 cd_4x
xcj4s out 0 cd_4x
.ends

.subckt buf_fb_2x6x out in
* small devices
xj1 n1 in 0 je_2x
xj2 Vcc n1 n1 jd_2x
xcj1g in 0 ce_2x
xcj1d n1 0 ce_2x
xcj2s n1 0 cd_2x
* large devices
xj3 out n1 0 je_6x
xj4 Vcc in out jd_6x
xcj3g n1 0 ce_6x
xcj3d out 0 ce_6x
xcj4g in 0 cd_6x
xcj4s out 0 cd_6x
.ends

.subckt buf_fb_2x8x out in
* small devices
xj1 n1 in 0 je_2x
xj2 Vcc n1 n1 jd_2x
xcj1g in 0 ce_2x
xcj1d n1 0 ce_2x
xcj2s n1 0 cd_2x
* large devices
xj3 out n1 0 je_8x
xj4 Vcc in out jd_8x
xcj3g n1 0 ce_8x
xcj3d out 0 ce_8x
xcj4g in 0 cd_8x
xcj4s out 0 cd_8x
.ends

.subckt buf_fb_3x8x out in
* small devices
xj1 n1 in 0 je_3x
xj2 Vcc n1 n1 jd_3x
xcj1g in 0 ce_3x
xcj1d n1 0 ce_3x
xcj2s n1 0 cd_3x
* large devices
xj3 out n1 0 je_8x
xj4 Vcc in out jd_8x
xcj3g n1 0 ce_8x
xcj3d out 0 ce_8x
xcj4g in 0 cd_8x
xcj4s out 0 cd_8x
.ends

.subckt buf_fb_3x10x out in
* small devices
xj1 n1 in 0 je_3x
xj2 Vcc n1 n1 jd_3x
xcj1g in 0 ce_3x
xcj1d n1 0 ce_3x
xcj2s n1 0 cd_3x
* large devices3x
xj3 out n1 0 je_10x
xj4 Vcc in out jd_10x
xcj3g n1 0 ce_10x
xcj3d out 0 ce_10x
xcj4g in 0 cd_10x
xcj4s out 0 cd_10x
.ends

.subckt buf_fb_4x10x out in
* small devices
xj1 n1 in 0 je_4x
xj2 Vcc n1 n1 jd_4x
xcj1g in 0 ce_4x
xcj1d n1 0 ce_4x
xcj2s n1 0 cd_4x
* large devices
xj3 out n1 0 je_10x
xj4 Vcc in out jd_10x
xcj3g n1 0 ce_10x
xcj3d out 0 ce_10x
xcj4g in 0 cd_10x
xcj4s out 0 cd_10x
.ends

.subckt buf_fb_3x12x out in
* small devices
xj1 n1 in 0 je_3x
xj2 Vcc n1 n1 jd_3x
xcj1g in 0 ce_3x
xcj1d n1 0 ce_3x
xcj2s n1 0 cd_3x
* large devices
xj3 out n1 0 je_12x
xj4 Vcc in out jd_12x
xcj3g n1 0 ce_12x
xcj3d out 0 ce_12x
xcj4g in 0 cd_12x
xcj4s out 0 cd_12x
.ends

.subckt buf_fb_4x12x out in
* small devices
xj1 n1 in 0 je_4x
xj2 Vcc n1 n1 jd_4x
xcj1g in 0 ce_4x
xcj1d n1 0 ce_4x
xcj2s n1 0 cd_4x
* large devices
xj3 out n1 0 je_12x
xj4 Vcc in out jd_12x
xcj3g n1 0 ce_12x
xcj3d out 0 ce_12x
xcj4g in 0 cd_12x
xcj4s out 0 cd_12x
.ends

.subckt buf_fb_6x16x out in
* small devices
xj1 n1 in 0 je_6x
xj2 Vcc n1 n1 jd_6x
xcj1g in 0 ce_6x
xcj1d n1 0 ce_6x
xcj2s n1 0 cd_6x
* large devices
xj3 out n1 0 je_16x
xj4 Vcc in out jd_16x
xcj3g n1 0 ce_16x
xcj3d out 0 ce_16x
xcj4g in 0 cd_16x
xcj4s out 0 cd_16x
.ends

.subckt buf_fb_6x20x out in
* small devices
xj1 n1 in 0 je_6x
xj2 Vcc n1 n1 jd_6x
xcj1g in 0 ce_6x
xcj1d n1 0 ce_6x
xcj2s n1 0 cd_6x
* large devices
xj3 out n1 0 je_20x
xj4 Vcc in out jd_20x
xcj3g n1 0 ce_20x
xcj3d out 0 ce_20x
xcj4g in 0 cd_20x
xcj4s out 0 cd_20x
.ends

.subckt buf_fb_8x20x out in
* small devices
xj1 n1 in 0 je_8x
xj2 Vcc n1 n1 jd_8x
xcj1g in 0 ce_8x
xcj1d n1 0 ce_8x
xcj2s n1 0 cd_8x
* large devices
xj3 out n1 0 je_20x
xj4 Vcc in out jd_20x
xcj3g n1 0 ce_20x
xcj3d out 0 ce_20x
xcj4g in 0 cd_20x
xcj4s out 0 cd_20x
.ends

.subckt buf_fb_8x24x out in
* small devices
xj1 n1 in 0 je_8x
xj2 Vcc n1 n1 jd_8x
xcj1g in 0 ce_8x
xcj1d n1 0 ce_8x
xcj2s n1 0 cd_8x
* large devices
xj3 out n1 0 je_24x
xj4 Vcc in out jd_24x
xcj3g n1 0 ce_24x
xcj3d out 0 ce_24x
xcj4g in 0 cd_24x
xcj4s out 0 cd_24x
.ends



**************************************************************************
* 	SQUIRT BUFFERS
**************************************************************************
.subckt sb_p7x2x_core out in 1
* small devices
xj1 1 in 0 je_p7x
xj2 Vcc 1 1 jd_p7x
xd3 1 2 dio_p7x
xj3 2 out 0 je_p7x
xcj1g in 0 ce_p7x
xcj1d  1 0 ce_p7x
xcj2s 1 0 cd_p7x
xcd3g 1 0 cd_p7x
xcd3d 2 0 cd_p7x
xcj3d 2 0 ce_p7x
xcj3g out 0 ce_p7x
* large devices
xj4 Vcc 1 out jd_2x
xj5 out in 0 je_2x
xcj4g 1 0 cd_2x
xcj4s out 0 cd_2x
xcj5g in 0 ce_2x
xcj5d out 0 ce_2x
.ends

.subckt sb_1x2x_core out in 1
* small devices
xj1 1 in 0 je_1x
xj2 Vcc 1 1 jd_1x
xd3 1 2 dio_1x
xj3 2 out 0 je_1x
xcj1g in 0 ce_1x
xcj1d  1 0 ce_1x
xcj2s 1 0 cd_1x
xcd3g 1 0 cd_1x
xcd3d 2 0 cd_1x
xcj3d 2 0 ce_1x
xcj3g out 0 ce_1x
* large devices
xj4 Vcc 1 out jd_2x
xj5 out in 0 je_2x
xcj4g 1 0 cd_2x
xcj4s out 0 cd_2x
xcj5g in 0 ce_2x
xcj5d out 0 ce_2x
.ends


.subckt sb_1x3x_core out in 1
* small devices
xj1 1 in 0 je_1x
xj2 Vcc 1 1 jd_1x
xd3 1 2 dio_1x
xj3 2 out 0 je_1x
xcj1g in 0 ce_1x
xcj1d  1 0 ce_1x
xcj2s 1 0 cd_1x
xcd3g 1 0 cd_1x
xcd3d 2 0 cd_1x
xcj3d 2 0 ce_1x
xcj3g out 0 ce_1x
* large devices
xj4 Vcc 1 out jd_3x
xj5 out in 0 je_3x
xcj4g 1 0 cd_3x
xcj4s out 0 cd_3x
xcj5g in 0 ce_3x
xcj5d out 0 ce_3x
.ends

.subckt sb_1p3x4x_core out in 1
* small devices
xj1 1 in 0 je_1p3x
xj2 Vcc 1 1 jd_1p3x
xd3 1 2 dio_1p3x
xj3 2 out 0 je_1p3x
xcj1g in 0 ce_1p3x
xcj1d  1 0 ce_1p3x
xcj2s 1 0 cd_1p3x
xcd3g 1 0 cd_1p3x
xcd3d 2 0 cd_1p3x
xcj3d 2 0 ce_1p3x
xcj3g out 0 ce_1p3x
* large devices
xj4 Vcc 1 out jd_4x
xj5 out in 0 je_4x
xcj4g 1 0 cd_4x
xcj4s out 0 cd_4x
xcj5g in 0 ce_4x
xcj5d out 0 ce_4x
.ends

.subckt sb_2x4x_core out in 1
* small devices
xj1 1 in 0 je_2x
xj2 Vcc 1 1 jd_2x
xd3 1 2 dio_2x
xj3 2 out 0 je_2x
xcj1g in 0 ce_2x
xcj1d  1 0 ce_2x
xcj2s 1 0 cd_2x
xcd3g 1 0 cd_2x
xcd3d 2 0 cd_2x
xcj3d 2 0 ce_2x
xcj3g out 0 ce_2x
* large devices
xj4 Vcc 1 out jd_4x
xj5 out in 0 je_4x
xcj4g 1 0 cd_4x
xcj4s out 0 cd_4x
xcj5g in 0 ce_4x
xcj5d out 0 ce_4x
.ends

.subckt sb_2x6x_core out in 1
* small devices
xj1 1 in 0 je_2x
xj2 Vcc 1 1 jd_2x
xd3 1 2 dio_2x
xj3 2 out 0 je_2x
xcj1g in 0 ce_2x
xcj1d  1 0 ce_2x
xcj2s 1 0 cd_2x
xcd3g 1 0 cd_2x
xcd3d 2 0 cd_2x
xcj3d 2 0 ce_2x
xcj3g out 0 ce_2x
* large devices
xj4 Vcc 1 out jd_6x
xj5 out in 0 je_6x
xcj4g 1 0 cd_6x
xcj4s out 0 cd_6x
xcj5g in 0 ce_6x
xcj5d out 0 ce_6x
.ends

.subckt sb_3x6x_core out in 1
* small devices
xj1 1 in 0 je_3x
xj2 Vcc 1 1 jd_3x
xd3 1 2 dio_3x
xj3 2 out 0 je_3x
xcj1g in 0 ce_3x
xcj1d  1 0 ce_3x
xcj2s 1 0 cd_3x
xcd3g 1 0 cd_3x
xcd3d 2 0 cd_3x
xcj3d 2 0 ce_3x
xcj3g out 0 ce_3x
* large devices
xj4 Vcc 1 out jd_6x
xj5 out in 0 je_6x
xcj4g 1 0 cd_6x
xcj4s out 0 cd_6x
xcj5g in 0 ce_6x
xcj5d out 0 ce_6x
.ends

.subckt sb_3x8x_core out in 1
* small devices
xj1 1 in 0 je_3x
xj2 Vcc 1 1 jd_3x
xd3 1 2 dio_3x
xj3 2 out 0 je_3x
xcj1g in 0 ce_3x
xcj1d  1 0 ce_3x
xcj2s 1 0 cd_3x
xcd3g 1 0 cd_3x
xcd3d 2 0 cd_3x
xcj3d 2 0 ce_3x
xcj3g out 0 ce_3x
* large devices
xj4 Vcc 1 out jd_8x
xj5 out in 0 je_8x
xcj4g 1 0 cd_8x
xcj4s out 0 cd_8x
xcj5g in 0 ce_8x
xcj5d out 0 ce_8x
.ends

.subckt sb_4x10x_core out in 1
* small devices
xj1 1 in 0 je_4x
xj2 Vcc 1 1 jd_4x
xd3 1 2 dio_4x
xj3 2 out 0 je_4x
xcj1g in 0 ce_4x
xcj1d  1 0 ce_4x
xcj2s 1 0 cd_4x
xcd3g 1 0 cd_4x
xcd3d 2 0 cd_4x
xcj3d 2 0 ce_4x
xcj3g out 0 ce_4x
* large devices
xj4 Vcc 1 out jd_10x
xj5 out in 0 je_10x
xcj4g 1 0 cd_10x
xcj4s out 0 cd_10x
xcj5g in 0 ce_10x
xcj5d out 0 ce_10x
.ends

.subckt sb_4x12x_core out in 1
* small devices
xj1 1 in 0 je_4x
xj2 Vcc 1 1 jd_4x
xd3 1 2 dio_4x
xj3 2 out 0 je_4x
xcj1g in 0 ce_4x
xcj1d  1 0 ce_4x
xcj2s 1 0 cd_4x
xcd3g 1 0 cd_4x
xcd3d 2 0 cd_4x
xcj3d 2 0 ce_4x
xcj3g out 0 ce_4x
* large devices
xj4 Vcc 1 out jd_12x
xj5 out in 0 je_12x
xcj4g 1 0 cd_12x
xcj4s out 0 cd_12x
xcj5g in 0 ce_12x
xcj5d out 0 ce_12x
.ends

.subckt sb_6x16x_core out in 1
* small devices
xj1 1 in 0 je_6x
xj2 Vcc 1 1 jd_6x
xd3 1 2 dio_6x
xj3 2 out 0 je_6x
xcj1g in 0 ce_6x
xcj1d  1 0 ce_6x
xcj2s 1 0 cd_6x
xcd3g 1 0 cd_6x
xcd3d 2 0 cd_6x
xcj3d 2 0 ce_6x
xcj3g out 0 ce_6x
* large devices
xj4 Vcc 1 out jd_16x
xj5 out in 0 je_16x
xcj4g 1 0 cd_16x
xcj4s out 0 cd_16x
xcj5g in 0 ce_16x
xcj5d out 0 ce_16x
.ends

.subckt sb_6x20x_core out in 1
* small devices
xj1 1 in 0 je_6x
xj2 Vcc 1 1 jd_6x
xd3 1 2 dio_6x
xj3 2 out 0 je_6x
xcj1g in 0 ce_6x
xcj1d  1 0 ce_6x
xcj2s 1 0 cd_6x
xcd3g 1 0 cd_6x
xcd3d 2 0 cd_6x
xcj3d 2 0 ce_6x
xcj3g out 0 ce_6x
* large devices
xj4 Vcc 1 out jd_20x
xj5 out in 0 je_20x
xcj4g 1 0 cd_20x
xcj4s out 0 cd_20x
xcj5g in 0 ce_20x
xcj5d out 0 ce_20x
.ends

.subckt sb_8x24x_core out in 1
* small devices
xj1 1 in 0 je_8x
xj2 Vcc 1 1 jd_8x
xd3 1 2 dio_8x
xj3 2 out 0 je_8x
xcj1g in 0 ce_8x
xcj1d  1 0 ce_8x
xcj2s 1 0 cd_8x
xcd3g 1 0 cd_8x
xcd3d 2 0 cd_8x
xcj3d 2 0 ce_8x
xcj3g out 0 ce_8x
* large devices
xj4 Vcc 1 out jd_24x
xj5 out in 0 je_24x
xcj4g 1 0 cd_24x
xcj4s out 0 cd_24x
xcj5g in 0 ce_24x
xcj5d out 0 ce_24x
.ends

*******************************************************************
.subckt not_sb_p7x2x out in1
xsb out in1 n1 sb_p7x2x_core 
.ends

.subckt nor2_sb_p7x2x out in1 in2
xsb out in1 n1 sb_p7x2x_core 
* small devices
xj1 1 in2 0 je_p7x2x
xcj1f in2 0 ce_p7x2x
xcj2f in2 0 ce_p7x2x
xcj3f in2 0 ce_p7x2x
xcj4f 1 0 ce_p7x2x
* large devices
xj2 out in2 0 je_2x
xcj2g in2 0 ce_2x
xcj2d out 0 ce_2x
.ends

.subckt nor3_sb_p7x2x out in1 in2 in3
xsb out in1 n1 sb_p7x2x_core 
* small devices
xj1 1 in2 0 je_p7x
xj2 1 in3 0 je_p7x
xcj1g in2 0 ce_p7x
xcj1d 1 0 ce_p7x
xcj2g in3 0 ce_p7x
xcj2d 1 0 ce_p7x
* large devices
xj3 out in2 0 je_2x
xj4 out in3 0 je_2x
xcj3g in2 0 ce_2x
xcj3d out 0 ce_2x
xcj4g in3 0 ce_2x
xcj4d out 0 ce_2x
.ends

.subckt nor4_sb_p7x2x out in1 in2 in3 in4
xsb out in1 in2 in3 sb_p7x2x_core
xj1 1 in2 0 je_p7x
xj2 1 in3 0 je_p7x
xj3 1 in4 0 je_p7x
xcj1g in2 0 ce_p7x
xcj1d 1 0 ce_p7x
xcj2g in3 0 ce_p7x
xcj2d 1 0 ce_p7x
xcj3g in4 0 ce_p7x
xcj3d 1 0 ce_p7x
* large devices
xj4 out in2 0 je_2x
xj5 out in3 0 je_2x
xj6 out in4 0 je_2x
xcj4g in2 0 ce_2x
xcj4d out 0 ce_2x
xcj5g in3 0 ce_2x
xcj5d out 0 ce_2x
xcj6g in4 0 ce_2x
xcj6d out 0 ce_2x
.ends

.subckt not_sb_1x2x out in1
xsb out in1 n1 sb_1x2x_core 
.ends

.subckt nor2_sb_1x2x out in1 in2
xsb out in1 n1 sb_1x2x_core 
* small devices
xj1 1 in2 0 je_1x
xcj1g in2 0 ce_1x
xcj1d 1 0 ce_1x
* large devices
xj2 out in2 0 je_2x
xcj2g in2 0 ce_2x
xcj2d out 0 ce_2x
.ends

.subckt nor3_sb_1x2x out in1 in2 in3
xsb out in1 n1 sb_1x2x_core 
* small devices
xj1 1 in2 0 je_1x
xj2 1 in3 0 je_1x
xcj1g in2 0 ce_1x
xcj1d 1 0 ce_1x
xcj2g in3 0 ce_1x
xcj2d 1 0 ce_1x
* large devices
xj3 out in2 0 je_2x
xj4 out in3 0 je_2x
xcj3g in2 0 ce_2x
xcj3d out 0 ce_2x
xcj4g in3 0 ce_2x
xcj4d out 0 ce_2x
.ends

.subckt nor4_sb_1x2x out in1 in2 in3 in4
xsb out in1 n1 sb_1x2x_core 
xj1 1 in2 0 je_1x
xj2 1 in3 0 je_1x
xj3 1 in4 0 je_1x
xcj1g in2 0 ce_1x
xcj1d 1 0 ce_1x
xcj2g in3 0 ce_1x
xcj2d 1 0 ce_1x
xcj3g in4 0 ce_1x
xcj3d 1 0 ce_1x
* large devices
xj4 out in2 0 je_2x
xj5 out in3 0 je_2x
xj6 out in4 0 je_2x
xcj4g in2 0 ce_2x
xcj4d out 0 ce_2x
xcj5g in3 0 ce_2x
xcj5d out 0 ce_2x
xcj6g in4 0 ce_2x
xcj6d out 0 ce_2x
.ends

.subckt not_sb_1x3x out in1
xsb out in1 n1 sb_1x3x_core
.ends

.subckt nor2_sb_1x3x out in1 in2
xsb out in1 n1 sb_1x3x_core
* small devices
xj1 1 in2 0 je_1x
xcj1g in2 0 ce_1x
xcj1d 1 0 ce_1x
* large devices
xj2 out in2 0 je_3x
xcj2g in2 0 ce_3x
xcj2d out 0 ce_3x
.ends

.subckt nor3_sb_1x3x out in1 in2 in3
xsb out in1 n1 sb_1x3x_core
* small devices
xj1 1 in2 0 je_1x
xj2 1 in3 0 je_1x
xcj1g in2 0 ce_1x
xcj1d 1 0 ce_1x
xcj2g in3 0 ce_1x
xcj2d 1 0 ce_1x
* large devices
xj3 out in2 0 je_3x
xj4 out in3 0 je_3x
xcj3g in2 0 ce_3x
xcj3d out 0 ce_3x
xcj4g in3 0 ce_3x
xcj4d out 0 ce_3x
.ends

.subckt nor4_sb_1x3x out in1 in2 in3 in4
xsb out in1 n1 sb_1x3x_core
xj1 1 in2 0 je_1x
xj2 1 in3 0 je_1x
xj3 1 in4 0 je_1x
xcj1g in2 0 ce_1x
xcj1d 1 0 ce_1x
xcj2g in3 0 ce_1x
xcj2d 1 0 ce_1x
xcj3g in4 0 ce_1x
xcj3d 1 0 ce_1x
* large devices
xj4 out in2 0 je_3x
xj5 out in3 0 je_3x
xj6 out in4 0 je_3x
xcj4g in2 0 ce_3x
xcj4d out 0 ce_3x
xcj5g in3 0 ce_3x
xcj5d out 0 ce_3x
xcj6g in4 0 ce_3x
xcj6d out 0 ce_3x
.ends

.subckt not_sb_1p3x4x out in1
xsb out in1 n1 sb_1p3x4x_core 
.ends

.subckt nor2_sb_1p3x4x out in1 in2
xsb out in1 n1 sb_1p3x4x_core 
* small devices
xj1 1 in2 0 je_1p3x
xcj1g in2 0 ce_1p3x
xcj1d 1 0 ce_1p3x
* large devices
xj2 out in2 0 je_4x
xcj2g in2 0 ce_4x
xcj2d out 0 ce_4x
.ends

.subckt nor3_sb_1p3x4x out in1 in2 in3
xsb out in1 n1 sb_1p3x4x_core 
* small devices
xj1 1 in2 0 je_1p3x
xj2 1 in3 0 je_1p3x
xcj1g in2 0 ce_1p3x
xcj1d 1 0 ce_1p3x
xcj2g in3 0 ce_1p3x
xcj2d 1 0 ce_1p3x
* large devices
xj3 out in2 0 je_4x
xj4 out in3 0 je_4x
xcj3g in2 0 ce_4x
xcj3d out 0 ce_4x
xcj4g in3 0 ce_4x
xcj4d out 0 ce_4x
.ends

.subckt nor4_sb_1p3x4x out in1 in2 in3 in4
xsb out in1 n1 sb_1p3x4x_core 
xj1 1 in2 0 je_1p3x
xj2 1 in3 0 je_1p3x
xj3 1 in4 0 je_1p3x
xcj1g in2 0 ce_1p3x
xcj1d 1 0 ce_1p3x
xcj2g in3 0 ce_1p3x
xcj2d 1 0 ce_1p3x
xcj3g in4 0 ce_1p3x
xcj3d 1 0 ce_1p3x
* large devices
xj4 out in2 0 je_4x
xj5 out in3 0 je_4x
xj6 out in4 0 je_4x
xcj4g in2 0 ce_4x
xcj4d out 0 ce_4x
xcj5g in3 0 ce_4x
xcj5d out 0 ce_4x
xcj6g in4 0 ce_4x
xcj6d out 0 ce_4x
.ends

.subckt not_sb_2x4x out in1
xsb out in1 n1 sb_2x4x_core
.ends

.subckt nor2_sb_2x4x out in1 in2
xsb out in1 n1 sb_2x4x_core
* small devices
xj1 1 in2 0 je_2x
xcj1g in2 0 ce_2x
xcj1d 1 0 ce_2x
* large devices
xj2 out in2 0 je_4x
xcj2g in2 0 ce_4x
xcj2d out 0 ce_4x
.ends

.subckt nor3_sb_2x4x out in1 in2 in3
xsb out in1 n1 sb_2x4x_core
* small devices
xj1 1 in2 0 je_2x
xj2 1 in3 0 je_2x
xcj1g in2 0 ce_2x
xcj1d 1 0 ce_2x
xcj2g in3 0 ce_2x
xcj2d 1 0 ce_2x
* large devices
xj3 out in2 0 je_4x
xj4 out in3 0 je_4x
xcj3g in2 0 ce_4x
xcj3d out 0 ce_4x
xcj4g in3 0 ce_4x
xcj4d out 0 ce_4x
.ends

.subckt nor4_sb_2x4x out in1 in2 in3 in4
xsb out in1 n1 sb_2x4x_core
xj1 1 in2 0 je_2x
xj2 1 in3 0 je_2x
xj3 1 in4 0 je_2x
xcj1g in2 0 ce_2x
xcj1d 1 0 ce_2x
xcj2g in3 0 ce_2x
xcj2d 1 0 ce_2x
xcj3g in4 0 ce_2x
xcj3d 1 0 ce_2x
* large devices
xj4 out in2 0 je_4x
xj5 out in3 0 je_4x
xj6 out in4 0 je_4x
xcj4g in2 0 ce_4x
xcj4d out 0 ce_4x
xcj5g in3 0 ce_4x
xcj5d out 0 ce_4x
xcj6g in4 0 ce_4x
xcj6d out 0 ce_4x
.ends

.subckt not_sb_2x6x out in1
xsb out in1 n1 sb_2x6x_core 
.ends

.subckt nor2_sb_2x6x out in1 in2
xsb out in1 n1 sb_2x6x_core 
* small devices
xj1 1 in2 0 je_2x
xcj1g in2 0 ce_2x
xcj1d 1 0 ce_2x
* large devices
xj2 out in2 0 je_6x
xcj2g in2 0 ce_6x
xcj2d out 0 ce_6x
.ends

.subckt nor3_sb_2x6x out in1 in2 in3
xsb out in1 n1 sb_2x6x_core 
* small devices
xj1 1 in2 0 je_2x
xj2 1 in3 0 je_2x
xcj1g in2 0 ce_2x
xcj1d 1 0 ce_2x
xcj2g in3 0 ce_2x
xcj2d 1 0 ce_2x
* large devices
xj3 out in2 0 je_6x
xj4 out in3 0 je_6x
xcj3g in2 0 ce_6x
xcj3d out 0 ce_6x
xcj4g in3 0 ce_6x
xcj4d out 0 ce_6x
.ends

.subckt nor4_sb_2x6x out in1 in2 in3 in4
xsb out in1 n1 sb_2x6x_core 
xj1 1 in2 0 je_2x
xj2 1 in3 0 je_2x
xj3 1 in4 0 je_2x
xcj1g in2 0 ce_2x
xcj1d 1 0 ce_2x
xcj2g in3 0 ce_2x
xcj2d 1 0 ce_2x
xcj3g in4 0 ce_2x
xcj3d 1 0 ce_2x
* large devices
xj4 out in2 0 je_6x
xj5 out in3 0 je_6x
xj6 out in4 0 je_6x
xcj4g in2 0 ce_6x
xcj4d out 0 ce_6x
xcj5g in3 0 ce_6x
xcj5d out 0 ce_6x
xcj6g in4 0 ce_6x
xcj6d out 0 ce_6x
.ends

.subckt not_sb_3x6x out in1
xsb out in1 n1 sb_3x6x_core
.ends

.subckt nor2_sb_3x6x out in1 in2
xsb out in1 n1 sb_3x6x_core
* small devices
xj1 1 in2 0 je_3x
xcj1g in2 0 ce_3x
xcj1d 1 0 ce_3x
* large devices
xj2 out in2 0 je_6x
xcj2g in2 0 ce_6x
xcj2d out 0 ce_6x
.ends

.subckt nor3_sb_3x6x out in1 in2 in3
xsb out in1 n1 sb_3x6x_core
* small devices
xj1 1 in2 0 je_3x
xj2 1 in3 0 je_3x
xcj1g in2 0 ce_3x
xcj1d 1 0 ce_3x
xcj2g in3 0 ce_3x
xcj2d 1 0 ce_3x
* large devices
xj3 out in2 0 je_6x
xj4 out in3 0 je_6x
xcj3g in2 0 ce_6x
xcj3d out 0 ce_6x
xcj4g in3 0 ce_6x
xcj4d out 0 ce_6x
.ends

.subckt nor4_sb_3x6x out in1 in2 in3 in4
xsb out in1 n1 sb_3x6x_core
xj1 1 in2 0 je_3x
xj2 1 in3 0 je_3x
xj3 1 in4 0 je_3x
xcj1g in2 0 ce_3x
xcj1d 1 0 ce_3x
xcj2g in3 0 ce_3x
xcj2d 1 0 ce_3x
xcj3g in4 0 ce_3x
xcj3d 1 0 ce_3x
* large devices
xj4 out in2 0 je_6x
xj5 out in3 0 je_6x
xj6 out in4 0 je_6x
xcj4g in2 0 ce_6x
xcj4d out 0 ce_6x
xcj5g in3 0 ce_6x
xcj5d out 0 ce_6x
xcj6g in4 0 ce_6x
xcj6d out 0 ce_6x
.ends

.subckt not_sb_3x8x out in1
xsb out in1 n1 sb_3x8x_core 
.ends

.subckt nor2_sb_3x8x out in1 in2
xsb out in1 n1 sb_3x8x_core 
* small devices
xj1 1 in2 0 je_3x
xcj1g in2 0 ce_3x
xcj1d 1 0 ce_3x
* large devices
xj2 out in2 0 je_8x
xcj2g in2 0 ce_8x
xcj2d out 0 ce_8x
.ends

.subckt nor3_sb_3x8x out in1 in2 in3
xsb out in1 n1 sb_3x8x_core 
* small devices
xj1 1 in2 0 je_3x
xj2 1 in3 0 je_3x
xcj1g in2 0 ce_3x
xcj1d 1 0 ce_3x
xcj2g in3 0 ce_3x
xcj2d 1 0 ce_3x
* large devices
xj3 out in2 0 je_8x
xj4 out in3 0 je_8x
xcj3g in2 0 ce_8x
xcj3d out 0 ce_8x
xcj4g in3 0 ce_8x
xcj4d out 0 ce_8x
.ends

.subckt nor4_sb_3x8x out in1 in2 in3 in4
xsb out in1 n1 sb_3x8x_core 
xj1 1 in2 0 je_3x
xj2 1 in3 0 je_3x
xj3 1 in4 0 je_3x
xcj1g in2 0 ce_3x
xcj1d 1 0 ce_3x
xcj2g in3 0 ce_3x
xcj2d 1 0 ce_3x
xcj3g in4 0 ce_3x
xcj3d 1 0 ce_3x
* large devices
xj4 out in2 0 je_8x
xj5 out in3 0 je_8x
xj6 out in4 0 je_8x
xcj4g in2 0 ce_8x
xcj4d out 0 ce_8x
xcj5g in3 0 ce_8x
xcj5d out 0 ce_8x
xcj6g in4 0 ce_8x
xcj6d out 0 ce_8x
.ends

.subckt not_sb_4x10x out in1
xsb out in1 n1 sb_4x10x_core 
.ends

.subckt nor2_sb_4x10x out in1 in2
xsb out in1 n1 sb_4x10x_core 
* small devices
xj1 1 in2 0 je_4x
xcj1g in2 0 ce_4x
xcj1d 1 0 ce_4x
* large devices
xj2 out in2 0 je_10x
xcj2g in2 0 ce_10x
xcj2d out 0 ce_10x
.ends

.subckt nor3_sb_4x10x out in1 in2 in3
xsb out in1 n1 sb_4x10x_core 
* small devices
xj1 1 in2 0 je_4x
xj2 1 in3 0 je_4x
xcj1g in2 0 ce_4x
xcj1d 1 0 ce_4x
xcj2g in3 0 ce_4x
xcj2d 1 0 ce_4x
* large devices
xj3 out in2 0 je_10x
xj4 out in3 0 je_10x
xcj3g in2 0 ce_10x
xcj3d out 0 ce_10x
xcj4g in3 0 ce_10x
xcj4d out 0 ce_10x
.ends

.subckt nor4_sb_4x10x out in1 in2 in3 in4
xsb out in1 n1 sb_4x10x_core 
xj1 1 in2 0 je_4x
xj2 1 in3 0 je_4x
xj3 1 in4 0 je_4x
xcj1g in2 0 ce_4x
xcj1d 1 0 ce_4x
xcj2g in3 0 ce_4x
xcj2d 1 0 ce_4x
xcj3g in4 0 ce_4x
xcj3d 1 0 ce_4x
* large devices
xj4 out in2 0 je_10x
xj5 out in3 0 je_10x
xj6 out in4 0 je_10x
xcj4g in2 0 ce_10x
xcj4d out 0 ce_10x
xcj5g in3 0 ce_10x
xcj5d out 0 ce_10x
xcj6g in4 0 ce_10x
xcj6d out 0 ce_10x
.ends

.subckt not_sb_4x12x out in1
xsb out in1 n1 sb_4x12x_core 
.ends

.subckt nor2_sb_4x12x out in1 in2
xsb out in1 n1 sb_4x12x_core 
* small devices
xj1 1 in2 0 je_4x
xcj1g in2 0 ce_4x
xcj1d 1 0 ce_4x
* large devices
xj2 out in2 0 je_12x
xcj2g in2 0 ce_12x
xcj2d out 0 ce_12x
.ends

.subckt nor3_sb_4x12x out in1 in2 in3
xsb out in1 n1 sb_4x12x_core 
* small devices
xj1 1 in2 0 je_4x
xj2 1 in3 0 je_4x
xcj1g in2 0 ce_4x
xcj1d 1 0 ce_4x
xcj2g in3 0 ce_4x
xcj2d 1 0 ce_4x
* large devices
xj3 out in2 0 je_12x
xj4 out in3 0 je_12x
xcj3g in2 0 ce_12x
xcj3d out 0 ce_12x
xcj4g in3 0 ce_12x
xcj4d out 0 ce_12x
.ends

.subckt nor4_sb_4x12x out in1 in2 in3 in4
xsb out in1 n1 sb_4x12x_core 
xj1 1 in2 0 je_4x
xj2 1 in3 0 je_4x
xj3 1 in4 0 je_4x
xcj1g in2 0 ce_4x
xcj1d 1 0 ce_4x
xcj2g in3 0 ce_4x
xcj2d 1 0 ce_4x
xcj3g in4 0 ce_4x
xcj3d 1 0 ce_4x
* large devices
xj4 out in2 0 je_12x
xj5 out in3 0 je_12x
xj6 out in4 0 je_12x
xcj4g in2 0 ce_12x
xcj4d out 0 ce_12x
xcj5g in3 0 ce_12x
xcj5d out 0 ce_12x
xcj6g in4 0 ce_12x
xcj6d out 0 ce_12x
.ends

.subckt not_sb_6x16x out in1
xsb out in1 n1 sb_6x16x_core 
.ends

.subckt nor2_sb_6x16x out in1 in2
xsb out in1 n1 sb_6x16x_core 
* small devices
xj1 1 in2 0 je_6x
xcj1g in2 0 ce_6x
xcj1d 1 0 ce_6x
* large devices
xj2 out in2 0 je_16x
xcj2g in2 0 ce_16x
xcj2d out 0 ce_16x
.ends

.subckt nor3_sb_6x16x out in1 in2 in3
xsb out in1 n1 sb_6x16x_core 
* small devices
xj1 1 in2 0 je_6x
xj2 1 in3 0 je_6x
xcj1g in2 0 ce_6x
xcj1d 1 0 ce_6x
xcj2g in3 0 ce_6x
xcj2d 1 0 ce_6x
* large devices
xj3 out in2 0 je_16x
xj4 out in3 0 je_16x
xcj3g in2 0 ce_16x
xcj3d out 0 ce_16x
xcj4g in3 0 ce_16x
xcj4d out 0 ce_16x
.ends

.subckt nor4_sb_6x16x out in1 in2 in3 in4
xsb out in1 n1 sb_6x16x_core 
xj1 1 in2 0 je_6x
xj2 1 in3 0 je_6x
xj3 1 in4 0 je_6x
xcj1g in2 0 ce_6x
xcj1d 1 0 ce_6x
xcj2g in3 0 ce_6x
xcj2d 1 0 ce_6x
xcj3g in4 0 ce_6x
xcj3d 1 0 ce_6x
* large devices
xj4 out in2 0 je_16x
xj5 out in3 0 je_16x
xj6 out in4 0 je_16x
xcj4g in2 0 ce_16x
xcj4d out 0 ce_16x
xcj5g in3 0 ce_16x
xcj5d out 0 ce_16x
xcj6g in4 0 ce_16x
xcj6d out 0 ce_16x
.ends

.subckt not_sb_6x20x out in1
xsb out in1 n1 sb_6x20x_core 
.ends

.subckt nor2_sb_6x20x out in1 in2
xsb out in1 n1 sb_6x20x_core 
* small devices
xj1 1 in2 0 je_6x
xcj1g in2 0 ce_6x
xcj1d 1 0 ce_6x
* large devices
xj2 out in2 0 je_20x
xcj2g in2 0 ce_20x
xcj2d out 0 ce_20x
.ends

.subckt nor3_sb_6x20x out in1 in2 in3
xsb out in1 n1 sb_6x20x_core 
* small devices
xj1 1 in2 0 je_6x
xj2 1 in3 0 je_6x
xcj1g in2 0 ce_6x
xcj1d 1 0 ce_6x
xcj2g in3 0 ce_6x
xcj2d 1 0 ce_6x
* large devices
xj3 out in2 0 je_20x
xj4 out in3 0 je_20x
xcj3g in2 0 ce_20x
xcj3d out 0 ce_20x
xcj4g in3 0 ce_20x
xcj4d out 0 ce_20x
.ends

.subckt nor4_sb_6x20x out in1 in2 in3 in4
xsb out in1 n1 sb_6x20x_core 
xj1 1 in2 0 je_6x
xj2 1 in3 0 je_6x
xj3 1 in4 0 je_6x
xcj1g in2 0 ce_6x
xcj1d 1 0 ce_6x
xcj2g in3 0 ce_6x
xcj2d 1 0 ce_6x
xcj3g in4 0 ce_6x
xcj3d 1 0 ce_6x
* large devices
xj4 out in2 0 je_20x
xj5 out in3 0 je_20x
xj6 out in4 0 je_20x
xcj4g in2 0 ce_20x
xcj4d out 0 ce_20x
xcj5g in3 0 ce_20x
xcj5d out 0 ce_20x
xcj6g in4 0 ce_20x
xcj6d out 0 ce_20x
.ends

.subckt not_sb_8x24x out in1
xsb out in1 n1 sb_8x24x_core 
.ends

.subckt nor2_sb_8x24x out in1 in2
xsb out in1 n1 sb_8x24x_core 
* small devices
xj1 1 in2 0 je_8x
xcj1g in2 0 ce_8x
xcj1d 1 0 ce_8x
* large devices
xj2 out in2 0 je_24x
xcj2g in2 0 ce_24x
xcj2d out 0 ce_24x
.ends

.subckt nor3_sb_8x24x out in1 in2 in3
xsb out in1 n1 sb_8x24x_core 
* small devices
xj1 1 in2 0 je_8x
xj2 1 in3 0 je_8x
xcj1g in2 0 ce_8x
xcj1d 1 0 ce_8x
xcj2g in3 0 ce_8x
xcj2d 1 0 ce_8x
* large devices
xj3 out in2 0 je_24x
xj4 out in3 0 je_24x
xcj3g in2 0 ce_24x
xcj3d out 0 ce_24x
xcj4g in3 0 ce_24x
xcj4d out 0 ce_24x
.ends

.subckt nor4_sb_8x24x out in1 in2 in3 in4
xsb out in1 n1 sb_8x24x_core 
xj1 1 in2 0 je_8x
xj2 1 in3 0 je_8x
xj3 1 in4 0 je_8x
xcj1g in2 0 ce_8x
xcj1d 1 0 ce_8x
xcj2g in3 0 ce_8x
xcj2d 1 0 ce_8x
xcj3g in4 0 ce_8x
xcj3d 1 0 ce_8x
* large devices
xj4 out in2 0 je_24x
xj5 out in3 0 je_24x
xj6 out in4 0 je_24x
xcj4g in2 0 ce_24x
xcj4d out 0 ce_24x
xcj5g in3 0 ce_24x
xcj5d out 0 ce_24x
xcj6g in4 0 ce_24x
xcj6d out 0 ce_24x
.ends


********************************************************
*	SCCS ID: %W% %G%
*************************************************************
*	Leaf cells for fp path
*************************************************************
*	Leaf Cells:
*           ffce_1x
*           ffce_3x
*
*	    mux21_p5x
*	    mux21_1x
*	    mux21_2x
*	    mux21_4x
*	    mux31_p5x
*	    mux31_1x
*	    mux31_2x
*	    mux31_4x
*	    mux41_p5x
*	    mux41_1x
*	    mux41_2x
*	    mux41_4x
*
*	    not_sb_2x
*	    not_sb_3x
*	    not_sb_4x
*	    not_sb_6x
*	    not_sb_8x
*	    not_sb_10x
*	    not_sb_12x
*
**************************************************************************
*       Flip Flops
**************************************************************************

.subckt ffce_1x q s0 s1 s2 si clk d
x1 7 d s0 10 nor3_p5x
x2 8 si s1 10 nor3_p5x
x3 9 s2 q 10 nor3_p5x
x4 12 7 8 9 11 nor4_p7x
X5 11 13 12 nor2_1X
X6 q 11 14 nor2_1x
x7 14 q clk nor2_1x
x8 13 clk not_1x
x9 10 13 not_1x
.ends ffce_1x

.subckt ffce_3x q qbuf s0 s1 s2 si clk d
x1 7 d s0 10  nor3_1x
x2 8 si s1 10  nor3_1x
x3 9 s2 q 10  nor3_1x
x4 12 7 8 9 11  nor4_1p3x
x5 11 13 12  nor2_3x
x6 q 11 14 nor2_1p3x
x7 14 q clk nor2_2x
x10 qbuf 11 14 nor2_3x
x8 13 clk not_2x
x9 10 13 not_1x
.ends ffce_3x

**************************************************************************
* 	SQUIRT BUFFERS
**************************************************************************

.subckt not_sb_2x out in 
xj1 1 in 0  je_1x
xj2 Vcc 1 1   jd_1x
xd3 1 2 dio_1x
xj3 2  out 0 je_1x
xj4 Vcc 1  out jd_2x
xj5 out in 0 je_2x
xcin1 in 0 ce_1x
xcin2 in 0 ce_2x
xc1d1 1 0 cd_1x M=2
xc1d2 1 0 cd_2x
xc1e  1 0 ce_1x
xc2d  2 0 cd_1x
xc2e  2 0 ce_1x
xcoutd  out 0 cd_2x
xcoute1 out 0 ce_1x
xcoute2 out 0 ce_2x
.ends

.subckt not_sb_3x out in 
xj1 1 in 0 je_1x
xj2 Vcc 1 1  jd_1x
xd3 1 2 dio_1x
xj3 2 out 0  je_1x 
xj4 Vcc 1 out  jd_3x
xj5 out in 0 je_3x
xcin1 in 0 ce_1x
xcin2 in 0 ce_3x
xc1d1 1 0 cd_1x M=2
xc1d2 1 0 cd_3x
xc1e  1 0 ce_1x
xc2d  2 0 cd_1x
xc2e  2 0 ce_1x
xcoutd  out 0 cd_3x
xcoute1 out 0 ce_1x
xcoute2 out 0 ce_2x
.ends

.subckt not_sb_4x out in 
xj1 1 in 0 je_2x
xj2 Vcc 1 1  jd_2x
xd3 1 2 dio_2x
xj3 2 out 0  je_2x 
xj4 Vcc 1 out  jd_4x
xj5 out in 0 je_4x
xcin1 in 0 ce_2x
xcin2 in 0 ce_4x
xc1d1 1 0 cd_2x M=2
xc1d2 1 0 cd_4x
xc1e  1 0 ce_2x
xc2d  2 0 cd_2x
xc2e  2 0 ce_2x
xcoutd  out 0 cd_4x
xcoute1 out 0 ce_2x
xcoute2 out 0 ce_4x
.ends

.subckt not_sb_6x out in 
xj1 1 in 0 je_3x
xj2 Vcc 1 1  jd_3x
xd3 1 2 dio_3x
xj3 2 out 0  je_3x 
xj4 Vcc 1 out  jd_6x
xj5 out in 0 je_6x
xcin1 in 0 ce_3x
xcin2 in 0 ce_6x
xc1d1 1 0 cd_3x M=2
xc1d2 1 0 cd_6x
xc1e  1 0 ce_3x
xc2d  2 0 cd_3x
xc2e  2 0 ce_3x
xcoutd  out 0 cd_6x
xcoute1 out 0 ce_3x
xcoute2 out 0 ce_6x
.ends

.subckt not_sb_8x out in 
xj1 1 in 0 je_4x
xj2 Vcc 1 1  jd_4x
xd3 1 2 dio_4x
xj3 2 out 0  je_4x
xj4 Vcc 1 out  jd_8x
xj5 out in 0 je_8x
xcin1 in 0 ce_4x
xcin2 in 0 ce_8x
xc1d1 1 0 cd_4x M=2
xc1d2 1 0 cd_8x
xc1e  1 0 ce_4x
xc2d  2 0 cd_4x
xc2e  2 0 ce_4x
xcoutd  out 0 cd_8x
xcoute1 out 0 ce_4x
xcoute2 out 0 ce_8x
.ends

.subckt not_sb_10x out in 
xj1 1 in 0 je_4x
xj2 Vcc 1 1  jd_4x
xd3 1 2 dio_4x
xj3 2 out 0  je_4x
xj4 Vcc 1 out  jd_10x
xj5 out in 0 je_10x
xcin1 in 0 ce_4x
xcin2 in 0 ce_10x
xc1d1 1 0 cd_4x M=2
xc1d2 1 0 cd_10x
xc1e  1 0 ce_4x
xc2d  2 0 cd_4x
xc2e  2 0 ce_4x
xcoutd  out 0 cd_10x
xcoute1 out 0 ce_4x
xcoute2 out 0 ce_10x
.ends

.subckt not_sb_12x out in 
xj1 1 in 0 je_4x
xj2 Vcc 1 1  jd_4x
xd3 1 2 dio_4x
xj3 2 out 0  je_4x
xj4 Vcc 1 out  jd_12x
xj5 Vcc out in je_12x
xcin1 in 0 ce_4x
xcin2 in 0 ce_12x
xc1d1 1 0 cd_4x M=2
xc1d2 1 0 cd_12x
xc1e  1 0 ce_4x
xc2d  2 0 cd_4x
xc2e  2 0 ce_4x
xcoutd  out 0 cd_12x
xcoute1 out 0 ce_4x
xcoute2 out 0 ce_12x
.ends

*****************************************************************************
*	MUXES
*****************************************************************************

.subckt mux21_p5x out in1 in2 sel1 sel2
x1 n1 in1 sel1 nor2_p5x
x2 n2 in2 sel2 nor2_p5x
x3 out n1 n2 nor2_p5x
.ends

.subckt mux21_1x out in1 in2 sel1 sel2
x1 n1 in1 sel1 nor2_p5x
x2 n2 in2 sel2 nor2_p5x
x3 out n1 n2 nor2_1x
.ends

.subckt mux21_2x out in1 in2 sel1 sel2
x1 n1 in1 sel1 nor2_p7x
x2 n2 in2 sel2 nor2_p7x
x3 out n1 n2 nor2_2x
.ends

.subckt mux21_4x out in1 in2 sel1 sel2
x1 n1 in1 sel1 nor2_1p3x
x2 n2 in2 sel2 nor2_1p3x
x3 out n1 n2 nor2_4x
.ends


.subckt mux31_p5x out in1 in2 in3 sel1 sel2 sel3
x1 n1 in1 sel1 nor2_p5x
x2 n2 in2 sel2 nor2_p5x
x3 n3 in3 sel3 nor2_p5x
x4 out n1 n2 n3 nor3_p5x
.ends

.subckt mux31_1x out in1 in2 in3 sel1 sel2 sel3
x1 n1 in1 sel1 nor2_p5x
x2 n2 in2 sel2 nor2_p5x
x3 n3 in3 sel3 nor2_p5x
x4 out n1 n2 n3 nor3_1x
.ends

.subckt mux31_2x out in1 in2 in3 sel1 sel2 sel3
x1 n1 in1 sel1 nor2_p7x
x2 n2 in2 sel2 nor2_p7x
x3 n3 in3 sel3 nor2_p7x
x4 out n1 n2 n3 nor3_2x
.ends

.subckt mux31_4x out in1 in2 in3 sel1 sel2 sel3
x1 n1 in1 sel1 nor2_1p3x
x2 n2 in2 sel2 nor2_1p3x
x3 n3 in3 sel3 nor2_1p3x
x4 out n1 n2 n3 nor3_4x
.ends


.subckt mux41_p5x out in1 in2 in3 in4 sel1 sel2 sel3 sel4
x1 n1 in1 sel1 nor2_p5x
x2 n2 in2 sel2 nor2_p5x
x3 n3 in3 sel3 nor2_p5x
x4 n4 in4 sel4 nor2_p5x
x5 out n1 n2 n3 n4 nor4_p5x
.ends

.subckt mux41_1x out in1 in2 in3 in4 sel1 sel2 sel3 sel4
x1 n1 in1 sel1 nor2_p5x
x2 n2 in2 sel2 nor2_p5x
x3 n3 in3 sel3 nor2_p5x
x4 n4 in4 sel4 nor2_p5x
x5 out n1 n2 n3 n4 nor4_1x
.ends

.subckt mux41_2x out in1 in2 in3 in4 sel1 sel2 sel3 sel4
x1 n1 in1 sel1 nor2_p7x
x2 n2 in2 sel2 nor2_p7x
x3 n3 in3 sel3 nor2_p7x
x4 n4 in4 sel4 nor2_p7x
x5 out n1 n2 n3 n4 nor4_2x
.ends

.subckt mux41_4x out in1 in2 in3 in4 sel1 sel2 sel3 sel4
x1 n1 in1 sel1 nor2_1p3x
x2 n2 in2 sel2 nor2_1p3x
x3 n3 in3 sel3 nor2_1p3x
x4 n4 in4 sel4 nor2_1p3x
x5 out n1 n2 n3 n4 nor4_4x
.ends
*
.subckt xnor2_1x out in1 in2
x1 n1 in1 in2 nor2_1x
x2 n2 in1 n1  nor2_1x
x3 n3 in2 n1  nor2_1x
x4 out n2 n3  nor2_1x
.ends

*
.subckt xnor2_1p3x out in1 in2
x1 n1 in1 in2 nor2_1x
x2 n2 in1 n1  nor2_1x
x3 n3 in2 n1  nor2_1x
x4 out n2 n3  nor2_1p3x
.ends

*
.subckt xnor2_2x out in1 in2
x1 n1 in1 in2 nor2_1x
x2 n2 in1 n1  nor2_1x
x3 n3 in2 n1  nor2_1x
x4 out n2 n3  nor2_2x
.ends

.subckt xnor4_1x out in1 in2 in3 in4
x1  n1 in1 in2 nor2_1x
x2  n2 in1 n1  nor2_1x
x3  n3 in2 n1  nor2_1x
x4  n4 in3 in4 nor2_1x
x5  n5 in3 n4  nor2_1x
x6  n6 in4 n4  nor2_1x
x7  n7 n2 n3 n5 n6 nor4_1x
x8  n8 n2 n3 n7 nor3_1x
x9  n9 n7 n5 n6 nor3_1x
x10 out n8 n9 nor2_1x
.ends

.subckt xnor4_2x out in1 in2 in3 in4
x1  n1 in1 in2 nor2_1x
x2  n2 in1 n1  nor2_1x
x3  n3 in2 n1  nor2_1x
x4  n4 in3 in4 nor2_1x
x5  n5 in3 n4  nor2_1x
x6  n6 in4 n4  nor2_1x
x7  n7 n2 n3 n5 n6 nor4_1x
x8  n8 n2 n3 n7 nor3_1x
x9  n9 n7 n5 n6 nor3_1x
x10 out n8 n9 nor2_2x
.ends

.subckt buf_1x out in
x1 n1  in not_1x
x2 out n1 not_1x
.ends
************************************************************************
*	Pinlist
************************************************************************
xnor4 out[0] in1 in2 in3 in4 xnor4_1x

xnor2_1 n1 in1 in2 xnor2_1x
xnor2_2 n2 in3 in4 xnor2_1x
xnor2_3 out1 n1 n2 xnor2_1x

************************************************************************
*	Drivers
************************************************************************
xbuf1 in1 x1 buf_1x
xbuf2 in2 x2 buf_1x
xbuf3 in3 x3 buf_1x
xbuf4 in4 x4 buf_1x

************************************************************************
*	Inputs
************************************************************************
Vx1     x1  0  PULSE(0.6 0.0 200P 100P 100P 2000P 4000P)
Vx2     x2  0  PULSE(0.0 0.0 200P 100P 100P 2000P 4000P)
Vx3     x3  0  PULSE(0.6 0.6 200P 100P 100P 2000P 4000P)
Vx4     x4  0  PULSE(0.0 0.0 200P 100P 100P 2000P 4000P)

************************************************************************
*	Loads
************************************************************************
xload out[0] load_1x 
xload1 out1 load_1x 

************************************************************************
*	Commands
************************************************************************
.trans 20p 5n
.print tran v(x1) v(in1) v(out[0]) v(out1)
.print tran I(vcc)

************************************************************************
.end
