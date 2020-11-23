#include <stdlib.h>
#include "tree.h"

Node *new_node() {
    Node *ret = (Node*)malloc(sizeof(Node));
    ret->left = ret->right = NULL;
    return ret;
}

Node *treeAND(Node *root1, Node *root2) {
    if ( root1 == NULL || root2 == NULL )
        return NULL;
    Node *ret = new_node();
    ret->val = root1->val * root2->val;
    ret->left = treeAND(root1->left, root2->left);
    ret->right = treeAND(root1->right, root2->right);
    return ret;
}
Node *treeOR(Node *root1, Node *root2) {
    if ( root1 == NULL && root2 == NULL )
        return NULL;
    Node *ret = new_node();
    ret->val = (root1 == NULL ? 0 : root1->val) + (root2 == NULL ? 0 : root2->val);
    ret->left = treeOR((root1 == NULL ? NULL : root1->left), (root2 == NULL ? NULL : root2->left));
    ret->right = treeOR((root1 == NULL ? NULL : root1->right), (root2 == NULL ? NULL : root2->right));
    return ret;
}
