// name: 임형근
// student ID: 20201261
// description: finds the best factor by which shapes are expanded such that they touch each other while not overlapping 

#include <iostream>
#include "shape.h"
#include "functions.h"

int main() {
    using namespace std;
    char input_shape_type[10];
    shape shape_arr[10];
    size_t arr_size = 0;

    while(true) {
        char type;
        double point_x, point_y, size_1, size_2;
        cin >> type;
        input_shape_type[arr_size] = type;
        switch(type) {
            case 'r':
                cin >> point_x >> point_y >> size_1 >> size_2;
                shape_arr[arr_size].type = shape_type::is_rectangle;
                shape_arr[arr_size].point[0] = point_x;
                shape_arr[arr_size].point[1] = point_y;
                shape_arr[arr_size].rectangle = {.width=size_1, .height=size_2};
                break;
            case 's':
                cin >> point_x >> point_y >> size_1;
                shape_arr[arr_size].type = shape_type::is_rectangle;
                shape_arr[arr_size].point[0] = point_x;
                shape_arr[arr_size].point[1] = point_y;
                shape_arr[arr_size].rectangle = {.width=size_1, .height=size_1};
                break;
            case 'c':
                cin >> point_x >> point_y >> size_1;
                shape_arr[arr_size].type = shape_type::is_circle;
                shape_arr[arr_size].point[0] = point_x;
                shape_arr[arr_size].point[1] = point_y;
                shape_arr[arr_size].circle = {.radius=size_1};
                break;
        }
        arr_size++;
        if(cin.eof()) {
            break;
        }
    }
    
    shape expanded_shape_arr[10];
    double factor = ideal_expansion_factor(shape_arr, arr_size);
    expand(shape_arr, arr_size, expanded_shape_arr, factor);
    cout << "Ideal expansion factor " << factor << endl;
    for (size_t i=0; i<arr_size; i++) {
        switch(input_shape_type[i]) {
            case 'r':
                cout << "r ";
                cout << expanded_shape_arr[i].point[0] << " ";
                cout << expanded_shape_arr[i].point[1] << " ";
                cout << expanded_shape_arr[i].rectangle.width << " ";
                cout << expanded_shape_arr[i].rectangle.height << endl;
                break;
            case 's':
                cout << "s ";
                cout << expanded_shape_arr[i].point[0] << " ";
                cout << expanded_shape_arr[i].point[1] << " ";
                cout << expanded_shape_arr[i].rectangle.width << endl;
                break;
            case 'c':
                cout << "c ";
                cout << expanded_shape_arr[i].point[0] << " ";
                cout << expanded_shape_arr[i].point[1] << " ";
                cout << expanded_shape_arr[i].circle.radius << endl;
                break;
        }
    }
    
    return 0;
}