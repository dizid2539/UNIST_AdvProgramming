// name: 임형근
// student ID: 20201261
// description: reads in two RNA sequences and finds the best alignment

#include <iostream>
#include "functions.h"

#define INPUT_SIZE 1000

int main() {
    using namespace std;
    char seq_1[INPUT_SIZE], seq_2[INPUT_SIZE];
    size_t seq_1_size = 0, seq_2_size = 0;

    for(size_t i=0; i<INPUT_SIZE; i++) {
        int input;
        bool is_input_valid = true;

        cin >> input;
        if(!cin) {
            is_input_valid = false;
        }
        else if(input < 0 || input > 3) {
            if (input == -1) {
                break;
            }
            else {
                is_input_valid = false;
            }
        }
        if(!is_input_valid) {
            cerr << "Bad input" << endl;
            return 1;
        }
        seq_1[seq_1_size] = input;
        seq_1_size++;
    }
    for(size_t i=0; i<INPUT_SIZE; i++) {
        int input;
        bool is_input_valid = true;

        cin >> input;
        if(!cin) {
            is_input_valid = false;
        }
        else if(input < 0 || input > 3) {
            if (input == -1) {
                break;
            }
            else {
                is_input_valid = false;
            }
        }
        if(!is_input_valid) {
            cerr << "Bad input" << endl;
            return 1;
        }
        seq_2[seq_2_size] = input;
        seq_2_size++;
    }

    long shift;
    int best_score = best_alignment(seq_1, seq_1_size, seq_2, seq_2_size, &shift);
    cout << "Best score: " << best_score << endl;
    cout << "Best alignment:" << endl;
    if(shift < 0) {
        for(int i=0; i<shift*-1; i++) {
            cout << "  ";
        }
    }
    for(size_t i=0; i<seq_1_size; i++){
        cout << (int)(seq_1[i]) << " ";
    }
    cout << endl;
    if(shift > 0) {
        for(int i=0; i<shift; i++) {
            cout << "  ";
        }
    }
    for(size_t i=0; i<seq_2_size; i++){
        cout << (int)(seq_2[i]) << " ";
    }
    cout << endl;

    return 0;
}