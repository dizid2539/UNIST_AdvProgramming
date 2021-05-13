#include <iostream>

int num_real_roots(double a, double b, double c){
    double discriminant = b*b-4*a*c;
    if (discriminant > 0) {
        return 2;
    }
    else if (discriminant == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int main(){
    using namespace std;
    int num;
    double a, b, c;

    cout << "a : ";
    cin >> a;
    cout << "b : ";
    cin >> b;
    cout << "c : ";
    cin >> c;
    num = num_real_roots(a, b, c);

    cout << "number of real roots : " << num << endl;

    return 0;
}