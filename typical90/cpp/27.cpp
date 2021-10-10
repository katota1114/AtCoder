#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // -- 入力 --
    int N;
    string S[100009];

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
    }

    // -- 使っているかチェックして使っていなかったら出力 --
    map<string, int> used;
    for (int i = 1; i <= N; i++) {
        if (used[S[i]] != 0) {
            continue;
        }
        used[S[i]]++;
        cout << i << endl;
    }

    return 0;
}
