#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    // -- 入力 --
    int N, M;
    int a[100009], b[100009];

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> a[i] >> b[i];
    }

    // -- 隣接リストの作成 --
    map<int, vector<int>> adjList;
    for (int i = 1; i <= M; i++) {
        adjList[a[i]].push_back(b[i]);
        adjList[b[i]].push_back(a[i]);
    }

    // -- 頂点全部調べる --
    int count = 0;
    for (int i = 1; i <= N; i++) {
        vector<int> connect = adjList[i];
        int connectSmall = 0;
        for (int n : connect) {
            if (n < i) {
                connectSmall++;
            }
        }
        if (connectSmall == 1) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
