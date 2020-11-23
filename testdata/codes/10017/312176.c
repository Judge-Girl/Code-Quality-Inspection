#include<stdio.h>
#include<stdlib.h>
#define abs(x) ((x)>0?(x):-(x))
#pragma optimize ("Ofast")
typedef struct node{
    struct node *l,*r;
    int x,y;
    _Bool dim;
}Node;

Node *newn(int x,int y){
    static Node mem[200010];
    static Node *pt=mem;
    pt->l=pt->r=NULL;
    pt->x=x,pt->y=y;
    return pt++;
}
_Bool dimt=1;

Node *insert(Node *tr,Node *sor){
    if(tr==NULL){
            sor->dim=!dimt;
            return sor;
            }
    dimt=tr->dim;
    if(tr->dim==0){
        if(tr->x <= sor->x)
            tr->r=insert(tr->r,sor);
        else
            tr->l=insert(tr->l,sor);
    }
    if(tr->dim==1){
        if(tr->y <= sor->y)
            tr->r=insert(tr->r,sor);
        else
            tr->l=insert(tr->l,sor);
    }
    return tr;
}
int mindis=1<<30;
int min(int a,int b){
    return a>b?b:a;
}
int dis(Node *n,int x,int y){
    return abs(n->x - x)+abs(n->y - y);
}

int search(Node *tree,int x,int y){
    if(tree==NULL)return 0;

    /*if(tree->dim==0 && abs(tree->x -x)>=mindis)return 0;
    if(tree->dim==1 && abs(tree->y -y)>=mindis)return 0;*/

    mindis=min(dis(tree,x,y),mindis);

    if(tree->dim==0){
        if(tree->x > x){
            if(tree->l!=NULL)search(tree->l,x,y);
            if(tree->r!=NULL&& abs(tree->x -x)<mindis )search(tree->r,x,y);
        }
        else{
            if(tree->r!=NULL)search(tree->r,x,y);
            if(tree->l!=NULL&& abs(tree->x -x)<mindis)search(tree->l,x,y);
        }
    }
    else{

        if(tree->y > y){
            if(tree->l!=NULL)search(tree->l,x,y);
            if(tree->r!=NULL&& abs(tree->y -y)<mindis)search(tree->r,x,y);
        }
        else{
            if(tree->r!=NULL)search(tree->r,x,y);
            if(tree->l!=NULL&& abs(tree->y -y)<mindis)search(tree->l,x,y);
        }
    }
    return 0;
};
int main(){
    int n;
    scanf("%d",&n);
    int a,b;
    Node *t;
    Node *rt1=NULL,*rt2=NULL;

    scanf("%d%d",&a,&b); // first time
    t=newn(a,b);
    rt1=insert(rt1,t);
    scanf("%d%d",&a,&b);
    t=newn(a,b);
    rt2=insert(rt2,t);
    mindis=1<<25;
    search(rt1,a,b);
    printf("%d\n",mindis);

    for(int i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        t=newn(a,b);
        rt1=insert(rt1,t);
        mindis=1<<25;
        search(rt2,a,b);
        printf("%d\n",mindis);
        scanf("%d%d",&a,&b);
        t=newn(a,b);
        rt2=insert(rt2,t);
        mindis=1<<25;
        search(rt1,a,b);
        printf("%d\n",mindis);
    }
    return 0;
}

