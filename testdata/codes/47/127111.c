#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 128
 
typedef struct Node {
    struct Node *lson, *rson;
    int n, lx, rx;
    char c;
} Node;
 
Node *root = NULL;
int cnt = 1;
 
 
Node *new_node(int n, int lx, int rx, char c, Node *lson, Node *rson) {
    Node *ret = (Node *)malloc(sizeof(Node));
    ret->lson = lson;
    ret->rson = rson;
    ret->n = n;
    ret->c = c;
    ret->lx = lx;
    ret->rx = rx;
    return ret;
}
////////////////insert
void insert(int k, char c, int n) {
    if(root == NULL) {
        root = new_node(n, 0, 0, c, NULL, NULL);
        return;
    }
    Node *cur = root;
    int pos = root->lx+1;
    while(k <= pos || k >= pos+cur->n) {
        if(k == pos) {
            if(cur->c == c) {
                cur->n += n;
                return;
            }
            if(cur->lson != NULL) {
                Node *pre = cur->lson;
                while(pre->rson != NULL) pre = pre->rson;
                if(pre->c == c) {
                    pre->n += n;
                    pre = cur->lson;
                    cur->lx += n;
                    while(pre->rson != NULL) {
                        pre->rx += n;
                        pre = pre->rson;
                    }
                    return;
                } else {
                    Node *node = new_node(n, 0, 0, c, NULL, NULL);
                    cur->lx += n;
                    pre->rson = node;
                    pre = cur->lson;
                    while(pre != node) {
                        pre->rx += n;
                        pre = pre->rson;
                    }
                }
            } else {
                cur->lson = new_node(n, 0, 0, c, NULL, NULL);
                cur->lx = n;
            }
            return;
        } else if(k == pos+cur->n) {
            if(cur->c == c) {
                cur->n += n;
                return;
            }
            if(cur->rson != NULL) {
                Node *next = cur->rson;
                while(next->lson != NULL) next = next->lson;
                if(next->c == c) {
                    next->n += n;
                    cur->rx += n;
                    next = cur->rson;
                    while(next->lson != NULL) {
                        next->lx += n;
                        next = next->lson;
                    }
                } else {
                    Node *node = new_node(n, 0, 0, c, NULL, NULL);
                    cur->rx += n;
                    next->lson = node;
                    next = cur->rson;
                    while(next != node) {
                        next->lx += n;
                        next = next->lson;
                    }
                }
                return;
            } else {
                cur->rson = new_node(n, 0, 0, c, NULL, NULL);
                cur->rx = n;
            }
            return;
        } else if(k < pos) {
            cur->lx += n;
            cur = cur->lson;
            pos -= (cur->n+cur->rx);
        } else if(k > pos+cur->n) {
            pos += cur->n;
            cur->rx += n;
            cur = cur->rson;
            pos += cur->lx;
        }
    }
    if(cur->c == c) {
        cur->n += n;
        return;
    } else {
        Node *left = new_node(k-pos, cur->lx, 0, cur->c, cur->lson, NULL);
        Node *right = new_node(cur->n-left->n, 0, cur->rx, cur->c, NULL, cur->rson);
        cur->c = c;
        cur->lson = left;
        cur->rson = right;
        cur->n = n;
        cur->lx += left->n;
        cur->rx += right->n;
    }
}
/////////////
void print(Node *node) {
    if(node == NULL) return;
    print(node->lson);
    printf("%c %d ", node->c, node->n);
    print(node->rson);
}
int main(void) {
    char s[MAXN];
    while(~scanf("%s", s)) {
        if(s[0] == 'p') {
            print(root);
            putchar('$');
            putchar('\n');
        } else {
            scanf("%s", s);
            char c[2];
            int n, k;
            scanf("%s%d", c, &n);
            if(isdigit(s[0])) {
                sscanf(s, "%d", &k);
                insert(k, *c, n);
            } else {
                if(*s == 'l') insert(1, *c, n);
                if(*s == 'r') insert(cnt, *c, n);
            }
            cnt += n;
        }
    }
}
