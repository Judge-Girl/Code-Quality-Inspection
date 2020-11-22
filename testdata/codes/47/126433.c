#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

typedef struct treeNode {
    char c;
    int n, left_size;
    struct treeNode *left, *right;
} Node;

Node* newNode(char c, int n, int left_size){
    Node *new;
    new = (Node*) malloc(sizeof(Node));
    assert(new != NULL);
    new->left = NULL;
    new->right = NULL;
    new->c = c;
    new->n = n;
    new->left_size = left_size;
    return new;
}


Node* insert_left(Node *root, char c, int n) {
    if(root == NULL)
        return newNode(c, n, 0);
    if(root->left == NULL){
        if(c == root->c)
            root->n += n;
        else{
            root->left_size += n;
            root->left = newNode(c, n, 0);
        }
    }else{
        root->left_size += n;
        root->left = insert_left(root->left, c, n);
    }
    return root;
}

Node* insert_right(Node *root, char c, int n) {
    if(root == NULL)
        return newNode(c, n, 0);
    if(root->right == NULL){
        if(c == root->c)
            root->n += n;
        else
            root->right = newNode(c, n, 0);
    }else
        root->right = insert_right(root->right, c, n);
    return root;
}

Node* insert(Node *root, int loc, char c, int n){
    if(root == NULL)
        return newNode(c, n, 0);
    if(loc < root->left_size){
        root->left_size += n;
        root->left = insert(root->left, loc, c, n);
    }else if(loc > root->left_size + root->n){
        root->right = insert(root->right, loc - (root->left_size + root->n), c, n);
    }else if(loc == root->left_size){
        if(c == root->c)
            root->n += n;
        else{
            root->left_size += n;
            root->left = insert_right(root->left, c, n);
        }
    }else if(loc == root->left_size + root->n){
        if(c == root->c)
            root->n += n;
        else{
            root->right = insert_left(root->right, c, n);
        }
    }else{
        if(c == root->c)
            root->n += n;
        else{
            root->left = insert_right(root->left, root->c, loc - root->left_size);
            root->right = insert_left(root->right, root->c, root->left_size + root->n - loc);
            root->c = c;
            root->n = n;
            root->left_size += loc - root->left_size;
        }
    }
    return root;
}

void printList(Node *current){
    if(current == NULL)
        return;
    printList(current->left);
    printf("%c %d ", current->c, current->n);
    printList(current->right);
}

int main() {
    int n;
    Node* root = NULL;
    char c, command[7], pos[6];
    while(scanf("%s ", command) != EOF) {
        if(command[0] == 'i'){
            scanf("%s ", pos);
            scanf("%c", &c);
            scanf("%d", &n);
            if(pos[0] == 'l')
                root = insert_left(root, c, n);
            else if(pos[0] == 'r')
                root = insert_right(root, c, n);
            else
                root = insert(root, atoi(pos) - 1, c, n);
        }else{
            printList(root);
            printf("$\n");
        }
    }
    return 0;
}
