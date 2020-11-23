#include "tree.h"
#include <stdlib.h>

Node *treeAND(Node *root1, Node *root2) {
    Node *res = (Node*)malloc(sizeof(Node));
    res->left = res->right = NULL;
    res->val = root1->val * root2->val;
    if (root1->left && root2->left) res->left = treeAND(root1->left, root2->left);
    if (root1->right && root2->right) res->right = treeAND(root1->right, root2->right);
    return res;
}

Node *treeOR(Node *root1, Node *root2) {
    Node *res = (Node*)malloc(sizeof(Node));
    res->left = res->right = NULL;
    res->val = root1->val + root2->val;
    if (root1->left && root2->left) res->left = treeOR(root1->left, root2->left);
    else if (root1->left) res->left = root1->left;
    else if (root2->left) res->left = root2->left;
    if (root1->right && root2->right) res->right = treeOR(root1->right, root2->right);
    else if (root1->right) res->right = root1->right;
    else if (root2->right) res->right = root2->right;
    return res;
}

