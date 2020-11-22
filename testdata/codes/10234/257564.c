#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
// typedef struct Node{
//     int val;
//     struct Node *left, *right;
// } Node;

Node *build(int data) {
    Node *root = (Node *)malloc(sizeof(Node));
    root->val = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}
Node *A(Node *root1, Node *root2) {
    if(root1 == NULL || root2 == NULL) return NULL;
    Node *new = build(root1->val * root2->val);
    new->left = A(root1->left, root2->left);
    new->right = A(root1->right, root2->right);
    return new;
}
Node *treeAND(Node *root1, Node *root2) {
    return A(root1, root2);
}
Node *B(Node *root1, Node *root2) {
    if(root1 == NULL && root2 == NULL) return NULL;
    
    //for the node itself
    Node *new;
    if(root1 == NULL) new = build(root2->val);
    else if(root2 == NULL) new = build(root1->val);
    else new = build(root1->val + root2->val);

    //for the left side and right side
    if(root1 == NULL) {
        new->left = B(NULL, root2->left);
        new->right = B(NULL, root2->right);
    }
    else if(root2 == NULL) {
        new->left = B(NULL, root1->left);
        new->right = B(NULL, root1->right);
    }
    else {
        new->left = B(root1->left, root2->left);
        new->right = B(root1->right, root2->right);
    }
    return new;
}
Node *treeOR(Node *root1, Node *root2) {
    return B(root1, root2);
}
