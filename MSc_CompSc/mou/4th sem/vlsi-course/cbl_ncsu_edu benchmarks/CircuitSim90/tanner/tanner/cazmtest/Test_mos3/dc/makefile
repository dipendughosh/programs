MODEL = /usr/vlsi/lib/spice/cmos/HP160CN
CAZM = /unc/jge/bin/cazm
SPICE2 = /unc/jge/cad/cazm/spice2/spice

plot2g6:	spice2g6
		cat 2g6.plot | lpr -g -Plw2

plot3b1:	spice3b1
		cat 3b1.plot | lpr -g -Plw2

plotc:		cazm
		cat cazm.plot | lpr -g -Plw2

diffc:		cazm
		cat nfet_*.N.c pfet_*.N.c > c.old
		/bin/rm nfet_*.N.c pfet_*.N.c
		make cazm
		cat nfet_*.N.c pfet_*.N.c > c.new
		diff c.old c.new > c.diff
		wc c.diff

spice2g6:	nfet_1.N.s2 nfet_2.N.s2 nfet_3.N.s2 nfet_4.N.s2 \
		pfet_1.N.s2 pfet_2.N.s2 pfet_3.N.s2 pfet_4.N.s2

spice3b1:	nfet_1.N.s3 nfet_2.N.s3 nfet_3.N.s3 nfet_4.N.s3 \
		pfet_1.N.s3 pfet_2.N.s3 pfet_3.N.s3 pfet_4.N.s3

cazm:		nfet_1.N.c nfet_2.N.c nfet_3.N.c nfet_4.N.c \
		pfet_1.N.c pfet_2.N.c pfet_3.N.c pfet_4.N.c

nfet_1.N.s2:	$(MODEL) nfet_1.fa nfet.env
		cat $(MODEL) nfet_1.fa nfet.env | expand > spice.in 
		echo ".end" >> spice.in
		$(SPICE2) < spice.in > spice.out
		awk -f fixgraph.s2.a spice.out > nfet_1.N.s2
		cat nfet_1.N.s2 | \
		 graph -b -g 2 -l nfet_1.N.s2 -x 0 5.5 0.5 -y 0 400 50 -h 0.6035 -w 0.80145 > 2g6.plot

nfet_2.N.s2:	$(MODEL) nfet_2.fa nfet.env
		cat $(MODEL) nfet_2.fa nfet.env | expand > spice.in 
		echo ".end" >> spice.in
		$(SPICE2) < spice.in | awk -f fixgraph.s2.a > nfet_2.N.s2
		cat nfet_2.N.s2 | \
		 graph -b -g 2 -l nfet_2.N.s2 -x 0 5.5 0.5 -y 0 24 2 -h 0.6035 -w 0.80145 >> 2g6.plot
		 lpr -g -Plw2

nfet_3.N.s2:	$(MODEL) nfet_3.fa nfet.env
		cat $(MODEL) nfet_3.fa nfet.env | expand > spice.in 
		echo ".end" >> spice.in
		$(SPICE2) < spice.in | awk -f fixgraph.s2.a > nfet_3.N.s2
		cat nfet_3.N.s2 | \
		 graph -b -g 2 -l nfet_3.N.s2 -x 0 5.5 0.5 -y 0 9000 1000 -h 0.6035 -w 0.80145 >> 2g6.plot
		 lpr -g -Plw2

nfet_4.N.s2:	$(MODEL) nfet_4.fa nfet.env
		cat $(MODEL) nfet_4.fa nfet.env | expand > spice.in 
		echo ".end" >> spice.in
		$(SPICE2) < spice.in | awk -f fixgraph.s2.a > nfet_4.N.s2
		cat nfet_4.N.s2 | \
		 graph -b -g 2 -l nfet_4.N.s2 -x 0 5.5 0.5 -y 0 550 50 -h 0.6035 -w 0.80145 >> 2g6.plot
		 lpr -g -Plw2

pfet_1.N.s2:	$(MODEL) pfet_1.fa pfet.env
		cat $(MODEL) pfet_1.fa pfet.env | expand > spice.in 
		echo ".end" >> spice.in
		$(SPICE2) < spice.in | awk -f fixgraph.s2.a > pfet_1.N.s2
		cat pfet_1.N.s2 | \
		 graph -b -g 2 -l pfet_1.N.s2 -x 0 5.5 0.5 -y 0 140 20 -h 0.6035 -w 0.80145 >> 2g6.plot
		 lpr -g -Plw2

pfet_2.N.s2:	$(MODEL) pfet_2.fa pfet.env
		cat $(MODEL) pfet_2.fa pfet.env | expand > spice.in 
		echo ".end" >> spice.in
		$(SPICE2) < spice.in | awk -f fixgraph.s2.a > pfet_2.N.s2
		cat pfet_2.N.s2 | \
		 graph -b -g 2 -l pfet_2.N.s2 -x 0 5.5 0.5 -y 0 6 1 -h 0.6035 -w 0.80145 >> 2g6.plot
		 lpr -g -Plw2

pfet_3.N.s2:	$(MODEL) pfet_3.fa pfet.env
		cat $(MODEL) pfet_3.fa pfet.env | expand > spice.in 
		echo ".end" >> spice.in
		$(SPICE2) < spice.in | awk -f fixgraph.s2.a > pfet_3.N.s2
		cat pfet_3.N.s2 | \
		 graph -b -g 2 -l pfet_3.N.s2 -x 0 5.5 0.5 -y 0 3500 500 -h 0.6035 -w 0.80145 >> 2g6.plot
		 lpr -g -Plw2

pfet_4.N.s2:	$(MODEL) pfet_4.fa pfet.env
		cat $(MODEL) pfet_4.fa pfet.env | expand > spice.in 
		echo ".end" >> spice.in
		$(SPICE2) < spice.in | awk -f fixgraph.s2.a > pfet_4.N.s2
		cat pfet_4.N.s2 | \
		 graph -b -g 2 -l pfet_4.N.s2 -x 0 5.5 0.5 -y 0 160 20 -h 0.6035 -w 0.80145 >> 2g6.plot
		 lpr -g -Plw2


nfet_1.N.s3:	$(MODEL) nfet_1.fa nfet.env
		cat $(MODEL) nfet_1.fa nfet.env | expand > spice.in 
		echo ".end" >> spice.in
		spice -b spice.in > spice.out
		awk -f fixgraph.s3.a spice.out > nfet_1.N.s3
		cat nfet_1.N.s3 | \
		 graph -b -g 2 -l nfet_1.N.s3 -x 0 5.5 0.5 -y 0 400 50 -h 0.6035 -w 0.80145 > 3b1.plot

nfet_2.N.s3:	$(MODEL) nfet_2.fa nfet.env
		cat $(MODEL) nfet_2.fa nfet.env | expand > spice.in 
		echo ".end" >> spice.in
		spice -b spice.in | awk -f fixgraph.s3.a > nfet_2.N.s3
		cat nfet_2.N.s3 | \
		 graph -b -g 2 -l nfet_2.N.s3 -x 0 5.5 0.5 -y 0 24 2 -h 0.6035 -w 0.80145 >> 3b1.plot

nfet_3.N.s3:	$(MODEL) nfet_3.fa nfet.env
		cat $(MODEL) nfet_3.fa nfet.env | expand > spice.in 
		echo ".end" >> spice.in
		spice -b spice.in | awk -f fixgraph.s3.a > nfet_3.N.s3
		cat nfet_3.N.s3 | \
		 graph -b -g 2 -l nfet_3.N.s3 -x 0 5.5 0.5 -y 0 9000 1000 -h 0.6035 -w 0.80145 >> 3b1.plot

nfet_4.N.s3:	$(MODEL) nfet_4.fa nfet.env
		cat $(MODEL) nfet_4.fa nfet.env | expand > spice.in 
		echo ".end" >> spice.in
		spice -b spice.in | awk -f fixgraph.s3.a > nfet_4.N.s3
		cat nfet_4.N.s3 | \
		 graph -b -g 2 -l nfet_4.N.s3 -x 0 5.5 0.5 -y 0 550 50 -h 0.6035 -w 0.80145 >> 3b1.plot

pfet_1.N.s3:	$(MODEL) pfet_1.fa pfet.env
		cat $(MODEL) pfet_1.fa pfet.env | expand > spice.in 
		echo ".end" >> spice.in
		spice -b spice.in | awk -f fixgraph.s3.a > pfet_1.N.s3
		cat pfet_1.N.s3 | \
		 graph -b -g 2 -l pfet_1.N.s3 -x 0 5.5 0.5 -y 0 140 20 -h 0.6035 -w 0.80145 >> 3b1.plot

pfet_2.N.s3:	$(MODEL) pfet_2.fa pfet.env
		cat $(MODEL) pfet_2.fa pfet.env | expand > spice.in 
		echo ".end" >> spice.in
		spice -b spice.in | awk -f fixgraph.s3.a > pfet_2.N.s3
		cat pfet_2.N.s3 | \
		 graph -b -g 2 -l pfet_2.N.s3 -x 0 5.5 0.5 -y 0 6 1 -h 0.6035 -w 0.80145 >> 3b1.plot

pfet_3.N.s3:	$(MODEL) pfet_3.fa pfet.env
		cat $(MODEL) pfet_3.fa pfet.env | expand > spice.in 
		echo ".end" >> spice.in
		spice -b spice.in | awk -f fixgraph.s3.a > pfet_3.N.s3
		cat pfet_3.N.s3 | \
		 graph -b -g 2 -l pfet_3.N.s3 -x 0 5.5 0.5 -y 0 3500 500 -h 0.6035 -w 0.80145 >> 3b1.plot

pfet_4.N.s3:	$(MODEL) pfet_4.fa pfet.env
		cat $(MODEL) pfet_4.fa pfet.env | expand > spice.in 
		echo ".end" >> spice.in
		spice -b spice.in | awk -f fixgraph.s3.a > pfet_4.N.s3
		cat pfet_4.N.s3 | \
		 graph -b -g 2 -l pfet_4.N.s3 -x 0 5.5 0.5 -y 0 160 20 -h 0.6035 -w 0.80145 >> 3b1.plot


nfet_1.N.c:	$(MODEL) nfet_1.c.fa nfet.cmd
		cat $(MODEL) nfet_1.c.fa > cazm.in
		$(CAZM) -o cazm.out cazm.in nfet.cmd
		awk -f fixgraph.ca.a cazm.out > nfet_1.N.c
		cat nfet_1.N.c | \
		 graph -b -g 2 -l nfet_1.N.c -x 0 5.5 0.5 -y 0 400 50 -h 0.6035 -w 0.80145 > cazm.plot


nfet_2.N.c:	$(MODEL) nfet_2.c.fa nfet.cmd
		cat $(MODEL) nfet_2.c.fa > cazm.in
		$(CAZM) -o cazm.out cazm.in nfet.cmd
		awk -f fixgraph.ca.a cazm.out > nfet_2.N.c
		cat nfet_2.N.c | \
		 graph -b -g 2 -l nfet_2.N.c -x 0 5.5 0.5 -y 0 24 2 -h 0.6035 -w 0.80145 >> cazm.plot


nfet_3.N.c:	$(MODEL) nfet_1.c.fa nfet.cmd
		cat $(MODEL) nfet_3.c.fa > cazm.in
		$(CAZM) -o cazm.out cazm.in nfet.cmd
		awk -f fixgraph.ca.a cazm.out > nfet_3.N.c
		cat nfet_3.N.c | \
		 graph -b -g 2 -l nfet_3.N.c -x 0 5.5 0.5 -y 0 9000 1000 -h 0.6035 -w 0.80145 >> cazm.plot


nfet_4.N.c:	$(MODEL) nfet_4.c.fa nfet.cmd
		cat $(MODEL) nfet_4.c.fa > cazm.in
		$(CAZM) -o cazm.out cazm.in nfet.cmd
		awk -f fixgraph.ca.a cazm.out > nfet_4.N.c
		cat nfet_4.N.c | \
		 graph -b -g 2 -l nfet_4.N.c -x 0 5.5 0.5 -y 0 550 50 -h 0.6035 -w 0.80145 >> cazm.plot

pfet_1.N.c:	$(MODEL) pfet_1.c.fa pfet.cmd
		cat $(MODEL) pfet_1.c.fa > cazm.in
		$(CAZM) -o cazm.out cazm.in pfet.cmd
		awk -f fixgraph.ca.a cazm.out > pfet_1.N.c
		cat pfet_1.N.c | \
		 graph -b -g 2 -l pfet_1.N.c -x 0 5.5 0.5 -y 0 140 20 -h 0.6035 -w 0.80145 >> cazm.plot


pfet_2.N.c:	$(MODEL) pfet_2.c.fa pfet.cmd
		cat $(MODEL) pfet_2.c.fa > cazm.in
		$(CAZM) -o cazm.out cazm.in pfet.cmd
		awk -f fixgraph.ca.a cazm.out > pfet_2.N.c
		cat pfet_2.N.c | \
		 graph -b -g 2 -l pfet_2.N.c -x 0 5.5 0.5 -y 0 6 1 -h 0.6035 -w 0.80145 >> cazm.plot

pfet_3.N.c:	$(MODEL) pfet_3.c.fa pfet.cmd
		cat $(MODEL) pfet_3.c.fa > cazm.in
		$(CAZM) -o cazm.out cazm.in pfet.cmd
		awk -f fixgraph.ca.a cazm.out > pfet_3.N.c
		cat pfet_3.N.c | \
		 graph -b -g 2 -l pfet_3.N.c -x 0 5.5 0.5 -y 0 3500 500 -h 0.6035 -w 0.80145 >> cazm.plot

pfet_4.N.c:	$(MODEL) pfet_4.c.fa pfet.cmd
		cat $(MODEL) pfet_4.c.fa > cazm.in
		$(CAZM) -o cazm.out cazm.in pfet.cmd
		awk -f fixgraph.ca.a cazm.out > pfet_4.N.c
		cat pfet_4.N.c | \
		 graph -b -g 2 -l pfet_4.N.c -x 0 5.5 0.5 -y 0 160 20 -h 0.6035 -w 0.80145 >> cazm.plot
