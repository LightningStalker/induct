# induct
Calculators and utilities for real-world electronic design

## iloc
iloc.c is a very simple calculator program for designing single layer air coils,
including space wound coils having a length equal to or greater than 4 times
their diameter. For single turn inductances and shorter coils, I encourage you
to consult the fine work of the late Nagaoka who published tables and formulas
for his correction coefficient. This was not a concern for the scope of this
simple calculator as such inductances are not seen or desirable outside of
antenna systems or above UHF frequencies. I may decide to revisit this should
the need arise.

Most calculators found online need either length or turns count to generate a
result. As they are both mathematically related, this has been simplified to a
single term in the form of turns spacing. Thus all that is required is target
inductance, diameter, and the turns spacing value to derive both length and
turns count. I have found this much easier when designing coils, especially
spacewound coils.

Eventually the capability to output capacitance and self resonant frequency
would be ideal, however the available formulas do not appear to be accurate
enough to produce a result that would allow one to design and build a component
such as a trap with any kind of accuracy. Maybe it's asking a bit too much right
now. Taking it slow and careful with the incremental progress thus far is
producing some results albeit at such a glacial pace.

## tankfreq
tankfreq.c is another very simple program which will calculate LC tank circuit
resonance frequency as might be expected. 

## elcut
elcut.c is a very very simple calculator designed as an antenna tuning aid. It
will give the estimated length to remove from a wire in order to bring it to the
desired resonance frequency as entered. It is recommended never to remove the
exact amount given but instead gradually and carefully reach the resonant
length. As in the oft repeated words of Guy Wireson (whom has died), "You can
take more off but you can't put more back on." If you don't think that's funny
at least consider it my gift to you as the only person who will ever read this.

## cap
cap.c is the capacitor complement to iloc. It calculates dimensions for
capacitors of several different shapes. Simply provide the K permittivity
constant for the dielectric material and various dimensions as they are called
for. Though the algorithm is extremely simple, even moreso than the other
calculators in this collection, it does speed up the process and make for less
time entering formulas into a calculator (and less chance for mistakes).

### Command line options are:
* -p = flat plate capacitor
* -c = cylindrical capacitor
* -? = list of command line options
