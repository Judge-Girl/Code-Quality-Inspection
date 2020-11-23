#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"
 
Node *treeAND(Node *root1, Node *root2){
	Node *current;
	if (root1 != NULL && root2 != NULL){
		current = (Node *)malloc(sizeof(Node));
		assert(current != NULL);
		current->val = root1->val * root2->val;
		current->left = treeAND(root1->left , root2->left);
		current->right = treeAND(root1->right , root2->right);
		return (current);
	}
	else
		return NULL;
}
Node *treeOR(Node *root1, Node *root2){
	Node *current;
	if (root1 != NULL || root2 != NULL){
		current = (Node *)malloc(sizeof(Node));
		assert(current != NULL);
		
		current->val = 0;
		if (root1 != NULL){
			current->val += root1->val;
		}
		if (root2 != NULL) 
			current->val += root2->val;
		if (root1 == NULL){
			current->left = treeOR(NULL , root2->left);
			current->right = treeOR(NULL , root2->right);
		}
		else if (root2 == NULL){
			current->left = treeOR(root1->left , NULL);
			current->right = treeOR(root1->right , NULL);
		}
		else {
			current->left = treeOR(root1->left , root2->left);
			current->right = treeOR(root1->right , root2->right);
		}
		return (current);
	}
	else{
		return NULL;
	}
}
