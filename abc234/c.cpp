#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
    long k;
    cin >> k;

    string answer = "";

    while (k > 0) {
        if (k % 2 == 0) {
            answer = "0" + answer;
        } else {
            answer = "2" + answer;
        }

        k = k / 2;
    }

    cout << answer << endl;
}
