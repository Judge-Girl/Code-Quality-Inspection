#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
 
typedef struct treeNode {
    int x, y;
    bool axis;
    struct treeNode *left, *right;
} Node;

Node* newNode(int x, int y, bool axis) {
    Node *new;
    new = (Node*) malloc(sizeof(Node));
    assert(new != NULL);
    new->x = x;
    new->y = y;
    new->axis = axis;
    new->left = NULL;
    new->right = NULL;
    return new;
}

Node* insert(Node *t, int x, int y, bool axis) {
    if(t == NULL)
        return newNode(x, y, axis);
    if(axis) {
        if(x + y < t->x + t->y)
            t->left = insert(t->left, x, y, !axis);
        else
            t->right = insert(t->right, x, y, !axis);
    }else {
        if(x - y < t->x - t->y)
            t->left = insert(t->left, x, y, !axis);
        else
            t->right = insert(t->right, x, y, !axis);
    }
    return t;
}

int Mdist(Node *t, int x, int y) {
    return abs(t->x - x) + abs(t->y - y);
}

int min;

void search(Node *t, int x, int y) {
    if(t == NULL)
        return;
    if(Mdist(t, x, y) < min)
        min = Mdist(t, x, y);
    int dx;
    if(t->axis){
        dx = x + y - t->x - t->y;
        if(dx <= -min)
            search(t->left, x, y);
        else if(dx >= min)
            search(t->right, x, y);
        else if(dx > 0) {
            search(t->right, x, y);
            search(t->left, x, y);
        } else {
            search(t->left, x, y);
            search(t->right, x, y);
        }
    } else{
        dx = x - y - t->x + t->y;
        if(dx <= -min)
            search(t->left, x, y);
        else if(dx >= min)
            search(t->right, x, y);
        else if(dx > 0) {
            search(t->right, x, y);
            search(t->left, x, y);
        } else {
            search(t->left, x, y);
            search(t->right, x, y);
        }        
    }
}

int main() {
    int N, x, y;
    Node *A = NULL, *B = NULL;
    scanf("%d\n", &N);
    for(int i = 0; i < N; ++i) {
        min = 65534;
        scanf("%d %d\n", &x, &y);
        A = insert(A, x, y, 0);
        if(i){
            search(B, x, y);
            printf("%d\n", min);
        }
        min = 65534;
        scanf("%d %d\n", &x, &y);
        B = insert(B, x, y, 0);
        search(A, x, y);
        printf("%d\n", min);
    }
    return 0;
}
