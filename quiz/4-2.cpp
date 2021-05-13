#include <iostream>

static size_t len(char const *x) {
    size_t i;
    for(i=0; x[i]; i++);
    return i;
}

int main() {
    using namespace std;
    char x[] = "hello!";
    char *y = &x[2];
    char *z = &x[0];
    *y = '\0';
    cout << len(z) << endl;
    return 0;
}