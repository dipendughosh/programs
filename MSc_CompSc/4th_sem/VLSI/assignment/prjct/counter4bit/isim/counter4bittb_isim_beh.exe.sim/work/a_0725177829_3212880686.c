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
static const char *ng0 = "D:/Programs/Program/Programs/MSc_CompSc/4th_sem/VLSI/assignment/prjct/counter4bit/counter4bitvhd.vhd";
extern char *IEEE_P_3620187407;

char *ieee_p_3620187407_sub_436279890_3620187407(char *, char *, char *, char *, int );
char *ieee_p_3620187407_sub_436351764_3620187407(char *, char *, char *, char *, int );


static void work_a_0725177829_3212880686_p_0(char *t0)
{
    char t16[16];
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    unsigned char t11;
    unsigned char t12;
    unsigned char t13;
    unsigned char t14;
    char *t15;
    char *t17;

LAB0:    xsi_set_current_line(48, ng0);
    t1 = (t0 + 868U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 660U);
    t4 = xsi_signal_has_event(t1);
    if (t4 == 1)
        goto LAB7;

LAB8:    t3 = (unsigned char)0;

LAB9:    if (t3 != 0)
        goto LAB5;

LAB6:
LAB3:    t1 = (t0 + 2144);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(49, ng0);
    t1 = (t0 + 4316);
    t6 = (t0 + 2196);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 40U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 4U);
    xsi_driver_first_trans_fast(t6);
    goto LAB3;

LAB5:    xsi_set_current_line(51, ng0);
    t2 = (t0 + 776U);
    t6 = *((char **)t2);
    t13 = *((unsigned char *)t6);
    t14 = (t13 == (unsigned char)3);
    if (t14 != 0)
        goto LAB10;

LAB12:    t1 = (t0 + 776U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t11 = (t4 == (unsigned char)2);
    if (t11 == 1)
        goto LAB15;

LAB16:    t3 = (unsigned char)0;

LAB17:    if (t3 != 0)
        goto LAB13;

LAB14:    t1 = (t0 + 776U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t11 = (t4 == (unsigned char)2);
    if (t11 == 1)
        goto LAB20;

LAB21:    t3 = (unsigned char)0;

LAB22:    if (t3 != 0)
        goto LAB18;

LAB19:
LAB11:    goto LAB3;

LAB7:    t2 = (t0 + 684U);
    t5 = *((char **)t2);
    t11 = *((unsigned char *)t5);
    t12 = (t11 == (unsigned char)3);
    t3 = t12;
    goto LAB9;

LAB10:    xsi_set_current_line(52, ng0);
    t2 = (t0 + 592U);
    t7 = *((char **)t2);
    t2 = (t0 + 2196);
    t8 = (t2 + 32U);
    t9 = *((char **)t8);
    t10 = (t9 + 40U);
    t15 = *((char **)t10);
    memcpy(t15, t7, 4U);
    xsi_driver_first_trans_fast(t2);
    goto LAB11;

LAB13:    xsi_set_current_line(54, ng0);
    t1 = (t0 + 1144U);
    t6 = *((char **)t1);
    t1 = (t0 + 4280U);
    t7 = ieee_p_3620187407_sub_436279890_3620187407(IEEE_P_3620187407, t16, t6, t1, 1);
    t8 = (t0 + 2196);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    t15 = (t10 + 40U);
    t17 = *((char **)t15);
    memcpy(t17, t7, 4U);
    xsi_driver_first_trans_fast(t8);
    goto LAB11;

LAB15:    t1 = (t0 + 960U);
    t5 = *((char **)t1);
    t12 = *((unsigned char *)t5);
    t13 = (t12 == (unsigned char)2);
    t3 = t13;
    goto LAB17;

LAB18:    xsi_set_current_line(56, ng0);
    t1 = (t0 + 1144U);
    t6 = *((char **)t1);
    t1 = (t0 + 4280U);
    t7 = ieee_p_3620187407_sub_436351764_3620187407(IEEE_P_3620187407, t16, t6, t1, 1);
    t8 = (t0 + 2196);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    t15 = (t10 + 40U);
    t17 = *((char **)t15);
    memcpy(t17, t7, 4U);
    xsi_driver_first_trans_fast(t8);
    goto LAB11;

LAB20:    t1 = (t0 + 960U);
    t5 = *((char **)t1);
    t12 = *((unsigned char *)t5);
    t13 = (t12 == (unsigned char)3);
    t3 = t13;
    goto LAB22;

}

static void work_a_0725177829_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(60, ng0);

LAB3:    t1 = (t0 + 1144U);
    t2 = *((char **)t1);
    t1 = (t0 + 2232);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 40U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 4U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 2152);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_0725177829_3212880686_init()
{
	static char *pe[] = {(void *)work_a_0725177829_3212880686_p_0,(void *)work_a_0725177829_3212880686_p_1};
	xsi_register_didat("work_a_0725177829_3212880686", "isim/counter4bittb_isim_beh.exe.sim/work/a_0725177829_3212880686.didat");
	xsi_register_executes(pe);
}
