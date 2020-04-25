#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x, double k){
    return k*x*(1-x);
}

int main(){

    FILE *solutions;

    double x = 0.5;
    int n;

    if ((solutions = fopen("solutions.txt", "w")) == NULL) {
        printf ("Blad tworzenia dokumentu!\n");
    }



    for (double i = 2; i <= 4; i+=0.002) {
        n = 100;
        while (n < 1000)
        {
            x = f(x, i);
            fprintf(solutions, "%.3f %.20f\n", i, x);
            n++;
        }
    }
    fclose(solutions);
    return 0;
}