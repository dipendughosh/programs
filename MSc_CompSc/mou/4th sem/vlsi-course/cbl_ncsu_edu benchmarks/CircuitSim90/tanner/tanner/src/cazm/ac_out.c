
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
                    	Gary Nifong - MCNC
                    	Freda Locklear - Duke University
                    	Donald Erdman - Duke University
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
#include <math.h>
#include "Hmain.h"
#include "sim.h"
#include "Hcmd.h"
#include "mod.h"
#include "sp.h"
#include "spcmd.h"

ac_printheader(gp)
struct param_s *gp;
{
	struct plot_s *p;
	struct main_plot_s *pm;
	FILE *fd;        			/* output file pointer */
	int cnt;
	int decimal;


	for (pm = gp->p_plot; pm != NULL; pm = pm->next) {
	    fd = pm->fd;
	    cnt = 0;

	    if(!(pm->mode & AC_PLOT))
		continue;

            if (pm->nuthead != NULL) {
                pm->nuthead->name[cnt] = (char *) sim_alloc(10, S_CAZM);
                strcpy(pm->nuthead->name[cnt],"Frequency");
                pm->nuthead->type[cnt] = -1;
                cnt++;
            } else if (pm->csdfhead != NULL) {
                pm->csdfhead->name[cnt] = (char *) sim_alloc(10, S_CAZM);
                strcpy(pm->csdfhead->name[cnt],"Frequency");
                pm->csdfhead->type[cnt] = -1;
                cnt++;
            } else {
  		fprintf(fd, "\nAC ANALYSIS");            
		fprintf(fd,"\n  Frequency");
	    }

	    if(pm->plot_n == NULL)
		    continue;

	decimal = gp->p_decimal;
        
			/* loop through plotlist to print heading */
	if (!gp->p_csdf) 
	  for (p=pm->plot_n; p != NULL; p = p->p_next, cnt++) {
	    if (p->p_printype == SPCMD_PHASE_VPLOT) 
		vheader(p, fd, "vp", cnt, pm->nuthead, decimal);
	    else if (p->p_printype == SPCMD_MAG_VPLOT)
		vheader(p, fd, "vm", cnt, pm->nuthead, decimal);
	    else if (p->p_printype == SPCMD_IMAG_VPLOT)
		vheader(p, fd, "vi", cnt, pm->nuthead, decimal);
	    else if (p->p_printype == SPCMD_REAL_VPLOT)
		vheader(p, fd, "vr", cnt, pm->nuthead, decimal);
	    else if (p->p_printype == SPCMD_DB_VPLOT)
		vheader(p, fd, "vdb", cnt, pm->nuthead, decimal);
	    else if (p->p_printype == SPCMD_PHASE_CPLOT)
		iheader(p, fd, "ip", cnt, pm->nuthead, FALSE, decimal);
	    else if (p->p_printype == SPCMD_MAG_CPLOT)
		iheader(p, fd, "im", cnt, pm->nuthead, FALSE, decimal);
	    else if (p->p_printype == SPCMD_IMAG_CPLOT)
		iheader(p, fd, "ii", cnt, pm->nuthead, FALSE, decimal);
	    else if (p->p_printype == SPCMD_REAL_CPLOT)
		iheader(p, fd, "ir", cnt, pm->nuthead, FALSE, decimal);
	    else if (p->p_printype == SPCMD_DB_CPLOT)
		iheader(p, fd, "idb", cnt, pm->nuthead, FALSE, decimal);
	    else if (p->p_printype == SPICE_PHASE_CPLOT)
		iheader(p, fd, "ip", cnt, pm->nuthead, TRUE, decimal);
	    else if (p->p_printype == SPICE_MAG_CPLOT)
		iheader(p, fd, "im", cnt, pm->nuthead, TRUE, decimal);
	    else if (p->p_printype == SPICE_IMAG_CPLOT)
		iheader(p, fd, "ii", cnt, pm->nuthead, TRUE, decimal);
	    else if (p->p_printype == SPICE_REAL_CPLOT)
		iheader(p, fd, "ir", cnt, pm->nuthead, TRUE, decimal);
	    else if (p->p_printype == SPICE_DB_CPLOT)
		iheader(p, fd, "idb", cnt, pm->nuthead, TRUE, decimal);

	}
        if ((pm->nuthead == NULL) && (pm->csdfhead == NULL))
	    fprintf(fd,"\n");
	else if (pm->nuthead != NULL)
	    nutmeg_plot_header(pm->nuthead, gp);
	else
	    csdf_plot_header(gp, pm->csdfhead, AC);
        }
}

vheader(p, fd, type, cnt, nuthead, decimal)
struct plot_s *p;
FILE *fd;
char *type; 
int cnt;
struct nutlst_s *nuthead;
int decimal;
{
	char temp[128];
	char strformat[128];
	int len;
	int fixed;

	if(p->p_node2 == NULL) {
	    sprintf(temp,"%s(%s)", type, p->p_node1);
	} else {
	    sprintf(temp,"%s(%s,%s)", type, p->p_node1, p->p_node2);
	}
	len = strlen(temp);
	temp[len] = '\0';

	fixed = len;
	if(decimal + 7 > fixed)
	    fixed = 7 + decimal;

		/* Set the string and floating point format */
	sprintf(strformat," %%%d.%ds\0", fixed, fixed);
	sprintf(p->p_format," %%%d.%de\0", fixed, decimal);

        if (nuthead != NULL) {
            nuthead->name[cnt] = (char *) sim_alloc(len+2, S_CAZM);
	    if(p->p_node2 == NULL)
                sprintf(nuthead->name[cnt],"%s_%s\0", type, p->p_node1);
	    else
                sprintf(nuthead->name[cnt],"%s_%s_%s\0", type, p->p_node1, p->p_node2);
            nuthead->type[cnt] = VOLT;
	    strcpy(p->p_format,"\n\t%20.15e");
        } else
	    fprintf(fd, strformat, temp);

}

iheader(p, fd, type, cnt, nuthead, flag, decimal)
struct plot_s *p;
FILE *fd;
char *type; 
int cnt;
struct nutlst_s *nuthead;
int flag;
int decimal;
{
	char temp[128];
	char strformat[128];
	int len;
	int fixed;

	if(flag == TRUE)
	    sprintf(temp,"%s(%s)", type, p->p_devicename);
	else
	    sprintf(temp,"%s(%s,%s)", type, p->p_devicename, p->p_node1);

	len = strlen(temp);
	temp[len] = '\0';

	fixed = len;
	if(decimal + 7 > fixed)
	    fixed = 7 + decimal;

		/* Set the string and floating point format */
	sprintf(strformat," %%%d.%ds\0", fixed, fixed);
	sprintf(p->p_format," %%%d.%de\0", fixed, decimal);

        if (nuthead != NULL) {
            nuthead->name[cnt] = (char *) sim_alloc(len+2, S_CAZM);
            sprintf(nuthead->name[cnt],"%s_%s_%s\0",
		type, p->p_devicename, p->p_node1);
            nuthead->type[cnt] = CURRENT;
	    strcpy(p->p_format,"\n\t%20.15e");
        } else {
	    fprintf(fd, strformat, temp);
	}

}


/*******************************************************************
*
*        AC_OUTPUT
*
*   Parameters- amp,deg,fstart,fstop
*               nd,num_ind,k
*  
*   Returns-    AC analysis output listing
*               of requested nodes
*
********************************************************************/ 

ac_output(gp, val_double, val_int, z, ia, fq2, freq)
struct param_s *gp;
Val_Double *val_double;			/* double array passing structure */
Val_Int *val_int;		
struct complex *z;
struct complex *ia;
struct complex *fq2;
double freq;				/* frequency */
{

	struct plot_s *p;
	struct main_plot_s *pm;
	struct polar cmplx2polar();
	struct complex cmplxmult();
	struct complex cmplxminus();
	struct complex ac_voltage();
	struct complex ac_current();
	struct complex cmplxclean();
	struct complex cx;
	struct polar pol;
	double db;
	int num_ind;				/* independent nodes */
	int num_nodes;				/* dependent nodes */
	int i,j;				/* node numbers */
	FILE *fd;        			/* output file pointer */

        i=0;
	num_ind = gp->p_num_ind;
	num_nodes = gp->p_num_nodes;


	for (pm = gp->p_plot; pm != NULL; pm = pm->next) {
	    fd = pm->fd;

	    if(!(pm->mode & AC_PLOT))
		continue;
			    /* print a line frequency and values */
	    if (pm->nuthead != NULL) {
	        fprintf(fd,"\n%d\t\t%20.15e",pm->nuthead->cnt, freq);
		(pm->nuthead->cnt)++;
	    } else if (pm->csdfhead != NULL) {
		fprintf(fd,"#C %g %d\n", freq, pm->csdfhead->no_var);
	    } else
	        fprintf(fd,"%10.5e", freq);

	    if(pm->plot_n == NULL)
		    continue;

			/* loop through plotlist to print output */
	    for (p=pm->plot_n; p !=NULL; p = p->p_next){
		switch(p->p_printype) {
		    case SPCMD_PHASE_VPLOT:
		    case SPCMD_MAG_VPLOT:
		    case SPCMD_IMAG_VPLOT:
		    case SPCMD_REAL_VPLOT:
		    case SPCMD_DB_VPLOT:

				/* Compute the AC voltage */
			cx = ac_voltage(gp, p, z, freq);

                               /* Get rid of garbage numbers */
                        cx = cmplxclean(cx);

				    /* Convert complex to polar */
			pol = cmplx2polar(cx,val_double->pi);
			if (pol.mag == 0.0)
			    db = -1.0e-33;
			else 
			    db = 20.0*log10(fabs(pol.mag));

			if (p->p_printype == SPCMD_PHASE_VPLOT)
			    if (gp->p_csdf) {
			       i++;
			       fprintf(fd, "%g:%x ", pol.deg, i);
			    } else
			       fprintf(fd,p->p_format, pol.deg);
			else if (p->p_printype == SPCMD_MAG_VPLOT)
			    if (gp->p_csdf) {
			       i++;
			       fprintf(fd, "%g:%x ", pol.mag, i);
			    } else
			       fprintf(fd,p->p_format, pol.mag);
			else if (p->p_printype == SPCMD_IMAG_VPLOT)
			    if (gp->p_csdf) {
			       i++;
			       fprintf(fd, "%g:%x ", cx.imag, i);
			    } else
			       fprintf(fd,p->p_format, cx.imag);
			else if (p->p_printype == SPCMD_REAL_VPLOT)
			    if (gp->p_csdf) {
			       i++;
			       fprintf(fd, "%g:%x ", cx.real, i);
			    } else
			       fprintf(fd,p->p_format, cx.real);
				/* print decibel output */
			else  if (p->p_printype == SPCMD_DB_VPLOT)
			    if (gp->p_csdf) {
			       i++;
			       fprintf(fd, "%g:%x ", db, i);
			    } else
			       fprintf(fd,p->p_format, db);
			break;
		    case SPCMD_PHASE_CPLOT:
		    case SPCMD_MAG_CPLOT:
		    case SPCMD_IMAG_CPLOT:
		    case SPCMD_REAL_CPLOT:
		    case SPCMD_DB_CPLOT:
		    case SPICE_PHASE_CPLOT:
		    case SPICE_MAG_CPLOT:
		    case SPICE_IMAG_CPLOT:
		    case SPICE_REAL_CPLOT:
		    case SPICE_DB_CPLOT:

				/* Compute the AC current */
			cx = ac_current(gp, p, val_double, val_int,
				z, ia, fq2, freq);

                               /* Get rid of garbage numbers */
                        cx = cmplxclean(cx);
 
			pol = cmplx2polar(cx,val_double->pi);

			if (pol.mag == 0.0)
			    db = -1.0e-33;
			else 
			    db = 20.0*log10(fabs(pol.mag));

			if (p->p_printype == SPCMD_PHASE_CPLOT ||
				p->p_printype == SPICE_PHASE_CPLOT)
			    if (gp->p_csdf) {
			       i++;
			       fprintf(fd, "%g:%x ", pol.deg, i);
			    } else
			       fprintf(fd,p->p_format, pol.deg);
			else if (p->p_printype == SPCMD_MAG_CPLOT ||
				p->p_printype == SPICE_MAG_CPLOT)
			    if (gp->p_csdf) {
			       i++;
			       fprintf(fd, "%g:%x ", pol.mag, i);
			    } else
			       fprintf(fd,p->p_format, pol.mag);
			else if (p->p_printype == SPCMD_IMAG_CPLOT ||
				p->p_printype == SPICE_IMAG_CPLOT)
			    if (gp->p_csdf) {
			       i++;
			       fprintf(fd, "%g:%x ", cx, i);
			    } else
			       fprintf(fd,p->p_format, cx.imag);
			else if (p->p_printype == SPCMD_REAL_CPLOT ||
				p->p_printype == SPICE_REAL_CPLOT)
			    if (gp->p_csdf) {
			       i++;
			       fprintf(fd, "%g:%x ", cx.real, i);
			    } else
			       fprintf(fd,p->p_format, cx.real);
				/* print decibel output */
			else  if (p->p_printype == SPCMD_DB_CPLOT ||
				p->p_printype == SPICE_DB_CPLOT)
			    if (gp->p_csdf) {
			       i++;
			       fprintf(fd, "%g:%x ", db, i);
			    } else
			       fprintf(fd,p->p_format,db);
			break;

		    default:
			break;
		}
	    }
	    if (pm->nuthead == NULL) 
	        fprintf(fd,"\n");   		
	}

}


struct complex 
ac_voltage(gp, p, z, freq)
struct param_s *gp;
struct plot_s *p;
struct complex *z;
double freq;				/* frequency */
{
	struct complex cx1;
	struct complex cx2;
	struct complex cx;
	int i,j;				/* node numbers */
 
		    /* Set the complex number from the
		     * the solution vector or input vector.
		     */
	if(p->p_node2 == NULL) {
		    /* Get the node number then index the
		     * the array to set complex number.
		     */
	    i = p->p_nodes[0];
		
		    /* Get computed value */
	    if ( i < gp->p_num_nodes - NUM_GNDS) {
	        cx.real = z[i].real;
	        cx.imag = z[i].imag;
	    } else {
	        cx.real = 0;
	        cx.imag = 0;
	    }
	}
	else if(p->p_node2 != NULL) {

	    i = p->p_nodes[0];
	    j = p->p_nodes[1];

	    if ( i < gp->p_num_nodes - NUM_GNDS) {
	        cx1.real = z[i].real;
	        cx1.imag = z[i].imag;
	    } else {
	        cx1.real = 0.0;
	        cx1.imag = 0.0;
	    }
	    if ( j < gp->p_num_nodes - NUM_GNDS) {
	        cx2.real = z[j].real;
	        cx2.imag = z[j].imag;
	    } else {
	        cx2.real = 0;
	        cx2.imag = 0;
	    }

	    cx.real = cx1.real - cx2.real;
	    cx.imag = cx1.imag - cx2.imag;
	}
	return(cx);

}

struct complex 
ac_current(gp, p, val_double, val_int, z, ia, fq2, freq)
struct param_s *gp;
struct plot_s *p;
Val_Double *val_double;			/* double array passing structure */
Val_Int *val_int;		
struct complex *z;
struct complex *ia;
struct complex *fq2;
double freq;				/* frequency */
{

	struct complex rwt[MAXTERMINALS];
	struct complex cmplxvectmult();
	struct complex cx;
	double sub[4][4];		/* sub matrix for each device */
	double subq[4][4];		/* sub matrix for Qs of a device */
	struct circuit_s *cp;
	struct boundary_s *iv;
	struct other_wavef_s *ov;
	struct volt_volt_s *vv;
	double *ug;
	double coef;
	double wt;
	int flag;
	int num_ind;				/* independent nodes */
	int num_nodes;				/* total nodes */
	int i,j;				/* node numbers */
	int k;
	struct complex v[MAXTERMINALS];

	wt = 2.0 * val_double->pi * freq;

	if (p->p_dev != NULL) {

	    cp = p->p_dev;
	    ug = val_double->ug;
	    num_ind = gp->p_num_ind;
	    flag = AC;
	    coef = 1;

		  /* Build the voltage vector for the device */
	    for(i = 0; i < cp->c_numnodes; i++) { 
		j = cp->c_nodes[i];

	    	if ( j < gp->p_num_nodes - NUM_GNDS) {
		    v[i].real = z[j].real;
		    v[i].imag = z[j].imag;
		} else {
		    v[i].real = 0.0;
		    v[i].imag = 0.0;
		}
	    }
			/* Initialize the complex current */
	    cx.real = 0.0;
	    cx.imag = 0.0;

	    switch(cp->c_type) {
		case DIODE: 
		    diode_assem(gp, cp, cp->c_modelF, cp->c_modelQ, ug, sub,
			subq, flag, coef);

		    i = p->p_termnum;
		    rwt[0].real =  sub[i][0]; 
		    rwt[0].imag =  wt * subq[i][0]; 
		    rwt[1].real =  sub[i][1]; 
		    rwt[1].imag =  wt * subq[i][1]; 

		    break;

		case JFET: 
		    jfet_assem(gp, cp, cp->c_modelF, cp->c_modelQ, ug, sub,
			subq, flag, coef);

		    i = p->p_termnum;
		    rwt[0].real =  sub[i][0]; 
		    rwt[0].imag =  wt * subq[i][0]; 
		    rwt[1].real =  sub[i][1]; 
		    rwt[1].imag =  wt * subq[i][1]; 
		    rwt[2].real =  sub[i][2]; 
		    rwt[2].imag =  wt * subq[i][2]; 

		    break;

		case BIPOLAR: 
		    bjt_assem(gp, cp, cp->c_modelF, cp->c_modelQ, ug, sub,
			subq, flag, coef);

		    i = p->p_termnum;
		    rwt[0].real =  sub[i][0]; 
		    rwt[0].imag =  wt * subq[i][0]; 
		    rwt[1].real =  sub[i][1]; 
		    rwt[1].imag =  wt * subq[i][1]; 
		    rwt[2].real =  sub[i][2]; 
		    rwt[2].imag =  wt * subq[i][2]; 

		    break;

		case MOSFET: 
		    mosfet_assem(gp, cp, cp->c_modelF, cp->c_modelQ, ug, sub,
			subq, flag, coef);

		    i = p->p_termnum;

		    rwt[0].real =  sub[i][0]; 
		    rwt[0].imag =  wt * subq[i][0]; 
		    rwt[1].real =  sub[i][1]; 
		    rwt[1].imag =  wt * subq[i][1]; 
		    rwt[2].real =  sub[i][2]; 
		    rwt[2].imag =  wt * subq[i][2]; 
		    rwt[3].real =  sub[i][3]; 
		    rwt[3].imag =  wt * subq[i][3]; 

		    break;

		case TRANSMISSION: 
		    transmission_assem(gp, cp, val_double, sub,
			subq, AC, freq);
		    i = p->p_termnum;

		    rwt[0].real =  0.0; 
		    rwt[0].imag =  subq[i][0]; 
		    rwt[1].real =  0.0; 
		    rwt[1].imag =  subq[i][1]; 
		    rwt[2].real =  0.0; 
		    rwt[2].imag =  subq[i][2]; 
		    rwt[3].real =  0.0; 
		    rwt[3].imag =  subq[i][3]; 

		    break;

		case RESISTOR: 

		    i = p->p_termnum;

		    if(i == 0) {
			rwt[0].real = cp->c_val;
			rwt[0].imag =  0.0; 
			rwt[1].real = -cp->c_val;
			rwt[1].imag =  0.0; 
		    }
		    else {
			rwt[0].real = -cp->c_val;
			rwt[0].imag =  0.0; 
			rwt[1].real = cp->c_val;
			rwt[1].imag =  0.0; 
		    }
		    break;

		case CAPACITOR: 
		    i = p->p_termnum;

		    if(i == 0) {
			rwt[0].real =  0.0; 
			rwt[0].imag = wt * cp->c_val;
			rwt[1].real =
			rwt[1].imag = wt * -cp->c_val;
		    }
		    else {
			rwt[0].real =  0.0; 
			rwt[0].imag = wt * -cp->c_val;
			rwt[1].real =  0.0; 
			rwt[1].imag = wt * cp->c_val;
		    }
		    break;

		case VOLT_CURR: 
		case IND_VOLT_CURR: 
		    i = p->p_termnum;

		    if(i == 0) {
			rwt[0].real =  0.0; 
			rwt[0].imag =  0.0; 
			rwt[1].real =  0.0; 
			rwt[1].imag =  0.0; 
			rwt[2].real = -cp->c_val;
			rwt[2].imag =  0.0; 
			rwt[3].real = cp->c_val;
			rwt[3].imag =  0.0; 
		    }
		    else {
			rwt[0].real =  0.0; 
			rwt[0].imag =  0.0; 
			rwt[1].real =  0.0; 
			rwt[1].imag =  0.0; 
			rwt[2].real = cp->c_val;
			rwt[2].imag =  0.0; 
			rwt[3].real = -cp->c_val;
			rwt[3].imag =  0.0; 
		    }

		    break;

		default:
		break;
	    }

	    cx = cmplxvectmult(rwt, v, cp->c_numnodes);
	    return(cx);
	}
			/* Voltage and current sources */
	else {

	    if (p->p_iv != NULL) {
		switch(p->p_caltype) {
		    case CURRENT_PLOT: 
			iv = p->p_iv;
			if (iv != NULL) {
			    if (p->p_nodes[0] == iv->b_node1) {
				if (iv->b_node1 >= val_int->jasize) {
				    cx.real = -ia[iv->b_node2].real;
				    cx.imag = -ia[iv->b_node2].imag;
				} else {
				    cx.real = ia[iv->b_node1].real;
				    cx.imag = ia[iv->b_node1].imag;
				}
			    }
			    else {
				if (iv->b_node1 >= val_int->jasize) {
				    cx.real = ia[iv->b_node2].real;
				    cx.imag = ia[iv->b_node2].imag;
				} else {
				    cx.real = -ia[iv->b_node1].real;
				    cx.imag = -ia[iv->b_node1].imag;
				}
			    }
			}
			break;
		    case VOLT_PLOT: 
			iv = p->p_iv;
			if (iv != NULL) {
			    if (p->p_nodes[0] == iv->b_node1) {
				cx.real = -z[iv->b_row].real;
				cx.imag = -z[iv->b_row].imag;
			    }
			    else {
				cx.real = z[iv->b_row].real;
				cx.imag = z[iv->b_row].imag;
			    }
			}
			break;
		    case O_VOLT_PLOT: 
			ov = (struct other_wavef_s *) p->p_iv;
			if (ov != NULL) {
			    if (p->p_nodes[0] == ov->o_node1) {
				cx.real = -z[ov->o_row].real;
				cx.imag = -z[ov->o_row].imag;
			    }
			    else {
				cx.real = z[ov->o_row].real;
				cx.imag = z[ov->o_row].imag;
			    }
			}
			break;
		    case O_CURRENT_PLOT: 
			ov = (struct other_wavef_s *) p->p_iv;
			if (ov != NULL) {
			    if (p->p_nodes[0] == ov->o_node1) {
				cx.real = -ia[ov->o_node1].real;
				cx.imag = -ia[ov->o_node1].imag;
			    }
			    else {
				cx.real = ia[ov->o_node1].real;
				cx.imag = ia[ov->o_node1].imag;
			    }
			}
			break;
		    case VV_PLOT: 
			vv = (struct volt_volt_s *) p->p_iv;
			if (vv != NULL) {
			    if (p->p_nodes[0] == vv->v_node1) {
				cx.real = -z[vv->v_row].real;
				cx.imag = -z[vv->v_row].imag;
			    }
			    else {
				cx.real = z[vv->v_row].real;
				cx.imag = z[vv->v_row].imag;
			    }
			}
			break;
		    default:
			;
			    /* End of switch */
		    return(cx);
		}
	    }
	}
	return(cx);
}


cmplxmatrixmult(fq2, v, cout, ja, num)
struct complex *fq2;
struct complex *v;
struct complex *cout;
int *ja;
int num;
{
	struct complex cx;
	struct complex cmplxadd();
	struct complex cmplxmult();
	int i, j, k, h;

		/*  multiply the diagonals of a and subtract b */
	for (i = 0; i < num; i++)
	    cout[i] = cmplxmult(fq2[i], v[i]);

		/*  now multiply off diagonals */
	h = ja[num] - ja[0];
	for (i = 0; i < num; i++) {
	    for (j = ja[i]-1; j < ja[i+1]-1; j++) {
		k = ja[j] - 1;
		cx = cmplxmult(fq2[j],v[k]);
             	cout[i] = cmplxadd(cout[i],cx);

		cx = cmplxmult(fq2[j + h] , v[i]);
		cout[k] = cmplxadd(cout[k] , cx); 
	    }
	}
}
