#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct Node {
	Node* right;
	Node* left;
	char tag;
	int count;
	int left_count;
	int priority;
} Node;

Node *new_node(char tag, int count)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->tag = tag;
	node->count = count;
	node->left_count = 0;
	node->priority = rand();
	node->left = NULL;
	node->right = NULL;
	return node;
}

void right_rotate(Node *&node)
{
	Node *left = node->left;
	node->left_count -= left->left_count + left->count;
	node->left = left->right;
	left->right = node;
	node = left;
}
void left_rotate(Node *&node)
{
	Node *right = node->right;
	right->left_count += node->left_count + node->count;
	node->right = right->left;
	right->left = node;
	node = right;

}
void insert(Node *&root, char tag, int count, int position)
{
	if (root == NULL) {
		root = new_node(tag, count);
	} else if (tag == root->tag && position >= root->left_count &&
			position <= root->left_count + root->count) {
		root->count += count;
	} else if (position <= root->left_count) {
		root->left_count += count;
		insert(root->left, tag, count, position);
		if (root->left->priority < root->priority)
			right_rotate(root);
	} else if (position >= root->left_count + root->count) { 
		insert(root->right, tag, count, position - root->left_count - root->count);
		if (root->right->priority < root->priority)
			left_rotate(root);
	} else {
		int right_count = root->left_count + root->count - position;
		root->count -= right_count;
		insert(root->right, root->tag, right_count, 0);
		insert(root->right, tag, count, 0);
		if (root->right->priority < root->priority)
			left_rotate(root);
	}
}

void print(Node *node)
{
	if (node == NULL) return;
	print(node->left);
	printf("%c %d ", node->tag, node->count);
	print(node->right);
}

int main()
{
	char cmd[256];
	Node *root = NULL;
	int n = 0;
	while (~scanf("%s", cmd)) {
		if (cmd[0] == 'p') {
			print(root);
			printf("$\n");
		} else {
			int position, count;
			char tag;
			scanf("%s %c %d", cmd, &tag, &count);
			if (cmd[0] == 'l') {
				position = 1;
			} else if (cmd[0] == 'r') {
				position = n + 1;
			} else {
				position = atoi(cmd);
			}
			insert(root, tag, count, position - 1);
			n += count;
		}
		
	}
	return 0;
}

