# induct
Calculators and utilities for real-world electronic design

## iloc
iloc.c is a very simple calculator program for designing single layer air coils,
including space wound coils having a length equal to or greater than their
diameter. For single turn inductances and short coils, I encourage you to
consult the fine work of the late Nagaoka who published tables and formulas for
his correction coefficient. This was not a concern for the scope of this simple
calculator as such inductances are not seen or desirable outside of antenna
systems or above UHF frequencies. I may decide to revisit this should the need
arise.

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

Some credit is due to Samuel Goldwasser et al. whom distribute the coil.c which
is used as a template to provide ui and output formatting.

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
