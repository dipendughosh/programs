Two-level Benchmarks 1997

[Image]

We ask you to post any comments and suggestions about the contents of this
directory using our PosterNotes.

We have generated PLA equivalence classes with number of inputs ranging from
3 to 16 and syndrome of 0.125, 0.25, 0.5. There are 100 PLAs in each class.
The first sets of experiments on some of these descriptions are available in
1996-Thesis-PhD-Zemva.

A syndrome for an n-input PLA is defined as

                  s = (no. of 1's in the PLA output)/(2^n)

It is known that PLAs with s=0.5 involve highest amount of computations and
hence may result in a circuit of highest complexity for a given input size.
For example, see:
K.T. Cheng and V.D. Agrawal, "An Entropy Measure for the Complexity of
Multi-Output Boolean Functions",
Design Automation Conference, pp. 302-305, June 1991.
As shown in the list, the current directory stores PLAs with s=0.125 and
s=0.5 and input sizes of n=4 to n=8. Efficient construction of PLAs of other
input sizes and syndrome are under construction. If you need PLAs of other
input size/syndrome, please send a request to ghosh@cbl.ncsu.edu.

To use these PLAs:

        * Download the file PLAs.tar.gz
        * Execute the command

          gunzip -c PLAs.tar.gz | tar xf -

          to retrieve the directory.

For more details about data formats, see the User Guide 1991-IWLS-UG-Saeyang
