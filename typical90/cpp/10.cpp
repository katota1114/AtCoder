#include <iostream>
using namespace std;

int main() {
    // -- 入力 --
    int N;
    int C[100009], P[100009];
    int Q;
    int L[100009], R[100009];

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> C[i] >> P[i];
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> L[i] >> R[i];
    }

    // -- 前処理 --
    // index番目の学生までの得点の合計を求める
    int scoreSum1[100009], scoreSum2[100009];
    scoreSum1[0] = 0;
    scoreSum2[0] = 0;
    for (int i = 1; i <= N; i++) {
        if (C[i] == 1) {
            // 1組の学生の場合
            scoreSum1[i] = scoreSum1[i - 1] + P[i];
            scoreSum2[i] = scoreSum2[i - 1];
        } else {
            // 2組の学生の場合
            scoreSum1[i] = scoreSum1[i - 1];
            scoreSum2[i] = scoreSum2[i - 1] + P[i];
        }
    }

    // -- 計算 --
    for (int i = 1; i <= Q; i++) {
        int answer1, answer2;
        answer1 = scoreSum1[R[i]] - scoreSum1[L[i] - 1];
        answer2 = scoreSum2[R[i]] - scoreSum2[L[i] - 1];
        cout << answer1 << " " << answer2 << endl;
    }

    return 0;
}
