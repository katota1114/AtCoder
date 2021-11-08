#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int N;
    map<vector<int>, int> count;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int L;
        vector<int> a;
        cin >> L;

        for (int j = 0; j < L; j++) {
            int number;
            cin >> number;
            a.push_back(number);
        }

        count[a]++;
    }

    cout << count.size() << endl;

    return 0;
}
