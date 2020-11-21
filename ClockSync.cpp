// AlgorithmPractice3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;
const int INF = 100000;

int clockSwitch[10][16] = { {0,},{0,},{0,},{0,},{0,},{0,},{0,},{0,},{0,},{0,}, };

void makeClockSwitch() {
    clockSwitch[0][0] = 1; clockSwitch[0][1] = 1; clockSwitch[0][2] = 1;
    clockSwitch[1][3] = 1; clockSwitch[1][7] = 1; clockSwitch[1][9] = 1; clockSwitch[1][11] = 1;
    clockSwitch[2][4] = 1; clockSwitch[2][10] = 1; clockSwitch[2][14] = 1; clockSwitch[2][15] = 1;
    clockSwitch[3][0] = 1; clockSwitch[3][4] = 1; clockSwitch[3][5] = 1; clockSwitch[3][6] = 1; clockSwitch[3][7] = 1;
    clockSwitch[4][6] = 1; clockSwitch[4][7] = 1; clockSwitch[4][8] = 1; clockSwitch[4][10] = 1; clockSwitch[4][12] = 1;
    clockSwitch[5][0] = 1; clockSwitch[5][2] = 1; clockSwitch[5][14] = 1; clockSwitch[5][15] = 1;
    clockSwitch[6][3] = 1; clockSwitch[6][14] = 1; clockSwitch[6][15] = 1;
    clockSwitch[7][4] = 1; clockSwitch[7][5] = 1; clockSwitch[7][7] = 1; clockSwitch[7][14] = 1; clockSwitch[7][15] = 1;
    clockSwitch[8][1] = 1; clockSwitch[8][2] = 1; clockSwitch[8][3] = 1; clockSwitch[8][4] = 1; clockSwitch[8][5] = 1;
    clockSwitch[9][3] = 1; clockSwitch[9][4] = 1; clockSwitch[9][5] = 1; clockSwitch[9][9] = 1; clockSwitch[9][13] = 1;
}

void addArr(int switchNum, vector<int> *clockTimeArr) {

    for (int i = 0; i < 16; i++) {
        (*clockTimeArr)[i] += (clockSwitch[switchNum][i] * 3);
    }
}

void subtractArr(int switchNum, vector<int>* clockTimeArr) {
    for (int i = 0; i < 16; i++) {
        (*clockTimeArr)[i] -= (clockSwitch[switchNum][i] * 3);
    }
}

int minClick(vector<int> clockTimeArr, int*switchClickedTime, int num, int lastSwitch) {

    int clickSum = INF;
    bool isCase;

    //방법을 못찾고 돌아가는 경우
    for (int i = 0; i < 10; i++)
        if (switchClickedTime[i] == 4) {
            return INF;
        }

    isCase = true;
    for (int i = 0; i < 16; i++) {
        if (clockTimeArr[i] % 12 != 0) {
            isCase = false;
            break;
        }
    }
    //방법을 찾고 돌아가는 경우
    if (isCase) {
        cout << "num : " << num << "\n";
        return num;
    }


    for (int i = lastSwitch; i < 10; i++) {
        addArr(i, &clockTimeArr);
        switchClickedTime[i]++;
        clickSum = min(clickSum, minClick(clockTimeArr, switchClickedTime, num + 1, i));
        subtractArr(i, &clockTimeArr);
        switchClickedTime[i]--;
    }

    return clickSum;

}

int main()
{
    int C;
    int clockTime;
    int switchClickedTime[10] = { 0, };
    vector<vector<int>> clockTimeArrs;
    vector<int> clockTimeArr;
    makeClockSwitch();

    cin >> C;
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < 16; j++) {
            cin >> clockTime;
            clockTimeArr.push_back(clockTime);
        }
        clockTimeArrs.push_back(clockTimeArr);
        clockTimeArr.clear();
    }

   for (int i = 0; i < C; i++)
      cout << "답:" << minClick(clockTimeArrs[i], switchClickedTime, 0, 0) << "\n";
}


