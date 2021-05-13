// name: 임형근
// student ID: 20201261
// description: contains prototypes of score_without_realigning and best_alignment functions


#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>

int score_without_realigning(char const *, size_t, char const *, size_t);
int best_alignment(char const *, size_t, char const *, size_t, long *);

#endif