#include <iostream>
using namespace std;

int main() {
    int N, M;
    long long B[10009][10];

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> B[i][j];
        }
    }

    // 基点からN行M列を取って溢れないかどうか
    int start = (B[1][1] - 1) % 7;
    int end = (B[1][1] + (M - 1) - 1) % 7;
    if (end < start) {
        cout << "No" << endl;
        return 0;
    }

    // 横方向の整合性チェック
    for (int i = 1; i <= N; i++) {
        long long counter = B[i][1];
        for (int j = 2; j <= M; j++) {
            if (B[i][j] == counter + 1) {
                counter++;
            } else {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    // 縦方向の整合性チェック
    long long vertCounter = B[1][1];
    for (int i = 2; i <= N; i++) {
        if (B[i][1] == vertCounter + 7) {
            vertCounter += 7;
        } else {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
