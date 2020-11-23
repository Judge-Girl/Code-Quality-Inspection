#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node *treeAND(Node *root1, Node *root2){
    if (root1 == NULL || root2 == NULL)
        return NULL;
    Node *cur = (Node *)malloc(sizeof(Node));
    cur->val = root1->val * root2->val;
    cur->left = treeAND(root1->left, root2->left);
    cur->right = treeAND(root1->right, root2->right);
    return cur;
}
Node *treeOR(Node *root1, Node *root2){
    Node *cur = (Node *)malloc(sizeof(Node));
    if (root1 == NULL && root2 == NULL)
        return NULL;
    else if (root1 == NULL){
        cur->val = root2->val;
        cur->left = treeOR(NULL, root2->left);
        cur->right = treeOR(NULL, root2->right);
    }
    else if (root2 == NULL){
        cur->val = root1->val;
        cur->left = treeOR(root1->left, NULL);
        cur->right = treeOR(root1->right, NULL);
    }
    else{
        cur->val = root1->val + root2->val;
        cur->left = treeOR(root1->left, root2->left);
        cur->right = treeOR(root1->right, root2->right);
    }
    return cur;
}



