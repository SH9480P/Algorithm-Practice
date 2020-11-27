#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

bool check_white_space(vector<vector<char>> board, int h, int w)
{
	int white = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (board[i][j] == '.')
				white++;
		}
	}

	if (white % 3 == 0)
		return true;
	else
		return false;
}


bool invalid(vector<vector<char>> board, int h, int w, int row, int col, int type)
{
	
	if (board[row][col] == '#' || board[row][col] == '/')
		return true;
	switch (type)
	{
	case 1:
		if (row - 1 <= 0 || col + 1 >= w)
			return true;
		else if (board[row - 1][col] == '#' || board[row - 1][col] == '/' || board[row][col + 1] == '/' || board[row][col + 1] == '#')
			return true;
		break;
	case 2:
		if (row - 1 <= 0 || col - 1 <= 0)
			return true;
		else if (board[row - 1][col] == '#' || board[row - 1][col] == '/' || board[row][col - 1] == '/' || board[row][col - 1] == '#')
			return true;
		break;
	case 3:
		if (row + 1 >= h || col + 1 >= w)
			return true;
		else if (board[row + 1][col] == '#' || board[row + 1][col] == '/' || board[row][col + 1] == '/' || board[row][col + 1] == '#')
			return true;
		break;
	case 4:
		if (row + 1 >= h || col - 1 <= 0)
			return true;
		else if (board[row + 1][col] == '#' || board[row + 1][col] == '/' || board[row][col - 1] == '/' || board[row][col - 1] == '#')
			return true;
		break;
	case 0:
		break;
	default:
		printf("TypeError\n");

	}
	return false;
}

int full_check(vector<vector<char>> board, int h, int w)
{
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
		{
			if (board[i][j] == '.')
				return 1;
		}
	}
	return 0;
}

void vector_clear(vector<vector<char>> board, int h, int w)
{
	for (int i = 0; i < h; i++)
	{
		board[i].clear();
		vector<char>().swap(board[i]);
	}
	board.clear();
	vector<vector<char>>().swap(board);
}

int recursive(vector<vector<char>> board, int h, int w, int idx, int* res)
{
	if (idx >= h * w)
	{
		if (!full_check(board, h, w))
		{
			(*res)++;
		}
		return 0;
	}

	vector<vector<char>> temp = board;
	int row, col;
	row = idx / w;
	col = idx % w;

	//pass
	recursive(temp, h, w, idx + 1, res);
	
	//1
	if (!invalid(board, h, w, row, col, 1))
	{
		temp = board;
		temp[row][col] = '/';
		temp[row - 1][col] = '/';
		temp[row][col + 1] = '/';
		recursive(temp, h, w, idx + 1, res);
	}
	//2
	if (!invalid(board, h, w, row, col, 2))
	{
		temp = board;
		temp[row][col] = '/';
		temp[row - 1][col] = '/';
		temp[row][col - 1] = '/';
		recursive(temp, h, w, idx + 1, res);
	}
	//3
	if (!invalid(board, h, w, row, col, 3))
	{
		temp = board;
		temp[row][col] = '/';
		temp[row + 1][col] = '/';
		temp[row][col + 1] = '/';
		recursive(temp, h, w, idx + 1, res);
	}
	//4
	if (!invalid(board, h, w, row, col, 4))
	{
		temp = board;
		temp[row][col] = '/';
		temp[row + 1][col] = '/';
		temp[row][col - 1] = '/';
		recursive(temp, h, w, idx + 1, res);
	}

	vector_clear(temp, h, w);
	vector_clear(board, h, w);
	
}

int main()
{
	//보드 채우기
	int h, w;
	int result = 0;
	scanf("%d %d", &h, &w);
	vector<vector<char>> board(h);
	
	for (int j = 0; j < h; j++)
	{
		//vector<char> vtmp;
		char* c = new char[w + 1];
		scanf("%s", c);
		for (int k = 0; k < w; k++)
		{
			board[j].push_back(c[k]);
		}
		
		delete[] c;
		
	}
	//흰 칸이 3 배수인지 검사
	if (!check_white_space(board, h, w))
	{
		printf("0\n");
		return 0;
	}

	recursive(board, h, w, 0, &result);

	printf("%d\n", result);

	/*for (int i = 0; i < h*w; i++) {
		int row = i / w;
		int col = i % w;
		printf("%c ", board[row][col]);
		if (col == w - 1)
			printf("\n");
	}*/
	return 0;
}