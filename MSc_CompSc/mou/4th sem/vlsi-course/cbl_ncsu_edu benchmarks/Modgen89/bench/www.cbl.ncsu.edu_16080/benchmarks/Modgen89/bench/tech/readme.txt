.PH ""
.ce
Technology and Plotting Rules

One of the purposes of the Physical Design Workshop is to compare algorithms
for module synthesis on a ``level playing field.''
Since we do not consider fabrication technology to be part of the workshop,
we have to compensate for  differences in things like design rules and electrical 
characteristics that each CAD group works with.

.H 1 "Basic Rules"
One way to do that is to require everybody to use the same design rules 
and electrical models.
If you are able to participate on this level,
please do so.
The rules to use are the MOSIS CMOS 3.0 micron rules supplied in the 
file ``mosis.3.0.rules''.
If you cannot,
please use whatever technology your tools work 
with that is closely proportional
to the rules,
e.g. the metal wires should be larger than the poly wires by a factor of 1.5,
and metal2, if present,
should be the same width as metal.
We suggest you use an older technology that is in no way proprietary to your company,
to simplify releasing your results.

.H 1 "Technology Normalization Cell"

In either case,
you are required to enter and simulate the ``technology normalization'' cell.
This just a bunch of combinational gates: 2 inverters,
a NAND and a NOR gate.
The logic of the cell is (expressed in C)
	
.nf
	temp1 = !in;
	temp2 = !in;
	temp3 = !(temp1 && temp2)
	out = !(temp3 || temp3);
.fi

Obviously, 
this is nonsense.
But it has the properties that
the output is the inverse of the input,
and no signals go nowhere.
Do not lay this out with your synthesizer!
Instead,
use the exact topology provided:
A ``gate-matrix'' style ASCII file is shown in ``normal.gm,''
a postscript drawing (outlines only) is included in ``normal.post,''
and a pic drawing (with shading) is included in ``normal.pic.''
Most likely,
it will be quicker and easier for you to get it a 
layout editor and enter it graphically.
Enter the design,
in virtual or fixed-grid,
into your system.
If you will use a compacter on the benchmarks,
run it on the normalizer cell to produce a hard-dimensioned layout.
If your compacter is capable of adding jogs,
reordering objects,
offsetting contacts,
flipping transistors,
etc.,
please disable these features for the normalization cell.
If you cannot disable these optimizations,
you will have to get into the layout and undo them.
Your final output should look exactly like the picture presented
including any extra contacts and wasted wires.
It should,
for example,
have 4 diffusion breaks running horizontally,
and 5 tracks of metal-poly routing contacts between the nFET and pFETs.
It is in your interest to conform to the topology on this cell!
Save your state-of-the-art transformations on the real benchmarks.
Adjust your layout so that it can but together on the right
and left sides. 
This means that you will have to provide clearance so
that the diffusion does not short out or have design rule
violations.
The ``size'' of your cell must include these spacings.

(We tried running the normalization cell with the 3.0 rules
and got dimensions of about 111 microns wide by 113 tall.
Measured on the span of the cell in X (the repeatable spacing)
and from the bottom of the ground wire to the top of the Vdd wire.
Note that ground and power wires are 2X minimum size = 9 microns.
The area may be effected by how you compact diagonally around MP contacts.
These dimensions are preliminary -- your results may be slightly different).

.H 2 "Technology Details"

Here are some more details that are not discussed widely,
but should be considered in doing the layout:
Whenever we say ``default size FET'' we mean the smallest FET that will
butt up with a metal-diffusion contact.
In the MOSIS 3.0 rules, this is 6 microns.
That is, 
the channel width == side of diffusion square in the contact.
This may be larger than the smallest transistor 
that can be reliably fabricated,
but it serves to equalize participants.
For the normalizing cell,
please use nFETs that are 2 times the default and pFETs that are 3 times.
Many shops require tub ties are required for both the pMOS and nMOS side;
to be fair,
even if your technology does not need them, please put them in.
And put in enough tub ties so that no diffusion is more 
than 10 contact widths (60 microns)
from a tub tie.
(Some shops will probably find this optimistic,
others unrealistic).
Also,
put at least one tub tie in for every 5 transistors.
Finally,
include the tubs themselves (n or p or both) in the final drawing,
at least if they are not obvious.
But keep them subtle so as not to obscure the transistors (more on drawing later).

.H 2 "NMOS Details"

For any nMOS example,
you may assume the availability of buried contacts (diffusion-poly)
and three-way contacts (metal-diffusion-poly).
Assume that these are the same size as n-type tub ties.
Also,
please assume the conservative 4:1 ratio of pull-down to pull-up strength,
and use depletion loads.
Assume the same minimum sizes for channel length and widths as for CMOS.


.H 2 "Resistance"

One of the biggest problems in this arena is that of diffusion runners.
Some CAD systems use diffusion freely, others avoid it almost entirely
as an interconnection level because of its high capacitance 
(both fringe and area)
and high resistance per square (Weste quotes 1000 Ohms/sq).
Nevertheless,
it is found in the output of some systems.
If your system does this,
please be prepared to justify its use,
its impact on performance,
and reliability.
Reliability is also influenced by metal migration and IR drop
on power lines.
Please use a guideline of 1 milliamp/micron for metal migration.
If you don't compute this, please use powerlines that are at least
2 times the minimum width for cells less than 20 transistors,
and 4 times minimum width for larger cells.
High-speed, working chips,
and/or oscilloscope photos thereof 
would be considered the most compelling evidence that you have
accurate speed and reliability models.

.H 2 "Calibrating Speed"

Speaking of speed:
many of the participants are interested in the speed of their modules as much as,
or more than their area.
In order to speak the same language,
we ask that you take the normallizer cell,
build 10 copies right next to each other in a row.
Then run it through your local circuit simulator such as SPICE,
or your local static timing analyzer such as CRYSTAL, or TV.
Put a pulse in the input and figure how long it takes to get out the other end.
Divide the time by the number of stages (10) and then by the number of gates per stage (3),
and that will be used as ``one gate delay'' for the purpose of comparison.
(As in ``our timing driven layout''
achieved a worst case delay of 3.2 gate delay equivalents.)

.H 1 "Plotting Rules"

When you make your plots,
please try to use color,
and use the color scheme in the INSIDE of Neil Weste's book,
``Principles of VLSI System Design'' (not the scheme on the cover).
These colors are as follows:
metal=blue, poly=red, n-type diff = green, p-type diff=yellow, contacts shown in black.
Colors for things not in Weste's book:
metal2=grey, ptub (which goes around nFET's) should be a faint yellow outline,
and likewise ntub (which goes around pFET's) should be a faint green outline.
Please plot with a white background.
Make your plots large enough to show the points of interest,
and provide a scale (microns of silicon / inch of paper) on each one.
The normalization of the designs will be done at the workshop
after we've compared plots of the normalization cell itself.
Attach them to large sheets of cardboard,
one benchmark per sheet,
and show the benchmark number on each one (e.g. ``1.3'').
This way,
all of the ALU's can be displayed near each other, 
for example.
You may want to make blow-ups of small areas to show off clever features
(e.g. dog-leg routing).

.H 1 Summary

We understand that doing this normalization cell involves effort and time,
and that it is far from a perfect comparison.
Many technology differences exist that are not included here.
But given the limitations of time and the diverse set of CAD tools and participants,
it seems like the only way to at compare fruit with fruit,
if not apples with apples.
