#include <ieee754.h>
#define LOG2_10 3.321928095 // conversion factor from base-2 logs to base-10 logs --> used to calculate the order of magnitude of the nbr in base 10 from its bin notation
#define EPSILON 0.00000011929093 // epsilon is the smallest x | 1 + x > 1
#define flt_zero(x) (fabs(x) < EPSILON) // to check if a floating pt is effectively zero
 
int max_digs_rt = 3;  /* maximum # of 0's right of decimal before using
                         scientific notation */
int max_digs_lf = 5;  /* max # of digits left of decimal */
 
void print_real(double r, int width, int dec) // with width = the min total chars on the output & dec = the nbr of decimal places
{
    int mag; // = magnitude of r 
    double fpart, temp; // fpart = fract part 
    char format[8];
    char num_format[3] = {'l',0,0};
    union ieee754_double *dl; // ieee754_double = standard layout of a double --> allows access to the raw bits of the float
 
    dl = (union ieee754_double*)&r; // typecast r to its raw bit notation
    mag = (dl->ieee.exponent - IEEE754_DOUBLE_BIAS) / LOG2_10; // extracting the magnitude of r
    if (r == 0)
        mag = 0;
    if ((mag > max_digs_lf-1) || (mag < -max_digs_rt)) { // deciding on the format depending on if the tresholds are exceeded
        num_format[1] = 'e'; // scientific notation
        temp = r/pow(10, mag);      /* see if number will have a decimal */
        fpart = temp - floor(temp); /* when written in scientific notation */
    }
    else {
        num_format[1] = 'f'; // fixed-point notation
        fpart = r - floor(r);
    }
    if (flt_zero(fpart)) // if fract < epsilon then reduced to 0
        dec = 0;
    if (width == 0) {
        snprintf(format, 8, "%%.%d%s", dec, num_format);
    }
    else {
        snprintf(format, 8, "%%%d.%d%s", width, dec, num_format);
    }
    printf(format, r);
}