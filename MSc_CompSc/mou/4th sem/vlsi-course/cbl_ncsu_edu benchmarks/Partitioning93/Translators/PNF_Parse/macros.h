/*#############################################################################
 
    This is a part of the PNF netlist reader.
 
    Copyright (C) 1994 by Roman Kuznar, Dept. of ECE, Univ. of Ljubljana
 
    FILE: macros.h 
    Last update: Aug. 25, 1994 
 
############################################################################*/

/*********************************************************************/
/* Macro definitions                      			     */
/*********************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

#define BADPTR   (0xFFFFFFFF)
#define TRUE     1
#define FALSE    0
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
#define ASCII_a  97
#define ASCII_A  64
#define ASCII_0  48

#define MAX(a,b) (((a) >= (b)) ? (a):(b))
#define MIN(a,b) (((a) <= (b)) ? (a):(b))
#define HIGH(a,b) (((a) >= (b)) ? (0):(1))
#define LOW(a,b)  (((a) >= (b)) ? (1):(0))

#define CALLOC(ptr, nr, type) if(!(ptr = (type*)calloc((unsigned)nr,\
   sizeof(type)))) { PRINTF("calloc failed\n"); EXIT(1); }

#define MALLOC(ptr, type) if(!(ptr = (type*)malloc(  \
   sizeof(type)))) { PRINTF("malloc failed\n"); exit(); }

#define REALLOC(obj, num, type) \
    (obj) ? ((type *) realloc((char *) obj, sizeof(type) * (num))) : \
            ((type *) malloc(sizeof(type) * (num)))

#define FREEMEM(ptr) (void)free((char*)(ptr))  

#define FOPEN(ptr, buff, mode)  if((ptr = fopen(buff, mode)) == NULL) \
         { PRINTF("Cannot open '%s' file\n",buff); EXIT(); }


#define PRINTF (void)printf
#define FPRINTF (void)fprintf
#define SPRINTF (void)sprintf
#define FCLOSE (void)fclose
#define FGETS (void)fgets
#define SSCANF (void)sscanf
#define FSCANF (void)fscanf
#define EXIT (void)exit

