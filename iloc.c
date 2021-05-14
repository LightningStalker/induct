/*
 *   iloc.c -- Air-core coil design program
 *
 *         compile with:  cc -Wall -o iloc iloc.c -lm
 *
 *  Copyright (c) 2000, Eddie Kovelan and Sam Goldwasser
 *  Dvoracek (c)2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define u 1.2566370621219E-6 // permeability of free space

int main()
{
  /*
   *    L = inductance in microhenries,
   *  DIA = diameter of coil.
   *  NOT = Number Of Turns
   *    A = area of cross section
   *   TS = turn spacing
   * imed = intermediate temp variable
   */

  long double L, DIA, A, length, TS, NOT, imed;

  printf("\n \
    **********************************************************\n \
    *  This program finds the required number of turns and   *\n \
    *  length for an air-core inductor with specified        *\n \
    *  inductance (uH), radius (mm), and turn spacing (mm).  *\n \
    *  Valid for coils where diameter = length or longer.    *\n \
    **********************************************************\n");

  printf("\nEnter inductance (uH): ");
  scanf("%Lf", &L);
  printf("Enter diameter of coil (mm): ");
  scanf("%Lf", &DIA);
  printf("Enter turn spacing (mm per turn): ");
  scanf("%Lf", &TS);

  /* calculation of NOT (Number Of Turns) */
  // first some unit conversion
  L = L / 1000000;  // H --> µH
  DIA = DIA / 1000; // m --> mm
  TS = TS / 1000;   // m --> mm

  // Meet the meat
  A = M_PI * powl(DIA / 2, 2);
  imed = L * (1 / u) / A;
  NOT = imed * TS;
  length = NOT * TS * 1000;

  //The coil shall be 2.138090 in length (inches) and have 4.209364 turns.
  printf("\nThe coil shall be %.1Lf mm in length and have %.1Lf turns.\n\n", length, NOT);
}
