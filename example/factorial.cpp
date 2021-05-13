#include <iostream>
#include <iomanip>  // for setw()

int factorial(int n) {
    int anw = 1;
    for (int i=1; i<=n; i++) {
        anw *= i;
    }
    return anw;
}

int main() {
    using namespace std;
    int max_n;
    cout << "factorial 0 to : " << flush;
    cin >> max_n;

    for (int i=0; i<=max_n; i++) {
        cout << setw(3) << i << " : " 
             << setw(11) << factorial(i) << endl;
    }

    return 0;
}