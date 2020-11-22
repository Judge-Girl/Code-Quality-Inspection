#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int val;
    struct Node *left, *right;
} Node;
Node *treeAND(Node *root1, Node *root2){
    Node *root = (Node *) malloc(sizeof(Node));
    if(root1==NULL || root2==NULL)
        return NULL;
    else{
        root->val = root1->val * root2->val;
        root->left = treeAND(root1->left, root2->left);
        root->right = treeAND(root1->right, root2->right);
        return root;

    }
}
Node *treeOR(Node *root1, Node *root2){
    Node *root = (Node *) malloc(sizeof(Node));
    if(root1==NULL && root2==NULL)
        return NULL;
    else if(root1==NULL && root2 != NULL){
        root->val = root2->val;
        root->left = treeOR(NULL, root2->left);
        root->right = treeOR(NULL, root2->right);
        return root;
    }
    else if(root1!=NULL && root2 == NULL){
        root->val = root1->val;
        root->left = treeOR(root1->left, NULL);
        root->right = treeOR(root1->right, NULL);
        return root;
    }
    else{
        root->val = root1->val + root2->val;
        root->left = treeOR(root1->left, root2->left);
        root->right = treeOR(root1->right, root2->right);
        return root;
    }
}
