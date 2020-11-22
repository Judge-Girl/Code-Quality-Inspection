#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node *treeAND(Node *root1, Node *root2){
	if(root1 == NULL || root2 == NULL)
		return NULL;
	Node *root3 = (Node *)malloc(sizeof(Node));
	root3->val = root1->val * root2->val;
	root3->left = treeAND(root1->left, root2->left);
	root3->right = treeAND(root1->right, root2->right);
	return root3;
}

Node *treeOR(Node *root1, Node *root2){
	if(root1 == NULL && root2 == NULL){
		return NULL;
	}
	Node *root3 = (Node *)malloc(sizeof(Node));
	root3->val = 0;
	if(root1 == NULL){
		root3->val = root2->val;
		root3->left = treeOR(NULL, root2->left);
		root3->right = treeOR(NULL, root2->right);
	}
	else if(root2 == NULL){
		root3->val = root1->val;
		root3->left = treeOR(NULL, root1->left);
		root3->right = treeOR(NULL, root1->right);
	}
	else{
		root3->val = root1->val + root2->val;
		root3->left = treeOR(root2->left, root1->left);
		root3->right = treeOR(root2->right, root1->right);
	}
	return root3;
}
