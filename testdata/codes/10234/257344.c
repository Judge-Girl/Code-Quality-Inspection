#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
Node *treeAND(Node *root1, Node *root2){
	Node* C=NULL;
	if(root1==NULL || root2==NULL)return C;
	C = (Node *) malloc(sizeof(Node));
	C->val=root1->val*root2->val;
	C->left=treeAND(root1->left,root2->left); 
	C->right=treeAND(root1->right,root2->right); 
	return C;
}
Node *treeOR(Node *root1, Node *root2){
	Node* C=NULL;
	if(root1==NULL && root2==NULL)return C;
	C = (Node *) malloc(sizeof(Node));
	if(root1==NULL){
		C->val=root2->val;
		C->left=treeOR(root1,root2->left); 
		C->right=treeOR(root1,root2->right); 
		return C;
	}
	else if(root2==NULL){
		C->val=root1->val;
		C->left=treeOR(root1->left,root2); 
		C->right=treeOR(root1->right,root2); 
		return C;
	}
	else{
		C->val=root1->val+root2->val;
		C->left=treeOR(root1->left,root2->left); 
		C->right=treeOR(root1->right,root2->right); 
		return C;
	}
}
