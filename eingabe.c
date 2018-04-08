#include "eingabe.h"
#include <stdio.h>
#include <float.h>

double einlesen(void)
{
	int status;
	double wert;
	char c;

	status = scanf("%lf", &wert);
	if (status == EOF) {
		return DBL_MIN;
	} else if (status == 0) {
		if (!leeren()) {
			return DBL_MIN;
		}
		return DBL_MAX;
	}
	c = getchar();
	if (c == EOF) {
		return DBL_MIN;
	} else if (c != '\n') {
		if (!leeren()) {
			return DBL_MIN;
		}
		return DBL_MAX;
	}
	if (wert == DBL_MIN || wert == DBL_MAX) {
		return DBL_MAX;
	}
	return wert;
}

int leeren(void)
{
	int c;

	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
	return c != EOF;
}
