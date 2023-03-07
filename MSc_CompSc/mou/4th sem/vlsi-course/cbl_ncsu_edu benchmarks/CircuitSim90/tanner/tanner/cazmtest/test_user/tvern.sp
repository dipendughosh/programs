*
.MODEL QSTD NPN IS=2E-16 BF=50 BR=0.1 RB=100 RC=10 TF=0.12N
+  TR=5N CJE=0.4P VJE=0.8 MJE=0.4 CJC=0.5P VJC=0.8 MJC=0.333
+  CJS=3P VAF=50 RBM=50 IRB=1.0e-4


q0 1 2 3 3 QSTD
q00 2 2 3 3 QSTD
rb0 0 2 10k
q1 4 5 1 3 QSTD
q2 4 0 1 3 QSTD
lb1 5 6 500n

vcc 4 0 12.0
vee 3 0 -12.0
vsrc 6 0 pwl(0 0 62.5p 10 125p 0 1 0)

.option limpts=10000
.tran .1n 10n
.print trans v(6) v(5) v(1) v(2)
.end

*waveform src pie {0 0 62.5p 10 125p 0 1 0}
*plot{b1 ncom nbias}
*transient 10n .1n

*q0 ncom nbias vee vee QSTD
*q00 nbias nbias vee vee QSTD
*rb0 gnd nbias 10k
*q1 vcc b1 ncom vee QSTD
*q2 vcc gnd ncom vee QSTD
*lb1 b1 src 500n



