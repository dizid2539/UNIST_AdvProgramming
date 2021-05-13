#include <iostream>

int main() {
    using namespace std;
    int x[] = {7,5,3,6,4,2};
    int* y= x+3;
    cout << y[-2] << " " << *y << endl;

    return 0;
}