#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
 
typedef struct treeNode {
    int x[2];
    bool axis;
    struct treeNode *left, *right;
} Node;

Node* newNode(int x[2], bool axis) {
    Node *new;
    new = (Node*) malloc(sizeof(Node));
    assert(new != NULL);
    new->x[0] = x[0];
    new->x[1] = x[1];
    new->axis = axis;
    new->left = NULL;
    new->right = NULL;
    return new;
}

Node* insert(Node *t, int x[2], bool axis) {
    if(t == NULL)
        return newNode(x, axis);
    else if(x[axis] < t->x[axis])
        t->left = insert(t->left, x, !axis);
    else
        t->right = insert(t->right, x, !axis);
    return t;
}

int Mdist(Node *t, int x[2]) {
    return abs(t->x[0] - x[0]) + abs(t->x[1] - x[1]);
}

int min;

void search(Node *t, int x[2]) {
    if(t == NULL)
        return;
    if(Mdist(t, x) < min)
        min = Mdist(t, x);
    if(x[t->axis] + min <= t->x[t->axis])
        search(t->left, x);
    else if(x[t->axis] - min >= t->x[t->axis])
        search(t->right, x);
    else{
        search(t->left, x);
        search(t->right, x);
    }
}

int main() {
    int N, x[2];
    Node *A = NULL, *B = NULL;
    scanf("%d\n", &N);
    for(int i = 0; i < N; ++i) {
        min = 65534;
        scanf("%d %d\n", &x[0], &x[1]);
        A = insert(A, x, 0);
        if(i){
            search(B, x);
            printf("%d\n", min);
        }
        min = 65534;
        scanf("%d %d\n", &x[0], &x[1]);
        B = insert(B, x, 0);
        search(A, x);
        printf("%d\n", min);
    }
    return 0;
}
