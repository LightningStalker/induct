 /* Simple capacitor plate area calculator
  * compile with cc -Wall -o cap cap.c -lm
  * 2021 The Lightning Stalker
  */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define e 0.08854187812813 // ɛ - electric constant with cm/pF conversion

int main()
{
  // variable declarations
  long double C, d, A, K, l, i;

  /*   C = desired capacitance
   *   d = depth of dielectric material (thickness)
   *   A = plate area
   *   K = dielectric constant
   *   l = length of sides of a square plate
   *   i = intermediate temp variable
   */

  // boiler plate
  puts("\n \
    cap is a capacitor calculator.\n \
    cap will find area and side length of square plates for a capacitor given\n \
    the target capacitance, thickness and K constant of the dielectric\n \
    material.\n \
    \n");

  // input section
  printf("Enter target capacitance (pF): ");
  scanf("%Lf", &C);
  printf("Enter spacing or depth of dielectric material (cm): ");
  scanf("%Lf", &d);
  printf("Enter dielectric K constant of dielectric material: ");
  scanf("%Lf", &K);

  // begin formulas
  i = e * K;
  A = C * d / i;
  l = sqrt(A);
  // end formulas

  // output section
  printf("\nThe capacitor area shall be %.1Lf cm² as in a square having %.1Lf cm length sides.\n\n", A, l);
}
