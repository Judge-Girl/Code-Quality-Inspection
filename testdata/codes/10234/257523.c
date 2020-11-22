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
Node *A(Node *root1, Node *root2, int depth) {
    if(root1 == NULL || root2 == NULL) return NULL;
    Node *new;
    new = build(root1->val * root2->val);
    new->left = A(root1->left, root2->left, depth+1);
    new->right = A(root1->right, root2->right, depth+1);
    return new;
}
Node *treeAND(Node *root1, Node *root2) {
    return A(root1, root2, 0);

}
Node *B(Node *root1, Node *root2, int depth) {
    if(root1 == NULL && root2 == NULL) return NULL;
    Node *new;
    if(root1 == NULL) new = build(root2->val);
    else if(root2 == NULL) new = build(root1->val);
    else {
        new = build(root1->val + root2->val);

    }

    if(root1 == NULL) {
        new->left = B(NULL, root2->left, depth+1);
        new->right = B(NULL, root2->right, depth+1);
    }
    else if(root2 == NULL) {
        new->left = B(NULL, root1->left, depth+1);
        new->right = B(NULL, root1->right, depth+1);
    }
    else {
        new->left = B(root1->left, root2->left, depth+1);
        new->right = B(root1->right, root2->right, depth+1);
    }
    return new;
}
Node *treeOR(Node *root1, Node *root2) {
    Node *new;
    return B(root1, root2, 0);
}
