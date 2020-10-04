#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

bool isalltrue(vector<bool> list)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i] == false)
			return false;
	}
	return true;
}

void recursive(vector<vector<int>> graph, vector<bool> boolist, int* ptresult)
{
	int start;
	vector<bool> templist = boolist;
	for (int i = 0; i < boolist.size(); i++)
	{
		if (boolist[i] == false) {
			start = i;
			break;
		}
	}

	for (int i = 0; i < graph[start].size(); i++)
	{
		if (templist[graph[start][i]] == false) {
			templist[start] = true;
			templist[graph[start][i]] = true;
			if (isalltrue(templist))
			{
				(*ptresult)++;
				return;
			}
			else
				recursive(graph, templist, ptresult);
			templist = boolist;
		}
		else
			continue;
	}
}

int main()
{
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		int students, pairs;
		cin >> students >> pairs;
		vector<int> picked;
		vector<vector<int>> graph(students);
		vector<bool> boollist(students, false);
		int result = 0;

		vector<int> v(pairs * 2);
		int vtemp;
		for (int i = 0; i < pairs * 2; i++)
		{
			cin >> vtemp;
			v[i] = vtemp;
		}
		clock_t start, end; 
		double seconds;
		start = clock(); 

		for (int i = 0; i < pairs; i++)
		{
			int a = v[i * 2];
			int b = v[i * 2 + 1];
			if (a > b)
			{
				a = v[i * 2 + 1];
				b = v[i * 2];
			}
			graph[a].push_back(b);
		}

		recursive(graph, boollist, &result);

		cout << result << endl;
		end = clock();
		seconds = (double)(end - start);
		cout << "time : " << seconds << " microseconds" << endl;

	}

	return 0;
}