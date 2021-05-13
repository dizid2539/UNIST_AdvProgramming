#include <iostream>

int main() {
    using namespace std;
    int x = 5;
    int z = 7;
    int* y = &x;
    int* w = &z;
    y = w;

    cout << x << " " << z << " " << y << " " << w << endl;
    cout << &x << " " << &z << endl;

    return 0;
}