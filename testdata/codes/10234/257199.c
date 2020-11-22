#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *left, *right;
} Node;
 
Node *treeAND(Node *root1, Node *root2){
	Node *head;
	head = (Node *) malloc(sizeof(Node));
	
	if(root1->left != NULL && root2->left != NULL){
		head->left = treeAND(root1->left, root2->left);
	}
	else head->left = NULL;
	
	if(root1->right != NULL && root2->right != NULL){
		head->right = treeAND(root1->right, root2->right);
	}
	else head->right = NULL;
	
	head->val = root1->val * root2->val;
	return head;
}

Node *treeOR(Node *root1, Node *root2){
	Node *head;
	head = (Node *) malloc(sizeof(Node));
	
	if(root1->left != NULL && root2->left != NULL){
		head->left = treeOR(root1->left, root2->left);
	}
	else if(root1->left != NULL) head->left = root1->left;
	else if(root2->left != NULL) head->left = root2->left;
	else head->left = NULL;
	
	if(root1->right != NULL && root2->right != NULL){
		head->right = treeOR(root1->right, root2->right);
	}
	else if(root1->right != NULL) head->right = root1->right;
	else if(root2->right != NULL) head->right = root2->right;
	else head->right = NULL;
	
	//if(root1 == NULL && root2 != NULL) head->val = root2->val;
	//else if(root2 == NULL && root1 != NULL) head->val = root1->val;
	head->val = root1->val + root2->val;
	
	return head;
}
