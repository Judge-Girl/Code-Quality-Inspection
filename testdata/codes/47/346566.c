#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
 
typedef struct Tree {
    int left_size, right_size, size;
    char c;
    struct Tree *lch, *rch; 
} Tree;
 
Tree *newTree(Tree *root, char c, int n) {
    root = malloc(sizeof *root); assert(root != NULL);
    root->size = n; root->c = c; 
    root->left_size = root->right_size = 0;
    root->lch = root->rch = NULL;
    return root;;
}
 
Tree *update(Tree *root) {
    if(root->lch) 
        root->left_size = root->lch->left_size + root->lch->right_size + root->lch->size;
    if(root->rch) 
        root->right_size = root->rch->left_size + root->rch->right_size + root->rch->size;
    return root;
 
}
 
int check_merge(Tree *root, int k, char c, int n) {
    if(c != root->c) return 0;
    if(k > root->left_size + root->size) return 0;
    if(k < root->left_size) return 0;
    return 1;
} 
 
Tree *insert(Tree *root, int k, char c, int n) {
    if(root == NULL) {
        root = newTree(root, c, n);
        return root;
    }
    if(check_merge(root, k, c, n)) {
        root->size += n;
    }
    else if(k <= root->left_size) {
        root->lch = insert(root->lch, k, c, n); 
    }
    else if(k >= root->left_size + root->size) {
        root->rch = insert(root->rch, k - root->left_size - root->size, c, n); 
    }
    else {
        if(k - root->left_size > 0)
            root->lch = insert(root->lch, root->left_size, root->c, k - root->left_size);
        if(root->size + root->left_size - k > 0)
            root->rch = insert(root->rch, 0, root->c, root->size - (k - root->left_size));
        root->c = c; root->size = n;
    }
    root = update(root);
    return root;
} 
void travel(Tree *root) {
    if(root == NULL) return;
    travel(root->lch);
    printf("%c %d ", root->c, root->size);
    //printf("l %d r %d\n", root->left_size, root->right_size);
    travel(root->rch);
    return;
}
 
int main(void)
{
    char cmd[50];
    Tree *tree = NULL;
    while(scanf("%s", cmd) != EOF){
        if(strcmp(cmd, "print") == 0) {
           travel(tree); printf("$\n");
        }
        else {
            int n, k = 0;
            char c[2];
            scanf("%s%s%d", cmd, c, &n);
            if(strcmp(cmd, "left") == 0) k = 0;
            else if(strcmp(cmd, "right") == 0) {
                if(tree) k = tree->left_size + tree->right_size + tree->size;
                else  k = 0;
            }
            else k = atoi(cmd) - 1;
            tree = insert(tree, k, c[0], n);
        }
    }
 
    return 0;
}

