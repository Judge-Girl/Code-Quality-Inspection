#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node *treeAND(Node *root1, Node *root2)
{
	Node *cur1 = root1;
	Node *cur2 = root2;
	if(cur1 == NULL || cur2 == NULL)
		return NULL;
	else if(cur1 != NULL && cur2 != NULL){
		Node *root = (Node *) malloc(sizeof(Node));
	    root->val = (cur1->val)*(cur2->val);
	    root->left = treeAND(cur1->left, cur2->left);
	    root->right = treeAND(cur1->right, cur2->right);
	    return root;
	}
}
Node *treeOR(Node *root1, Node *root2)
{
	Node *cur1 = root1;
	Node *cur2 = root2;
	if(cur1 != NULL && cur2 != NULL){
		Node *root = (Node *) malloc(sizeof(Node));
	    root->val = (cur1->val)+(cur2->val);
	    root->left = treeOR(cur1->left, cur2->left);
	    root->right = treeOR(cur1->right, cur2->right);
	    return root;
	}
	else if(cur1 != NULL && cur2 == NULL)
		return cur1;
	else if(cur1 == NULL && cur2 != NULL)
		return cur2;
	else
		return NULL;
}

