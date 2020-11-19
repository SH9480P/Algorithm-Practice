
#include <iostream>
using namespace std;


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

void deleteGameBoard(bool** gameBoard, int height) {
	for (int i = 0; i < height; i++)
		delete[] gameBoard[i];
	delete[] gameBoard;
}

void fillBoard(bool** gameBoard, int height, int width, int posY, int posX, int type) {
	switch (type)
	{
	case 0 :
		if (posY - 1 >= 0 && posX + 1 <= width) {
			gameBoard[posY][posX] = false;
			gameBoard[posY - 1][posX] = false;
			gameBoard[posY][posX + 1] = false;
		}
		break;
	case 1 :
		if (posY + 1 <= height && posX + 1 <= width) {
			gameBoard[posY][posX] = false;
			gameBoard[posY + 1][posX] = false;
			gameBoard[posY][posX + 1] = false;
		}
		break;
	case 2 :
		if (posY + 1 <= height && posX - 1 >= 0) {
			gameBoard[posY][posX] = false;
			gameBoard[posY + 1][posX] = false;
			gameBoard[posY][posX - 1] = false;
		}
		break;
	case 3 :
		if (posY - 1 >= 0 && posX - 1 >= 0) {
			gameBoard[posY][posX] = false;
			gameBoard[posY - 1][posX] = false;
			gameBoard[posY][posX - 1] = false;
		}
		break;
	default:
		break;
	}
}

void returnBoard(bool** gameBoard, int height, int width, int posY, int posX, int type) {
	switch (type)
	{
	case 0:
		if (posY - 1 >= 0 && posX + 1 <= width) {
			gameBoard[posY][posX] = true;
			gameBoard[posY - 1][posX] = true;
			gameBoard[posY][posX + 1] = true;
		}
		break;
	case 1:
		if (posY + 1 <= height && posX + 1 <= width) {
			gameBoard[posY][posX] = true;
			gameBoard[posY + 1][posX] = true;
			gameBoard[posY][posX + 1] = true;
		}
		break;
	case 2:
		if (posY + 1 <= height && posX - 1 >= 0) {
			gameBoard[posY][posX] = true;
			gameBoard[posY + 1][posX] = true;
			gameBoard[posY][posX - 1] = true;
		}
		break;
	case 3:
		if (posY - 1 >= 0 && posX - 1 >= 0) {
			gameBoard[posY][posX] = true;
			gameBoard[posY - 1][posX] = true;
			gameBoard[posY][posX - 1] = true;
		}
		break;
	default:
		break;
	}
}

int checkCases(bool** gameBoard, int height, int width, int lastPosY, int lastPosX, int type) {

	int posY = -1;
	int posX = -1;
	int cases = 0;

	for (int i = lastPosY; i < height; i++) {
		for (int j = lastPosX + 1; j < width; j++) {
			if (gameBoard[i][j] == true) {
				posY = i;
				posX = j;
				cout << "값 i :" << i << " ";
				cout << "값 j :" << j << "\n";
				break;
			}
		}
		if (posX != -1 && posY != -1)
			break;
	}

	if (posX == -1 && posY == -1) {
		for (int i = lastPosY; i < height; i++) {
			for (int j = lastPosX + 1; j < width; j++) {
				if (gameBoard[i][j] == true) {
					returnBoard(gameBoard, height, width, lastPosY, lastPosX, type);
					return 0;
				}
			};
		}
		return 1;
	}

	if (posX - 1 >= 0 && posY - 1 >= 0 && gameBoard[posY - 1][posX - 1] == true) {
		return 0;
	}


	for (int i = 0; i < 4; i++) {
		cout << "값 type :" << i << "\n";
		fillBoard(gameBoard, height, width, posX, posY, i);
		cases += checkCases(gameBoard, height, width, posX, posY, i);
		returnBoard(gameBoard, height, width, posX, posY, i);
	}

	return cases;
}

int main()
{
	int C;
	int height, width;
	bool** gameBoard;
	int caseNum[10] = { 0, };

	cin >> C;

	for (int i = 0; i < C; i++) {
		cin >> height >> width;
		gameBoard = makeGameBoard(height, width);
		caseNum[i] = checkCases(gameBoard, height, width, 0, -1, 0);
		deleteGameBoard(gameBoard, height);
	}

	for (int i = 0; i < C; i++) {
		cout << "case : " << caseNum[i] << "\n";
	}
}
