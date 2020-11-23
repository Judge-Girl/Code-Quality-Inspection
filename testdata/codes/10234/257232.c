#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
Node *treeAND(Node *root1, Node *root2)
{
	Node *current;
	if(root2 == NULL || root1 == NULL)
		return NULL;
	current = (Node*)malloc(sizeof(Node));
	current->val = root1->val*root2->val;
	current->left = treeAND(root1->left, root2->left);
	current->right = treeAND(root1->right, root2->right);
	return current;
}




Node *treeOR(Node *root1, Node *root2)
{
	Node *current;
	if(root2 == NULL && root1 == NULL)
		return NULL;
	current = (Node*)malloc(sizeof(Node));
	current->val = 0;
	if(root1 != NULL)
		current->val += root1->val;
	if(root2 != NULL)
		current->val += root2->val;
	if(root1 == NULL)
	{
		current->left = treeOR(root1, root2->left);
		current->right = treeOR(root1, root2->right);
	}
	else if(root2 == NULL)
	{
		current->left = treeOR(root1->left, root2);
		current->right = treeOR(root1->right, root2);
	}
	else
	{
		current->left = treeOR(root1->left, root2->left);
		current->right = treeOR(root1->right, root2->right);
	}
	return current;
	
}
