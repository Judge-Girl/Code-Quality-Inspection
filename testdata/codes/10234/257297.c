#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
 
Node *treeAND(Node *root1, Node *root2) {
    if (root2 != NULL && root1 != NULL) {
        struct Node *new = malloc(sizeof(struct Node));
        new->val = root1->val*root2->val;
        new->left = treeAND(root1->left,root2->left);
        new->right = treeAND(root1->right,root2->right);
        return new;
    }
    else return NULL;
}
 
Node *treeOR(Node *root1, Node *root2) {
    if (root2 != NULL && root1 != NULL) {
        struct Node *new = malloc(sizeof(struct Node));
        new->val = root1->val+root2->val;
        new->left = treeOR(root1->left,root2->left);
        new->right = treeOR(root1->right,root2->right);
        return new;
    }
    else if (root2 != NULL) {
        return root2;
    }
    else if (root1 != NULL) {
        return root1;
    }
    else return NULL;
}
