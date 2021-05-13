// name: 임형근
// student ID: 20201261
// description: contains definition of shape(struct) and shape_type(enum class)

#ifndef SHAPE_H
#define SHAPE_H

enum class shape_type {
    is_rectangle,
    is_square,
    is_circle
};

struct shape {
    shape_type type;
    double point[2];
    union {
        struct {
            double width;
            double height;
        } rectangle;
        struct {
            double length;
        } square;
        struct {
            double radius;
        } circle;
    };
};

#endif