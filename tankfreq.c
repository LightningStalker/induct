/* Compile with gcc -Wall -o tankfreq tankfreq.c -lm */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    if (argc == 3)
    {
        printf ("%f\n", 1 / (3.14159265358979324 * 2 * sqrt (atof(argv[1]) /
            1000000 * atof(argv[2]) / 1000000)));
        return (0);
    }
    else
    {
        puts ("tankfreq is an LC tank resonance frequency calculator.");
        puts ("output is frequency in Hz\n");
        puts ("Usage: tankfreq microfarads microhenries");
        puts ("Example: tankfreq 3.3 .86207");
        puts ("Output should be: 94360.861167");
        return (1);
    }
}
