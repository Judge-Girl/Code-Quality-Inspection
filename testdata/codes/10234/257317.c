#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
Node *treeAND(Node *root1, Node *root2)
{
	if (root1 == NULL || root2 == NULL)
		return NULL;
	Node *current = (Node*)malloc(sizeof(Node));
	current->val = root1->val * root2->val;
	current->left = treeAND(root1->left, root2->left);
	current->right = treeAND(root1->right, root2->right);	
	return current;
}
Node *treeOR(Node *root1, Node *root2)
{
	if (root1 == NULL && root2 == NULL)
		return NULL;
	Node *current = (Node*)malloc(sizeof(Node));
	if (root1 == NULL) {
		current = root2;
		return current;
	} else if (root2 == NULL) {
		current = root1;
		return current;
	}
	current->val = root1->val + root2->val;
	current->left = treeOR(root1->left, root2->left);
	current->right = treeOR(root1->right, root2->right);	
	return current;
} 

