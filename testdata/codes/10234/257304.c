#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node{
    int val;
    struct Node *left, *right;
} Node;

Node *nodeAND(Node *root1, Node *root2){
    if((root1 == NULL) || (root2 == NULL)){
        return NULL;
    }else{
        root1->val *= root2->val;
        root1->left = nodeAND(root1->left, root2->left);
        root1->right = nodeAND(root1->right, root2->right);
        return root1;
    }
}

Node *treeAND(Node *root1, Node *root2){
    Node *rroot;
    rroot = nodeAND(root1, root2);
    return rroot;
}

Node *nodeOR(Node *root1, Node *root2){
    if((root1 == NULL) && (root2 == NULL)){
        return NULL;
    }else if(root1 == NULL){
        return root2;
    }else if(root2 == NULL){
        return root1;
    }else{
        root1->val += root2->val;
        root1->left = nodeOR(root1->left, root2->left);
        root1->right = nodeOR(root1->right, root2->right);
        return root1;
    }
}

Node *treeOR(Node *root1, Node *root2){
    Node *rroot;
    rroot = nodeOR(root1, root2);
    return rroot;
}

