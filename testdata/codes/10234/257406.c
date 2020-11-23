#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node *treeAND(Node *root1, Node *root2){
    if(root1==NULL || root2==NULL){
        root1 = NULL;
        return root1;
    }
    root1->val = root1->val*root2->val;
    // printf("* done\n");
    root1->left = treeAND(root1->left, root2->left);
    // printf("left done\n");
    root1->right = treeAND(root1->right, root2->right);
    // printf("right done\n");
    return root1;
}

Node *treeOR(Node *root1, Node *root2){
    if(root1==NULL && root2==NULL){
        return root1;
    }
    else if(root1==NULL && root2!=NULL){
        root1 = (Node *) malloc(sizeof(Node));
        root1->val = root2->val;
        root1->left = NULL;
        root1->right = NULL;
        root1->left = treeOR(root1->left, root2->left);
        root1->right = treeOR(root1->right, root2->right);
        return root1;
    }
    else if(root1!=NULL && root2==NULL){
        return root1;
    }
    else if(root1!=NULL && root2!=NULL){
        root1->val = root1->val+root2->val;
        root1->left = treeOR(root1->left, root2->left);
        root1->right = treeOR(root1->right, root2->right);
        return root1;
    }
}
