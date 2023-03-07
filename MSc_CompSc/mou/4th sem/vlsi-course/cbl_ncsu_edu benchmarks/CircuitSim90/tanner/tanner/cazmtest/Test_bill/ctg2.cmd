
*dcell.test.cmd
*------------------------------------------------------------------------
volt Vdd 5

volt Vb 0.6
volt Vg 0.6
volt Vr 4.2
*
*	Label your voltage supplies.
*

volt photoa 3.5
volt photob 3.5
volt nea 3.0
volt wa 3.0
volt ea 3.0
volt swa 3.0
volt sea 3.0

volt neb 3.0
volt nwb 3.0
volt wb 3.0
volt swb 3.0
volt seb 3.0



transient 50ns

plot {Vr photoa photob rneta rnetb  ea neb nea wa nwb wb}
