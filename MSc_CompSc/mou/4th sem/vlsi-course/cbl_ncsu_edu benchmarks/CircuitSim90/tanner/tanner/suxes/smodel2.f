      subroutine MODEL2(xt,id,iexit)
      implicit double precision (a-h,o-z)
	include 'parsize.f'
c--------------------------------------------------------------------
c     Date Code  Aug 10,1982
c--------------------------------------------------------------------
c                M O D E L 2
c
c     Optimization of Model2 Mobility parameters extraction
c
c     Original : Kyr. Doganis                  Aug 1982 
c     Mod # 1  : kyr. Doganis                  Aug 1982 
c     Mod # 2  : kyr. Doganis                  Sep 1982 
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
      double precision xt(ixdim),id(ifdim)
c---------------------------------------------------------------------
c     model parameters
c---------------------------------------------------------------------
c
      common /param3/ a0,a1,a2,a3,b0,b1,b2,b3,n0,u0,a4,b4,dum(18)
c
      double precision parmtr(ixdim)
      equivalence (parmtr(1),a0)
c
      integer ixl(10),ixw(10)
c---------------------------------------------------------------------
c     local variables
c---------------------------------------------------------------------
c
      double precision n0
c
c------------------------------------------------------------------
c     Now the subroutine MODEL2 starts
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
      idfunc='Mobility'
c
      npar=12
      nvar=1
c
      prname(1)=' a0 '
      prname(2)=' a1 '
      prname(3)=' a2 '
      prname(4)=' a3 '
      prname(5)=' b0 '
      prname(6)=' b1 '
      prname(7)=' b2 '
      prname(8)=' b3 '
      prname(9)=' n0 '
      prname(10)=' u0 '
      prname(11)=' a4 '
      prname(12)=' b4 '
c
      return
c--------------------------------------------------------------
c     
c     In this section we introduce some constants which will be 
c        of the same value throughtout the optimization.
c        These constants enter the model subroutine.
c--------------------------------------------------------------
200   continue
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
370   continue
c
c---------------------------------------------------------------------
c     Go to 400 for some output after one extraction is concluded
c
c---------------------------------------------------------------------
      if (iexit.eq.6) return
      if (iexit.eq.4) go to 400
c---------------------------------------------------------------------
c     Mobility modeling
c
c     Here the mobility calculation occurs
c     for the different elements
c     Boron and Phosphorous
c
c---------------------------------------------------------------------
      ii=1
      do 2000  i=1,m
         if (ixl(ii).ne.i) go to 2100
         xle=xlkeep(ii)
         xwi=xwkeep(ii)
         ii=ii+1
         xl=(xle-2.d0*xld)*1.d-6
         xw=xwi*1.d-6
         id(i)=1.d-20
         go to 2000
2100     vdsi=vds(i)
         xlog=dlog10(vdsi/n0)
         above=a0+xlog*(a1+xlog*(a2+xlog*(a3+xlog*a4)))
         down =b0+xlog*(b1+xlog*(b2+xlog*(b3+xlog*b4)))
         id(i)=u0*10.0d0**(above/down)
c         write(10,*) vdsi,id(i)
c         write(11,*) vdsi,above
c         write(12,*) vdsi,down
2000  continue
      return
c---------------------------------------------------------------------
c     some results to go out
c---------------------------------------------------------------------
400   continue
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
         if (dabs(vds(i)).gt.1.d30) go to 560
         if (isetwe.ne.1) go to 550
         if (vds(i).ge.1.d22.or.vds(i).le.1.d13) 
     +   weight(i)=10.0d0
         go to 550
560      isetwe=1
550   continue
      return
      end
      subroutine scren2(xt,nvar,npar)
      implicit double precision (a-h,o-z)
	include 'parsize.f'
c
      integer ttyw,ttyr
      common /termin/ luout,luinf,luopt,ttyw,ttyr,icont,iauto
c
      common /param3/ a0,a1,a2,a3,b0,b1,b2,b3,n0,u0,a4,b4,dum(18)
      double precision n0
c
      double precision parmtr(ixdim)
      equivalence (parmtr(1),a0)
c
      double precision xt(ixdim),id(ifdim)
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
     +    indvb(ifdim,2)
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
      call orderi(1.0d0,nvar,mk,ierror)
      if (ierror.eq.1) go to 26
c--------------------------------------------------------------------
      kss=1
            do 5300 ks=1,ivddim
               do 200 i=1,mk
      if (dabs(vkp(i,1)-vdorde(ks)).gt.1.d-3) go to 200
                  x(kss)=vkp(i,1)
                  y(kss)=trgt(i)
                  kss=kss+1
200            continue
5300        continue
            yname='Mob*1000'
160         xmin=13.0d0
            ymin=0.0d0
            xmax=-1.d30
            ymax=-1.d30
            ivdbdi=kss-1
            do 120 i=1,ivdbdi
               x(i)=dlog10(x(i))   
               y(i)=y(i)*1.d-3
               xmin=dmin1(xmin,x(i)) 
               xmax=dmax1(xmax,x(i))
               ymin=dmin1(ymin,y(i))
               ymax=dmax1(ymax,y(i))
120         continue
            xname='Log(n)'
            if (ik.eq.1) go to 151
            call plotax(xdim,ydim,ixinte,iyinte,xmin,ymin,
     +                    xmax,ymax,xname,yname,filena)
            xmax1=xmax
            ymax1=ymax
            xmin1=xmin
            ymin1=ymin
151         call plotda(ixinte,iyinte,ik,ivdbdi,1,xmin1,ymin1,
     +                    xmax1,ymax1,x,y,xname,yname)
c--------------------------------------------------------------------
      if (ik.eq.1) go to 121
c--------------------------------------------------------------------
      if (kagain.eq.0)  call model2(xt,id,6)
c------------------------------------------------------------------
      vdsmax=dlog10(vdorde(ivddim))
      kss=1
      vd=dlog10(vdorde(1))
      do 6700 l=1,10000
         xlog=vd-dlog10(n0)
         above=a0+xlog*(a1+xlog*(a2+xlog*(a3+xlog*a4)))
         down =b0+xlog*(b1+xlog*(b2+xlog*(b3+xlog*b4)))
         y(kss)=u0*10.0d0**(above/down)
         x(kss)=10.d0**vd
         kss=kss+1
         vd=vd+(vdsmax-dlog10(vdorde(1)))/200.d0
         if (vd.gt.vdsmax) go to 6600
6700     continue
6600        continue
c--------------------------------------------------------------------
      ik=1
      go to 160
c--------------------------------------------------------------------
121      write(ttyw,140)
140     format(' Input the  MODEL: (8 char) ... ',$)
        read(ttyr,60) model
        modl10(1:8)=' MODEL: '
        modl10(9:16)=model
        call moveto(70,iyinte+25)
        call txorig(1)
        call fmtdte(modl10)
        write(ttyw,142)
142     format(' Any comments (16 char) ....',$)
        read(ttyr,60) modl10
        call moveto(200,iyinte+25)
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
      subroutine PLOT2(xt)
      implicit double precision (a-h,o-z)
	include 'parsize.f'
c--------------------------------------------------------------------
c     Date Code  Jan 10,1982
c--------------------------------------------------------------------
c
c     Plot for the  Mobility parameters extraction
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
      common /param3/ a0,a1,a2,a3,b0,b1,b2,b3,n0,u0,a4,b4,dum(18)
c
      double precision parmtr(ixdim)
      equivalence (parmtr(1),a0)
c
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
c
      double precision n0
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
c------------------------------------------------------------------
      call model2(xt,id,6)
      call order(1.0d0)
c
c------------------------------------------------------------------
      vdsmax=dlog10(vdorde(ivddim))
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
              vd=dlog10(vdorde(1))
              do 700 l=1,10000
                 xlog=vd-dlog10(n0)
         above=a0+xlog*(a1+xlog*(a2+xlog*(a3+xlog*a4)))
         down =b0+xlog*(b1+xlog*(b2+xlog*(b3+xlog*b4)))
                 xid=u0*10.0d0**(above/down)
                 if (j.eq.1.and.k1.eq.1.and.l.eq.1) 
     +                write(9,901) xwkeep(i),xlkeep(i)
901               format('*  Plot of data',/,
     +              '     Width/Length=',f5.2,'/',f5.2)
                 write(9,1000) 10d0**vd,xid
1000             format(2(1pg15.6,2x))
                 vd=vd+0.1d0
                 if (vd.gt.vdsmax) go to 500
700            continue
500      continue
        close(unit=9)
400   continue
      return
      end    

