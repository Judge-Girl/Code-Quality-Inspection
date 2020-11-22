#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node *aNd(Node *root1, Node *root2,Node *C){
	if(root1==NULL||root2==NULL){
		return NULL;
	}
	C=(Node *) malloc(sizeof(Node));
	C->left=NULL;
	C->right==NULL;
	C->val=(root1->val)*(root2->val);
	C->left=aNd(root1->left,root2->left,C->left);
	C->right=aNd(root1->right,root2->right,C->right);
	return C;
}

Node *treeAND(Node *root1, Node *root2){
	Node *QAQ=(Node *)malloc(sizeof(Node));
	QAQ=NULL;
	QAQ=aNd(root1,root2,QAQ);
	return QAQ;
}

Node *oR(Node *root1, Node *root2,Node *C){
	if(root1==NULL&&root2==NULL){
		return NULL;
	}
	C=(Node *) malloc(sizeof(Node));
	C->left=NULL;
	C->right==NULL;
	if(root1==NULL){
		C->val=(root2->val);
		C->left=oR(NULL,root2->left,C->left);
		C->right=oR(NULL,root2->right,C->right);
	}
	else if(root2==NULL){
		C->val=(root1->val);
		C->left=oR(root1->left,NULL,C->left);
		C->right=oR(root1->right,NULL,C->right);
	}
	else{
		C->val=(root1->val)+(root2->val);
		C->left=oR(root1->left,root2->left,C->left);
		C->right=oR(root1->right,root2->right,C->right);
	}
	return C;
}

Node *treeOR(Node *root1, Node *root2){
	Node *QAQ=(Node *)malloc(sizeof(Node));
	QAQ=NULL;
	QAQ=oR(root1,root2,QAQ);
	return QAQ;
}
