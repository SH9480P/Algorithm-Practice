#include <iostream>
#include <string.h>
using namespace std;


// gameBoard[height][width] 를 만드는 함수
bool** makeGameBoard(int height, int width) {
	bool** gameBoard;
	string widthShape;

	gameBoard = new bool* [height];
	for (int i = 0; i < height; i++) {
		gameBoard[i] = new bool[width];
	}

	for (int i = 0; i < height; i++) {
		cin >> widthShape;
		for (int j = 0; j < width; j++) {
			if (widthShape[j] == '#')
				gameBoard[i][j] = false;
			else
				gameBoard[i][j] = true;
		}
	}

	return gameBoard;
}



// gameBoard를 없애는 함수
void deleteGameBoard(bool** gameBoard, int height) {
	for (int i = 0; i < height; i++)
		delete[] gameBoard[i];
	delete[] gameBoard;
}

void setFourCase(bool** fourCase, bool** testGameBoard, int i, int j, int height, int width) {
	if(i - 1 < 0 || j + 1 > width)
		fourCase[width * i + j][0] = false;
	else {
		if (testGameBoard[i - 1][j] == true && testGameBoard[i][j + 1] == true)
			fourCase[width * i + j][0] = true;
		else
			fourCase[width * i + j][0] = false;
	}

	if (i + 1 > height || j + 1 > width)
		fourCase[width * i + j][1] = false;
	else {
		if (testGameBoard[i + 1][j] == true && testGameBoard[i][j + 1] == true)
			fourCase[width * i + j][1] = true;
		else
			fourCase[width * i + j][1] = false;
	}

	if (i + 1 > height || j - 1 < 0)
		fourCase[width * i + j][2] = false;
	else {
		if (testGameBoard[i + 1][j] == true && testGameBoard[i][j - 1] == true)
			fourCase[width * i + j][2] = true;
		else
			fourCase[width * i + j][2] = false;
	}

	if(i - 1 < 0 || j - 1 < 0)
		fourCase[width * i + j][3] = false;
	else {
		if (testGameBoard[i - 1][j] == true && testGameBoard[i][j - 1] == true)
			fourCase[width * i + j][3] = true;
		else
			fourCase[width * i + j][3] = false;
	}
}

int recursionCheck(bool** fourCase, bool** testGameBoard, int height, int width, int num) {

	int caseNum = 0;

	if (num == height * width) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (testGameBoard[i][j] == false)
					return 0;
			}
		}
		return 1;
	}

	if (num / width - 1 >= 0 && num % width - 1 >= 0 && testGameBoard[num / width - 1][num % width] == false)
		return 0;

	for (int i = 0; i < 4; i++) {
		if (fourCase[num][i] == true) {
			switch (i)
			{
			case 0:
				testGameBoard[num / width - 1][num % width] = false;
				testGameBoard[num / width][num % width + 1] = false;
				caseNum += recursionCheck(fourCase, testGameBoard, height, width, num + 1);
				testGameBoard[num / width - 1][num % width] = true;
				testGameBoard[num / width][num % width + 1] = true;
				break;
			case 1:
				testGameBoard[num / width + 1][num % width] = false;
				testGameBoard[num / width][num % width + 1] = false;
				caseNum += recursionCheck(fourCase, testGameBoard, height, width, num + 1);
				testGameBoard[num / width + 1][num % width] = true;
				testGameBoard[num / width][num % width + 1] = true;
				break;
			case 2:
				testGameBoard[num / width + 1][num % width] = false;
				testGameBoard[num / width][num % width - 1] = false;
				caseNum += recursionCheck(fourCase, testGameBoard, height, width, num + 1);
				testGameBoard[num / width + 1][num % width] = true;
				testGameBoard[num / width][num % width - 1] = true;
				break;
			case 3:
				testGameBoard[num / width - 1][num % width] = false;
				testGameBoard[num / width][num % width - 1] = false;
				caseNum += recursionCheck(fourCase, testGameBoard, height, width, num + 1);
				testGameBoard[num / width - 1][num % width] = true;
				testGameBoard[num / width][num % width - 1] = true;
				break;
			default:
				break;
			}
		}
	}
	return caseNum;
}

int caseOfAllCovered(bool** gameBoard, int height, int width) {
	bool** testGameBoard;
	bool** fourCase;

	testGameBoard = new bool* [height];
	for (int i = 0; i < height; i++) {
		testGameBoard[i] = new bool[width];
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			testGameBoard[i][j] = gameBoard[i][j];
		}
	}

	fourCase = new bool* [height * width];
	for (int i = 0; i < 4; i++) {
		fourCase[i] = new bool[width];
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (testGameBoard[i][j] == true)
				setFourCase(fourCase, testGameBoard, i, j, height, width);
			else {
				fourCase[i * width + j][0] = false;
				fourCase[i * width + j][1] = false;
				fourCase[i * width + j][2] = false;
				fourCase[i * width + j][3] = false;
			}
		}
	}
	
	return recursionCheck(fourCase, testGameBoard, height, width, 0);
}



int main(void) {

	int C;
	int height, width;
	bool** gameBoard;

	cin >> C;

	for (int i = 0; i < C; i++) {
		cin >> height >> width; 
		gameBoard = makeGameBoard(height, width); 
		cout << caseOfAllCovered(gameBoard, height, width) << "\n";
		deleteGameBoard(gameBoard, height); 
	}

	return 0;
}