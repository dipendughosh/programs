#*---------------------------------------------------------------------------
#
#    =========       ========        ===========    ===== =======   =======
#   ==      ===     ===     ==       ==     ===        ===     === =     ===
#  ==       ===     ===   =====      =     ===         ==       ===       ===
#  ==               =====   ===          ===           ==       ===       ===
#  ==              ===      ===         = =    =       ==       ===       ===
#   ==        =    ===      ===       ===      =       ==       ===       ===
#    =========      ======== ====    ===========    =======   =======  =======
#
#-----------------------------------------------------------------------------
#
#	            Designed and written by
#                    	Donald Erdman - Duke University
#                    	Ravi Subrahmanyan - MCNC
#                    	Gary Nifong - MCNC
#                    	Steve Kenkel - MCNC
#
#	Copyright 1989, 1990 by the Microelectronics Center of North 
#	Carolina, Don Erdman, and Don Rose.
#
#        This copy, serial #00, of MCNC proprietary software, is made  
#        available under license agreement.  Please heed all non-  
#        disclosure and internal use restrictions.  
#-----------------------------------------------------------------------------
#
# 	This is the makefile for CAzM
#
#----------------------------------------------------------------------------*


# variables that may be set by global makefile
SRCPATH		= ../..
FC		= f77 
FFLAGS		= -O
CC		= /bin/cc
CFLAGS		= -g

# options
INCLOPTS	= -I. -I${INCL} 
CCOPTS		= $(CFLAGS) $(INCLOPTS)
COPY            = /bin/cp


# libraries
BIN		= ../../bin
LIB		= ../../lib
LIBSP		= ${LIB}/libsp.a
LIBSIM    	= ${LIB}/libsim.a
LIBMOD    	= ${LIB}/libmod.a
LIBCMD    	= ${LIB}/libcmd.a

# non-default system libraries (e.g. -lm)
SYSLIBS		= -lm
LIBL		= -ll


# standard names for the source directory and its subdirectories
LOCAL	= .
OBJECTS	= $(LOCAL)/OBJECTS

# Network include  *.h files
INCL		= ${SRCPATH}/include


#############################################################################


all:	cazm 

OBJS =${OBJECTS}/assem.o ${OBJECTS}/cazm.o ${OBJECTS}/circ.o \
${OBJECTS}/comm.o ${OBJECTS}/con.o ${OBJECTS}/genfq.o ${OBJECTS}/globals.o \
${OBJECTS}/gs.o ${OBJECTS}/hash.o ${OBJECTS}/init.o ${OBJECTS}/md.o \
${OBJECTS}/mdi.o ${OBJECTS}/mdm.o ${OBJECTS}/mdp.o ${OBJECTS}/mdu.o \
${OBJECTS}/newton.o ${OBJECTS}/ntrbdf.o ${OBJECTS}/output.o ${OBJECTS}/snf.o \
${OBJECTS}/sns.o ${OBJECTS}/ssf.o ${OBJECTS}/table.o ${OBJECTS}/trans.o \
${OBJECTS}/trbdf.o ${OBJECTS}/ndev.o \
${OBJECTS}/psource.o ${OBJECTS}/pdevice.o \
${OBJECTS}/parse.o ${OBJECTS}/shash.o  \
${OBJECTS}/leech.o	${OBJECTS}/tick.o ${OBJECTS}/tape.o ${OBJECTS}/tline.o \
${OBJECTS}/csns.o	${OBJECTS}/csnf.o \
${OBJECTS}/ac.o	${OBJECTS}/ac_out.o ${OBJECTS}/ac_model.o ${OBJECTS}/plot.o \
${OBJECTS}/condn.o ${OBJECTS}/func.o ${OBJECTS}/func_user.o  \
${OBJECTS}/nutout.o ${OBJECTS}/bhash.o ${OBJECTS}/csrcs.o 

cazm:	${OBJS} ${LIBMOD} ${LIBSP} ${LIBSIM} ${LIBCMD} 
	${CC} -o cazm ${CCOPTS} ${OBJS} ${LIBSP} ${LIBCMD} ${LIBMOD} \
	${LIBSIM} -lF77 -lU77 -lI77  -lm
#	${LIBSIM} /../simon/usr/local/std/lib/libnag.a  -lF77 -lU77 -lI77  -lm 


${OBJECTS}/gs.o: gs.f
	${FC}  ${FFLAGS} -c gs.f
	mv gs.o ${OBJECTS}/gs.o

${OBJECTS}/condn.o: condn.f
	${FC}  ${FFLAGS} -c condn.f
	mv condn.o ${OBJECTS}/condn.o

${OBJECTS}/newton.o: newton.c Hmain.h Hnum.h
	${CC} ${CCOPTS} -c newton.c
	mv newton.o ${OBJECTS}/newton.o

${OBJECTS}/cazm.o: cazm.c Hmain.h Hnum.h hash.h ${INCL}/sim.h
	${CC} ${CCOPTS} -c cazm.c 
	mv cazm.o ${OBJECTS}/cazm.o

${OBJECTS}/comm.o: comm.c Hmain.h Hnum.h hash.h  ${INCL}/sim.h ${INCL}/Hcmd.h    ${INCL}/sp.h
	${CC} ${CCOPTS} -c comm.c
	mv comm.o ${OBJECTS}/comm.o

${OBJECTS}/circ.o: circ.c Hmain.h Hnum.h hash.h parse.h ${INCL}/sim.h ${INCL}/sp.h ${INCL}/Hcmd.h func.h
	${CC} ${CCOPTS} -c circ.c
	mv circ.o ${OBJECTS}/circ.o

${OBJECTS}/ndev.o: ndev.c Hmain.h Hnum.h hash.h ${INCL}/sim.h ${INCL}/sp.h ${INCL}/mod.h
	${CC} ${CCOPTS} -c ndev.c 
	mv ndev.o ${OBJECTS}/ndev.o

${OBJECTS}/psource.o: psource.c Hmain.h Hnum.h hash.h ${INCL}/sim.h ${INCL}/sp.h ${INCL}/mod.h
	${CC} ${CCOPTS} -c psource.c 
	mv psource.o ${OBJECTS}/psource.o

${OBJECTS}/pdevice.o: pdevice.c Hmain.h Hnum.h hash.h ${INCL}/sim.h ${INCL}/sp.h ${INCL}/mod.h
	${CC} ${CCOPTS} -c pdevice.c 
	mv pdevice.o ${OBJECTS}/pdevice.o

${OBJECTS}/parse.o: parse.c Hmain.h parse.h ${INCL}/sim.h 
	${CC} ${CCOPTS} -c parse.c 
	mv parse.o ${OBJECTS}/parse.o

${OBJECTS}/shash.o: shash.c Hmain.h shash.h ${INCL}/sim.h  ${INCL}/sp.h 
	${CC} ${CCOPTS} -c shash.c 
	mv shash.o ${OBJECTS}/shash.o

${OBJECTS}/trbdf.o: trbdf.c Hmain.h Hnum.h hash.h ${INCL}/sim.h ${INCL}/Hcmd.h ${INCL}/sp.h
	${CC} ${CCOPTS} -c trbdf.c
	mv trbdf.o ${OBJECTS}/trbdf.o

${OBJECTS}/ntrbdf.o: ntrbdf.c Hmain.h Hnum.h hash.h ${INCL}/sim.h ${INCL}/Hcmd.h ${INCL}/sp.h
	${CC} ${CCOPTS} -c ntrbdf.c
	mv ntrbdf.o ${OBJECTS}/ntrbdf.o

${OBJECTS}/trans.o: trans.c Hmain.h Hnum.h hash.h ${INCL}/sim.h ${INCL}/Hcmd.h
	${CC} ${CCOPTS} -c trans.c 
	mv trans.o ${OBJECTS}/trans.o

${OBJECTS}/output.o: output.c Hmain.h Hnum.h hash.h ${INCL}/sim.h ${INCL}/Hcmd.h
	${CC} ${CCOPTS} -c output.c
	mv output.o ${OBJECTS}/output.o

${OBJECTS}/genfq.o: genfq.c Hmain.h Hnum.h hash.h ${INCL}/sim.h ${INCL}/Hcmd.h ${INCL}/sp.h
	${CC} ${CCOPTS} -c genfq.c 
	mv genfq.o ${OBJECTS}/genfq.o

${OBJECTS}/assem.o: assem.c Hmain.h Hnum.h hash.h ${INCL}/sim.h ${INCL}/sp.h
	${CC} ${CCOPTS} -c assem.c
	mv assem.o ${OBJECTS}/assem.o

${OBJECTS}/hash.o: hash.c Hmain.h Hnum.h hash.h ${INCL}/sim.h ${INCL}/mod.h ${INCL}/Hcmd.h ${INCL}/sp.h func.h
	${CC} ${CCOPTS} -c hash.c 
	mv hash.o ${OBJECTS}/hash.o

${OBJECTS}/table.o: table.c Hmain.h Hnum.h hash.h ${INCL}/sim.h ${INCL}/sp.h ${INCL}/mod.h
	${CC} ${CCOPTS} -c table.c 
	mv table.o ${OBJECTS}/table.o

${OBJECTS}/globals.o: globals.c Hmain.h Hnum.h hash.h ${INCL}/sim.h
	${CC} ${CCOPTS} -c globals.c
	mv globals.o ${OBJECTS}/globals.o

${OBJECTS}/init.o: init.c Hmain.h Hnum.h hash.h ${INCL}/sim.h ${INCL}/sp.h
	${CC} ${CCOPTS} -c init.c 
	mv init.o ${OBJECTS}/init.o

${OBJECTS}/con.o: con.c Hmain.h Hnum.h hash.h ${INCL}/sim.h ${INCL}/Hcmd.h ${INCL}/sp.h
	${CC} ${CCOPTS} -c con.c 
	mv con.o ${OBJECTS}/con.o

${OBJECTS}/tick.o: tick.c Hmain.h Hnum.h hash.h ${INCL}/sim.h ${INCL}/sp.h ${INCL}/mod.h
	${CC} ${CCOPTS} -c tick.c 
	mv tick.o ${OBJECTS}/tick.o

${OBJECTS}/tape.o: tape.c Hmain.h Hnum.h hash.h ${INCL}/sim.h ${INCL}/sp.h ${INCL}/mod.h
	${CC} ${CCOPTS} -c tape.c 
	mv tape.o ${OBJECTS}/tape.o

${OBJECTS}/tline.o: tline.c Hmain.h Hnum.h hash.h ${INCL}/sim.h ${INCL}/sp.h ${INCL}/mod.h
	${CC} ${CCOPTS} -c tline.c 
	mv tline.o ${OBJECTS}/tline.o

${OBJECTS}/leech.o: leech.c Hmain.h Hnum.h hash.h ${INCL}/sim.h ${INCL}/sp.h ${INCL}/mod.h
	${CC} ${CCOPTS} -c leech.c 
	mv leech.o ${OBJECTS}/leech.o

${OBJECTS}/ac.o: ac.c Hmain.h ${INCL}/sim.h ${INCL}/sp.h ${INCL}/mod.h ${INCL}/Hcmd.h
	${CC} ${CCOPTS} -c ac.c 
	mv ac.o ${OBJECTS}/ac.o

${OBJECTS}/ac_model.o: ac_model.c Hmain.h ${INCL}/sim.h ${INCL}/sp.h ${INCL}/mod.h ${INCL}/Hcmd.h
	${CC} ${CCOPTS} -c ac_model.c 
	mv ac_model.o ${OBJECTS}/ac_model.o

${OBJECTS}/ac_out.o: ac_out.c Hmain.h ${INCL}/sim.h ${INCL}/sp.h ${INCL}/mod.h ${INCL}/Hcmd.h
	${CC} ${CCOPTS} -c ac_out.c 
	mv ac_out.o ${OBJECTS}/ac_out.o


${OBJECTS}/plot.o: plot.c Hmain.h ${INCL}/sim.h ${INCL}/sp.h ${INCL}/mod.h
	${CC} ${CCOPTS} -c plot.c 
	mv plot.o ${OBJECTS}/plot.o

${OBJECTS}/func.o: func.c Hmain.h ${INCL}/sim.h ${INCL}/sp.h func.h
	${CC} ${CCOPTS} -c func.c 
	mv func.o ${OBJECTS}/func.o

${OBJECTS}/func_user.o: func_user.c Hmain.h ${INCL}/sim.h ${INCL}/sp.h func.h
	${CC} ${CCOPTS} -c func_user.c 
	mv func_user.o ${OBJECTS}/func_user.o

${OBJECTS}/bhash.o: bhash.c Hmain.h bhash.h ${INCL}/sim.h
	${CC} ${CCOPTS} -c bhash.c 
	mv bhash.o ${OBJECTS}/bhash.o

${OBJECTS}/csrcs.o: csrcs.c Hmain.h ${INCL}/sim.h
	${CC} ${CCOPTS} -c csrcs.c 
	mv csrcs.o ${OBJECTS}/csrcs.o

${OBJECTS}/nutout.o: nutout.c Hmain.h ${INCL}/sim.h 
	${CC} ${CCOPTS} -c nutout.c 
	mv nutout.o ${OBJECTS}/nutout.o


${OBJECTS}/ssf.o: ssf.f
	${FC} ${FFLAGS} -c ssf.f
	mv ssf.o ${OBJECTS}/ssf.o

${OBJECTS}/snf.o: snf.f
	${FC} ${FFLAGS} -c snf.f
	mv snf.o ${OBJECTS}/snf.o

${OBJECTS}/sns.o: sns.f
	${FC} ${FFLAGS} -c sns.f
	mv sns.o ${OBJECTS}/sns.o

${OBJECTS}/csns.o: csns.f
	${FC} ${FFLAGS} -c csns.f
	mv csns.o ${OBJECTS}/csns.o

${OBJECTS}/csnf.o: csnf.f
	${FC} ${FFLAGS} -c csnf.f
	mv csnf.o ${OBJECTS}/csnf.o

${OBJECTS}/md.o: md.f
	${FC} ${FFLAGS} -c md.f
	mv md.o ${OBJECTS}/md.o

${OBJECTS}/mdi.o: mdi.f
	${FC} ${FFLAGS} -c mdi.f
	mv mdi.o ${OBJECTS}/mdi.o

${OBJECTS}/mdu.o: mdu.f
	${FC} ${FFLAGS} -c mdu.f
	mv mdu.o ${OBJECTS}/mdu.o

${OBJECTS}/mdp.o: mdp.f
	${FC} ${FFLAGS} -c mdp.f
	mv mdp.o ${OBJECTS}/mdp.o

${OBJECTS}/mdm.o: mdm.f
	${FC} ${FFLAGS} -c mdm.f
	mv mdm.o ${OBJECTS}/mdm.o

install:	cazm
	${COPY} cazm ${BIN}/cazm

clean:
	rm -rf cazm ${OBJECTS}/*.o 

lint:
	lint  ${INCLOPTS}  assem.c cazm.c circ.c comm.c con.c genfq.c globals.c hash.c init.c ntrbdf.c newton.c output.c trans.c table.c trbdf.c tline.c leech.c tick.c tape.c ac.c ac_out.c ac_model.c
