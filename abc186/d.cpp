#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // input
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // solve
    sort(A.begin(), A.end());

    long long total = 0;
    for (int i = 1; i < N; i++) {
        long long diff = A[i] - A[i - 1];
        total += diff * (N - i) * i;
    }

    cout << total << endl;
}
