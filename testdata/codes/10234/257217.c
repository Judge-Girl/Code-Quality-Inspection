#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int val;
    struct Node *left, *right;
} Node;
Node *treeAND(Node *root1, Node *root2)
{
    Node *root3;
    root3 = (Node *) malloc(sizeof(Node));
    if(root1 == NULL || root2 == NULL){
        return(NULL);
    }
    else{
        root3->val = root1->val * root2->val;
        root3->left = treeAND(root1->left,root2->left);
        root3->right = treeAND(root1->right,root2->right);
    }
    return(root3);
}
Node *treeOR(Node *root1, Node *root2)
{
    Node *root3;
    root3 = (Node *) malloc(sizeof(Node));
    if(root1 == NULL && root2 == NULL){
        return(NULL);
    }
    else if(root1 == NULL || root2 == NULL){
        if(root1 == NULL){
            root3->val = root2->val;
            root3->left = treeOR(NULL,root2->left);
            root3->right = treeOR(NULL,root2->right);
        }
        else if(root2 == NULL){
            root3->val = root1->val;
            root3->left = treeOR(root1->left,NULL);
            root3->right = treeOR(root1->right,NULL);
        }
    }
    else{
        root3->val = root1->val + root2->val;
        root3->left = treeOR(root1->left,root2->left);
        root3->right = treeOR(root1->right,root2->right);
    }
    return(root3);
}
