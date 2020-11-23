#include<stdio.h>
#include<stdlib.h>
 
typedef struct SAVE {
    int y, m, d;
}save;
 
save s[1000000];
 
int cmp(const void *a, const void *b){
    save c = *(save*)a;
    save d = *(save*)b;
    if (c.y == d.y) {
        if (c.m == d.m) {
            return c.d - d.d;
        }
        return c.m - d.m;
    }
    return c.y - d.y;
}
 
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &s[i].y, &s[i].m, &s[i].d);
    }
    qsort(s, n, sizeof(save), cmp);
    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", s[i].y, s[i].m, s[i].d);
    }
}
