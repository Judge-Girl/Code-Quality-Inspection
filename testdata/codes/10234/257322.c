#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
Node *treeAND(Node *root1, Node *root2)
{
    if(root1 == NULL || root2 == NULL) return NULL;
    Node *newnode = (Node *) malloc(sizeof(Node));
    newnode -> val = root1 -> val * root2 -> val;
    newnode -> left =  treeAND(root1 -> left, root2 -> left);
    newnode -> right = treeAND(root1 -> right, root2 -> right);
    return newnode;
}
Node *treeOR(Node *root1, Node *root2)
{
    if(root1 == NULL && root2 == NULL) return NULL;
    if(root1 == NULL){
        Node *newnode = (Node *) malloc(sizeof(Node));
        newnode -> val = root2 -> val;
        newnode -> left = treeOR(NULL, root2 -> left);
        newnode -> right = treeOR(NULL, root2 -> right);
        return newnode;
    }
    if(root2 == NULL){
        Node *newnode = (Node *) malloc(sizeof(Node));
        newnode -> val = root1 -> val;
        newnode -> left = treeOR(root1 -> left, NULL);
        newnode -> right = treeOR(root1 -> right, NULL);
        return newnode;
    }
    Node *newnode = (Node *) malloc(sizeof(Node));
    newnode -> val = root1 -> val + root2 -> val;
    newnode -> left =  treeOR(root1 -> left, root2 -> left);
    newnode -> right = treeOR(root1 -> right, root2 -> right);
    return newnode;
}
