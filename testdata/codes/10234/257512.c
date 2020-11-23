#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node *newNode(int val){
    Node *node = (Node *) malloc(sizeof(Node));
    node->val = val; node->left = NULL; node->right = NULL;
    return node;
}


Node *Atree(Node *t1, Node *t2, int depth){
    if(t1 == NULL || t2 == NULL) return NULL;
    Node *newnode = newNode(t1->val * t2->val);
    newnode->right = Atree(t1->right, t2->right, depth+1);
    newnode->left = Atree(t1->left, t2->left, depth+1);
    return newnode;
}

Node *treeAND(Node *root1, Node *root2){
    return Atree(root1, root2, 0);
}

Node *Otree(Node *t1, Node *t2, int depth){
    if(t1 == NULL && t2 == NULL) return NULL;
    Node *newnode = NULL;
    if(t1 == NULL){
        newnode = newNode(t2->val);
        // printf("at %d = %d\n", depth , t2->val);
    }else if(t2 == NULL){
        newnode = newNode(t1->val);
        // printf("at %d = %d\n", depth, t1->val);
    }else{
        newnode = newNode(t1->val + t2->val);
        // printf("at %d = %d\n", depth, t1->val + t2->val);
    }
    if(t1 == NULL){
        newnode->right = Otree(NULL, t2->right, depth+1);
        newnode->left = Otree(NULL, t2->left, depth+1);
    }else if(t2 == NULL){
        newnode->right = Otree(t1->right, NULL, depth+1);
        newnode->left = Otree(t1->left, NULL, depth+1);
    }
    else{
        newnode->right = Otree(t1->right, t2->right, depth+1);
        newnode->left = Otree(t1->left, t2->left, depth+1);
    }
    return newnode;
}

Node *treeOR(Node *root1, Node *root2){
    return Otree(root1, root2, 0);
}
