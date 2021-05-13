// name: 임형근
// student ID: 20201261
// description: reads in temperatures and prints various statistics

#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>
#include "array.h"

int main() {
    using namespace std;
    double input[1000];
    size_t input_size = 0;

    while(1) {
        double input_buffer;
        cin >> input_buffer;

        if(cin) {
            input[input_size] = input_buffer;
        }
        else {
            input[input_size] = NAN;
            cin.clear();
            cin.ignore(SSIZE_MAX, '\n');
        }
        input_size++;

        if(cin.eof()) {
            break;
        }
    }

    cout << "Daily highs" << endl;
    cout << "===========" << endl;
    for(size_t i=0; i<input_size; i+=24) {
        cout <<  fixed << setprecision(3);
        cout << setw(12) << *maximum_value((input+i), (24 <= input_size-i ? 24 : input_size-i)) << endl;
    }

    cout << "\nSliding window 24-hour averages" << endl;
    cout << "===============================" << endl;
    for(size_t i=0; i<input_size; i++) {
        size_t start_pos;
        size_t len = 0;

        if(i <= 12) {
            start_pos = 0;
            len += i;
        }
        else {
            start_pos = i-12;
            len += 12;
        }
        if (i+11 >= input_size-1) {
            len += input_size-i-1;
        }
        else {
            len += 11;
        }
        len++;

        cout <<  fixed << setprecision(3);
        cout << setw(12) << input[i] << setw(12) << mean(input+start_pos, len) << endl;
    
    }

    cout << "\nOverall mean: ";
    cout << fixed << setprecision(3);
    cout << mean(input, input_size) << endl;

    *maximum_value(input, input_size) = NAN;
    cout << "Mean after removing the largest value: ";
    cout << fixed << setprecision(3);
    cout << mean(input, input_size) << endl;

    *maximum_value(input, input_size) = NAN;
    cout << "Mean after removing the 2 largest values: ";
    cout << fixed << setprecision(3);
    cout << mean(input, input_size) << flush;

    return 0;
}