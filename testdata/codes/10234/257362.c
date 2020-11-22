#include <stdlib.h>
typedef struct Node{
    int val;
    struct Node *left, *right;
} Node;
 
Node *treeAND(Node *root1, Node *root2){
	Node *current;
	if(root1 == NULL || root2 == NULL){
		return NULL;
	}
	current = (Node *)malloc(sizeof(Node));
	current->val = (root1->val)*(root2->val);
	current->left = treeAND(root1->left,root2->left);
	current->right = treeAND(root1->right,root2->right);
	return current;
}

Node *treeOR(Node *root1, Node *root2){
	Node *current;
	if(root1 == NULL && root2 == NULL){
		return NULL;
	}
	current = (Node *)malloc(sizeof(Node));
	int v1 = 0,v2 = 0;
	if(root1 != NULL){
		v1 = root1->val;
	}
	if(root2 != NULL){
		v2 = root2->val;
	}
	current->val = v1+v2;

	current->left = treeOR(root1 == NULL?NULL:root1->left,root2==NULL?NULL:root2->left);
	current->right = treeOR(root1 == NULL?NULL:root1->right,root2 == NULL?NULL:root2->right);
	return current;
}
