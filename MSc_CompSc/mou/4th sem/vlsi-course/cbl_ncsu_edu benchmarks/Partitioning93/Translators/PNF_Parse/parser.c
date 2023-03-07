/*#############################################################################
 
    This is a part of the PNF netlist reader.
 
    Copyright (C) 1994 by Roman Kuznar, Dept. of ECE, Univ. of Ljubljana
 
    FILE: parser.c 
    Version: 1.0
    Last update: Aug. 25, 1994 
 
############################################################################*/

#include "parser.h"
#define WLEN	516	/* Max word length	*/
#define SLEN	1024	/* Max line length 	*/


#define NREC	11 	/* Number of records 	*/

/*	GLOBAL VARIABLES 	*/

static char *ch_brk[] = {" :=\t\n"};	/* separators */

static char *record[] = {		/* reserved words: lexicaly sorted */
	"BEGIN",
	"BUF",
	"END",
	"EOF",
	"EXTERN",
	"FUNC",
	"LIB",
	"LOGIC",
	"NETLIST",
	"PIN",
	"SPECIAL"
};

static char *ERRMSG[] = {
	"Execution terminated ... \n",
	"PARSE_ERROR[1]:Syntax error!\n",
	"PARSE_ERROR[2]:No BEGIN record!\n",
	"PARSE_ERROR[3]:No END record!\n",
	"PARSE_ERROR[4]:No TYPE record!\n",
	"PARSE_ERROR[5]:No SPECIAL record!\n",
	"PARSE_ERROR[6]:No PINTYPE record!\n",
	"PARSE_ERROR[7]:No PINNAME record!\n",
	"PARSE_ERROR[8]:No BUFTYPE record!\n",
	"PARSE_ERROR[9]:No BUF output record!\n",
	"PARSE_ERROR[10]:No I/O TYPE record!\n",
	"PARSE_ERROR[11]:No I/O NAME record!n",
	"PARSE_ERROR[12]:Incorrect LIBRARY record!\n",
	"PARSE_ERROR{13]:No NAME record!\n"
};

/* 	some general counters 		*/

int	NLogic = 0;		/* # of Logic	*/
int	NIo    = 0;		/* # of Extern	*/
int	NBuf   = 0;		/* # of Buffers	*/
int	NPin   = 0;		/* # of Pins 	*/
int 	NNet   = 0;		/* # of Nets	*/

char	*Library;	/* device library 			*/
int     str_tab = 10;	/* temp. string table dimension   : change if necessary !!! */
int     max_pin = 20;   /* max # of pins in Logic element : change if necessary !!! */

/* Top pointers of Linked list of LOGIC, BUF and I/O elements   */

struct Logic *lm;	/* linked list of LOGIC elements 	*/
struct Io    *ext;      /* linked list of Io elemnts		*/
struct Buf   *bf;	/* linked list of Buffers		*/

/* FUNCTIONS:	*/

void ERROR(errstr, errno) 

	char **errstr;
	int     errno;
{
	PRINTF("%s%s",errstr[errno],errstr[0]);
	EXIT(errno);
}


/* searching for string index : linear search because of small search table 	*/

int strinx(string, table, size)

	char *string;
	char **table;
	int	size;
{

	int index,len;

	for (index = 0; index < size; index++) {
	    len = MAX(strlen(string),strlen(table[index]));
	    if (!strncmp(string,table[index],len)) return(index);
	}
	return(-1);
}

/* read LOGIC arrays	*/
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void read_logic(buff,lm,file)

	char		*buff;	/* first line of the LOGIC element 	*/
	struct Logic	*lm;	/* data record to store values into 	*/
	FILE		*file;  /* Read file				*/

{
	char *word,*string,*buff1;
	char Break = FALSE,be = 0;
	int	i,np,nspec = 0,npin = 0,nfunc = 0;
	
	/* parsing LOCIC line */
	word = strtok(buff,*ch_brk);
	if ((word = strtok(NULL,*ch_brk))==NULL) ERROR(ERRMSG,4); 
	lm->type = strdup(word);lm->pin = 0;lm->tspec = NULL;
	if ((word = strtok(NULL,*ch_brk))==NULL) ERROR(ERRMSG,4);
	lm->name = strdup(word);	
	while((word = strtok(NULL,*ch_brk))!=NULL) {
	    if ((!strncmp(word,"IN",2)) || (!strncmp(word,"OUT",3))) {
		 lm->npin+ = atoi(strtok(NULL,*ch_brk));
	    } else if (!strncmp(word,"SPECIAL",7)) { /* !!! */
		 lm->tspec = strdup(strtok(NULL,"\n"));
	    } else 
		 ERROR(ERRMSG,1);
	    
	}

	do {
		FGETS(buff,SLEN,file);
		word = strtok(buff,*ch_brk);		
		switch (strinx(word,record,NREC)) {

		case BEGIN: be++; break;

		case END: 
			 be++;
			 if (be%2 == 0) {Break = TRUE;break;}
			 else  ERROR(ERRMSG,2); /* no BEGIN record */

		case FUNC:
			 nfunc++; CALLOC(lm->func, str_tab, char*);
			 while ((word = strtok(NULL,*ch_brk))!=NULL) { /* I/O depend. */
			        lm->func[nfunc-1] = strdup(word);
		         }
			 break;
						 
		case SPECIAL:
			 nspec++; /* !!! */
			 if ((word = strtok(NULL,"\n")) == NULL) ERROR(ERRMSG,5);
			 if (nspec == 1) CALLOC(lm->spec, str_tab, char*);
			 lm->spec[nspec-1] = strdup(word);
			 break;

		case PIN:
			 npin++;
			 if (npin == 1) CALLOC(lm->pin, max_pin, struct Pin*);
			 MALLOC(lm->pin[npin-1], struct Pin);
			 if ((word = strtok(NULL,*ch_brk)) == NULL) ERROR(ERRMSG,6);
			 if ((lm->pin[npin-1]->type = word[0]) == 'O') NNet++;
			 if ((word = strtok(NULL,*ch_brk)) == NULL) ERROR(ERRMSG,7);
			 lm->pin[npin-1]->name = strdup(word);
			 lm->pin[npin-1]->special = NULL;
			 lm->pin[npin-1]->ptype = NULL;
			 while((word = strtok(NULL,*ch_brk))!=NULL) {
			    if (!strncmp(word,"SPECIAL",7)) {
				 word = strtok(NULL,"\n");
				 lm->pin[npin-1]->special = strdup(word);
			    } else {
				/* this string should be pin type array */	
	 			lm->pin[npin-1]->ptype = strdup(word);			
			    }
			 }			 
			 break;

		default:
			if (be == 0) ERROR(ERRMSG,2);
		        if (be == 1) ERROR(ERRMSG,3);
			ERROR(ERRMSG,1); /* syntax error: LOGIC array must end with END */
		}
	}while(Break != TRUE);
	lm->nspec = nspec;
	lm->nfunc = nfunc;
	lm->npin = npin; NPin+ = npin;
	REALLOC(lm->func, nfunc, char*);
	REALLOC(lm->spec, nspec, char*);
	REALLOC(lm->pin, npin, struct Pin*);
}

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void read_buf(buff,bf,file)
	char     *buff;	/* first line of the LOGIC element 	*/
	struct Buf *bf;	/* data record to store values into 	*/
	FILE	 *file;

{
	char *word;
	char Break = FALSE,be = 0;
	int    nspec = 0,npin = 0;

	word = strtok(buff,*ch_brk);
	if ((word = strtok(NULL,*ch_brk)) == NULL) ERROR(ERRMSG,8);
	bf->type = strdup(word);
	if ((word = strtok(NULL,*ch_brk)) == NULL) ERROR(ERRMSG,9);
	npin++;
	CALLOC(bf->nets, str_tab, char*);NNet++;
	bf->nets[npin-1] = bf->name = strdup(word);  /* name of the output net  */
	while ((word = strtok(NULL,*ch_brk)) != NULL) {
		if (!strncmp("SPECIAL",word,7)) {
		   word = strtok(NULL,"\n"); /* !!! */
		   bf->tspec = strdup(word);
		} else {
		   npin++;	/* input nets */
		   bf->nets[npin-1] = strdup(word);
		}
	}
	
	do {
		FGETS(buff,SLEN,file);
		word = strtok(buff,*ch_brk);
		switch(strinx(word,record,NREC)) {

		case SPECIAL:  /* !!! */         
			 nspec++;
			 if ((word = strtok(NULL, "\n")) == NULL) ERROR(ERRMSG,5);
			 if (nspec == 1) CALLOC(bf->spec, str_tab, char*);
			 bf->spec[nspec-1] = strdup(word);
			 break;		
		
		case BEGIN: be++; break;

		case END: 
			 be++;
			 if (be%2 == 0) {Break = TRUE;break;}
			 else  ERROR(ERRMSG,2); /* no BEGIN record */

		default: Break = TRUE; /* Not BUF array */
		}
	}while(Break != TRUE);
	bf->nspec = nspec;
	bf->nnets = npin; NPin+ = npin;
	REALLOC(bf->nets, npin, char*);
	REALLOC(bf->spec, nspec, char*);
}

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void read_extern(buff,ext)

	char 	   *buff;
	struct Io   *ext;

{
	char *word;
	
	word = strtok(buff,*ch_brk); /* EXTERN field */

	if ((word = strtok(NULL, *ch_brk)) == NULL) ERROR(ERRMSG,10);	
	if ((ext->type = word[0]) == 'I') NNet++;
	if ((word = strtok(NULL, *ch_brk)) == NULL) ERROR(ERRMSG,11);	
	ext->name = strdup(word);
	NPin++;
}

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


int parse_input(file)

	FILE *file;
{

	char *buff, *buff1, *word, Break = FALSE;
	char endread = FALSE;
	struct Logic *clm;
	struct Io    *cext;
	struct Buf   *cbf;


	CALLOC(buff, SLEN, char);
	FGETS(buff,SLEN,file);

	MALLOC(lm, struct Logic);clm = lm;	/* top elements of  linked lists */
	MALLOC(bf, struct Buf);	 cbf = bf;	/* of objects			 */
	MALLOC(ext, struct Io);  cext = ext;

	do {
	   CALLOC(buff1, SLEN, char);strcpy(buff1, buff);
	   word = strtok(buff, *ch_brk);
	   switch(strinx(word,record,NREC)) {
	   case NETLIST:

		    FGETS(buff,SLEN,file);
		    break;

	   case LIB:
		    if ((word = strtok(NULL,*ch_brk)) == NULL) ERROR(ERRMSG, 12);
		    Library = strdup(word);
		    FGETS(buff,SLEN,file);
		    break;

	   case LOGIC:
		    MALLOC(clm->next, struct Logic);
		    clm = clm->next;
		    read_logic(buff1, clm,file);
		    clm->next = NULL;
		    NLogic++;
		    break;

	   case BUF:
		    MALLOC(cbf->next, struct Buf);
		    cbf = cbf->next;
		    read_buf(buff1, cbf,file);
		    cbf->next = NULL;
		    NBuf++;
		    break;

	   case EXTERN:
		    MALLOC(cext->next, struct Io);
		    cext = cext->next;
		    read_extern(buff1, cext);
		    cext->next = NULL;
		    NIo++;
		    break;

	   case ENDFILE:
		    Break = TRUE;break;

	   default:
		    ERROR(ERRMSG,1); /* syntax error : unknown record */
	   }
	   FGETS(buff,SLEN,file); FREEMEM(buff1);	    
	}while((endread==TRUE) || (!feof(file)));

	if (NLogic > 0) lm = lm->next;	else  lm = NULL;
	if (NBuf > 0)   bf = bf->next; 	else  bf = NULL;
	if (NIo	> 0)   ext = ext->next;	else ext = NULL; 
	return(1);
}

