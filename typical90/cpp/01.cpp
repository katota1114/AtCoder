#include <iostream>
using namespace std;

long long N, K, L;
long long A[1 << 18];

// M以上の羊羹K個以上に分けられるか
bool solve(long long M) {
    long long cnt = 0, pre = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] - pre >= M && L - A[i] >= M) {
            cnt += 1;
            pre = A[i];
        }
    }

    if (cnt >= K) {
        return true;
    }
    return false;
}

int main() {
    // 入力を受け取る
    cin >> N >> L;
    cin >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // 二分探索
    long long left = -1;
    long long right = L + 1;
    while (right - left > 1) {
        long long mid = left + (right - left) / 2;
        if (!solve(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << left << endl;
    return 0;
}
