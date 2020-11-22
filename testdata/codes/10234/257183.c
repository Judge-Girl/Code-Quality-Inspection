#include"tree.h"
#include<stdlib.h>
#include<assert.h>

Node *treeAND(Node *root1, Node *root2){
	Node *tree_root = malloc(sizeof(Node));
	assert(tree_root);
	tree_root->val = root1->val * root2->val;
	tree_root->left = NULL;
	tree_root->right = NULL;
	if(root1->left && root2->left){
		tree_root->left = treeAND(root1->left, root2->left);
	}
	if(root1->right && root2->right){
		tree_root->right = treeAND(root1->right, root2->right);
	}
	return tree_root;
}

Node *get_empty(){
	Node* result = malloc(sizeof(Node));
	result->val = 0;
	result->left = NULL;
	result->right = NULL;
	return result;
} 

Node *treeOR(Node *root1, Node *root2){
	Node *tree_root = malloc(sizeof(Node));
	assert(tree_root);
	if(root1 == NULL){
		root1 = get_empty();
	}
	if(root2 == NULL){
		root2 = get_empty();
	}
	tree_root->val = root1->val + root2->val;
	tree_root->left = NULL;
	tree_root->right = NULL;
	if(root1->left || root2->left){
		tree_root->left = treeOR(root1->left, root2->left);
	}
	if(root1->right || root2->right){
		tree_root->right = treeOR(root1->right, root2->right);
	}
	return tree_root;
}

