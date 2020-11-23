#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node *treeAND(Node *root1, Node *root2){
    if(root1 == NULL || root2 == NULL){
        return NULL;
    }
    else if(root1 != NULL && root2 != NULL){
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->val = root1->val * root2->val;
        newNode->left = treeAND(root1->left,root2->left);
        newNode->right = treeAND(root1->right,root2->right);
        return newNode;
    }
}

Node *treeOR(Node *root1, Node *root2){
    if(root1 == NULL && root2 == NULL){
        return NULL;
    }
    else if(root1 != NULL && root2 != NULL){
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->val = root1->val + root2->val;
        newNode->left = treeOR(root1->left,root2->left);
        newNode->right = treeOR(root1->right,root2->right);
        return newNode;
    }
    else if(root1 != NULL || root2 != NULL){
        if(root1 != NULL){
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->val = root1->val;
            newNode->left = treeOR(root1->left,NULL);
            newNode->right = treeOR(root1->right,NULL);
            return newNode;
        }
        else if(root2 != NULL){
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->val = root2->val;
            newNode->left = treeOR(NULL,root2->left);
            newNode->right = treeOR(NULL,root2->right);
            return newNode;
        }
    }
}
