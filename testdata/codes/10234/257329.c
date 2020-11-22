#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int val;
    struct Node *left, *right;
} Node;

Node *treeAND(Node *root1, Node *root2){
    if(root1==NULL||root2==NULL)
        return NULL;
    else{
        root1->val=root1->val*root2->val;
        root1->left=treeAND(root1->left, root2->left);
        root1->right=treeAND(root1->right, root2->right);
        return root1;
    }
}
Node *treeOR(Node *root1, Node *root2){
    if(root1==NULL&&root2==NULL)
        return NULL;
    else if(root2==NULL)
        return root1;
    else if(root1==NULL){
        return root2;
    }
    else{
        root1->val=root1->val+root2->val;
        root1->left=treeOR(root1->left, root2->left);
        root1->right=treeOR(root1->right, root2->right);
        return root1;
    }
}
