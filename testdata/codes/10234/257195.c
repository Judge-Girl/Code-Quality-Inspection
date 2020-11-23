#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

Node *treeAND(Node *root1, Node *root2) {
	if (root1 != NULL && root2 != NULL) {
		struct Node *newNode = malloc(sizeof(struct Node));
		newNode->val = root1->val * root2->val;
		newNode->left = treeAND(root1->left, root2->left);
		newNode->right = treeAND(root1->right, root2->right);
		return newNode;
	}
	else return NULL;
}

Node *treeOR(Node *root1, Node *root2) {
	if (root1 != NULL && root2 != NULL) {
		struct Node *newNode = malloc(sizeof(struct Node));
		newNode->val = root1->val + root2->val;
		newNode->left = treeOR(root1->left, root2->left);
		newNode->right = treeOR(root1->right, root2->right);
		return newNode;
	}
	else if (root1 != NULL) {
		return root1;
	}
	else if (root2 != NULL) {
		return root2;
	}
	else return NULL;
}

