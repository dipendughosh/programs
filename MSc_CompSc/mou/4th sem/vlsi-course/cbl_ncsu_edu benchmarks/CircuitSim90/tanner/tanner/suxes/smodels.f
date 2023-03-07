      subroutine TFUN1(xt,id,iexit)
      implicit double precision (a-h,o-z)
	include 'parsize.f'
c
c--------------------------------------------------------------------
c     Date Code  Jan 10,1982
c--------------------------------------------------------------------
c
c     Optimization for the different models 
c
c     Original : Kyr. Doganis                  Aug 1981 
c     Mod # 1  : kyr. Doganis                  Feb 1982 
c
c---------------------------------------------------------------------
c
      integer ttyw,ttyr
      common /termin/ luout,luinf,luopt,ttyw,ttyr,icont,iauto
c
      double precision xt(ixdim),id(ifdim)
c
      common /models/ model
c
      if (iexit.ne.6) go to 100
c---------------------------------------------------------------------
c     deside for the model used
c---------------------------------------------------------------------
      write(ttyw,80)
80    format(' Define the model [1=SPICE, 2=MOBILITY, 3=FACTS, 4=CAzM]..
     +.',$)
      read(ttyr,*) model
      return
c--------------------------------------------------------------------
c     Go to the different models 
c     Advised by the documentation
c--------------------------------------------------------------------
100   if (model.eq.1) call model1(xt,id,iexit)
      if (model.eq.2) call model2(xt,id,iexit)
      if (model.eq.3) call model3(xt,id,iexit)
      if (model.eq.4) call model4(xt,id,iexit)
      return
      end
      subroutine PLOT(xt)
      implicit double precision (a-h,o-z)
	include 'parsize.f'
c
c--------------------------------------------------------------------
c     Date Code  Jan 10,1982
c--------------------------------------------------------------------
c
c     Ploting the IV extracted characteristics
c
c     Original : Kyr. Doganis                  Aug 1981 
c     Mod # 1  : kyr. Doganis                  Feb 1982 
c
c---------------------------------------------------------------------
c
      double precision xt(ixdim)
c
      common /models/ model
c
c--------------------------------------------------------------------
c     Go to the different models 
c     Advised by the documentation
c--------------------------------------------------------------------
      if (model.eq.1) call plot1(xt)
      if (model.eq.2) call plot2(xt)
      if (model.eq.3) call plot3(xt)
      if (model.eq.4) call plot4(xt)
      return
      end
      subroutine SCREN(xt)
      implicit double precision (a-h,o-z)
	include 'parsize.f'
c
c--------------------------------------------------------------------
c     Date Code  Jan 10,1982
c--------------------------------------------------------------------
c
c     Ploting the IV extracted characteristics
c
c     Original : Kyr. Doganis                  Aug 1981 
c     Mod # 1  : kyr. Doganis                  Feb 1982 
c
c---------------------------------------------------------------------
c
      integer optflg
      character*2 k
      common /jpar/ m,n,nsig,maxfn,infer,ier,optflg,
     +       ibad,icount,idelx1,idelxl,idelxu,ieval,ifml,ifml1,ifpl,
     +    ifpl1,ifpu,igrad1,igradl,igradu,ijac,iscal1,iscall,iscalu,
     +       isw,iter,ixbad1,ixnew1,ixnewl,j,istop,inflag,
     +       icnst,kvk,kvkold,iterr,nvar,npar,iweigs,k
c
      double precision xt(ixdim)
c
      common /models/ model
c
c--------------------------------------------------------------------
c     Go to the different models 
c     Advised by the documentation
c--------------------------------------------------------------------
      if (ihp.eq.0) return
      open(11, status='unknown', file='HPGL')
      if (model.eq.1) call scren1(xt,nvar,npar)
      if (model.eq.2) call scren2(xt,nvar,npar)
      if (model.eq.3) call scren3(xt,nvar,npar)
      if (model.eq.4) call scren4(xt,nvar,npar)
      close(11)
      return
      end
      subroutine PROCES(inputi,inputj,iwhere)
c      include 'parsize.f'
c
c      double precision initkp,uprbkp,lowbkp,tolrkp,trgtkp,weigkp
c      common /inkeep/ initkp(ixdim),uprbkp(ixdim),lowbkp(ixdim),
c     +                tolrkp(ifdim),trgtkp(ifdim),weigkp(ifdim)
c
c
      go to (200,200),iwhere
c100   trgtkp(inputi)=dlog10(trgtkp(inputi))
c      return
200   return
      end

