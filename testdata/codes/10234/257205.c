#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
// typedef struct Node{
//     int val;
//     struct Node *left, *right;
// } Node;
 
Node *treeAND(Node *root1, Node *root2){
	if(root1 == NULL || root2 == NULL)return NULL;
	Node * curr = (Node *)malloc(sizeof(Node));
	curr->val = root1->val * root2->val;
	curr->left = treeAND(root1->left,root2->left);
	curr->right = treeAND(root1->right,root2->right);
	return curr;
}
Node *treeOR(Node *root1, Node *root2){
	if(root1 == NULL && root2 == NULL)return NULL;
	Node * curr = (Node *)malloc(sizeof(Node));
	int tmp1 = 0,tmp2 = 0;
	Node *tmp1Left = NULL,*tmp1Right = NULL;
	Node *tmp2Left = NULL,*tmp2Right = NULL;
	if(root1 != NULL){tmp1 = root1->val;tmp1Left = root1->left;tmp1Right = root1->right;}
	if(root2 != NULL){tmp2 = root2->val;tmp2Left = root2->left;tmp2Right = root2->right;}
	curr->val = tmp1 + tmp2;
	curr->left = treeOR(tmp1Left,tmp2Left);
	curr->right = treeOR(tmp1Right,tmp2Right);
	return curr;
}
