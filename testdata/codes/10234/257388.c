#include <stdio.h>
#include <stdlib.h>
#include "tree.h"



Node*ANDdfs(Node *root1, Node *root2){
	if(root1==NULL||root2==NULL){
		return NULL;
	}

	Node* reference=(Node*)malloc(sizeof(Node));
	reference->val=root1->val*root2->val;
	reference->left=ANDdfs(root1->left,root2->left);
	reference->right=ANDdfs(root1->right,root2->right);
	return reference;

}

Node*ORdfs(Node *root1, Node *root2){
	if(root1==NULL&&root2==NULL){

		return NULL;
	}
	if(root1==NULL&&root2!=NULL){
		Node* reference=(Node*)malloc(sizeof(Node));
		reference->val=root2->val;
		reference->left=ORdfs(NULL,root2->left);
		reference->right=ORdfs(NULL,root2->right);
		return reference;
	}
	if(root1!=NULL&&root2==NULL){
		Node* reference=(Node*)malloc(sizeof(Node));
		reference->val=root1->val;
		reference->left=ORdfs(root1->left,NULL);
		reference->right=ORdfs(root1->right,NULL);
		return reference;
	}

	Node* reference=(Node*)malloc(sizeof(Node));
	reference->val=root1->val+root2->val;
	reference->left=ORdfs(root1->left,root2->left);
	reference->right=ORdfs(root1->right,root2->right);
	return reference;

}

Node *treeAND(Node *root1, Node *root2){
	



	return ANDdfs(root1,root2);

}
Node *treeOR(Node *root1, Node *root2){
	return ORdfs(root1, root2);
}
