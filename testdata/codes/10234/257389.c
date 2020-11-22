#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int val;
    struct Node *left, *right;
} Node;
 
Node *treeAND(Node *root1, Node *root2){
	Node *current;
	if(root1 == NULL || root2 == NULL) return NULL;
	current = (Node *)malloc(sizeof(Node));
	current->val = root1->val * root2->val;
	//current->left = current->right = NULL;
	current->left = treeAND(root1->left, root2->left);
	current ->right = treeAND(root1->right, root2->right);
	return current;
}
Node *treeOR(Node *root1, Node *root2){
	Node *current;
	if((root1 == NULL) && (root2 == NULL)) return NULL;
	current = (Node *)malloc(sizeof(Node));
	current->val = 0;
	if(root1 != NULL) current->val += root1->val;
	if(root2 != NULL) current->val += root2->val;
	//printf("current %d\n",current->val);
	current->left = current->right = NULL;
	if(root1 == NULL){
		current->left = treeOR(NULL,root2->left);
		current->right = treeOR(NULL, root2->right);
	}
	else if(root2 == NULL){
		current->left = treeOR(root1->left, NULL);
		current->right = treeOR(root1->right , NULL);
	}
	else {
		current->left = treeOR(root1->left , root2->left);
		current->right = treeOR(root1->right, root2->right);
	}
	return current;
}
