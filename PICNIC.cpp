#include <iostream>
#include <string.h>
using namespace std;

int** MakeRelationTable(int n, int m) {
	int** relation;
	int friend1, friend2;

	relation = new int* [n];
	for (int i = 0; i < n; i++) {
		relation[i] = new int[n];
		memset(relation[i], 0, sizeof(int) * n);
	}



	for (int i = 0; i < m; i++) {
		cin >> friend1 >> friend2;
		relation[friend1][friend2] = 1;
		relation[friend2][friend1] = 1;
	}

	return relation;
}

void DeleteRelationTable(int** relation, int n) {
	for (int i = 0; i < n; i++)
		delete[] relation[i];
	delete[] relation;
}

int CountCase(int n, int** relation_table, bool* called, int friend_made) {

	int count_case = 0;
	

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (relation_table[i][j] == 1 && called[i] == false && called[j] == false) {
					called[i] = true;
					called[j] = true;
					friend_made++;
					
					if (friend_made == n / 2) {
						called[i] = false;
						called[j] = false;
						friend_made -= 1;
						return 1;
					}
					

					count_case += CountCase(n, relation_table, called, friend_made);
					called[i] = false;
					called[j] = false;
					friend_made -= 1;
				}
			}
		}
		

	return count_case;

}

int factorial(int n) {
	if (n == 1)
		return 1;
	return n * factorial(n - 1);
}

int main(void) {
	int C, n, m;
	int** relation; // ���� ģ���� �� �� �ִ��� �˷��ִ� ���߹迭
	int case_num[50] = { 0, }; //����� ������ ��Ƴ��� �迭
	int friend_made; // ģ������ ������� ����
	bool called[10]; //� ������� �̹� ¦�� ��� ģ���� �ƴ��� �Ǵ��ϱ� ���� ��

	for (int i = 0; i < 10; i++)
		called[i] = false;

	cin >> C; //�׽�Ʈ ���̽� �Է�

	for (int i = 0; i < C; i++) {
		cin >> n >> m; //��� ��, ģ�� ���� �� �Է�
		relation = MakeRelationTable(n, m); // �����Ҵ� �迭 ����
		friend_made = 0;
		case_num[i] = CountCase(n, relation, called, friend_made) / factorial(n/2) ; //����Ǽ�
		DeleteRelationTable(relation, n); //�����Ҵ� �迭 ����
	}

	for (int i = 0; i < C; i++)
		cout << case_num[i] << "\n";

	return 0;
}