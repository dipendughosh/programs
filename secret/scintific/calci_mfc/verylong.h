#include <iostream.h>
#include <string.h>
#include <stdlib.h>
const int SZ=32000;//no. of digits

class verylong
{
	private:
		char vlstr[SZ];
		int vlen;
		verylong multdigit(int);
		verylong mult10(verylong);
	public:
		verylong()
			{vlstr[0]='\0'; vlen=0;}
		verylong(char s[SZ])
			{strcpy(vlstr,s); vlen=strlen(s);}
		verylong(unsigned long n)
			{
				ltoa(n,vlstr,10);
				strrev(vlstr);
				vlen=strlen(vlstr);
			}
		void putvl();
		void getvl();
		verylong operator + (verylong);
		verylong operator * (verylong);
};