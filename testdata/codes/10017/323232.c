#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#define INF 0x3f3f3f3f;

struct Tree{
    int x, y;
    struct Tree *lch, *rch;
    struct Tree *subtree;
}; 
typedef struct Tree Tree;

int min(int a ,int b){
    return a < b ? a : b;
}
int dis(int ax, int ay, int bx, int by) {
    return abs(ax - bx) + abs(ay - by);
}

Tree* insert(Tree* node, int x, int y, int dim) {
    if(node == NULL) {
        node = malloc(sizeof(Tree));
        assert(node != NULL);
        node->x = x; node->y = y;
         node->lch = node->rch = node->subtree = NULL;

    }    
    if(dim == 0) {
        if(x == node->x) {
            node->subtree = insert(node->subtree, x, y, 1);
            return node;
        }
        if(x < node->x) node->lch = insert(node->lch, x, y, 0);
        else node->rch = insert(node->rch, x, y, 0);
    }
    else if(dim == 1) {
        if(y == node->y) return node;
        if(y < node->y) node->lch = insert(node->lch, x, y, 1);
        else node->rch = insert(node->rch, x, y, 1);
    }
    return node;
}

int min_d;
int query(Tree* node, int x, int y, int dim) {
    if(dim == 0) {
        int d = query(node->subtree, x, y, 1);
        if(x == node->x) {
             if(node->lch) d = min(d, query(node->lch, x, y, 0));
             if(node->rch) d = min(d, query(node->rch, x, y, 0));
        }
        else if(x < node->x) {
            if(node->lch) d = min(d, query(node->lch, x, y, 0));
            if(node->rch && abs(x - node->x) < min_d) d = min(d, query(node->rch, x, y, 0)); 
        }
        else if(x > node->x) {
            if(node->rch) d = min(d, query(node->rch, x, y, 0)); 
            if(node->lch && abs(x - node->x) < min_d)  d = min(d, query(node->lch, x, y, 0)); 
        }

        return d;
    }
    else {
        int d = dis(x, y, node->x, node->y);
        min_d = min(d, min_d);
        if(y == node->y) return d;
        if(y < node->y) {
            if(node->lch) return min(d, query(node->lch, x, y, 1));
            return d;
        }
        else if(y > node->y) {
            if(node->rch) return min(d, query(node->rch, x, y, 1));
            return d;
        }
    }
    return -1;
}

Tree *odd = NULL, *even = NULL;
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < 2 * n; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        if(i & 1) odd = insert(odd, x, y, 0);
        else even = insert(even, x, y, 0);

        if(i == 0) continue;
        min_d = INF;
        if(i & 1) printf("%d\n", query(even, x, y, 0));
        else printf("%d\n", query(odd, x, y, 0));
    }
    return 0;
}

