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
 * Revision 1.4  87/10/30  16:09:27  erdman
 * October release version
 * 
 * Revision 1.2  87/03/25  13:23:02  erdman
 * release version
 * 
 * Revision 1.1  86/07/29  14:35:25  erdman
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
|    Traverses the plot list and outputs the requested values
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

outputvalues(to, time, ui, gp, type, fo, qo, val_double)
double to;					/* old time */
double time;					/* current time */
double *ui;					/* array of voltages */
struct param_s *gp;
int type;					/* type of analysis */
double *fo;
double *qo;
Val_Double *val_double;
{
	struct main_plot_s *pm;		/* loop var for outer plot list */
	struct plot_s *p;		/* loop var for plot list */
	struct cmd_power_s *pw;		/* instantaneous power */
	FILE *fd; 			/* output file pointer */
	double fval, qval;		/* current and charge values */
	double fvalp, qvalp;		/* parasitic current and charge value */
	double fnew;			/* new fo */
	double vval;			/* voltage difference */
	double pval;			/* power difference */
	double *f, *q, *fmid, *qmid;			
	int i;
	
	pm = gp->p_plot;
	p = pm->plot_n;
	i=0;
			/* Loop through file names */
	for (pm = gp->p_plot; pm != NULL; pm = pm->next) {
	  fd = pm->fd;

			/* Print time if transient simulation */
	  if ((type == TR || type == BDF) && (pm->mode & TR_PLOT) ) {
	    if (gp->p_csdf) fprintf(fd, "#C %g %d\n", time, pm->csdfhead->no_var);
	    if( time >= gp->p_tdelay) {
	       if ((pm->nuthead == NULL)  && (pm->csdfhead == NULL))
	          fprintf(fd,pm->plot_n->p_format, time-gp->p_tdelay);  /* wrr 6/16/92 */
	       else if (pm->nuthead != NULL) {
	          fprintf(fd,"%d\t\t%20.15e",pm->nuthead->cnt, time-gp->p_tdelay);
	          (pm->nuthead->cnt)++;
	       } else {
	          (pm->csdfhead->cnt)++;
	       }
	    } 
	  } else if ((type == TRANS) && (pm->mode & TX_PLOT)) {
	       if (gp->p_csdf) fprintf(fd, "#C %g %d\n", gp->p_transfer->src[0]->val, pm->csdfhead->no_var);
	  } else if ((type == DC) && (pm->mode & DC_PLOT)) 
	       if (gp->p_csdf) fprintf(fd, "#C %g %d\n", time, pm->csdfhead->no_var);
			/* Loop through plot elements for each file */
	  for ( p = pm->plot_n; p != NULL; p = p->p_next) {
	    f = &p->p_dev->c_fq[0];
	    fmid = &p->p_fqmid[0];
	    q = &p->p_dev->c_fq[3];
	    qmid = &p->p_fqmid[3];
	    fval = 0.0;
	    qval = 0.0;

			/* Print nothing */
	    if (p->p_printype == NULL) 
		    continue;	

	    switch(p->p_caltype) {
	    				/* print voltages */
		case V_DIFF_PLOT:
		    vval = ui[p->p_nodes[0]] - ui[p->p_nodes[1]];
		    break;
					/* Resistors, capacitors, diodes */
		case TWOTERM_PLOT: 
			/* Two terminal device */
		    if (p->p_termnum == 0) {
			if(type == TR) {
			    fval = fmid[0];
			    qval = qmid[0];
			}
			else {
			    qval = q[0];
			    fval = f[0];
			}
		    }
		    else if (p->p_termnum == 1) {
			if(type == TR) {
			    qval = -qmid[0];
			    fval = -fmid[0];
			}
			else { 
			    qval = -q[0];
			    fval = -f[0];
			}
		    }
				/* add the parasitic components */
		    fq_parasitic(p, &fval, &qval, type);
		    break;
			/* Three terminal device */
		case THREETERM_PLOT:
		    if (p->p_termnum == 0) {
			if(type == TR) {
			    qval = qmid[0];
			    fval = fmid[0];
			}
			else {
			    qval = q[0];
			    fval = f[0];
			}
		    }
		    else if (p->p_termnum == 1) {
			if(type == TR) {
			    qval = qmid[1];
			    fval = fmid[1];
			}
			else { 
			    qval = q[1];
			    fval = f[1];
			}
		    }
		    else if (p->p_termnum == 2) {
			if(type == TR) {
			    qval = -(qmid[0] + qmid[1]);
			    fval = -(fmid[0] + fmid[1]);
			}
			else { 
			    qval = -(q[0] + q[1]);
			    fval = -(f[0] + f[1]);
			}
		    }
				/* add the parasitic components */
		    fq_parasitic(p, &fval, &qval, type);
		    break;

			/* Four terminal device */
		case FOURTERM_PLOT:
		    if (p->p_termnum == 0) {
			if(type == TR) {
			    qval = qmid[0];
			    fval = fmid[0];
			}
			else {
			    qval = q[0];
			    fval = f[0];
			}
		    }
		    else if (p->p_termnum == 1) {
			if(type == TR) {
			    qval = qmid[1];
			    fval = fmid[1];
			}
			else {
			    qval = q[1];
			    fval = f[1];
			}
		    }
		    else if (p->p_termnum == 2) {
			if(type == TR) {
			    qval = qmid[2];
			    fval = fmid[2];
			}
			else {
			    qval = q[2];
			    fval = f[2];
			}
		    }
		    else if (p->p_termnum == 3) {
			if(type == TR) {
			    qval = -(qmid[0] + qmid[1] + qmid[2]);
			    fval = -(fmid[0] + fmid[1] + fmid[2]);
			}
			else { 
			    qval = -(q[0] + q[1] + q[2]);
			    fval = -(f[0] + f[1] + f[2]);
			}
		    }
				/* add the parasitic components */
		    fq_parasitic(p, &fval, &qval, type);
		    break;
	        case VC_PLOT:
				/* Special circuit device voltage
				 * controlled current sources
				 */
		    if (p->p_termnum == 0) {
			if(type == TR) {
			    qval = -qmid[0];
			    fval = -fmid[0];
			}
			else {
			    qval = -q[0];
			    fval = -f[0];
			}
		    }
		    else if (p->p_termnum == 1) {
			if(type == TR) {
			    qval = qmid[0];
			    fval = fmid[0];
			}
			else { 
			    qval = q[0];
			    fval = f[0];
			}
		    }
		    else {
			fval =0;
			qval =0;
		    }
		    break;
	        case IND_VC_PLOT:
				/* Special voltage-cntl-current source
				 * used to model an inductor.
				 */
		    if (p->p_termnum == 0) {
			if(type == TR) {
			    fval = -fmid[0];
			    qval = -qmid[0];
			}
			else  { 
			    fval = -f[0];
			    qval = -q[0];
			}
		    }
		    else if (p->p_termnum == 1) {
			if(type == TR) {
			    fval = fmid[0];
			    qval = qmid[0];
			}
			else  {
			    fval = f[0];
			    qval = q[0];
			}
		    }
		    else {
			fval =0;
			qval =0;
		    }
		    break;
		case CURRENT_PLOT:
			/* current sources */
		    if (p->p_nodes[0] == p->p_iv->b_node1) {
			if(type == TR) 
			    fval = -fmid[0];
			else 
			    fval = -p->p_iv->b_fo;
		    }
		    else {
			if(type == TR) 
			    fval = fmid[0];
			else 
			    fval = p->p_iv->b_fo;
		    }
		    qval = 0;
		    break;
		case O_CURRENT_PLOT:
			/* Other current sources */
		    {
		    struct other_wavef_s *ov;
			/* recast it */
		    ov = (struct other_wavef_s *) p->p_iv;
		    if (p->p_nodes[0] == ov->o_node1) {
			if(type == TR) 
			    fval = -fmid[0];
			else 
			    fval = -ov->o_fo;
		    }
		    else {
			if(type == TR) 
			    fval = fmid[0];
			else 
			    fval = ov->o_fo;
		    }
		    qval = 0;
		    }
		    break;
	        case VV_PLOT:
			/* Voltage controlled voltage sources */
		    {
		    struct volt_volt_s *vv;

		    vv = (struct volt_volt_s *) p->p_iv;
		    if (p->p_nodes[0] == vv->v_node1)
			if(type == TR) {
			    fval = -fmid[0];
			    qval = -qmid[0];
			}
			else {
			    fval = -vv->v_fo;
			    qval = -vv->v_qo;
			}
		    else
			if(type == TR) {
			    fval = fmid[0];
			    qval = qmid[0];
			}
			else  { 
			    fval = vv->v_fo;
			    qval = vv->v_qo;
			}
		    }
		    break;
	        case VOLT_PLOT:
			/* voltage sources */
		    if (p->p_nodes[0] == p->p_iv->b_node1) 
			if(type == TR) {
			    fval = -val_double->fg[p->p_iv->b_node1];
			    qval = -val_double->qg[p->p_iv->b_node1];
			}
			else  { 
			    if (time == 0.0) {
				fval = -val_double->fo[p->p_iv->b_node1];
				qval = -val_double->qo[p->p_iv->b_node1];
			    }
			    else {
				fval = -val_double->fi[p->p_iv->b_node1];
				qval = -val_double->qi[p->p_iv->b_node1];
			    }
			}
		    else
			if(type == TR) {
			    fval = val_double->fg[p->p_iv->b_node1];
			    qval = val_double->qg[p->p_iv->b_node1];
			}
			else  { 
			    if (time == 0.0) {
				fval = val_double->fo[p->p_iv->b_node1];
				qval = val_double->qo[p->p_iv->b_node1];
			    }
			    else {
				fval = val_double->fi[p->p_iv->b_node1];
				qval = val_double->qi[p->p_iv->b_node1];
			    }
			}
		    break;

	        case  O_VOLT_PLOT:
			/* Other voltage sources */
		    {
		    struct other_wavef_s *ov;
		    ov = (struct other_wavef_s *) p->p_iv;

		    if (p->p_nodes[0] == ov->o_node1) 
			if(type == TR) {
			    fval = -val_double->fg[ov->o_node1];
			    qval = -val_double->qg[ov->o_node1];
			}
			else  { 
			    if (time == 0.0) {
				fval = -val_double->fo[ov->o_node1];
				qval = -val_double->qo[ov->o_node1];
			    }
			    else {
				fval = -val_double->fi[ov->o_node1];
				qval = -val_double->qi[ov->o_node1];
			    }
			}
		    else
			if(type == TR) {
			    fval = val_double->fg[ov->o_node1];
			    qval = val_double->qg[ov->o_node1];
			}
			else  { 
			    if (time == 0.0) {
				fval = val_double->fo[ov->o_node1];
				qval = val_double->qo[ov->o_node1];
			    }
			    else {
				fval = val_double->fi[ov->o_node1];
				qval = val_double->qi[ov->o_node1];
			    }
			}
		    }
		    break;
	        case  POWER_PLOT:
		    pw = p->p_power;
		    if (time == 0.0 || type == DC || type == TRANS) {
			int node1, node2;
					/* get node with the current */
			if (pw->p_nodes[0] < pw->p_nodes[1]) {
		    	    node1 = pw->p_nodes[0];
		    	    node2 = pw->p_nodes[1];
			} else {
		    	    node2 = pw->p_nodes[0];
		    	    node1 = pw->p_nodes[1];
			}
					/* compute initial power */
		        pval = val_double->fo[node1] * (val_double->uo[node1]-
				val_double->uo[node2]);
		    }
		    else if (type == TR)
		        pval = pw->tr_inst;
		    else if (type == BDF)
			pval = pw->bdf_inst;
		    else
			pval = 0.0;
		    break;
	        default:
		    break;	/* AC or nothing to plot */

	    }	/* end of switch */

			/*	Print the voltage, current, and charge.  */
	    if ((type == TR || type == BDF) && (pm->mode & TR_PLOT) && (time >= gp->p_tdelay)) {

			/* Print the voltage values */
		if (p->p_printype == SPCMD_V_PLOT ||
			p->p_printype == SPCMD_VNODE_PLOT) {
			if (gp->p_csdf) {
			    i++;
			    fprintf(fd, "%g:%x ", vval, i);
			} else 
			    fprintf(fd, p->p_format, vval);
		} else if (p->p_printype == SPCMD_P_PLOT) {
			if (gp->p_csdf) {
			    i++;
			    fprintf(fd, "%g:%x ", pval, i);
			} else 
			    fprintf(fd, p->p_format, pval);
			/* Print the device currents */
		} else if (p->p_printype == SPCMD_C_PLOT ||
				p->p_printype == SPICE_C_PLOT){
			/* Initialize at time = zero. */
		    if (time == 0.0) {

			p->p_qold = qval;
			p->p_fold = fval;
		    }
		    else {	
			fnew = fval;
			if (type == TR ) {
			    fval = (qval - p->p_qold)/(time - to) +
				    ((p->p_fold + fnew) * 0.5);
			p->p_qmid = qval;
			p->p_fmid = fnew;
			}
			else if (type == BDF) {
			    fval = fnew + ((((2.0 - GAMMA) * qval)
				- (p->p_qmid * INV_GAMMA)
				    + (INV_GAMMA1SQ * p->p_qold)) /
					    (time - to));
			p->p_qold = qval; 
			p->p_fold = fnew;
			}
		    }
			/* Print current for TR, and BDF */
		    if (gp->p_csdf) {
		       i++;
		       fprintf(fd, "%g:%x ", fval, i);
		    } else 
		       fprintf(fd, p->p_format, fval);
		}
		
			/* Plot the charge values */
		else if (p->p_printype == SPCMD_Q_PLOT) 
		    if (gp->p_csdf) {
		       i++;
		       fprintf(fd, "%g:%x ", qval, i);
		    } else 
		       fprintf(fd, p->p_format, qval);
	    }
	    else if ((type == TRANS) && (pm->mode & TX_PLOT)) {

			/* Print the voltage values */
		if (p->p_printype == SPCMD_VTX_PLOT ||
			p->p_printype == SPCMD_VNODE_PLOT) {
			if (gp->p_csdf) {
			    i++;
			    fprintf(fd, "%g:%x ", vval, i);
			} else 
			    fprintf(fd,p->p_format, vval);

			/* Print the device currents */
		} else if (p->p_printype == SPCMD_CTX_PLOT) 
		    if (gp->p_csdf) {
		        i++;
		        fprintf(fd, "%g:%x ", fval, i);
		    } else 
		        fprintf(fd,p->p_format, fval);

			/* Plot the charge values */
		else if (p->p_printype == SPCMD_QTX_PLOT) 
		    if (gp->p_csdf) {
		       i++;
		       fprintf(fd, "%g:%x ", qval, i);
		    } else 
		       fprintf(fd, p->p_format, qval);

			/* Plot the power values */
		else if (p->p_printype == SPCMD_PTX_PLOT) 
		    if (gp->p_csdf) {
			i++;
			fprintf(fd, "%g:%x ", vval, i);
		    } else 
		        fprintf(fd, p->p_format, pval);

			/* Print the device currents */
		else if (p->p_printype == SPICE_CTX_PLOT) 
		    if (gp->p_csdf) {
		        i++;
		        fprintf(fd, "%g:%x ", fval, i);
		    } else 
		        fprintf(fd,p->p_format, fval);

	    }
	    else if ((type == DC) && (pm->mode & DC_PLOT)) {

	        if ((pm->nuthead != NULL) || (pm->csdfhead != NULL))
		    fd = stdout;
	        if (p->p_printype == SPCMD_VNODE_PLOT) {
		    if (gp->p_csdf) {
		       i++;
		       fprintf(fd, "%g:%x ", vval, i);
		    } else  {
		       fprintf(fd,"\n%s = ", p->p_node1);
		       fprintf(fd, p->p_format, vval);
		    }
		} else 
	        if (p->p_printype == SPCMD_VDC_PLOT && p->p_node2 == NULL) {
		    if (gp->p_csdf) {
		       i++;
		       fprintf(fd, "%g:%x ", vval, i);
		    } else  {
		       fprintf(fd,"\nvdc(%s) = ", p->p_node1);
		       fprintf(fd, p->p_format, vval);
		    }
	        } else 
	        if (p->p_printype == SPCMD_VDC_PLOT) {
		    if (gp->p_csdf) {
		       i++;
		       fprintf(fd, "%g:%x ", vval, i);
		    } else  {
		       fprintf(fd,"\nvdc(%s,%s) = ", p->p_node1, p->p_node2);
		       fprintf(fd, p->p_format, vval);
		    }
	        } else 
	        if (p->p_printype == SPCMD_CDC_PLOT) {
		    if (gp->p_csdf) {
		       i++;
		       fprintf(fd, "%g:%x ", fval, i);
		    } else  {
		       fprintf(fd,"\nidc(%s,%s) = ", p->p_devicename, p->p_node1);
		       fprintf(fd, p->p_format, fval);
		    }
		} else
	        if (p->p_printype == SPCMD_QDC_PLOT) {
		    if (gp->p_csdf) {
		       i++;
		       fprintf(fd, "%g:%x ", qval, i);
		    } else  {
		        fprintf(fd,"\nqdc(%s,%s) = ", p->p_devicename, p->p_node1);
		        fprintf(fd, p->p_format, qval);
		    }
		} else
	        if (p->p_printype == SPCMD_PDC_PLOT && p->p_node2 == NULL) {
		    if (gp->p_csdf) {
		       i++;
		       fprintf(fd, "%g:%x ", pval, i);
		    } else  {
		       fprintf(fd,"\npdc(%s,%s) = ", p->p_node1, "GND");
		       fprintf(fd, p->p_format, pval);
		    }
		} else
	        if (p->p_printype == SPCMD_PDC_PLOT) {
		    if (gp->p_csdf) {
		       i++;
		       fprintf(fd, "%g:%x ", pval, i);
		    } else  {
		       fprintf(fd,"\npdc(%s,%s) = ", p->p_node1, p->p_node2);
		       fprintf(fd, p->p_format, pval);
		    }
	        } else 
	        if (p->p_printype == SPICE_CDC_PLOT) {
		    if (gp->p_csdf) {
		       i++;
		       fprintf(fd, "%g:%x ", fval, i);
		    } else  {
		       fprintf(fd,"\nidc(%s) = ", p->p_devicename);
		       fprintf(fd, p->p_format, fval);
		    }
		}
	    }
	}

			/* Don't print if AC mode */
	if ((type == TR || type == BDF) && (pm->mode & TR_PLOT) && (time >= gp->p_tdelay && (time >= gp->p_tdelay))) {
	    if (gp->p_csdf && (time == gp->p_transient->finaltime)) {
	       fprintf(fd, "\n#;");
	    }
	    fprintf(fd, "\n");
	} else if ((type == TRANS) && (pm->mode & TX_PLOT)) {
	    if (gp->p_csdf && (fabs(gp->p_transfer->src[0]->end - 
	       gp->p_transfer->src[0]->val) < 1e-5))
	       fprintf(fd, "\n#;");
            fprintf(fd, "\n");
	} else if ((type == DC) && (pm->mode & DC_PLOT)) 
            fprintf(fd, "\n");
    }
}


fq_parasitic(p, fval, qval, type)
struct plot_s *p;
double *fval;
double *qval;
int type;	
{
	struct circuit_s *cp;
	struct plot_parasitic_s *par;
	double *f, *q, *fmid, *qmid;

	for(par = p->p_parasitic; par != NULL; par = par->next) {
	
	    cp  = par->device;
	    f = &cp->c_fq[0];
	    fmid = &par->fqmid[0];
	    q = &cp->c_fq[3];
	    qmid = &par->fqmid[3];

	    if(p->p_termnum == par->termnum1) {

		    /* Two terminal device  */
		    if(type == TR) {
			*fval += fmid[0];
			*qval += qmid[0];
		    }
		    else {
			*qval += q[0];
			*fval += f[0];
		    }
	    }
	    else if(p->p_termnum == par->termnum2) {

		    if(type == TR) {
			*qval += -qmid[0];
			*fval += -fmid[0];
		    }
		    else { 
			*qval += -q[0];
			*fval += -f[0];
		    }
	    }
	}

}

/*
-------------------------------------------------------------------
|    PRINT_HEAD
|    prints header for all output. 
|
--------------------------------------------------------------------
*/
print_head(gp, type)
Param *gp;
int type;			/* printed before plot list, usually time*/
{
	struct main_plot_s *pm;		/* plot list */
	struct plot_s *p;	/* loops through individual plot lists */
	char temp[128];		/* holds characters for format */
	FILE *fd;		/* output file pointer */
	int cnt;

	pm = gp->p_plot;

	for (pm; pm != NULL; pm = pm->next) {
	    p = pm->plot_n;
	    fd = pm->fd;
	    cnt = 0;
	    if ((type == DC) && (pm->mode & DC_PLOT)) {
		if ((pm->nuthead != NULL) || (pm->csdfhead != NULL)) {
		    fprintf(stdout, "\nDC ANALYSIS");
		} else
		    fprintf(fd, "\nDC ANALYSIS");
		continue;
	    }
	    else if ((type == TR || type == BDF) && (pm->mode & TR_PLOT)) {

		if (pm->nuthead != NULL) {
	    	    pm->nuthead->name[cnt] = (char *) sim_alloc(5, S_CAZM);
	    	    strcpy(pm->nuthead->name[cnt],"time"); 
	    	    pm->nuthead->type[cnt] = -1;
		    cnt++;
		} else if (pm->csdfhead != NULL) {
	    	    pm->csdfhead->name[cnt] = (char *) sim_alloc(5, S_CAZM);
	    	    strcpy(pm->csdfhead->name[cnt],"time"); 
	    	    pm->csdfhead->type[cnt] = -1;
		    cnt++;
		} else {
		    fprintf(fd, "\nTRANSIENT ANALYSIS");
		    fprintf(fd, "\n%-11.11s", "Time");
		}

		for ( p ; p != NULL; p = p->p_next, cnt++) {
			/* Nothing to plot */
		
		    if (p->p_printype == NULL)
			continue;

		    if (p->p_printype == SPCMD_VNODE_PLOT) { 
			sprintf(temp,"%s", p->p_node1);
			print_headstr(gp, temp, p, fd, cnt,
				pm->nuthead,VOLT);
		    }
		    else 
		    if (p->p_printype == SPCMD_V_PLOT && p->p_node2 == NULL) {
			sprintf(temp,"v(%s)", p->p_node1);
			print_headstr(gp, temp, p, fd, cnt,
				pm->nuthead,VOLT);
		    }
		    else 
		    if (p->p_printype == SPCMD_V_PLOT) {
			sprintf(temp,"v(%s,%s)", p->p_node1, p->p_node2);
			print_headstr(gp, temp, p, fd, cnt,
				pm->nuthead,VOLT);
		    }
		    else 
		    if (p->p_printype == SPCMD_C_PLOT) {
			sprintf(temp,"i(%s,%s)", p->p_devicename, p->p_node1);
			print_headstr(gp, temp, p, fd, cnt,
				pm->nuthead, CURRENT);
		    }
		    else
		    if (p->p_printype == SPCMD_Q_PLOT) {
			sprintf(temp,"q(%s,%s)", p->p_devicename, p->p_node1);
			print_headstr(gp, temp, p, fd, cnt,
				pm->nuthead, CURRENT);
		    }
		    else 
		    if (p->p_printype == SPCMD_P_PLOT) {
			sprintf(temp,"p(%s,%s)", p->p_node1, p->p_node2);
			print_headstr(gp, temp, p, fd, cnt,
				pm->nuthead, CURRENT);
		    }
		    else 
		    if (p->p_printype == SPICE_C_PLOT) {
			sprintf(temp,"i(%s)", p->p_devicename);
			print_headstr(gp, temp, p, fd, cnt,
				pm->nuthead, CURRENT);
		    }

		}
		if ((pm->nuthead == NULL) && (pm->csdfhead == NULL))
		    fprintf(fd, "\n");
		else if (pm->nuthead != NULL) 
		    nutmeg_plot_header(gp, pm->nuthead);
		else
		    csdf_plot_header(gp, pm->csdfhead, type);
	    }
	    else if ((type == TRANS) && (pm->mode & TX_PLOT)) {
		if (pm->nuthead != NULL) {
	    	   pm->nuthead->name[cnt] = (char *) sim_alloc(5, S_CAZM);
	    	   strcpy(pm->nuthead->name[cnt],"Time"); 
	    	   pm->nuthead->type[cnt] = -1;
		   cnt++;
		} else if (pm->csdfhead != NULL) {
	    	   pm->csdfhead->name[cnt] = (char *) sim_alloc(5, S_CAZM);
	    	   strcpy(pm->csdfhead->name[cnt],"Time"); 
	    	   pm->csdfhead->type[cnt] = -1;
		   cnt++;
		} else {
		   fprintf(fd, "\nTRANSFER ANALYSIS\n");
		}
	   
		for ( p ; p != NULL; p = p->p_next, cnt++) {
			/* Nothing to plot */
		    if (p->p_printype == NULL)
			continue;

		    if (p->p_printype == SPCMD_VNODE_PLOT) {
			sprintf(temp,"%s", p->p_node1);
			print_headstr(gp, temp, p, fd, cnt,
				pm->nuthead, VOLT);
		    }
		    else
		    if (p->p_printype == SPCMD_VTX_PLOT && p->p_node2 == NULL ) {
			sprintf(temp,"vtx(%s)", p->p_node1);
			print_headstr(gp, temp, p, fd, cnt,
				pm->nuthead, VOLT);
		    }
		    else
		    if (p->p_printype == SPCMD_VTX_PLOT) {
			sprintf(temp,"vtx(%s,%s)", p->p_node1, p->p_node2);
			print_headstr(gp, temp, p, fd, cnt,
				pm->nuthead, VOLT);
		    }
		    else 
		    if (p->p_printype == SPCMD_CTX_PLOT) {
			sprintf(temp,"itx(%s,%s)",p->p_devicename, p->p_node1);
			print_headstr(gp, temp, p, fd, cnt,
				pm->nuthead, CURRENT);
		    }
		    else
		    if (p->p_printype == SPCMD_QTX_PLOT) {
			sprintf(temp,"qtx(%s,%s)",p->p_devicename, p->p_node1);
			print_headstr(gp, temp, p, fd, cnt,
				pm->nuthead, CURRENT);
		    }
		    else 
		    if (p->p_printype == SPCMD_PTX_PLOT) {
			/* NOT YET */;
		    }
		    else 
		    if (p->p_printype == SPICE_CTX_PLOT) {
			sprintf(temp,"itx(%s)",p->p_devicename);
			print_headstr(gp, temp, p, fd, cnt,
				pm->nuthead, CURRENT);
		    }

		}
		if ((pm->nuthead == NULL) && (pm->csdfhead == NULL))
		    fprintf(fd, "\n");
		else if (pm->nuthead != NULL) 
		    nutmeg_plot_header(gp, pm->nuthead);
		else
		    csdf_plot_header(gp, pm->csdfhead, type);
	    }
	}
}

print_headstr(gp, s, p, fd, cnt, nuthead, type)
Param *gp;
char *s;
struct plot_s *p;	/* plot structure */
FILE *fd;		/* output file pointer */
int cnt;		/* entry in the plot list */
struct nutlst_s *nuthead;
int type;		/* current or voltage */
{
	char strformat[12];
	int len;
	int fixed;

	len = strlen(s);

	fixed = len;
	if(gp->p_decimal + 7 > fixed)
	    fixed = 7 + gp->p_decimal;

		/* Set the string and floating point format */
	sprintf(strformat," %%%d.%ds\0", fixed, fixed);
	sprintf(p->p_format," %%%d.%de\0", fixed, gp->p_decimal);

	if (nuthead != NULL) {
	    nuthead->name[cnt] = (char *) sim_alloc(len+2, S_CAZM);
	    if (type == CURRENT) {
	       sscanf(s,"%[^(]",s);
	       sprintf(nuthead->name[cnt],"%s_%s#%s\0", s,
			p->p_devicename, p->p_node1); 
	    } else {
	       strcpy(nuthead->name[cnt],s); 
	    }
	    nuthead->type[cnt] = type;
	    sprintf(p->p_format,"%s%%20.15e\0", "\n\t", len+1);
	} else if (gp->p_csdf == NULL)
	    fprintf(fd, strformat, s);
}


open_files(gp)
struct param_s *gp;	/* pointer to information structure */
{
	struct main_plot_s *pm;
	struct main_acmodel_s *acm;
	FILE *fd, *fd2, *fd3;			/* output file name */
	char *date;
	long tloc;

			/* get the date and print a header */
	tloc = time(NULL);
	date = ctime(&tloc);
	if(date != NULL) {
	    /* remove the "\n" (stupid routine) */
	    date[24] = '\0';
	}
	gp->p_date = date;
					/* Open PLOT files */
	if (strcmp(gp->p_outputfile, "") == 0) {
	    fd = stdout;
	} else {
	    if ((fd = fopen(gp->p_outputfile,"w")) == NULL) {
		sim_error(S_WARNING, S_CAZM, "Can't open file %s",
			gp->p_outputfile);
		fd = stdout;
	    }
	}
	for (pm = gp->p_plot; pm != NULL; pm = pm->next) {
	    if (strcmp(pm->filename, NONAME) == 0) {
		pm->fd = fd;
				/* print the CAzM header */
		if (!gp->p_nutmeg && !gp->p_csdf)
		if(date != NULL) 
		    fprintf(pm->fd,"* CAzM Simulation\t%s\t%s\n",
			    date, gp->p_circuitfile);
		else
		    fprintf(pm->fd,"* CAzM Simulation\t\t\t\t%s\n",
			    gp->p_circuitfile);
	    }
	    else {
	        if ((fd2 = fopen(pm->filename,"w")) == NULL) {
		    sim_error(S_WARNING, S_CAZM, "Can't open file %s",
			pm->filename);
		    fd2 = stdout;
		}
		else {
				/* print the CAzM header */
		    if (!gp->p_nutmeg && !gp->p_csdf)
		    if(date != NULL) 
			fprintf(fd2,"* CAzM Simulation\t%s\t%s\n",
				date, gp->p_circuitfile);
		    else
			fprintf(fd2,"* CAzM Simulation\t\t\t\t%s\n",
				gp->p_circuitfile);
		}
		pm->fd = fd2;
	    }
	    if (gp->p_nutmeg) {
		nutmeg_setup(pm);
	    } else {
		pm->nuthead = NULL;
	    }
	    if (gp->p_csdf) {
		csdf_setup(pm);
	    } else {
		pm->csdfhead = NULL;
	    }
	}

					/* Open AC STAT files */
	for (acm = gp->p_acmodel; acm != NULL; acm=acm->next) {
	    if (strcmp(acm->filename, NONAME) == 0 && !gp->p_nutmeg && !gp->p_csdf) 
		acm->fd = fd;
	    else if (strcmp(acm->filename, NONAME) == 0 && gp->p_nutmeg)
		acm->fd = stdout;
	    else if (strcmp(acm->filename, NONAME) == 0 && gp->p_csdf)
		acm->fd = stdout;
	    else {

			/* Check for open plot files with same name */
		for (pm = gp->p_plot; pm != NULL;
		    pm = pm->next) {

		    if (strcmp(acm->filename,pm->filename) == 0) {
			acm->fd = pm->fd;
			break;
		    }
		}
			/* If file has not been opened, open it */
		if( acm->fd == NULL) {
		    if ((fd3 = fopen(acm->filename,"w")) == NULL) {
			sim_error(S_WARNING, S_CAZM, "Can't open file %s",
			    acm->filename);
			fd3 = stdout;
		    }
		    else {
				    /* print the CAzM header */
			if(date != NULL) 
			    fprintf(fd3,"* CAzM Simulation\t%s\t%s\n",
				    date, gp->p_circuitfile);
			else
			    fprintf(fd3,"* CAzM Simulation\t\t\t\t%s\n",
				    gp->p_circuitfile);
		    }
		    acm->fd = fd3;
		}
	    }
	}
}
