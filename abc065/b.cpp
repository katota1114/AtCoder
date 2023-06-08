#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int currentLighting = 1;
    int pushTime = 0;
    while (currentLighting != 2 && pushTime <= N) {
        pushTime++;
        currentLighting = a[currentLighting - 1];
    }

    if (currentLighting != 2) {
        cout << -1 << endl;
        return 0;
    }
    cout << pushTime << endl;
}
