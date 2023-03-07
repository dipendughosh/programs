          REAL DUMMY,X,Y,X1,Y1,vg(4),vb(3)
          INTEGER I,J,MARK(10)
	  CHARACTER*48 INF,OUTF,REFF
C  INPUTS
	NARG=IARGC()
	IF (NARG.LT.1) THEN
		WRITE(6,40)
		READ (5,*) INF
		ELSE
		CALL GETARG(1,INF)
	ENDIF
        OPEN (1,FILE=INF)
	REWIND (1)

	IF (NARG.LT.2) THEN
	  WRITE(6,41)
	  READ (5,*) OUTF
	  ELSE
	  CALL GETARG(2,OUTF)
	ENDIF
        OPEN (2,FILE=OUTF)
	REWIND (2)

C	READ X,Y INPUT
	READ (1,*,END=1003) x1
	READ (1,*,END=1003) vg(1)
	READ (1,*,END=1003) vg(2)
	READ (1,*,END=1003) vg(3)
	READ (1,*,END=1003) vg(4)
	READ (1,*,END=1003) vb(1)	
	READ (1,*,END=1003) vb(2)
	READ (1,*,END=1003) vb(3)
	READ (1,*,END=1003) vds1
	READ (1,*,END=1003) vds2
	READ (1,*,END=1003) step
	READ (1,*,END=1003) x1
	READ (1,*,END=1003) x1
	READ (1,*,END=1003) x1
	do 30 j=1,4
	do 20 k=1,3
	do 10 i=1,int(step)
	READ (1,*,END=1003) bIDS
	vds=vds1+(vds2-vds1)/(step-1.)*(i-1.)
10	write(2,*)vds,vg(j),vb(k),bIDS
20	continue
30	continue
	write(2,*)'*****************'
C
	READ (1,*,END=1003) x1
	READ (1,*,END=1003) x1
	READ (1,*,END=1003) x1
	do 130 j=1,4
	do 120 k=1,3
	do 110 i=1,int(step)
	READ (1,*,END=1003) bIDS
	vds=vds1+(vds2-vds1)/(step-1.)*(i-1.)
110	write(2,*)vds,vg(j),vb(k),bIDS
120	continue
130	continue
	write(2,*)'*****************'
C
	READ (1,*,END=1003) x1
	READ (1,*,END=1003) x1
	READ (1,*,END=1003) x1
	do 230 j=1,4
	do 220 k=1,3
	do 210 i=1,int(step)
	READ (1,*,END=1003) bIDS
	vds=vds1+(vds2-vds1)/(step-1.)*(i-1.)
210	write(2,*)vds,vg(j),vb(k),bIDS
220	continue
230	continue
	goto 100
1003	WRITE (6,*) 'No intersection before end of file'
100	CLOSE (1)
	CLOSE (2)
C        CLOSE (3)
40      FORMAT (1x,'NAME OF INPUT FILE')
41      FORMAT (1x,'NAME OF OUTPUT FILE')
42      FORMAT (1x,'NAME OF REFERENCE INPUT FILE')
	END
