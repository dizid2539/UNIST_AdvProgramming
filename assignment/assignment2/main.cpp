// name: 임형근
// student ID: 20201261
// description: reads in k and print probabilities in (k,n) where 1<=n<=k

#include <iostream>
#include <iomanip>
#include <cmath>
#include "functions.h"
#define DIGIT(n) (int)(log10(round(((n)>=1.0?(long double)(n):1.0L)*powl(10,7))))+1

int main() {
    using namespace std;
    int k;
    
    cin >> k;
    if(cin && k>=1) {
        double *p = new double[k];
        for (int i=1; i<=k; i++){
            p[i-1] = probability(k, i) * 100.0;
        }

        int ndigit = (int)log10(k)+1;
        int pdigit = DIGIT(p[k-1]);
        for (int i=1; i<=k; i++){
            int idigit = DIGIT(p[i-1]);

            cout << setw(ndigit) << right << i;
            for (int j=0; j<pdigit-idigit+1; j++){
                cout << " ";
            }
            cout << fixed << setprecision(7) << p[i-1] << endl;
        }

        delete[] p;
    }

    return 0;
}