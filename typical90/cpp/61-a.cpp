/* vectorを用いた解放(ちょっと強引) */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // -- 入力 --
    int Q;
    int t[100009], x[100009];

    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> t[i] >> x[i];
    }

    // -- 実際にルールに従って処理する --
    vector<int> deck{};
    for (int i = 1; i <= Q; i++) {
        if (t[i] == 1) {
            deck.insert(deck.begin(), x[i]);
        }
        if (t[i] == 2) {
            deck.push_back(x[i]);
        }
        if (t[i] == 3) {
            cout << deck[x[i] - 1] << endl;
        }
    }

    return 0;
}
