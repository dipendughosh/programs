      subroutine MODEL4(xt,id,iexit)
      implicit double precision (a-h,o-z)
	include 'parsize.f'
c--------------------------------------------------------------------
c     Date Code  Aug 10,1982
c--------------------------------------------------------------------
c                M O D E L 1
c
c     Optimization of Model1 for SPICE parameters extraction
c
c     Original : Kyr. Doganis                  Aug 1981 
c     Mod # 1  : kyr. Doganis                  Feb 1982 
c     Mod # 2  : kyr. Doganis                  Aug 1982 
c     Mod # 4  : SIMbozos		       Dec 1987
c
c---------------------------------------------------------------------
c
c     Common Area 
c---------------------------------------------------------------------
      integer ttyw,ttyr
      common /termin/ luout,luinf,luopt,ttyw,ttyr,icont,iauto
c
      integer optflg
      character*2 k
      common /jpar/ m,n,nsig,maxfn,infer,ier,optflg,
     +       ibad,icount,idelx1,idelxl,idelxu,ieval,ifml,ifml1,ifpl,
     +    ifpl1,ifpu,igrad1,igradl,igradu,ijac,iscal1,iscall,iscalu,
     +       isw,iter,ixbad1,ixnew1,ixnewl,j,istop,inflag,
     +       icnst,kvk,kvkold,iterr,nvar,npar,iweigs,k
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
      character*8 prname
      common /pnames/ prname(ixdim)
c
      character*8 idfunc
      common /idfu/ idfunc
c
      double precision init,uprb,lowb,tolr,trgt,ores,weight
      common /incond/ init(ixdim),uprb(ixdim),lowb(ixdim),
     +           tolr(ifdim),trgt(ifdim),ores(ifdim),weight(ifdim)
c
      double precision xlkeep,xwkeep
      common /xplot/ iikeep,xlkeep(10),xwkeep(10)
c
      double precision Vds(ifdim),Vgs(ifdim),Vbs(ifdim)
      equivalence (Vds(1),v(1,1)),(Vgs(1),v(1,2)),(Vbs(1),v(1,3))
c
      double precision xt(ixdim),Id(ifdim)
c-----------------------------------------------------------------
c     Model parameter variables
c-----------------------------------------------------------------
c
      double precision lev,phii,phi,phib, tempr
c
      common /param1/   Lev,Type,Xld,Toxi,Xnsubi,Vtoi,Xkpi,Gammai,
     +              Phii,Uoi,Uexpi,Ucrit,Deltai,Vmaxi,Xji,
     +        Xlamdi,Xkappa,Xnfsi,Xneffi,Xnss,Tpg,Eta,Theta,dumy(7)
c
      COMMON /MOSARG/ VTO,BETA,GAMMA,PHI,PHIB,COX,XNSUB,XNFS,XD,XJ,
     1   XLAMDA,UO,UEXP,VBP,UTRA,VMAX,XNEFF,XL,XW,VBI,VON,VDSAT,QSPOF,
     2   BETA0,BETA1,CDRAIN,XQCO,XQC,FNARRW,FSHORT
c
      COMMON /KNSTNT/ TWOPI,VT,CHARGE,EPSSIL,EPSOX,EGFET,XNI
c
      double precision parmtr(ixdim)
      equivalence (parmtr(1),Lev)
c
      common /toplot/ tox,xkp,fnarri
c
      integer ixl,ixw
      common /lwloc/ ixl(10),ixw(10)
c------------------------------------------------------------------
c     common for simulation purposes
c------------------------------------------------------------------
c
      common /result/ Ueff,gammad,Xleff,Vbin,deltal,vth
c
c------------------------------------------------------------------
c     Now the subroutine MODEL* starts
c------------------------------------------------------------------
      go to (100,200,300,350,500,350),iexit
c-----------------------------------------------------------------
c
c     In this section we specify 
c                 the name of the model (idfunc='*'),
c                 the number of the parameters (npar)
c                 the number of the variables  (nvar)
c                 the names of the parameters (prname(*)='*' )
c
c-----------------------------------------------------------------
100   continue
c
      idfunc='CAZM 2.0 '
c
      npar=23
      nvar=3
c
      prname(1)='Level'
      prname(2)='Type'
      prname(3)='Xld'
      prname(4)='Tox'
      prname(5)='Nsub'
      prname(6)='Vto'
      prname(7)='Xkp'
      prname(8)='Gamma'
      prname(9)='Phi'
      prname(10)='Uo'
      prname(11)='Uexp'
      prname(12)='Ucrit'
      prname(13)='Delta'
      prname(14)='Vmax'
      prname(15)='Xj'
      prname(16)='Xlambda'
      prname(17)='Xkappa'
      prname(18)='Xnfs'
      prname(19)='Xneff'
      prname(20)='Xnss'
      prname(21)='Tpgate'
      prname(22)='Eta'
      prname(23)='Theta'
c
      return
c--------------------------------------------------------------
c     
c     In this section we introduce some constants which will be 
c        of the same value throughtout the optimization.
c        These constants enter the model subroutine.
c--------------------------------------------------------------
200   continue
      twopi=2.d0*3.1415926535d0
      charge=1.6021918d-19
      epssil=11.7d0*8.854214871d-12
      epsox=3.9d0*8.854214871d-12
      vt=1.3806226d-23*300.15d0/charge
      xni=1.45d16
      egfet=1.115087742d0
c--------------------------------------------------------------
c     finds the different  channel lengths and widths
c     the lengths corresponds to the vds/1e30
c     the widths corresponds to the vgs/1e30
c--------------------------------------------------------------
      ii=0
      do 250 i=1,m
         if (vds(i).lt.1.d10) go to 250
         ii=ii+1
         ixl(ii)=i
         ixw(ii)=i
         xlkeep(ii)=vds(i)*1.d-30
         xwkeep(ii)=vgs(i)*1.d-30
250   continue
      iikeep=ii
      return
c---------------------------------------------------------------------
c
c     this one is for the specifications of the parameters
c     DONT TOUCH IT
c
c---------------------------------------------------------------------
300   continue
      l=0
      do 310 i=1,npar
         parmtr(i)=initkp(i)
         if (noyes(i).eq.0) go to 310
         l=l+1
         parmtr(i)=xt(l)
310   continue
      go to 370
c---------------------------------------------------------------------
350   continue
      do 360 i=1,npar
         parmtr(i)=xt(i)
360   continue
c
c---------------------------------------------------------------------
c
c     Special preprocessing for MOSFET models
c     Define the model parameters as a function of the
c     optimizable parmaters.
c
c---------------------------------------------------------------------
370   continue      

C     Call mos_setup here 

       tempr = 27.0d0
       call mosetp(tempr)

c
c---------------------------------------------------------------------
c     Go to 400 for some output after one extraction is concluded
c
c---------------------------------------------------------------------
c


      if (iexit.eq.6) return
      if (iexit.eq.4) go to 400
c---------------------------------------------------------------------
c     Mosfets
c
c     Here the Current  calculation occurs
c     for the different bias conditions and different channel
c     Width/Lenghts ratios
c
c---------------------------------------------------------------------
      ii=1
      do 2000  i=1,m
         if (ixl(ii).ne.i) go to 2100
         xle=xlkeep(ii)
         xwi=xwkeep(ii)
         ii=ii+1
C         xl=(xle-2.d0*xld)*1.d-6
C         xw=xwi*1.d-6
C         beta=Xkp*xw/xl
C         cox=epsox/tox*xw*xl
C         if (lev.eq.3.) Fnarrw=fnarri/Xw
         id(i)=1.d-20
         go to 2000
2100     if (lev.eq.2.d0) xlamda=xlamdi
         if (lev.eq.3.d0) beta=xkp*xw/xl
         vdsi=type*vds(i)
         vbsi=type*vbs(i)
         vgsi=type*vgs(i)
         if (lev.eq.1.d0) call Libeq1(Vdsi,Vbsi,Vgsi)
         if (lev.eq.2.d0) call Libeq2(Vdsi,Vbsi,Vgsi, xle, xwi)
         if (lev.eq.3.d0) call Libeq3(Vdsi,Vbsi,Vgsi)
         id(i)=Cdrain*type
2000  continue
      return
c-----------------------------------------------------------
c
c      some results to go out
c
c----------------------------------------------------------
400   continue
      if (luout.ne.11)
     +    write(luout,404) xnsubi,tox/1.d-10,betai/1.d-6,gamma,
     +               xwi,uoi,vtoi,vbi,vmax,phii,xdlx
c
404   format(/,10x,'Nsub=',1pg16.5,10x,'Tox=',1pg16.5,/
     +         10x,'Kp(in)=',1pg16.5,8x,'Gamma=',1pg16.5,/
     +         10x,'Width=',1pg16.5,9x,'Mobility=',1pg16.5,/
     +         10x,'Vto=',1pg16.5,11x,'Vbi=',1pg16.5,/
     +         10x,'Vmax=',1pg16.5,10x,'Phi=',1pg16.5,/
     +         10x,'Ld=',1pg16.5,//)
c
c----------------------------------------------------------
c
c     Section of the simulation of the model using the extracted 
c     parameters.
c
c----------------------------------------------------------
      write(ttyw,600)
600   format(' Do you want some simulations for this extraction ? [y/n]
     + ? ',$)
10101  format(a2)
      read(ttyr,10101) k
      if (k.eq.'n'.or.k.eq.'N') go to 900
c----------------------------------------------------------
c
c     Here the model is simulated by users input biases and 
c     Width/Length ratios
c
c----------------------------------------------------------
605   write(ttyw,610)
610   format(' Input L,W,Vds,Vgs,Vbs ..... ',$)
      read(ttyr,*) xle,Xwi,Vd,Vg,Vb
         vd=type*vd
         vg=type*vg
         vb=type*vb
C        xl=(xle-2.d0*xld)*1.d-6
C        xw=xwi*1.d-6
C        beta=Xkp*xw/xl
C        cox=epsox/tox*xw*xl
         if (lev.eq.3.d0) Fnarrw=fnarri/Xw
         if (lev.eq.2.d0) xlamda=xlamdi
         if (lev.eq.3.d0) beta=xkp*xw/xl
         if (lev.eq.1.d0) call Libeq1(Vd,Vb,Vg)
         if (lev.eq.2.d0) call Libeq2(Vd,Vb,Vg, xle, xwi)
         if (lev.eq.3.d0) call Libeq3(Vd,Vb,Vg)
         xid=Cdrain*type
      write(ttyw,620) xle,xwi,type,type*vd,type*vg,type*vb,
     +               xl*1.d6,xleff*1.d6,
     +               ueff*1.d4,vmax,type*vdsat,
     +               beta1*1.d6,gammad,
     +               type*von,type*vbin,type*vth
620    format(/,2x,'Length=',1pg12.5,5x,'Width=',1pg12.5,5x,'Type=',
     + 1pg10.2,/2x,'Vds=',1pg12.5,2x,'Vgs=',1pg12.5,2x,'Vbs=',1pg12.5,/
     +          2x,'L-2dl=',1pg12.5,10x,'Length(eff)=',1pg12.5,/
     +          2x,'Mobility(eff)=',1pg12.5,x,'Vmax=',1pg12.5,x,
     +             'Vdsat=',1pg12.5,/
     +          2x,'Beta(eff)=',1pg12.5,10x,'Gamma(eff)=',1pg12.5,/
     +       2x,'Von=',1pg12.5,3x,'Vbin=',1pg12.5,3x,'Vth=',1pg12.5,/)
630   write(ttyw,635)
635   format(' MORE ? [y/n] ',$)
      read(ttyr,10101) k
      if (k.eq.'y'.or.k.eq.'Y') go to 605   
      if (k.eq.'n'.or.k.eq.'N')  return
      go to 630
900   continue
      return
c----------------------------------------------------------
c    
c    Here we specify the weighting function to the data
c         This section is called whenever weights are to 
c         be set to the data.
c
c----------------------------------------------------------
500   continue
      isetwe=0
      do 550 i=1,mkeep
         weight(i)=1.0d0
         if (dabs(vds(i)).gt.1.d10) go to 560
         if (isetwe.ne.1) go to 550
         if (dabs(vds(i)).ge.3.0d0.and.dabs(vgs(i)).gt.2.0d0) 
     +   weight(i)=10.0d0
         go to 550
560      xlengt=dabs(vds(i)*1.d-30)          
         isetwe=0
         if (xlengt.lt.6.0d0.or.xlengt.gt.10.d0) isetwe=1
550   continue
      return
      end
      subroutine scren4(xt,nvar,npar)
      implicit double precision (a-h,o-z)
	include 'parsize.f'
c
      integer ttyw,ttyr
      common /termin/ luout,luinf,luopt,ttyw,ttyr,icont,iauto
c
      double precision lev,phii,phi,phib
      common /param1/   Lev,Type,Xld,Toxi,Xnsubi,Vtoi,Xkpi,Gammai,
     +              Phii,Uoi,Uexpi,Ucrit,Deltai,Vmaxi,Xji,
     +        Xlamdi,Xkappa,Xnfsi,Xneffi,Xnss,Tpg,Eta,Theta,dumy(7)
c
      COMMON /MOSARG/ VTO,BETA,GAMMA,PHI,PHIB,COX,XNSUB,XNFS,XD,XJ,
     1   XLAMDA,UO,UEXP,VBP,UTRA,VMAX,XNEFF,XL,XW,VBI,VON,VDSAT,QSPOF,
     2   BETA0,BETA1,CDRAIN,XQCO,XQC,FNARRW,FSHORT
      COMMON /KNSTNT/ TWOPI,VT,CHARGE,EPSSIL,EPSOX,EGFET,XNI
c
      double precision parmtr(ixdim)
      equivalence (parmtr(1),Lev)
c
      double precision xt(ixdim),id(ifdim)
c
      common /toplot/ tox,xkp,fnarri
c
      double precision x(ifdim),y(ifdim)
      character yes*1,xname*8,yname*8,filena*20,a*80
      character*8 model,wl
      character*16 modl10,wl1
      common /forplo/ vkp(ifdim,invar),trgt(ifdim)
      double precision length,width
      common /wl/ width,length
c
      common /plotor/ vdorde(ifdim),vgorde(ifdim),vborde(ifdim),
     +   indvb(ifdim,2)
      common /plotdi/ ivddim,ivgdim,ivbdim
c--------------------------------------------------------------------
      integer jpair(ifdim,2)
      logical exchange
      character splot*8
c--------------------------------------------
      kagain=0
5     write(ttyw,10)
10    format(' Do you like to CLEAR the display ? [y/n]',$)
      read(ttyr,60) yes
      if (yes.ne.'n'.and.yes.ne.'N') call clear()
      if (yes.ne.'n'.and.yes.ne.'N') call initgr()
c--------------------------------------------------------------------
      write(ttyw,50)
50    format(' Give the name of the data file ..',$)
      read(ttyr,60) filena
60    format(a)
       if(.not.(ivbdim.lt.10.and.ivgdim.lt.10)) then
      write(ttyw,124) 
124   format(' Enter name for the plot file (8 char.) ... ',$)
      read(ttyr,134) splot
134   format(a)
        open(unit=9,status='unknown',file=splot)
       endif
c--------------------------------------------------------------------
      ik=0
c--------------------------------------------------------------------
203   continue
      call selecv(filena,nvar,mk,x,y)
      call orderi(type,nvar,mk,ierror)
      if (ierror.eq.1) go to 26
c--------------------------------------------------------------------
      ipair=0
      do 5100 is=1,ivbdim
         do 5200 js=1,ivgdim
               do 200 i=indvb(is,1),indvb(is,2)
      if (type*vkp(i,3).ne.vborde(is)) go to 200
      if (type*vkp(i,2).ne.vgorde(js)) go to 200
                  ipair=ipair+1
                  jpair(ipair,1)=is
                  jpair(ipair,2)=js
                  goto 5200
200            continue
5200    continue
5100  continue
      kss=1
           do 5250 is=1,ipair
            do 5300 ks=1,ivddim
               do 220 i=indvb(jpair(is,1),1),indvb(jpair(is,1),2)
      if (type*vkp(i,3).ne.vborde(jpair(is,1))) go to 220
      if (type*vkp(i,2).ne.vgorde(jpair(is,2))) go to 220
      if (type*vkp(i,1).ne.vdorde(ks)) go to 220
                  x(kss)=type*vkp(i,1)
                  y(kss)=trgt(i)
                  kss=kss+1
                  goto 5300
220            continue
5300         continue
5250        continue
            yname='Ids (mA)'
160         xmax=-1.d30
            ymax=-1.d30
            ivdbdi=kss-1
            xmin=0.0d0
            ymin=0.0d0
            do 120 i=1,ivdbdi
               y(i)=y(i)*1.d3
               xmin=dmin1(xmin,x(i)) 
               xmax=dmax1(xmax,x(i))
               ymin=dmin1(ymin,y(i))
               ymax=dmax1(ymax,y(i))
120         continue
        if ((ymax.ge.1.d-0).or.(dabs(ymin).ge.1.d-0)) go to 150
            yname='Ids (uA)'
            go to 160
150         xname='Vds (V)'
            if (type.eq.-1.0d0) xname='-Vds (V)'
            if (ik.eq.1) go to 151
            call plotax(xdim,ydim,ixinte,iyinte,xmin,ymin,
     +                    xmax,ymax,xname,yname,filena)
            xmax1=xmax
            ymax1=ymax
            ymin1=ymin
            xmin1=xmin
151         call plotda(ixinte,iyinte,ik,ivdbdi,0,xmin1,ymin1,
     +                    xmax1,ymax1,x,y,xnam,ynam)
c--------------------------------------------------------------------
      if (ik.eq.1) go to 121
c--------------------------------------------------------------------
      if (kagain.eq.0) call model4(xt,id,6)
        xwi=width
        xle=length
C       xl=(xle-2.d0*xld)*1.d-6
C       xw=xwi*1.d-6
C       if (lev.eq.3.d0) Fnarrw=fnarri/xw
C       beta=Xkp*xw/xl
C       cox=epsox/tox*xw*xl
c------------------------------------------------------------------
      kss=1
       if(ivbdim.lt.10.and.ivgdim.lt.10) then
         do 6500 j=1,ivbdim
            vb=vborde(j)
            do 6600 k=1,ivgdim
               vg=vgorde(k)
               vd=0.d0
               do 6700 l=1,10000
                 if (lev.eq.2.d0) xlamda=xlamdi
                 if (lev.eq.3.d0) beta=xkp*xw/xl
                 if (lev.eq.1.d0) call Libeq1(Vd,Vb,Vg)
                 if (lev.eq.2.d0) call Libeq2(Vd,Vb,Vg, xle, xwi)
                 if (lev.eq.3.d0) call Libeq3(Vd,Vb,Vg)
                  y(kss)=Cdrain*type
                  x(kss)=vd
                  kss=kss+1
                  vd=vd+0.1d0
                  if (vd.gt.vdorde(ivddim)) go to 6600
6700           continue
6600        continue
6500      continue
        else
          ipair=0	
          do 6510 j=ivbdim,1,-1
           do 6610 k=ivgdim,1,-1
               do 6660 i=indvb(j,1),indvb(j,2)
      if (type*vkp(i,3).ne.vborde(j)) go to 6660
      if (type*vkp(i,2).ne.vgorde(k)) go to 6660
                  ipair=ipair+1
                  jpair(ipair,1)=j
                  jpair(ipair,2)=k
                  goto 6610
6660            continue
6610       continue
6510      continue

        is=1
        js=1
6530    if (js.eq.ipair) goto 6520
        if (vborde(jpair(js+1,1)).lt.vborde(jpair(js,1))-.5)goto 6520
        js=js+1
        goto 6530    

c	Begin bubble sort on 'jpair'
6520    do 6620 i=is,js-1
	   exchange=.false.
	   do 6630 j=is,js-i+is-1
	       if (vgorde(jpair(j,2)).lt.vgorde(jpair(j+1,2))) then
		    itemp=jpair(j,2)
		    jpair(j,2)=jpair(j+1,2)
		    jpair(j+1,2)=itemp
		    itemp=jpair(j,1)
		    jpair(j,1)=jpair(j+1,1)
		    jpair(j+1,1)=itemp
		    exchange=.true.
		endif
6630       continue
		if (.NOT. exchange) goto 6540
6620	   continue

6540      is=js+1
          js=js+1
          if(js.le.ipair)goto 6530

           do 6680 j=1,ipair
            do 6710 l=1,ivddim
             do 6750 lll=indvb(jpair(j,1),1),indvb(jpair(j,1),2)
              if (vdorde(l).ne.type*vkp(lll,1)) goto 6750
              if (vgorde(jpair(j,2)).ne.type*vkp(lll,2)) goto 6750
              if (vborde(jpair(j,1)).ne.type*vkp(lll,3)) goto 6750
              vd=vdorde(l)
              vg=vgorde(jpair(j,2))
              vb=vborde(jpair(j,1))
                 if (lev.eq.2.d0) xlamda=xlamdi
                 if (lev.eq.3.d0) beta=xkp*xw/xl
                 if (lev.eq.1.d0) call Libeq1(Vd,Vb,Vg)
                 if (lev.eq.2.d0) call Libeq2(Vd,Vb,Vg, xle, xwi)
                 if (lev.eq.3.d0) call Libeq3(Vd,Vb,Vg)
                  y(kss)=Cdrain*type
                  x(kss)=vd
                  if (kss.eq.1) write(9,901) width,length
901               format('*  Plot of data',/,
     +              '*     Vds              Vgs
     +              Vbs              Ids',/,
     +              '     Width/Length=',f5.2,'/',f5.2)
                  if(kss.gt.1)then
                   if(x(kss).lt.x(kss-1))
     +             write(9,902) type*x(kss-1),type*vg,type*vb,0.
                  endif
                  write(9,902) type*vd,type*vg,type*vb,y(kss)
902               format(4(1pg15.6,2x))
                  kss=kss+1
              goto 6710
6750         continue
6710        continue
6680       continue
        close(unit=9)
        endif
c--------------------------------------------------------------------
      ik=1
      go to 160
c--------------------------------------------------------------------
121      write(ttyw,140)
140     format(' Input the  MODEL: (8 char) ... ',$)
        read(ttyr,60) model
        modl10(1:8)=' MODEL: '
        modl10(9:16)=model
        call moveto(500,iyinte+25)
        call txorig(1)
        call fmtdte(modl10)
        write(ttyw,142)
142     format(' Any comments (16 char) ....',$)
        read(ttyr,60) modl10
        call moveto(70,iyinte-5)
        call txorig(1)
        call fmtdte(modl10)
        call lintyp(0)
26      continue
        write(ttyw,28)
28      format(' Do you like to keep the graph ? [y/n].. ',$)
        read(ttyr,60) yes
        if (yes.eq.'y'.or.yes.eq.'Y') call keep()
        write(ttyw,27)
27      format(' Again for another plot ? [y/n].. ',$)
        read(ttyr,60) yes
        if (ierror.eq.0) kagain=1
        if (yes.eq.'y'.or.yes.eq.'Y') go to 5
        if (yes.eq.'n'.or.yes.eq.'N') return
        go to 26
        end
      subroutine PLOT4(xt)
      implicit double precision (a-h,o-z)
	include 'parsize.f'
c--------------------------------------------------------------------
c     Date Code  Jan 10,1982
c--------------------------------------------------------------------
c
c     Plot for the  Model1, for spice parameters extraction
c
c     Original : Kyr. Doganis                  Aug 1981 
c     Mod # 1  : kyr. Doganis                  Feb 1982 
c     Mod # 2  : kyr. Doganis                  Sep 1982 
c
c---------------------------------------------------------------------
c     Common Area  
c---------------------------------------------------------------------
c
      integer ttyw,ttyr
      common /termin/ luout,luinf,luopt,ttyw,ttyr,icont,iauto
c
      integer optflg
      character*2 k
      common /jpar/ m,n,nsig,maxfn,infer,ier,optflg,
     +       ibad,icount,idelx1,idelxl,idelxu,ieval,ifml,ifml1,ifpl,
     +    ifpl1,ifpu,igrad1,igradl,igradu,ijac,iscal1,iscall,iscalu,
     +       isw,iter,ixbad1,ixnew1,ixnewl,j,istop,inflag,
     +       icnst,kvk,kvkold,iterr,nvar,npar,iweigs,k
c
      double precision xlkeep,xwkeep
      common /xplot/ iikeep,xlkeep(10),xwkeep(10)
c
      double precision xt(ixdim),id(ifdim)
c
c---------------------------------------------------------------------
c     Model parameter variables
c---------------------------------------------------------------------
c
      double precision lev,phii,phi,phib
c
      common /param1/   Lev,Type,Xld,Toxi,Xnsubi,Vtoi,Xkpi,Gammai,
     +              Phii,Uoi,Uexpi,Ucrit,Deltai,Vmaxi,Xji,
     +        Xlamdi,Xkappa,Xnfsi,Xneffi,Xnss,Tpg,Eta,Theta,dumy(7)
c
      COMMON /MOSARG/ VTO,BETA,GAMMA,PHI,PHIB,COX,XNSUB,XNFS,XD,XJ,
     1   XLAMDA,UO,UEXP,VBP,UTRA,VMAX,XNEFF,XL,XW,VBI,VON,VDSAT,QSPOF,
     2   BETA0,BETA1,CDRAIN,XQCO,XQC,FNARRW,FSHORT
c
      COMMON /KNSTNT/ TWOPI,VT,CHARGE,EPSSIL,EPSOX,EGFET,XNI
c
      double precision parmtr(ixdim)
      equivalence (parmtr(1),Lev)
c
      common /toplot/ tox,xkp,fnarri
c------------------------------------------------------------------
c     local variables
c------------------------------------------------------------------
      character splot*3,splot1*1,splot2*1,splot3*1,splot4*1,splot5*8
      character blank
c
      double precision vdorde,vgorde,vborde
      common /plotor/ vdorde(ifdim),vgorde(ifdim),vborde(ifdim)
      common /plotdi/ ivddim,ivgdim,ivbdim
      data  blank/'      '/
c------------------------------------------------------------------
c  
c     We enter the first 3 characters for the name of the plot files
c
c------------------------------------------------------------------
c
      write(ttyw,120) 
120   format(' Enter 3 char for the plot file XXXWWLLP.dat .. ',$)
      read(ttyr,130) splot
130   format(a)
c---------------------------------------------------------------------
c
c     Special preprocessing for MOSFET models
c     Define the model parameters as a function of the
c     optimizable parmaters.
c
c---------------------------------------------------------------------
c
      call model4(xt,id,6)
      call order(type)
c
c------------------------------------------------------------------
c
c     we start creating the plot files
c        the filenames are as following  XXXWWLLP.dat
c        where xxx is the users 3 char input 
c              WW    is the channel width of the device
c              LL    is the channel length of the device
c              P     is for the plot files
c
c------------------------------------------------------------------
c            
      do 400 i=1,iikeep
        xwi=xwkeep(i)
        xwplot=xwi
        if (xwi.lt.10.0d0) xwplot=xwi*10.0d0
        iplot1=xwplot
        splot1=char(iplot1/10+ichar('0'))
        iplot2=mod(iplot1,10)
        splot2=char(iplot2+ichar('0'))
        if (iplot2.eq.0.and.xwi.lt.10.0d0) splot2='Z'
c------------------------------------------------------------------
        xle=xlkeep(i)
        xlplot=xle
        if (xle.lt.10.0d0) xlplot=xle*10.0d0
        iplot3=xlplot
        splot3=char(iplot3/10+ichar('0'))
        iplot4=mod(iplot3,10)
        splot4=char(iplot4+ichar('0'))
        if (iplot4.eq.0.and.xle.lt.10.0d0) splot4='Z'
c------------------------------------------------------------------
        splot5(1:3)=splot
        k1=4
        splot5(k1:k1)=splot1
        k1=k1+1
        splot5(k1:k1)=splot2
        k1=k1+1
        if (splot2.eq.'Z') k1=k1-1
        splot5(k1:k1)=splot3
        k1=k1+1
        splot5(k1:k1)=splot4
        k1=k1+1
        if (splot4.eq.'Z') k1=k1-1
        splot5(k1:k1)='P'
        k1=k1+1
        kres=9-k1
        if (k1.lt.9) splot5(k1:8)=blank(1:kres)
c------------------------------------------------------------------
        open(unit=9,status='new',file=splot5)
c------------------------------------------------------------------
C       xl=(xle-2.d0*xld)*1.d-6
C       xw=xwi*1.d-6
C       if (lev.eq.3.d0) Fnarrw=fnarri/xw
C       beta=Xkp*xw/xl
C       cox=epsox/tox*xw*xl
c------------------------------------------------------------------
         do 500 j=1,ivbdim
            vb=vborde(j)
            do 600 k1=1,ivgdim
               vg=vgorde(k1)
               vd=0.0d0
               lll=100000
               do 700 l=1,10000
                 if (lev.eq.2.d0) xlamda=xlamdi
                 if (lev.eq.3.d0) beta=xkp*xw/xl
                 if (lev.eq.1.d0) call Libeq1(Vd,Vb,Vg)
                 if (lev.eq.2.d0) call Libeq2(Vd,Vb,Vg, xle, xwi)
                 if (lev.eq.3.d0) call Libeq3(Vd,Vb,Vg)
                  xid=Cdrain*type
                  if (j.eq.1.and.k1.eq.1.and.l.eq.1) 
     +                write(9,901) xwkeep(i),xlkeep(i)
901               format('*  Plot of data',/,
     +              '*     Vds              Vgs
     +              Vbs              Ids',/,
     +              '     Width/Length=',f5.2,'/',f5.2)
                  write(9,902) type*vd,type*vg,type*vb,xid
902               format(4(1pg15.6,2x))
                  vd=vd+0.1d0
                  if (l.lt.lll) then
                   if (vd.gt.vdorde(ivddim)+.0000001d0)then
                    lll=0
                    vd=vd-0.2d0
                   endif
                   goto 700
                  else
                   vd=vd-0.2d0
                   if(vd.lt.-.0000001d0) go to 600
                   if(dabs(vd).lt.1.d-9) vd=0.d0
                  endif  
700           continue
600        continue
500      continue
        close(unit=9)
400   continue
      return
      end

