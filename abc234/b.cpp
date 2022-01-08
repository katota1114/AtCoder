#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int x[109];
    int y[109];
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    double max = 0.0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double length = sqrt((x[i] - x[j]) * (x[i] - x[j]) +
                                 (y[i] - y[j]) * (y[i] - y[j]));

            if (length > max) {
                max = length;
            }
        }
    }

    printf("%.16f\n", max);
}
