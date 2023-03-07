/*###########################################################################
 
    This is a part of the PNF netlist reader.
 
    Copyright (C) 1994 by Roman Kuznar, Dept. of ECE, Univ. of Ljubljana
 
    File: PARSER.H
    Version: 1.0
    Last update: August 21, 1994

########################################################################### */

#include "macros.h"

enum {
	BEGIN,
	BUF,
	END,
	ENDFILE,
	EXTERN,
	FUNC,
	LIB,
	LOGIC,
	NETLIST,
	PIN,
	SPECIAL
};

struct Pin {
	char 	type;		/* 'I' or 'O' 		*/
	char	*name;		/* name of the pin 	*/
	char	*ptype;		/* pin type		*/
	char	*special;	/* special records	*/
};

struct Io {
	char 	   type;	/* 'I' or 'O' 			*/
	char	  *name;	/* name of the pin 		*/
	struct Io *next;	/* next Io record		*/	
};

struct Buf {
	char 	*type;		/* type of the buffer		*/
	char	*name;		/* name of the pin 		*/
	char    *tspec;		/* special record at the top	*/
	char    **spec;		/* array of special records 	*/
	char    **nets;		/* output  and input(s)		*/
	int      nspec;		/* # of SPECIAL arrays          */
	int      nnets;		/* # of nets			*/
	struct Buf *next;	/* next Buf array		*/
};

struct Logic {
	char 	*type;		/* type of the buffer		*/
	int 	 npin;		/* number of pins		*/
	char	*name;		/* name of the pin 		*/
	char   	*tspec;		/* special record at the top	*/
	char    **spec;		/* array of special records 	*/
	char     **func;	/* functional depenedency	*/
	struct Pin **pin;	/* nets connected to LOGIC	*/
	int	 nspec;		/* # of SPECIAL arrays		*/
	int      nfunc;		/* # of FUNC arrays		*/
	struct Logic *next;	/* next Logic array		*/	
};
