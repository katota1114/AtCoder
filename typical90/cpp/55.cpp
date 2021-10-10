#include <iostream>
using namespace std;

int main() {
    // -- 入力 --
    int N, P, Q;
    int A[109];

    cin >> N >> P >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    // -- 該当の組み合わせを数え上げ --
    int count = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N && j < i; j++) {
            for (int k = 1; k <= N && k < j; k++) {
                for (int l = 1; l <= N && l < k; l++) {
                    for (int m = 1; m <= N && m < l; m++) {
                        if (1LL * A[i] * A[j] % P * A[k] % P * A[l] % P * A[m] %
                                P ==
                            Q) {
                            count++;
                        }
                    }
                }
            }
        }
    }

    // -- 出力 --
    cout << count << endl;

    return 0;
}
