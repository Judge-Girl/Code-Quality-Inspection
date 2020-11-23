#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct str{
    char c;
    int n, leftlen, rightlen;
    struct str *left, *right;
};
 
struct str *root;
 
struct str *new_str(char c, int n, int ln, int rn, struct str *l, struct str *r){
    struct str *s = (struct str*)malloc(sizeof(struct str));
    s->c = c;
    s->n = n;
    s->leftlen = ln;
    s->rightlen = rn;
    s->left = l;
    s->right = r;
    return s;
};
 
void insert_left(char c, int n){
    struct str *pt = root;
    while (pt->left != NULL) {
        pt->leftlen += n;
        pt = pt->left;
    }
    if (pt->c == c) {
        pt->n += n;
    }
    else {
        pt->left = new_str(c, n, 0, 0, NULL, NULL);
        pt->leftlen += n;
    }
    return;
}
 
void insert_right(char c, int n){
    struct str *pt = root;
    while (pt->right != NULL) {
        pt->rightlen += n;
        pt = pt->right;
    }
    if (pt->c == c) {
        pt->n += n;
    }
    else {
        pt->right = new_str(c, n, 0, 0, NULL, NULL);
        pt->rightlen += n;
    }
    return;
}
 
void insert_n(struct str *pt, int posn, char c, int n){
    if (posn <= pt->leftlen) {
        pt->leftlen += n;
        insert_n(pt->left, posn, c, n);
    }
    else if (posn - pt->leftlen - pt->n > 1){
        pt->rightlen += n;
        insert_n(pt->right, posn - pt->leftlen - pt->n, c, n);
    }
    else {
        if (pt->c == c) {
            pt->n += n;
        }
        else if (posn - pt->leftlen == 1){
            if (pt->left == NULL) {
                pt->left = new_str(c, n, 0, 0, NULL, NULL);
            }
            else {
                insert_n(pt->left, posn, c, n);
            }
            pt->leftlen += n;
        }
        else if (posn - pt->leftlen - pt->n == 1){
            if (pt->right == NULL) {
                pt->right = new_str(c, n, 0, 0, NULL, NULL);
            }
            else {
                insert_n(pt->right, 1, c, n);
            }
            pt->rightlen += n;
        }
        else {
            posn -= pt->leftlen;
            pt->left = new_str(pt->c, posn - 1, pt->leftlen, 0, pt->left, NULL);
            pt->leftlen += pt->left->n;
            pt->right = new_str(pt->c, pt->n - posn + 1, 0, pt->rightlen, NULL, pt->right);
            pt->rightlen += pt->right->n;
            pt->c = c;
            pt->n = n;
        }
    }
    
    return;
}
 
void print_str(struct str* pt){
    if (pt == NULL) {
        return;
    }
    print_str(pt->left);
    printf("%c %d ", pt->c, pt->n);
    print_str(pt->right);
    return;
}
 
int main(){
    root = NULL;
    char instr[16];
    while (scanf("%s", instr) != EOF) {
        if (instr[0] == 'p') {
            print_str(root);
            printf("$\n");
        }
        else if (instr[0] == 'i'){
            char pos[16], c[4];
            int n;
            scanf("%s%s%d", pos, c, &n);
            if (root == NULL) {
                root = new_str(c[0], n, 0, 0, NULL, NULL);
            }
            else if (pos[0] == 'l') {
                insert_left(c[0], n);
            }
            else if (pos[0] == 'r') {
                insert_right(c[0], n);
            }
            else {
                int posn;
                sscanf(pos, "%d", &posn);
                insert_n(root, posn, c[0], n);
            }
        }
    }
    return 0;
}

