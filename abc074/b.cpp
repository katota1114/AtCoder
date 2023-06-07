#include <iostream>
#include <vector>
using namespace std;

int main() {
    // input
    int N, K;
    cin >> N >> K;
    vector<int> x(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    // solve
    //  mid以下の位置はAが，mid以上の位置はBに取りに行かせる
    int mid = K / 2;

    int length = 0;
    for (int i = 0; i < N; i++) {
        int ballPos = x[i];
        if (ballPos <= mid) {
            length += ballPos * 2;
        } else {
            length += (K - ballPos) * 2;
        }
    }

    cout << length << endl;
}
