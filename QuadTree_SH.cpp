#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<list>
#include<cstring>

using namespace std;

typedef struct node {
	char ch;
	struct node* child[4];
}Node;

Node* make_tree_node()
{
	Node* nd = new Node;
	for (int i = 0; i < 4; i++)
		nd->child[i] = NULL;
	return nd;
}

void make_subtree(Node* root, Node* child, int type)
{
	root->child[type] = child;
}


int recursive(char* input, Node* n, int idx)
{
	n->ch = input[idx];
	idx++;
	//printf("%d\n", idx);
	for (int i = 0; i < 4; i++)
	{
		Node* tmp = make_tree_node();
		
		if (input[idx] == 'x')
		{
			
			idx = recursive(input, tmp, idx);
		}
		else
		{
			tmp->ch = input[idx];
			idx++;
			//printf("%d\n", idx);
		}
		make_subtree(n, tmp, i);
		
	}
	return idx;

}

void preorder(Node* ptr)
{
	if (ptr) {
		printf("%c", ptr->ch);
		for (int i = 0; i < 4; i++) {
			preorder(ptr->child[i]);
		}
	}
}

void upsidedown_order(Node* ptr)
{
	if (ptr) {
		printf("%c", ptr->ch);
		upsidedown_order(ptr->child[2]);
		upsidedown_order(ptr->child[3]);
		upsidedown_order(ptr->child[0]);
		upsidedown_order(ptr->child[1]);
	}
}

int main()
{
	char input[1000];
	int len;
	int cur = 0;
	scanf("%s", input);
	len = strlen(input);

	Node* root = make_tree_node();
	if (len == 1)
	{
		printf("%c\n", input[0]);
		return 0;
	}
	else
	{
		recursive(input, root, 0);
	}

	upsidedown_order(root);

	return 0;
}