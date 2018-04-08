#include <stdio.h>
#include <float.h>
#include <math.h>
#include <errno.h>
#include <limits.h>

#include "eingabe.h"
#include "xmath.h"

void xpow_tests(void);

int main(void)
{
	double d1;
	
	xpow_tests();
	
	printf("Eingabe des ersten Parameters fuer alle Funktionen\n");
	printf("(Programmabbruch durch Falscheingabe): ");

	d1 = einlesen();

	while (d1 != DBL_MIN && d1 != DBL_MAX) {
		double d2;
		printf("xceil(%f) = %f\n", d1, xceil(d1));
		printf("xfabs(%f) = %f\n", d1, xfabs(d1));
		printf("\nEingabe des zweiten Parameters fuer xpow\n");
		printf("(Berechnungsabbruch durch Falscheingabe): ");
		d2 = einlesen();
		while (d2 != DBL_MIN && d2 != DBL_MAX) {
			int i = d2;
			printf("xpow(%f, %i) = %e\n", d1, i, xpow(d1, i));
			printf("errno: %i\n", errno);
			printf("\nEingabe des zweiten Parameters fuer xpow\n");
			printf("(Berechnungsabbruch durch Falscheingabe): ");
			d2 = einlesen();
		}
		printf("\nEingabe des ersten Parameters fuer alle Funktionen\n");
		printf("(Programmabbruch durch Falscheingabe): ");
		d1 = einlesen();
	}
	return 0;
}

void xpow_tests(void)
{
	printf("XPOW TESTS (SUCCESS == 1 / FAILURE == 0)\n");
	printf("=================================================\n");
	printf("Test (xpow(2, 6)): \t\t%i\t", xpow(2, 6) == pow(2, 6));
	xpow(2, 6);
	printf("errno: %i\n", errno);
	printf("Test (xpow(-2, -3)): \t\t%i\t", xpow(-2, -3) == pow(-2, -3));
	xpow(-2, -3);
	printf("errno: %i\n", errno);
	printf("Test (xpow(1, 17)): \t\t%i\t", xpow(1, 17) == pow(1, 17));
	xpow(1, 17);
	printf("errno: %i\n", errno);
	printf("Test (xpow(0, -2)): \t\t%i\t", xpow(0, -2) == 0);
	xpow(0, -2);
	printf("errno: %i\n", errno);
	printf("Test (xpow(-3, 647)): \t\t%i\t", xpow(-3, 647) == pow(-3, 647));
	xpow(-3, 647);
	printf("errno: %i\n", errno);
	printf("Test (xpow(-5, 442)): \t\t%i\t", xpow(-5, 442) == pow(-5, 442));
	xpow(-5, 442);
	printf("errno: %i\n", errno);
	printf("Test (xpow(-101, INT_MAX)): \t%i\t", xpow(-101, INT_MAX) == pow(-101, INT_MAX));
	xpow(-101, INT_MAX);
	printf("errno: %i\n", errno);
	printf("Test (xpow(-101, INT_MAX-1)): \t%i\t", xpow(-101, INT_MAX-1) == pow(-101, INT_MAX-1));
	xpow(-101, INT_MAX-1);
	printf("errno: %i\n", errno);
	printf("Test (xpow(-101, -INT_MAX)): \t%i\t", xpow(-101, -INT_MAX) == pow(-101, -INT_MAX));
	xpow(-101, -INT_MAX);
	printf("errno: %i\n", errno);
	printf("Test (xpow(-101, -INT_MAX+1)): \t%i\t", xpow(-101, -INT_MAX+1) == pow(-101, -INT_MAX+1));
	xpow(-101, -INT_MAX+1);
	printf("errno: %i\n", errno);
	printf("=================================================\n");
	printf("errno (EDOM: %i / ERANGE: %i)\n\n", EDOM, ERANGE);

}
