#include "roman.h"

int main() {
    using namespace std;
    Roman a, b, sum;
    const Roman one=1;

    cout << "Enter starting and ending numbers: " << flush;
    cin >> a >> b;
    for(; a<=b; a+=one) {
        Roman square = a*a;
        sum += square;
        cout << a << '\t' << square << '\t' << sum << endl;
    }
}