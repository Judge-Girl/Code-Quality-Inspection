#include <stdio.h>
#include <stdlib.h>
 typedef struct Node{
    int val;
    struct Node *left, *right;
} Node;
Node *buildtreeAND(Node *root1, Node *root2)
{
	if(root1!=NULL&&root2!=NULL)
	{
		Node *newroot;
		newroot=(Node*)malloc(sizeof(Node));
		newroot->val=(root1->val)*(root2->val);
		newroot->left=buildtreeAND(root1->left,root2->left);
		newroot->right=buildtreeAND(root1->right,root2->right);
		return newroot;
	}
	else
		return NULL;
	
}
Node *treeAND(Node *root1, Node *root2)
{
	Node *newroot;
	return buildtreeAND(root1,root2);
}
Node *buildtreeOR(Node *root1, Node *root2)
{
	if(root1!=NULL||root2!=NULL)
	{
		Node *newroot;
		newroot=(Node*)malloc(sizeof(Node));
		
		if(root1==NULL)
				newroot->val=(root2->val);
		else if(root2==NULL)
				newroot->val=(root1->val);
		else
			newroot->val=(root2->val)+(root1->val);
		if(root1==NULL)
		{
			newroot->left=buildtreeOR(NULL,root2->left);
			newroot->right=buildtreeOR(NULL,root2->right);	
		}
		else if(root2==NULL)
		{
			newroot->left=buildtreeOR(root1->left,NULL);
			newroot->right=buildtreeOR(root1->right,NULL);
		}
		else
		{
			newroot->left=buildtreeOR(root1->left,root2->left);
			newroot->right=buildtreeOR(root1->right,root2->right);
		}
		return newroot;
	}
	else
		return NULL;
}
Node *treeOR(Node *root1, Node *root2){
	Node *newroot;
	return buildtreeOR(root1,root2);
}
