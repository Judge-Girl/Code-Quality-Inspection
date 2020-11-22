#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node {
    int pos[2];
    int dim;
    struct node *left, *right;
} Node;

void insert(Node **root, int p[2], int dim)
{
    if(*root == NULL) {
        *root = malloc(sizeof(Node));
        **root = (Node) {p[0], p[1], dim, NULL, NULL};
        return;
    }
    if(p[dim] >= (*root)->pos[dim]) {
        insert(&(*root)->right, p, (dim + 1) % 2);
    }
    else {
        insert(&(*root)->left, p, (dim + 1) % 2);
    }
}
int dist(int p1[2], int p2[2])
{
    return abs(p2[0] - p1[0]) + abs(p2[1] - p1[1]);
}
int search(Node *root, int p[2], int min)
{
    if(root == NULL)
        return min;
    int d = dist(root->pos, p);
    if(d <= min) {
        min = d;
    }
    int dim = root->dim;
    if(p[dim] - root->pos[dim] >= min)
        return search(root->right, p, min);
    if(root->pos[dim] - p[dim] >= min)
        return search(root->left, p, min);
    if(p[dim] - root->pos[dim] > 0) {
        min = search(root->right, p, min);
        min = search(root->left, p, min);
    }
    else {
        min = search(root->left, p, min);
        min = search(root->right, p, min);
    }
    return min;
}
void print(Node *root) {
    if(!root)
        return;
    print(root->left);
    printf("pos = (%d, %d), dim = %d\n", root->pos[0], root->pos[1], root->dim);
    print(root->right);
}
int main(void)
{
    int N = 0;
    scanf("%d", &N);
    Node *dola = NULL, *kon = NULL;
    for(int i = 0; i < N; ++i) {
        int p[2];
        scanf("%d %d", &p[0], &p[1]);
        insert(&dola, p, 0);
        if(i != 0)
            printf("%d\n", search(kon, p, INT_MAX));
        scanf("%d %d", &p[0], &p[1]);
        insert(&kon, p, 0);
        printf("%d\n", search(dola, p, INT_MAX));
    }
#ifdef DEBUG
    puts("d");
    print(dola);
    puts("k");
    print(kon);
#endif
    return 0;
}

