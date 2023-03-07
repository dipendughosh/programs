
volt ve GND 0.0
volt vs GND 0.0
volt vc GND 5.0
volt in GND .8 acmag=0.3 acphase=90.0 label=vin
ac lin 100 10MEG 1000MEG
plot {ir(Rc,vc) ii(Rc,vc) ir(Rc,c1) ii(Rc,c1) ir(Q1,c1) ii(Q1,c1)  }

acmodel { Q1  }



