
CAZM	=/sim/cazm4.1_3100/src/cazm/cazm
#CAZM	=/sim/cazm5.0/src/cazm/cazm
#CAZM	=/sim1/cazm5.0.debug/src/cazm/cazm

CZ	=cz
#CZ	=cz2
#CZ	=cz3

CTA	=.cta3

#
#	Current sources
#

OUTPUTS = ampbjt_${CZ} ampjfet_${CZ} ampbjt_${CZ} \
	ampmosgrid_${CZ} diores_${CZ} diomult_${CZ} \
	diorect_${CZ} diorectfloat_${CZ} ecl_${CZ}\
	eclinv_${CZ} pass_${CZ} tank_${CZ} dupont_${CZ} a32_${CZ} \
	inv_${CZ} invtab_${CZ} minvt_${CZ} minvtabt_${CZ} \
	inv1${CTA} inv1tab${CTA} minvtab${CTA} \
	xline_${CZ} xline2_${CZ} xline3_${CZ} xline4_${CZ} \
	hwang_${CZ} \
	eqcv_${CZ} eqcc_${CZ} 

all:	${OUTPUTS}

	@echo done!

ampbjt_${CZ}:	ampbjt.cmd ampbjt.fa
	 ${CAZM} -o ampbjt_${CZ} ampbjt

ampjfet_${CZ}: ampjfet.cmd ampjfet.fa
	 ${CAZM} -o ampjfet_${CZ} ampjfet

ampmos_${CZ}: ampmos.cmd ampmos.fa
	 ${CAZM} -o ampmos_${CZ} ampmos

ampmosgrid_${CZ}: ampmosgrid.cmd ampmosgrid.fa
	 ${CAZM} -o ampmosgrid_${CZ} ampmosgrid

diores_${CZ}: diores.cmd diores.fa
	 ${CAZM} -o diores_${CZ} diores

diomult_${CZ}: diomult.cmd diomult.fa
	 ${CAZM} -o diomult_${CZ} diomult

diorect_${CZ}: diorect.cmd diorect.fa
	 ${CAZM} -o diorect_${CZ} diorect

diorectfloat_${CZ}: diorectfloat.cmd diorectfloat.fa
	 ${CAZM} -o diorectfloat_${CZ} diorectfloat

eclinv_${CZ}: eclinv.cmd eclinv.fa
	 ${CAZM} -o eclinv_${CZ} eclinv

ecl_${CZ}: ecl.cmd ecl.fa
	 ${CAZM} -o ecl_${CZ} ecl

pass_${CZ}: pass.cmd pass.fa
	 ${CAZM} -o pass_${CZ} pass

tank_${CZ}: tank.cmd tank.fa
	 ${CAZM} -o tank_${CZ} tank

dupont_${CZ}: dupont.cmd dupont.fa
	 ${CAZM} -o dupont_${CZ} dupont

a32_${CZ}: a32.cmd a32.fa
	 ${CAZM} -o a32_${CZ} a32

hwang_${CZ}: hwang.cmd hwang.fa
	 ${CAZM} -o hwang_${CZ} hwang

kwf_${CZ}: kwf.cmd kwf.fa
	 ${CAZM} -o kwf_${CZ} kwf

eqcv_${CZ}: eqcv.cmd eqcv.fa
	 ${CAZM} -o eqcv_${CZ} eqcv

eqcc_${CZ}: eqcc.cmd eqcc.fa
	 ${CAZM} -o eqcc_${CZ} eqcc

#
#	Inverters and Invertor Tables
#
inv_${CZ}: inv.cmd inv.fa
	 ${CAZM}  -o inv_${CZ} -m M125CN.md inv

invtab_${CZ}: invtab.cmd invtab.fa
	 ${CAZM}  -o invtab_${CZ} invtab

minvt_${CZ}: minvt.cmd minvt.fa
	 ${CAZM}  -o minvt_${CZ} minvt

minvtabt_${CZ}: minvtabt.cmd minvtabt.fa
	 ${CAZM}  -o minvtabt_${CZ} minvtabt

inv1${CTA}: inv1.cmd inv1.fa
	 ${CAZM}  -o inv1${CTA} -m M125CN.md inv1

inv1tab${CTA}: inv1tab.cmd inv1tab.fa
	 ${CAZM}  -o inv1tab${CTA} inv1tab

minvtab${CTA}: minvtab.cmd minvtab.fa
	 ${CAZM}  -o minvtab${CTA} minvtab


#
#	Transmission lines 
#
xline_${CZ}: xline.cmd xline.fa
	${CAZM}  -o xline_${CZ} xline

xline2_${CZ}: xline2.cmd xline2.fa
	${CAZM}  -o xline2_${CZ} xline2

xline3_${CZ}: xline3.cmd xline3.fa
	${CAZM}  -o xline3_${CZ} xline3

xline4_${CZ}: xline4.cmd xline4.fa
	${CAZM}  -o xline4_${CZ} xline4


clean:
	rm -rf ${OUTPUTS} *.conn

