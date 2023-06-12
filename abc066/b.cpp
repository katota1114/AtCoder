#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    while (true) {
        S = S.substr(0, S.length() - 2);

        string first = S.substr(0, S.length() / 2);
        string second = S.substr(S.length() / 2, S.length());
        if (first == second) {
            cout << S.length() << endl;
            return 0;
        }
    }
}
