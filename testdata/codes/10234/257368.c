#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


Node *treeAND(Node *root1, Node *root2)
{
	if(root1 == NULL || root2 == NULL) return NULL;
	Node *new = (Node*)malloc(sizeof(Node));
	new->val = root1->val * root2->val;
	new->left = treeAND(root1->left, root2->left);
	new->right = treeAND(root1->right, root2->right);
	return new;
}

Node *treeOR(Node *root1, Node *root2)
{
	if(root1 == NULL && root2 == NULL) return NULL;
	Node *new = (Node*)malloc(sizeof(Node));
	if(root1 == NULL)
	{
		new->val = root2->val;
		new->left = treeOR(NULL, root2->left);
		new->right = treeOR(NULL, root2->right);
		return new;
	}
	if(root2 == NULL)
	{
		new->val = root1->val;
		new->left = treeOR(root1->left, NULL);
		new->right = treeOR(root1->right, NULL);
		return new;
	}
	else
	{
		new->val = root1->val + root2->val;
		new->left = treeOR(root1->left, root2->left);
		new->right = treeOR(root1->right, root2->right);
		return new;
	}
	
}
