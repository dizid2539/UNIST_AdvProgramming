#include <cstddef>
#include "shape.h"

static double abs(double a) {return (a>=0 ? a : -a);}

// dist: calculates the distance between two points
static double dist(const double *point1, const double *point2) {
    double delta_x = point1[0]-point2[0];
    double delta_y = point1[1]-point2[1];
    double distance = delta_x*delta_x + delta_y*delta_y;

    const size_t ITER = 40;
    double start_point;
    double end_point;
    double mid_point;
    if(distance >= 1) {
        start_point = 1;
        end_point = distance;
    }
    else {
        start_point = distance;
        end_point = 1;
    }
    for(size_t i=0; i<ITER; i++) {
        mid_point = (start_point+end_point)/2;
        if(mid_point*mid_point > distance) {
            end_point = mid_point;
        }
        else {
            start_point = mid_point;
        }
    }

    return mid_point;
}

// overlap_circle_rectangle: determines if a circle and a rectangle overlap each other
// more accurate circle-rectangle overlap judgement than original one
static bool overlap_circle_rectangle(shape const &circle, shape const &rectangle) {
    double rectangle_vertices[4][2] = {0, 0, 1, 0, 0, 1, 1, 1};
    double circle_vertices[5][2] = {0, 0, 1, 0, 0, 1, -1, 0, 0, -1};
    for(size_t i=0; i<4; i++) {
        rectangle_vertices[i][0] = rectangle.point[0] + rectangle_vertices[i][0]*rectangle.rectangle.width;
        rectangle_vertices[i][1] = rectangle.point[1] + rectangle_vertices[i][1]*rectangle.rectangle.height;
    }
    for(size_t i=0; i<5; i++) {
        circle_vertices[i][0] = circle.point[0] + circle_vertices[i][0]*circle.circle.radius;
        circle_vertices[i][0] = circle.point[0] + circle_vertices[i][0]*circle.circle.radius;
    }

    for(size_t i=0; i<4; i++) {
        if(circle.circle.radius >= dist(circle.point, &rectangle_vertices[i][0])) {
            return true;
        }
    }
    for(size_t i=0; i<5; i++) {
        if((rectangle.point[0] <= circle_vertices[i][0]) && 
            (rectangle.point[0]+rectangle.rectangle.width >= circle_vertices[i][0]) &&
            (rectangle.point[1] <= circle_vertices[i][1]) && 
            (rectangle.point[1]+rectangle.rectangle.height >= circle_vertices[i][1])) {
            return true;
        }
    }
    if((abs(rectangle.point[0]-circle.point[0]) <= circle.circle.radius)) {
        if((rectangle.point[1] <= circle.point[1]) && 
            (rectangle.point[1]+rectangle.rectangle.height >= circle.point[1])) {
            return true;
        }
    }
    if((abs(rectangle.point[1]-circle.point[1]) <= circle.circle.radius)) {
        if((rectangle.point[0] <= circle.point[0]) && 
            (rectangle.point[0]+rectangle.rectangle.width >= circle.point[1])) {
            return true;
        }
    }
    return false;
}

bool overlap(shape const &shape1, shape const &shape2) {
    if((shape1.type == shape_type::is_circle) && (shape2.type == shape_type::is_circle)) {
        return ((shape1.circle.radius + shape2.circle.radius) >= dist(shape1.point, shape2.point));
    }
    if((shape1.type == shape_type::is_circle) && (shape2.type == shape_type::is_rectangle)) {
        return overlap_circle_rectangle(shape1, shape2);
    }
    if((shape1.type == shape_type::is_rectangle) && (shape2.type == shape_type::is_circle)) {
        return overlap_circle_rectangle(shape2, shape1);
    }

    // shape1 is rectangle and shape2 is rectangle
    return ((shape1.point[0]+shape1.rectangle.width >= shape2.point[0]) &&
            (shape2.point[0]+shape2.rectangle.width >= shape1.point[0]) &&
            (shape1.point[1]+shape1.rectangle.height >= shape2.point[1]) &&
            (shape2.point[1]+shape2.rectangle.height >= shape1.point[1]));
}

bool overlap(shape const *shape_arr, size_t arr_size) {
    if(arr_size == 1) {
        return false;
    }

    for(size_t i=0; i<arr_size-1; i++) {
        if(overlap(shape_arr[0], shape_arr[i+1])) {
            return true;
        }
    }
    return overlap(shape_arr+1, arr_size-1);
}

void expand(shape const *original_shape_arr, size_t arr_size, shape *expanded_shape_arr, double factor) {
    for(size_t i=0; i<arr_size; i++) {
        expanded_shape_arr[i].point[0] = original_shape_arr[i].point[0];
        expanded_shape_arr[i].point[1] = original_shape_arr[i].point[1];
        expanded_shape_arr[i].type = original_shape_arr[i].type;

        if(original_shape_arr[i].type == shape_type::is_circle) {
            expanded_shape_arr[i].circle = {.radius = original_shape_arr[i].circle.radius*factor};
        }
        // original_shape_arr[i] is rectangle
        expanded_shape_arr[i].rectangle = {.width = original_shape_arr[i].rectangle.width*factor,
                                            .height = original_shape_arr[i].rectangle.height*factor};
    }
}

double ideal_expansion_factor(shape const *shape_arr, size_t arr_size) {
    shape expanded_shape_arr[10];
    const size_t ITER = 40;
    double start_point = 0;
    double end_point = 100;
    double factor;

    for(size_t i=0; i<ITER; i++) {
        factor = (start_point+end_point)/2;
        expand(shape_arr, arr_size, expanded_shape_arr, factor);
        if(overlap(expanded_shape_arr, arr_size)) {
            end_point = factor;
        }
        else {
            start_point = factor;
        }
    }
    return factor;
}