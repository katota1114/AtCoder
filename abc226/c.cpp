#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int main() {

    int N;
    cin >> N;

    vector<int> T(N);
    map<int, set<int>> A;

    for (int i = 0; i < N; i++) {
        cin >> T[i];

        int K;
        cin >> K;
        for (int j = 0; j < K; j++) {
            int ak;
            cin >> ak;
            A[i].insert(ak - 1);
        }
    }

    set<int> needToLearn;
    map<int, int> alreadyQueued;
    queue<int> searchQueue;

    searchQueue.push(N - 1);
    alreadyQueued[N - 1]++;

    while (!searchQueue.empty()) {
        int current = searchQueue.front();
        searchQueue.pop();
        needToLearn.insert(current);

        for (int x : A[current]) {
            if (alreadyQueued[x] == 0) {
                searchQueue.push(x);
                alreadyQueued[x]++;
            }
        }
    }

    long long needTime = 0;
    for (int x : needToLearn) {
        needTime += T[x];
    }

    cout << needTime << endl;

    return 0;
}
