#! /bin/nawk -f
#
# MAP2PNF TRANSLATOR: AWK sipt 
#
# VERSION: 1.0
#
# Last update: August 2, 1994
#
#########################################################################
#
# Global variables:
# ================
#
# OPTIONS:
#---------
# -f = F_Option; default == 0: evaluate functionality
# -r = R_Option; default == 0: reduced netlist without SPECIAL arrays
#
# FILENAME, FILEOUT, NLogic, NBuf, NPin, NIo, NNet : file_name & global counters
#	    Library
#
# general   arrays: 	spec, pin, 
# LOGIC    strings: 	type, name, tspec, Func
#	  integers:	IN, OUT
#
# BUF     arrays:    output input 
#
#
########################################################################
# Basic function for parsing specific lines:
#
########################################################################
#
# fstr - returning the string up to the label string - without label string
# lstr - returning the string begining from label string
#
function fstr(str,label)
{
	len = index(str,label) - 1;
	if (len == -1) len = 0;
	return(substr(str,1,len));
}
function lstr(str,label)
{
	len = index(str,label);
	if (len == -1) len = 0;
	return(substr(str,len));
}
function llstr(str, label)
{
	len = index(str,label) +1;
	if (len == -1) len = 0;
	return(substr(str,len));
}
# 
# Reading all PIN lines of CLB element
#
function pin_array(pin)  
{
	np = 0; for (i in pin) pin[i] = "\0";
	while (match($1,/PIN/)) {
	    NPin++; np++;
            if (match($3,/O,/)) {
		OUT++;NNet++; 
	    } else {
	        IN++;
	    }
	    if ((NR  > 4) && (R_option == 0)) {
		pin[np] = sprintf("PIN %s %s %s SPECIAL:%s",
		fstr($3,","), fstr($4,","), fstr($2,","), lstr($0,$5));
	    } else {
		pin[np] = sprintf("PIN %s %s %s",
		fstr($3,","), fstr($4,","), fstr($2,",")); 
	    }
	    getline <  FILENAME
	}
	return(np);
}
#
# Reading CLB configuration: assuming file pointer at SYM CLB ... line !
#
function Logic(FILEOUT)
{
    	nspec = 0;IN = 0; OUT = 0;

   	while (!match($1,/^(END|MODEL)$/)) {
	
		if (match($3, /CLB/)) {
		   tspec = "\0";
		   name = fstr($2,","); type = sprintf("%s",$3);
		   if ((RS > 3) && (R_option == 0)) 
			tspec = sprintf("SPECIAL: %s",lstr($0,$4));
		   getline < FILENAME
		}
	
		if ((match($1, /CFG,/)) && (R_option == 0)) {
		   nspec++;
		   spec[nspec] = sprintf("SPECIAL: %s",$0);
		   getline < FILENAME
		}
	
		if (match($1, /PIN,/)) {
		   NP = pin_array(pin);NPin += NP;
		}
   	}
	
	# writing configuration into file !!!

	buff = sprintf("LOGIC %s %s IN:%d OUT:%d %s\n",type,name,IN,OUT,tspec);
	{print buff"BEGIN" > FILEOUT}
	for (i = 1; i<=nspec; i++ ) {print spec[i] > FILEOUT}
	for (i = 1; i <=NP; i++ )   {print pin[i] > FILEOUT}
	{print "END" > FILEOUT}
	if (F_Option == 1) {
	   for (i in spec) if (match($2,/Config/)) break;
	   elfunc_arg = fstr($0,$2);
	   buff = sprintf("elfunc(%s) > %s.elf",elfunc_arg, FILENAME);
	   {system(buff)}
	   FELF = sprintf("%s.elf",FILENAME);
	   getline < FELF;
	   Func = sprintf("FUNC %s", $0);
	   { print Func > FILEOUT }
	}
}
#
# Reading IOB configutation: assuming file pointer at SYM IOB ... line !
#
function Iob(FILEOUT)
{
	nspec = 0;np = 0;
	
	while (!match($1,/^(END|MODEL)$/)) {

		if (match($3, /IOB/)) {
		   name = fstr($2,",");
		   tspec = "\0";
		   if ((RS > 3) && (R_option == 0)) {
			tspec = lstr($0, $4);
		   } 	 
		}

		if ((match($1, /CFG,/)) && (R_option == 0)) {
		   nspec++;
		   spec[nspec] = sprintf("SPECIAL: %s",$0);
		}

		if (match($1, /PIN,/)) {
		   np++;
		   if (match($3,/I,/)) {
			output = name;
			input[np] = fstr($4, ",");
		   } else {
			output = fstr($4, ",");
			input[1] = name;NNet++;NPin++;
		   }
		   pspec == "\0";
		   if ((NR  > 4) && (R_option == 0)) {
		       spec_position = index($0, $5);
		       pspec = sprintf("SPECIAL: %s",substr($0, pspec_position));
		   }		   
		}
		
		getline < FILENAME
	}
	type = "IOB";
	if (match($1,/MODEL/)) {
	   while (!match($1,/SYM,/)) getline < FILENAME 
	   type = $3;
	}
	Input = "";
	for (i in input) Input = sprintf("%s %s",Input, input[i]);
	{ printf("BUF %s %s %s %s\n",type,output,Input,pspec) > FILEOUT }
	if (nspec > 0) {
	   {print "BEGIN" > FILEOUT}
	   for (i in spec) {print spec[i] > FILEOUT}
	   {print "END" > FILEOUT}
	}
	
}

function syntax()
{
	FILENAME =ARGV[1]; # Options file
	getline < FILENAME
	F_Option = llstr($1,"=");
	R_Option = llstr($2,"=");
	Library = llstr($3,"=");
	FILENAME = ARGV[2];
	FNAME = fstr(FILENAME, ".");  
	FILEOUT = sprintf("%s.pnf",FNAME);  
	return(FILEOUT)
}

#########################################################################
#	MAIN AWK PROGRAM - PARSING THE MAP FILE 
#
#		*****	MAP2XNF	  *****
#
# 	Translate Xilinx MAP file into PNF format
#
# Usage: map2pnf.awk filename.opt filename[.map]
#
#########################################################################

BEGIN {

#  	reading the aliase names of the NETS
	NLogic = 0; NBuf = 0; NIo = 0; NPin = 0; NNet = 0;

	syntax();
	while (!match($1,/EOF/)) {

	     if ((match($1,/SYM,/)) && (match($3,/CLB/))) {		 
		Logic(FILEOUT);NLogic++;
	     }
	     if ((match($1,/SYM,/)) && (match($3,/IOB/))) {
		 Iob(FILEOUT);NBuf++;
	     }
	     if (match($1,/EXT,/)) {
	        NIo++;
		{printf("EXTERN %s %s\n",fstr($3,","),fstr($2,",")) > FILEOUT}
	     }

	     getline < FILENAME

	}
	{print "EOF" > FILEOUT}	
	close(FILENAME);
}
END {

	{ print "	   N E T L I S T  S T A T I S T I C          " }
	{ print "----------------------------------------------------" }
	{ print "  # of CLBs    # of IOs      # of NETs    # of Pins " }
	{ print "++++++++++++++++++++++++++++++++++++++++++++++++++++" }
	{ printf("    %4d        %4d          %5d        %6d    ",NLogic,NIo,NNet,NPin)}
	{ print "====================================================\n" }
	{ print "MAP2PNF terminated normaly...\n" }
	{ print "PNF netlist written into file: "FILEOUT }
}

##########################################################################
#	END OF AWK PROGRAM 
##########################################################################

