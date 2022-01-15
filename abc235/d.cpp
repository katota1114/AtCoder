#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>

using namespace std;

int act1(int a, int x) { return x * a; }

int act2(int x) {
    if (x < 10 || x % 10 == 0) {
        return -1;
    }
    string xStr = to_string(x);
    xStr = xStr[xStr.size() - 1] + xStr.substr(0, xStr.size() - 1);
    return stoi(xStr);
}

int main() {

    int a, N;
    cin >> a >> N;

    // BFSで探索していく…？
    queue<pair<int, int>> BFS;
    map<int, int> alreadyAdded;

    int result = -1;
    BFS.push(make_pair(1, 0));
    alreadyAdded[1]++;

    while (!BFS.empty()) {
        pair<int, int> current = BFS.front();
        BFS.pop();

        if (current.first == N) {
            result = current.second;
            break;
        }

        int tmp1 = act1(a, current.first);
        if (tmp1 < N * 10 && alreadyAdded[tmp1] == 0) {
            BFS.push(make_pair(tmp1, current.second + 1));
            alreadyAdded[tmp1]++;
        }

        int tmp2 = act2(current.first);
        if (tmp2 != -1 && tmp2 < N * 10 && alreadyAdded[tmp2] == 0) {
            BFS.push(make_pair(tmp2, current.second + 1));
            alreadyAdded[tmp2]++;
        }
    }

    cout << result << endl;
}
