/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x36e8438f */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "D:/Programs/Program/Programs/MSc_CompSc/4th_sem/VLSI/assignment/prjct/tflipflop/tflipflopvhd.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_1690584930_2592010699(char *, unsigned char );


static void work_a_0057312127_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    unsigned char t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    unsigned char t13;

LAB0:    t1 = (t0 + 1712U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(47, ng0);

LAB6:    t2 = (t0 + 2196);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    t9 = (t0 + 2196);
    *((int *)t9) = 0;
    xsi_set_current_line(48, ng0);
    t2 = (t0 + 776U);
    t4 = *((char **)t2);
    t3 = *((unsigned char *)t4);
    t6 = (t3 == (unsigned char)3);
    if (t6 != 0)
        goto LAB11;

LAB13:    t2 = (t0 + 592U);
    t4 = *((char **)t2);
    t3 = *((unsigned char *)t4);
    t6 = (t3 == (unsigned char)3);
    if (t6 != 0)
        goto LAB14;

LAB15:
LAB12:    xsi_set_current_line(51, ng0);
    t2 = (t0 + 1052U);
    t4 = *((char **)t2);
    t6 = *((unsigned char *)t4);
    t7 = (t6 != (unsigned char)2);
    if (t7 == 1)
        goto LAB19;

LAB20:    t3 = (unsigned char)0;

LAB21:    if (t3 != 0)
        goto LAB16;

LAB18:
LAB17:    goto LAB2;

LAB5:    t4 = (t0 + 684U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    if (t7 == 1)
        goto LAB8;

LAB9:    t3 = (unsigned char)0;

LAB10:    if (t3 == 1)
        goto LAB4;
    else
        goto LAB6;

LAB7:    goto LAB5;

LAB8:    t4 = (t0 + 660U);
    t8 = xsi_signal_has_event(t4);
    t3 = t8;
    goto LAB10;

LAB11:    xsi_set_current_line(48, ng0);
    t2 = (t0 + 2256);
    t5 = (t2 + 32U);
    t9 = *((char **)t5);
    t10 = (t9 + 40U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    goto LAB12;

LAB14:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 1052U);
    t5 = *((char **)t2);
    t7 = *((unsigned char *)t5);
    t8 = ieee_p_2592010699_sub_1690584930_2592010699(IEEE_P_2592010699, t7);
    t2 = (t0 + 2256);
    t9 = (t2 + 32U);
    t10 = *((char **)t9);
    t11 = (t10 + 40U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = t8;
    xsi_driver_first_trans_fast(t2);
    goto LAB12;

LAB16:    xsi_set_current_line(51, ng0);
    t2 = (t0 + 2256);
    t9 = (t2 + 32U);
    t10 = *((char **)t9);
    t11 = (t10 + 40U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    goto LAB17;

LAB19:    t2 = (t0 + 1052U);
    t5 = *((char **)t2);
    t8 = *((unsigned char *)t5);
    t13 = (t8 != (unsigned char)3);
    t3 = t13;
    goto LAB21;

}

static void work_a_0057312127_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(54, ng0);

LAB3:    t1 = (t0 + 1052U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 2292);
    t4 = (t1 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 40U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t8 = (t0 + 2204);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_0057312127_3212880686_p_2(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;

LAB0:    xsi_set_current_line(55, ng0);

LAB3:    t1 = (t0 + 1052U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = ieee_p_2592010699_sub_1690584930_2592010699(IEEE_P_2592010699, t3);
    t1 = (t0 + 2328);
    t5 = (t1 + 32U);
    t6 = *((char **)t5);
    t7 = (t6 + 40U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = t4;
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t9 = (t0 + 2212);
    *((int *)t9) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_0057312127_3212880686_init()
{
	static char *pe[] = {(void *)work_a_0057312127_3212880686_p_0,(void *)work_a_0057312127_3212880686_p_1,(void *)work_a_0057312127_3212880686_p_2};
	xsi_register_didat("work_a_0057312127_3212880686", "isim/tflipfloptb_isim_beh.exe.sim/work/a_0057312127_3212880686.didat");
	xsi_register_executes(pe);
}
