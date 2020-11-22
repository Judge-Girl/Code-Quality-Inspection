#include <stdio.h>
#include <stdlib.h>
#include "tree.h"



Node *treeAND(Node *root1, Node *root2){
	
	if(root1==NULL||root2==NULL){
		return NULL;
	}

	Node* reference=(Node*)malloc(sizeof(Node));
	reference->val=root1->val*root2->val;
	reference->left=treeAND(root1->left,root2->left);
	reference->right=treeAND(root1->right,root2->right);
	return reference;

}
Node *treeOR(Node *root1, Node *root2){
	if(root1==NULL&&root2==NULL){

		return NULL;
	}
	if(root1==NULL&&root2!=NULL){
		Node* reference=(Node*)malloc(sizeof(Node));
		reference->val=root2->val;
		reference->left=treeOR(NULL,root2->left);
		reference->right=treeOR(NULL,root2->right);
		return reference;
	}
	if(root1!=NULL&&root2==NULL){
		Node* reference=(Node*)malloc(sizeof(Node));
		reference->val=root1->val;
		reference->left=treeOR(root1->left,NULL);
		reference->right=treeOR(root1->right,NULL);
		return reference;
	}

	Node* reference=(Node*)malloc(sizeof(Node));
	reference->val=root1->val+root2->val;
	reference->left=treeOR(root1->left,root2->left);
	reference->right=treeOR(root1->right,root2->right);
	return reference;
}
