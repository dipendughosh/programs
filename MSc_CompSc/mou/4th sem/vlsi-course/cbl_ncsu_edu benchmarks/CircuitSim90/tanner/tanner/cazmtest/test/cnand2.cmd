wave inputa bit {000111} pw=20n rt=3.0ns ft=3.0ns
wave inputb bit {010101} pw=20n rt=3.0ns ft=3.0ns
options format=4
power
plot {inputb inputa s1 out}
transient 100n .5ns
