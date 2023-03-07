/*---------------------------------------------------------------------------

    =========       ========        ===========    ===== =======   =======
   ==      ===     ===     ==       ==     ===        ===     === =     ===
  ==       ===     ===   =====      =     ===         ==       ===       ===
  ==               =====   ===          ===           ==       ===       ===
  ==              ===      ===         = =    =       ==       ===       ===
   ==        =    ===      ===       ===      =       ==       ===       ===
    =========      ======== ====    ===========    =======   =======  =======

-----------------------------------------------------------------------------

	            Designed and written by
                    	Donald Erdman - Duke University
                    	Ravi Subrahmanyan - MCNC
                    	Gary Nifong - MCNC
                    	Steve Kenkel - MCNC

	Copyright 1989, 1990 by the Microelectronics Center of North 
	Carolina, Don Erdman, and Don Rose.

        This copy, serial #00, of MCNC proprietary software, is made  
        available under license agreement.  Please heed all non-  
        disclosure and internal use restrictions.  
-----------------------------------------------------------------------------

	This file contains the routines used to parse the command line
	and the main routine which controls all subroutines.

----------------------------------------------------------------------------*/
/*
-----------------------------------------------------------
|    MAIN
|    Front end for the circuit simulator
|
| Parameters -
|         A file containing the circuit description, and a
|         file containing commands.
|
| Returns -
|         Creates a netlist to be used by the numerical routines.
|
------------------------------------------------------------
$Header: cazm.c,v 1.12 87/10/30 16:08:35 erdman Locked $
$Log:	cazm.c,v $
 * Revision 1.12  87/10/30  16:08:35  erdman
 * October release version
 * 
 * Revision 1.10  87/03/25  13:21:20  erdman
 * release version
 * 
 * Revision 1.9  86/05/28  11:43:35  erdman
 * Adding new Spice parser
 * 
 * Revision 1.8  86/03/20  21:21:12  erdman
 * Breaking out command and circuit parsers
 * 
 * Revision 1.7  86/02/15  21:04:09  erdman
 * adding new command parser,
 * vector and bus commands are added
 * plot, transient, and bit commands are enhanced
 * 
 * Revision 1.6  86/01/19  21:39:20  erdman
 * adding empirical formulas to generate tables
 * 
 * Revision 1.5  85/11/19  11:58:33  erdman
 * adding node mapping capabilities, create a list of
 * node names and their associated node numbers.
 * 
 * Revision 1.4  85/10/29  11:34:55  erdman
 * Adding subcircuit capabilities
 * 
 * Revision 1.3  85/09/10  15:27:45  erdman
 * adding command parser
 * 
 * Revision 1.2  85/08/12  13:32:52  erdman
 * Added Gary`s parser 
 * 
*/

#include "Hmain.h"
#include "sim.h"
#include "Hcmd.h"


main(argc, argv) 
int argc;
char *argv[];
{
	Param *gp;			/* Global parameter pointer */
	Val_Double val_double;		/* used to pass double arrays neatly */
	Val_Int val_int;		/* used to pass int arrays neatly */
	struct count_s *cnt;
	int speed;
	extern int cache_misses;
	extern int vgs_allocs;


			/* allocate the simulation structure */
	gp = (struct param_s *)
		sim_alloc(sizeof(struct param_s), S_CAZM);

			/* get command line arguments */
	commandline(gp, argc, argv);

			/* Initialize the memory statistics */
	if(gp->p_debug_num == -3)
	    sim_mem_init();


			/* Initialize pointers and parameters before
			 * parsing  circuit and command files.
			 */
	gp->p_boundary = NULL;
	gp->p_currb = NULL;
	gp->p_other_i = NULL;
	gp->p_other_v = NULL;
	gp->p_volt_v = NULL;
	gp->p_dcoppt = NULL;
	gp->p_transient = NULL;
	gp->p_transfer = NULL;
	gp->p_ac = NULL;
	gp->p_ac_volt = NULL;
	gp->p_ac_curr = NULL;
	gp->p_plot = NULL;
	gp->p_power = NULL;
	gp->p_dcg = NULL;
	gp->p_ic = NULL;
	gp->p_temp = NULL;
	gp->p_abs = ABS_ERROR;
	gp->p_relative = REL_ERROR;
	gp->p_chargetol = CHARGE_TOL;
	gp->p_relchargetol = REL_CHARGE_TOL;
	gp->p_max_tr = NEWTON_CNT;
	gp->p_max_dc = DC_CNT;
	gp->p_linear_equ = GAUSS;
	gp->p_decimal = MAX_DECIMAL;
	gp->p_tdelay = T_DELAY;
	gp->p_maxsinfreq = 0.0;
	gp->p_transmission_step = 0.0;
	gp->p_tab_size = (struct mod_table_size *) mod_gsize_init();


			/* Start parsing the circuit file */
	parse_files(gp);

			/* The circuit description is now stored
			*  in a netlist and the node names are
			*  stored in a hash table
			*/

			/*
			* boundary nodes, initial conditions, and
			* commands for the simulator
			*/

	/* Convert BSIM-type resistors and capacitors to regular
	 * resistors and capacitors
	 * Adjust resistors with temperature.
	 */

	adj_geometry(gp);

	   /* Use direct model evaluation and do not create tables if only AC */
	if(gp->p_transient == NULL && gp->p_transfer == NULL &&
		gp->p_ac != NULL)
	    gp->p_usemodels = TRUE;

		/* Check to make sure we loaded all the model tables */
	check_tables(gp);
	
		/* find model parameters associated with a function */
	find_models(gp->p_func);


		/* put parasitics on devices */
	add_parasitics(gp);
	delete_known(gp, gp->p_num_nodes); 

		/* add parasitic to the plot structure */ 
	plot_parasitic_setup(gp);


			/* re map the node numbers so the boundary nodes are
			 * last */
	remap(gp);

			/* Use a faster table look-up for mosfets.  */
	speed = FALSE;
	if(!gp->p_usemodels && !gp->p_cache && 
		gp->p_transient != NULL &&
	   gp->p_transient->type != CMD_PREVIEW)
	    speed = TRUE;
	else if (!gp->p_usemodels && !gp->p_cache && 
		gp->p_transfer != NULL)
	    speed = TRUE;


	if(speed == TRUE)
	    speed_up(gp);


			/* Lump multiple capacitors attached to the same node */
	lump_cap(gp);

			/* free up some memory */
	cz_sim_free();

		/* check to see if it is a SPICE user with global grounds */
	global_gnd_check(gp->p_num_ind - gp->p_count.c_vvt);

		/* group transmission lines */
	group_transmission(gp);

			/* call numerical routines */
	init_num(gp, &val_double, &val_int);

			/* Print memory statistics */
	if(gp->p_debug_num == -3) {
	    cnt = &gp->p_count;
	    sim_mem_print(cnt->c_trans, cnt->c_uniquetr, cnt->c_bjt,
		cnt->c_jfet, cnt->c_cap, cnt->c_res, cnt->c_ind,
		cnt->c_mesfet, cnt->c_transmission, gp->p_num_ind,
		gp->p_num_nodes);
	}

	    /* When we return everything is done */
	print_stats(gp);	
	/*
	if (gp->p_count.c_uniquetr > 0 ) {
	    fprintf(stderr,"Average number of table misses per table %d\n",cache_misses/ gp->p_count.c_uniquetr);
	    fprintf(stderr,"Average number of vgs allocs per table %d\n",vgs_allocs/ gp->p_count.c_uniquetr);
	}
	if (gp->p_count.c_mesfet > 0 ) {
	    fprintf(stderr,"Average number of table misses per table %d\n",cache_misses/ gp->p_count.c_mesfet);
	    fprintf(stderr,"Average number of vgs allocs per table %d\n",vgs_allocs/ gp->p_count.c_mesfet);
	}
	*/
	if ((gp->p_nutmeg) && (gp->p_csdf)) sim_error(S_FATAL, S_CAZM, "must specify only one output file format");
	if (gp->p_nutmeg)
	   nutmeg_finish(gp);
/*	if (gp->p_csdf)
	   csdf_finish(gp);
	   */
	exit(0);
}
/*
----------------------------------------------------------------
|    PRINT_STATS
|    Print what is recorded so far in the count structure
|
----------------------------------------------------------------
*/
print_stats(gp)
Param *gp;
{

struct count_s *count = &gp->p_count;

	fprintf(stderr, "\nMOS Transistors - %d\t\tUnique MOS transistors - %d \n",
		count->c_trans, count->c_uniquetr);
	fprintf(stderr, "BJTs - %d\t\t\tJFETs - %d \n", count->c_bjt,
	 	count->c_jfet);
	fprintf(stderr, "Capacitors - %d\t\t\tResistors - %d\n",
		count->c_cap, count->c_res);
	fprintf(stderr, "Inductors - %d\t\t\tTransmission lines - %d\n",
		count->c_ind, count->c_transmission);
	fprintf(stderr,  "MESFETs - %d\n",count->c_mesfet);

	fprintf(stderr,"number of nodes - %d\t\tboundary nodes - %d\n\n",
	   gp->p_num_ind, gp->p_num_nodes - gp->p_num_ind);
}
	

/*
-----------------------------------------------------------
|    COMMANDLINE 
|        Process the command line.
|
| Parameters -
|         argc      - count of the number of arguments on the command line
|	  argv      - pointer to an array of strings
|
| Returns -
|         Returns if the command line was correct. Otherwise the program
|         terminates with an error message.
|
| Side effects -
|          If the procedure is successful, the names of the circuit file
|          and command files and indexing and debuging mode are determined
|	   and set.
|
------------------------------------------------------------
*/
commandline(gp, argc, argv)
Param *gp;
int argc;
char **argv;
{
	int c;				/* character returned from getarg */
	double atof();			/* ascii to double */
	extern int sim_optind; 		/* index of operand */
	extern char *sim_optarg;	/* operand of flag ret. from getarg */
	char *strip_ext();		/* takes extension off filename */
	char *index, indx[128];		/* used by indexing system */

				/* default values for command line args */
	strcpy(gp->p_outputfile, "");
	strcpy(gp->p_modfile, "");
	gp->p_chkconn = TRUE; 		/*check connectivity */
	gp->p_mosfet_parasitics = FALSE;  /* resistor & diodes */
	gp->p_usemodels   = FALSE;        /* Bypass tables */
	gp->p_moscap  = FALSE;        /* CAzM default for s/d areas */
	gp->p_debug_num = DEBUG_DEFAULT;	/* debugging off  */
	gp->p_linearmode  = FALSE;        /* Linear interp for BJTs */
	gp->p_nutmeg = FALSE;   	        /* nutmeg output format */
	gp->p_csdf = FALSE;   	        /* CSDF output format */
	gp->p_cache = FALSE;		/* cache tables */

	index = (char *)NULL;
  
	while (( c = sim_getopt(argc, argv, "CMLVUOacrxI:D:m:o:")) != EOF)
	switch (c) {
		case 'o':
			strcpy(gp->p_outputfile, sim_optarg);
			break;
		case 'C':		/* turn off check of connectivity */
			gp->p_chkconn = FALSE;
			break;
		case 'I':
			index = strcpy(indx,sim_optarg);
			break;
		case 'V':
			sim_version(S_CAZM); 
			exit(0);
		case 'D':
			gp->p_debug_num = atoi(sim_optarg); 
			break;
		case 'c':
			gp->p_moscap = TRUE;
			break;
		case 'L':
			gp->p_linearmode = TRUE;
			break;
		case 'M': /* Set both modes when using -M */
			gp->p_usemodels = TRUE;
			gp->p_mosfet_parasitics = TRUE;
			break;
		case 'a':
			gp->p_mosfet_parasitics = TRUE;
			break;
		case 'm':		/* Model filename */
			strcpy(gp->p_modfile, sim_optarg); 
			break;
		case 'r':
			gp->p_nutmeg = TRUE;
			break;
		case 'O':
			gp->p_csdf = TRUE;
			break;
		case 'x':
			gp->p_cache = TRUE;
			break;
		case 'U':
		default:
			usage(*argv);
			/* NOT REACHED */
	}

					/* circuit file */
	if (argv[sim_optind] != NULL) {
	   argv[sim_optind] = strip_ext(argv[sim_optind], SIM_FA_SUFFIX);
	   strcpy(gp->p_circuitfile, argv[sim_optind]);
	} else {
	   usage(*argv);
	}
					/* now look for command file */
	sim_optind++;
	if (argv[sim_optind] == NULL) {
	    strcpy(gp->p_commandfile, gp->p_circuitfile);
	} else {
	    argv[sim_optind] = strip_ext(argv[sim_optind], SIM_CMD_SUFFIX);
	    strcpy(gp->p_commandfile, argv[sim_optind]);
	    sim_optind++;
	}

	if (sim_optind != argc || argc == 1 ) /* incorrect number of options */
		usage(*argv);
	
		
					/* Initialize the Index System */
	if (sim_index_init(index)) {
	   sim_error(S_FATAL, S_CAZM, "unable to initialize indexing system");
	   exit(1);
	}

}

usage(name)
char *name;

{
	fprintf(stderr,
		"Usage: %s -acrxCMOUV [-o <outputfile> ] [-I index] [-D debug] [-m Model_file]\n <circuit_file> <command_file>\n",
		name);
	exit(1);
}

/*
---------------------------------------------------------------
|     STRIP_EXT
|     Take extension off filename and return result
|
|     Determines if there is an extension on a filename, if the 
|     extension is the same as the expected 'ext', the extension
|     is removed. Otherwise, the filename is returned as unchanged
---------------------------------------------------------------
*/
char *
strip_ext(name, ext)
char *name;			/* filename */
char *ext;			/* extension the filename may have */
{
	int l_ext;		/* length of extension */
	int l_name;		/* length of name */

	l_ext = strlen(ext);
	l_name = strlen(name);

	if (l_name < l_ext) 
	    return(name);

	if (strcmp(&name[l_name - l_ext], ext) == 0 &&
	    name[l_name - l_ext - 1] == '.') {
	    name[l_name - l_ext - 1] = '\0';
	}

	return(name);
}
/*
------------------------------------------------------------
|    ZERO_COUNT
|    Zero the variables in the count structure.
|
------------------------------------------------------------
*/
zero_count(count)
struct count_s *count;
{
	count->c_num_newtons = 0;
	count->c_num_inner = 0;
	count->c_uniquetr = 0;
	count->c_trans = 0;
	count->c_cap = 0;
	count->c_res = 0;
	count->c_ind = 0;
	count->c_transmission = 0;
	count->c_dio = 0;
	count->c_bjt = 0;
	count->c_jfet = 0;
	count->c_mesfet = 0;
	count->c_vvt = 0;
	count->c_cvt = 0;
	count->c_cct = 0;
	count->c_flops = 0l;
}
