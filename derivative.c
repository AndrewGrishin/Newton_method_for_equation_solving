#include <stdio.h>
#include <math.h>

typedef double (*func)(double);

double f(double x){
    return (x - pow(M_E,M_PI));
}

double derivative(func f, double x){
    double delta = 1E-8;
    double a = f(x + delta);
    double b = f(x);
    double c = a - b;
    double slope = c / delta;
    return slope;
}

double findRoots(func f){
    double x = 0.1;

    for (int i = 0; i < (int)1E15; i++){
        x -= f(x) / derivative(f,x);
    }

    return x;
}

int main()
{
    fprintf(stdout,"The root of the function: %lf.\n",findRoots(f));
    return 0;
}