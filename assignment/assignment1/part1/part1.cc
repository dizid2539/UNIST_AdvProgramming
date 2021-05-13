// name: 임형근
// student ID: 20201261
// description: print largest number among 3 inputs

#include <iostream>
#include <climits>

int main() {
    using namespace std;
    long a;
    double b, c;
    int anw = 0;
    bool is_a_good = true, is_b_good = true, is_c_good = true;

    cin >> a;
    if (!cin){
        is_a_good = false;
        cin.clear();
    }
    cin.ignore(SSIZE_MAX, '\n');
    cin >> b;
    if (!cin){
        is_b_good = false;
        cin.clear();
    }
    cin.ignore(SSIZE_MAX, '\n');
    cin >> c;
    if (!cin){
        is_c_good = false;
        cin.clear();
    }
    cin.ignore(SSIZE_MAX, '\n');

    if (is_a_good){
        if (is_b_good){
            anw = (a >= b ? 1 : 2);
        }
        if (is_c_good){
            anw = (a >= c ? 1 : 3);
        }
        if (!is_b_good && !is_c_good){
            anw = 1;
        }
    }
    if (anw != 1){
        if (is_b_good && is_c_good){
            anw = (b >= c ? 2 : 3);
        }
        else if (is_b_good){
            anw = 2;
        }
        else if (is_c_good){
            anw = 3;
        }
    }

    switch (anw)
    {
        case 1:
            cout << a << endl;
            break;

        case 2:
            cout << b << endl;
            break;

        case 3:
            cout << c << endl;
            break;
        
        default:
            cout << "Bad input for all 3 values" << endl;
            break;
    }

    return 0;
}
