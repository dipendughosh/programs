* dfuz1.cmd
*

temp 75
volt Vdd 3

vector in {TreeOutE3S1H TreeOutE2S1H TreeOutE1S1H TreeOutE0S1H }

wave RDeFuzzS1H pie {0,3.0,15n,3.0,18n,0,145n,0,148n,3.0,169n,3.0,172n,0,300n,0}
wave Q1H pie {0,0,3n,3.0,9.5n,3.0,12.5n,0,25n,0}
wave Q1L pie {0,3.0,3n,0,9.5n,0,12.5n,3.0,25n,3.0}
wave Q2H pie {0,0,12.5n,0,15.5n,3.0,22n,3.0,25n,0}
wave Q2L pie {0,3.0,12.5n,3.0,15.5n,0,22n,0,25n,3.0}
wave in bus {12(0000b)} pw=25n on=3.0 off=0.0 rt=3n ft=3n

transient 300n powerup

plot { Q1H Q2H reset sum10 DeFoutE5S1H DeFoutE4S1H DeFoutE3S1H DeFoutE2S1H DeFoutE1S1H DeFoutE0S1H }
