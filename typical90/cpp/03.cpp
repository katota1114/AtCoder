#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 問題の入力
int N;
int A[1 << 18];
int B[1 << 18];

// グラフ
const int INF = INT_MAX;
vector<int> G[1 << 18];
int dist[1 << 18];

// DFSで距離をdistに入れていく
void getDist(int start) {
    // 最初に全部無限大にしておく
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }

    queue<int> Q;
    Q.push(start);
    dist[start] = 0;

    while (!Q.empty()) {
        int current = Q.front();
        Q.pop();
        for (int to : G[current]) {
            if (dist[to] == INF) {
                dist[to] = dist[current] + 1;
                Q.push(to);
            }
        }
    }
}

int main() {
    // 入力を受け取る
    cin >> N;
    for (int i = 1; i <= N - 1; i++) {
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    // 頂点1から一番遠いところ(maxId)を探す
    getDist(1);
    int maxValue = -1;
    int maxId = -1;
    for (int i = 1; i <= N; i++) {
        if (dist[i] > maxValue) {
            maxValue = dist[i];
            maxId = i;
        }
    }

    // 頂点aからの最長距離を求める
    getDist(maxId);
    int maxDist = -1;
    for (int i = 1; i <= N; i++) {
        maxDist = max(maxDist, dist[i]);
    }

    cout << maxDist + 1 << endl;
    return 0;
}
