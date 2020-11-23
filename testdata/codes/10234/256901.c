#include"tree.h"
Node* treeAND(Node *a,Node *b){
	if(!a||!b) return 0;
	a->val*=b->val;
	a->left=treeAND(a->left,b->left);
	a->right=treeAND(a->right,b->right);
	return a;
}
Node* treeOR(Node *a,Node *b){
	if(!a||!b) return a?a:b;
	a->val+=b->val;
	a->left=treeOR(a->left,b->left);
	a->right=treeOR(a->right,b->right);
	return a;
}
