#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define LEN 11
typedef struct tree {
	char c;
	int len;
	int leftlen;
	struct tree *left;
	struct tree *right;
} Tree;

Tree *genNode(char c, int len, int leftlen, Tree *left, Tree *right)
{
	Tree *new = (Tree *)malloc(sizeof(Tree));
	assert(new != NULL);
	new->c = c;
	new->len = len;
	new->leftlen = leftlen;
	new->left = left;
	new->right = right;
	return new;
}
void printTree(Tree *tree)
{
	if (tree == NULL)
		return;
	printTree(tree->left);
	printf("%c %d ", tree->c, tree->len);
	printTree(tree->right);
	return;
}
//start == n means that there should be (n - 1) elements on this node's left.
Tree *insertNode(Tree *tree, char c, int start, int len)
{
	if (tree == NULL)
		return genNode(c, len, 0, NULL, NULL);
	if (c == tree->c && start - 1 >= tree->leftlen && start - 1 <= tree->leftlen + tree->len)
		tree->len += len;
	else if (start - 1 <= tree->leftlen) {
		tree->leftlen += len;
		tree->left = insertNode(tree->left, c, start, len);
	} else if (start - 1 >= tree->leftlen + tree->len)
		tree->right = insertNode(tree->right, c, start - tree->leftlen - tree->len, len);
	else {
		Tree *left = genNode(tree->c, start - tree->leftlen - 1, tree->leftlen, tree->left, NULL);
		Tree *right = genNode(tree->c, tree->len - left->len, 0,  NULL, tree->right);
		tree->c = c;
		tree->len = len;
		tree->leftlen += left->len;
		tree->left = left;
		tree->right = right;
	}
	return tree;
}
void Process(Tree *tree)
{
	int len = 0;
	char command[LEN] = {0};
	char temp[2] = {0};
	while (scanf("%s", command) != EOF) {
		if (strcmp(command, "print") == 0) {
			printTree(tree);
			printf("$\n");
		} else {
			char c;
			int pos, num;
			scanf("%s%s%d", command, temp, &num);
			c = temp[0];
			if (strcmp(command, "right") == 0)
				pos = len + 1;
			else if (strcmp(command, "left") == 0)
				pos = 1;
			else
				pos = atoi(command);
			tree = insertNode(tree, c, pos, num);
			len += num;
		}
	}
	return;
}
void freeTree(Tree *tree)
{
	if (tree == NULL)
		return;
	freeTree(tree->left);
	freeTree(tree->right);
	free(tree);
	return;
}
int main(void)
{
	Tree *tree = NULL;
	Process(tree);
	freeTree(tree);
	return 0;
}

