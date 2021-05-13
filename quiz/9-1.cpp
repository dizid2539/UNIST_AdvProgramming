#include <iostream>

struct x {
    int a;
};
struct y {
    x a;
    x *b;
};
struct z {
    int a;
    union {
        y *b;
        struct {
            x *d;
            y *e;
        } c;
    };
};

int main() {
    using namespace std;
    x x1 = {.a=1};
    y y1 = {.a=x1, .b=&x1};
    z z1 = {.a=3};
    z1.b = &y1;
    z1.c = {.d=&x1, .e=&y1};

    z1.c.e->a.a = 3;
    cout << z1.c.e->a.a << endl;
    return 0;
}