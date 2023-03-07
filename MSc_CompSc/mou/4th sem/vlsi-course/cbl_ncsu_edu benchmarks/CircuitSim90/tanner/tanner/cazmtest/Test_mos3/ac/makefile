MODEL = /usr/vlsi/lib/spice/cmos/HP160CN
CAZM = /unc/jge/bin/cazm
SPICE2 = /usr/vlsi/bin/spice2g6
SPICE3 = /usr/vlsi/bin/spice
AWKS = /unc/jp/cadtools/awks

# Check charge model by sloshing charge on/off gate/drain terminals
a:		a.c a.s2 a.s3

# Check charge model by modelling circuit with considerable Miller cap
b:		b.c b.s2 b.s3

# Check charge model by sloshing charge on/off drains of several transistors
c:		c.c c.s2 c.s3

# Test the effectiveness of Nfs in controlling weak inversion model
nfs:		nfs.n.c nfs.p.c nfs.n.s2 nfs.p.s2

# Test the temperature model
t:		t.n.27.c t.n.100.c t.p.27.c t.p.100.c \
		t.n.27.s2 t.n.100.s2 t.p.27.s2 t.p.100.s2 

# Test the Wd parameter
wd:		wd.pre wd.non

# Test the current model's ability to handle body effect
bd:		bd.n.c bd.p.c bd.n.s2 bd.p.s2

a.c:		a.fa a.cmd $(MODEL) $(CAZM)
		cat $(MODEL) a.fa > cazm.in
		$(CAZM) -o cazm.out cazm.in a.cmd
		awk -f fixa.c.a cazm.out > a.c

a.s2:		a.spc a.env $(MODEL) $(SPICE2)
		cat $(MODEL) a.spc a.env | expand > spice.in
		echo ".options limpts=20000" >> spice.in
		echo ".end" >> spice.in
		$(SPICE2) < spice.in > spice.out
		spicestrip spice.out > tmp
		awk -f fixa.s.a tmp > a.s2

a.s3:		a.spc a.env $(MODEL) $(SPICE3)
		cat $(MODEL) a.spc a.env | expand > spice.in
		$(SPICE3) -b spice.in > spice.out
		awk -f $(AWKS)/strip.a spice.out > tmp
		awk -f fixa.s.a tmp > a.s3


b.c:		b.fa b.cmd
		cat $(MODEL) b.fa > cazm.in
		$(CAZM) -o b.c cazm.in b.cmd

b.s2:		b.spc b.env $(MODEL) $(SPICE2)
		cat $(MODEL) b.spc b.env | expand > spice.in
		echo ".options limpts=20000" >> spice.in
		echo ".end" >> spice.in
		$(SPICE2) < spice.in > spice.out
		spicestrip spice.out > b.s2

b.s3:		b.spc b.env $(MODEL) $(SPICE3)
		cat $(MODEL) b.spc b.env > spice.in
		$(SPICE3) -b spice.in > spice.out
		awk -f $(AWKS)/strip.a spice.out > b.s3

c.c:		c.fa c.cmd
		cat $(MODEL) c.fa > cazm.in
		$(CAZM) -o cazm.out cazm.in c.cmd
		awk -f fixc.a cazm.out > c.c

c.s2:		c.sp c.env $(MODEL) $(SPICE2)
		cat $(MODEL) c.sp c.env | expand > spice.in
		echo ".options limpts=20000" >> spice.in
		echo ".end" >> spice.in
		$(SPICE2) < spice.in > spice.out
		spicestrip spice.out > tmp
		awk -f fixc.a tmp > c.s2

c.s3:		c.sp c.env $(MODEL) $(SPICE3)
		cat $(MODEL) c.sp c.env | expand > spice.in
		$(SPICE3) -b spice.in > spice.out
		awk -f $(AWKS)/strip.a spice.out > tmp
		awk -f fixc.a tmp > c.s3

nfs.n.c:	nfs.n.fa nfs.n.cmd nfs.model $(CAZM)
		$(CAZM) -o tmp -m nfs.model nfs.n.fa nfs.n.cmd
		awk -f fixgraph.ca.a tmp > nfs.n.c

nfs.p.c:	nfs.p.fa nfs.p.cmd nfs.model $(CAZM)
		$(CAZM) -o tmp -m nfs.model nfs.p.fa nfs.p.cmd
		awk -f fixgraph.ca.a tmp > nfs.p.c

nfs.n.s2:	nfs.n.spc nfs.n.env nfs.model $(SPICE2)
		cat nfs.model nfs.n.spc nfs.n.env | expand > spice.in
		echo ".end" >> spice.in
		$(SPICE2) < spice.in > spice.out
		awk -f fixgraph.s2.a spice.out > nfs.n.s2

nfs.p.s2:	nfs.p.spc nfs.p.env nfs.model $(SPICE2)
		cat nfs.model nfs.p.spc nfs.p.env | expand > spice.in
		echo ".end" >> spice.in
		$(SPICE2) < spice.in > spice.out
		awk -f fixgraph.s2.a spice.out > nfs.p.s2

t.n.27.c:	t.n.fa t.n.cmd $(MODEL) $(CAZM)
		$(CAZM) -o tmp -m $(MODEL) t.n.fa t.n.cmd
		awk -f fixgraph.ca.a tmp > t.n.27.c

t.n.100.c:	t.n.fa t.n.cmd $(MODEL) $(CAZM)
		cat t.n.cmd > 100.n.cmd
		echo "temp 100" >> 100.n.cmd
		$(CAZM) -o tmp -m $(MODEL) t.n.fa 100.n.cmd
		awk -f fixgraph.ca.a tmp > t.n.100.c
		/bin/rm 100.n.cmd

t.p.27.c:	t.p.fa t.p.cmd $(MODEL) $(CAZM)
		$(CAZM) -o tmp -m $(MODEL) t.p.fa t.p.cmd
		awk -f fixgraph.ca.a tmp > t.p.27.c

t.p.100.c:	t.p.fa t.p.cmd $(MODEL) $(CAZM)
		cat t.p.cmd > 100.p.cmd
		echo "temp 100" >> 100.p.cmd
		$(CAZM) -o tmp -m $(MODEL) t.p.fa 100.p.cmd
		awk -f fixgraph.ca.a tmp > t.p.100.c
		/bin/rm 100.p.cmd

t.n.27.s2:	t.n.spc t.n.env $(MODEL) $(SPICE2)
		cat $(MODEL) t.n.spc t.n.env | expand > spice.in
		echo ".end" >> spice.in
		$(SPICE2) < spice.in > spice.out
		awk -f fixgraph.s2.a spice.out > t.n.27.s2

t.n.100.s2:	t.n.spc t.n.env $(MODEL) $(SPICE2)
		cat $(MODEL) t.n.spc t.n.env | expand > spice.in
		echo ".temp 100" >> spice.in
		echo ".end" >> spice.in
		$(SPICE2) < spice.in > spice.out
		awk -f fixgraph.s2.a spice.out > t.n.100.s2

t.p.27.s2:	t.p.spc t.p.env $(MODEL) $(SPICE2)
		cat $(MODEL) t.p.spc t.p.env | expand > spice.in
		echo ".end" >> spice.in
		$(SPICE2) < spice.in > spice.out
		awk -f fixgraph.s2.a spice.out > t.p.27.s2

t.p.100.s2:	t.p.spc t.p.env $(MODEL) $(SPICE2)
		cat $(MODEL) t.p.spc t.p.env | expand > spice.in
		echo ".temp 100" >> spice.in
		echo ".end" >> spice.in
		$(SPICE2) < spice.in > spice.out
		awk -f fixgraph.s2.a spice.out > t.p.100.s2

wd.pre:		wd.pre.fa wd.cmd $(MODEL) $(CAZM)
		$(CAZM) -o wd.pre -m $(MODEL) wd.pre.fa wd.cmd

wd.non:		wd.non.fa wd.cmd wd.model $(CAZM)
		$(CAZM) -o wd.non -m wd.model wd.non.fa wd.cmd

bd.0.n.c:	bd.n.fa bd.n.cmd $(MODEL) $(CAZM)
		echo "volt Bulk GND 0" > tmp.cmd
		cat bd.n.cmd >> tmp.cmd
		$(CAZM) -o tmp -m $(MODEL) bd.n.fa tmp.cmd
		awk -f fixgraph.ca.a tmp > bd.0.n.c

bd.1.n.c:	bd.n.fa bd.n.cmd $(MODEL) $(CAZM)
		echo "volt Bulk GND -1.0" > tmp.cmd
		cat bd.n.cmd >> tmp.cmd
		$(CAZM) -o tmp -m $(MODEL) bd.n.fa tmp.cmd
		awk -f fixgraph.ca.a tmp > bd.1.n.c

bd.2.n.c:	bd.n.fa bd.n.cmd $(MODEL) $(CAZM)
		echo "volt Bulk GND -2.0" > tmp.cmd
		cat bd.n.cmd >> tmp.cmd
		$(CAZM) -o tmp -m $(MODEL) bd.n.fa tmp.cmd
		awk -f fixgraph.ca.a tmp > bd.2.n.c

bd.0.n.s2:	bd.n.spc bd.n.env $(MODEL) $(SPICE2)
		cat $(MODEL) bd.n.spc | expand > spice.in
		echo "vbulk 3 0 dc 0" >> spice.in
		cat bd.n.env >> spice.in
		echo ".end" >> spice.in
		$(SPICE2) < spice.in > spice.out
		awk -f fixgraph.s2.a spice.out > bd.0.n.s2

bd.1.n.s2:	bd.n.spc bd.n.env $(MODEL) $(SPICE2)
		cat $(MODEL) bd.n.spc | expand > spice.in
		echo "vbulk 3 0 dc -1.0" >> spice.in
		cat bd.n.env >> spice.in
		echo ".end" >> spice.in
		$(SPICE2) < spice.in > spice.out
		awk -f fixgraph.s2.a spice.out > bd.1.n.s2

bd.2.n.s2:	bd.n.spc bd.n.env $(MODEL) $(SPICE2)
		cat $(MODEL) bd.n.spc | expand > spice.in
		echo "vbulk 3 0 dc -2.0" >> spice.in
		cat bd.n.env >> spice.in
		echo ".end" >> spice.in
		$(SPICE2) < spice.in > spice.out
		awk -f fixgraph.s2.a spice.out > bd.2.n.s2

