*
*
* THESE ARE NOMINAL CASE VALUES FOR THE MOSIS 3u CMOS PROCESS
*
.model nenh nmos
+ level=2.00            ld=0.100u               tox=500.e-10
+ nsub=1.0e+16          vto=0.779               kp=3.52e-05
+ gamma=1.04            phi=0.60                uo=400.0
+ uexp=1.001e-03        ucrit=999000.           delta=1.33
+ vmax=32585.3          xj=.0385u               lambda=2.052e-02
+ nfs=1.306e+11         neff=1.001e-02          nss=0.0e+00
+ tpg=1.0               rsh=25                  cgso=5.2e-10
+ cgdo=5.2e-10          cj=4.2e-4               mj=0.5
+ cjsw=9e-10            mjsw=0.33
*
.model penh pmos
+ level=2.00            ld=0.252u               tox=500.e-10
+ nsub=8.158e+14        vto=-0.988              kp=1.206e-05
+ gamma=0.619           phi=0.60                uo=150.0
+ uexp=0.170            ucrit=54941.0           delta=1.129
+ vmax=100000.          xj=.146u                lambda=3.165e-02
+ nfs=0.555e+10         neff=1.001e-02          nss=0.0e+00
+ tpg=-1.0              rsh=95                  cgso=4e-10
+ cgdo=4e-10            cj=3.2e-4               mj=0.5
+ cjsw=5.5e-10          mjsw=0.33
*

