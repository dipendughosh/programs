wave vd 0 sin amp=2.0 freq=3M offset=2.5 delay=0 label=VDD
transfer {VDD -5.0 5.0 0.1 VGG -5.0 5.0 0.5 }
plot { vtx(vd,GND) vtx(vg,GND) itx(VSS,vs)}


