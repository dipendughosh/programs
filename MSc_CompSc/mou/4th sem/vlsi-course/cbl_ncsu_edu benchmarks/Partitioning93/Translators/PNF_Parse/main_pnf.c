/*#############################################################################
 
    This is a part of the PNF netlist reader.
 
    Copyright (C) 1994 by Roman Kuznar, Dept. of ECE, Univ. of Ljubljana

    FILE: main_pnf.c 
    Version: 1.0
    Last update: Aug. 25, 1994 

############################################################################*/

#include "parser.h"
#define NFLAGS	5


static char  *IN_ERROR[] = {
	"Execution aborted...\n",
	"ERROR[1]: Incorrect input format ...\n",
	"ERROR[2]: Incorrect option...\n",
	"ERROR[3]: Output file not specified...\n",
	"ERROR[4]: Input file not specified...\n"
};

static char *HELP[] = {
	"\nHELP:   read_pnf is an executable which illustrates\n",
        "        how to use main parser function parse_input():\n\n",
	"        FILE *f_in;\n\n",
        "        FOPEN(f_in, filename<.pnf>,\"r\");\n",
        "        parse_input(f_in);\n",
        "        FCLOSE(f_in);\n\n",
        "        parse_input() reads the PNF netlist and stores data into\n",	
	"        three linked lists:\n",
        "         (1) list of EXTERN elements: the top pointer to the\n",
	"             linked list is global variable: struct Io *ext; \n",
	"         (2) list of BUF elements: the top pointer to the   \n",
	"             linked list is global variables: struct Buf *bf \n",
	"         (3) list of LOGIC elements: the top pointer to the\n",
	"             linked list is global variable: struct Logic *lm\n",
	"        Data structures are defined in 'parser.h' file\n\n",
	"        WARNING: parse_input() only reads data into data structures.\n",
	"                 It does not create a netlist e.g. list of elements\n",
	"                 (EXTERN,BUF,LOGIC) in each net !!!\n\n"     	
};

/* Top pointers of Linked list of LOGIC, BUF and I/O elements   	*/
/* !!!  All data stored in these linked lists !!!			*/
extern struct Logic *lm;	/* linked list of LOGIC elements 	*/
extern struct Io    *ext;       /* linked list of Io elemnts		*/
extern struct Buf   *bf;	/* linked list of Buffers		*/

extern int	NLogic;		/* # of Logic	*/
extern int	NIo;		/* # of Extern	*/
extern int	NBuf;		/* # of Buffers	*/
extern int	NPin;		/* # of Pins 	*/
extern int 	NNet;		/* # of Nets	*/
extern char	*Library;	/* device library  */

extern int parse_input();  	/* the main function of the reader : 
				   the argument is FILE* pointer to the input file */ 
extern void ERROR();
 
/* Bellow are functions for printing the data from linked lists : 
 *   - Use then when you like to check if you reader works O.K. 
 *
 *   - main() function is very simple --> to illustrate the usage of the
 *     reader : how to call reader and output the results !!!
 */
     
void print_Ios(f_out)
FILE *f_out;
{
	struct Io *cio;

	int nio = 0;
 
	/* print all EXTERN fields */
	FPRINTF(f_out,"EXTERN fileds:\n");
	FPRINTF(f_out,"--------------\n");
	cio = ext;
	while (cio != NULL) {

	   FPRINTF(f_out,"EXTERN name: %s \t type: %c\n", cio->name, cio->type);
	   nio++;
	   cio = cio->next;
	}
	FPRINTF(f_out,"Total IOs = %d\n", nio);

}


void print_Buf(f_out)
FILE *f_out;
{
	struct Buf *cbf;

	int nbf = 0,i;
 
	/* print all EXTERN fields */
	FPRINTF(f_out,"BUF fileds:\n");
	FPRINTF(f_out,"--------------\n");
	cbf = bf;
	while (cbf != NULL) {

	   FPRINTF(f_out,"BUF name: %s\ttype: %s\ttspec: %s\n", 
			       cbf->name, cbf->type,cbf->tspec);
	   for (i = 0; i < cbf->nspec; i++) {FPRINTF(f_out,"SPECIAL[%d]: %s\n", 
								i,cbf->spec[i]);}
	   for (i = 0; i < cbf->nnets; i++) FPRINTF(f_out,"NET: %s\n", cbf->nets[i]);
	   nbf++;
	   cbf = cbf->next;
	}
	FPRINTF(f_out,"Total BFs = %d\n", nbf);

}


void print_Logic(f_out)
FILE *f_out;
{
	struct Logic *clm;

	int nbf = 0,i;
 
	/* print all EXTERN fields */
	FPRINTF(f_out,"LOGIC fileds:\n");
	FPRINTF(f_out,"-------------\n");
	clm = lm;
	while (clm != NULL) {

	   FPRINTF(f_out,"LOGIC name: %s\ttype: %s\ttspec: %s\n", clm->name,
		 clm->type,clm->tspec);
	   for (i = 0; i < clm->nspec; i++) {FPRINTF(f_out,"SPECIAL[%d]: %s\n", 
							      i,clm->spec[i]);}
	   for (i = 0; i < clm->npin; i++) FPRINTF(f_out,"PIN[%d]: %s\t%c\t%s\t%s\n",i,
	   clm->pin[i]->name,clm->pin[i]->type,clm->pin[i]->ptype,clm->pin[i]->special);
	   nbf++;
	   clm = clm->next;
	}
	FPRINTF(f_out,"Total LMs = %d\n", nbf);

}

void print_stats(f_out)
FILE *f_out;
{
	FPRINTF(f_out,"\n	 S T A T I S T I C S  of  T H E  C I R C U I T\n");
	FPRINTF(f_out,"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	FPRINTF(f_out," # of LOGIC   # of BUF   # of I/O    # of NETs    # of PINs  \n");
	FPRINTF(f_out,"==============================================================\n");
	FPRINTF(f_out,"     %-6d      %-4d       %-3d        %-6d         %-6d\n\n",
		NLogic,NBuf, NIo, NNet, NPin);  
}


/**************************************************************************/
/* FUNCTION: display head of the program		                  */
/**************************************************************************/

	void pnf_head()

{
    PRINTF("\n               READ_PNF Version 1.0\n");
}

/**************************************************************************/
/* FUNCTION: display syntax if incorrectly usage of the program           */
/*           detected; 				                          */
/**************************************************************************/

	void pnf_syntax()

{
    PRINTF("\n               READ_PNF Version 1.0 \n");
    PRINTF("\nFUNCTION: Reads PNF netlist format and output netlist/statistics\n");
    PRINTF("\nUSAGE   : read_pnf [-e][-b][-l][-f fileout][-h] filename<.pnf>\n");
}


/**************************************************************************/
/* FUNCTION: display sintax if incorrectly usage of the program           */
/*           detected; it return 0 iff 0.K. else 1                        */
/**************************************************************************/


	void pnf_options()

{
    PRINTF("\n        -e = output all EXTERN elements ");
    PRINTF("\n        -b = output all BUF elements ");
    PRINTF("\n        -l = output all LOGIC elements ");
    PRINTF("\n        -f = redirect into file <fileout>"); 
    PRINTF("\n        -h = help");      
    PRINTF("\nEXAMPLE: read_pnf -l -f counter.out counter.pnf\n");
}


/**************************************************************************/
/* FUNCTION: read_pnf main function				                  */
/*  						   	                  */
/**************************************************************************/

void	main(argc,argv) 

	int       argc;
        char    **argv;

{
	char *word,*filein,*fileout = NULL;
	FILE *f_in, *f_out = stdout;
	int i,j;
	int  ff = 0,fe = 0,fb = 0,fl = 0;

	if ((argc<2) || (argc>NFLAGS+2)) {
           pnf_syntax();
           pnf_options();
	   ERROR(IN_ERROR,1);
        } else {

           /* checking options */
  	   for (i=1;i<argc;i++)    
      	       if (argv[i][0] == '-') {
         	  /* check for frags */
         	  switch (argv[i][1]) {
		     case 'f':
			      ff = 1;i++;
			      if (((fileout = strdup(argv[i])) == NULL) 
				|| (fileout[0] == '-')) ERROR(IN_ERROR,3);
			      FOPEN(f_out,fileout,"w");    
			      break; 			      
		     case 'e':
			      fe = 1; 
			      break; 			     
		     case 'b':
			      fb = 1;
			      break; 
		     case 'l':
			      fl = 1;
			      break; 					     
		     case 'h':
			      pnf_syntax();pnf_options();
			      for (j = 0; j < 18; j++) PRINTF("%s", HELP[j]); 
			      EXIT(1);			     
	     
		     default :			 /* incorrect flag */
			      pnf_syntax();
			      pnf_options();
			      ERROR(IN_ERROR,2);
		  }
	       } else {
		    pnf_head();
		    /* this MUST be an input filename */
		    if (((word = strtok(argv[i],".\0\n")) == NULL) 
			|| (word[0] == '-')) ERROR(IN_ERROR,3); 
		    CALLOC(filein,strlen(word)+4,char);
		    SPRINTF(filein,"%s.pnf",word);
		    FOPEN(f_in, filein,"r");   
		    parse_input(f_in);
		    FCLOSE(f_in);
		    if (fe) print_Ios(f_out);
		    if (fb) print_Buf(f_out);
	            if (fl) print_Logic(f_out); 
		    if (ff) {
			print_stats(f_out);
			f_out = stdout;
			print_stats(f_out);
		    } else 
			print_stats(f_out);
		    FREEMEM(filein);
	      }
	}
	PRINTF("READ_PNF successfully terminated ....\n");
	system("date");	
	if (ff) FCLOSE(f_out);
	EXIT(0);
}

