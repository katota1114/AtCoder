#include <iostream>
#include <queue>
using namespace std;

// 解説AC(プライオリティーキューを使うことで最適にできる)

int main() {
    int N, K;
    cin >> N >> K;

    priority_queue<int, vector<int>, greater<int>> que;

    // 先頭K項までを一旦入力
    for (int i = 0; i < K; i++) {
        int input;
        cin >> input;
        que.push(input);
    }

    // 降順ソート
    cout << que.top() << endl;

    // K項目より先から最後まで比較していく
    for (int i = K; i < N; i++) {
        int input;
        cin >> input;

        if (input > que.top()) {
            que.pop();
            que.push(input);
        }
        cout << que.top() << endl;
    }
}
