#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

Node *treeAND(Node *root1, Node *root2) {
    Node* ret = (Node*) malloc(sizeof(Node));
    // ret->val = 0;
    // ret->left=NULL;
    // ret->right=NULL; 

    if (root1 == NULL) return NULL;
    if (root2 == NULL) return NULL;

    if(root1 != NULL && root2 != NULL){
        ret->val = root1->val * root2->val;
        ret->left = treeAND(root1->left, root2->left);
        ret->right = treeAND(root1->right, root2->right);
    }


    return ret;
}

Node *treeOR(Node *root1, Node *root2) {
    Node* ret = (Node*) malloc(sizeof(Node));
    // ret->val = 0;
    // ret->left=NULL;
    // ret->right=NULL;

    if (root1 == NULL) return root2;
    if (root2 == NULL) return root1; 
    if(root1 != NULL && root2 == NULL){
        ret->val = root1->val;
        ret->left = treeOR(root1->left, root2->left);
        ret->right = treeOR(root1->right, root2->right);
    }
    else if(root1 == NULL && root2 != NULL){
        ret->val = root2->val;
        ret->left = treeOR(root1->left, root2->left);
        ret->right = treeOR(root1->right, root2->right);
    }
    else if(root1 != NULL && root2 != NULL){
        ret->val = root1->val + root2->val;
        ret->left = treeOR(root1->left, root2->left);
        ret->right = treeOR(root1->right, root2->right);
    }


    return ret;


}

