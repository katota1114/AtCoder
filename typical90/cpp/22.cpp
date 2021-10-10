#include <iostream>
using namespace std;

// 入力値
long long A, B, C;

long long gcd(long long a, long long b) {
    if (b > a) {
        return gcd(b, a);
    }

    long long r = a % b;
    if (r == 0LL) {
        return b;
    }
    return gcd(b, r);
}

int main() {
    // -- 入力 --
    cin >> A >> B >> C;

    // -- 計算 --
    long long r = gcd(gcd(A, B), C);
    long long ans = (A / r - 1LL) + (B / r - 1LL) + (C / r - 1LL);

    // -- 出力 --
    cout << ans << endl;
}
