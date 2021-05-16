 /* Simple solenoidal air coil calculator
  * compile with cc -Wall -o iloc iloc.c -lm
  * 2021 The Lightning Stalker
  */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define u 1.2566370621219E-6 // µ - permeability of free space

int main()
{
  // variable declarations
  long double L, D, A, TS, l, N, i;

  /*   L = target inductance
   *   D = diameter in mm
   *   A = area of cross section
   *  TS = turn spacing
   *   l = length of coil in mm
   *   N = turns count
   *   i = intermediate temp variable
   */

  // boiler plate
  puts("\n \
    iloc is a coil calculator.\n \
    iloc will find turns count and length of a coil given the target\n \
    inductance, desired diameter, and turns spacing (pitch).\n \
    \n");

  // input section
  printf("Enter target inductance (µH): ");
  scanf("%Lf", &L);
  printf("Enter desired coil diameter (mm): ");
  scanf("%Lf", &D);
  printf("Enter turn spacing (mm per turn): ");
  scanf("%Lf", &TS);

  // begin formulas
  // first some unit conversion
  L = L / 1000000; // H --> µH
  D = D / 1000;    // m --> mm
  TS = TS / 1000;  // m --> mm

  // Meet the meat
  A = M_PI * powl(D / 2, 2); // M_PI = Pi
  i = L * (1 / u) / A;
  N = i * TS;
  l = N * TS * 1000;
  // end formulas

  // output section
  printf("\nThe coil shall be %.1Lf mm in length and have %.1Lf turns.\n\n", l, N);
}
