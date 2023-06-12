#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // input
    int N;
    cin >> N;

    string s;
    cin >> s;

    int Q;
    cin >> Q;

    vector<int> T(Q);
    vector<int> A(Q);
    vector<int> B(Q);
    for (int i = 0; i < Q; i++) {
        cin >> T[i] >> A[i] >> B[i];
    }

    // solve
    bool isFlipped = false;
    for (int i = 0; i < Q; i++) {
        if (T[i] == 2) {
            isFlipped = !isFlipped;
            continue;
        }

        int indexA = A[i] - 1;
        int indexB = B[i] - 1;
        if (isFlipped) {
            indexA = (indexA + N) % (2 * N);
            indexB = (indexB + N) % (2 * N);
        }

        char tmp = s[indexA];
        s[indexA] = s[indexB];
        s[indexB] = tmp;
    }

    string pre = s.substr(0, N);
    string suf = s.substr(N, N);

    if (isFlipped) {
        string tmp = pre;
        pre = suf;
        suf = tmp;
    }

    cout << pre << suf << endl;
}
