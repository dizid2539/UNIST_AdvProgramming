#include <iostream>

int f(int x, int y){
    if(x <= 0){
        return y;
    }
    return f(x-2, f(x/2, y+1));
}

int main(){
    using namespace std;
    cout << f(4,2) << endl;
    return 0;
}