#include <stdio.h>
#include <string.h>

#define maxn  105
int n, g[maxn][maxn];
int mval;
int flag;

typedef struct Vector
{
    int sz;
    int a[105];
} Set;

Set U;

void dfs(int x, Set S) // S can use, U used
{
    //if(flag) return;

    if(U.sz > mval)
    {
        mval = U.sz;
        if(x == n) {flag = 1; return;}
    }

    for(int i = 0; i < S.sz; i++)
    {
        if(mval > U.sz + S.sz - i) break;
        int cur = S.a[i];

        U.a[U.sz++] = cur;

        Set nS; nS.sz = 0;
        for(int j = i+1; j < S.sz; j++)
            if(g[cur][S.a[j]]) nS.a[nS.sz++] = S.a[j];
        if(U.sz + nS.sz > mval) dfs(cur, nS);

        U.sz--;
    }
}

int main()
{
    scanf("%d", &n);
    memset(g, 0, sizeof g);
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) scanf("%d", &g[i][j]);
    for(int i = 1; i <= n; i++) g[i][0] = g[0][i] = 1; // super source

    mval = 0;
    flag = 0;
    Set S0;
    S0.sz = n; U.sz = 0;
    for(int i = 1; i <= n; i++) S0.a[i-1] = i;
    dfs(0, S0);

    printf("%d\n", mval);

    return 0;
}

