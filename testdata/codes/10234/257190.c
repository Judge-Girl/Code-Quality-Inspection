#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *left, *right;
} Node;
 
Node *treeAND(Node *root1, Node *root2);
Node *treeOR(Node *root1, Node *root2);
 
Node *treeAND(Node *root1, Node *root2){
	if(root1 != NULL && root2 != NULL){
		root1 -> val *= root2 -> val;
		root1 -> left = treeAND(root1 -> left, root2 -> left);
		root1 -> right = treeAND(root1 -> right, root2 -> right);
		return root1;
	}else{
		return NULL;
	}
}

Node *treeOR(Node *root1, Node *root2){
	if(root1 != NULL && root2 != NULL){
		root1 -> val += root2 -> val;
		root1 -> left = treeOR(root1 -> left, root2 -> left);
		root1 -> right = treeOR(root1 -> right, root2 -> right);
		return root1;
	}else if(root1 != NULL || root2 != NULL){
		Node *newroot = (Node *)malloc(sizeof(Node));
		newroot -> val = ((root1 == NULL) ? (0) : (root1 -> val)) + ((root2 == NULL) ? (0) : (root2 -> val));
		Node *newleft, *newright;
		newleft = ((root1 != NULL) ? root1 : root2) -> left;
		newright = ((root1 != NULL) ? root1 : root2) -> right;
		newroot -> left = treeOR(newleft, NULL);
		newroot -> right = treeOR(newright, NULL);
		return newroot;
	}else{
		return NULL;
	}
}
