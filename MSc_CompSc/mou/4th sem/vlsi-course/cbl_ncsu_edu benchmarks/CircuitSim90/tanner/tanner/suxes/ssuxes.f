           Program SUXES
c
c     Date code : Jan 10,1982
c---------------------------------------------------------------------
c 
c     00000000000            
c     00000000000            
c     00       00            
c     00       00            
c     00       00            
c     0000   0000 
c     0000   0000
c       00   00
c       00   00
c     0000   0000
c     0000   0000
c
c     SUXES : Stanford University-Xerox Extraction Simulator
c
c     Original : Kyr. Doganis           Aug  1981  at Stanford
c     Mod # 1  : Kyr. Doganis           Nov  1981  at Stanford
c     Mod # 2  : Kyr. Doganis           Jan  1982  at Xerox
c
c--------------------------------------------------------------------
c     Common Area      
c--------------------------------------------------------------------
      double precision xdim, ydim
	include 'parsize.f'
c
      integer ttyw,ttyr
      common /termin/ luout,luinf,luopt,ttyw,ttyr,icont,iauto
c
      integer optflg
      character*2 k
      common /jpar/ m,n,nsig,maxfn,infer,ier,optflg,
     +       ibad,icount,idelx1,idelxl,idelxu,ieval,ifml,ifml1,ifpl,
     +       ifpl1,ifpu,igrad1,igradl,igradu,ijac,iscal1,iscall,iscalu,
     +       isw,iter,ixbad1,ixnew1,ixnewl,j,istop,inflag,
     +       icnst,kvk,kvkold,iterr,nvar,npar,iweigs,k
c
      common /yesno/ noyes(ixdim),next,mkeep,inext,ntimes
c
      double precision xparam,xlow,xuper
      common /xout/ xparam(ixdim),xlow(ixdim),xuper(ixdim)
c
      character*8 prname
      common /pnames/ prname(ixdim)
c
      character*8 xname
c
      character*8 idfunc
      common /idfu/ idfunc
c
      common /nfile/ nfiles
      character*8 fname1,fname2,fname3,fname4
      common /fnames/ fname1,fname2(10),fname3,fname4
c
      common /models/ model
c
      double precision xt(ixdim),id(ifdim)
c---------------------------------------------------------------------
c      Get the tty and other output lu's
c---------------------------------------------------------------------
      write(6,10)
10    format(/,
     +' ***********************************************************',/
     +' ***********************************************************',//
     +'     SUXES : Stanford University Extractor of Model Parameters ',/
     +'                                       Akis Doganis 2-10-83',//)
C  no need to ask  SHG-J  MCNC 4-18-86
      ttyw=6
      ttyr=5
C      write(6,11)
C11    format(' Input your Logic Unit No [write, read]  ',$)
C      read(5,*) ttyw,ttyr
c
c---------------------------------------------------------------------
c     Start of Optimization Routine
c---------------------------------------------------------------------
c     Call the Optimizer I/O routine. Do initial setup
c---------------------------------------------------------------------
      icont=0
      ntime=1
      next=0
      inext=0
      iauto=0
c---------------------------------------------------------------------
c     In case you need an output printouts
c---------------------------------------------------------------------
100   write(ttyw,20)
20    format(' Turn on the debugger(LUOUT) [plenty data] [y/n]? ',$)
      read(ttyr,10101) k
      luout=11
      if (k.eq.'n'.or.k.eq.'N') go to 120
      if (k.ne.'y'.and.k.ne.'Y') go to 100
      open(unit=1,file='luout.dat',status='new')
      luout=1
c---------------------------------------------------------------------
c      For consiquent operations
c---------------------------------------------------------------------
120   if (icont.eq.1) go to 110
c---------------------------------------------------------------------
c     automated desired ?
c---------------------------------------------------------------------
      write(ttyw,70)
70    format(' A U T O M A T E D    V E R S I O N ? [y/n] .. ',$)
      read(ttyr,10101) k
      if (k.eq.'y'.or.k.eq.'Y') iauto=1
      if (k.eq.'n'.or.k.eq.'N') iauto=0
      call tfun1(xt,id,6)
c---------------------------------------------------------------------
c     initial set up
c---------------------------------------------------------------------
110   call topto(1)
c---------------------------------------------------------------------
c     Call Optimizer Routine 
c---------------------------------------------------------------------
      call toptr
c---------------------------------------------------------------------
c     Call Optimizer I/O Routine , Do final printout
c---------------------------------------------------------------------
      call topto(2)
      inext=1
      icont=1
      if (iauto.eq.0) go to 200
c---------------------------------------------------------------------
c     used in the automated mode
c---------------------------------------------------------------------
      ntime=ntime+1
      if (ntime.le.ntimes) go to 110
c---------------------------------------------------------------------
c     for simulations, plots, etc
c---------------------------------------------------------------------
      call topto(3)
c---------------------------------------------------------------------
c     write the extracted parameters
c---------------------------------------------------------------------
200   write(ttyw,40)
40    format(/,' Save the EXTRACTED parameters ? '/
     +,5x,' [ No=0, or the name of the file (8 char)] ',$)
      read(ttyr,10102) xname
10102 format(a)
C      k=ichar(xname)-48
C      if (k.eq.0) go to 500
      if (xname.eq.'0') goto 500
      open(unit=4,file=xname,status='new')
      if (iauto.eq.1) then
       write(4,50) idfunc,fname1,fname3,fname4
       write(4,5153) (fname2(k1),k1=1,nfiles)
       write(4,5154)
       endif
50    format('*'/
     +       '*   MODEL used for the extraction .......:  ',a,/
     +       '*   INPUT file name .....................:  ',a,/
     +       '*   STRATEGY file name ..................:  ',a,/
     +       '*   OPTIONS file name ...................:  ',a)
5153  format('*   DATA file name ......................:  ',a)
5154  format('*',2x,'Parameters',9x,'Initial',9x,'Lowbound',
     +                                      9x,'Upperbound')
      if (iauto.eq.0) then
       write(4,90) idfunc,fname1,fname4
       write(4,5153) (fname2(k1),k1=1,nfiles)
       write(4,5154)
       endif
90    format('*'/
     +       '*   MODEL used for the extraction .......:  ',a,/
     +       '*   INPUT file name .....................:  ',a,/
     +       '*   OPTIONS file name ...................:  ',a,/)
      do 400 i=1,npar
         write(4,60) prname(i),xparam(i),xlow(i),xuper(i)
60       format(5x,a8,5x,3(1pg15.6,2x))
400   continue
      close(unit=4)
c---------------------------------------------------------------------
c     another operation
c---------------------------------------------------------------------
500   write(ttyw,30)
30    format(/,5x,'************************************************'/
     +5x,'*******   A G A I N  / Q U I T     [a/q]  ******     ',$)
      read(ttyr,10101) k
10101 format(a2)
      if (k.eq.'q'.or.k.eq.'Q') go to 1000
      if (k.eq.'a'.or.k.eq.'A') go to 120
      go to 500
1000   continue
      end
      subroutine TOPTO(ink)
c
c     Date Code  Jan 10,1982
c--------------------------------------------------------------------
c
c     Optimizer Setup and Output routine
c
c     Original : Kyr. Doganis                  Aug 1981 at Stanford
c     Mod # 1  : kyr. Doganis                  Nov 1981 at Stanford
c     Mod # 2  : kyr. Doganis                  Jan 1982 at Xerox
c
c---------------------------------------------------------------------
c
c     Common Area 
c---------------------------------------------------------------------
c
	include 'parsize.f'
c
      integer ttyw,ttyr
      common /termin/ luout,luinf,luopt,ttyw,ttyr,icont,iauto
c
      integer optflg
      character*2 k,ksym
      common /jpar/ m,n,nsig,maxfn,infer,ier,optflg,
     +       ibad,icount,idelx1,idelxl,idelxu,ieval,ifml,ifml1,ifpl,
     +       ifpl1,ifpu,igrad1,igradl,igradu,ijac,iscal1,iscall,iscalu,
     +       isw,iter,ixbad1,ixnew1,ixnewl,j,istop,inflag,
     +       icnst,kvk,kvkold,iterr,nvar,npar,iweigs,k
c
      double precision eps,delta,parm1,parm2,parm3,parm4,ssq,ax,
     +               al,cons2,delta2,erl2,erl2x,f0,f0sq,f0sqs4,g,val,
     +               hh,onesf0,prec,rel,relcon,sqdif,ssqold,up,xhold,
     +               bigtrg,smltrg
      common /xpar/   eps,delta,parm1,parm2,parm3,parm4,ssq,ax,
     +               al,cons2,delta2,erl2,erl2x,f0,f0sq,f0sqs4,g,val,
     +               hh,onesf0,prec,rel,relcon,sqdif,ssqold,up,xhold,
     +               bigtrg,smltrg
c
      double precision work
      common /work/ work(iwkdim)
c
       double precision x,f
       common /xf/ x(ixdim),f(ifdim)
c
       double precision xx,ff
       common /xxff/ xx(ixdim),ff(ifdim)
c
      double precision init,uprb,lowb,tolr,trgt,ores,weight
      common /incond/ init(ixdim),uprb(ixdim),lowb(ixdim),
     +        tolr(ifdim),trgt(ifdim),ores(ifdim),weight(ifdim)
c
      common /cstr/ icons(ixdim),icold(ixdim),
     +              itang(ixdim),itold(ixdim)
c
      double precision jtjsen,xjacs,grads,delxs
      common /jtjs/ jtjsen(ijtdim),xjacs(ijdim),
     +              grads(ixdim),delxs(ixdim)
c
      double precision initkp,uprbkp,lowbkp,tolrkp,trgtkp,weigkp
      common /inkeep/ initkp(ixdim),uprbkp(ixdim),lowbkp(ixdim),
     +                tolrkp(ifdim),trgtkp(ifdim),weigkp(ifdim)
c
      double precision v,vkp
      common /vars/ v(ifdim,invar),vkp(ifdim,invar)
c
      common /yesno/ noyes(ixdim),next,mkeep,inext,ntimes
c
      character*8 prname
      common /iproc/ iprocd(ixdim,10)
      common /pnames/ prname(ixdim)
c
      double precision ffsens
      common /ffsen/ ffsens(ifdim)
c
      character*8 prsnam(ixdim)
c
      double precision ersens(ifdim,ixdim)
      common /nfile/ nfiles
c----------------------------------------------------------------------
c     local variables     
c---------------------------------------------------------------------
c
      double precision aa,bb,u,cc,trgti
      double precision sum,xsqrt
      double precision initl(ixdim)
      double precision xs(ixdim)
      double precision xt(ixdim),id(ifdim)
c
       double precision xparam,xlow,xuper
       common /xout/ xparam(ixdim),xlow(ixdim),xuper(ixdim)
c
c---------------------------------------------------------------------
c     start of program SUXES
c---------------------------------------------------------------------
c
      if (iauto.eq.0) write(ttyw,1)
1     format(' SEGMENT TOPTO')
c
      go to (101,200,3000),ink
c---------------------------------------------------------------------
c
c     start of setup routine
c
c---------------------------------------------------------------------
101   optflg=-99
      inflag=1
      if (icont.eq.0) call filrea(1)
      if (iauto.eq.0) go to 7000
c--------------------------------------------------------------------
c     If automated version is desired
c--------------------------------------------------------------------
c
      if (icont.eq.0) ntime=0
      ntime=ntime+1
      if (icont.eq.1) go to 6030
c---------------------------------------------------------------------
c     first time for the automated mode
c---------------------------------------------------------------------
      do 6010 i=1,npar
         noyes(i)=iprocd(i,1)
6010  continue
      go to 6020
c---------------------------------------------------------------------
c     consiquent operations updateing procedures
c---------------------------------------------------------------------
6030  do 6035 i=1,npar
         initkp(i)=xparam(i)
         noyes(i)=iprocd(i,ntime)
6035  continue
c---------------------------------------------------------------------
c     defines the new parameters to be extracted
c---------------------------------------------------------------------
6020  l=0
      do 6040 i=1,npar
         if (noyes(i).eq.0) go to 6040
         l=l+1
         init(l)=initkp(i)
         lowb(l)=lowbkp(i)
         uprb(l)=uprbkp(i)
6040  continue
c---------------------------------------------------------------------
c     check the parameter's number
c---------------------------------------------------------------------
      n=l
      if (n.le.0) write(ttyw,1171)
      if (n.le.0) stop
c-----------------------------------------------------------------
c     take care of weights
c-----------------------------------------------------------------
      if (iweigs.eq.1) call tfun1(xt,id,5)
      go to 115
c-----------------------------------------------------------------
c      if manual version is desired
c-----------------------------------------------------------------
c
7000  idef=0
      if (iweigs.eq.1) call tfun1(xt,id,5)
100   write(ttyw,1001)
1001  format(/x,'* * * * * * * * D E F I N E  T H E  F O L L O W I N G 
     +* * * * * * * * * * *'//
     +10x,'Define the Optimizable Parameters (*).......[yes=1]'/
     +10x,'Number of the data points ........(m).......[yes=2]'/
     +10x,'Initial values of the Parameters  (init)....[yes=3]'/
     +10x,'Lower and Upper Bounds .......(lowb,uprb)...[yes=4]'/
     +10x,'Data to be fitted ................(trgt)....[yes=5]'/
     +10x,'Fit Tolerances ...................(tolr)....[yes=6]'/
     +10X,'Weights to the Data...............(weight)..[yes=7]'//
     +10X,'* * * * * GO TO THE NEXT STEP * * * * * * * [yes=0]'/
     +50x,'....................',$)
      read(ttyr,10101) k
      write(ttyw,207)
      if (k.eq.'0') go to 2000
      if (k.eq.'1') go to 1100
      if (k.eq.'2') go to 1200
      if (k.eq.'3') go to 1300
      if (k.eq.'4') go to 1400
      if (k.eq.'5') go to 1500
      if (k.eq.'6') go to 1600
      if (k.eq.'7') go to 1700
      go to 100
c---------------------------------------------------------------------
c     see/change the optimizable parameters
c---------------------------------------------------------------------
1100  l=0
      do 1110 i=1,npar
         ksym=' '
         aa=initkp(i)
c         if (aa.eq.1.d30) go to 1110
         if (noyes(i).ne.1) go to 1113
         ksym='*'
         l=l+1
         aa=init(l)
1113     write(ttyw,1111) ksym,prname(i),aa
1111     format(5x,a1,x,a8,2x,'Init=',1pg15.6)
1110  continue
c
      write(ttyw,207)
      write(ttyw,1132)
1132  format(22x,
     +      'See/Change/Update/Opt.chg.updat/oRig/Quit [s,c,u,o,r,q]')
      write(ttyw,207)
1120  l=0
      ll=0
      do 1130 i=1,npar
         ksym=' '
         if (noyes(i).ne.1) go to 1140
         ksym='*'
         ll=ll+1
         aa=init(ll)
         bb=init(ll)
         if (inext.eq.1.and.idef.eq.0) bb=xx(ll)
         write(ttyw,1131) ksym,prname(i),aa,bb
         go to 1145
1140     aa=initkp(i)
         bb=initkp(i)
         write(ttyw,1131) ksym,prname(i),aa,bb
1131     format(3x,a1,x,a8,'INIT=',1pg15.6,x,
     +         'Update=',1pg15.6,x,'[s/c/u/o/r/q] ?',$)
1145     read(ttyr,10101) k
         if (k.eq.'c'.or.k.eq.'C') go to 1150
         if (k.eq.'o'.or.k.eq.'O') go to 1160
         if (k.eq.'r'.or.k.eq.'R') go to 1170
         if (k.eq.'q'.or.k.eq.'Q') go to 1135
         if (k.eq.'s'.or.k.eq.'S') go to 11800
         noyes(i)=0 
         initkp(i)=aa
         if (k.eq.'u'.or.k.eq.'U') initkp(i)=bb
         uprbkp(i)=uprbkp(i)
         lowbkp(i)=lowbkp(i)
         go to 1130
1150     write(ttyw,1012)
         read(ttyr,*) initkp(i)
         noyes(i)=0
         go to 1130
1160     ksym='*'
         l=l+1
         initl(l)=aa
         lowb(l)=lowbkp(i)
         uprb(l)=uprbkp(i)
         if (noyes(i).ne.1) go to 1165
         write(ttyw,1161) ksym,prname(i),aa,bb
1161     format(2x,a1,x,a8,'INIT=',1pg15.6,
     +   x,'Updat=',1pg15.6,x,'Chg/Upd [c/u] ',$)
         read(ttyr,10101) k
         if (k.eq.'c'.or.k.eq.'C') go to 1180
         if (k.eq.'u'.or.k.eq.'U') go to 1190   
         go to 1130
1180     write(ttyw,1012)
         read(ttyr,*) initl(l)
         go to 1130
1190     initl(l)=bb
         go to 1130
1165     noyes(i)=1
         write(ttyw,1162) ksym,prname(i),aa
1162     format(2x,a1,x,a8,'INIT=',1pg15.6,
     +   '.... Change [c] ? ',$)
         read(ttyr,10101) k
         if (k.ne.'c'.and.k.ne.'C') go to 1130
         write(ttyw,1012)
         read(ttyr,*) initl(l)
         go to 1130
1135     if (ll.gt.0) ll=ll-1
         do 1136 il=i,npar
            ksym=' '
            if (noyes(il).ne.1) go to 1136
            ksym='*'
            ll=ll+1     
            l=l+1
            initl(l)=init(ll)
1136     continue
         go to 1137
11800    if (noyes(i).ne.1) go to 1130
         l=l+1
         initl(l)=aa
1130  continue
c
1137  n=l
      if (n.gt.0) go to 1195
      write(ttyw,1171)
1171  format(20x,' * * * W A R N I N G * * * '/
     +       20x,' No parameters to Optimize'/)
      go to 1120
1195  do 1199 i=1,n
         init(i)=initl(i)
1199  continue
      idef=1
c
      go to 100
1170  call filrea(4)
      go to 100
10101 format(a2)
c--------------------------------------------------------------------
c      initial values for the parameters
c-------------------------------------------------------------------
1300  if (n.gt.0) go to 1302
      write(ttyw,207)
      write(ttyw,1171)
      go to 100
1302  l=0
      do 1310 i=1,npar
         if (noyes(i).eq.0) go to 1310
         l=l+1
         write(ttyw,1311) prname(i),init(l)
1311     format(5x,a8,'  INIT=',1pg15.6,'....CHANGE [c] ? ',$)
         read(ttyr,10101) k
         if (k.ne.'c'.and.k.ne.'C') go to 1310
         write(ttyw,1012)
         read(ttyr,*) init(L)
1310  continue
c
      go to 100
c-----------------------------------------------------------------
c     low and uper bounds 
c-----------------------------------------------------------------
1400  if (n.gt.0) go to 1402
      write(ttyw,207)
      write(ttyw,1171)
      go to 100
1402  l=0
      do 1410 i=1,npar
         if (noyes(i).eq.0) go to 1410
         l=l+1
         write(ttyw,1411) prname(i),lowb(l),uprb(l)
1411     format(2x,a8,2x,'LOWB=',1pg15.6,'  UPRB=',1pg15.6,
     +   '.......CHANGE [c] ? ',$)
         read(ttyr,10101) k
         if (k.ne.'c'.and.k.ne.'C') go to 1410
         write(ttyw,1012)
1012     format(20x,'Input the value ........... ',$)
         read(ttyr,*) lowbkp(i),uprbkp(i)
         lowb(l)=lowbkp(i)
         uprb(l)=uprbkp(i)
1410  continue
c
      go to 100
c-------------------------------------------------------------------
c     number of points 
c------------------------------------------------------------------
1200  write(ttyw,1201) m-nfiles
1201  format(/,20x,' m=',i4,/)
      go to 100
2222  bigtrg=0.0d0
      smltrg=0.0d0
      do 1220 i=1,mkeep
         trgt(i)=trgtkp(i)
         tolr(i)=tolrkp(i)
         weight(i)=weigkp(i)
         trgti=dabs(trgt(i))
         if (trgti.ge.1.d8) bigtrg=dmax1(bigtrg,trgti)
         if (trgti.lt.1.d8) smltrg=dmax1(smltrg,trgti)
         do 1210 j=1,nvar
            v(i,j)=vkp(i,j)
1210     continue
1220  continue
c
      m=mkeep
      bigtrg=1.d-3*bigtrg
      smltrg=1.d-3*smltrg
      if (smltrg.eq.0.0d0) call users(3,1)
      go to 100
c---------------------------------------------------------------
c     targets to see/change
c---------------------------------------------------------------
1500  igo=0
      l=1
      write(ttyw,1512)
1512  format(5x,'Vds',8x,'Vgs',8x,'Vbs',8x,'Ids',8x,
     +  'Del/Change/Orig/Quit')
      do 1510 i=1,m
         if (igo.eq.1) go to 1520
         if (v(i,1).lt.1.d10)
     +     write(ttyw,1511) (v(i,j),j=1,nvar),trgt(i)
         if (v(i,1).ge.1.d10)
     +    write(ttyw,2090) v(i,1)*1.d-30,v(i,2)*1.d-30
         if (v(i,1).ge.1.d10) go to 1520
1511     format(2x,3(1pg8.2,3x),1pg15.6,5x,
     +  '[d/c/o/q] ',$)
         read(ttyr,10101) k
         if (k.eq.'o'.or.k.eq.'O') go to 2222
         if (k.eq.'d'.or.k.eq.'D') go to 1510
         if (k.eq.'q'.or.k.eq.'Q') go to 1540
         if (k.ne.'c'.and.k.ne.'C') go to 1520
         write(ttyw,1012)
         read(ttyr,*) trgt(i)
         go to 1520
1540     igo=1
1520     trgt(l)=trgt(i)
         tolr(l)=tolr(i)
         weight(l)=weight(i)
         do 1530 j=1,nvar
            v(l,j)=v(i,j)
1530     continue
         l=l+1
1510  continue
c
      m=l-1
      go to 100
c----------------------------------------------------------------
c     tolerances see/change
c---------------------------------------------------------------
1600      write(ttyw,1612)
1612  format(5x,'Vds',8x,'Vgs',8x,'Vbs',13x,'Ids',8x,
     +           'Tolr       Change/Quit')
         do 1610 i=1,m
         if (v(i,1).lt.1.d10)
     +   write(ttyw,1611) (v(i,j),j=1,nvar),trgt(i),tolr(i)
         if (v(i,1).ge.1.d10)
     +    write(ttyw,2090) v(i,1)*1.d-30,v(i,2)*1.d-30
         if (v(i,1).ge.1.d10) go to 1610
1611     format(2x,3(1pg8.2,3x),1pg15.6,4x,
     +1pg8.2,3x,'[c/q]..',$)
         read(ttyr,10101) k
         if (k.eq.'q'.or.k.eq.'Q') go to 100
         if (k.ne.'c'.and.k.ne.'C') go to 1610
         write(ttyw,1012)
         read(ttyr,*) tolr(i)
1610  continue
c
      go to 100
c---------------------------------------------------------------
c     weights see./change
c--------------------------------------------------------------
1700   write(ttyw,1701)
1701   format(' Weights? Programable/Kept/No? [p/k/n]  ',$)
       read(ttyr,10101) k
       if (k.eq.'n'.or.k.eq.'N') go to 1705
       iweigs=1
       if (k.eq.'k'.or.k.eq.'K') go to 1800
       if (k.ne.'p'.and.k.ne.'P') go to 1700
       call tfun1(xt,id,5)
       go to 1800
1705   iweigs=0
       do 1800 i=1,m
          weight(i)=1.d0
1800   continue
      write(ttyw,1812)
1812  format(5x,'Vds',8x,'Vgs',8x,'Vbs',13x,'Ids',8x,
     +'Weight      Change/Quit')
       do 1710 i=1,m
         if (v(i,1).lt.1.d10)
     + write(ttyw,1711) (v(i,j),j=1,nvar),trgt(i),weight(i)
         if (v(i,1).ge.1.d10)
     +    write(ttyw,2090) v(i,1)*1.d-30,v(i,2)*1.d-30
         if (v(i,1).ge.1.d10) go to 1710
1711     format(2x,3(1pg8.2,3x),1pg15.6,5x,
     +1pg8.2,3x,'[c/q]..',$)
         read(ttyr,10101) k
         if (k.eq.'q'.or.k.eq.'Q') go to 100
         if (k.ne.'c'.and.k.ne.'C') go to 1710
         write(ttyw,1012)
         read(ttyr,*) weight(i)
1710  continue
c
      go to 100
c----------------------------------------------------------------
c     go for the optional values
c----------------------------------------------------------------
2000  write(ttyw,207)
      if (n.gt.0) go to 1999
      write(ttyw,1171)
      go to 100
1999  if (m.ge.n) go to 2001 
      write(ttyw,2002)
      go to 100
2002  format(20x,' * * * W A R N I N G * * * '/
     +       20x,'     M is less than N '/)
2001  continue
      write(ttyw,191) char(12),
     +               NSIG,MAXFN,eps,delta,parm1,parm2,parm3,parm4
4500  write(ttyw,1081)
1081  format(1x,'* * * * * * C H A N G E  T H E  O P T I O N A L  V A L
     + U E S ? * * * * * '//
     +10x,'Nsignificant, Max Function Evaluations......[yes=1]'/
     +10x,'SSQ Diff Epsilon, Norm Gradient Delta.......[yes=2]'/
     +10x,'M-L Parameter, Initial, Scale, Max..........[yes=3]'/
     +10x,'Forward/Central Difference Switch...........[yes=4]'//
     +10x,'....G O  T O  P R E V I O U S  S T E P......[yes=5]'/
     +10X,'...S T A R T  T H E  E X T R A C T I O N....[yes=0]'/
     +50x,'...............',$)
      read(ttyr,10101) k
      if (k.eq.'0') go to 115
      if (k.eq.'1') go to 2100
      if (k.eq.'2') go to 2200
      if (k.eq.'3') go to 2300
      if (k.eq.'4') go to 2400
      if (k.eq.'5') go to 100
      go to 4500
2100  write(ttyw,2111)
2111  format(' NSIG, MAXFN=',$)
      read(ttyr,*) nsig,maxfn
      go to 4500
2200  write(ttyw,2201)
2201  format(' SSQ DIFF EPSIL,  NORM GRAD DELTA =',$)
      read(ttyr,*) eps,delta 
      go to 4500
2300  write(ttyw,2301)
2301  format(' M-L Parameter [INIT, SCALE, MAX]=',$)
      read(ttyr,*) parm1,parm2,parm3
      go to 4500
2400  write(ttyw,2401)
2401  format(' FORW/CENTL SWITCH =',$)
      read(ttyr,*) parm4
      go to 4500
115   write(ttyw,207)
      do 120 i=1,n
         aa=lowb(i)
         bb=uprb(i)
         if (bb.lt.aa) lowb(i)=bb
         if (bb.lt.aa) uprb(i)=aa
         x(i)=1.0d0
120   continue
c
c---------------------------------------------------------------------
c     scan output parameters
c---------------------------------------------------------------------
135   do 140 i=1,m
         ores(i)=0.0d0
         tolr(i)=abs(tolr(i))
140   continue
c
c---------------------------------------------------------------------
c     write out optimimization data
c---------------------------------------------------------------------
      if (luout.eq.11) go to 192
      write(luout,174) char(12)
174   format(a,/' OPTIMIZATION INPUT PARAMETERS ( * = Extracted )'/
     +/5X,2x,'NAME',7x,'INIT. VALUE',7x,'LOWER BOUND',7x,'UPPER BOUND'
     +/)
c
      do 175 i=1,npar
         ksym=' '
         if (noyes(i).eq.1) ksym='*'
         write(luout,176) 
     +      ksym,prname(i),init(i),lowb(i),uprb(i)
176   format(5x,a1,x,a8,3(3x,1pg15.6))
175   continue
c
c      write(luout,181) char(12)
181   format(a,/' OPTIMIZATION OUTPUT VARIABLES'/
     +/5X,2x,'NAME',9x,'TARGET VAL.',8x,'TOLERANCE',8x,' WEIGHT'/)
c
c      do 185 i=1,m
c         aa=100.d0*tolr(i)
c         bb=weight(i)**2.
c         write(luout,186) i,trgt(i),aa,bb
185   continue
c
186   format(3x,'F(',i4,')=',5x,1pg15.7,0pf15.7,' %',5x,1pg15.7)
c
      write(luout,191) char(12),
     +                 nsig,maxfn,eps,delta,parm1,parm2,parm3,parm4
191   format(a,/' OPTIMIZATION OPTION VALUES'//
     +5X,'NUMBER OF SIGNIFICANT DIGITS =',I9/
     +5X,'MAX.  NO. OF FUNCTION EVALS. =',I9//
     +5X,'SUM OF SQUARES DIFF. EPSILON =',1PG14.6/
     +5X,'NORM OF GRADIENT BOUND DELTA =',1PG14.6//
     +5X,'MARQUARDT PARAM INITIAL VAL. =',1PG14.6/
     +5X,'MARQUARDT PARAM SCALE FACTOR =',1PG14.6/
     +5X,'MARQUARDT PARAM UPPER BOUND  =',1PG14.6//
     +5X,'FORWARD/CENTRAL DIFF. SWITCH =',1PG14.6/)
c---------------------------------------------------------------------
c
c     set the initial ICONS(.)=0
c                     ICOLD(.)=0
c                     ITANG(.)=1
c                     ITOLD(.)=1
c                     KVK=0
c                     KVKOLD=0
c---------------------------------------------------------------------
192   continue
      if (luout.ne.11) write(luout,9951)
9951  format(' topto192 ',/
     +'  Low bound     Initial     Uprb bound     Constraints ')
      kvk=0
      kvkold=0
      do 199 i=1,n
          icons(i)=0 
       if (init(i).eq.0.0d0) init(i)=(uprb(i)-lowb(i))/1000.d0
       if (init(i).ge.uprb(i).and.uprb(i).ne.0.0d0)
     +     init(i)=uprb(i)-1d-3*dabs(uprb(i))
       if (init(i).ge.uprb(i).and.uprb(i).eq.0.0d0)
     +     init(i)=lowb(i)/1000.d0
       if (init(i).le.lowb(i).and.lowb(i).ne.0.0d0)
     +     init(i)=lowb(i)+1d-3*dabs(lowb(i))
       if (init(i).le.lowb(i).and.lowb(i).eq.0.0d0)
     +     init(i)=uprb(i)/1000.d0
          icold(i)=0
          itang(i)=1
          itold(i)=1
c       if (luout.ne.11) write(luout,9950) 
c     +    lowb(i),init(i),uprb(i),icons(i)
9950   format(x,3(1pg14.5,x)x,i2)
199   continue
c
      return
c---------------------------------------------------------------------
c
c     optimizer write-out routine
c
c---------------------------------------------------------------------
200   if (luout.ne.11) write(luout,201) 
      write(ttyw,201)
201   format(/' OPTIMIZATION INPUT RESULTS'/
     +/5X,'  NAME         INIT. VALUE    FINAL VALUE  '
     +/)
c
202   l=0
      do 205 i=1,npar
         ksym=' '
         if (noyes(i).eq.0) go to 204
         ksym='*'
         l=l+1
         aa=init(l)
         u=x(l)
         bb=aa*u
         if (init(l).eq.0.0d0) bb=u
         go to 203
204      aa=initkp(i)
         bb=aa
203      xt(i)=bb
         xparam(i)=bb
         xlow(i)=lowbkp(i)
         xuper(i)=uprbkp(i)
         if (luout.ne.11) write(luout,206) ksym,prname(i),aa,bb
      write(ttyw,206) ksym,prname(i),aa,bb
206   format(5x,a2,a8,2x,1p2g15.6)
205   continue
      if (iauto.eq.1) go to 6100
c------------------------------------------------------------
c      if manual version is desired
c------------------------------------------------------------
      write(ttyw,209)
209   format(/
     +' Do you want the Final Fitting Errors ? [y/n] ',$)
      read(ttyr,10101) k
      if (k.ne.'y'.and.k.ne.'Y') go to 216
      if (luout.ne.11) write(luout,211) char(12)
      write(ttyw,211) char(12)
211   format(a,/' OPTIMIZATION FINAL FITTING ERRORS'/
     + 2x,'Vds',7x,'Vgs',7x,'Vbs',13x,'Ids',10x,
     +   'Extracted Ids',3x,'NormalErrors'/)
c
      ideter=0
      do 215 i=1,m
         ideter=ideter+1
         if (ideter.le.100) go to 66699
         write(ttyw,209)
         read(ttyr,10101)k
         if (k.ne.'y'.and.k.ne.'Y') go to 216
         write(ttyw,211) char(12)
         ideter=0
66699    aa=ores(i)
         bb=ff(i)
         u=trgt(i)
         cc=weight(i)**2
         l=i
         call users(2,l)
         val=val/dsqrt(weight(i))
         val=1.d2*val
         if (luout.ne.11) write(luout,208)
     +      (v(i,j),j=1,nvar),trgt(i),ff(i),val
         if (v(i,1).lt.1.d10)
     +    write(ttyw,208) (v(i,j),j=1,nvar),trgt(i),ff(i),val
         if (v(i,1).ge.1.d10)
     +    write(ttyw,2090) v(i,1)*1.d-30,v(i,2)*1.d-30
2090  format(10x,'Length=',1pg10.2,5x,'Width=',1pg10.2)
208   format(x,3(1pg8.2,2x),2(1pg15.6,2x),0pf10.4,' %')
215   continue
216   continue
c
      if (luout.ne.11) write(luout,207)
      if (luout.ne.11) write(luout,207)
      write(ttyw,207)
207   format(' ')
      call tfun1(xt,Id,4)
      if (luout.ne.11) write(luout,207)
      call func1(x,work(ifpl))
      if (luout.ne.11) write(luout,207)
      write(ttyw,220)
220   format(/' Do you want sensitivity analysis ? [y/n] ',$)
      read(ttyr,10101) k
      if (k.eq.'n'.or.k.eq.'N') go to 5554
c     sum=0.0d0
      do 300 i=1,n
         xs(i)=x(i)*init(i)
c        sum=sum+xs(i)*xs(i)
300   continue
c     xsqrt=dsqrt(sum)
      il=0
      do 400 i=1,npar
         if (noyes(i).eq.0) go to 400
         il=il+1
         xs(il)=init(il)*1.01d0*x(il)
         call tfun1(xs,ff,3)
         xs(il)=x(il)*init(il)
         sum=0.0d0
         do 500 j=1,m
            call users(2,j)
            sum=sum+val*val
            ersens(j,il)=val*100.0d0/dsqrt(weight(j))-ffsens(j)
500      continue
         sum=(sum-ssq)/(0.01d0*ssq)
         write(ttyw,501) prname(i),sum
501      format(2x,'For 1% change in the ',a8,' the SENSITIVITY
     + is ',1pg16.5)
400   continue
      k='n'
c      write(ttyw,221)
221   format(/,'  Continue  ?   WARNING  plenty of data [y/n] ',$)
c      read(ttyr,10101) k
      if (k.eq.'n'.or.k.eq.'N') go to 5554
      l=0
      write(6,*)'Entering a forbidden zone!'
      do 1000 ii=1,npar
         if (noyes(ii).eq.0) go to 1000
         l=l+1
         prsnam(l)=prname(ii)
1000  continue
      nk=(n-1)/3+1
      do 4100 ii=1,nk
         ninit=(ii-1)*3+1
         nfinal=n
         if (n.ge.3*ii) nfinal=3*ii
         ntotl=nfinal-ninit+1
         write(ttyw,4110) (prsnam(ij),ij=ninit,nfinal)
         write(ttyw,4120) 
     +   (trgt(j),ffsens(j),(ersens(j,i),i=ninit,nfinal),j=1,m)
4100   continue
4110   format(/,'      TARGET      CALCULATED %   ',
     +       3(a8,'(1% err) '),/)
4120   format(5(1x,1pg15.6,1x,
     +            0pf10.4,' %  ',3(0pf10.4,' %  '),/))
      write(6,*)'Leaving forbidden zone'
5554  write(ttyw,5556)
5556  format(/,' Do you want eigenvalues-eigenvectors [y/n] ?',$)
      read(ttyr,10101) k
      if (k.eq.'n'.or.k.eq.'N') go to 5557
      call sensit
5557  write(ttyw,5555)
5555  format(/,' Generate plot Files/Screen/NONE  [f/s/n] ?',$)
      read(ttyr,10101) k
      optflg=0
      if (k.eq.'f'.or.k.eq.'F') call plot(xt)
      if (k.eq.'s'.or.k.eq.'S') call scren(xt)
      if (k.eq.'n'.or.k.eq.'N') return
      go to 5557
C   Next 6 lines are not necessary and not called???
C 9999  write(ttyw,5555)
C       read(ttyr,10101) k
C       if (k.eq.'s'.or.k.eq.'S') call scren(xt)
C       if (k.eq.'f'.or.k.eq.'F') call plot(xt)
C       if (k.eq.'n'.or.k.eq.'N') return
C       go to 9999
C
6100  continue
c----------------------------------------------------------------
c      continuing for the automated version
c---------------------------------------------------------------
      if (luout.ne.11) write(luout,207)
      call func1(x,work(ifpl))
      optflg=0
      return
3000  continue
      call tfun1(xt,id,4)
3003      write(ttyw,5555)
      read(ttyr,10101) k
      optflg=0
      if (k.eq.'f'.or.k.eq.'F') call plot(xt)
      if (k.eq.'s'.or.k.eq.'S') call scren(xt)
      if (k.eq.'n'.or.k.eq.'N') go to 3004
      go to 3003
3004  end
      subroutine FUNC1(xin,residl)
c
c     Date Code  Jan 10,1982
c--------------------------------------------------------------------
c
c     Optimization function and residual calculations
c
c     Original : Kyr. Doganis                  Aug 1981 at Stanford
c     Mod # 1  : kyr. Doganis                  Nov 1981 at Stanford
c     Mod # 2  : kyr. Doganis                  Jan 1982 at Xerox
c
c---------------------------------------------------------------------
c
c     Common Area 
c---------------------------------------------------------------------
c
	include 'parsize.f'
c---------------------------------------------------------------------
      integer ttyw,ttyr
      common /termin/ luout,luinf,luopt,ttyw,ttyr,icont,iauto
c
      integer optflg
      character*2 k,ksym,ksub
      common /jpar/ m,n,nsig,maxfn,infer,ier,optflg,
     +       ibad,icount,idelx1,idelxl,idelxu,ieval,ifml,ifml1,ifpl,
     +       ifpl1,ifpu,igrad1,igradl,igradu,ijac,iscal1,iscall,iscalu,
     +       isw,iter,ixbad1,ixnew1,ixnewl,j,istop,inflag,
     +       icnst,kvk,kvkold,iterr,nvar,npar,iweigs,k
c
      double precision eps,delta,parm1,parm2,parm3,parm4,ssq,ax,
     +               al,cons2,delta2,erl2,erl2x,f0,f0sq,f0sqs4,g,val,
     +               hh,onesf0,prec,rel,relcon,sqdif,ssqold,up,xhold,
     +               bigtrg,smltrg
      common /xpar/   eps,delta,parm1,parm2,parm3,parm4,ssq,ax,
     +               al,cons2,delta2,erl2,erl2x,f0,f0sq,f0sqs4,g,val,
     +               hh,onesf0,prec,rel,relcon,sqdif,ssqold,up,xhold,
     +               bigtrg,smltrg
c
      double precision x,f
      common /xf/ x(ixdim),f(ifdim)
c
      double precision work
      common /work/ work(iwkdim)
c
      common /cstr/ icons(ixdim),icold(ixdim),
     +              itang(ixdim),itold(ixdim)
c
      double precision xx,ff
      common /xxff/ xx(ixdim),ff(ifdim)
c
      double precision init,uprb,lowb,tolr,trgt,ores,weight
      common /incond/ init(ixdim),uprb(ixdim),lowb(ixdim),
     +        tolr(ifdim),trgt(ifdim),ores(ifdim),weight(ifdim)
c
      common /yesno/ noyes(ixdim),next,mkeep,inext,ntimes
c
      character*8 prname
      common /pnames/ prname(ixdim)
c
      double precision ffsens
      common /ffsen/ ffsens(ifdim)
c---------------------------------------------------------------------
c     local variables
c---------------------------------------------------------------------
      double precision iux,del0
      double precision deli(ixdim),residl(ifdim),xin(ixdim)
c---------------------------------------------------------------------
c
c     start of subroutine func1
c
c---------------------------------------------------------------------
      if (iauto.eq.1) go to (800,800,7,800), optflg
      goto (1,2,3,800), optflg
1     write(ttyw,4)
      goto 800
2     write(ttyw,5)
      goto 800
3     write(ttyw,6)
4     format(' FORWARD DIFF. EVALUATION')
5     format(' BACKWARD DIFF. EVALUATION')
6     format(' FUNCTION EVALUATION')
c---------------------------------------------------------------------
c
c      record the constrain violations by ICONS(.)
c                           ICONS(.)=0 no violation
c                           ICONS(.)=1 uprb
c                           ICONS(.)=-1 lowb
c      if ICONS(i)=1 or -1  as input then DELI(i)=1d12
c      if ICONS(i)=0 and no violation then DELI(i)=1d10
c
c---------------------------------------------------------------------
9950  format(' Func1 7',/
     + ' Val       Iux         Icons           Deli  ')
c
7     continue
      if (luout.ne.11) write(luout,9950)
      do 101 i=1,n
         val=init(i)*xin(i)
         if (init(i).eq.0.0d0) val=xin(i)
         if (icons(i).ne.0) go to 99
         if (val.ge.uprb(i)) go to 70
         if (val.le.lowb(i)) go to 80
         icons(i)=0
         deli(i)=1d10
         go to 100
 70      icons(i)=1
         if (init(i).eq.0.0d0) iux=uprb(i)
         if (init(i).ne.0.0d0) iux=uprb(i)/init(i)
         go to 95
 80      icons(i)=-1
         if (init(i).eq.0.0d0) iux=lowb(i)
         if (init(i).ne.0.0d0) iux=lowb(i)/init(i)
 95      deli(i)=1.0d0
         if (work(idelx1+i).ne.0.0d0) 
     +    deli(i)=-(iux-x(i))/work(idelx1+i)
         if (deli(i).eq.0.0d0) deli(i)=2.0d0
         go to 100
 99      deli(i)=1d12
100   continue
      if (luout.ne.11) write(luout,9951) val,iux,icons(i),deli(i)
9951  format(x,2(1pg15.4,x)x,i2,x,1pg14.5)
101   continue
c---------------------------------------------------------------------
c
c     now find the min of all DELI(i)
c     and record it as DEL0
c
c---------------------------------------------------------------------
      del0=deli(1)
      do 200 i=1,n
         del0=dmin1(del0,deli(i))
200   continue
c---------------------------------------------------------------------
c
c      if there is not a new constrain
c
c---------------------------------------------------------------------
       if (del0.eq.1d10) go to 250
       if (del0.eq.2.0d0) del0=1.0d0
c---------------------------------------------------------------------
c
c     find if this min satisfied by more than 1 constrain
c     find the new constrains
c     find the new point x(k1+1) on those constrains
c     be sure to be in the  constrains
c
c---------------------------------------------------------------------
      k1=0
      if (luout.ne.11) write(luout,9953)
9953  format(' Func1 300'/' Icons   xx      Deltax new')
      do 301 i=1,n
         if (deli(i).eq.2.d0) go to 310
         if (del0.eq.deli(i)) go to 310
         if (deli(i).ne.1d12) go to 320
 310     k1=k1+1
 325     if (icons(i).eq.1) go to 350
         if (init(i).eq.0.0d0) work(ixnew1+i)=lowb(i)
         if (init(i).ne.0.0d0) work(ixnew1+i)=lowb(i)/init(i)
         xx(i)=lowb(i)
         go to 300
 350     if (init(i).eq.0.0d0) work(ixnew1+i)=uprb(i)
         if (init(i).ne.0.0d0) work(ixnew1+i)=uprb(i)/init(i)
         xx(i)=uprb(i)
         go to 300
 320     icons(i)=0
         work(ixnew1+i)=x(i)-del0*work(idelx1+i)
         xx(i)=init(i)*work(ixnew1+i)
         if (init(i).eq.0.0d0) xx(i)=work(ixnew1+i)
300   continue
      if (luout.ne.11) write(luout,9952) icons(i),xx(i),work(ixnew1+i)
9952  format(x,i2,2(1pg15.4,x))
301   continue
c---------------------------------------------------------------------
c
c     kvk are the new constrains
c
c----------------------------------------------------------------------
      kvk=k1
      go to 270
      
250   do 260 i=1,n
         xx(i)=init(i)*work(ixnew1+i)
         if (init(i).eq.0.0d0) xx(i)=work(ixnew1+i)
260   continue
c----------------------------------------------------------------------
270   if (iauto.eq.1) go to 6100 
      l=0
      do 900 i=1,npar
         if (noyes(i).eq.0) go to 900
         l=l+1
         ksym=' '
         ksub=' '
         if (xx(l).ge.uprb(l).or.xx(l).le.lowb(l)) ksym='+'
         if (xx(l).ge.uprb(l).or.xx(l).le.lowb(l)) KSUB='*'
      write(ttyw,21) ksym,prname(i),xx(l),work(ixnew1+l),(ksub,ii=1,10)
         if (luout.ne.11) write(luout,21) 
     +      ksym,prname(i),xx(l),work(ixnew1+l)
     +                 ,(ksym,ii=1,10)
900   continue
c
6100  do 910 i=1,n
         itang(i)=1
         if (icons(i).ne.0) itang(i)=0
910   continue
c
      go to 22
800   l=0 
      do 20 i=1,npar
         if (noyes(i).eq.0) go to 20
         l=l+1
         xx(l)=init(l)*xin(l)
         if (init(l).eq.0.0d0) xx(l)=XIN(l)
20    continue
c
21    format(1x,a1,a8,'=',1pg15.6,5x,' WEIGHT=',1pg15.6,10a1)
22    call tfun1(xx,ff,3)
      isum=0
      istop=0
c---------------------------------------------------------------------
c     calculate residuals
c---------------------------------------------------------------------
      do 30 i=1,m
         if(inflag.ne.0) ores(i)=ff(i)
         l=i
         call users(2,l)
         ksym=' '
         if(dabs(val).gt.tolr(i)) go to 35
         isum=isum+1
         ksym='*'
35       residl(i)=val
         val=val/dsqrt(weight(i))
         val=val*1d2
         ffsens(i)=val
30    continue
c
31    format(1X,'F(',i4,')=',1PG15.6,' TRGT(',i4,')=',G15.6,
     +      a1,' (%)NORMALERR =',G14.6)
      if(isum.ge.m   ) istop=optflg
      inflag=0
91    format(' ')
      return
      end
      subroutine filrea(infile)
c
c     Date Code  Jan 10,1982
c--------------------------------------------------------------------
c
c     read the input and the data file
c
c     Original : Kyr. Doganis                  Aug 1981 at Stanford
c     Mod # 1  : kyr. Doganis                  Nov 1981 at Stanford
c     Mod # 2  : kyr. Doganis                  Jan 1982 at Xerox
c
c---------------------------------------------------------------------
c
c     Common Area 
c---------------------------------------------------------------------
c
	include 'parsize.f'
c     parameter invar
c
      integer ttyw,ttyr
      common /termin/ luout,luinf,luopt,ttyw,ttyr,icont,iauto
c
      integer optflg
      character*2 k
      common /jpar/ m,n,nsig,maxfn,infer,ier,optflg,
     +       ibad,icount,idelx1,idelxl,idelxu,ieval,ifml,ifml1,ifpl,
     +       ifpl1,ifpu,igrad1,igradl,igradu,ijac,iscal1,iscall,iscalu,
     +       isw,iter,ixbad1,ixnew1,ixnewl,j,istop,inflag,
     +       icnst,kvk,kvkold,iterr,nvar,npar,iweigs,k
c
      double precision eps,delta,parm1,parm2,parm3,parm4,ssq,ax,
     +               al,cons2,delta2,erl2,erl2x,f0,f0sq,f0sqs4,g,val,
     +               hh,onesf0,prec,rel,relcon,sqdif,ssqold,up,xhold,
     +               bigtrg,smltrg
      common /xpar/   eps,delta,parm1,parm2,parm3,parm4,ssq,ax,
     +               al,cons2,delta2,erl2,erl2x,f0,f0sq,f0sqs4,g,val,
     +               hh,onesf0,prec,rel,relcon,sqdif,ssqold,up,xhold,
     +               bigtrg,smltrg
c
      double precision xjac,xjtj
      common /jac/ xjac(ijdim),xjtj(ijTdim)
c
      double precision x,f
      common /xf/ x(ixdim),f(ifdim)
c
      double precision work
      common /work/ work(iwkdim)
c
      common /cstr/ icons(ixdim),icold(ixdim),
     +              itang(ixdim),itold(ixdim)
c
      double precision xx,ff
      common /xxff/ xx(ixdim),ff(ifdim)
c
      double precision init,uprb,lowb,tolr,trgt,ores,weight
      common /incond/ init(ixdim),uprb(ixdim),lowb(ixdim),
     +        tolr(ifdim),trgt(ifdim),ores(ifdim),weight(ifdim)
c
      double precision initkp,uprbkp,lowbkp,tolrkp,trgtkp,weigkp
      common /inkeep/ initkp(ixdim),uprbkp(ixdim),lowbkp(ixdim),
     +                tolrkp(ifdim),trgtkp(ifdim),weigkp(ifdim)
c
      common /yesno/ noyes(ixdim),next,mkeep,inext,ntimes
c
      double precision v,vkp
      common /vars/ v(ifdim,invar),vkp(ifdim,invar)
c
      common /iproc/ iprocd(ixdim,10)
      common /nfile/ nfiles
c
c--------------------------------------------------------------------
c        local and common block with the idfun subroutine
c--------------------------------------------------------------------
       character*8 idfunc
       common /idfu/ idfunc
       character*8 fname1,fname2,fname3,fname4
       common /fnames/ fname1,fname2(10),fname3,fname4
       double precision trgti
       character*80 a,word
       character*1 iblank,id1,id2,id3,id4
       character*40 word1(50)
       double precision var(4),xvar,aa,bb
       integer ivdsho,ivgsho,ivbsho
       character short*1,filesh*8
       double precision  vdmin,vdmax,vdincr,vdshor
       double precision  vgmin,vgmax,vgincr,vgshor
       double precision  vbmin,vbmax,vbincr,vbshor
       common /datsho/ vdmin,vdmax,vdincr,vdshor(200),
     +                   vgmin,vgmax,vgincr,vgshor(100),
     +                   vbmin,vbmax,vbincr,vbshor(100)
       common /idtsho/ ivdsho,ivgsho,ivbsho,iweigh
       data iblank/' '/,id1/' '/,id2/','/,id3/'='/,id4/'/'/
c--------------------------------------------------------------------
c    get the name of the function  
c    and also some parameters already prespesified
c--------------------------------------------------------------------
      go to (1,150,600,700),infile
1     call tfun1(xx,ff,1)
      if (next.eq.0) go to 5
      write(ttyw,6)
6     format('       Re-Initialize the parameters ? [y/n]',$)
      read(ttyr,10101) k
10101 format(a2)
      if (k.ne.'y'.and.k.ne.'Y') go to 150
      rewind 10
      go to 50
c--------------------------------------------------------------
c     initial estimates file
c--------------------------------------------------------------
5     write(ttyw,10)
10    format(' Enter the name of the INITIAL ESTIMATES file (8 char) '
     +,$)
      read(ttyr,110) fname1
110   format(a)
c--------------------------------------------------------------
c     number of data files 
c--------------------------------------------------------------
      write(ttyw,13)
13    format(' How many files to be read sequentially ? ',$)
      read(ttyr,*) nfiles
c--------------------------------------------------------------
c     read the data files sequentially
c--------------------------------------------------------------
      do 111 i=1,nfiles
         write(ttyw,11) i
11       format(' Enter the name of the DATA file ',i2,' (8 char) ',$)
         read(ttyr,110) fname2(i)
111   continue
c--------------------------------------------------------------
c     give the name of the options file
c--------------------------------------------------------------
      write(ttyw,6020)
6020  format(' Enter the name of the OPTIONS  file (8 char) ',$)
      read(ttyr,110) fname4
c--------------------------------------------------------------
c     read the options file for both cases
c--------------------------------------------------------------
      call select(fname4)
c
      if (iauto.eq.0) go to 6100
c--------------------------------------------------------------
c     automated version
c--------------------------------------------------------------
c
c--------------------------------------------------------------
c     give the strastegy filename
c--------------------------------------------------------------
      write(ttyw,6010)
6010  format(' Enter the name of the STRATEGY  file (8 char) ',$)
      read(ttyr,110) fname3
c--------------------------------------------------------------
c     write out the filenames for inspection
c--------------------------------------------------------------
      if (luout.ne.11)  then
       write(luout,6030) char(12),idfunc,fname1,fname3,fname4
       write(luout,2123) (fname2(k1),k1=1,nfiles)
       endif
      write(ttyw,6030) char(12),idfunc,fname1,fname3,fname4
      write(ttyw,2123) (fname2(k1),k1=1,nfiles)
6030  format(a,/' MODEL used for the extraction .......:  ',a,/
     +          ' INPUT file name .....................:  ',a,/
     +          ' STRATEGY file name ..................:  ',a,/
     +          ' OPTIONS file name ...................:  ',a,/)
      go to 700
c--------------------------------------------------------------
c     manual version
c--------------------------------------------------------------
6100  write(ttyw,1110)
1110  format(/,' Select the data Manually / from Options file  [m/o] ..
     +. ',$)
      read(ttyr,110) short
      if (short.eq.'m'.or.short.eq.'M') go to 1125
      if (short.ne.'o'.and.short.ne.'O') go to 6100
      iweigs=iweigh
      go to 1190
c--------------------------------------------------------------
c     take care of vds
c--------------------------------------------------------------
1125  write(ttyw,1130) 
1130  format(' Give the VDS [vdmin,vdmax,vdincr] ? .... ',$)
      read(ttyr,*) vdmin,vdmax,vdincr
      aa=dmin1(vdmin,vdmax)
      bb=dmax1(vdmin,vdmax)
      vdmin=aa
      vdmax=bb
      vdincr=dabs(vdincr)
      xvar=vdmin
      ivdsho=0
1140  ivdsho=ivdsho+1
      if (vdincr.lt.1.0d-22) go to 1145
      vdshor(ivdsho)=xvar
      xvar=xvar+vdincr
      if (xvar.lt.vdmax+0.001d0) go to 1140
c--------------------------------------------------------------
c     take care of vg
c--------------------------------------------------------------
1145  if (nvar.lt.2) go to 1190
      write(ttyw,1150) 
1150  format(' Give the VGS [vgmin,vgmax,vgincr] ? .... ',$)  
      read(ttyr,*) vgmin,vgmax,vgincr
      aa=dmin1(vgmin,vgmax)
      bb=dmax1(vgmin,vgmax)
      vgmin=aa
      vgmax=bb
      vgincr=dabs(vgincr)
      xvar=vgmin
      ivgsho=0
1160  ivgsho=ivgsho+1
      if (vgincr.lt.1.0d-22) go to 1165
      vgshor(ivgsho)=xvar
      xvar=xvar+vgincr
      if (xvar.lt.vgmax+0.001d0) go to 1160     
c--------------------------------------------------------------
c     take care of vb
c--------------------------------------------------------------
1165  if (nvar.lt.3) go to 1190
      write(ttyw,1170) 
1170  format(' Give the VBS [vbmin,vbmax,vbincr] ? .... ',$)  
      read(ttyr,*) vbmin,vbmax,vbincr
      aa=dmin1(vbmin,vbmax)
      bb=dmax1(vbmin,vbmax)
      vbmin=aa
      vbmax=bb
      vbincr=dabs(vbincr)
      xvar=vbmin
      ivbsho=0
1180  ivbsho=ivbsho+1
      if (vbincr.lt.1.0d-22) go to 1190
      vbshor(ivbsho)=xvar
      xvar=xvar+vbincr
      if (xvar.lt.vbmax+0.001d0) go to 1180     
1190  continue
c--------------------------------------------------------------------
c    write out the input file and the title of the program
c--------------------------------------------------------------------
      if (luout.ne.11) write (luout,20)  char(12),idfunc,fname1,fname4
      if (luout.ne.11) write (luout,2123) (fname2(k1),k1=1,nfiles)
      write(ttyw,20)  char(12),idfunc,fname1,fname4
      write(ttyw,2123) (fname2(k1),k1=1,nfiles)
20    format(a,/' MODEL used for the extraction .......:  ',a,/
     +          ' INPUT file name .....................:  ',a,/
     +          ' OPTIONS file name ...................:  ',a)
2123  format(' DATA file name ......................:  ',a)
700   open(unit=9,status='old',file=fname1)
c--------------------------------------------------------------------
c      get the (init lowb uprb )keep for later use
c      also noyes=(1,0) for(optimizable,not optimizable)parameter
c--------------------------------------------------------------------
50    if (npar.le.ixdim) go to 51
      write(ttyw,52) 
52    format ('  ERROR Npar > ixdim')
      stop
51    n=0
c--------------------------------------------------------------
c     this  reads in free format data and 
c     finds the initial low and upper bounds of the 
c     initial estimates file
c     read in the next line of data (80 columns)
c--------------------------------------------------------------
      iicoun=1
4300  initkp(iicoun)=0.0d0
      lowbkp(iicoun)=0.0d0
      uprbkp(iicoun)=0.0d0
4320  continue
      read(9,4500,err=1000,end=140) a
4500  format(a)
      if (a(1:1).eq.'*') go to 4320
c--------------------------------------------------------------
c     dig out and identify the parameter values
c--------------------------------------------------------------
      iflag=0
      ipoint=1
4600  call parse(a,word,ipoint,id1,id2)
      word1(iicoun)=word(1:8)
      imatch=0
4620  call parse(a,word,ipoint,id1,id2)
4501  format(x,2a)
      call decode(word,xvar,fname1)
      imatch=imatch+1
      var(imatch)=xvar
      iflag=1
      if(ipoint.lt.81) go to 4620
c--------------------------------------------------------------
c     store the naked data on the output file
c--------------------------------------------------------------
      if(iflag.eq.0) go to 4300
      initkp(iicoun)=var(1)
      lowbkp(iicoun)=var(2)
      uprbkp(iicoun)=var(3)
      noyes(iicoun)=0
      iicoun=iicoun+1
      iflag=0
      go to 4300
c
1000  write(ttyw,1100)
1100  format(1x,'error in reading data')
      stop
140   continue
      close(unit=9)
      if ((iicoun-1).ne.npar) write(ttyw,1200)iicoun,npar
1200  format(' ERROR iicoun # npar ',2i8)
      if (infile.eq.4) return
      if (iauto.eq.0) go to 150
c---------------------------------------------------------------------
c      Automated version 
c---------------------------------------------------------------------
c
c---------------------------------------------------------------------
c      take care of the strategy file
c---------------------------------------------------------------------
       open(unit=9,status='old',file=fname3)
       i=0
6250   read(9,4500,err=1000,end=6200) a
       if (a(1:1).eq.'*') go to 6250
       i=i+1
       ipoint=1
       call parse(a,word,ipoint,id1,id2)
       imatch=0
6260   call parse(a,word,ipoint,id1,id2)
       call decode(word,xvar,fname3)
       imatch=imatch+1
       iprocd(i,imatch)=jidnnt(xvar)
       if (ipoint.lt.81) go to 6260
       go to 6250
6200   ntimes=imatch-1
       if (i.eq.npar) go to 6400
       write(ttyw,6201)
6201   format(' E R R O R n(strategy)~n(param) ')
       stop
6400   continue
       close(unit=9)
c---------------------------------------------------------------------
c      take care of the options file
c---------------------------------------------------------------------
       iweigs=iweigh
       short='y'
c
c---------------------------------------------------------------------
c      get the data points
c      define the smltrg=max of trgt<1d8
c      define the bigtrg=max of trgt>1d8
c      read the weights of the data
c--------------------------------------------------------------------
150   i=0
      ikeep=0
      bigtrg=0.0d0
      smltrg=0.0d0
c     if (next.eq.0)   do something
      do 300 ik=1,nfiles
      open(unit=8,status='old',file=fname2(ik))
190   read(8,4500,err=1000) a
      if (a(1:1).eq.'*') go to 190
c--------------------------------------------------------------------
c     for the keywords width/lenght
c     parsing finding = sign
c--------------------------------------------------------------------
      ipoint=1
      call parse(a,word,ipoint,id1,id3)
      ipoint=ipoint+1
      if (ipoint.gt.79) go to 200
c--------------------------------------------------------------------
c     finds the width
c--------------------------------------------------------------------
      call parse(a,word,ipoint,id1,id4)
      call decode(word,xvar,fname2(ik))
      var(1)=xvar
c--------------------------------------------------------------------
c     finds the length
c--------------------------------------------------------------------
      call parse(a,word,ipoint,id1,id4)
      call decode(word,xvar,fname2(ik))
      var(2)=xvar
      i=i+1
      vkp(i,1)=var(2)*1.d30
      vkp(i,2)=var(1)*1.d30
      vkp(i,3)=0.0d0
      trgtkp(i)=1.d-20
      go to 205
200   i=i+1
      read(8,*,end=500) (vkp(i,j),j=1,nvar),trgtkp(i)
      if (nvar.ne.3) call proces(i,j,1)
      if (nvar.eq.1) go to 5290
      if (nvar.eq.2) go to 5190
      do 5100 ishort=1,ivbsho
         if (ivbsho.ne.1) go to 5110
         if (vkp(i,3).lt.vbmin-0.001d0) go to 5100
         if (vkp(i,3).gt.vbmax+0.001d0) go to 5100
         go to 5190
5110     if (dabs(vkp(i,3)-vbshor(ishort)).gt.0.001d0) go to 5100
5190     do 5200 jshort=1,ivgsho
            if (ivgsho.ne.1) go to 5210
            if (vkp(i,2).lt.vgmin-0.001d0) go to 5200
            if (vkp(i,2).gt.vgmax+0.001d0) go to 5200
            go to 5290
5210        if (dabs(vkp(i,2)-vgshor(jshort)).gt.1.d-3) go to 5200
5290        do 5300 kshort=1,ivdsho
               if (ivdsho.ne.1) go to 5310
               if (vkp(i,1).lt.vdmin-0.001d0) go to 5300
               if (vkp(i,1).gt.vdmax+0.001d0) go to 5300
               go to 205
5310           if (dabs(vkp(i,1)-vdshor(kshort)).gt.1.d-3) go to 5300
               go to 205
5300        continue
            i=i-1
            go to 200
5200     continue
         i=i-1
         go to 200
5100  continue
      i=i-1
      go to 200
205   tolrkp(i)=1.d-3
      weigkp(i)=1.d0
      trgt(i)=trgtkp(i)
      tolr(i)=tolrkp(i)
      weight(i)=weigkp(i)
      do 210 j=1,nvar
         v(i,j)=vkp(i,j)
210   continue
      trgti=dabs(trgt(i))
      if (trgti.ge.1.d8) bigtrg=dmax1(bigtrg,trgti)
      if (trgti.lt.1.d8) smltrg=dmax1(smltrg,trgti)
      go to 200
500   close(unit=8)
      if (ikeep+2.eq.i) write(ttyw,503) fname2(ik)
      i=i-1
      ikeep=i
503   format(' * * * * * * * * *  Warning * * * * * * * * ',/,
     +       ' No points have been selected in the file ',a)
300   continue
      next=1
      mkeep=i
      m=mkeep
      if (m.eq.nfiles) go to 600
      if (m.le.ifdim) go to 501
      write(ttyw,502)
502   format(' ERROR m > ifdim ')
      stop
501   bigtrg=1.d-3*bigtrg
      smltrg=1.d-3*smltrg
      if (smltrg.eq.0.0) call users(3,1)
      if (infile.eq.2) return
      call tfun1(xx,ff,2)
      return
600   write(ttyw,504)
504   format(' ********** ERROR ***********',/
     +       ' No points have been selected')
      go to 1125
      end
      subroutine users(ink,l)
c
c     Date Code  Jan 10,1982
c--------------------------------------------------------------------
c
c     users supplied error and deltax calculations
c
c     Original : Kyr. Doganis                  Aug 1981 at Stanford
c     Mod # 1  : kyr. Doganis                  Nov 1981 at Stanford
c     Mod # 2  : kyr. Doganis                  Jan 1982 at Xerox
c
c---------------------------------------------------------------------
c
c     Common Area 
c---------------------------------------------------------------------
c
	include 'parsize.f'
c
      integer ttyw,ttyr
      common /termin/ luout,luinf,luopt,ttyw,ttyr,icont,iauto
c
      integer optflg
      character*2 k
      common /jpar/ m,n,nsig,maxfn,infer,ier,optflg,
     +       ibad,icount,idelx1,idelxl,idelxu,ieval,ifml,ifml1,ifpl,
     +       ifpl1,ifpu,igrad1,igradl,igradu,ijac,iscal1,iscall,iscalu,
     +       isw,iter,ixbad1,ixnew1,ixnewl,j,istop,inflag,
     +       icnst,kvk,kvkold,iterr,nvar,npar,iweigs,k
c
      double precision eps,delta,parm1,parm2,parm3,parm4,ssq,ax,
     +               al,cons2,delta2,erl2,erl2x,f0,f0sq,f0sqs4,g,val,
     +               hh,onesf0,prec,rel,relcon,sqdif,ssqold,up,xhold,
     +               bigtrg,smltrg
      common /xpar/   eps,delta,parm1,parm2,parm3,parm4,ssq,ax,
     +               al,cons2,delta2,erl2,erl2x,f0,f0sq,f0sqs4,g,val,
     +               hh,onesf0,prec,rel,relcon,sqdif,ssqold,up,xhold,
     +               bigtrg,smltrg
c
      double precision xjac,xjtj
      common /jac/ xjac(ijdim),xjtj(ijTdim)
c
      double precision x,f
      common /xf/ x(ixdim),f(ifdim)
c
      double precision work
      common /work/ work(iwkdim)
c
      common /cstr/ icons(ixdim),icold(ixdim),
     +              itang(ixdim),itold(ixdim)
c
      double precision xx,ff
      common /xxff/ xx(ixdim),ff(ifdim)
c
      double precision init,uprb,lowb,tolr,trgt,ores,weight
      common /incond/ init(ixdim),uprb(ixdim),lowb(ixdim),
     +        tolr(ifdim),trgt(ifdim),ores(ifdim),weight(ifdim)
c
      double precision valweg
      common /valwei/ valweg(ifdim)
c
c--------------------------------------------------------------------
c      local variables
c--------------------------------------------------------------------
      double precision xdabs,trg
      double precision aa,bb,cc
c--------------------------------------------------------------------
      go to (10,20,30,10),ink
c--------------------------------------------------------------------
c     user's specified hh/deltax for the 
c     jacobian calculations
c--------------------------------------------------------------------
 10   continue
c     xdabs=dabs(x(l))
c     hh=rel*dmax1(xdabs,ax)
c     return
      xdabs=dabs(work(idelx1+l))
c     hh=dmax1(0.1d0*relcon,xdabs)
      hh=dmax1(0.01d0*relcon,xdabs)
c     hh=dmin1(rel,hh)
      hh=dmin1(0.1d0*rel,hh)
      if (init(l).eq.0.0d0) hh=0.01d0*hh
c     if (init(l).ne.0.0d0) hh=0.1d0*hh/init(l)
      if (iterr.ne.0) hh=rel
      if (l.eq.n) iterr=0
      if (ink.eq.4) go to 45
      return
c--------------------------------------------------------------------
c     now lets define the error
c---------------------------------------------------------------------
20    continue
      trg=smltrg
      if (dabs(trgt(l)).ge.1d8) trg=bigtrg
      valweg(l)=(ff(l)-trgt(l))/dmax1(dabs(trgt(l)),trg)
      val=dsqrt(weight(l))*valweg(l)
c     val=dsqrt(weight(l))*(ff(l)-trgt(l))/trgt(l)
      return
30    continue
      smltrg=1d-5
      return
c--------------------------------------------------------------------
c     users input of hh
c--------------------------------------------------------------------
45    aa=dabs(x(l))
      bb=dabs(work(idelx1+l))
       write(ttyw,41) aa,bb,hh
41    format(10x,'x=',1pg15.6,x,'delx=',1pg15.6,x,'hh=',1pg15.6,
     +       2x,'.....Change hh [c] ',$)
      read(ttyr,10101) k
10101 format(a2)
      if (k.ne.'c'.and.k.ne.'C') return
      write(ttyw,42)
42    format(20x,'---------> input your value _',$)
      read(ttyr,*) hh
      return
      end
        subroutine TOPTR
c
c     Date Code  Jan 10,1982
c--------------------------------------------------------------------
c
c     the main optimization routine
c
c     Original : Kyr. Doganis                  Aug 1981 at Stanford
c     Mod # 1  : kyr. Doganis                  Nov 1981 at Stanford
c     Mod # 2  : kyr. Doganis                  Jan 1982 at Xerox
c
c---------------------------------------------------------------------
c
c     Common Area 
c---------------------------------------------------------------------
c
	include 'parsize.f'
c---------------------------------------------------------------------
c
      integer ttyw,ttyr
      common /termin/ luout,luinf,luopt,ttyw,ttyr,icont,iauto
c
      integer optflg
      character*2 k
      common /jpar/ m,n,nsig,maxfn,infer,ier,optflg,
     +       ibad,icount,idelx1,idelxl,idelxu,ieval,ifml,ifml1,ifpl,
     +       ifpl1,ifpu,igrad1,igradl,igradu,ijac,iscal1,iscall,iscalu,
     +       isw,iter,ixbad1,ixnew1,ixnewl,j,istop,inflag,
     +       icnst,kvk,kvkold,iterr,nvar,npar,iweigs,k
c
      double precision eps,delta,parm1,parm2,parm3,parm4,ssq,ax,
     +               al,cons2,delta2,erl2,erl2x,f0,f0sq,f0sqs4,g,val,
     +               hh,onesf0,prec,rel,relcon,sqdif,ssqold,up,xhold,
     +               bigtrg,smltrg
      common /xpar/   eps,delta,parm1,parm2,parm3,parm4,ssq,ax,
     +               al,cons2,delta2,erl2,erl2x,f0,f0sq,f0sqs4,g,val,
     +               hh,onesf0,prec,rel,relcon,sqdif,ssqold,up,xhold,
     +               bigtrg,smltrg
c
      double precision xjac,xjtj
      common /jac/ xjac(ijdim),xjtj(ijtdim)
c
      double precision x,f
      common /xf/ x(ixdim),f(ifdim)
c
      double precision work
      common /work/ work(iwkdim)
c
      common /cstr/ icons(ixdim),icold(ixdim),
     +              itang(ixdim),itold(ixdim)
c
      double precision jtjsen,xjacs,grads,delxs
      common /jtjs/ jtjsen(ijtdim),xjacs(ijdim),
     +              grads(ixdim),delxs(ixdim)
c
      double precision wcons,ermax,ermaxa,rms
      double precision xx,ff
      common /xxff/ xx(ixdim),ff(ifdim)
c
      double precision valweg
      common /valwei/ valweg(ifdim)
c
c---------------------------------------------------------------------
c     start of local data
c---------------------------------------------------------------------
c
      double precision dnorm,dsq,rhh,sum,xdif
      double precision sig,p01,tenth,half,zero,one
      double precision onep5,two,ten,huntw,onep10
c
      data sig/4.d0/,ax/0.1d0/,p01/0.01d0/,tenth/0.1d0/,half/0.5d0/
      data zero/0.0d0/,one/1.d0/,onep5/1.5d0/,two/2.d0/,ten/10.d0/
      data huntw/1.2d2/,onep10/1.d10/
c
c---------------------------------------------------------------------
c
c     select proper entry point
c
c---------------------------------------------------------------------
      if (iauto.eq.0) write(ttyw,1)
1     format(' segment toptr')
c---------------------------------------------------------------------
c
c     error checks
c
c---------------------------------------------------------------------
      if (parm2.le.one.or.
     +    parm1.le.zero.or.
     +    m.lt.n.or.
     +    n.eq.0) go to 305
c---------------------------------------------------------------------
c
c     machine dependent constants
c
c---------------------------------------------------------------------
5     prec=ten**(-sig-one)
      rel=ten**(-nsig*half)
      relcon=ten**(-nsig)
c---------------------------------------------------------------------
c
c     work vector is concatenation of scaled hessian, gradient, delx
c     scale, xnew, xbad, f(x+del), f(x-del)
c
c---------------------------------------------------------------------
      igrad1=((n+1)*n)/2
      igradl=igrad1+1
      igradu=igrad1+n
      idelx1=igradu
      idelxl=idelx1+1
      idelxu=idelx1+n
      iscal1=idelxu
      iscall=iscal1+1
      iscalu=iscal1+n
      ixnew1=iscalu
      ixnewl=ixnew1+1
      ixbad1=ixnew1+n
      ifpl1=ixbad1+n
      ifpl=ifpl1+1
      ifpu=ifpl1+m
      ifml1=ifpu
      ifml=ifml1+1
c---------------------------------------------------------------------
c
c     initialize variables
c
c---------------------------------------------------------------------
      al=parm1
      f0=parm2
      up=parm3
      cons2=parm4*half
      onesf0=one/f0
      f0sq=f0*f0
      f0sqs4=f0sq**4
      delta2=delta*half
      erl2=onep10
c
c
      ieval=0
      ibad=-1
      isw=1
      iter=-1
      iterr=-1
      infer=0
      ier=0
c
c
      do 25 j=idelxl,idelxu
         work(j)=zero
25    continue
      go to 163
c---------------------------------------------------------------------
c
c     main loop
c
c---------------------------------------------------------------------
30    ssqold=ssq
c---------------------------------------------------------------------
c
c     calculate jacobian
c
c---------------------------------------------------------------------
      if (icnst.eq.1.or.
     +    infer.gt.0.or.
     +    ijac.ge.n.or.
     +    icount.gt.0) go to 55
c---------------------------------------------------------------------
c
c     rank one update to jacobian
c
c---------------------------------------------------------------------
      if (iauto.eq.0) write(ttyw,88000)
88000 format(' rank one update')
      ijac=ijac+1
      dsq=zero
      ki=0
      do 35 j=idelxl,idelxu
         ki=ki+1
         if (icons(ki).ne.0) go to 35
         dsq=dsq+work(j)*work(j)
35    continue
c
      if(dsq.le.zero) go to 55
c
      do 50 i=1,m
         g=f(i)-work(ifml1+i)
         k1=i
         kii=0
         do 40 j=idelxl,idelxu
            kii=kii+1
            if (icons(kii).ne.0) go to 40
            g=g+xjac(k1)*work(j)
            k1=k1+m
40       continue
         g=g/dsq
         k1=i
         kii=0
         do 45 j=idelxl,idelxu
            kii=kii+1
            if (icons(kii).ne.0) go to 45
            xjac(k1)=xjac(k1)-g*work(j)
            k1=k1+m
45       continue
50    continue
c
      if (kvk.eq.0) go to 80
c
      k1=0
      ii=0
      do 88888 i=1,n
         if (icons(i).ne.0) go to 88888
         ii=ii+1
         sum=zero
         do 8866 j=1,m
            k1=k1+1
            sum=sum+xjac(k1)*f(j)
8866     continue
         work(igrad1+ii)=sum
88888 continue
c
      erl2x=erl2
      erl2=zero
      do 579 i=1,n-kvk
         erl2=erl2+work(igrad1+i)**2
579   continue
c
      erl2=dsqrt(erl2)
      go to 95
c---------------------------------------------------------------------
c
c     jacobian by incrementing x
c
c---------------------------------------------------------------------
55    ik=1
54    ijac=0
      k1=0
      do 75 j=1,n
         l=j
         call users(ik,l)
         xhold=x(j)
         x(j)=x(j)+hh
         optflg=1
         call func1(x,work(ifpl))
         ieval=ieval+1
         if(istop.eq.0) x(j)=xhold
         if(isw.eq.1) go to 65
c--------------------------------------------------------------------
c
c     central differences
c
c---------------------------------------------------------------------
         x(j)=xhold-hh
         optflg=2
         call func1(x,work(ifml))
         ieval=ieval+1
         if(istop.eq.0) x(j)=xhold
         rhh=half/hh
         do 60 i=ifpl,ifpu
            k1=k1+1
            xjac(k1)=(work(i)-work(i+m))*rhh
60       continue
         go to 72
c---------------------------------------------------------------------
c
c     forward differences
c
c---------------------------------------------------------------------
65       rhh=one/hh
         do 70 i=1,m
            k1=k1+1
            xjac(k1)=(work(ifpl1+i)-f(i))*rhh
70       continue
72       if(istop.ne.0.and.j.ne.n) go to 77
         if(istop.ne.0) go to 76
75    continue
c
76    continue
c
77    if(istop.eq.0) go to 80
      do 78 j=1,n
         work(ixnew1+j)=x(j)
78    continue
      go to 215
c---------------------------------------------------------------------
c
c     calculate gradient
c
c---------------------------------------------------------------------
80    k1=0
      l=0
      do 90 j=igradl,igradu
         sum=zero
         do 85 i=1,m
            k1=k1+1
            sum=sum+xjac(k1)*f(i)
            xjacs(k1)=xjac(k1)
85       continue
         work(j)=sum
         l=l+1
         grads(l)=work(j)
90    continue
c---------------------------------------------------------------------
c
c     check if the gradient in tdhe rn space points in or out
c
c---------------------------------------------------------------------
      do 11190 i=1,n
          if (work(igrad1+i).eq.0.0d0) write(ttyw,11193) i
11193     format(/,'   Gradient = 0.0d0 for the ',i2,' parameter ',/
     +             '  The model is independent of this parameter')
          wcons=icons(i)*work(igrad1+i)
          if (luout.ne.11) write(luout,*) icons(i),work(igrad1+i)
          if (wcons.gt.0.0d0) go to 11189
11190 continue
c---------------------------------------------------------------------
c
c     points outwards ....find the tangent subspace and continue
c
c---------------------------------------------------------------------
      do 11192 i=1,n
          itang(i)=1
          if (icons(i).ne.0) itang(i)=0
11192 continue
      if (luout.ne.11) write(luout,11111) (itang(i),i=1,n)
11111 format(' 11192 ',/,(x,i2,x,/))
      go to 11185
c---------------------------------------------------------------------
c
c      points inwards.... let the prob be free to move
c
c---------------------------------------------------------------------
11189 do 11188 i=1,n
          itang(i)=1
          itold(i)=1
          icons(i)=0
          icold(i)=0
11188 continue
c
      kvk=0
      kvkold=0
c---------------------------------------------------------------------
c
c     we have now the tangent space
c     find the djtf ( the confint in this subspace)
c
c---------------------------------------------------------------------
11185 k1=0
      do 11200 i=1,n
         if (itang(i).eq.0) go to 11200
         k1=k1+1
         work(igrad1+k1)=work(igrad1+i)
11200 continue
c      if (luout.ne.11) write(luout,11112) (itang(i),i=1,n)
11112 format(' 11200 ',/,(x,i2,x,/))
c-----------------------------------------------------------------------
c
c     lets estimate the norm of the gradient
c
c-----------------------------------------------------------------------
      erl2x=erl2
      erl2=zero
      do 11300 i=1,n-kvk
         erl2=erl2+work(igrad1+i)**2
11300 continue
c
      erl2=dsqrt(erl2)
c---------------------------------------------------------------------
c
c      now find the djt=js
c
c---------------------------------------------------------------------
      l=0
      k1=0
      do 11400 i=1,n
         do 11500 j=1,m
            k1=k1+1
            if (itang(i).eq.0) go to 11500
            l=l+1
            xjac(l)=xjac(k1)
11500     continue
11400 continue
c      if (luout.ne.11) write(luout,11113) (itang(i),i=1,n)
11113 format(' 11400 ',/,(x,i2,x,/))
c---------------------------------------------------------------------
c
c     convergence test for norm of gradient
c
c---------------------------------------------------------------------
      if(ijac.gt.0) go to 95
94    if(erl2.le.delta2) infer=infer+4
      isw=1
      if(erl2.le.cons2) isw=2
c---------------------------------------------------------------------
c
c     calculate the lower super triangle of
c     jacobian (transposed) * jacobian
c
c---------------------------------------------------------------------
95    l=0
      is=-m
      do 110 i=1,n-kvk
         is=is+m
         js=0
         do 105 j=1,i
            l=l+1
            sum=zero
            do 100 k1=1,m
               li=is+k1
               js=js+1
               sum=sum+xjac(li)*xjac(js)
100         continue
            xjtj(l)=sum
105      continue
110   continue
c---------------------------------------------------------------------
c
c     convergence checks
c
c---------------------------------------------------------------------
      if(infer.gt.0) go to 315
      if(ieval.ge.maxfn) go to 290
c---------------------------------------------------------------------
c
c     compute scaling vector
c
c---------------------------------------------------------------------
      k1=0
      do 115 j=1,n-kvk
         k1=k1+j
         work(iscal1+j)=dsqrt(xjtj(k1))
115   continue
c---------------------------------------------------------------------
c
c     add l-m factor to diagonal
c
c---------------------------------------------------------------------
135   icount=0
140   k1=0
c----------------------------------------------------------------------
c
c     for the first time after the violation set the al to original
c     then let it free
c
c----------------------------------------------------------------------
c      if (icnst.eq.1) al=parm1
      do 150 i=1,n-kvk
         do 145 j=1,i
            k1=k1+1
            work(k1)=xjtj(k1) 
         if (luout.ne.11) write(luout,*) k1,work(k1)
145      continue
         work(k1)=work(k1)+work(iscal1+i)*al
         work(idelx1+i)=work(igrad1+i)
         if (luout.ne.11) write(luout,*) k1,i,work(k1),work(idelx1+i)
150   continue
c
      icnst=0
c---------------------------------------------------------------------
c
c     cholesky decomposition
c
c---------------------------------------------------------------------
155   call lneqs(work,n-kvk,work(idelxl),g,xhold,ier)
      if (luout.ne.11) write(luout,*) (work(idelx1+i),i=1,n-kvk)
      if(ier.eq.0) go to 160
      ier=0
      if(ijac.gt.0) go to 55
      if(ibad.le.0) go to 240
      go to 190
160   if(ibad.ne.-1) ibad=0
c---------------------------------------------------------------------
c
c      find the new delx corresponding in the n space
c
c---------------------------------------------------------------------
       l=n-kvk+1
       do 164 i=1,n
          k1=n-i+1
          if (itang(k1).eq.0) go to 162
          l=l-1
          work(idelx1+k1)=work(idelx1+l)
          go to 164
 162      work(idelx1+k1)=0.0d0
164    continue
c---------------------------------------------------------------------
c
c     calculate sum of squares
c
c---------------------------------------------------------------------
163   do 170 j=1,n
         work(ixnew1+j)=x(j)-work(idelx1+j)
      if (luout.ne.11) write(luout,9898) 
     + icons(j),itang(j),x(j),work(idelx1+j)
9898  format(x,i2,x,i2,2(1pg14.5,x))
170   continue
c
      optflg=3
      call func1(work(ixnewl),work(ifpl))
      if (luout.ne.11) write(luout,*) 
     + (itang(j),icons(j),x(j),work(ixnew1+j),j=1,n)
      ieval=ieval+1
      ssq=zero
      ermax=0.0d0
      ermaxa=0.0d0
      do 175 i=ifpl,ifpu
         ssq=ssq+work(i)*work(i)
         ermax=dmax1(ermax,dabs(valweg(i+1-ifpl)))
         ermaxa=ermaxa+dabs(valweg(i+1-ifpl))
175   continue
      rms=dsqrt(ssq/m)
      ermaxa=100.0d0*ermaxa/m
      ermax=100.0d0*ermax
c
      if(iter.ge.0) go to 185
c---------------------------------------------------------------------
c
c     ssq for initial estimates of x
c
c---------------------------------------------------------------------
      iter=0
      ssqold=ssq
      do 180 i=1,m
         f(i)=work(ifpl1+i)
180   continue
c
      go to 55
c---------------------------------------------------------------------
c
c     check descent property
c
c---------------------------------------------------------------------
185   if(ssq.le.ssqold) go to 205
c---------------------------------------------------------------------
c
c     reset the old constrains and try again
c
c     increase parameter
c
c---------------------------------------------------------------------
190   do 191 i=1,n
         icons(i)=icold(i)
         itang(i)=itold(i)
191   continue
c
      kvk=kvkold
      icount=icount+1
      al=al*f0sq
      if(ijac.eq.0) go to 195
      if(icount.ge.4.or.al.gt.up) go to 200
195   if(al.le.up) go to 140
      if(ibad.eq.1) go to 310
      go to 300
200   al=al/f0sqs4
      go to 55
c---------------------------------------------------------------------
c
c     adjust marquardt parameter
c
c---------------------------------------------------------------------
205   if(icount.eq.0) al=al/f0
      if(erl2x.le.zero) go to 210
      g=erl2/erl2x
      if(erl2.lt.erl2x) al=al*dmax1(onesf0,g)
      if(erl2.gt.erl2x) al=al*dmin1(f0,g)
210   al=dmax1(al,prec)
c---------------------------------------------------------------------
c
c     one iteration cycle completed
c
c---------------------------------------------------------------------
215   if (iauto.eq.1) call printo
      iter=iter+1
      xdif=2.d0*erl2
      write(ttyw,216) iter,ieval,ssq,al,xdif,ermax,ermaxa,rms
      if (luout.ne.11) write(luout,216) 
     +    iter,ieval,ssq,al,xdif,ermax,ermaxa,rms
216   format(' iter=',i3,' eval=',i4,
     +'  ssq=',1pg15.6,'  al=',1pg12.6,
     +'  grad=',1pg14.6/
     +' max err=',0pf10.4,' %',' average err=',0pf10.4,' %',
     +' rms=',g15.6/)
      do 220 j=1,n
         x(j)=work(ixnew1+j)
         icold(j)=icons(j)
         itold(j)=itang(j)
         delxs(j)=work(idelx1+j)
220   continue
      if (kvk.ne.kvkold) icnst=1
      kvkold=kvk
      do 225 i=1,m
         work(ifml1+i)=f(i)
         f(i)=work(ifpl1+i)
225   continue
c---------------------------------------------------------------------
c
c     error bounds convergence test
c
c---------------------------------------------------------------------
      if(istop.eq.0) go to 227
      infer=infer+8
      ssqold=ssq
      go to 315
c---------------------------------------------------------------------
c
c     relative convergence test for x
c
c---------------------------------------------------------------------
227   if(icount.gt.0.or.ijac.gt.0) go to 30
      do 230 j=1,n
         if (itang(j).eq.0) go to 230
         xdif=dabs(work(idelx1+j))/dmax1(dabs(x(j)),ax)
         if(xdif.gt.relcon) go to 235
230   continue
c
      infer=1
c---------------------------------------------------------------------
c
c     relative convergence test for ssq
c
c---------------------------------------------------------------------
235   sqdif=dabs(ssq-ssqold)/dmax1(ssqold,ax)
      if(sqdif.le.eps) infer=infer+2
      if(infer.gt.0) go to 315
      go to 30
c---------------------------------------------------------------------
c
c     singular decomposition
c
c---------------------------------------------------------------------
240   if(ibad) 255,245,280
c---------------------------------------------------------------------
c
c     check to see if current iterate has cycled back to
c     the last singular point
c
c---------------------------------------------------------------------
245   do 250 j=1,n-kvk
         xhold=work(ixbad1+j)
         if(dabs(x(j)-xhold).gt.relcon*dmax1(ax,dabs(xhold))) go to 255
250   continue
c
      go to 295
c---------------------------------------------------------------------
c
c     update the bad x values
c
c---------------------------------------------------------------------
255   do 260 j=1,n-kvk
         work(ixbad1+j)=x(j)
260   continue
c
      ibad=1
c---------------------------------------------------------------------
c
c     replace zeroes on hessian diagonal
c
c---------------------------------------------------------------------
280   izero=0
      do 285 j=iscall,iscalu-kvk
         if(work(j).gt.zero) go to 285
         izero=izero+1
         work(j)=one
285   continue
c
      if(izero.lt.n-kvk) go to 140
      ier=38
      go to 315
c---------------------------------------------------------------------
c
c     terminal errors
c
c---------------------------------------------------------------------
290   ier=ier+1
295   ier=ier+1
300   ier=ier+1
305   ier=ier+1
310   ier=ier+129
      if(ier.eq.130) go to 9000
c---------------------------------------------------------------------
c
c     output erl2,ieval,nsig,al, and iter
c
c---------------------------------------------------------------------
315   work(1)=erl2+erl2
      work(2)=ieval
      ssq=ssqold
      g=sig
      do 320 j=1,n
         xhold=dabs(work(idelx1+j))
         if(xhold.le.zero) go to 320
         g=dmin1(g,-dlog10(xhold/dmax1(ax,dabs(x(j)))))
320   continue
c
      work(3)=g
      work(4)=al
      work(5)=iter
c
      if (luout.ne.11) write(luout,7001) 
     + char(12),ssq,work(1),al,nsig,ieval,iter
      if (iauto.eq.0)
     +write(ttyw,7001) char(12),ssq,work(1),al,nsig,ieval,iter
7001  format(a,/5x,'minimization results'//
     +       10x,'residual sum of squares     =',1pg14.6/
     +       10x,'norm of the gradient',8x,'=',1pg14.6/
     +       10x,'marquardt scaling parameter =',1pg14.6/
     +       10x,'no. of significant digits   =',0pi9/
     +       10x,'no. of function evaluations =',0pi9/
     +       10x,'no. of iterations',11x,'=',0pi9)
c---------------------------------------------------------------------
c
c     termination message section
c
c---------------------------------------------------------------------
7777  continue
      if (luout.ne.11) write(luout,8001)
      if (iauto.eq.0) write(ttyw,8001)
      j1=mod(infer,2)
      j3=infer/2
      j2=mod(j3,2)
      j5=j3/2
      j4=mod(j5,2)
      j8=j5/2
      if(infer.eq.0.and.luout.ne.11) write(luout,8010)
      if (infer.eq.0.and.iauto.eq.0) write(ttyw,8010)
      if(j1.ne.0.and.luout.ne.11) write(luout,8011) nsig
      if (j1.ne.0.and.iauto.eq.0) write(ttyw,8011) nsig
      if(j2.ne.0.and.luout.ne.11) write(luout,8012) eps
      if (j2.ne.0.and.iauto.eq.0) write(ttyw,8012) eps
      if(j4.ne.0.and.luout.ne.11) write(luout,8014) delta
      if (j4.ne.0.and.iauto.eq.0) write(ttyw,8014) delta
      if(j8.ne.0.and.luout.ne.11) write(luout,8018)
      if (j8.ne.0.and.iauto.eq.0) write(ttyw,8018)
8001  format(/5x,'termination criteria'/)
8010  format(10x,'convergence failed'/)
8011  format(10x,'on two succesive iterations the parameter estimates ',
     +'agree,'/10x,'component by component, to nsig (',i3,') digits.'/)
8012  format(10x,'on two succesive iterations the residual sum of squa',
     +'res'/10x,'estimates have relative difference less than or equal',
     +' to'/10x,'eps (',1pg14.6,').')
8014  format(10x,'the euclidean norm of the approximate gradient is le',
     +'ss'/10x,'than or equal to delta (',1pg14.6,').')
8018  format(10x,'the sum of the squares of residuals is zero.'
     +/10x,'all target values are within error bounds.')
      if(ier.eq.0) go to 9999
c---------------------------------------------------------------------
c
c     error message section
c
c---------------------------------------------------------------------
9000  continue
      if (luout.ne.11) write(luout,9001)
      if (iauto.eq.0) write(ttyw,9001)
      if (luout.ne.11) write(luout,9002)
      if (iauto.eq.0) write(ttyw,9002)
      if(ier.eq.38.and.luout.ne.11) write(luout,9038)
      if (ier.eq.38.and.iauto.eq.0) write(ttyw,9038)
      if(ier.eq.129.and.luout.ne.11) write(luout,9129)
      if (ier.eq.129.and.iauto.eq.0) write(ttyw,9129)
      if(ier.eq.130.and.luout.ne.11) write(luout,9130) m,n,parm1,parm2
      if (ier.eq.130.and.iauto.eq.0) write(ttyw,9130) m,n,parm1,parm2
      if(ier.eq.131.and.luout.ne.11) write(luout,9131) al,parm3
      if (ier.eq.131.and.iauto.eq.0) write(ttyw,9131) al,parm3
      if(ier.eq.132.and.luout.ne.11) write(luout,9132)
      if (ier.eq.132.and.iauto.eq.0) write(ttyw,9132)
      if(ier.eq.133.and.luout.ne.11) write(luout,9133) maxfn
      if (ier.eq.133.and.iauto.eq.0) write(ttyw,9133) maxfn
      if (luout.ne.11) write(luout,9001)
      write(ttyw,9001)
9001  format(1x,72('*'))
9002  format(/5x,'error condition:'/)
9038  format(10x,'the jacobian is zero. the solution x is a stationary',
     +' point.')
9129  format(10x,'a singularity was detected in the jacobian and recov',
     +'ery failed.')
9130  format(10x,'at least one of the following was specified incorrec',
     +'tly'/10x,'m      (',i14,')'/10x,'n      (',i14,')'/
     +10x,'parm1 (',1pg14.6,')'/10x,'parm2 (',1pg14.6,')'
     +'fied'/10x,'incorrectly.')
9131  format(10x,'the marquardt parameter (',1pg14.6,') exceeded'/10x,
     +'parm3 (',1pg14.6,').')
9132  format(10x,'after a succesful recovery from a singular jacobian,',
     +/10x,'the vector x has cycled back to the first singularity.')
9133  format(10x,'the maximum number of function evaluations (',i6,')',
     +'was',/10x,'exceeded.')
c---------------------------------------------------------------------
c
c     normal exit
c
c---------------------------------------------------------------------
9999  optflg=4
      return
      end
      subroutine LNEQS(a,n,b,d1,d2,ier)
c
c     Date Code  Jan 10,1982
c--------------------------------------------------------------------
c
c     solution of linear equations
c
c     Original : Kyr. Doganis                  Aug 1981 at Stanford
c     Mod # 1  : kyr. Doganis                  Nov 1981 at Stanford
c     Mod # 2  : kyr. Doganis                  Jan 1982 at Xerox
c
c---------------------------------------------------------------------
c
c     Common Area 
c---------------------------------------------------------------------
c
      double precision a(1),b(1),d1,d2
c---------------------------------------------------------------------
c
c     initialize ier
c
c---------------------------------------------------------------------
      ier=0
c---------------------------------------------------------------------
c
c     decompose a
c
c---------------------------------------------------------------------
      call ludec(a,a,n,d1,d2,ier)
      if(ier.ne.0) go to 9005
c---------------------------------------------------------------------
c
c     perform elimination
c
c---------------------------------------------------------------------
      call luelm(a,b,n,b)
9005  return
      end
      subroutine LUDEC(a,ul,n,d1,d2,ier)
c
c     Date Code  Jan 10,1982
c--------------------------------------------------------------------
c
c     LU decomposition of a matrix
c
c     Original : Kyr. Doganis                  Aug 1981 at Stanford
c     Mod # 1  : kyr. Doganis                  Nov 1981 at Stanford
c     Mod # 2  : kyr. Doganis                  Jan 1982 at Xerox
c
c---------------------------------------------------------------------
c
c     Common Area 
c---------------------------------------------------------------------
c
      double precision a(1),ul(1)
      double precision d1,d2,zero,one,four,sixtn,sixth,x,rn
c
      data zero/0.d0/,one/1.d0/,four/4.d0/,sixtn/16.d0/,sixth/.0625d0/
c---------------------------------------------------------------------
c
c     start ludec
c
c---------------------------------------------------------------------
      d1=one
      d2=zero
      rn=one/(n*sixtn)
      ip=1
      ier=0
      do 45 i=1,n
         iq=ip
         ir=1
         do 40 j=1,i
            x=a(ip)
            if(j.eq.1) go to 10
            do 5 k=iq,ip1
               x=x-ul(k)*ul(ir)
               ir=ir+1
5           continue
10          if(i.ne.j) go to 30
            d1=d1*x
            if(a(ip)+x*rn.le.a(ip)) go to 50
15          if(dabs(d1).le.one) go to 20
            d1=d1*sixth
            d2=d2+four
            go to 15
20          if(dabs(d1).ge.sixth) go to 25
            d1=d1*sixtn
            d2=d2-four
            go to 20
25          ul(ip)=one/dsqrt(x)
            go to 35
30          ul(ip)=x*ul(ir)
35          ip1=ip
            ip=ip+1
            ir=ir+1
40       continue
45    continue
c
      go to 9005
50    ier=129
9005  return
      end
      subroutine LUELM(a,b,n,x)
c
c     Date Code  Jan 10,1982
c--------------------------------------------------------------------
c
c     elimination part of the solution AX=B
c
c     Original : Kyr. Doganis                  Aug 1981 at Stanford
c     Mod # 1  : kyr. Doganis                  Nov 1981 at Stanford
c     Mod # 2  : kyr. Doganis                  Jan 1982 at Xerox
c
c---------------------------------------------------------------------
c
c     Common Area 
c---------------------------------------------------------------------
c
      double precision a(1),b(1),x(1),t,zero
c
c---------------------------------------------------------------------
c
c     solution of ly = b
c
c---------------------------------------------------------------------
      ip=1
      iw=0
      do 15 i=1,n
         t=b(i)
         im1=i-1
         if (iw.eq.0) go to 9
         ip=ip+iw-1
         do 5 k=iw,im1
            t=t-a(ip)*x(k)
            ip=ip+1
5        continue
         go to 10
9        if(t.ne.0.0) iw=i
         ip=ip+im1
10       x(i)=t*a(ip)
         ip=ip+1
15    continue
c---------------------------------------------------------------------
c
c     solution of ux = y
c
c---------------------------------------------------------------------
      n1=n+1
      do 30 i=1,n
         ii=n1-i
         ip=ip-1
         is=ip
         iq=ii+1
         t=x(ii)
         if(n.lt.iq) go to 25
         kk=n
         do 20 k=iq,n
            t=t-a(is)*x(kk)
            kk=kk-1
            is=is-kk
20       continue
25       x(ii)=t*a(is)
30    continue
      return
      end
      subroutine SENSIT
c
c     Date Code  Jan 10,1982
c--------------------------------------------------------------------
c
c     calculation of the sensitivity of the parameters
c
c     Original : Kyr. Doganis                  Aug 1981 at Stanford
c     Mod # 1  : kyr. Doganis                  Nov 1981 at Stanford
c     Mod # 2  : kyr. Doganis                  Jan 1982 at Xerox
c
c---------------------------------------------------------------------
c
c     Common Area 
c---------------------------------------------------------------------
c
	include 'parsize.f'
c
      integer ttyw,ttyr
      common /termin/ luout,luinf,luopt,ttyw,ttyr,icont,iauto
c
      integer optflg
      character*2 k
      common /jpar/ m,n,nsig,maxfn,infer,ier,optflg,
     +       ibad,icount,idelx1,idelxl,idelxu,ieval,ifml,ifml1,ifpl,
     +       ifpl1,ifpu,igrad1,igradl,igradu,ijac,iscal1,iscall,iscalu,
     +       isw,iter,ixbad1,ixnew1,ixnewl,j,istop,inflag,
     +       icnst,kvk,kvkold,iterr,nvar,npar,iweigs,k
c
      double precision x,f
      common /xf/ x(ixdim),f(ifdim)
c
      integer nv,nm,ierr
      common /isens/ nv,nm,ierr
c
      double precision jtjsen,xjacs,grads,delxs
      common /jtjs/ jtjsen(ijtdim),xjacs(ijdim),
     +               grads(ixdim),delxs(ixdim)
c
      double precision jtsens,egval,egvec,egvlmx,egvlmn,
     +                 cndnum,cndvct
      common /sens/ jtsens(ijtdim),egval(ixdim),
     +              egvec(ixdim,ixdim),egvlmx,egvlmn,cndnum,cndvct
c
      double precision init,uprb,lowb,tolr,trgt,ores,weight
      common /incond/ init(ixdim),uprb(ixdim),lowb(ixdim),
     +        tolr(ifdim),trgt(ifdim),ores(ifdim),weight(ifdim)
c
      character*8 prname
      common /pnames/ prname(ixdim)
c
      common /yesno/ noyes(ixdim),next,mkeep,inext,ntimes
c-----------------------------------------------------------------
c     local variables
c-----------------------------------------------------------------
      double precision deltas,projs(ixdim,ixdim),delgrd(ifdim)
      double precision delf(ixdim),jprojs(ifdim,ixdim)
      double precision sum,sum1,gradst,dum,dum1,dum2,dumsum
      double precision df,dx
      double precision jptjps(ixdim),delftl(ifdim)
c-----------------------------------------------------------------
c     take the jacobian elements and construct the lower triagle
c     of the jtj for the calculation of the sensitivities
c----------------------------------------------------------------
      l=0
      is=-m
      do 10 i=1,n
         is=is+m
         js=0
	 do 50 j=1,i
	    l=l+1
	    sum=0.0d0
	    do 20 k1=1,m
	       li=is+k1
	       js=js+1
	       sum=sum+xjacs(li)*xjacs(js)
   20      continue
	 jtjsen(l)=sum
         jtsens(l)=sum
  50    continue
10    continue
c--------------------------------------------------------------
c      start the program of calculating the eigenvalues and 
c      the eigenvectors
c-------------------------------------------------------------
       nv=n*(n+1)/2
       call eigen
       write(ttyw,60) (i,egval(i),i=1,n)
60     format(' eigenvalue(',i3,')=  ',1pg15.6)
c      write(ttyw,70) ((i,j,egvec(i,j),i=1,n),j=1,n)
70     format(' eigenvector(',i3,',',i3,')= ',1pg12.4)
       egvlmx=egval(1)
       egvlmn=egval(1)
       do 100 i=1,n
          egvlmx=dmax1(egvlmx,egval(i))
          if (egvlmx.eq.egval(i)) imax=i
          egvlmn=dmin1(egvlmn,egval(i))
          if (egvlmn.eq.egval(i)) imin=i
100    continue
c
       if (egvlmn.eq.0.0d0) go to 1000
       cndnum=egvlmx/egvlmn
       write(ttyw,110) cndnum,imax,egvlmx,imin,egvlmn
110    format(/' condition number =',1pg12.4,/
     +' max eigenvalue(',i3,')=',1pg12.4,/
     +' min eigenvalue(',i3,')=',1pg12.4/)
      if (cndnum.le.0.0) go to 1000
      cndvct=dsqrt(cndnum)
      write(ttyw,310) cndvct
310   format(' max eigvct/min eigvct =',1pg15.6,/)
c-------------------------------------------------------------
c
c
c
c
c
c
c
c
c 
         k1=0
         if (k1.eq.0) return
c
c
c
c
c
c
c
c
c     find the min increment of idelx
c-------------------------------------------------------------
      deltas=dabs(delxs(1))
      do 200 i=1,n
         deltas=dmin1(deltas,dabs(delxs(i)))
200   continue
c-------------------------------------------------------------
c     now confind deltas in the interval 1d-2,1d-4
c-------------------------------------------------------------
      deltas=dmin1(deltas,1.0d-2)
      deltas=dmax1(deltas,1.0d-4)
      do 230 j=1,n
         do 240 i=1,n
            projs(i,j)=init(i)*deltas*egvec(i,j)
 240     continue
230   continue
c-- - - - - - -- - - - - - -
      k1=0
      i=0
      do 700 ii=1,npar
         if (noyes(ii).eq.0) go to 700
         i=i+1
         dumsum=0.0d0
         dum=init(i)*dabs(delxs(i))*0.01d0
         do 710 j=1,m
            k1=k1+1
            dum1=xjacs(k1)*f(j)
            dum2=xjacs(k1)*xjacs(k1)
c           dumsum=dumsum+2.0d0*dum1+dum*dum2
            dumsum=dumsum+dum2*dum
710      continue
         df=dum*dumsum
c        dx=100.0d0*deltas/dabs(delxs(i))
         dx=1.00d0
         write(ttyw,711) dx,prname(ii),df
         if (luout.ne.11) write(luout,711) dx,prname(ii),df
711      format(2x,'For ',1pg12.4,'% change in ',a8,
     +          '  the SENSITIVITY is ',1pg16.5)
700   continue
c-----------------------------------------------------------
c     find the individual deltaf's corresponding to delta's
c     first find the first term in the taylor exp. series
c     do k1 ( for the n increments along the eigenvectors)
c     do j ( for the m functions in the ssq)
c     do i ( for the n elemenents in the jacobian)
c     
c     finds the f**2(j)=2*projs(.,k1)*xjacs(j)*f(j)+
c                       (xjacs(j)*projs(.,k1))**2)
c----------------------------------------------------------
      i=0
      do 600 ii=1,npar
         if (noyes(ii).eq.0) go to 600
         i=i+1
         do 610 j=1,m
            sum=0.0d0
            do 620 k1=1,n
               gradst=xjacs(j+(k1-1)*m)*f(j)
               sum=sum+gradst*projs(k1,i)
  620       continue
            delgrd(j)=2.0d0*sum
610      continue
c----------------------------------------------------------
c     find the xjac*projs
c----------------------------------------------------------
         do 320 j=1,m
            sum=0.0d0
            l=j
            do 340 k1=1,n
               sum=sum+xjacs(l)*projs(k1,i)
               l=l+m
  340       continue
            jprojs(j,i)=sum
 320     continue
c-----------------------------------------------------------
c     now find the jprojs t*jprojs 
c-----------------------------------------------------------
         do 420 j=1,m
            jptjps(j)=jprojs(j,i)**2
  420    continue
c-----------------------------------------------------------
c     now lets add the results of the two terms
c     to find the total difference in the ssq
c----------------------------------------------------------
         sum=0.0d0
         do 500 j=1,m
            delftl(j)=delgrd(j)+jptjps(j)
            sum1=dsqrt(dabs(delftl(j)))
c           write(ttyw,511) j,i,sum1
c           if (luout.ne.11) write(luout,511) j,i,sum1
511         format(5x,'* * * *  sensitivity of function',i3,' due to
     +deltax(',i3,') =',1pg12.4)
            sum=sum+delftl(j)
500      continue
         delf(i)=sum
         write(ttyw,512) prname(ii),sum
         if (luout.ne.11) write(luout,512) prname(ii),sum
512      format(5x,'* * *  Sensitivity due to ',a8,'=',1pg15.6)
600   continue
c
      return
1000  write(ttyw,330)
330   format(10x,'* * * * * matrix at least singular * * * * * * * '/,
     +       10x,'* at least one eigenvalue less or equal to zero *')
      return
      end
      subroutine EIGEN
c
c     Date Code  Jan 10,1982
c--------------------------------------------------------------------
c
c    Find the eigenvalues and the eigenvectors
c
c     Original : Kyr. Doganis                  Aug 1981 at Stanford
c     Mod # 1  : kyr. Doganis                  Nov 1981 at Stanford
c     Mod # 2  : kyr. Doganis                  Jan 1982 at Xerox
c
c---------------------------------------------------------------------
c
c     Common Area 
c---------------------------------------------------------------------
c
	include 'parsize.f'
c
      integer optflg
      character*2 k
      common /jpar/ m,n,nsig,maxfn,infer,ier,optflg,
     +       ibad,icount,idelx1,idelxl,idelxu,ieval,ifml,ifml1,ifpl,
     +       ifpl1,ifpu,igrad1,igradl,igradu,ijac,iscal1,iscall,iscalu,
     +       isw,iter,ixbad1,ixnew1,ixnewl,j,istop,inflag,
     +       icnst,kvk,kvkold,iterr,nvar,npar,iweigs,k
c
      integer nv,nm,ierr
      common /isens/ nv,nm,ierr
c
      double precision jtsens,egval,egvec,egvlmx,egvlmn,
     +                 cndnum,cndvct
      common /sens/ jtsens(ijtdim),egval(ixdim),
     +              egvec(ixdim,ixdim),egvlmx,egvlmn,cndnum,cndvct
c
c------------------------------------------------------------
      call  orthog
      do 40 i = 1, n
         do 30 j = 1, n
            egvec(j,i) = 0.0d0
30       continue
         egvec(i,i) = 1.0d0
40    continue
c
      call  qlxfor
      if (ierr .ne. 0) go to 50
      call  symetr
   50 return
      end
      subroutine QLXFOR
c
c     Date Code  Jan 10,1982
c--------------------------------------------------------------------
c
c     Eigenvalues & eigenvectors using QL method
c
c     Original : Kyr. Doganis                  Aug 1981 at Stanford
c     Mod # 1  : kyr. Doganis                  Nov 1981 at Stanford
c     Mod # 2  : kyr. Doganis                  Jan 1982 at Xerox
c
c---------------------------------------------------------------------
c
c     Common Area 
c---------------------------------------------------------------------
c
	include 'parsize.f'
c
      integer optflg
      character*2 k
      common /jpar/ m,n,nsig,maxfn,infer,ier,optflg,
     +       ibad,icount,idelx1,idelxl,idelxu,ieval,ifml,ifml1,ifpl,
     +       ifpl1,ifpu,igrad1,igradl,igradu,ijac,iscal1,iscall,iscalu,
     +       isw,iter,ixbad1,ixnew1,ixnewl,j,istop,inflag,
     +       icnst,kvk,kvkold,iterr,nvar,npar,iweigs,k
c
      integer nv,nm,ierr
      common /isens/ nv,nm,ierr
c
      double precision jtsens,egval,egvec,egvlmx,egvlmn,
     +                 cndnum,cndvct
      common /sens/ jtsens(ijtdim),egval(ixdim),
     +              egvec(ixdim,ixdim),egvlmx,egvlmn,cndnum,cndvct
c
      double precision e
      common /seint/ e(ixdim)
c
c------------------------------------------------------
c      local variables
c------------------------------------------------------
      double precision b,c,fs,gs,h,p,r,s,machep
c------------------------------------------------------
c      machep='2400'x
c      machep = 6.9d-18
       machep=16.d0**-13
c
      ierr = 0
      if (n .eq. 1) go to 1001
      do 100 i = 2, n
         e(i-1) = e(i)
100   continue
c
      fs = 0.0d0
      b = 0.0d0
      e(n) = 0.0d0
      do 240 l = 1, n
         j = 0
         h = machep * (dabs(egval(l)) + dabs(e(l)))
         if (b .lt. h) b = h
c--------------------------------------------------------------------
c     look for small sub-diagonal element
c--------------------------------------------------------------------
         do 110 mi = l, n
            if (dabs(e(mi)) .le. b) go to 120
c--------------------------------------------------------------------
c     e(n) is always zero, so there is no exit
c     through the bottom of the loop
c--------------------------------------------------------------------
  110    continue
c
  120    if (mi .eq. l) go to 220
  130    if (j .eq. 30) go to 1000
         j = j + 1
c--------------------------------------------------------------------
c     form shift
c--------------------------------------------------------------------
         l1 = l + 1
         gs = egval(l)
         p = (egval(l1) - gs) / (2.0d0 * e(l))
         r = dsqrt(p*p+1.0d0)
         egval(l) = e(l) / (p + dsign(r,p))
         h = gs - egval(l)
         do 140 i = l1, n
            egval(i) = egval(i) - h
140      continue
c
         fs = fs + h
c--------------------------------------------------------------------
c     QL transformation 
c--------------------------------------------------------------------
         p = egval(mi)
         c = 1.0d0
         s = 0.0d0
         mml = mi - l
c---------------------------------------------------------------------
c     for i=mi-1 step -1 until l do -- 
c--------------------------------------------------------------------
         do 200 ii = 1, mml
            i = mi - ii
            gs = c * e(i)
            h = c * p
            if (dabs(p) .lt. dabs(e(i))) go to 150
            c = e(i) / p
            r = dsqrt(c*c+1.0d0)
            e(i+1) = s * p * r
            s = c / r
            c = 1.0d0 / r
            go to 160
  150       c = p / e(i)
            r = dsqrt(c*c+1.0d0)
            e(i+1) = s * e(i) * r
            s = 1.0d0 / r
            c = c * s
  160       p = c * egval(i) - s * gs
            egval(i+1) = h + s * (c * gs + s * egval(i))
c--------------------------------------------------------------------
c     form vector
c--------------------------------------------------------------------
            do 180 k1 = 1, n
               h = egvec(k1,i+1)
               egvec(k1,i+1) = s * egvec(k1,i) + c * h
               egvec(k1,i) = c * egvec(k1,i) - s * h
  180       continue
c
  200    continue
c
         e(l) = s * p
         egval(l) = c * p
         if (dabs(e(l)) .gt. b) go to 130
  220    egval(l) = egval(l) + fs
  240 continue
c--------------------------------------------------------------------
c     order eigenvalues and eigenvectors 
c--------------------------------------------------------------------
      do 300 ii = 2, n
         i = ii - 1
         k1 = i
         p = egval(i)
         do 260 j = ii, n
            if (egval(j) .ge. p) go to 260
            k1 = j
            p = egval(j)
  260    continue
         if (k1 .eq. i) go to 300
         egval(k1) = egval(i)
         egval(i) = p
         do 280 j = 1, n
            p = egvec(j,i)
            egvec(j,i) = egvec(j,k1)
            egvec(j,k1) = p
  280    continue
  300 continue
c
      go to 1001
c--------------------------------------------------------------------
c     set error -- no convergence to an
c      eigenvalue after 30 iterations 
c---------------------------------------------------------------------
 1000 ierr = l
 1001 return
      end
      subroutine SYMETR
c
c     Date Code  Jan 10,1982
c--------------------------------------------------------------------
c
c     Forms eigenvectors for real symmetric matrix
c
c     Original : Kyr. Doganis                  Aug 1981 at Stanford
c     Mod # 1  : kyr. Doganis                  Nov 1981 at Stanford
c     Mod # 2  : kyr. Doganis                  Jan 1982 at Xerox
c
c---------------------------------------------------------------------
c
c     Common Area 
c
c---------------------------------------------------------------------
c
	include 'parsize.f'
c
      integer optflg
      character*2 k
      common /jpar/ m,n,nsig,maxfn,infer,ier,optflg,
     +       ibad,icount,idelx1,idelxl,idelxu,ieval,ifml,ifml1,ifpl,
     +       ifpl1,ifpu,igrad1,igradl,igradu,ijac,iscal1,iscall,iscalu,
     +       isw,iter,ixbad1,ixnew1,ixnewl,j,istop,inflag,
     +       icnst,kvk,kvkold,iterr,nvar,npar,iweigs,k
c
      double precision jtsens,egval,egvec,egvlmx,egvlmn,
     +                 cndnum,cndvct
      common /sens/ jtsens(ijtdim),egval(ixdim),
     +              egvec(ixdim,ixdim),egvlmx,egvlmn,cndnum,cndvct
c
c----------------------------------------------------------------
c    local variables
c--------------------------------------------------------------
      double precision h,s
c-------------------------------------------------------------
c
      if (n .eq. 1) go to 200
      do 140 i = 2, n
         l = i - 1
         iz = (i * l) / 2
         ik = iz + i
         h = jtsens(ik)
         if (h .eq. 0.0d0) go to 140
         do 130 j = 1, n
            s = 0.0d0
            ik = iz
            do 110 k1 = 1, l
               ik = ik + 1
               s = s + jtsens(ik) * egvec(k1,j)
  110       continue
c--------------------------------------------------------------------
c     double division avoids possible underflow 
c---------------------------------------------------------------------
            s = (s / h) / h
            ik = iz
            do 120 k1 = 1, l
               ik = ik + 1
               egvec(k1,j) = egvec(k1,j) - s * jtsens(ik)
  120       continue
  130    continue
  140 continue
  200 return
      end
      subroutine ORTHOG
c
c     Date Code  Jan 10,1982
c--------------------------------------------------------------------
c
c     one dimension array to a symmetric triagonal matrix
c
c     Original : Kyr. Doganis                  Aug 1981 at Stanford
c     Mod # 1  : kyr. Doganis                  Nov 1981 at Stanford
c     Mod # 2  : kyr. Doganis                  Jan 1982 at Xerox
c
c---------------------------------------------------------------------
c
c     Common Area 
c---------------------------------------------------------------------
c
	include 'parsize.f'
c
      integer optflg
      character*2 k
      common /jpar/ m,n,nsig,maxfn,infer,ier,optflg,
     +       ibad,icount,idelx1,idelxl,idelxu,ieval,ifml,ifml1,ifpl,
     +       ifpl1,ifpu,igrad1,igradl,igradu,ijac,iscal1,iscall,iscalu,
     +       isw,iter,ixbad1,ixnew1,ixnewl,j,istop,inflag,
     +       icnst,kvk,kvkold,iterr,nvar,npar,iweigs,k
c
      double precision jtsens,egval,egvec,egvlmx,egvlmn,
     +                 cndnum,cndvct
      common /sens/ jtsens(ijtdim),egval(ixdim),
     +              egvec(ixdim,ixdim),egvlmx,egvlmn,cndnum,cndvct
c
      double precision e
      common /seint/ e(ixdim)
c
      double precision fs,gs,h,hhs,scale
c
c-----------------------------------------------------
c     for i=n step -1 until 1 do -- 
c--------------------------------------------------------------------
      do 300 ii = 1, n
         i = n + 1 - ii
         l = i - 1
         iz = (i * l) / 2
         h = 0.0d0
         scale = 0.0d0
         if (l .lt. 1) go to 130
c--------------------------------------------------------------------
c     scale row 
c---------------------------------------------------------------------
         do 120 k1 = 1, l
            iz = iz + 1
            egval(k1) = jtsens(iz)
            scale = scale + dabs(egval(k1))
  120    continue
         if (scale .ne. 0.0d0) go to 140
  130    e(i) = 0.0d0
         go to 290
  140    do 150 k1 = 1, l
            egval(k1) = egval(k1) / scale
            h = h + egval(k1) * egval(k1)
  150    continue
         fs = egval(l)
         gs = -dsign(dsqrt(h),fs)
         e(i) = scale * gs
         h = h - fs * gs
         egval(l) = fs - gs
         jtsens(iz) = scale * egval(l)
         if (l .eq. 1) go to 290
         fs = 0.0d0
         do 240 j = 1, l
            gs = 0.0d0
            jk = (j * (j-1)) / 2
c--------------------------------------------------------------------
c     form element of a*u 
c--------------------------------------------------------------------
            do 180 k1 = 1, l
               jk = jk + 1
               if (k1 .gt. j) jk = jk + k1 - 2
               gs = gs + jtsens(jk) * egval(k1)
  180       continue
c---------------------------------------------------------------------
c     form element of p 
c--------------------------------------------------------------------
            e(j) = gs / h
            fs = fs + e(j) * egval(j)
240      continue
         hhs = fs / (h + h)
         jk = 0
c--------------------------------------------------------------------
c     form reduced a 
c--------------------------------------------------------------------
         do 260 j = 1, l
            fs = egval(j)
            gs = e(j) - hhs * fs
            e(j) = gs
            do 260 k1 = 1, j
               jk = jk + 1
               jtsens(jk) = jtsens(jk) - fs * e(k1) - gs * egval(k1)
  260    continue
  290    egval(i) = jtsens(iz+1)
         jtsens(iz+1) = scale * dsqrt(h)
  300 continue
c
      return
      end
      subroutine printo
c
	include 'parsize.f'
c---------------------------------------------------------------------
      integer ttyw,ttyr
      common /termin/ luout,luinf,luopt,ttyw,ttyr,icont,iauto
c
      integer optflg
      character*2 k,ksym,ksub 
      common /jpar/ m,n,nsig,maxfn,infer,ier,optflg,
     +       ibad,icount,idelx1,idelxl,idelxu,ieval,ifml,ifml1,ifpl,
     +       ifpl1,ifpu,igrad1,igradl,igradu,ijac,iscal1,iscall,iscalu,
     +       isw,iter,ixbad1,ixnew1,ixnewl,j,istop,inflag,
     +       icnst,kvk,kvkold,iterr,nvar,npar,iweigs,k
c
c
      double precision xx,ff
      common /xxff/ xx(ixdim),ff(ifdim)
c
      double precision init,uprb,lowb,tolr,trgt,ores,weight
      common /incond/ init(ixdim),uprb(ixdim),lowb(ixdim),
     +        tolr(ifdim),trgt(ifdim),ores(ifdim),weight(ifdim)
c
      double precision work
      common /work/ work(iwkdim)
c
      common /yesno/ noyes(ixdim),next,mkeep,inext,ntimes
c
      character*8 prname
      common /pnames/ prname(ixdim)
c
      write(ttyw,10)
10    format(' ')
      l=0
      do 100 i=1,npar
         if (noyes(i).eq.0) go to 100
         l=l+1
         ksym=' '
         ksub=' '
         if (xx(l).ge.uprb(l).or.xx(l).le.lowb(l)) ksym='+'
         if (xx(l).ge.uprb(l).or.xx(l).le.lowb(l)) ksub='*'
         write(ttyw,110) ksym,prname(i),xx(l),work(ixnew1+l)
     +                  ,(ksub,ii=1,10)
110      format(1x,a1,a8,'=',1pg15.6,5x,'Weight=',1pg15.6,2x,10a1)
100   continue
      return
      end
      subroutine parse(a,word,ipoint,id1,id2)
      implicit double precision(a-h,o-z)
      character*80 a,word
      character*1 id1,id2,iblank
      data iblank/' '/
      if(ipoint.ge.81) go to 400
      l=0
      length=80
      do100 i=ipoint,80
      i1=i
      if((a(i:i).ne.id1).and.(a(i:i).ne.id2)) go to 200
100   continue
      ipoint=81
      go to 400
200   l=0
      do300 i=i1,80
      if((a(i:i).eq.id1).or.(a(i:i).eq.id2)) go to 400
      ipoint=i+1
      l=l+1
300   if(l.le.length) word(l:l)=a(i:i)
400   l=min0(l,length)
      do500 i=1,length
500   if(i.gt.l) word(i:i)=iblank
      return
      end
      subroutine decode(number,x,name)
      implicit double precision(a-h,o-z)
c     this takes a character string in 'number' and returns a 
c     real*8 number in 'x'
      character name*8
      character number*80,iplus,iminus,iper,iblank,se,sd,sd1,se1
      data iplus/'+'/,iminus/'-'/,iper/'.'/,iblank/' '/,
     1 se/'e'/,sd/'d'/,se1/'E'/,sd1/'D'/
      x=0.0d0
      sign=1.0d0
      iflag=0
      factor=10.0d0
      i1=1
      length=80
      if(number(1:1).ne.iplus) go to 100
      i1=2
      go to 200
100   if(number(1:1).ne.iminus) go to 200
      i1=2
      sign=-1.0d0
200   do500 i=i1,length
      ipoint=i+1
      if(number(i:i).eq.iblank) go to 600
      if((number(i:i).eq.se).or.(number(i:i).eq.sd)) go to 700
      if((number(i:i).eq.se1).or.(number(i:i).eq.sd1)) go to 700
      if(number(i:i).ne.iper) go to 300
      if(iflag.eq.1) go to 1200
      iflag=1
      go to 500
300   j=ichar(number(i:i))-48
      if((j.lt.0).or.(j.gt.9)) go to 1200
      if(iflag.eq.0) go to 400
      x1=j
      x=x+x1/factor
      factor=factor*10.0d0
      go to 500
400   x=x*10.0d0+j
500   continue
600   x=x*sign
      return
700   if((x.eq.0.0d0).and.(ipoint.eq.2)) x=1.0d0
      if((sign.eq.-1.0d0).and.(ipoint.eq.3)) x=1.0d0
      iexp=0
      isign=1
      if(number(ipoint:ipoint).ne.iplus) go to 800
      ipoint=ipoint+1
      go to 900
800   if(number(ipoint:ipoint).ne.iminus) go to 900
      ipoint=ipoint+1
      isign=-1
900   do1000 i=ipoint,length
      if(number(i:i).eq.iblank) go to 1100
      j=ichar(number(i:i))-48
      if((j.lt.0).or.(j.gt.9)) go to 1200
      iexp=iexp*10+j
1000  continue
1100  if(iexp.gt.77) go to 1400
      x=sign*x*10.0d0**(iexp*isign)
      return
1200  write(6,1300) number(i:i),name
1300  format(1x,'unexpected character  ',a1,' in file',a)
      stop
1400  write(6,1500) iexp
1500  format(1x,'** ',i4,' ** Exponent is too large in file',a)
      stop
      end
      subroutine select(filesh)
      integer optflg
      character*2 k
      common /jpar/ m,n,nsig,maxfn,infer,ier,optflg,
     +       ibad,icount,idelx1,idelxl,idelxu,ieval,ifml,ifml1,ifpl,
     +       ifpl1,ifpu,igrad1,igradl,igradu,ijac,iscal1,iscall,iscalu,
     +       isw,iter,ixbad1,ixnew1,ixnewl,j,istop,inflag,
     +       icnst,kvk,kvkold,iterr,nvar,npar,iweigs,k
c
      double precision eps,delta,parm1,parm2,parm3,parm4,ssq,ax,
     +               al,cons2,delta2,erl2,erl2x,f0,f0sq,f0sqs4,g,val,
     +               hh,onesf0,prec,rel,relcon,sqdif,ssqold,up,xhold,
     +               bigtrg,smltrg
      common /xpar/   eps,delta,parm1,parm2,parm3,parm4,ssq,ax,
     +               al,cons2,delta2,erl2,erl2x,f0,f0sq,f0sqs4,g,val,
     +               hh,onesf0,prec,rel,relcon,sqdif,ssqold,up,xhold,
     +               bigtrg,smltrg
       integer ivdsho,ivgsho,ivbsho
       character short*1,filesh*8
       double precision vdshor,vgshor,vbshor
       double precision vdmin,vdmax,vdincr
       double precision vgmin,vgmax,vgincr
       double precision vbmin,vbmax,vbincr
       common /datsho/ vdmin,vdmax,vdincr,vdshor(200),
     +                   vgmin,vgmax,vgincr,vgshor(100),
     +                   vbmin,vbmax,vbincr,vbshor(100)
       common /idtsho/ ivdsho,ivgsho,ivbsho,iweigh
       character*80 a,word
       character*1 id1,id2,id3
       double precision xvar
       double precision var(200)
       data id1/' '/,id2/','/,id3/'='/
       open(unit=9,status='old',file=filesh)   
c
       nsig=4
       maxfn=100
       delta=1.0d-6
       eps=1.0d-9
       parm1=0.1d0
       parm2=2d0
       parm3=1000d0
       parm4=0.1d0
c
       iweigh=0
c
1      read(9,100,err=1000,end=2000) a
100    format(a)
       if (a(1:1).eq.'*') go to 1
       irange=0
       ilist=0
       ipoint=1
       call parse(a,word,ipoint,id1,id2)
       if (word(1:6).eq.'RangVD'.or.word(1:6).eq.'RANGVD')
     +    irange=1
       if (word(1:6).eq.'ListVD'.or.word(1:6).eq.'LISTVD')
     +    ilist=1
       if (word(1:6).eq.'RangVG'.or.word(1:6).eq.'RANGVG')
     +    irange=2
       if (word(1:6).eq.'ListVG'.or.word(1:6).eq.'LISTVG')
     +    ilist=2
       if (word(1:6).eq.'RangVB'.or.word(1:6).eq.'RANGVB')
     +    irange=3
       if (word(1:6).eq.'ListVB'.or.word(1:6).eq.'LISTVB')
     +    ilist=3
       if (word(1:6).eq.'Weight'.or.word(1:6).eq.'WEIGHT')
     +    iweigh=1
       if (word(1:8).eq.'Criteria'.or.word(1:8).eq.'CRITERIA')
     +    go to 600
       if (irange.gt.0) go to 200
       if (ilist.gt.0) go to 300
       if (iweigh.eq.1) go to 1
       go to 500
c---------------------------------------------------------------
c       take care of ranges
c---------------------------------------------------------------
200    continue
220    call parse(a,word,ipoint,id1,id3)
       if (word(1:3).eq.'min'.or.word(1:3).eq.'MIN')
     +    go to 2201
       if (word(1:3).eq.'max'.or.word(1:3).eq.'MAX')
     +    go to 2202
       if (word(1:3).eq.'inc'.or.word(1:3).eq.'INC')
     +    go to 2203
       read(9,100,err=1000,end=2000) a
       if (a(1:1).eq.'*') go to 2204
       ipoint=1
       go to 200
c---------------------------------------------------------------
c      here is the minimum
c---------------------------------------------------------------
2201   ipoint=ipoint+1
       call parse(a,word,ipoint,id1,id2)
       call decode(word,xvar,filesh)
       var(1)=xvar
       go to 220
c---------------------------------------------------------------
c      here is the maximum
c---------------------------------------------------------------
2202   ipoint=ipoint+1
       call parse(a,word,ipoint,id1,id2)
       call decode(word,xvar,filesh)
       var(2)=xvar
       go to 220
c---------------------------------------------------------------
c      here is the increment
c---------------------------------------------------------------
2203   ipoint=ipoint+1
       call parse(a,word,ipoint,id1,id2)
       call decode(word,xvar,filesh)
       var(3)=xvar
       go to 220
c---------------------------------------------------------------
c      find the range of the v's
c---------------------------------------------------------------
2204   go to (201,202,203), irange
c---------------------------------------------------------------
c      vdrange 
c---------------------------------------------------------------
201    vdmin=dmin1(var(1),var(2))
       vdmax=dmax1(var(1),var(2))
       vdincr=dabs(var(3))
       var(1)=vdmin
       ivdsho=0
2010   ivdsho=ivdsho+1
       if (vdincr.lt.1.0d-22) go to 1
       vdshor(ivdsho)=var(1)
       var(1)=var(1)+vdincr
       if (var(1).gt.vdmax+0.0001d0) go to 1
       go to 2010
c---------------------------------------------------------------
c      vgrange
c---------------------------------------------------------------
202    vgmin=dmin1(var(1),var(2))
       vgmax=dmax1(var(1),var(2))
       vgincr=dabs(var(3))
       var(1)=vgmin
       ivgsho=0
2020   ivgsho=ivgsho+1
       if (vgincr.lt.1.0d-22) go to 1
       vgshor(ivgsho)=var(1)
       var(1)=var(1)+vgincr
       if (var(1).gt.vgmax+0.0001d0) go to 1
       go to 2020
c---------------------------------------------------------------
c      vbrange
c---------------------------------------------------------------
203    vbmin=dmin1(var(1),var(2))
       vbmax=dmax1(var(1),var(2))
       vbincr=dabs(var(3))
       var(1)=vbmin
       ivbsho=0
2030   ivbsho=ivbsho+1
       if (vbincr.lt.1.0d-22) go to 1
       vbshor(ivbsho)=var(1)
       var(1)=var(1)+vbincr
       if (var(1).gt.vbmax+0.0001d0) go to 1
       go to 2030
c---------------------------------------------------------------
c      take care of listing
c---------------------------------------------------------------
300    imatch=0
320    call parse(a,word,ipoint,id1,id2)
       call decode(word,xvar,filesh)
       imatch=imatch+1
       var(imatch)=xvar
       if (ipoint.lt.81) go to 320
       go to 310
350    imatch=imatch-1
       go to (401,402,403), ilist
310    read(9,100,err=1000,end=2000) a
       if (a(1:1).eq.'*') go to 350
       ipoint=1
       imatch=imatch-1
       go to 320
c---------------------------------------------------------------
c      take care of vdlist
c---------------------------------------------------------------
401    ivdsho=imatch
       do 410 i=1,ivdsho
          vdshor(i)=var(i)
410    continue
       go to 1
c---------------------------------------------------------------
c      take care of vglist
c---------------------------------------------------------------
402    ivgsho=imatch
       do 420 i=1,ivgsho
          vgshor(i)=var(i)
420    continue
       go to 1
c---------------------------------------------------------------
c      take care of vblist
c---------------------------------------------------------------
403    ivbsho=imatch
       do 430 i=1,ivbsho
          vbshor(i)=var(i)
430    continue
       go to 1
c---------------------------------------------------------------
c      the convergence criteria
c---------------------------------------------------------------
600    read(9,100,err=1000,end=2000) a
       if (a(1:1).eq.'*') go to 1
       ipoint=1
620    call parse(a,word,ipoint,id1,id3)
       if (word(1:5).eq.'Nsign'.or.word(1:5).eq.'NSIGN')
     +    go to 601
       if (word(1:5).eq.'Maxfn'.or.word(1:5).eq.'MAXFN')
     +    go to 602
       if (word(1:5).eq.'Delta'.or.word(1:5).eq.'DELTA')
     +    go to 603
       if (word(1:5).eq.'Epsil'.or.word(1:5).eq.'EPSIL')
     +    go to 604
       if (word(1:5).eq.'Linit'.or.word(1:5).eq.'LINIT')
     +    go to 605
       if (word(1:5).eq.'Lscal'.or.word(1:5).eq.'LSCAL')
     +    go to 606
       if (word(1:5).eq.'Luppr'.or.word(1:5).eq.'LUPPR')
     +    go to 607
       if (word(1:5).eq.'Fcdsw'.or.word(1:5).eq.'FCDSW')
     +    go to 608
       go to 600
c---------------------------------------------------------------
c      determine the nsignificant
c---------------------------------------------------------------
601    ipoint=ipoint+1
       call parse(a,word,ipoint,id1,id2)
       call decode(word,xvar,filesh)
       nsig=xvar
       if (ipoint.lt.81) go to 620
       go to 600
c---------------------------------------------------------------
c      determine the maximum functions evaluations
c---------------------------------------------------------------
602    ipoint=ipoint+1
       call parse(a,word,ipoint,id1,id2)
       call decode(word,xvar,filesh)
       maxfn=xvar
       if (ipoint.lt.81) go to 620
       go to 600
c---------------------------------------------------------------
c      determine the norm of the gradsient bound delta
c---------------------------------------------------------------
603    ipoint=ipoint+1
       call parse(a,word,ipoint,id1,id2)
       call decode(word,xvar,filesh)
       delta=xvar
       if (ipoint.lt.81) go to 620
       go to 600
c---------------------------------------------------------------
c      determine the sum of squares difference epsilon
c---------------------------------------------------------------
604    ipoint=ipoint+1
       call parse(a,word,ipoint,id1,id2)
       call decode(word,xvar,filesh)
       eps=xvar
       if (ipoint.lt.81) go to 620
       go to 600
c---------------------------------------------------------------
c      determine the M-L parameter initial value
c---------------------------------------------------------------
605    ipoint=ipoint+1
       call parse(a,word,ipoint,id1,id2)
       call decode(word,xvar,filesh)
       parm1=xvar
       if (ipoint.lt.81) go to 620
       go to 600
c---------------------------------------------------------------
c      determaine the M-L parameter scale factor
c---------------------------------------------------------------
606    ipoint=ipoint+1
       call parse(a,word,ipoint,id1,id2)
       call decode(word,xvar,filesh)
       parm2=xvar
       if (ipoint.lt.81) go to 620
       go to 600
c---------------------------------------------------------------
c      determine the upper bound of the M-L parameter
c---------------------------------------------------------------
607    ipoint=ipoint+1
       call parse(a,word,ipoint,id1,id2)
       call decode(word,xvar,filesh)
       parm3=xvar
       if (ipoint.lt.81) go to 620
       go to 600
c---------------------------------------------------------------
c      determine the forward.central difference switch
c---------------------------------------------------------------
608    ipoint=ipoint+1
       call parse(a,word,ipoint,id1,id2)
       call decode(word,xvar,filesh)
       parm4=xvar
       if (ipoint.lt.81) go to 620
       go to 600
500    continue
c
c     for other specificsations
c
       return
2000   close(unit=9)
       return
1000   stop
c
c       
       end

