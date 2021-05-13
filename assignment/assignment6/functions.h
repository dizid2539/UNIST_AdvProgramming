// name: 임형근
// student ID: 20201261
// description: contains prototypes of functions

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "shape.h"
#include <cstddef>

bool overlap(shape const *, size_t);
bool overlap(shape const &, shape const &);
void expand(shape const *, size_t, shape *, double);
double ideal_expansion_factor(shape const *, size_t);

#endif