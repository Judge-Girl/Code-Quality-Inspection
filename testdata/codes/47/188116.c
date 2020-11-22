#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
    char c;
    int size;
    struct node *left, *right;
} Node;

// construction of an external node; other attributes are undefined
Node *init()
{
    Node *external = (Node *) malloc(sizeof(Node));
    assert(external != NULL);
    external->size = 0;
    return external;
}
inline int length(Node *p)
{
    return p->size - p->left->size - p->right->size;
}
void myprint(Node *root)
{
    if(root->size == 0) return;
    myprint(root->left);
    printf("%c %d ", root->c, length(root));
    myprint(root->right);
}
void insertLeft(Node *root, char x, int n)
{
    Node *p = root, *prev = NULL;
    while(p->size != 0) {
        p->size += n;
        prev = p;
        p = p->left;
    }
    if(prev != NULL && prev->c == x) {
        return;
    }
    p->size += n;
    p->c = x;
    p->left = init();
    p->right = init();
}
void insertRight(Node *root, char x, int n)
{
    Node *p = root, *prev = NULL;
    while(p->size != 0) {
        p->size += n;
        prev = p;
        p = p->right;
    }
    if(prev != NULL && prev->c == x) {
        return;
    }
    p->size += n;
    p->c = x;
    p->left = init();
    p->right = init();
}
void insert(Node *root, int now, int k, char x, int n)
{
    if(root->size == 0) {
        root->size = n;
        root->c = x;
        root->left = init();
        root->right = init();
        return;
    }
    int a = now + root->left->size + 1, b = now + root->size - root->right->size;
    if(k <= a) {
        if(k == a && root->c == x) {
            root->size += n;
            return;
        }
        root->size += n;
        insert(root->left, now, k, x, n);
    }
    else if(k > b) {
        if(k == b + 1 && root->c == x) {
            root->size += n;
            return;
        }
        root->size += n;
        insert(root->right, b, k, x, n);
    }
    else {
        if(root->c == x) {
            root->size += n;
            return;
        }
        int l = k - a, r = b - k + 1;
        insertLeft(root->right, root->c, r);
        insertRight(root->left, root->c, l);
        root->size += n;
        root->c = x;
    }
}
int main(void)
{
    char cmd[16] = {};
    Node *root = init();

    while(scanf("%s", cmd) == 1) {
        if(!strcmp(cmd, "print")) {
            myprint(root);
            puts("$");
        }
        else if(!strcmp(cmd, "insert")) {
            scanf("%s", cmd);
            if(!strcmp(cmd, "left")) {
                char x[2];
                int n;
                scanf("%s %d", x, &n);
                insertLeft(root, x[0], n);
            }
            else if(!strcmp(cmd, "right")) {
                char x[2];
                int n;
                scanf("%s %d", x, &n);
                insertRight(root, x[0], n);
            }
            else {
                int k = atoi(cmd);
                char x[2];
                int n;
                scanf("%s %d", x, &n);
                insert(root, 0, k, x[0], n);
            }
        }
#ifdef DEBUG
        myprint(root);
        puts("$$");
#endif
    }
    return 0;
}

