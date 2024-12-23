      subroutine MODEL3(xt,id,iexit)
      implicit double precision (a-h,o-z)
	include 'parsize.f'
c--------------------------------------------------------------------
c     Date Code  June 10,1985
c--------------------------------------------------------------------
c                M O D E L 3
c
c     Optimization of Model3 for FACTS parameters extraction
c
c     Original : Kyr. Doganis                  Aug 1981 
c     Mod # 1  : kyr. Doganis                  Feb 1982 
c     Mod # 2  : kyr. Doganis                  Aug 1982 
c     Rewrite  : S. Goodwin-Johansson          Jun 1985
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
      double precision lev,phii,phi,phib
c
      common /param4/   Type,Toxi,Xnsubi,Vtoi,
     +              Phii,Uoi,Xlldi,Capji,Capswi,
     +        dumy(21)
c
      COMMON /MOSARG/ VTO,BETA,GAMMA,PHI,PHIB,COX,XNSUB,XNFS,XD,XJ,
     1   XLAMDA,UO,UEXP,VBP,UTRA,VMAX,XNEFF,XL,XW,VBI,VON,VDSAT,QSPOF,
     2   BETA0,BETA1,CDRAIN,XQCO,XQC,FNARRW,FSHORT
c
      COMMON /KNSTNT/ TWOPI,VT,CHARGE,EPSSIL,EPSOX,EGFET,XNI
c
      double precision parmtr(ixdim)
      equivalence (parmtr(1),Type)
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
      idfunc='FACTS1.1'
c
      npar=9
      nvar=3
c
      prname(1)='Type'
      prname(2)='Tox'
      prname(3)='Nsub'
      prname(4)='Vto'
      prname(5)='Phi'
      prname(6)='Uo'
      prname(7)='Ld'
      prname(8)='Capj'
      prname(9)='Capjsw'
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
      Uo=Uoi
      Xnsub=Xnsubi
      Xlld=Xlldi*1.d-6
      Phib=0.8d0
      phi=phii
      vto=vtoi
      tox=toxi
c
      if (xnsub.ne.1.d30) Xnsub=xnsub*1.0d6
      tox=tox*1.d-10
      Cox=epsox/Tox
c
      if (Xnsub.eq.1.d30) go to 1400
      if (Xnsub.le.Xni) go to 1300
c
c---------------------------------------------------------------------
c     Nsub nonzero ... Process oriented model
c---------------------------------------------------------------------
      If (Phi.eq.1.d30) Phi=dmax1((2.d0*Vt*Dlog(Xnsub/Xni)),0.1d0)
      fermis=Type*0.5d0*Phi
c---------------------------------------------------------------------
      Gamma=dsqrt(2.d0*Epssil*Charge*Xnsub)/Cox
      gmma=dsqrt(2.d0*epssil/charge/xnsub)
c
c---------------------------------------------------------------------
c     Measured Vto has been input
c---------------------------------------------------------------------
1200  Vbi=Vto-Type*(Gamma*dsqrt(Phi)+Phi)
      go to 1400
1300  Xnsub=0.0d0
c
c---------------------------------------------------------------------
1400    continue
c
      if (Vto.eq.1.d30) Vto=0.0d0
      if (Phi.eq.1.d30) Phi=0.6d0
      if (Tox.eq.1.d30) Tox=0.0d0
      if (Xnsub.eq.1.d30) Xnsub=0.0d0
      if (Xlld.eq.1.d30) Xlld=0.0d0
      if (Uo.eq.1.d30) Uo=600.d0
c
      uo=uo*1.d-4
c
c---------------------------------------------------------------------
c     Go to 400 for some output after one extraction is concluded
c
c---------------------------------------------------------------------
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
         xl=(xle)*1.d-6
         xw=xwi*1.d-6
c   take care of PMOS current in beta
         beta=type*Uo*epsox/tox*xw/(xl-2.d0*xlld)
         id(i)=1.d-20
         go to 2000
2100     vdsi=type*vds(i)
         vbsi=type*vbs(i)
         vgsi=type*vgs(i)
c   Body effect
         vto=vtoi+type*gamma*(dsqrt(dabs(vbsi)+phi)-dsqrt(phi))
         avto=type*vto
c   Cutoff
         if (vgsi.le.avto) then
         id(i)=0.d0
         goto 2000
         endif
c   Linear
         if ((vgsi.gt.avto).and.((vgsi-avto).gt.vdsi)) then
         id(i)=.5d0*beta*(2.d0*(vgsi-avto)-vdsi)*vdsi
         goto 2000
         endif
c   Saturation
         if ((vgsi.gt.avto).and.((vgsi-avto).le.vdsi)) then
         id(i)=.5d0*beta*(vgsi-avto)*(vgsi-avto)
         goto 2000
         endif
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
     +               xwi,uoi,vtoi,phii
c
404   format(/,10x,'Nsub=',1pg16.5,10x,'Tox=',1pg16.5,/
     +         10x,'Kp(in)=',1pg16.5,8x,'Gamma=',1pg16.5,/
     +         10x,'Width=',1pg16.5,9x,'Mobility=',1pg16.5,/
     +         10x,'Vto=',1pg16.5,11x,'Phi=',1pg16.5,//)
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
         xl=(xle)*1.d-6
         xw=xwi*1.d-6
c  take care of PMOS current in beta
         beta=type*Uo*epsox/tox*xw/(xl-2.d0*xlld)
c   Body effect
         vto=vtoi+type*gamma*(dsqrt(dabs(vb)+phi)-dsqrt(phi))
         avto=type*vto
c   Cutoff
         if (vg.le.avto) then
         xid=0.d0
         goto 2200
         endif
c   Linear
         if ((vg.gt.avto).and.((vg-avto).gt.vd)) then
         xid=.5d0*beta*(2.d0*(vg-avto)-vd)*vd
         goto 2200
         endif
c   Saturation
         if ((vg.gt.avto).and.((vg-avto).le.vd)) then
         xid=.5d0*beta*(vg-avto)*(vg-avto)
         goto 2200
         endif
2200     write(ttyw,620) xle,xwi,type,type*vd,type*vg,type*vb,
     +               type*vto,typo*xid
620    format(/,2x,'Length=',1pg12.5,5x,'Width=',1pg12.5,5x,'Type=',
     + 1pg10.2,/2x,'Vds=',1pg12.5,2x,'Vgs=',1pg12.5,2x,'Vbs=',1pg12.5,/
     +          2x,'Vth=',1pg12.5,2x,'Ids=',1pg12.5,/)
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
         if (dabs(vbs(i)).eq.1.5d0) weight(i)=.9d0
         if (dabs(vbs(i)).eq.3.0d0) weight(i)=.8d0
         go to 550
560      xlengt=dabs(vds(i)*1.d-30)          
550   continue
      return
      end
 
      subroutine scren3(xt,nvar,npar)
      implicit double precision (a-h,o-z)
	include 'parsize.f'
c
      integer ttyw,ttyr
      common /termin/ luout,luinf,luopt,ttyw,ttyr,icont,iauto
c
      double precision lev,phii,phi,phib
      common /param4/   Type,Toxi,Xnsubi,Vtoi,
     +              Phii,Uoi,Xlldi,Capji,Capswi,
     +        dumy(21)
c
      COMMON /MOSARG/ VTO,BETA,GAMMA,PHI,PHIB,COX,XNSUB,XNFS,XD,XJ,
     1   XLAMDA,UO,UEXP,VBP,UTRA,VMAX,XNEFF,XL,XW,VBI,VON,VDSAT,QSPOF,
     2   BETA0,BETA1,CDRAIN,XQCO,XQC,FNARRW,FSHORT
c
      COMMON /KNSTNT/ TWOPI,VT,CHARGE,EPSSIL,EPSOX,EGFET,XNI
c
      double precision parmtr(ixdim)
      equivalence (parmtr(1),Type)
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
     +     indvb(ifdim,2)
      common /plotdi/ ivddim,ivgdim,ivbdim
c--------------------------------------------------------------------
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
c--------------------------------------------------------------------
      ik=0
c--------------------------------------------------------------------
203   continue
      call selecv(filena,nvar,mk,x,y)
      call orderi(type,nvar,mk,ierror)
      if (ierror.eq.1) go to 26
c--------------------------------------------------------------------
      kss=1
      do 5100 is=1,ivbdim
         do 5200 js=1,ivgdim
            do 5300 ks=1,ivddim
               do 200 i=1,mk
      if (dabs(type*vkp(i,3)-vborde(is)).gt.1.d-3) go to 200
      if (dabs(type*vkp(i,2)-vgorde(js)).gt.1.d-3) go to 200
      if (dabs(type*vkp(i,1)-vdorde(ks)).gt.1.d-3) go to 200
                  x(kss)=type*vkp(i,1)
                  y(kss)=trgt(i)
                  kss=kss+1
200            continue
5300        continue
5200    continue
5100  continue
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
        if ((dabs(ymax).ge.1.d-0).or.(dabs(ymin).ge.1.d-0)) go to 150
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
      if (kagain.eq.0) call model3(xt,id,6)
      Uo=Uoi
      Xnsub=Xnsubi
      Xlld=Xlldi*1.d-6
      phi=phii
      vto=vtoi
      tox=toxi
      if (xnsub.ne.1.d30) Xnsub=Xnsub*1.0d6
      tox=tox*1.d-10
      Uo=Uo*1.d-4
      Cox=epsox/Tox
      Gamma=dsqrt(2.d0*Epssil*Charge*Xnsub)/Cox
      gmma=dsqrt(2.d0*epssil/charge/xnsub)
        xwi=width
        xle=length
        xl=(xle)*1.d-6
        xw=xwi*1.d-6
c   Take care of PMOS current in beta
        beta=type*Uo*epsox/tox*xw/(xl-2.d0*xlld)
c------------------------------------------------------------------
      kss=1
         do 6500 j=1,ivbdim
            vb=vborde(j)
            do 6600 k=1,ivgdim
               vg=vgorde(k)
               vd=0.d0
               do 6700 l=1,10000
c   Body effect
         vto=vtoi+type*gamma*(dsqrt(dabs(vb)+phi)-dsqrt(phi))
         avto=type*vto
c   Cutoff
         if (vg.le.avto) then
         xid=0.d0
         goto 2200
         endif
c   Linear
         if ((vg.gt.avto).and.((vg-avto).gt.vd)) then
         xid=.5d0*beta*(2.d0*(vg-avto)-vd)*vd
         goto 2200
         endif
c   Saturation
         if ((vg.gt.avto).and.((vg-avto).le.vd)) then
         xid=.5d0*beta*(vg-avto)*(vg-avto)
         goto 2200
         endif
2200              y(kss)=xid
                  x(kss)=vd
                  kss=kss+1
                  vd=vd+0.1d0
                  if (vd.gt.vdorde(ivddim)) go to 6600
6700           continue
6600        continue
6500      continue
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
 
      subroutine PLOT3(xt)
      implicit double precision (a-h,o-z)
	include 'parsize.f'
c--------------------------------------------------------------------
c     Date Code  Jun 10,1985
c--------------------------------------------------------------------
c
c     Plot for the  Model3, for factse parameters extraction
c
c     Original : Kyr. Doganis                  Aug 1981 
c     Mod # 1  : kyr. Doganis                  Feb 1982 
c     Mod # 2  : kyr. Doganis                  Sep 1982 
c     rewrite  : S. Goodwin-Johansson          Jun 1985
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
      common /param4/   Type,Toxi,Xnsubi,Vtoi,
     +              Phii,Uoi,Xlldi,Capji,Capswi,
     +        dumy(21)
c
      COMMON /MOSARG/ VTO,BETA,GAMMA,PHI,PHIB,COX,XNSUB,XNFS,XD,XJ,
     1   XLAMDA,UO,UEXP,VBP,UTRA,VMAX,XNEFF,XL,XW,VBI,VON,VDSAT,QSPOF,
     2   BETA0,BETA1,CDRAIN,XQCO,XQC,FNARRW,FSHORT
c
      COMMON /KNSTNT/ TWOPI,VT,CHARGE,EPSSIL,EPSOX,EGFET,XNI
c
      double precision parmtr(ixdim)
      equivalence (parmtr(1),Type)
c
      common /toplot/ tox,xkp,fnarri
c------------------------------------------------------------------
c     local variables
c------------------------------------------------------------------
      character splot*3,splot1*1,splot2*1,splot3*1,splot4*1,splot5*8
      character blank
c
      double precision vdorde,vgorde,vborde
      integer indvb
      common /plotor/ vdorde(ifdim),vgorde(ifdim),vborde(ifdim),
     +    indvb(ifdim,2)
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
      call model3(xt,id,6)
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
      Uo=Uoi
      Xnsub=Xnsubi
      Xlld=Xlldi*1.d-6
      phi=phii
      vto=vtoi
      tox=toxi
      if (xnsub.ne.1.d30) Xnsub=Xnsub*1.0d6
      tox=tox*1.d-10
      Uo=Uo*1.d-4
      Cox=epsox/Tox
      Gamma=dsqrt(2.d0*Epssil*Charge*Xnsub)/Cox
      gmma=dsqrt(2.d0*epssil/charge/xnsub)
        xl=(xle)*1.d-6
        xw=xwi*1.d-6
c   Take care of PMOS current in beta
        beta=type*Uo*epsox/tox*xw/(xl-2.d0*xlld)
c------------------------------------------------------------------
         do 500 j=1,ivbdim
            vb=vborde(j)
            do 600 k1=1,ivgdim
               vg=vgorde(k1)
               vd=0.1d0
               lll=100000
               do 700 l=1,10000
c   Body effect
         vto=vtoi+type*gamma*(dsqrt(dabs(vb)+phi)-dsqrt(phi))
         avto=type*vto
c   Cutoff
         if (vg.le.avto) then
         xid=0.d0
         goto 2200
         endif
c   Linear
         if ((vg.gt.avto).and.((vg-avto).gt.vd)) then
         xid=.5d0*beta*(2.d0*(vg-avto)-vd)*vd
         goto 2200
         endif
c   Saturation
         if ((vg.gt.avto).and.((vg-avto).le.vd)) then
         xid=.5d0*beta*(vg-avto)*(vg-avto)
         goto 2200
         endif
2200     continue
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

