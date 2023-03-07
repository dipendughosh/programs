* Project TRY1
* WorkVIEW Wirelist Created with Version 4.1

wave     N20 N22 sin amp=1.0 freq=300000
wave     N6  N8  sin amp=100.0 freq=60

transient 1e-3

plot {v(N6,N8) v(N20,N22) v(N56,N57) v(N27,0)}
