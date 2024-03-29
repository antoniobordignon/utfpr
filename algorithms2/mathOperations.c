#include <stdio.h>

int multiplica (int x1, int x2) {
    return x1 * x2;
}

int quadrado(int x) {
    return x * x;
}

int cubo (int x) {
    return x * x * x;
}

int pol_cubo(int a, int b, int c, int d, int x) {
    return a*x*x*x + b*x*x + c*x + d;
}