
#include <iostream>
#include <vector>

using namespace std;

typedef struct _node
{
	char color;
	struct _node* root[4];
}Node;

Node* makeNode(char color) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->root[0] = NULL;
	node->root[1] = NULL;
	node->root[2] = NULL;
	node->root[3] = NULL;
	node->color = color;
	return node;
}

int idx;

int reverse(int num) {
	switch (num)
	{
	case 0:
		return 2;
	case 1:
		return 3;
	case 2:
		return 0;
	case 3:
		return 1;
	}
}

void makeReverseQuadTree(Node*reverseTree, string originStr) {
	
	if (idx == originStr.size()) {
		return;
	}


	for (int i = 0; i < 4; i++) {
		switch (originStr[idx++])
		{
		case 'x':
			reverseTree->root[reverse(i)] = makeNode('x');
			makeReverseQuadTree(reverseTree->root[reverse(i)], originStr);
			break;
		case 'b':
			reverseTree->root[reverse(i)] = makeNode('b');
			break;
		case 'w':
			reverseTree->root[reverse(i)] = makeNode('w');
			break;
		}
	}
}

void printQuadTree(Node* tree) {

	for (int i = 0; i < 4; i++) {	
		if (tree->root[i] != NULL) {
			cout << tree->root[i]->color;
			if (tree->root[i]->color == 'x') {
				printQuadTree(tree->root[i]);
			}
		}
	}
}

int main()
{
	int C;
	string inputString;
	vector<string> compressedString;
	vector<bool> isUsed;


	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> inputString;
		compressedString.push_back(inputString);
	}

	for (int i = 0; i < C; i++) {
		idx = 1;
		Node* reverseTree = makeNode(compressedString[i][0]);
		makeReverseQuadTree(reverseTree, compressedString[i]);

		cout << i+1 << "번째 답 : ";
		cout << reverseTree->color;
		printQuadTree(reverseTree);
		cout << "\n";
	}
}


