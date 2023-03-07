mkdir 1
tcc -1 -n1 add.c
mkdir 2
tcc -2 -n2 add.c
mkdir C
tcc -C -nC add.c
mkdir G
tcc -G -nG add.c
mkdir K
tcc -K -nK add.c
mkdir M
tcc -M -nM add.c
mkdir O
tcc -O -nO add.c
mkdir N
tcc -N -nN add.c
mkdir P
tcc -P -nP add.c
mkdir S
tcc -S -nS add.c
mkdir X
tcc -X -nX add.c
mkdir Z
tcc -Z -nZ add.c
mkdir aa
tcc -a -naa add.c
mkdir cc
tcc -c -ncc add.c
mkdir dd
tcc -d -ndd add.c
mkdir ee
tcc -eadd -nee add.c
mkdir gg
tcc -g1 -ngg add.c
mkdir ii
tcc -i10 -nii add.c
mkdir jj
tcc -j10 -njj add.c
mkdir kk
tcc -k -nkk add.c
mkdir rr
tcc -r -nrr add.c
mkdir uu
tcc -u -nuu add.c
mkdir vv
tcc -v -nvv add.c
mkdir yy
tcc -y -nyy add.c
mkdir oo
copy add.c oo\add.c
cd oo
tcc -oadd add.c
del add.c
cd..
