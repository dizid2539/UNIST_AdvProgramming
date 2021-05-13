// name: 임형근
// student ID: 20201261
// description: contains score_without_realigning and best_alignment functions

#include <cstddef>

#define NUCLEOTIDE_MATCH(a,b) ((a) == 0 && (b) == 2) || ((a) == 2 && (b) == 0) || ((a) == 1 && (b) == 3) || ((a) == 3 && (b) == 1)

int score_without_realigning(char const * seq_1, size_t seq_1_size, char const * seq_2, size_t seq_2_size) {
    size_t smaller_size = (seq_1_size < seq_2_size ? seq_1_size : seq_2_size);
    int score = 0;

    for(size_t i=0; i<smaller_size; i++) {
        score += (NUCLEOTIDE_MATCH(seq_1[i], seq_2[i]) ? 1 : -1);
    }

    return score;
}

int best_alignment(char const * seq_1, size_t seq_1_size, char const * seq_2, size_t seq_2_size, long *shift) {
    int best_score;
    bool is_best_score_undefined = true;

    for(size_t i=0; i<=seq_1_size; i++) {
        int temp_score = score_without_realigning(seq_1+i, seq_1_size-i, seq_2, seq_2_size);
        if(is_best_score_undefined || temp_score > best_score) {
            is_best_score_undefined = false;
            best_score = temp_score;
            *shift = (long)i;
        }
    }
    
    for(size_t i=1; i<=seq_2_size; i++) {
        int temp_score = score_without_realigning(seq_1, seq_1_size, seq_2+i, seq_2_size-i);
        if(temp_score > best_score) {
            best_score = temp_score;
            *shift = ((long)i)*-1;
        }
    }

    return best_score;
}