wave inputa bit {000111} pw=20n on=5.0
wave inputb bit {01} pw=20n on=5.0 rt=2.0n ft=1.0n
plot {inputb inputa s1 out}
transient 100n {s1 =0.0}
