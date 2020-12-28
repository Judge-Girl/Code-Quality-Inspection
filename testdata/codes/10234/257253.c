#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
Node *treeAND(Node *root1, Node *root2){
if(root1 == NULL || root2 == NULL){
    return NULL;
}
Node *root=(Node *)malloc(sizeof(Node));
root->val=root1->val*root2->val;
root->left=treeAND(root1->left, root2->left);
root->right=treeAND(root1->right, root2->right);
return root;
}
Node *treeOR(Node *root1, Node *root2){
if(root1 == NULL && root2 == NULL){
    return NULL;
}
Node *root=(Node *)malloc(sizeof(Node));
if(root1 != NULL && root2 != NULL){
    root->val=root1->val+root2->val;
    root->left=treeOR(root1->left, root2->left);
    root->right=treeOR(root1->right, root2->right);
}
else if( root2 == NULL){
    root->val=root1->val;
    root->left=treeOR(root1->left, root2);
    root->right=treeOR(root1->right, root2);
}
else if( root1 == NULL){
    root->val=root2->val;
    root->left=treeOR(root1, root2->left);
    root->right=treeOR(root1, root2->right);
}
return root;
}