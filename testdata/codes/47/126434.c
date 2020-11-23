#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

typedef struct treeNode {
    char c;
    int n, size, height;
    struct treeNode *left, *right;
} Node;

Node* newNode(char c, int n) {
    Node *new;
    new = (Node*) malloc(sizeof(Node));
    assert(new != NULL);
    new->left = NULL;
    new->right = NULL;
    new->c = c;
    new->n = n;
    new->size = n;
    new->height = 1;
    return new;
}

void update(Node *x) {
    if(x->left == NULL){
        if(x->right != NULL){
            x->height = 1 + x->right->height;
            x->size = x->n + x->right->size;
        }else{
            x->height = 1;
            x->size = x->n;
        }
    }else if(x->right == NULL){
        x->height = 1 + x->left->height;
        x->size = x->n + x->left->size;
    }
    else {
        if(x->left->height >= x->right->height)
            x->height = 1 + x->left->height;
        else
            x->height = 1 + x->right->height;
        x->size = x->n + x->left->size + x->right->size;
    }
}

Node* rotate_right(Node *x) {
    Node *y = x->left;
    x->left = y->right;
    y->right = x;
    update(x);
    update(y);
    return y;
}

Node* rotate_left(Node *x) {
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    update(x);
    update(y);
    return y;
}

Node* balance(Node *x) {
    update(x);
    if(x->height == 1)
        return x;
    if(x->right == NULL && x->height > 1)
        x = rotate_right(x);
    else if(x->left == NULL && x->height > 1)
        x = rotate_left(x);
    else if(x->left->height > 1 + x->right->height)
        x = rotate_right(x);
    else if(x->right->height > 1 + x->left->height)
        x = rotate_left(x);
    return x;
}

Node* insert_left(Node *x, char c, int n) {
    if(x == NULL)
        return newNode(c, n);
    if(x->left == NULL){
        if(c == x->c)
            x->n += n;
        else
            x->left = newNode(c, n);
    }else{
        x->left = insert_left(x->left, c, n);
    }
    return balance(x);
}

Node* insert_right(Node *x, char c, int n) {
    if(x == NULL)
        return newNode(c, n);
    if(x->right == NULL){
        if(c == x->c)
            x->n += n;
        else
            x->right = newNode(c, n);
    }else
        x->right = insert_right(x->right, c, n);
    return balance(x);
}

Node* insert(Node *x, int loc, char c, int n) {
    if(x == NULL)
        return newNode(c, n);
    int left_size;
    if(x->left == NULL)
        left_size = 0;
    else
        left_size = x->left->size;
    if(loc < left_size){
        x->left = insert(x->left, loc, c, n);
    }else if(loc > left_size + x->n){
        x->right = insert(x->right, loc - (left_size + x->n), c, n);
    }else if(loc == left_size){
        if(c == x->c)
            x->n += n;
        else{
            x->left = insert_right(x->left, c, n);
        }
    }else if(loc == left_size + x->n){
        if(c == x->c)
            x->n += n;
        else{
            x->right = insert_left(x->right, c, n);
        }
    }else{
        if(c == x->c)
            x->n += n;
        else{
            x->left = insert_right(x->left, x->c, loc - left_size);
            x->right = insert_left(x->right, x->c, left_size + x->n - loc);
            x->c = c;
            x->n = n;
        }
    }
    return balance(x);
}

void printList(Node *current) {
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
