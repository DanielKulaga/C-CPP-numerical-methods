#include <iostream>

using namespace std;
double static epsilon =  1e-8;

double funkcja(double x)
{
	return -x * x * x + 12 * x * x - 46 * x + 56;
}
double poch1(double x)
{
	return -3 * x * x + 24 * x - 46;
}

double metoda_falsi(double a, double b)
{
	double x = 0, fa = 0, fb = 0;
	double x1=0, xn, f;
	int counter = 0;
	fb = funkcja(b);
	fa = funkcja(a);

	//printf("wartosc x1: %d\n", x1);
	do {
		x1 = ((b * funkcja(a) - a * funkcja(b)) / (funkcja(a) - funkcja(b)));
		f = funkcja(x1);
		if (funkcja(b) * f > 0)
		{
			b = x1;
			fb = f;
			if (x == -1)
			{
				fa /= 2;
				x = -1;
			}
		}
		else if (fa * f > 0) {
			a = x1;
			fa = f;
			if (x == +1)
			{
				fb /= 2;
				x = +1;
			}
		}
		else {
			break;
		}counter++;

		

	} while ((abs(b - a)) > (1e-8 * abs(b + a)));

	printf("Ilosc iteracji: %d\n ", counter);
	return x1;
}
	double metoda_bisekcji(double a, double b)
	{
		double x1, x0 = 0;
		int counter = 0;
		while (abs(a - b) > epsilon)
		{
			x1 = ((a + b) / 2);
			if (funkcja(x1) == 0)
			{
				break;
			}
			else if ((funkcja(x1) * funkcja(a)) < 0)
			{
				b = x1;
			}
			else {
				a = x1;
			}
			counter++;
		}
		printf("Ilosc iteracji: %d\n", counter);
		return x1;
		
	}
double metoda_newtona(double xn)
{
	int counter = 0;

	double x1 = xn;
	while (abs(funkcja(x1)) > epsilon) {
		xn = x1 - funkcja(x1) / poch1(x1);
		x1 = xn;
		counter++;
	}
	printf("Iteracje: %d\n", counter);
	return x1;
}
int main()
{
	printf("Pierwsze miejsce zerowe: \n");
	printf("Regula falsi w przedziale <2.5, 3>\n");
	printf("Wartosc: %.8f\n", metoda_falsi(2.5, 3));
	printf("Metoda bisekcji w przedziale <2.5, 3>\n");
	printf("Wartosc: %.8f\n", metoda_bisekcji(2.5, 3));
	printf("Metoda Newtona dla x=2.5\n");
	printf("Wartosc: %.8f\n", metoda_newtona(2.5));
	
	printf("Drugie miejsce zerowe: \n");
	printf("Regula falsi w przedziale <3.1, 4.5>\n");
	printf("Wartosc: %.8f\n", metoda_falsi(3.1, 4.5));
	printf("Metoda bisekcji w przedziale <3.1, 4.5>\n");
	printf("Wartosc: %.8f\n", metoda_bisekcji(3.1, 4.5));
	printf("Metoda Newtona dla x=4.5\n");
	printf("Wartosc: %.8f\n", metoda_newtona(4.5));

	printf("Trzecie miejsce zerowe: \n");
	printf("Regula falsi w przedziale <5, 6>\n");
	printf("Wartosc: %.8f\n", metoda_falsi(5, 6));
	printf("Metoda bisekcji w przedziale <5, 6>\n");
	printf("Wartosc: %.8f\n", metoda_bisekcji(5, 6));
	printf("Metoda Newtona dla x=5\n");
	printf("Wartosc: %.8f\n", metoda_newtona(5));
	
	
	
	
	return 0;

}