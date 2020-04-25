#include <iostream>
#include <stdio.h>
#include <fstream>
#include <math.h>


using namespace std;

int const N = 51;
double const h = 1.0 / N;
double const H = (1.0 / (h * h));

int main()
{
	double wek_f[N];
	double wspol_c[N];
	double wspol_d[N];
	double wek_y[N];
	double diagA[N];
	double diagB[N];
	double diagC[N];

	diagC[0] = 0;
	//wypelnienie jedynkami diagonali c 
	for (int i = 1; i < N - 1; i++)
	{
		diagC[i] = 1.0;
	}


	diagC[N - 1] = 0;
	diagA[N - 1] = 0;
	// diagonala a po wyciagnieciu 1/h^2 przed macierz
	diagA[0] = 0;
	for (int i = 1; i < N - 1; i++)
	{
		diagA[i] = 1.0;
	}

	
	
	

	 
	//wstawianie do diagonali B
	for (int i = 1; i < N - 1; i++)
	{
		diagB[i] = -2.0;
	}

	diagB[0] = (1.0/ (H));
	diagB[N - 1] = (1.0/(H));
	



	

	for (int i = 0; i <= N - 1; i++)
	{
		if (i == N - 1)
			wek_f[i] = 1.0;
		else
			wek_f[i] = 0;
	}

	wspol_c[0] = 0;

	for (int i = 1; i <= N - 1; i++)
	{
		wspol_c[i] = diagC[i] / (diagB[i] - (diagA[i] * wspol_c[i - 1]));
	}

	wspol_d[0] = 0;

	for (int i = 1; i <= N - 1; i++)
	{
		wspol_d[i] = (wek_f[i] - (diagA[i] * wspol_d[i - 1])) / (diagB[i] - (diagA[i] * wspol_c[i - 1]));
	}

	wek_y[N - 1] = wspol_d[N - 1] * (1.0/H);

	for (int i = N - 2; i >= 0; i--)
	{
		wek_y[i] = (wspol_d[i] - (wspol_c[i] * wek_y[i + 1])) ;
	}

	
	//wydrukowanie wynikow
	for (int i = 0; i <= N - 1; i++)
	{
		printf("%f \n", wek_y[i]);
	}
	printf("\n\n%f, %f \n", diagB[0], diagB[N - 1]);
	
	   
	return 0;
}

