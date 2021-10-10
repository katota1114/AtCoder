#include <iostream>
using namespace std;

int main() {
    // 入力
    const long long mod = 1000000000 + 7;
    long long N, B, K;
    long long C[11];

    cin >> N >> B >> K;
    for (int i = 0; i < K; i++) {
        cin >> C[i];
    }

    long long dp[10009][33];
    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < B; j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < B; j++) {
            for (int k = 0; k < K; k++) {
                int newMod = (10 * j + C[k]) % B;
                dp[i + 1][newMod] += dp[i][j];
                dp[i + 1][newMod] %= mod;
            }
        }
    }

    cout << dp[N][0] << endl;

    return 0;
}
