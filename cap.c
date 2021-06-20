 /* Simple capacitor plate area calculator
  * compile with cc -Wall -o cap cap.c -lm
  * 2021 The Lightning Stalker
  */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define e 0.08854187812813 // ɛ - electric constant with cm/pF conversion

double roundval(long double inval)
// round to 2 decimal places
{
  int i;
  i = (int)(inval * 100 + .5);
  return (double)i / 100;
}

void plate()
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

   // input section
   puts("Plate type");
   printf("Enter target capacitance (pF): ");
   scanf("%Lf", &C);
   printf("Enter spacing or depth of dielectric material (cm): ");
   scanf("%Lf", &d);
   printf("Enter dielectric K constant of dielectric material: ");
   scanf("%Lf", &K);

   // begin formulas
   i = e * K;
   A = C * d / i;
   i = sqrt(A);
   l = roundval(i);
   i = roundval(A);
   // end formulas

   // output section
   printf("\nThe capacitor area shall be %.2Lf cm² as in a square\nhaving %.2Lf cm length sides.\n\n", i, l);
}

void cylinder()
{
  // variable declarations
  long double C, R1, R2, K, l, i;

  /*   C = desired capacitance
   *   R1 = inner diametr of dielectric
   *   R2 = outer diameter of dielectric
   *   K = dielectric constant
   *   l = length of capacitor
   *   i = intermediate temp variable
   */

   // input section
   puts("cylinder type");
   printf("Enter target capacitance (pF): ");
   scanf("%Lf", &C);
   printf("Enter inner diameter of dielectric (cm): ");
   scanf("%Lf", &R1);
   printf("Enter outer diameter of dielectric (cm): ");
   scanf("%Lf", &R2);
   printf("Enter dielectric K constant of dielectric material: ");
   scanf("%Lf", &K);

   // begin formulas
   i = logl(R2 / R1);
   l = (C * i) / (2 * M_PI * e * K);
   i = roundval(l);
   // end formulas

   // output section
   printf("\nThe capacitor shall be %.2Lf cm in length.\n\n", i);
}

void usage()
{
  puts("\
  Valid options are:\n \
    \n \
    -p = square flat plate type (default)\n \
    -c = cylinder type.\n \
    -? = this usage text\
  \n");
}

int main(int argc, char *argv[])
{
  // variable declarations
  char c;

  // boiler plate
  puts("\n \
  cap is a capacitor calculator.\n \
  cap will find dimensions of the conductors for a capacitor given the target\n \
  capacitance, thickness and K constant of the dielectric material.\n \
  Enter 'cap -?' for a list of command line options.\n \
  \n");

  // get options passed at the command line
  c = getopt(argc, argv, "pc?");
		switch(c)
		{
      case -1: // Detect the end of the options.
        plate();
        break;
			case 'p':
				plate(); // plate type
				break;
			case 'c':
				cylinder(); //cylinder type
				break;
			case '?':
				usage(1);
				break;
			default:
				printf ("?? invalid option 0%o ??\n", c);
				break;
		}
    exit(0);
}
