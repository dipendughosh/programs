options reltol=0.01
ic {  100 =3  101 =0   200 =0  201 =3   300 =3  301 =0 }
wave 200 0 pie  { 0.0NS 0 1NS 0 2NS 3 5NS 3 6NS 0 10NS 0 11NS 3 15NS 3 
   16NS 0 20NS 0 21NS 3 25NS 3 26NS 0
  30NS 0 31NS 3 35NS 3 36NS 0 40NS 0 
 }label=V2S
transient 20NS 0.01NS
plot { V(200) V(201) v(20) V(203) V(204) V(301) V(30) V(303) V(304)}
