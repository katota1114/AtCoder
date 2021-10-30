#include <iostream>
#include <map>
using namespace std;

int main() {
    int N;
    int a[100009], b[100009];

    cin >> N;
    for (int i = 1; i <= N - 1; i++) {
        cin >> a[i] >> b[i];
    }

    int candidade = -1;
    if (a[1] == a[2] || a[1] == b[2]) {
        candidade = a[1];
    }
    if (b[1] == b[2] || b[1] == a[2]) {
        candidade = b[1];
    }

    for (int i = 3; i <= N - 1; i++) {
        if (candidade != a[i] && candidade != b[i]) {
            candidade = -1;
        }
    }

    if (candidade == -1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}
