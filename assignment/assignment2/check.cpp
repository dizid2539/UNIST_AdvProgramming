// name: 임형근
// student ID: 20201261
// description: unit tests for factorial and probability function

#include <iostream>
#include <cmath>
#include "functions.h"

#define TEST(test_case, supposed_output, error_range) \
        if(abs((test_case)-(supposed_output)) > error_range) { \
            cerr << #test_case << " failed on line " << __LINE__ << endl; \
            INTEGRITY_FLAG = false; \
        }

int main() {
    using namespace std;
    bool integrity_flag = true;
    #define INTEGRITY_FLAG integrity_flag

    TEST(factorial(-1), 1.0, 0)
    TEST(factorial(0), 1.0, 0)
    TEST(factorial(1), 1.0, 0)
    TEST(factorial(12), 479001600.0, 0)

    TEST(probability(12, 1), 0.0, 0.0001)
    TEST(probability(12, 6), 0.777199074, 0.0001)
    TEST(probability(12, 12), 0.999946277, 0.0001)
    TEST(probability(1, 1), 0.0, 0.0001)
    TEST(probability(100, 100), 1.0, 0.0001)

    if (integrity_flag){
        cout << "All tests passed" << endl;
    }

    return 0;
}