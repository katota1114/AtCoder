#include <iostream>
#include <string>
using namespace std;

// 文字列が正しいカッコ列かチェックする
bool isValid(string s) {
    int dep = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            dep += 1;
        }
        if (s[i] == ')') {
            dep -= 1;
        }

        if (dep < 0) {
            return false;
        }
    }

    return dep == 0;
}

int main() {
    // 入力受け取り
    int N;
    cin >> N;

    // 小さい制約 -> 全探索できる
    for (int i = 0; i < (1 << N); i++) {
        // ビット列にして候補のカッコ列を作る
        string candidate = "";
        for (int j = N - 1; j >= 0; j--) {
            if ((i & (1 << j)) == 0) {
                candidate += "(";
            } else {
                candidate += ")";
            }
        }

        // 正しいカッコ列なら出力する
        if (isValid(candidate)) {
            cout << candidate << endl;
        }
    }

    return 0;
}
