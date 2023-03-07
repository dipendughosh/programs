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

	This file contains ALL the routines which write to the 
	output file.

----------------------------------------------------------------------------*/
/* $Header: output.c,v 1.4 87/10/30 16:09:27 erdman Locked $
   $Log:	output.c,v $
 * Revision 1.1  93/01/26  16:05:25  erdman
 * Initial revision
 * 
*/
#include <math.h>
#include <time.h>
#include "Hmain.h"
#include "Hcmd.h"
#include "sim.h"
#include "spcmd.h"

/*
-----------------------------------------------------------
|    OUTPUTVALUES
|
| Parameters -
|         The procedure uses the current time, voltage, current, and
|    charge to output the requested values.
|
| V_PLOT		- Report voltage difference between two nodes
| C_PLOT		- Report current at the terminal of a device
| Q_PLOT		- Report charge at the terminal of a device
| VOLT_PLOT		- Compute q or f through a voltage source
| CURRENT_PLOT  	- Compute q or f through a current source
| O_VOLT_PLOT		- Compute q or f through a non pwl voltage source
| O_CURRENT_PLOT	- Compute q or f through a non pwl current source
| VV_PLOT		- Compute q or f through a voltage-cntl-voltage source
| VC_PLOT 		- Compute q or f through a voltage-cntl-current source 
| POWER_PLOT 		- Report instantaneous power
|
| Returns -
|         The routine outputs values to the file pointer.
------------------------------------------------------------
*/

csdf_plot_header(gp, csdflst, type)
Param *gp;
struct csdflst_s *csdflst;
int type;					/* type of analysis */
{
	struct main_plot_s *pm;		/* loop var for outer plot list */
	struct plot_s *p;	/* loops through individual plot lists */

	struct cmd_power_s *pw;		/* instantaneous power */
	FILE *fd; 			/* output file pointer */
	double fval, qval;		/* current and charge values */
	double fvalp, qvalp;		/* parasitic current and charge value */
	double fnew;			/* new fo */
	double vval;			/* voltage difference */
	double pval;			/* power difference */
	double *f, *q, *fmid, *qmid;			
	char *time1, *date, *tmp;
	char var_str[80], type1[5];
	int i;
	long tloc;
	
	strcpy(var_str, "");
			/* Loop through file names */
	fprintf(csdflst->fd, "#H\n");
	fprintf(csdflst->fd, "SOURCE='%s'\n", "CAZM");
	fprintf(csdflst->fd, "VERSION='%s'\n", "5.0_work");
	fprintf(csdflst->fd, "TITLE='%s'\n", gp->p_circuitfile);
	fprintf(csdflst->fd, "SUBTITLE='%s'\n", "?");
	tloc = time(NULL);
	date = ctime(&tloc);
	if(date != NULL) {
	    /* remove the "\n" (stupid routine) */
	    date[24] = '\0';
	}
	gp->p_date = date;
	tmp=malloc(strlen(gp->p_date)+1);
	date=malloc(strlen(gp->p_date)+1);
	strcpy(tmp,gp->p_date);
	for (i=0;i<10;i++) {
	   *date = *tmp;
	   tmp++;
	   date++;
	}
	tmp++;
	time1=malloc(strlen(tmp)+1);
	for (i=0;i<8;i++) {
	   *time1 = *tmp;
	   tmp++;
	   time1++;
	}
        for (i=0; i<5; i++) {
	   *date = *tmp;
	   tmp++;
	   date++;
	}
	date=date-15;
	time1=time1-8;
	fprintf(csdflst->fd, "TIME='%s'\n", time1);
	fprintf(csdflst->fd, "DATE='%s'\n", date);
        free(tmp);
	free(time1);
	free(date);
   	pm = gp->p_plot;
   	p = pm->plot_n;
	switch(type) {
	   case TR:
	   case BDF:
	      fprintf(csdflst->fd, "TEMPERATURE='%g'\n", 
		   gp->p_temp->tpoints->temperature);
	      fprintf(csdflst->fd, "ANALYSIS='Transient Analysis'\n");
   	      fprintf(csdflst->fd, "NODES='%d'\n", csdflst->no_var);
   	      fprintf(csdflst->fd, "SWEEPVAR='TIME'\n");
   	      fprintf(csdflst->fd, "SWEEPMODE='VAR_STEP'\n");
   	      fprintf(csdflst->fd, "XBEGIN='%g'\n", gp->p_tdelay);
   	      fprintf(csdflst->fd, "XEND='%g'\n", gp->p_transient->finaltime);
	      break;
	   case TRANS:
	      fprintf(csdflst->fd, "TEMPERATURE='%g'\n", 
		   gp->p_temp->tpoints->temperature);
	      fprintf(csdflst->fd, "ANALYSIS='DC Analysis'\n");
   	      fprintf(csdflst->fd, "NODES='%d'\n", csdflst->no_var);
   	      fprintf(csdflst->fd, "SWEEPVAR='Voltage'\n");
   	      fprintf(csdflst->fd, "SWEEPMODE='LINEAR'\n");
   	      fprintf(csdflst->fd, "XBEGIN='%g'\n", gp->p_transfer->src[0]->start);
   	      fprintf(csdflst->fd, "XEND='%g'\n", gp->p_transfer->src[0]->end);
	      if (gp->p_transfer->src[1] != NULL) {
   	         fprintf(csdflst->fd, "SWEEP2PARM='Voltage'\n");
   	         fprintf(csdflst->fd, "SWEEP2VALUE='%g'\n", gp->p_transfer->src[1]->val);
	      }
	      break;
	   case AC:
	      fprintf(csdflst->fd, "ANALYSIS='AC Sweep'\n");
   	      fprintf(csdflst->fd, "NODES='%d'\n", csdflst->no_var);
   	      fprintf(csdflst->fd, "SWEEPVAR='Frequency'\n");
   	      fprintf(csdflst->fd, "SWEEPMODE='VAR_STEP'\n");
   	      fprintf(csdflst->fd, "XBEGIN='%g'\n", gp->p_ac->fstart);
   	      fprintf(csdflst->fd, "XEND='%g'\n", gp->p_ac->fstop);
	      break;
	   default:
	      fprintf(csdflst->fd, "Don't know what kind of analysis\n");
	      break;
	}
   	fprintf(csdflst->fd, "FORMAT='0 VOLTS;EFLOAT:NODE;NODE'\n");
   	fprintf(csdflst->fd, "#N\n");
   	p = pm->plot_n;
   	for ( p ; p != NULL; p = p->p_next){
   	   switch(p->p_printype) {
   	    /* print voltages */
   	       case SPCMD_V_PLOT:
		  if (p->p_node2 == NULL) 
   	             fprintf(csdflst->fd,"'%s'\n", p->p_node1);
		  else
   	             fprintf(csdflst->fd,"'%s,%s'\n",p->p_node1,p->p_node2);
   	          sprintf(var_str, "%s 'Volts'", var_str);
		  break;
   	       case SPCMD_VNODE_PLOT:
   	          fprintf(csdflst->fd,"'%s'\n", p->p_node1);
   	          sprintf(var_str, "%s 'Volts'", var_str);
		  break;
   	       case SPCMD_VTX_PLOT:
		  if (p->p_node2 == NULL) 
   	            fprintf(csdflst->fd,"'VTX(%s)'\n", p->p_node1);
		  else
   	            fprintf(csdflst->fd,"'VTX(%s,%s)'\n",p->p_node1,p->p_node2);
   	          sprintf(var_str, "%s 'Volts'", var_str);
   		  break;
   	       case SPCMD_VDC_PLOT:
		  if (p->p_node2 == NULL) 
   	            fprintf(csdflst->fd,"'VDC(%s)'\n", p->p_node1);
		  else
   	            fprintf(csdflst->fd,"'VDC(%s,%s)'\n",p->p_node1,p->p_node2);
   	          sprintf(var_str, "%s 'Volts'", var_str);
   		  break;
   	       case SPCMD_P_PLOT:
   	          fprintf(csdflst->fd,"'P(%s,%s)'\n",p->p_node1,p->p_node2);
   	          sprintf(var_str, "%s 'Watts'", var_str);
		  break;
   	       case SPCMD_PTX_PLOT:
   	          fprintf(csdflst->fd,"'PTX(%s,%s)'\n",p->p_node1,p->p_node2);
   	          sprintf(var_str, "%s 'Watts'", var_str);
		  break;
   	       case SPCMD_PDC_PLOT:
		  if (p->p_node2 == NULL) 
   	            fprintf(csdflst->fd,"'PDC(%s, %s)'\n", p->p_node1, "GND");
		  else
   	            fprintf(csdflst->fd,"'PDC(%s,%s)'\n",p->p_node1,p->p_node2);
   	          sprintf(var_str, "%s 'Watts'", var_str);
   		  break;
   	       case SPCMD_C_PLOT:
   	         fprintf(csdflst->fd,"'I(%s,%s)'\n",p->p_devicename,p->p_node1);
   	         sprintf(var_str, "%s 'Amps'", var_str);
		 break;
   	       case SPICE_C_PLOT:
   	          fprintf(csdflst->fd,"'I(%s)'\n", p->p_devicename);
   	          sprintf(var_str, "%s 'Amps'", var_str);
   		  break;
   	       case SPCMD_CTX_PLOT:
   	       fprintf(csdflst->fd,"'ITX(%s,%s)'\n",p->p_devicename,p->p_node1);
   	       sprintf(var_str, "%s 'Amps'", var_str);
	       break;
   	       case SPICE_CDC_PLOT:
   	          fprintf(csdflst->fd,"'I(%s)'\n", p->p_devicename);
   	          sprintf(var_str, "%s 'Amps'", var_str);
		  break;
   	       case SPCMD_CDC_PLOT:
   	       fprintf(csdflst->fd,"'ITX(%s,%s)'\n",p->p_devicename,p->p_node1);
   	       sprintf(var_str, "%s 'Amps'", var_str);
	       break;
   	       case SPCMD_Q_PLOT:
   	         fprintf(csdflst->fd,"'Q(%s,%s)'\n",p->p_devicename,p->p_node1);
   	         sprintf(var_str, "%s 'Coulombs'", var_str);
		 break;
   	       case SPCMD_QTX_PLOT:
   	       fprintf(csdflst->fd,"'QTX(%s,%s)'\n",p->p_devicename,p->p_node1);
   	       sprintf(var_str, "%s 'Coulombs'", var_str);
	       break;
   	       case SPCMD_QDC_PLOT:
   	       fprintf(csdflst->fd,"'QDC(%s,%s)'\n",p->p_devicename,p->p_node1);
   	       sprintf(var_str, "%s 'Coulombs'", var_str);
	       break;
	       case SPCMD_DB_VPLOT:
		  strcpy(type1, "VDB");
   	          sprintf(var_str, "%s 'Volts'", var_str);
	          break;
	       case SPCMD_PHASE_VPLOT: 
		  strcpy(type1, "VP");
   	          sprintf(var_str, "%s 'Volts'", var_str);
	          break;
	       case SPCMD_MAG_VPLOT:
		  strcpy(type1, "VM");
   	          sprintf(var_str, "%s 'Volts'", var_str);
	          break;
	       case SPCMD_IMAG_VPLOT:
		  strcpy(type1, "VI");
   	          sprintf(var_str, "%s 'Volts'", var_str);
	          break;
	       case SPCMD_REAL_VPLOT:
		  strcpy(type1, "VR");
   	          sprintf(var_str, "%s 'Volts'", var_str);
	          break;
	       case SPICE_PHASE_CPLOT:
	       case SPCMD_PHASE_CPLOT:
		  strcpy(type1, "IP");
   	          sprintf(var_str, "%s 'Amps'", var_str);
	          break;
	       case SPICE_MAG_CPLOT:
	       case SPCMD_MAG_CPLOT:
		  strcpy(type1, "IM");
   	          sprintf(var_str, "%s 'Amps'", var_str);
	          break;
	       case SPICE_IMAG_CPLOT:
	       case SPCMD_IMAG_CPLOT:
		  strcpy(type1, "II");
   	          sprintf(var_str, "%s 'Amps'", var_str);
	          break;
	       case SPICE_REAL_CPLOT:
	       case SPCMD_REAL_CPLOT:
		  strcpy(type1, "IR");
   	          sprintf(var_str, "%s 'Amps'", var_str);
	          break;
	       case SPICE_DB_CPLOT:
	       case SPCMD_DB_CPLOT:
		  strcpy(type1, "IDB");
   	          sprintf(var_str, "%s 'Amps'", var_str);
	          break;
   	       default:
   		  break;
           }
	   if (type == AC)
	      if(p->p_node2 == NULL) {
   	         fprintf(csdflst->fd,"'%s(%s)'\n",type1, p->p_node1);
	      } else {
   	         fprintf(csdflst->fd,"'%s(%s,%s)'\n",
		    type1, p->p_node1,p->p_node2);
              }
   	}
   	fprintf(csdflst->fd, "#U\n");
   	fprintf(csdflst->fd, "%s\n", var_str);
}
/*
----------------------------------------------------------------
|     CSDF_SETUP
|     Create the csdf header information (all but the number of lines)
|
----------------------------------------------------------------
*/
csdf_setup(pm)
struct main_plot_s *pm;
{
	struct plot_s *p;
	int ac;
	int cnt, nodes;

	p = pm->plot_n;
	nodes=0;
	for ( p ; p != NULL; p = p->p_next, nodes++){}
	pm->csdfhead = (struct csdflst_s *) sim_alloc(
		sizeof(struct csdflst_s), S_CAZM);
	pm->csdfhead->fd = pm->fd;
	pm->csdfhead->plotname = pm->filename;
	pm->csdfhead->title = pm->filename;
	ac = FALSE;
	cnt = 1;
	for (p = pm->plot_n; p != NULL; p = p->p_next) {
	    if (p->p_printype >= SPCMD_PHASE_VPLOT && 
		p->p_printype <= SPCMD_DB_CPLOT)
		ac = TRUE;
	    if (p->p_printype != NULL && (p->p_printype < SPCMD_VDC_PLOT ||
		p->p_printype > SPCMD_PDC_PLOT))
	        cnt++;
	}
/* In the future we may want to put it out in complex format but not now 
	if (ac)
	    pm->csdfhead->complex = TRUE;
	else
	    pm->csdfhead->complex = FALSE;
*/
	pm->csdfhead->complex = FALSE;

	pm->csdfhead->no_var = cnt-1;
	pm->csdfhead->no_pnt = 1000000;
	pm->csdfhead->name = (char **)sim_calloc(sizeof(char *),cnt,S_CAZM);
	pm->csdfhead->type = (int *)sim_calloc(sizeof(int),cnt,S_CAZM);
	pm->csdfhead->cnt = 0;
}
csdf_finish(gp)
struct param_s *gp;
{
        struct main_plot_s *pm;       /* loop var for outer plot list */

	for (pm = gp->p_plot; pm != NULL; pm = pm->next) {
					/* rewind file */
	    rewind(pm->csdfhead->fd);
	    pm->csdfhead->no_pnt = pm->csdfhead->cnt;
	    csdf_plot_header(gp, pm->csdfhead, 0);
	}
}
