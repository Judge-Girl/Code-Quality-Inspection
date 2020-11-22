#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node *createNode()
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->val = 0;
	return newNode;
}

Node *treeAND(Node *root1, Node *root2)
{
	if (root1 == NULL || root2 == NULL)
		return NULL;
	root1->left = treeAND(root1->left, root2->left);
	root1->right = treeAND(root1->right, root2->right);
	root1->val *= root2->val;
	return root1;
}

Node *treeOR(Node *root1, Node *root2)
{
	if (root1 == NULL && root2 == NULL)
		return NULL;

	int val = 0;
	if (root1 == NULL) {
		root1 = createNode();
	} else if (root2 == NULL) {
		root2 = createNode();
	}
	root1->left = treeOR(root1->left, root2->left);
	root1->right = treeOR(root1->right, root2->right);
	root1->val += root2->val;
	return root1;
}
