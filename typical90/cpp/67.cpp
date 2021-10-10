#include <iostream>
#include <string>
using namespace std;

long long base8_to_long(string s) {
    long long n = 0;
    long long x = 1;
    for (int digit = s.size() - 1; digit >= 0; digit--) {
        n += 1LL * (s[digit] - '0') * x;
        x *= 8LL;
    }
    return n;
}

string long_to_base9(long long n) {
    if (n == 0) {
        return "0";
    }

    string s = "";
    while (n > 0) {
        char c = ((n % 9) + '0');
        if (c == '8') {
            c = '5';
        }

        s = c + s;
        n /= 9LL;
    }
    return s;
}

int main() {
    // -- 入力 --
    string N;
    int K;
    cin >> N >> K;

    // --　繰り返し処理 --
    string current;
    current = N;
    for (int i = 0; i < K; i++) {
        current = long_to_base9(base8_to_long(current));
    }

    // -- 出力 --
    cout << current << endl;
}
