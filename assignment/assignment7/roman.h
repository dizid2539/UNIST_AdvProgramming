#include <iostream>
using namespace std;

class Roman {
    private:
        unsigned int value;
        int roman_value(const char) const;
        unsigned int to_int(const char *) const;
        void to_char(char *) const;

    public:
        Roman(char *input_char) : value(to_int(input_char)) {}
        Roman(unsigned int input_int=0) : value(input_int) {}

        Roman &operator+=(Roman const &);
        Roman operator+(Roman const &) const;
        Roman &operator*=(Roman const &);
        Roman operator*(Roman const &) const;
        bool operator<(Roman const &) const;
        bool operator<=(Roman const &) const;

        friend ostream &operator<<(ostream &, Roman const &);
        friend istream &operator>>(istream &, Roman &);
};