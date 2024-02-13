#include <stdio.h>
#include <math.h>

double f(double x, double a) {
    double w;
    w = 1 + atan(exp(- x * x)) * atan(exp(- x * x));
    return a - sin(1 / w);
}

double solve(double x, double eps, double a, int n, int *steps);
double solve(double x, double eps, double a, int n, int *steps) {
    double y;
    int i;
    y = f(x, a);
    for(i = 0; i < n && fabs(y - x) > eps && fabs(y - x) > eps*fabs(y); i++) {
        x = y;
        y = f(x, a);
    }
    *steps = i;
    return y;
}

int main(void) {
    int steps, n = 1000;
    int x0 = -1000;
    double d;
    double min, max;
    double y0, y;
    double x = 500, a = 1, eps = 1.e-9, w;
    y = solve(x, eps, a, n, &steps);
    printf("x = %f\n", x);
    printf("a = %f\n", a);
    printf("y = %.12f\n", y);
    printf("Steps = %d\n", steps);
    w = 1 + atan(exp(- y * y)) * atan(exp(- y * y));
    printf("f = %.12f\n", a - sin(1 / w) - y);
    y0 = solve(x0, eps, a, n, &steps);
    min = y0;
    max = y0;
    x0 += 1;
    
    while (x0 <= 1000) {
        y0 = solve(x0, eps, a, n, &steps);
        if (y0 > max) max = y0;
        if (y0 < min) min = y0;
        x0 += 1;
    }
    
    d = max - min;
    printf("d = %.12f\n", d);
    return 0;
}
