/* Simple program to perform automated analysis of analog functional blocks. 
Possibilites are:

AC Analysis:
	BW	- Bandwidth (open-loop 0db point)
	AVOL	- Open-loop DC gain
	GBW	- Gain-bandwidth product
	PSRR	- AC power supply rejection ratio
	CMRR	- AC common mode rejection ratio
	PM	- Phase margin (phase at fBW)
	GM	- Gain margin (gain at phase reversal)

Transient Analysis:
	SRP	- Slew rate (with 1V P-P) in + direction
	SRM	- Slew rate (with 1V P-P) in - direction
	STP	- Closed-loop settling time (+ step)
	STM	- Closed-loop settling time (- step)

DC Analysis:
	IDD	- Power supply current
	PD	- Power dissipation

Following are the sorts of variances that may be specified in the setup file:

PARAM <COMP> VAL1, VAL2, VAL2, ..., VALN	Component varying
PARAM TEMP VAL1, ..., VALN			Temperature varying
PARAM MODEL <MOD1>, <MOD2>, ..., <MODN>		Model varying
PARAM VOLT VAL1, VAL2, ..., VALN		DC voltage source varying

Analyses are specified as follows:

DCANAL [IDD] [PD]
TRANAL [SRP] [SRM] [STP] [STM]
ACANAL [BW] [AVOL] [GBW] [PSRR] [CMRR] [PM] [GM]

Uses a setup file which is parsed in and action taken. Reads in a single CAzM
output file which contains one to all of the analyses required per parameter.
*/

#include <stdio.h>
#include <math.h>

main(argc, argv)
int *argc;
char **argv;
{
	FILE *SetupFile, *FaFile;
	char *c;
	char buf[4096], line[80];
	int linenum, charnum, dum, i, j, k;

/* Open up the setup file stuff */

	if( argc<3 ) {
	   fprintf(stderr,"Usage: analyze <setup file> <netlist file>\n");
	   exit(1);
	} else {
	   if( (SetupFile=fopen( argv[1], "r" )) != NULL) {
	      fprintf(stderr,"Opening setup file %s\n",argv[1]);
	   } else {
	      fprintf(stderr,"Error on attempted open of %s\n",argv[1]);
	      exit(1);
	   }
	   if( (FaFile=fopen( argv[2], "r" )) != NULL) {
	      fprintf(stderr,"Opening netlist file %s\n",argv[2]);
	   } else {
	      fprintf(stderr,"Error on attempted open of %s\n",argv[2]);
	      exit(1);
	   }
	}

/* Now to parse it in */

	while( (c=getc(SetupFile)) != EOF ) buf[charnum++]=c;

	for(i=0; i<=charnum; i++) {
	   if ( buf[i]=='\n') linenum++;
	   }
	i=0;
	for(j=0; j<linenum; j++) {
	   k=0;
	   while( buf[i] != '\n' ) line[k++]=buf[i++];
	   i++;
	   line[k]='\0';
	   printf("Line num= %d Line= %s\n",j,line);
	   }
	printf("Num lines =%d\n",linenum);
	printf("Num chars =%d\n",charnum);
}
