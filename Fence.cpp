
#include <iostream>
#include <vector>

using namespace std;


int minimumHeight(vector<int> fenceHeight, int num) {
	
	int currentHeight;
	int rightWidth, leftWidth;
	int maximumSize = -1;
	for (int i = 0; i < num; i++) {
		currentHeight = fenceHeight[i];
		rightWidth = 0;
		leftWidth = 0;

		for (int j = i; j < num; j++) {
			if (fenceHeight[j] < currentHeight)
				break;
			rightWidth++;
		}

		for (int j = i; j >= 0; j--) {
			if (fenceHeight[j] < currentHeight)
				break;
			leftWidth++;
		}

		maximumSize = max(maximumSize, currentHeight * (leftWidth + rightWidth - 1));
	}
	return maximumSize;
}

int main()
{
	int C; 
	int N; 
	int height;
	vector<int> fenceHeight;
	vector<int> answer;


	cin >> C;
	for (int i = 0; i < C; i++) {

		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> height;
			fenceHeight.push_back(height);
		}
		answer.push_back(minimumHeight(fenceHeight, N));
		fenceHeight.clear();
	}

	for (int i = 0; i < C; i++) {
		cout << answer[i] << "\n";
	}

}


