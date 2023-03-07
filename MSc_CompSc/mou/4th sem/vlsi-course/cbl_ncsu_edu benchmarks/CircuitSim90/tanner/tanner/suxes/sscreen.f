      subroutine selecv(filena,nvar,m,x,y)
      implicit double precision (a-h,o-z)
	include 'parsize.f'
      integer ttyw,ttyr
      common /termin/ luout,luinf,luopt,ttyw,ttyr,icont,iauto

c
      double precision x(ifdim),y(ifdim)
      common /forplo/ vkp(ifdim,invar),trgt(ifdim)
c
      character*4 run,wafer,leng,widt,typ,locati
      common /info/ run,wafer,leng,widt,typ,locati
c
      double precision length,width
      common /wl/ width,length
c
      character filena*20
      character a*80,word*80,id1,id2,id3,id4
      double precision vdshor(1000)
      double precision vgshor(1000)
      double precision vbshor(1000)
      data id1/' '/,id2/','/,id3/'='/,id4/'/'/
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
      if (xvar.lt.vdmax+1.d-3) go to 1140
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
      if (xvar.lt.vgmax+1.d-3) go to 1160     
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
      if (xvar.lt.vbmax+1.d-3) go to 1180     
1190  continue
c--------------------------------------------------------------------
      open(unit=2,status='old',file=filena)
190   read(2,60,err=600) a
60    format(a)
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
      call decode(word,xvar,filena)
      width=xvar
      widt=word(1:4)
c--------------------------------------------------------------------
c     finds the length
c--------------------------------------------------------------------
      call parse(a,word,ipoint,id1,id4)
      call decode(word,xvar,filena)
      length=xvar
      leng=word(1:4)
      i=0
200   i=i+1
      read(2,*,end=500) (vkp(i,j),j=1,nvar),trgt(i)
      if (nvar.eq.1) go to 5290
      if (nvar.eq.2) go to 5190
      do 5100 ishort=1,ivbsho
         if (ivbsho.ne.1) go to 5110
         if (vkp(i,3).lt.vbmin-1.d-3) go to 5100
         if (vkp(i,3).gt.vbmax+1.d-3) go to 5100
         go to 5190
5110     if (dabs(vkp(i,3)-vbshor(ishort)).gt.1.d-3) go to 5100
5190     do 5200 jshort=1,ivgsho
            if (ivgsho.ne.1) go to 5210
            if (vkp(i,2).lt.vgmin-1.d-3) go to 5200
            if (vkp(i,2).gt.vgmax+1.d-3) go to 5200
            go to 5290
5210        if (dabs(vkp(i,2)-vgshor(jshort)).gt.1.d-3) go to 5200
5290        do 5300 kshort=1,ivdsho
               if (ivdsho.ne.1) go to 5310
               if (vkp(i,1).lt.vdmin-1.d-3) go to 5300
               if (vkp(i,1).gt.vdmax+1.d-3) go to 5300
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
205   y(i)=trgt(i)
      x(i)=vkp(i,1)
      go to 200
500   close(unit=2)
      i=i-1
      m=i
600   return
      end
 
      subroutine orderi(type,nvar,m,ierror)
      implicit double precision(a-h,o-z)
	include 'parsize.f'
c
      integer ttyw,ttyr
      common /termin/ luout,luinf,luopt,ttyw,ttyr,icont,iauto
c
      common /forplo/ vkp(ifdim,invar),trgt(ifdim)
      double precision vds(ifdim),vgs(ifdim),vbs(ifdim)
      common /plotor/ vdorde(ifdim),vgorde(ifdim),vborde(ifdim),
     +  indvb(ifdim,2)
      common /plotdi/ ivddim,ivgdim,ivbdim
      integer iz(ifdim),ipair(ifdim)
c-------------------------------------------------------------
c     find the real biases
c-------------------------------------------------------------
      ierror=0
      if (m.le.0.or.nvar.gt.3.or.type.eq.0.0d0) go to 4000
      ii=0
      do 100 i=1,m
         if (vkp(i,1).gt.1.d10) go to 100
         ii=ii+1
         vds(ii)=type*vkp(i,1)
         if (nvar.gt.1) vgs(ii)=type*vkp(i,2)
         if (nvar.gt.2) vbs(ii)=type*vkp(i,3)
         if (nvar.gt.2) ipair(ii)=i
100   continue
      iikeep=ii
c-------------------------------------------------------------
c     set the iz array to 0 elements
c-------------------------------------------------------------
      do 200 i=1,iikeep
         iz(i)=0
200   continue
c-------------------------------------------------------------
c     find the min and the max of vds,s
c-------------------------------------------------------------
      mtemp=iikeep
      ii=0
250   iistop=0
      vdmin=1.d30
      vdmax=-1.d30
c$dir scalar
      do 300 i=1,iikeep
         if (iz(i).eq.1) go to 300
         iistop=iistop+1
         vdmin=dmin1(vdmin,vds(i))
         vdmax=dmax1(vdmax,vds(i))
300   continue
      if (iistop.eq.0) go to 500
c-------------------------------------------------------------
c     set 1,s in the iz(i) where the min or the max occur
c-------------------------------------------------------------
      do 400 i=1,iikeep
         if (vdmin.eq.vds(i)) iz(i)=1
         if (vdmax.eq.vds(i)) iz(i)=1
400   continue
c-------------------------------------------------------------
c     order the array of vds
c-------------------------------------------------------------
      ii=ii+1
      vdorde(ii)=vdmin
      vdorde(mtemp-ii+1)=vdmax
      if (vdmin.lt.vdmax) go to 250
      mtemp=mtemp+1
c-------------------------------------------------------------
c     take care of one element left
c-------------------------------------------------------------
500   continue
c-------------------------------------------------------------
c     reorder the array
c-------------------------------------------------------------
      i=1
      k=1
600   vdorde(i)=vdorde(k)
      if (i.eq.ii) k=mtemp-ii
      i=i+1
      k=k+1
      if (k.le.iikeep) go to 600
      ivddim=i-1
c-------------------------------------------------------------
c     now for the vgs bias
c-------------------------------------------------------------
      if (nvar.lt.2) go to 3000
c-------------------------------------------------------------
c     set the iz array to 0 elements
c-------------------------------------------------------------
      do 1200 i=1,iikeep
         iz(i)=0
1200  continue
c-------------------------------------------------------------
c     find the min and the max of vgs,s
c-------------------------------------------------------------
      mtemp=iikeep
      ii=0
1250  iistop=0
      vgmin=1.d30
      vgmax=-1.d30
c$dir scalar
      do 1300 i=1,iikeep
         if (iz(i).eq.1) go to 1300
         iistop=iistop+1
         vgmin=dmin1(vgmin,vgs(i))
         vgmax=dmax1(vgmax,vgs(i))
1300  continue
      if (iistop.eq.0) go to 1500
c-------------------------------------------------------------
c     set 1,s in the iz(i) where the min or the max occur
c-------------------------------------------------------------
      do 1400 i=1,iikeep
         if (vgmin.eq.vgs(i)) iz(i)=1
         if (vgmax.eq.vgs(i)) iz(i)=1
1400  continue
c-------------------------------------------------------------
c     order the array of vgs
c-------------------------------------------------------------
      ii=ii+1
      vgorde(ii)=vgmin
      vgorde(mtemp-ii+1)=vgmax
      if (vgmin.lt.vgmax) go to 1250
      mtemp=mtemp+1
c-------------------------------------------------------------
c     take care of one element left
c-------------------------------------------------------------
1500  continue
c-------------------------------------------------------------
c     reorder the array
c-------------------------------------------------------------
      i=1
      k=1
1600  vgorde(i)=vgorde(k)
      if (i.eq.ii) k=mtemp-ii
      i=i+1
      k=k+1
      if (k.le.iikeep) go to 1600
      ivgdim=i-1
c-------------------------------------------------------------
c     take care of the vbs
c-------------------------------------------------------------
      if (nvar.lt.3) go to 3000
c-------------------------------------------------------------
c     set the iz array to 0 elements
c-------------------------------------------------------------
      do 2200 i=1,iikeep
         iz(i)=0
2200  continue
c-------------------------------------------------------------
c     find the min and the max of vbs,s
c-------------------------------------------------------------
      mtemp=iikeep
      ii=0
2250  iistop=0
      vbmin=1.d30
      vbmax=-1.d30
c$dir scalar
      do 2300 i=1,iikeep
         if (iz(i).eq.1) go to 2300
         iistop=iistop+1
         vbmin=dmin1(vbmin,vbs(i))
         vbmax=dmax1(vbmax,vbs(i))
2300  continue
      if (iistop.eq.0) go to 2500
c-------------------------------------------------------------
c     set 1,s in the iz(i) where the min or the max occur
c-------------------------------------------------------------
      jjpair=0
      kkpair=0
      do 2400 i=iikeep,1,-1
         if (vbmin.eq.vbs(i)) iz(i)=1
         if (vbmax.eq.vbs(i)) iz(i)=1
         if (vbmin.eq.vbs(i).and.jjpair.eq.0) jjpair=i
         if (vbmax.eq.vbs(i).and.kkpair.eq.0) kkpair=i
         if (vbmin.eq.vbs(i)) jpair=i
         if (vbmax.eq.vbs(i)) kpair=i
2400  continue
c-------------------------------------------------------------
c     order the array of vds
c-------------------------------------------------------------
      ii=ii+1
      vborde(ii)=vbmin
      indvb(ii,1)=ipair(jpair)
      indvb(ii,2)=ipair(jjpair)
      vborde(mtemp-ii+1)=vbmax
      indvb(mtemp-ii+1,1)=ipair(kpair)
      indvb(mtemp-ii+1,2)=ipair(kkpair)
      if (vbmin.lt.vbmax) go to 2250
      mtemp=mtemp+1
c-------------------------------------------------------------
c     take care of one element left
c-------------------------------------------------------------
2500  continue
c-------------------------------------------------------------
c     reorder the array
c-------------------------------------------------------------
      i=1
      k=1
2600  vborde(i)=vborde(k)
      indvb(i,1)=indvb(k,1)
      indvb(i,2)=indvb(k,2)
      if (i.eq.ii) k=mtemp-ii
      i=i+1
      k=k+1
      if (k.le.iikeep) go to 2600
      ivbdim=i-1
c-------------------------------------------------------------
3000  continue
      return
4000  write(ttyw,4010) type,m,nvar
4010  format(/,'*************** ERROR ******************',/,
     + ' One of the following is wrong specified :',/,
     + ' Type=',1pg12.4,'M=',i4,' Nvar=',i4)
      ierror=1
      return
      end
 
        subroutine plotax(xdim,ydim,ixinte,iyinte,
     +                      xmin,ymin,xmax,ymax,idx,idy,filena)
c
      implicit double precision(a-h,o-z)
      double precision xy(0:8),xx(0:8)
      character idx*8,idy*8,name*8,a*80,filena*20
      character*4 run,wafer,leng,widt,typ,locati
      common /info/ run,wafer,leng,widt,typ,locati
c----------------------------------------------------------
c       define the yincrement for the scale
c----------------------------------------------------------
        ik=0
        aa=0.0d0
        bb=ymin
4       continue
        xy(0)=0.8d0
        xy(1)=1.0d0
        xy(2)=1.6d0
        xy(3)=2.0d0
        xy(4)=3.2d0
        xy(5)=4.0d0
        xy(6)=5.0d0
        xy(7)=6.4d0
        xy(8)=8.0d0
        xdy=1.d-30
        if (bb.lt.0.0d0) xdy=-1.d-30
        if (bb.eq.0.0d0) go to 305 
c----------------------------------------------------------
c       find the scale for the yaxis for 8 divisions
c----------------------------------------------------------
100     do 200 i=1,8
           aa=xy(i)*xdy
           if (aa.gt.0.0d0) go to 210
           if (aa.lt.bb) go to 300
           go to 200
210        if (aa.gt.bb) go to 300
200     continue
 
        xdy=10.0d0*xdy
        go to 100
c----------------------------------------------------------
c       reset the ymax 
c----------------------------------------------------------
300     continue
        if (ik.eq.1) go to 310
305     ik=1
        if (aa.gt.0.0d0) bb=xdy*xy(i-1)
        if (aa.lt.0.0d0) bb=aa
        bbb=ymin
        ymin=bb
        bb=ymax-(bbb+bb)/2.d0
        go to 4
310     ymax=ymin+aa
        kyscal=8
c----------------------------------------------------------
c       or there are 5 divisions for yaxis 
c----------------------------------------------------------
        if (i.eq.1.or.i.eq.3.or.i.eq.5.or.i.eq.6) kyscal=5
        open(unit=2,status='new',file='fooy.dat')
c----------------------------------------------------------
c       write the yscale tiks 
c----------------------------------------------------------
           if (idy(1:1).ne.'>') write(2,355) ymin
           if (idy(1:1).eq.'>') write(2,350) ymin
        do 400 i=1,kyscal-1
           d=(ymin+i*(ymax-ymin)/kyscal)
           if (idy(1:1).ne.'>') write(2,355) d
           if (idy(1:1).eq.'>') write(2,350) d
350        format(pg8.1)
355        format(f8.3)
400      continue
         close(unit=2)
c
c----------------------------------------------------------
c       define the xincrement for the scale
c----------------------------------------------------------
        ik=0
        aa=0.0d0
        bb=xmin
14      continue
        xx(0)=0.8d0
        xx(1)=1.0d0
        xx(2)=1.6d0
        xx(3)=2.0d0
        xx(4)=3.2d0
        xx(5)=4.0d0
        xx(6)=5.0d0
        xx(7)=6.4d0
        xx(8)=8.0d0
        xdx=1.d-30
        if (bb.lt.0.0d0) xdx=-1.d-30
        if (bb.eq.0.0d0) go to 505
c----------------------------------------------------------
c       find the scale for the yaxis for 8 divisions
c----------------------------------------------------------
410     do 420 i=1,8
           aa=xx(i)*xdx
           if (aa.gt.0.0d0) go to 430
           if (aa.lt.bb) go to 500
           go to 420
430        if (aa.gt.bb) go to 500
420     continue
        xdx=10.0d0*xdx
        go to 410
c----------------------------------------------------------
c       reset the xmax 
c----------------------------------------------------------
500     continue
        if(ik.eq.1)goto510
505     ik=1
        if (aa.gt.0.0d0) bb=xdx*xx(i-1)
        if (aa.lt.0.0d0) bb=aa
        xmin=bb
        bb=xmax-xmin
        go to 14
510     xmax=xmin+aa
        kxscal=8
c----------------------------------------------------------
c       or there are 5 divisions for xaxis 
c----------------------------------------------------------
        if (i.eq.1.or.i.eq.3.or.i.eq.5.or.i.eq.6) kxscal=5
        open(unit=2,status='new',file='foox.dat')
c----------------------------------------------------------
c       write the xscale tiks 
c----------------------------------------------------------
           if (idx(1:1).ne.'>') write(2,355) xmin
           if (idx(1:1).eq.'>') write(2,350) xmin
        do 800 i=1,kxscal-1
           d=(xmin+i*(xmax-xmin)/kxscal)
           if (idx(1:1).ne.'>') write(2,355) d
           if (idx(1:1).eq.'>') write(2,350) d
800      continue
         close(unit=2)
c----------------------------------------------------------
c        find the internal dimensions
c----------------------------------------------------------
        ixtic=jidnnt((xdim-70.0d0)/10.0d0)
        iytic=jidnnt((ydim-40.0d0)/10.0d0)
        if (kxscal.eq.8) ixtic=jidnnt((xdim-70.0d0)/16.0d0)
        if (kyscal.eq.8) iytic=jidnnt((ydim-40.0d0)/16.0d0)
        ixinte=2*kxscal*ixtic+1
        iyinte=2*kyscal*iytic+1
c----------------------------------------------------------
c       draw the internal box
c----------------------------------------------------------
        call moveto(50,20)
        call drawbo(50,20,ixinte,iyinte)
c----------------------------------------------------------
        if (idx(1:1).ne.'V'.and.idx(1:1).ne.'v'.
     +and.idx(1:1).ne.'-') go to 501
        run=filena(4:5)
        wafer=filena(2:3)
        typ=filena(6:6)
        locati=filena(1:1)
c----------------------------------------------------------
        a(1:4)='RUN='
        a(5:6)=run
        call moveto(70,iyinte+25)
        call txorig(1)
        call fmtdte(a(1:6))
c----------------------------------------------------------
        a(1:6)='WAFER='
        a(7:8)=wafer
        call moveto(130,iyinte+25)
        call txorig(1)
        call fmtdte(a(1:8))
c----------------------------------------------------------
        a(1:5)='TYPE='
        a(6:6)=typ
        call moveto(195,iyinte+25)
        call txorig(1)
        call fmtdte(a(1:6))
c----------------------------------------------------------
        a(1:4)='W/L='
        a(5:6)=widt
        a(7:7)='/'
        a(8:11)=leng
        call moveto(260,iyinte+25)
        call txorig(1)
        call fmtdte(a(1:11))
c----------------------------------------------------------
        a(1:4)='LOC='
        a(5:8)=locati
        call moveto(340,iyinte+25)
        call txorig(1)
        call fmtdte(a(1:8))
c----------------------------------------------------------
501     call moveto(420,iyinte+25)
        call txorig(1)
        call fmtdte(filena(1:10))
        call moveto(50,20)
c----------------------------------------------------------
c       draw the xtics
c----------------------------------------------------------
        iixtic=50
        do 1000 i=1,kxscal
           iixtic=iixtic+ixtic 
           if (iixtic.ge.ixinte+49) go to 1100
           call moveto(iixtic,23)
           call drawto(iixtic,20)
           call moveto(iixtic,iyinte+16)
           call drawto(iixtic,iyinte+19)
           iixtic=iixtic+ixtic
           if (iixtic.ge.ixinte+49) go to 1100
           call moveto(iixtic,26)
           call drawto(iixtic,20)
           call moveto(iixtic,iyinte+13)
           call drawto(iixtic,iyinte+19)
1000    continue
1100    open (unit=2,status='old',file='foox.dat')
        iixtic=50
        do 1200 i=1,kxscal
           read(2,1250,end=1300) a
1250       format(a)
c           name=a(1:6)
           call moveto(iixtic,4)
           call txorig(4)
           call fmtdte(a(2:7))
           iixtic=iixtic+2*ixtic
1200     continue
1300     close(unit=2,status='delete')
        call moveto(ixinte+30,4)
        call txorig(1)
        call fmtdte(idx)
        iiytic=20
        do 2000 i=1,kyscal
           iiytic=iiytic+iytic 
           if (iiytic.ge.iyinte+19) go to 2100
           call moveto(50,iiytic)
           call drawto(53,iiytic)
           call moveto(ixinte+49,iiytic)
           call drawto(ixinte+46,iiytic)
           iiytic=iiytic+iytic
           if (iiytic.ge.iyinte+19) go to 2100
           call moveto(50,iiytic)
           call drawto(56,iiytic)
           call moveto(ixinte+49,iiytic)
           call drawto(ixinte+43,iiytic)
2000    continue
2100    open (unit=2,status='old',file='fooy.dat')
        iiytic=20
        do 2200 i=1,kyscal
           read(2,1250,end=2300) a
c           name=a(1:6)
           call moveto(43,iiytic)
           call txorig(8)
           call fmtdte(a(1:7))
           iiytic=iiytic+2*iytic
2200     continue
2300    close(unit=2,status='delete')
        call moveto(40,iyinte+15)
        call txorig(7)
        call fmtdte(idy)
        call moveto(50,20)
        return
        end
        subroutine plotda(ixinte,iyinte,linety,n,istart,
     +             xmin,ymin,xmax,ymax,x,y,name1,name2)
        implicit double precision(a-h,o-z)
        double precision x(1),y(1)
        character*6 name1,name2
c
        do 100 i=1,n
           ixplot=50+jidnnt((x(i)-xmin)*(ixinte-1)/(xmax-xmin)) 
           iyplot=20+jidnnt((y(i)-ymin)*(iyinte-1)/(ymax-ymin))
           if (i.eq.1) go to 210
           if (x(i).gt.x(i-1)) go to 200
210        call moveto(50,20)
           if (istart.eq.1) call moveto(ixplot,iyplot)
200        if (linety.eq.1) go to 300
           if (ixplot.lt.52.or.iyplot.lt.22) go to 100
           if (ixplot.gt.(ixinte+47).or.
     +         iyplot.gt.(iyinte+17)) go to 100
           call drawbo(ixplot-2,iyplot-2,4,4)
           go to 100
300        if (ixplot.lt.50.or.iyplot.lt.20) go to 100
           if (ixplot.gt.(ixinte+49).or.
     +         iyplot.gt.(iyinte+19)) go to 100
           call drawto(ixplot,iyplot)
100     continue
        call moveto(50,20)   
        return
        end
 
        subroutine drawto(ix,iy)
c--------------------------------------------------------------------
c       coordinates are absolute. (pen is normally left lowered).
c--------------------------------------------------------------------
        character*1 esc
        esc=char(27)
        write(6,100) esc,ix,iy
100     format(x,a,'*pf',i3,x,i3,'Z',$)
        write(11,300) ix,iy
300     format(x,'PD 'i3,x,i3,';')
c        read(5,200) dummy
200     format(a)
        return
        end
        subroutine lintyp(n)
        character*1 esc
        esc=char(27)
        write(6,100) esc,n
100     format(x,a,'*m',i2,'B',$)
        write(11,200) n
200     format(x,'SP 'i2,';')
        return
        end
        subroutine moveto(ix,iy)
        character*1 esc
        esc=char(27)
c--------------------------------------------------------------------
c       and lower pen, ready to draw.
c--------------------------------------------------------------------
        write(6,100) esc,ix,iy
100     format(x,a,'*paf',i3,x,i3,'Z',$)
        write(11,200) ix,iy
200     format(x,'PU 'i3,x,i3,x,';')
        return
        end
        subroutine initgr()
        character*1 esc, etx
        etx=char(13)
        esc=char(27)
c--------------------------------------------------------------------
c      turn off alfanum.
c      turn on graphics display and clear it.
c--------------------------------------------------------------------
        write(6,100) esc
100     format(x,a,'*dC',$)
        write(11,200)etx
        write(11,300)
200     format(x,'DF SC -10 730 -10 380 DT',a)
300     format(x,'SP 1 CS 10;')
        return
        end 
	Subroutine drawbo(llx,lly,iwidth,iheigh)
c--------------------------------------------------------------------
c       lower left corner is (llx,lly), 
c       width and height include the border lines.
c       pen position is first moved to ll corner, 
c       then stays there after drawing
c       the box. pen is lowered at the end. 
c       llx and lly are absolute coordinates.
c--------------------------------------------------------------------
	character*1 esc
        esc=char(27)
	idx=iwidth-1
	idy=iheigh-1
	write(6,100) esc,llx,lly,idx,idy,-idx,-idy
100	format(x,a,'*paf',i5,x,i5,'g',i5,',0 0,',i5,x,i5,',0 0,',i5,'Z',$)
        write(11,200) llx,lly,idx,idy,-idx,-idy
200     format(x,'PU ',i5,x,i5,'PD PR ',i5,' 0 0 ',i5,x,i5,' 0 0 ',i5,
     + 'PA;')
	return
	end
      subroutine fmtdte(string)
	character*(*) string
	character*1 esc, etx
	esc=char(27)
        etx=char(13)
	write (6,100) esc, string
100	format(x,a,'*l',a)
        write (11,200) string, etx
200     format(x,'LB ',a,a)
	return
	end
      Subroutine Clear()
	character*1 esc
	esc=char(27)
	write(6,100) esc
100	format(x,a,'*dA',$)
	return
	end
	subroutine Keep()
	character*1 esc
	esc=char(27)
	write(6,100) esc
100	format(x,a,'*dB',$)
	return
	end
	subroutine txorig(ix)
	character*1 esc
	esc=char(27)
	write (6,100) esc, ix
100	format(x,a,'*m',i5,'Q',$)
        write (11,200) ix
200     format(x,'LO ',i5,';')
	return
	end
c
        integer function jidnnt(x)
        double precision x
c      nearest integer to double precision value
        jidnnt=idint(x+dsign(.5d0,x))
        return
        end

