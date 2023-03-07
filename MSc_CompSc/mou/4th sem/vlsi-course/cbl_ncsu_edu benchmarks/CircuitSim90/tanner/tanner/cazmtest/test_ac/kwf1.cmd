
*The following file causes the ac model parameters to be confused.
*It contains many identical fets which share all nodes.  For example,
*m5a through m5h should all have identical model parameters.  Likewise,
*any fets with the same number are in parallel.  Errors in VDSAT and VTH
*are particularly noticable.  Run using -M.  Also, CAZM happens to find
*the wrong operating point for this circuit.  That may be related to
*the model problem, or maybe i just don't have the tolerances low enough.
*Anyway, I thought I would mention it.
*
*Good luck!
*
options reltol=1e-9 abstol=1e-11
dcoppt
plot {vdc(2) vdc(3) vdc(4) vdc(5) vdc(6) vdc(7) vdc(8) vdc(9) vdc(10) vdc(11) vdc(12) vdc(13) vdc(14) vdc(15)}
ac dec 10 0.1 10meg
acmodel {*}
plot {vdb(11) vp(11)}
