// name: 임형근
// student ID: 20201261
// description: declares mean and maximum_value function

#include <cmath>
#include <cstddef>
#include <iostream>

double mean(double const *arr, size_t arr_size) {
    double sum = 0.0, valid_num = 0.0;
    for(size_t i=0; i<arr_size; i++) {
        if(!std::isnan(arr[i])) {
            sum += arr[i];
            valid_num += 1.0;
        }
    }

    return sum/valid_num;
}

double *maximum_value(double *arr, size_t arr_size) {
    size_t largest_index;
    size_t i;
    
    for(i=0; i<arr_size; i++) {
        if(!std::isnan(arr[i])) {
            break;
        }
    }
    if(i == arr_size) {
        return nullptr;
    }
    largest_index = i;

    for(i++; i<arr_size; i++) {
        if(!std::isnan(arr[i])) {
            if(arr[i] > arr[largest_index]) {
                largest_index = i;
            }
        }
    }

    return &arr[largest_index];
}