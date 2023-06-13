#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    // input
    int N;
    cin >> N;

    vector<string> s(N);
    vector<string> t(N);

    for (int i = 0; i < N; i++) {
        cin >> s[i] >> t[i];
    }

    // solve
    // 姓名の重複チェック
    map<string, int> mp;
    for (int i = 0; i < N; i++) {
        mp[s[i]]++;
        mp[t[i]]++;

        if (s[i] == t[i]) {
            mp[s[i]]--;
        }
    }

    // かぶらないようにチェック
    for (int i = 0; i < N; i++) {
        if (mp[s[i]] > 1 && mp[t[i]] > 1) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
