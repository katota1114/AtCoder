#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    int currentHeight = 0;
    for (int i = 0; i < N; i++) {
        if (currentHeight < H[i]) {
            currentHeight = H[i];
        } else {
            break;
        }
    }

    cout << currentHeight << endl;
}
