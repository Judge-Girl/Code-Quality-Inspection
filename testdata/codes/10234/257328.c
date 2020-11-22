#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

Node *treeAND(Node *root1,Node *root2)
{
	Node *left=NULL,*right=NULL;
	if(root1->left!=NULL && root2->left!=NULL)
	{
		left=treeAND(root1->left,root2->left);	
	}
	if(root1->right!=NULL && root2->right!=NULL)
	{
		right=treeAND(root1->right,root2->right);
	}	

	Node *new=(Node *)malloc(sizeof(Node));
	new->val=root1->val*root2->val;
	new->left=NULL;
	new->right=NULL;
	if(left!=NULL)
	{
		new->left=left;
	}
	if(right!=NULL)
	{
		new->right=right;
	}
	return new;
}

Node *treeOR(Node *root1,Node *root2)
{
	Node *left=NULL,*right=NULL;
	Node *new=(Node *)malloc(sizeof(Node));
	new->left=NULL;
	new->right=NULL;
	if(root1==NULL && root2!=NULL)
	{
		left=treeOR(NULL,root2->left);
		right=treeOR(NULL,root2->right);
		new->val=root2->val;
	}
	else if(root1!=NULL && root2==NULL)
	{
		left=treeOR(root1->left,NULL);
		right=treeOR(root1->right,NULL);
		new->val=root1->val;
	}
	else if(root1!=NULL && root2!=NULL)
	{
		left=treeOR(root1->left,root2->left);
		right=treeOR(root1->right,root2->right);
		new->val=root1->val+root2->val;
	}
	else
	{
		return NULL;
	}

	if(left!=NULL)
	{
		new->left=left;
	}
	if(right!=NULL)
	{
		new->right=right;
	}
	return new;
}
