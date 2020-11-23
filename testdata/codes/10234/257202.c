//tree.c
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
/* typedef struct Node{
    int val;
    struct Node *left, *right;
} Node; */
	
Node *treeAND(Node *root1, Node *root2)
{
	Node *root;
	if(root1 == NULL || root2 == NULL)
		return NULL;
	else
	{
		root = (Node *)malloc(sizeof(Node) );
		root->val = (root1->val) * (root2->val);
		root->left = treeAND(root1->left, root2->left);
		root->right = treeAND(root1->right, root2->right);
		return root;
	}
}

Node *treeOR(Node *root1, Node *root2)
{
	Node *root;
	if(root1 == NULL && root2 == NULL) //don't have either root1 or root2
		return NULL;
	else
	{
		root = (Node *)malloc(sizeof(Node) );
		//assign node value, left, right
		if(root1 != NULL && root2 != NULL) //have both root1, root2
		{
			root->val = (root1->val) + (root2->val);
			root->left = treeOR(root1->left, root2->left);
			root->right = treeOR(root1->right, root2->right);
			return root;
		}
		else if(root1 != NULL) //only has root1
		{
			root->val = root1->val;
			root->left = root1->left;
			root->right = root1->right;
			return root;
		}
		else //only has root2
		{
			root->val = root2->val;
			root->left = root2->left;
			root->right = root2->right;
			return root;
		}
	}
}

