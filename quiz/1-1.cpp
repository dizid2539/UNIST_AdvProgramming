#include <iostream>

int main() {
    int x = 7;
    int y = -6;
    using namespace std;

    if (x > 0) {
        if (y > 0) {
            cout << "Both are positive" << endl;
        }
        else {
            cout << "Only one is positive" << endl;
        }
    }
    else {
        if (y > 0) {
            cout << "Only one is positive" << endl;
        }
        else {
            cout << "None are positive" << endl;
        }
    }

    return 0;
}