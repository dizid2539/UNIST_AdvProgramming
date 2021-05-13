#include <iostream>
#include <string>
#include <climits>

int main() {
    using namespace std;
    int n;
    
    while (true) {
        cout << "Input an integer : " << flush;
        cin >> n;

        if (cin) {
            cout << "You entered : " << n << endl;
            break;
        }
        else {
            cin.clear();
            cin.ignore(SSIZE_MAX, '\n');
            cout << "You entered bad input" << endl;
        }
    }

    return 0;
}