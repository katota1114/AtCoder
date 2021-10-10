#include <algorithm>
#include <iostream>
using namespace std;

const int INF = 2000000000;

// 入力
int N, Q;
int A[300009];
int B[300009];

int main() {
    // -- 入力 --
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> B[i];
    }

    // -- ソートする --
    sort(A, A + N);

    // -- 2分探索をQ人分行ってその度に結果を出す --
    for (int i = 0; i < Q; i++) {
        // indexには自分のレベル以上の最初のクラスが入る
        int index = lower_bound(A, A + N, B[i]) - A;
        int diff1 = INF, diff2 = INF;
        if (index < N) {
            diff1 = abs(B[i] - A[index]);
        }
        if (index > 0) {
            diff2 = abs(B[i] - A[index - 1]);
        }
        cout << min(diff1, diff2) << endl;
    }

    return 0;
}
