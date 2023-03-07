volt 1 5.0
volt Vref 4.5 acmag=1 acphase=0
ac DEC 10 10 100MEG
acmodel { * }
* plot acvm {vm(9,0) vm(11,0) vm(10,0) vm(12,0) im(mt3,0)}
* plot acvdb {vdb(11,0) vdb(10,0) vdb(12,0) idb(mt3,0)}
plot {vdb(13,0) vdb(5,0) vdb(6,0) }
plot {vp(13,0) vp(5,0) vp(6,0) }
* plot acvp {vp(11,0) vp(10,0) vp(12,0) ip(mt3,0)}
*
*
* DC operating point analysis
*
