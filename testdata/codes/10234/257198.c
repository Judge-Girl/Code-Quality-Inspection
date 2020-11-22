#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int val;
    struct Node *left, *right;
} Node;
 
Node *treeAND(Node *root1, Node *root2){
	Node *root = (Node *)malloc(sizeof(Node));
	root -> val = root1 -> val * root2 -> val;
	if(root1 -> left != NULL && root2 -> left != NULL){
		root -> left = treeAND(root1 -> left, root2 -> left);
	}
	else{
		root -> left = NULL;
	}
	if(root1 -> right != NULL && root2 -> right != NULL){
		root -> right = treeAND(root1 ->right, root2 ->right);
	}
	else{
		root -> right = NULL;
	}
	return root;
}
Node *treeOR(Node *root1, Node *root2){
	Node *root = (Node *)malloc(sizeof(Node));
	root -> val = root1 -> val + root2 -> val;
	if(root1 -> left != NULL && root2 ->left != NULL){
		root -> left = treeOR(root1 -> left, root2 -> left);
	}
	else if(root1 -> left != NULL){
		root -> left = root1 -> left;
	}
	else if(root2 -> left != NULL){
		root -> left = root2 -> left;
	}
	else{
		root -> left = NULL;
	}
	if(root1 -> right != NULL && root2 ->right != NULL){
		root -> right = treeOR(root1 -> right, root2 -> right);
	}
	else if(root1 -> right != NULL){
		root -> right = root1 -> right;
	}
	else if(root2 -> right != NULL){
		root -> right = root2 -> right;
	}
	else{
		root -> right = NULL;
	}
	return root;
}
