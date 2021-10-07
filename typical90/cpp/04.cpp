#include <iostream>
using namespace std;

int main() {
    // 入力
    int H, W;
    cin >> H >> W;

    int A[H][W];
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            // iostreamを使うよりも早くなる
            scanf("%d", &A[h][w]);
        }
    }

    // 行・列の合計を計算する
    int hSum[H], wSum[W];
    for (int h = 0; h < H; h++) {
        hSum[h] = 0;
    }
    for (int w = 0; w < W; w++) {
        wSum[w] = 0;
    }

    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            hSum[h] += A[h][w];
            wSum[w] += A[h][w];
        }
    }

    // 答えを計算する
    int answer[H][W];
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            answer[h][w] = hSum[h] + wSum[w] - A[h][w];
        }
    }

    // 答えを出力する
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (w > 0) {
                cout << " ";
            }
            cout << answer[h][w];
        }
        cout << endl;
    }

    return 0;
}
