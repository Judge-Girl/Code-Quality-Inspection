#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
typedef struct Node{
    int val;
    struct Node *left, *right;
} Node;
 

Node *treeAND(Node *root1, Node *root2)
{
    if (root1 == NULL || root2 == NULL) {
        return NULL;
    } else if (root1 != NULL && root2 != NULL) {
        Node *currentNode = (Node *)malloc(sizeof(Node));
        currentNode -> val = root1->val * root2->val;
        currentNode -> left = treeAND(root1 -> left, root2 -> left);
        currentNode -> right = treeAND(root1 -> right, root2 -> right);
        return currentNode;
    }
}

Node *treeOR(Node *root1, Node *root2) 
{
    if (root1 == NULL && root2 == NULL) {
        return NULL;
    } else if (root1 == NULL && root2 != NULL) {
        Node *currentNode = (Node *)malloc(sizeof(Node));
        currentNode -> val = root2->val;
        currentNode -> left = treeOR(NULL, root2 -> left);
        currentNode -> right = treeOR(NULL, root2 -> right);
        return currentNode;
    } else if (root1 != NULL && root2 == NULL) {
        Node *currentNode = (Node *)malloc(sizeof(Node));
        currentNode -> val = root1->val;
        currentNode -> left = treeOR(root1 -> left, NULL);
        currentNode -> right = treeOR(root1 -> right, NULL);
        return currentNode;
    } else if (root1 != NULL && root2 != NULL) {
        Node *currentNode = (Node *)malloc(sizeof(Node));
        currentNode -> val = root1->val + root2->val;
        currentNode -> left = treeOR(root1 -> left, root2 -> left);
        currentNode -> right = treeOR(root1 -> right, root2 -> right);
        return currentNode;
    }
}
