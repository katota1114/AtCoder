#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<long> x(Q);
    vector<int> k(Q);
    for (int i = 0; i < Q; i++) {
        cin >> x[i] >> k[i];
    }

    // 数字->indexのmapを作る
    map<long, vector<int>> indexMap;
    for (int i = 0; i < N; i++) {
        indexMap[a[i]].push_back(i);
    }

    // クエリごとに処理していく
    for (int i = 0; i < Q; i++) {
        if (indexMap[x[i]].size() < k[i]) {
            cout << -1 << endl;
            continue;
        }
        cout << indexMap[x[i]][k[i] - 1] + 1 << endl;
    }
}
