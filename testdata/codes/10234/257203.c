#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node *treeAND(Node *root1, Node *root2){
    if(root1!=NULL && root2!=NULL){
        Node *root = (Node *) malloc(sizeof(Node));
        root->val=root1->val * root2->val;
        root->left=treeAND(root1->left,root2->left);
        root->right=treeAND(root1->right,root2->right);
        return root;
    }
    else return NULL;

}
Node *treeOR(Node *root1, Node *root2){
    if(root1!=NULL || root2!=NULL){
        Node *root = (Node *) malloc(sizeof(Node));
        int a=0,b=0;
        if(root1!=NULL) a=root1->val;
        if(root2!=NULL) b=root2->val;
        root->val=a + b;
        if(root1==NULL){
            root->left=treeOR(NULL,root2->left);
            root->right=treeOR(NULL,root2->right);
        }
        else if(root2==NULL){
            root->left=treeOR(root1->left,NULL);
            root->right=treeOR(root1->right,NULL);
        }
        else{
            root->left=treeOR(root1->left,root2->left);
            root->right=treeOR(root1->right,root2->right);
        }
        return root;
    }
    else return NULL;
}

