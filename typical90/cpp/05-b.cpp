#include <iostream>
using namespace std;

const long long mod = 1000000000 + 7;
const int MAX_B = 33;

struct Matrix {
    int size;
    long long x[MAX_B][MAX_B];
};

// 行列 A * 行列B
Matrix multiply(Matrix A, Matrix B) {
    // Cの初期化
    Matrix C;
    C.size = A.size;
    for (int i = 0; i < C.size; i++) {
        for (int j = 0; j < C.size; j++) {
            C.x[i][j] = 0;
        }
    }

    // Cに答えを計算して入れていく
    for (int i = 0; i < A.size; i++) {
        for (int j = 0; j < A.size; j++) {
            for (int k = 0; k < A.size; k++) {
                C.x[i][k] += A.x[i][j] * B.x[j][k];
                C.x[i][k] %= mod;
            }
        }
    }

    return C;
}

// 行列A の n乗
Matrix powers(Matrix A, long long n) {
    // E[a] = A^(2^a)
    Matrix E[64], F;
    E[0] = A;
    for (int i = 1; i < 62; i++) {
        E[i] = multiply(E[i - 1], E[i - 1]);
    }

    // Fを一旦単位行列にする
    F.size = E[0].size;
    for (int i = 0; i < F.size; i++) {
        for (int j = 0; j < F.size; j++) {
            if (i == j)
                F.x[i][j] = 1;
            if (i != j)
                F.x[i][j] = 0;
        }
    }

    // 実際に計算する
    for (int i = 62; i >= 0; i--) {
        if ((n & (1LL << i)) != 0LL) {
            F = multiply(F, E[i]);
        }
    }

    return F;
}

// 入力
long long N, B, K;
long long C[11];

int main() {
    // -- 入力 --
    cin >> N >> B >> K;
    for (int i = 0; i < K; i++) {
        cin >> C[i];
    }

    // -- 遷移を表す行列Aを作る --
    Matrix A;
    A.size = B;

    // 初期化
    for (int i = 0; i < A.size; i++) {
        for (int j = 0; j < A.size; j++) {
            A.x[i][j] = 0;
        }
    }

    // 実際に値を計算する
    for (int i = 0; i < B; i++) {
        for (int j = 0; j < K; j++) {
            int newMod = (i * 10 + C[j]) % B;
            A.x[i][newMod] += 1;
        }
    }

    // -- N桁遷移させた結果を求める --
    Matrix Z = powers(A, N);
    long long answer = Z.x[0][0];

    cout << answer << endl;

    return 0;
}
