// HAPPINESS !
#include <iostream.h>
#include <conio.h>
#include <string.h>             // for strlen()
void main()
{    char hap[12]="HAPPY-HAPPY" ;
	 int i,j,l=strlen(hap),c=l/2 ;
	// clrscr() ;
	 for ( i=0 ; i<l ; i++ ) cout << hap[i] ;
	 cout << endl ;
	 for ( i=0 ; i<c-1 ; i++ )
	 {   for ( j=0 ; j<l ; j++ )
		 {   if ( (j>=c-i) && (j<=c+i) ) cout << " " ;
			 else cout << hap[j] ;
		 } cout << endl ;
	 }
	 for ( i=2 ; i<=c ; i++ )
	 {   for ( j=0 ; j<l ; j++ )
		 {   if ( (j>=i) && (j<=(l-1)-i) )           // l-1 to avoid
			 cout << " " ;                           // the last null
			 else cout << hap[j] ;                   // string
		 } cout << endl ;
	 }
	 for ( i=0 ; i<l ; i++ )
		 cout << hap[i] ;
	 cout << endl ;
	 getche();
}
