#include <iostream>
#include <map>
using namespace std;

int main() {
    map<char, int> sMap;
    char sChar;

    for (int i = 0; i < 3; i++) {
        cin.get(sChar);
        sMap[sChar]++;
    }

    int sMapSize = sMap.size();

    int answer;
    switch (sMapSize) {
    case 1:
        answer = 1;
        break;
    case 2:
        answer = 3;
        break;
    case 3:
        answer = 6;
        break;
    default:
        answer = -1;
        break;
    }

    cout << answer << endl;
    return 0;
}
