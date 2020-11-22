#include<stdio.h>
#include<stdlib.h>
#include "tree.h"

Node *treeOR(Node *root1, Node *root2){
	Node *ans;
	ans = (Node *)malloc(sizeof(Node));
	if(root1 != NULL && root2 == NULL){
		return root1;
	}
	else if(root1 == NULL && root2 != NULL){
		return root2;
	}
	else if(root1 == NULL && root2 == NULL){
		return NULL;
	}
	
	ans -> val = (root1 -> val) + (root2 -> val);
	ans -> left = treeOR(root1 -> left, root2 -> left);
	ans -> right = treeOR(root1 -> right, root2 -> right);
	
	return ans;
}










Node *treeAND(Node *root1, Node *root2)
{
	Node *ans;
	ans = (Node *)malloc(sizeof(Node));
	if(root1 != NULL && root2 == NULL){
		return NULL;
	}
	else if(root1 == NULL && root2 != NULL){
		return NULL;
	}
	else if(root1 == NULL && root2 == NULL){
		return NULL;
	}
	
	ans -> val = (root1 -> val) * (root2 -> val);
	ans -> left = treeAND(root1 -> left, root2 -> left);
	ans -> right = treeAND(root1 -> right, root2 -> right);
	
	return ans;
	
}
