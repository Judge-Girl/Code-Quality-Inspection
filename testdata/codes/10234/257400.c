#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
Node *treeAND(Node *root1, Node *root2){
    if(root1 != NULL && root2 != NULL){
        Node *node = (Node*)malloc(sizeof(Node));
        node->val = root1->val * root2->val;
        node->left = treeAND(root1->left, root2->left);
        node->right = treeAND(root1->right, root2->right);
        return node;
    }
    else{
        return NULL;
    }
}
 
Node *treeOR(Node *root1, Node *root2){
    if(root1 != NULL && root2 != NULL){
        Node *node = (Node*)malloc(sizeof(Node));
        node->val = root1->val + root2->val;
        node->left = treeOR(root1->left, root2->left);
        node->right = treeOR(root1->right, root2->right);
        return node;
    }
    else if(root1 == NULL && root2 != NULL){
        Node *node = (Node*)malloc(sizeof(Node));
        node->val = root2->val;
        node->left = treeOR(NULL, root2->left);
        node->right = treeOR(NULL, root2->right);
        return node;
    }
    else if(root1 != NULL && root2 == NULL){
        Node *node = (Node*)malloc(sizeof(Node));
        node->val = root1->val;
        node->left = treeOR(root1->left, NULL);
        node->right = treeOR(root1->right, NULL);
        return node;
    }
    else{
        return NULL;
    }
}
