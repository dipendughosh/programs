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

/* This file is designed for use with ISim build 0xc4ca3437 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "E:/Program/Programs/MSc_CompSc/4th_sem/VLSO/workspace/project_1/project_1.srcs/sources_1/imports/workspace/mux.vhd";



static void work_a_1323274903_3212880686_p_0(char *t0)
{
    unsigned char t1;
    char *t2;
    char *t3;
    unsigned char t4;
    unsigned char t5;
    char *t6;
    unsigned char t7;
    unsigned char t8;
    char *t9;
    unsigned char t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    unsigned char t15;
    char *t16;
    char *t17;
    unsigned char t18;
    unsigned char t19;
    char *t20;
    unsigned char t21;
    unsigned char t22;
    char *t23;
    unsigned char t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    unsigned char t29;
    char *t30;
    char *t31;
    unsigned char t32;
    unsigned char t33;
    char *t34;
    unsigned char t35;
    unsigned char t36;
    char *t37;
    unsigned char t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;
    char *t43;
    char *t44;
    unsigned char t45;
    char *t46;
    char *t47;
    char *t48;
    char *t49;
    char *t50;

LAB0:    xsi_set_current_line(55, ng0);
    t2 = (t0 + 1672U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (t4 == (unsigned char)2);
    if (t5 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:    t16 = (t0 + 1672U);
    t17 = *((char **)t16);
    t18 = *((unsigned char *)t17);
    t19 = (t18 == (unsigned char)2);
    if (t19 == 1)
        goto LAB10;

LAB11:    t15 = (unsigned char)0;

LAB12:    if (t15 != 0)
        goto LAB8;

LAB9:    t30 = (t0 + 1672U);
    t31 = *((char **)t30);
    t32 = *((unsigned char *)t31);
    t33 = (t32 == (unsigned char)3);
    if (t33 == 1)
        goto LAB15;

LAB16:    t29 = (unsigned char)0;

LAB17:    if (t29 != 0)
        goto LAB13;

LAB14:
LAB18:    t43 = (t0 + 1512U);
    t44 = *((char **)t43);
    t45 = *((unsigned char *)t44);
    t43 = (t0 + 3552);
    t46 = (t43 + 56U);
    t47 = *((char **)t46);
    t48 = (t47 + 56U);
    t49 = *((char **)t48);
    *((unsigned char *)t49) = t45;
    xsi_driver_first_trans_fast_port(t43);

LAB2:    t50 = (t0 + 3472);
    *((int *)t50) = 1;

LAB1:    return;
LAB3:    t2 = (t0 + 1032U);
    t9 = *((char **)t2);
    t10 = *((unsigned char *)t9);
    t2 = (t0 + 3552);
    t11 = (t2 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = t10;
    xsi_driver_first_trans_fast_port(t2);
    goto LAB2;

LAB5:    t2 = (t0 + 1832U);
    t6 = *((char **)t2);
    t7 = *((unsigned char *)t6);
    t8 = (t7 == (unsigned char)2);
    t1 = t8;
    goto LAB7;

LAB8:    t16 = (t0 + 1192U);
    t23 = *((char **)t16);
    t24 = *((unsigned char *)t23);
    t16 = (t0 + 3552);
    t25 = (t16 + 56U);
    t26 = *((char **)t25);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    *((unsigned char *)t28) = t24;
    xsi_driver_first_trans_fast_port(t16);
    goto LAB2;

LAB10:    t16 = (t0 + 1832U);
    t20 = *((char **)t16);
    t21 = *((unsigned char *)t20);
    t22 = (t21 == (unsigned char)3);
    t15 = t22;
    goto LAB12;

LAB13:    t30 = (t0 + 1352U);
    t37 = *((char **)t30);
    t38 = *((unsigned char *)t37);
    t30 = (t0 + 3552);
    t39 = (t30 + 56U);
    t40 = *((char **)t39);
    t41 = (t40 + 56U);
    t42 = *((char **)t41);
    *((unsigned char *)t42) = t38;
    xsi_driver_first_trans_fast_port(t30);
    goto LAB2;

LAB15:    t30 = (t0 + 1832U);
    t34 = *((char **)t30);
    t35 = *((unsigned char *)t34);
    t36 = (t35 == (unsigned char)2);
    t29 = t36;
    goto LAB17;

LAB19:    goto LAB2;

}


extern void work_a_1323274903_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1323274903_3212880686_p_0};
	xsi_register_didat("work_a_1323274903_3212880686", "isim/mux.exe.sim/work/a_1323274903_3212880686.didat");
	xsi_register_executes(pe);
}
