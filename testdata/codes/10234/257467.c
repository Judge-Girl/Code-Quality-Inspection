#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
Node *treeAND(Node *root1, Node *root2){
    Node *ans = (Node *) malloc(sizeof(Node));
    if(root1!=NULL && root2!=NULL){
        ans->val = root1->val * root2->val;
    }
    if(root1->left !=NULL && root2->left !=NULL){
        ans->left= treeAND(root1->left,root2->left);
    }
    if(root1->right!=NULL && root2->right!=NULL){
        ans->right = treeAND(root1->right,root2->right);
    }
    return ans;
}
Node *treeOR(Node *root1, Node *root2){
    Node *ans =(Node *) malloc(sizeof(Node));
    if(root1!=NULL && root2!=NULL){
        ans->val = root1->val + root2->val;
    }
    else if(root1!=NULL && root2==NULL){
        ans->val = root1->val;
    }
    else if(root1==NULL && root2!=NULL){
        ans->val = root2->val;
    }
    if(root1==NULL && root2!=NULL){
        if(root2->left!=NULL){
            ans->left = treeOR(NULL,root2->left);
        }
        if(root2->right!=NULL){
            ans->right = treeOR(NULL,root2->right);
        }
    }
    else if(root2==NULL && root1!=NULL){
        if(root1->left!=NULL){
            ans->left = treeOR(root1->left,NULL);
        }
        if(root1->right!=NULL){
            ans->right = treeOR(root1->right,NULL);
        }
    }
    else{
        if(root1->left!=NULL || root2->left!=NULL){
            ans->left = treeOR(root1->left,root2->left);
        }
        if(root1->right!=NULL || root2->right!=NULL){
            ans->right = treeOR(root1->right,root2->right);
        }
    }
    return ans;
}
