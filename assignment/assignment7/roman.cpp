#include "roman.h"
#include <cctype>
using namespace std;

int Roman::roman_value(const char c) const {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

unsigned int Roman::to_int(const char* input) const {
    int value = 0; size_t i;

    for(i=0; (int)input[i+1] != 0; i++) {
        int current_value = roman_value(input[i]);
        int next_value = roman_value(input[i+1]);

        if((current_value < next_value) &&
            (input[i]=='I' || input[i]=='X' || input[i]=='C')) {
                value -= current_value; }
        else {value += current_value; }
    }

    value += roman_value(input[i]);
    return (unsigned int)value;
}

void Roman::to_char(char* output) const {
    int input = (int)value;
    const char roman_list[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    const char subtractive_roman_list[3] = {'I', 'X', 'C'};
    size_t output_len = 0;

    for(size_t i=0; i<7; i++) {
        int curr_value = roman_value(roman_list[i]);
        int last_positive_input;
        for(; input > 0; output_len++) {
            last_positive_input= input;
            input -= curr_value;
            output[output_len] = roman_list[i];
        }
        if(input == 0) {break;}

        input *= -1;
        bool is_subtracted = false;
        for(size_t j=0; j<3; j++) {
            int curr_subtractive_value = roman_value(subtractive_roman_list[j]);
            if((curr_subtractive_value < curr_value) && 
                (curr_subtractive_value >= input)) {
                    input = curr_subtractive_value - input;
                    output[output_len-1] = subtractive_roman_list[j];
                    output[output_len] = roman_list[i];
                    output_len++; is_subtracted = true;
                    break;
            }
        }
        if(!is_subtracted) {
            input = last_positive_input;
            output_len--;
        }
    }
    output[output_len] = '\0';
}

Roman &Roman::operator+=(Roman const &other) {
    int updated_value = value + other.value;
    value = updated_value;
    return *this;
}
Roman Roman::operator+(Roman const &other) const {
    Roman output = *this;
    return output += other;
}
Roman &Roman::operator*=(Roman const &other) {
    int updated_value = value * other.value;
    value = updated_value;
    return *this;
}
Roman Roman::operator*(Roman const &other) const {
    Roman output = *this;
    return output *= other;

}
bool Roman::operator<(Roman const &other) const {
    return (value < other.value);
}
bool Roman::operator<=(Roman const &other) const {
    return (value <= other.value);
}

ostream &operator<<(ostream &out, Roman const &r) {
    char output[100]; r.to_char(output);
    return out << output;
}
istream &operator>>(istream &in, Roman &r) {
    char input[100]; in >> input;
    for(size_t i=0; (int)input[i]!=0; i++) {
        input[i] = toupper(input[i]);
    }
    r.value = r.to_int(input);
    return in;
}