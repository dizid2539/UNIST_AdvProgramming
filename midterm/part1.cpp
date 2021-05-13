#include <iostream>
#include <iomanip>
#include <climits>

double avg(const double *temp, const size_t temp_len) {
    double sum = 0;
    for(size_t i=0; i<temp_len; i++) {
        sum += temp[i];
    }
    return sum/(double)temp_len;
}

int main() {
    using namespace std;
    double temp[20];
    size_t input_len = 0, temp_len = 0;

    for(size_t i=0; i<20; i++) {
        double input_buffer;
        cin >> input_buffer;
        input_len++;

        if(cin) {
            temp[temp_len] = input_buffer;
            temp_len++;
        }
        else {
            cin.clear();
            cin.ignore(SSIZE_MAX, '\n');
        }
        if(cin.eof()) {
            break;
        }
    }

    cout << input_len << " lines read in" << endl;
    cout << temp_len << " valid lines read in" << endl;

    double mean = avg(temp, temp_len);
    cout << "mean temperature is ";
    cout << fixed << setprecision(1);
    cout << mean << endl;

    cout << "temperatures colder than the mean:" << endl;
    for(size_t i=0; i<temp_len; i++) {
        if(temp[i] < mean) {
            cout << fixed << setprecision(3);
            cout << setw(10) << temp[i] << endl;
        }
    }

    return 0;
} 