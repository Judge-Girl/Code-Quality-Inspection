#include <stdio.h>
#include <stdlib.h>
 
 typedef struct Node{
	int val;
	struct Node *left, *right;
} Node;
 
Node *treeAND(Node *root1, Node *root2){
	if (root1 == NULL || root2 == NULL){
		root1 = NULL;
		return NULL;
	}
	root1->left = treeAND(root1->left, root2->left);
	root1->right = treeAND(root1->right, root2->right);
	root1->val = root1->val * root2->val;
	return root1;
}
 
Node *treeOR(Node *root1, Node *root2){
	// printf("now val = %d\n", root1->val);
	if (root1 && root2 == NULL){
		root1 = NULL;
		return NULL;
	}
	if (root1->left == NULL && root2->left != NULL){
		// printf("root2 left %d\n", root2->val);
		root1->left = (Node*)malloc(sizeof(Node));
		root1->left->val = 0;
		root1->left->left = NULL, root1->left->right = NULL;
	}
	if (root1->left != NULL && root2->left == NULL){
		// printf("root1 left %d\n", root1->val);
		root2->left = (Node*)malloc(sizeof(Node));
		root2->left->val = 0;
		root2->left->left = NULL, root2->left->right = NULL;
	}
	if (root1->right == NULL && root2->right != NULL){
		// printf("root2 right %d\n", root2->val);
		root1->right = (Node*)malloc(sizeof(Node));
		root1->right->val = 0;
		root1->right->left = NULL, root1->right->right = NULL;
	}
	if (root1->right != NULL && root2->right == NULL){
		// printf("root1 right %d\n", root1->val);
		root2->right = (Node*)malloc(sizeof(Node));
		root2->right->val = 0;
		root2->right->left = NULL, root2->right->right = NULL;
	}
	// printf("in left / right\n");
	if (root1->left != NULL) root1->left = treeOR(root1->left, root2->left);
	// printf("done left\n");
	if (root1->right != NULL) root1->right = treeOR(root1->right, root2->right);
	// printf("done right\n");
	root1->val = root1->val + root2->val;
	// printf("(origin %d) val = %d\n", root2->val, root1->val);
	return root1;
}
