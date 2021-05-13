#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>

double* binary_search(double* arr, size_t arr_size, double target) {
    size_t midpoint = (size_t)(arr_size/2);

    if(arr_size == 0) {
        return nullptr;
    }

    if(arr[midpoint] == target) {
        return &arr[midpoint];
    }
    else if (arr[midpoint] > target) {
        return binary_search(arr, midpoint, target);
    }
    else {
        return binary_search(&arr[midpoint+1], arr_size-midpoint-1, target);
    }
}

int main() {
    using namespace std;
    double arr[] = {1,2,3,4,5,6,7,8,9};
    double target;

    cout << "target : ";
    cin >> target;
    double *search = binary_search(arr, sizeof(arr)/sizeof(arr[0]), target);
    if(search == nullptr) {
        cout << "not found" << endl;
    }
    else {
        cout << "index : " << search - arr << endl;
    }

    return 0; 
}