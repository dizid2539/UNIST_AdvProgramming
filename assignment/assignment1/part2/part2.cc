// name: 임형근
// student ID: 20201261
// description: print square numbers within given range

#include <iostream>
#include <climits>

int main() {
    using namespace std;
    unsigned int range[2];

    for (int i=0; i<2; i++){
        while (true) {
            cin >> range[i];
            if (cin) {
                break;
            }
            else {
                cin.clear();
                cin.ignore(SSIZE_MAX, '\n');
            }
        }
    }

    for (unsigned int i=1; ; i++){
        unsigned int square = i * i;
        if (square > range[1]){
            break;
        }
        if (square >= range[0]){
            cout << square << endl;
        }
    }

    return 0;
}