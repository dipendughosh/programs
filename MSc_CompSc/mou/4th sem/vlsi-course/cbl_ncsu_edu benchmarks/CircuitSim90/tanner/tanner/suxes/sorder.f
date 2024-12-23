      subroutine order(type)
      implicit double precision(a-h,o-z)
	include 'parsize.f'
c
      integer optflg
      character*2 k
      common /jpar/ m,n,nsig,maxfn,infer,ier,optflg,
     +       ibad,icount,idelx1,idelxl,idelxu,ieval,ifml,ifml1,ifpl,
     +    ifpl1,ifpu,igrad1,igradl,igradu,ijac,iscal1,iscall,iscalu,
     +       isw,iter,ixbad1,ixnew1,ixnewl,j,istop,inflag,
     +       icnst,kvk,kvkold,iterr,nvar,npar,iweigs,k
c
      double precision v,vkp
      common /vars/ v(ifdim,invar),vkp(ifdim,invar)
      double precision vds(ifdim),vgs(ifdim),vbs(ifdim)
      double precision vdorde,vgorde,vborde
      integer indvb
      common /plotor/ vdorde(ifdim),vgorde(ifdim),vborde(ifdim),
     +    indvb(ifdim,2)
      common /plotdi/ ivddim,ivgdim,ivbdim
      integer iz(ifdim)
c-------------------------------------------------------------
c     find the real biases
c-------------------------------------------------------------
      ii=0
      do 100 i=1,m
         if (vkp(i,1).gt.1.d10) go to 100
         ii=ii+1
         vds(ii)=type*vkp(i,1)
         if (nvar.gt.1) vgs(ii)=type*vkp(i,2)
         if (nvar.gt.2) vbs(ii)=type*vkp(i,3)
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
      k1=1
600   vdorde(i)=vdorde(k1)
      if (i.eq.ii) k1=mtemp-ii
      i=i+1
      k1=k1+1
      if (k1.le.iikeep) go to 600
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
      k1=1
1600  vgorde(i)=vgorde(k1)
      if (i.eq.ii) k1=mtemp-ii
      i=i+1
      k1=k1+1
      if (k1.le.iikeep) go to 1600
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
      do 2400 i=1,iikeep
         if (vbmin.eq.vbs(i)) iz(i)=1
         if (vbmax.eq.vbs(i)) iz(i)=1
2400  continue
c-------------------------------------------------------------
c     order the array of vds
c-------------------------------------------------------------
      ii=ii+1
      vborde(ii)=vbmin
      vborde(mtemp-ii+1)=vbmax
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
      k1=1
2600  vborde(i)=vborde(k1)
      if (i.eq.ii) k1=mtemp-ii
      i=i+1
      k1=k1+1
      if (k1.le.iikeep) go to 2600
      ivbdim=i-1
c-------------------------------------------------------------
3000  continue
      return
      end

