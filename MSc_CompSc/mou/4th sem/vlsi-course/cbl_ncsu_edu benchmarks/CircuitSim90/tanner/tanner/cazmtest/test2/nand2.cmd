
wave inputa bit {000111} pw=20n rt=3.0ns ft=3.0ns
wave inputb bit {010101} pw=20n rt=3.0ns ft=3.0ns
plot {inputb inputa in out}
transient 100n
