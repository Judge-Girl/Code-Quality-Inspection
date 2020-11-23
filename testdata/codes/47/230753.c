#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define maxn 10000005
#define INF 0x3f3f3f
int cnt=0,lch[maxn],rch[maxn];
char com1[15],com2[15],ch;
int ty,num;
struct Node
{
    char c;
    int left,len,right,tot;
}e[maxn];
int string_to_int(char a[])
{
    int res=0;
    for(int i=strlen(a)-1,j=1;i>=0;i--,j*=10)
        res+=j*(a[i]-'0');
    return res;
}
void pull(int root)
{
    if(lch[root]) e[root].left=e[lch[root]].tot;
    if(rch[root]) e[root].right=e[rch[root]].tot;
    e[root].tot=e[root].left+e[root].len+e[root].right;
}
void create_new(int root,int C,char id)
{
    e[root].len=C;
    e[root].c=id;
    pull(root);
}
int insert(int root,int L,int l,char id)
{
    if(root==0 || cnt==0){create_new(++cnt,l,id);return cnt;}
    if(L>e[root].left && L<=e[root].left+e[root].len+1 && e[root].c==id) e[root].len+=l;
    else if(L<=e[root].left+1) lch[root]=insert(lch[root],L,l,id);
    else if(L>e[root].left+e[root].len) rch[root]=insert(rch[root],L-e[root].left-e[root].len,l,id);
    else{
        lch[root]=insert(lch[root],e[root].left+1,L-e[root].left-1,e[root].c);
        rch[root]=insert(rch[root],0,e[root].len+e[root].left-L+1,e[root].c);
        create_new(root,l,id);
    }
    pull(root);
    return root;
}
void print(int root)
{
    if(lch[root]) print(lch[root]);
    if(e[root].len) printf("%c %d ",e[root].c,e[root].len);
    if(rch[root]) print(rch[root]);
    return;
}
int main()
{
    while(~scanf("%s",com1)){
        if(com1[0]=='p'){
            print(1);
            printf("$\n");
        }
        else{
            scanf("%s",com2);
            getchar();
            scanf("%c%d",&ch,&num);
            if(isdigit(com2[0])) insert(1,string_to_int(com2),num,ch);
            else if(com2[0]=='l') insert(1,1,num,ch);
            else insert(1,e[1].tot+1,num,ch);
        }
    }
    return 0;
}

