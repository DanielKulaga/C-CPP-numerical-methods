#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define _USE_MATH_DEFINES
#include <cmath>

const double e = 0.0000000001;

double funkcja(double x) {
	double cCos = 0.0;
	cCos = cos(x);
	return (exp(cCos * cCos));
}

double f(const double S1, double S2, double h) {
	return (h * (0.5 * S1 + S2));
}
int main() {
	double ostatni_I = 0.0;
	double N = 1.0;
	double b = M_PI;
	double a = 0.0;
	double h = b - a;
	double res;
	int i = 0;
	const double S1 = funkcja(a) + funkcja(b);
	double S2 = 0.0;
	res = f(S1, S2, h);
	ostatni_I = res;
	while (1) {
		i++;
		h /= 2;
		for (int j = 0; j < N; j++) {
			S2 += funkcja(a + (2 * j + 1) * h);
		}
		res = f(S1, S2, h);
		printf("%d %.10f \n", i, res);
		N *= 2;
		if (fabs(ostatni_I - res) < e) break;
		ostatni_I = res;
	}
	return 0;
}