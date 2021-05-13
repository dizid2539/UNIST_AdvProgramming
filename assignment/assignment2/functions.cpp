// name: 임형근
// student ID: 20201261
// description: defines factorial and probability function

#include <cmath>

double factorial(int x) {
    double result = 1.0;

    for(int i=1; i<=x; i++) {
        result *= (double)i;
    }

    return result;
}

double probability(int k, int n) {
    return 1.0-(factorial(k)/(pow(k,n)*factorial(k-n)));
}