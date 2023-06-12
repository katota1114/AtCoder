#include <iostream>
#include <string>
using namespace std;

int main() {
    // input
    string S;
    cin >> S;

    // solve
    // 連続した<や>を探し出す
    int N = S.length() + 1;
    char currentCheck = '>';
    int current = 0;
    int serialCount = 0;
    int tmpMax = 0;
    long long answerSum = 0;
    while (current < N - 1) {
        if (S[current] == currentCheck) {
            current++;
            serialCount++;
            continue;
        }
        // 不等号がcurrentとcurrent-1で逆になっている場合
        // または今読み取っている不等号が末尾の場合
        if (S[current] == '<') {
            if (tmpMax > serialCount) {
                answerSum += tmpMax;
            } else {
                answerSum += serialCount;
            }
            answerSum += (long long)serialCount * (serialCount - 1) / 2;
        }
        if (S[current] == '>') {
            tmpMax = serialCount;

            answerSum += (long long)serialCount * (serialCount - 1) / 2;
        }
        currentCheck = S[current];
        serialCount = 1;
        current++;
    }

    // 末尾分の処理
    if (S[current - 1] == '<') {
        answerSum += (long long)serialCount * (serialCount - 1) / 2;
        answerSum += serialCount;
    }
    if (S[current - 1] == '>') {
        if (tmpMax > serialCount) {
            answerSum += tmpMax;
        } else {
            answerSum += serialCount;
        }

        answerSum += (long long)serialCount * (serialCount - 1) / 2;
    }

    cout << answerSum << endl;
}
