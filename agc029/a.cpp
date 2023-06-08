#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // 以降Bを0,Wを1で表現する
    string S;
    cin >> S;

    int size = S.length();
    vector<int> s(size);
    for (int i = 0; i < size; i++) {
        char c = S[i];
        if (c == 'B') {
            s[i] = 0;
        } else {
            s[i] = 1;
        }
    }

    // 最終的に1(W)が左側，0(B)が右側に集結する
    long long reverseCount = 0;
    int countB = 0;

    if (s[0] == 0) {
        countB = 1;
    }

    for (int i = 1; i < size; i++) {
        if (s[i] == 0) {
            // Black
            countB++;
        } else {
            // White
            reverseCount += countB;
        }
    }

    cout << reverseCount << endl;
}
