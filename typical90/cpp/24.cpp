#include <iostream>
using namespace std;

int main() {
    int N, K;
    int A[1009], B[1009];

    // -- 入力 --
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }

    // 各要素ごとの誤差の和を求める
    long long diff = 0;
    for (int i = 1; i <= N; i++) {
        diff += abs(A[i] - B[i]);
    }

    if (diff > K) {
        cout << "No" << endl;
        return 0;
    }

    if ((K - diff) % 2 == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
