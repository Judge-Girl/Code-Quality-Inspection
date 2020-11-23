#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"


Node *treeAND(Node *root1, Node *root2){
	if(root1 == NULL || root2 == NULL)
		return NULL;
	else{
		Node *root = (Node *)malloc(sizeof(Node));
		root->val = root1->val * root2-> val;
		root->right = treeAND(root1->right,root2->right);
		root->left = treeAND(root1-> left, root2->left);
		return root;
	}
}
Node *treeOR(Node *root1, Node *root2){
	if(root1 == NULL && root2 == NULL)
		return NULL;
	else{
		Node *root = (Node *)malloc(sizeof(Node));
		if(root2 == NULL){
			root->val = root1->val;
			root->right = root1->right;
			root->left = root1-> left;
		}
		else if(root1 == NULL){
			root->val = root2->val;
			root->right = root2->right;
			root->left = root2-> left;
		}
		else{
			root->val = root1->val + root2-> val;
			root->right = treeOR(root1->right,root2->right);
			root->left = treeOR(root1-> left, root2->left);
		}
		return root;
	}

	return NULL;
}
