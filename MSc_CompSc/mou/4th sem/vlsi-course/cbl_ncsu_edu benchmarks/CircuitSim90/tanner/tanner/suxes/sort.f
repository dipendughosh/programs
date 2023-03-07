
c	Begin bubble sort on 'array'
        do 10 i=1,n-1
	   exchange=.false.
	   do 10 j=1,n-i
	       if (array(j) .gt. array(j+1)) then
		    temp=array(j)
		    array(j)=array(j+1)
		    array(j+1)=temp
		    exchange=.true.
		endif
		if (.NOT. exchange) goto 20
10	   continue
