#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
typedef struct NODE node;
 
struct NODE{
    int sz, mul;
    char val;
    node *lch, *rch;
};
 
static inline int rnd(){
    return rand();
}
 
static inline int size(node *tr){
    return tr ? tr->sz : 0;
}
 
void init(node *tr, char c, int num){
    tr->mul = tr->sz = num;
    tr->val = c;
    tr->lch = tr->rch = NULL;
}
 
void pull(node *tr){
    tr->sz = size(tr->lch) + size(tr->rch) + tr->mul;
}
 
node *allocate(){
    static node pool[500010];
    static int ptr = 0;
    return pool + (ptr ++);
}
 
node *merge(node *a, node *b){
    if(!a || !b)
        return a ? a : b;
    int det = rnd() % (a->sz + b->sz);
    if(det < a->sz){
        a->rch = merge(a->rch, b);
        pull(a->rch);
        return a;
    } else{
        b->lch = merge(a, b->lch);
        pull(b->lch);
        return b;
    }
}
 
void split(node *tr, node **a, node **b, int x){
    if(!tr)
        *a = *b = NULL;
    else if(size(tr->lch) >= x){
        *b = tr;
        split(tr->lch, a, &((*b)->lch), x);
        pull(*b);
    } else if(size(tr->lch) + tr->mul <= x){
        *a = tr;
        split(tr->rch, &((*a)->rch), b, x - size(tr->lch) - tr->mul);
        pull(*a);
    } else{
        node *p = allocate();
        init(p, tr->val, x - size(tr->lch));
        tr->mul -= p->mul;
        p->lch = tr->lch;
        tr->lch = NULL;
        *a = p, *b = tr;
        pull(*a), pull(*b);
    }
}
 
node *add(node *tr, int x, char c, int n){
    node *a, *b;
    split(tr, &a, &b, x);
    node *p = allocate();
    init(p, c, n);
    return merge(merge(a, p), b);
}
 
int get_pos(char *str, int n){
    if(str[0] == 'l')
        return 0;
    if(str[0] == 'r')
        return n;
    int len = strlen(str), ret = 0;
    for(int i = 0; i < len; i++)
        ret = 10 * ret + (str[i] - '0');
    return ret - 1;
}
 
char pre;
int len;
 
void putint(int x){
    int div = 1000000000, start = 0;
    while(div){
        int quo = x / div;
        if(quo || start)
            putchar(quo + '0');
        if(quo && !start)
            start = 1;
        x -= quo * div, div /= 10;
    }
}
 
void prt_unit(char c, int x){
    putchar(c);
    putchar(' ');
    putint(x);
    putchar(' ');
}
 
int max(int a, int b){
    return (a > b) ? a : b;
}
 
int prt(node *tr){
    if(!tr)
        return 0;
    int ret = 0;
    ret = max(prt(tr->lch), ret);
    if(len && tr->val != pre){
        prt_unit(pre, len);
        len = tr->mul, pre = tr->val;
    } else{
        pre = tr->val;
        len += tr->mul;
    }
    ret = max(prt(tr->rch), ret);
    return ret + 1;
}
 
const int S_MAX = 10;
 
int main(){
    char cmd[S_MAX];
    node *treap = NULL;
    int sum = 0;
    while(~scanf("%s", cmd)){
        if(cmd[0] == 'i') {
            char pos[S_MAX], c[S_MAX];
            int n;
            scanf("%s%s%d", pos, c, &n);
            sum += n;
            int x = get_pos(pos, size(treap));
            treap = add(treap, x, c[0], n);
            pull(treap);
        } else{
            pre = '\0', len = 0;
            if(prt(treap) > 150)
                printf("%d\n", 1 / 0);
            if(len)
                prt_unit(pre, len);
            puts("$");
        }
    }
    return 0;
}
