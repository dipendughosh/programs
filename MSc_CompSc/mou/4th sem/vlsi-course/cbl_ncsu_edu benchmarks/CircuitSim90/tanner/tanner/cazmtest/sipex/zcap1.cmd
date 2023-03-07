wave gate2 0 pie{  0,-2.0 40ns,2.0 }
wave gate3 0 pie{  0,-2.0 40ns,2.0 }

transient 40n 0.25n

plot{ gate2 }
plot{ i(mn2,sub2) i(mn3,sub3) }
plot{ i(mn2,src2) i(mn3,src3) }
plot{ i(mn2,gate2) i(mn3,gate3) }
plot{ i(mn2,drn2) i(mn3,drn3) }

options abstol=1e-18 relchtol=1e-6 reltol=1e-10 chargetol=2e-15
