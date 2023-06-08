#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    int count = 0;
    while (N > 1) {
        N = N / 2;
        count++;
    }

    int answer = 1;
    for (int i = 0; i < count; i++) {
        answer *= 2;
    }

    cout << answer << endl;
}
