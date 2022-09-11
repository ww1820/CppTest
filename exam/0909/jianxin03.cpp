#include<bits/stdc++.h>

using namespace std;

fstream infile("/data/workspace/cpp_test/test.txt", ios::in);

int main() {
    double x1, y1;
    double x2, y2;
    double x3, y3;
    infile >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double min_x = min(x1, min(x2, x3));
    double max_x = max(x1, max(x2, x3));
    double min_y = min(y1, min(y2, y3));
    double max_y = max(y1, max(y2, y3));

    double k1 = (y2 - y1) / (x2 - x1), b1 = y1 - k1 * x1;
    double k2 = (y3 - y1) / (x3 - x1), b2 = y1 - k2 * x1;
    double k3 = (y3 - y2) / (x3 - x2), b3 = y2 - k3 * x2;
    
    bool a = (x3 * k1 + b1) > y3;
    bool b = (x2 * k2 + b2) > y2;
    bool c = (x1 * k3 + b3) > y1;
    int count = 0;
    for (double i = floor(min_x); i < ceil(max_x); i++) {
        for (double j = floor(min_y); j <ceil(max_y); j++) {
            if (a) {
                if (i * k1 + b1 <= j && (i+1) * k1 + b1 <= j)
                    continue;
            } else {
                if (i * k1 + b1 >= j+1 && (i+1) * k1 + b1 >= j+1)
                    continue;
            }

            if (b) {
                if (i * k2 + b2 <= j && (i+1) * k2 + b2 <= j)
                    continue;
            } else {
                if (i * k2 + b2 >= j+1 && (i+1) * k2 + b2 >= j+1)
                    continue;
            }

            if (c) {
                if (i * k3 + b3 <= j && (i+1) * k3 + b3 <= j)
                    continue;
            } else {
                if (i * k3 + b3 >= j+1 && (i+1) * k3 + b3 >= j+1)
                    continue;
            }

            count++;
        }
    }
    cout << count;
}