#include <iostream>

using namespace std;
int const n = 5;
double const epsilon = 1e-8;

//double norma(double x[])
//{
//	int norm = 0;
//	double xn;
//	for (int i = 0; i < 3; i++)
//	{
//		xn = x[i] * x[i];
//		norm += xn;
//	}
//	return sqrt(norm);
//	
//}

int main()
{


	//macierz A
	double A[3][3] = { 4, -1, 0,
					  -1, 4, -1,
					   0, -1, 4};
	//wektor b
	double b[3] = { 2, 6 , 2 };
	double x[3] = { 0 , 0 ,0 };
	//double xn[3] = { 0,0,0 };
	double r[3] = { 2 , 6 ,2 };
	double p[3] = { 2 , 6 , 2};
	double r_r[3];
	double p_p[3];
	double alfa;
	double beta;
	int counter = 1;
	
	
	
	
	while (counter<n){//while (norma(x) -norma(xn)) < epsilon) {
 
		alfa = (r[0] * r[0] + r[1] * r[1] + r[2] * r[2]) /
			((p[0] * A[0][0] + p[1] * A[0][1] + p[2] * A[0][2]) * p[0] +
			(p[0] * A[1][0] + p[1] * A[1][1] + p[2] * A[1][2]) * p[1] +
				(p[0] * A[2][0] + p[1] * A[2][1] + p[2] * A[2][2]) * p[2]);

		for (int i = 0; i < 3; i++) {
			x[i] = x[i] + alfa * p[i];
		}

		for (int i = 0; i < 3; i++) {
			r_r[i] = r[i] - ((A[0][i] * p[0] + A[1][i] * p[1] + A[2][i] * p[2]) * alfa);
		}

		beta = (r_r[0] * r_r[0] + r_r[1] * r_r[1] + r_r[2] * r_r[2]) /
			(r[0] * r[0] + r[1] * r[1] + r[2] * r[2]);

		for (int i = 0; i < 3; i++) {
			p[i] = r_r[i] + beta * p[i];

			r[i] = r_r[i];
		}

	
		 
	   counter++;
		
	}

	for (int i = 0; i < 3; i++) {
		printf("%.8f\n",x[i]);

	}
	
	return 0;
}


