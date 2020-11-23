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
void insert(Node *&root, Node *node, int position)
{
	if (root == NULL) {
		root = node;
	} else if (node->tag == root->tag && position > root->left_count &&
			position - 1  <= root->left_count + root->count) {
		root->count += node->count;
		free(node);
	} else if (position - 1 <= root->left_count) {
		root->left_count += node->count;
		insert(root->left, node, position);
		if (root->left->priority < root->priority)
			right_rotate(root);
	} else if (position > root->left_count + root->count) { 
		insert(root->right, node, position - root->left_count - root->count);
		if (root->right->priority < root->priority)
			left_rotate(root);
	} else {
		int right_count = root->left_count + root->count - position + 1;
		//printf("%d %d %d\n", position, root->left_count, root->count);
		Node *right = new_node(root->tag, right_count);
		root->count -= right_count;
		insert(root->right, right, 1);
		//if (root->right->priority < root->priority)
		//	left_rotate(root);
		insert(root->right, node, 1);
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
			Node *node = new_node(tag, count);
			if (cmd[0] == 'l') {
				position = 1;
			} else if (cmd[0] == 'r') {
				position = n + 1;
			} else {
				position = atoi(cmd);
			}
			insert(root, node, position);
			n += count;
		}
		
	}
	return 0;
}

