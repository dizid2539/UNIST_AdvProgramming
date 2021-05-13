#include <iostream>

// submit part
double avg(double x, double y) {
    return (x+y)/2.0;
}
// submit part

int main() {
    double a, b;
    using namespace std;

    cin >> a;
    cin >> b;
    cout << avg(a, b) << endl;

    return 0;
}