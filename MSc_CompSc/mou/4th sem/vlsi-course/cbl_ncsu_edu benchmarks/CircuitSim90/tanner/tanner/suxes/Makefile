#
.SUFFIXES:  .f
#FC = f77 
FFLAGS = -g
SRCDIR = /src1/local/vlsi/simcad/src/suxes/src/
SINBAD   = /src1/local/vlsi/sinbad/include
LIBSIM	 = /src1/local/vlsi/sinbad/lib/libsim.a
LIBMOD   = MOD.a

NEW_LIBMOD = NEW_MOD.a

OBJ     = $(SRCDIR)ssuxes.o   $(SRCDIR)sscreen.o \
          $(SRCDIR)sspice.o   $(SRCDIR)sorder.o \
          $(SRCDIR)smodels.o  $(SRCDIR)smodel1.o \
          $(SRCDIR)smodel2.o  $(SRCDIR)smodel3.o \
	  $(SRCDIR)lsx.o      $(SRCDIR)smodel4.o \
	  $(SRCDIR)mod_moscheck.o

OBJ1    = $(SRCDIR)ssuxes.o   $(SRCDIR)sscreen.o \
          $(SRCDIR)sspice.o   $(SRCDIR)sorder.o \
          $(SRCDIR)smodels.o  $(SRCDIR)smodel1.o \
          $(SRCDIR)smodel2.o  $(SRCDIR)smodel3.o \
	  $(SRCDIR)new_lsx.o      $(SRCDIR)smodel4.o 

suxxes: $(OBJ) ${LIBMOD} 
	$(FC) $(FFLAGS) $(OBJ) -o suxxes ${LIBSIM} ${LIBMOD}

new_suxxes: $(OBJ1) ${NEW_LIBMOD}
	$(FC) $(FFLAGS) $(OBJ1) -o new_suxxes ${LIBSIM} ${NEW_LIBMOD}

#.f.o: ; $(FC) $(FFLAGS)  $*.f
.c.o: ; cc -c -g -I$(SINBAD) $*.c
