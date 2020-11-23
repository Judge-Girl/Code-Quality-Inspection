#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
 
Node *treeAND(Node *root1, Node *root2) {
	Node *root = (Node *) malloc(sizeof(Node));
    root->val = (root1->val) * (root2->val);
    if ( root1->left != NULL && root2->left != NULL )
    	root->left = treeAND(root1->left, root2->left);
    else 
    	root->left = NULL;
    if ( root1->right != NULL && root2->right != NULL )
    	root->right = treeAND(root1->right, root2->right);
    else 
    	root->right = NULL;
    return root;
}
Node *treeOR(Node *root1, Node *root2) {
	Node *root = (Node *) malloc(sizeof(Node));
	if ( root1 != NULL && root2 != NULL) {
    	root->val = (root1->val) + (root2->val);
    	if ( root1->left != NULL || root2->left != NULL )
    		root->left = treeOR(root1->left, root2->left);
    	else 
    		root->left = NULL;
    	if ( root1->right != NULL || root2->right != NULL )
    		root->right = treeOR(root1->right, root2->right);
    	else 
    		root->right = NULL;
    } else if ( root1 == NULL && root2 != NULL) {
    	root->val = root2->val;
    	if ( root2->left != NULL )
    		root->left = treeOR(NULL, root2->left);
    	else 
    		root->left = NULL;
    	if ( root2->right != NULL )
    		root->right = treeOR(NULL, root2->right);
    	else 
    		root->right = NULL;
    } else if ( root1 != NULL && root2 == NULL) {
    	root->val = root1->val;
    	if ( root1->left != NULL )
    		root->left = treeOR(root1->left, NULL);
    	else 
    		root->left = NULL;
    	if ( root1->right != NULL )
    		root->right = treeOR(root1->right,NULL);
    	else 
    		root->right = NULL;
    }
    return root;
}
