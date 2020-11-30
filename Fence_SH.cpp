#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

int n;

void check_left(vector<int> fence, int height, int idx, int * res)
{
	if (idx < 0 || fence[idx] < height)
		return;
	else
	{
		(*res)++;
		check_left(fence, height, idx - 1, res);
	}
}
void check_right(vector<int> fence, int height, int idx, int* res)
{
	if (idx >= n || fence[idx] < height)
		return;
	else
	{
		(*res)++;
		check_right(fence, height, idx + 1, res);
	}
}

int main()
{
	vector<int> fence;
	int height;
	int base_line;
	int max_size = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &height);
		fence.push_back(height);
	}

	for (int i = 0; i < n; i++)
	{
		int size = 0;
		base_line = 1;
		check_left(fence, fence[i], i - 1, &base_line);
		check_right(fence, fence[i], i + 1, &base_line);

		size = (base_line) * fence[i];
		if (size > max_size)
			max_size = size;
	}

	printf("%d\n", max_size);

	return 0;
}