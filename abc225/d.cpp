#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, Q;

// int - key , int[2] - [一個前、一個後]
vector<int> front(100009, -1);
vector<int> back(100009, -1);

void printConnectedTrain(int trainNum) {
    // 先頭車両を探す
    int lead = trainNum;
    while (front[lead] != -1) {
        lead = front[lead];
    }

    // 最後尾に当たるまで順番に出力していく
    int current = lead;
    vector<int> answer;
    answer.push_back(current);

    while (back[current] != -1) {
        current = back[current];
        answer.push_back(current);
    }

    cout << answer.size();

    for (int i = 0; i < answer.size(); i++) {
        cout << " " << answer[i];
    }

    cout << endl;
}

int main() {
    cin >> N >> Q;

    for (int i = 1; i <= Q; i++) {
        int c, x, y;
        cin >> c;
        if (c == 1) {
            // 電車 x の後部と、電車 y の前部を連結させる。
            cin >> x >> y;
            front[y] = x;
            back[x] = y;
        }
        if (c == 2) {
            // 電車 x の後部と、電車 y の前部を分離させる。
            cin >> x >> y;
            front[y] = -1;
            back[x] = -1;
        }
        if (c == 3) {
            // 電車 x が含まれる連結成分に属する電車の番号を、
            // 先頭から順番に全て出力する。
            cin >> x;
            printConnectedTrain(x);
        }
    }

    return 0;
}
