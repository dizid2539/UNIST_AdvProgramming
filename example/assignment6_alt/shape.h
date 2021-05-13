#ifndef SHAPE_H
#define SHAPE_H

enum class shape_type {
    is_rectangle,
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
            double radius;
        } circle;
    };
};

#endif