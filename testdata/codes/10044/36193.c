#include <stdio.h>
int max(int x,int y) {return x>y?x:y;}
struct Set {
    int s[110];
    int l;
};
int rel[110][110],n,find,ans,term;

void DFS(int x, struct Set A, struct Set S) {
    if(find) return;
    if(A.l>ans&&S.l==0) {
        ans=A.l;
        if(x==term) find=1;
    }
    for(int i=0; i<S.l; i++) {
        if(ans>A.l+S.l-i) break;
        int now=S.s[i];
        A.s[A.l]=now,A.l++;
        struct Set S1;S1.l=0;
        for(int j=i+1; j<S.l; j++) 
            if(rel[now][S.s[j]]) S1.s[S1.l]=S.s[j],S1.l++;
        if(A.l+S1.l>ans) DFS(now,A,S1);
        A.l--;
    }
}

int main() {
    scanf("%d",&n);
    for(int i=0; i<n; i++) 
        for(int j=0; j<n; j++) scanf("%d",&rel[i][j]);
    struct Set A;A.l=0;
    int a=0;
    for(int i=0; i<n; i++) {
        find=0,ans=0;
        A.s[0]=i,A.l=1;
        struct Set S;S.l=0;
        for(int j=i+1; j<n; j++)
            if(rel[i][j]) S.s[S.l]=j,S.l++;
        DFS(i,A,S);
        term=S.s[S.l-1];
        a=max(a,ans);
    }
    printf("%d\n",a);
    return 0;
}
