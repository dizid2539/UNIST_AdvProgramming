#include <iostream>

bool combination(int target, int* field, size_t field_s, bool* com, size_t offset=0) {
    if(target == 0)
        return true;
    else if(target < 0)
        return false;

    for(size_t i=0; i<field_s; i++) {
        bool is_com_vaild = combination(target-field[i], field+i+1, field_s-1, com, offset+i+1);
        if(is_com_vaild) {
            com[i+offset] = true;
            return true;
        }
    }
    return false;
}

int main() {
    #define LEN 10
    using namespace std;

    int target;
    cin >> target;
    int field[LEN] = {1,2};
    bool com[LEN] = {false};

    combination(target, field, LEN, com);
    for(size_t i=0; i<LEN; i++) {
        if(com[i]) {
            cout << field[i] << " ";
        }
    }
    cout << endl;
    
    return 0;
}