plot { vtx(99) vtx(41) vtx(42) vtx(51) vtx(52) vtx(61) vtx(62)}
*.dc VCC 0.0 10.0 .01 
*volt vdd 0 5.0 label=vdd
volt 99 0 1.0 label=VCC
*transfer {vdd 5.0 5.0 99 1.0 12.0 .01}
transfer {VCC 1.0 12.0 .01}
dcoppt
plot { vdc(99) vdc(41) vdc(42) vdc(51) vdc(52) vdc(61) vdc(62)}

