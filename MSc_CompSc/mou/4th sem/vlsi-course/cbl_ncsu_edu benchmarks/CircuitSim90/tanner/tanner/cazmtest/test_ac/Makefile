# standard names for the source directory and its subdirectories
CAZM	= /../moe/sim/cazm4.1_3100/src/cazm/cazm
SPICE	= spice2g6
SPICE3	= spice3


#############################################################################

all:	CAZMFILES 


SPICEFILES:	bjtbase_sp bjtcollector_sp bjtemitter_sp bjtsubstrate_sp \
 		mosbulk_sp mosdrain_sp mosgate_sp mossource_sp \
		dio_sp dioforward_sp \
		jfet_sp c741_sp \
 		xlineac_sp \
 		current_sp capimag_sp indimag_sp cap_sp \
		reg0_rawsp \
		bug28_sp bug29_sp

CAZMFILES:	bjtbase_cz2 bjtcollector_cz2 bjtemitter_cz2 bjtsubstrate_cz2 \
 		mosbulk_cz2 mosdrain_cz2 mosgate_cz2 mossource_cz2 \
		dio_cz2 dioforward_cz2 \
		jfet_cz2 c741_cz2 xlineac_cz2 \
		current_cz2 currcap_cz2 capimag_cz2 indimag_cz2 cap_cz2 \
		volt_cz2 voltfa_cz21 \
		lin_cz2 dec_cz2 oct_cz2 \
		rlc_cz2 diffpair_cz2 mes_cz2 \
		kwf1_cz2 \
		hwang_cz2 \
		reg0_raw \
		bug28_cz2 bug29_cz2 \
		op702_cz2 \
		op2_cz2 \
		opac_cz2 

bjtbase_sp: bjtbase.sp
	${SPICE} < bjtbase.sp > bjtbase_sp
bjtemitter_sp: bjtemitter.sp
	${SPICE} < bjtemitter.sp > bjtemitter_sp
bjtcollector_sp: bjtcollector.sp
	${SPICE} < bjtcollector.sp > bjtcollector_sp
bjtsubstrate_sp: bjtsubstrate.sp
	${SPICE} < bjtsubstrate.sp > bjtsubstrate_sp

mosbulk_sp: mosbulk.sp
	${SPICE} < mosbulk.sp > mosbulk_sp
mosdrain_sp: mosdrain.sp
	${SPICE} < mosdrain.sp > mosdrain_sp
mosgate_sp: mosgate.sp
	${SPICE} < mosgate.sp > mosgate_sp
mossource_sp: mossource.sp
	${SPICE} < mossource.sp > mossource_sp

bjtbase_cz2: bjtbase.cmd bjtbase.fa
	${CAZM} -o  bjtbase_cz2  bjtbase
bjtemitter_cz2: bjtemitter.cmd bjtemitter.fa
	${CAZM} -o  bjtemitter_cz2  bjtemitter
bjtcollector_cz2: bjtcollector.cmd bjtcollector.fa
	${CAZM} -o  bjtcollector_cz2  bjtcollector
bjtsubstrate_cz2: bjtsubstrate.cmd bjtsubstrate.fa
	${CAZM} -o  bjtsubstrate_cz2  bjtsubstrate

mosbulk_cz2: mosbulk.cmd mosbulk.fa
	${CAZM} -o  mosbulk_cz2  mosbulk
mosgate_cz2: mosgate.cmd mosgate.fa
	${CAZM} -o  mosgate_cz2  mosgate
mosdrain_cz2: mosdrain.cmd mosdrain.fa
	${CAZM} -o  mosdrain_cz2  mosdrain
mossource_cz2: mossource.cmd mossource.fa
	${CAZM} -o  mossource_cz2  mossource

jfet_cz2: jfet.cmd jfet.fa
	${CAZM} -o  jfet_cz2  jfet
jfet_sp: jfet.sp
	${SPICE} < jfet.sp > jfet_sp

c741_cz2: c741.cmd c741.fa M125CN.Apr89
	${CAZM} -o  c741_cz2 -m M125CN.Apr89 -M c741
c741_sp: c741.sp
	${SPICE} < c741.sp > c741_sp

dio_cz2: dio.cmd dio.fa
	${CAZM} -o  dio_cz2  dio
dioforward_cz2: dioforward.cmd dioforward.fa
	${CAZM} -o  dioforward_cz2  dioforward
dio_sp: dio.sp
	${SPICE} < dio.sp > dio_sp
dioforward_sp: dioforward.sp
	${SPICE} < dioforward.sp > dioforward_sp

xlineac_cz2: xlineac.cmd xlineac.fa
	${CAZM} -o  xlineac_cz2  xlineac
xlineac_sp: xlineac.sp
	${SPICE} < xlineac.sp > xlineac_sp

currcap_cz2: currcap.cmd currcap.fa
	${CAZM} -o  currcap_cz2  currcap

current_cz2: current.cmd current.fa
	${CAZM} -o  current_cz2  current
current_sp: current.sp 
	${SPICE} <  current.sp > current_sp 

capimag_cz2: capimag.cmd capimag.fa
	${CAZM} -o  capimag_cz2  capimag
capimag_sp: capimag.sp 
	${SPICE} <  capimag.sp > capimag_sp 
indimag_cz2: indimag.cmd indimag.fa
	${CAZM} -o  indimag_cz2  indimag
indimag_sp: indimag.sp 
	${SPICE} <  indimag.sp > indimag_sp 

voltraw_cz2: voltraw.cmd voltraw.fa
	${CAZM} -r voltraw

cap_cz2: cap.cmd cap.fa
	${CAZM} -o  cap_cz2  cap
cap_sp: cap.sp 
	${SPICE} <  cap.sp > cap_sp 

volt_cz2: volt.cmd volt.fa
	${CAZM}  volt
voltfa_cz21: voltfa.cmd voltfa.fa
	${CAZM}  voltfa

lin_cz2: lin.cmd lin.fa
	${CAZM} -o lin_cz2  lin
dec_cz2: dec.cmd dec.fa
	${CAZM} -o dec_cz2 dec
oct_cz2: oct.cmd oct.fa
	${CAZM} -o oct_cz2 oct

rlc_cz2: rlc.cmd rlc.fa
	${CAZM}  -o rlc_cz2 rlc
diffpair_cz2: diffpair.cmd diffpair.fa
	${CAZM}  -o diffpair_cz2 -M  diffpair
mes_cz2: mes.cmd mes.fa
	${CAZM}  -o mes_cz2 mes
hwang_cz2: hwang.cmd hwang.fa
	${CAZM}  -o hwang_cz2 hwang
kwf1_cz2: kwf1.cmd kwf1.fa
	${CAZM}  -o kwf1_cz2 kwf1

bug28_cz2: bug28.cmd bug28.fa
	${CAZM} -o bug28_cz2 bug28
bug28_sp: bug28.sp 
	${SPICE} <  bug28.sp > bug28_sp 

bug29_cz2: bug29.cmd bug29.fa
	${CAZM} -o bug29_cz2 bug29
bug29_sp: bug29.sp 
	${SPICE} <  bug29.sp > bug29_sp 

op702_cz2: op702.cmd op702.fa
	${CAZM}  -o op702_cz2 op702
op2_cz2: op2.cmd op2.fa
	${CAZM}  -o op2_cz2 op2
opac_cz2: opac.cmd opac.fa
	${CAZM}  -o opac_cz2 opac

reg0_cz:    reg0.cmd reg0.fa 
	${CAZM} -o reg0_cz reg0
reg0_raw:    reg0.cmd reg0.fa 
	${CAZM} -r -o reg0_raw reg0
reg0_rawsp:   reg0.sp
	${SPICE3} -r < reg0.sp
	mv rawspice reg0_rawsp
	 
	


clean:
	rm -rf *_cz2* *.DC *.conn *_sp
