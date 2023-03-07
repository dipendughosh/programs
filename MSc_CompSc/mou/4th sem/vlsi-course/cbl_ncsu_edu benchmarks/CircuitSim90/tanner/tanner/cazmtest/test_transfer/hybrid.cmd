plot { vtx(50) vtx(7) vtx(4)}
*.dc vcc 0.0 5.0 .01 
*transfer {vss 0.0 0.0 50 0.0 5.0 .01}
volt 50 0 0.0 label=VCC
transfer {VCC 0.0 5.0 .01}


