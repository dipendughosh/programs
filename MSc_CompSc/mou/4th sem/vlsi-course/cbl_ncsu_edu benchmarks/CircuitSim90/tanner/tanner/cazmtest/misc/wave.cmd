vector  xmb                     {xmb7 xmb6 xmb5 xmb4 xmb3 xmb2 xmb1 xmb0}
wave    xmb     bus     {
10(00h)
4(f0h)
4(0fh)
4(ffh)
12(0fh)
}         pw=20n   off=0.0 on=5.0 rt=2.0n ft=2.0n delay=0.0n

transient 820n

plot { xmb7 xmb6 xmb5 xmb4 xmb3 xmb2 xmb1 xmb0 } 
