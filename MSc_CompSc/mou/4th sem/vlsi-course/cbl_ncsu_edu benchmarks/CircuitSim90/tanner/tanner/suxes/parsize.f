c     max no of optimization parameters   (ixdim)
c-------------------
c     max no function data points   (ifdim)
c-------------------
c     no of jacobian elements ijdim=ixdim*ifdim
c--------------------
c     no of elements of the triangular matrix jTj
c     ijTdim=ixdim*(ixdim+1)/2
c--------------------
c     max size of work array
c     iwkdim = (ixdim+1)*ixdim/2 + 5*ixdim + 2*ifdim
c--------------------
c     the scren dimensions for HP graphics terminals
c     xdim,ydim
c--------------------
c     ihp is a flag for the HP graphics terminals
c     ihp=[1/0] if Hp terminal is used  for graphics or not
c--------------------
      parameter 
     + (ixdim=30,ifdim=3000,ijdim=90000,ijTdim=465,iwkdim=6715)
      parameter (invar=3)
      parameter (xdim=719.0d0,ydim=359.0d0,ihp=1)
