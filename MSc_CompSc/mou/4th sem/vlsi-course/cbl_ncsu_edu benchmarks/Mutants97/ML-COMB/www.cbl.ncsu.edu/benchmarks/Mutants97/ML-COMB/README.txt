Combinational Benchmarks 1997

[Image]

We ask you to post any comments and suggestions about the contents of this
directory using our PosterNotes . We solicit contributions of additional
circuit descriptions that we may use to generate equivalence mutant classes.

Unless noted otherwise, the combinational circuits mutants in this directory
are based on reference circuits described in User Guide
1991-IWLS-UG-Saeyang. See this document for more details about data formats.
Note that the reference circuits themselves have been preprocessed into a
logically equivalent form before the generation of the respective circuit
mutants.

The procedure for generating the equivalence class mutants is described in
1996-TR@CBL-04-Ghosh. The first sets of experiments with some of these
mutants have been described in 1997-TR@CBL-01-Ghosh and 1997-ISPD-Kapur.

For location of these documents and other publications see
http://www.cbl.ncsu.edu/publications/.

The combinational circuit mutants in this directory can be divided in two
groups:

Group 1
-------
n=4:
      ieee_adder-90
      miller-95
n=5:
      roth-62
      sqrt5
      rd53
n=6:
      cm138a
      mult_3X3
n=7:
      inc
      z4ml
n=8:
      rd84
      sqrt8

Mutant circuits in this group have the same number of input sizes (ranging
from 4 to 8) as the PLAs listed for two-level benchmarks under
http://cbl.ncsu.edu/benchmarks/Mutants97/PLA.

Reference circuit roth'62 is taken from J. P. Roth, R. M. Karp, Minimization
over Boolean Graphs, IBM Journal of Research and Development, April 1962.
Reference circuit ieee_adder is taken from R. K. Brayton, G. D. Hachtel and
A. L. Sangiovanni-Vincentelli, "Multilevel Logic Synthesis", Proceedings of
IEEE, Feb. 1990
Reference circuit miller is taken from E.V. Dubrova, D.M. Miller and J.C.
Muzio, "Upper bound on number of products in AND-OR-XOR expansion of logic
functions", Electronics Letters, Vol. 31, No. 7, 1995
Reference circuit mult_3X3 is an array multiplier constructed by D. Ghosh.

As demonstrated in 1996-Thesis-PhD-Zemva, 1997-TR@CBL-01-Ghosh, even the
simple circuit roth'62 and its mutants can be shown to represent a a
non-trivial challenge to the current generation of logic optimization
algorithms.

Group 2
------
Mutant circuits in this group are arranged here in terms of increasing
complexity. The list below describes the name of the reference circuit and
its node complexity to illustrate this point.

Circuit_name            Number_of_nodes
------------            ------------
C432                      179
C499                      206
C1355                     518
X3                       1008
C6288                    2353
des                      5088

Directory Organization :

The mutants are organized as follows:

        * The directory for each equivalence class contains the
          reference circuit and its 100 mutants. The circuits are named
          as {ref_ckt_name}_mut_xxxx.blif where xxxx ranges from 0000
          to 0100.
          0000 indicates the reference circuit which also belongs to
          the equivalence class.
        * The directory containing 101 circuits is 'tar'ed and zipped
          to form the {ref_ckt_name}_mutants.tar.gz file, which are
          used for distribution.

To use these mutants :

        * Download the {ref_ckt_name}.mutants.tar.gz file for the
          desired {ref_ckt_name}.
        * Execute the command

          gunzip -c _mutants.tar.gz | tar xf -

          to retrieve the directory.

For further information contact:
ghosh@cbl.ncsu.edu or kapur@cbl.ncsu.edu
