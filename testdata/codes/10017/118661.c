#include <stdio.h>
#include <stdlib.h>
 
typedef struct{
    short v[2];
}Pos;
 
typedef struct Node{
    Pos p;
    char c;
    struct Node* left;
    struct Node* right;
}Node; 
 
inline int dis(Pos a,Pos b){
    return abs(a.v[0]-b.v[0])+abs(a.v[1]-b.v[1]);
}
 
void insert(Node **head,Pos p,char c){
    if(!*head){
        *head=malloc(sizeof(Node));
        (*head)->left=NULL;
        (*head)->right=NULL;
        (*head)->p=p;
        (*head)->c=c;
        return;
    }
    if(p.v[(*head)->c]>(*head)->p.v[(*head)->c])
        insert(&((*head)->right),p,(*head)->c^1);
    else
        insert(&((*head)->left),p,(*head)->c^1);
}
 
int search(Node *head,Pos p,int min){
    if(!head)
        return min;
    int t=dis(head->p,p);
    if(t<min)
        min=t;
    if((p.v[head->c]-head->p.v[head->c])>=min)
        return search(head->right,p,min);
    if((p.v[head->c]-head->p.v[head->c])<=-min)
        return search(head->left,p,min);
    if(p.v[head->c]>head->p.v[head->c]){
        min=search(head->right,p,min);
        min=search(head->left,p,min);
    }
    else{
        min=search(head->left,p,min);
        min=search(head->right,p,min);
    }    
    return min;
}
 
void ReadShort(short *x){
    char c;
    while(c=getchar())
        if(c<='9'&&c>='0') break;
    *x=c-'0';
    while(c=getchar()){
        if(c>'9'||c<'0') break;    
        *x=(*x<<3)+(*x<<1)+c-'0';
    }        
}
 
int main()
{
    Node *Sora=NULL;
    Node *Dora=NULL;
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        Pos p;
        ReadShort(&p.v[0]);
        ReadShort(&p.v[1]);
        insert(&Dora,p,0);
        if(i)    printf("%d\n",search(Sora,p,65535));
        ReadShort(&p.v[0]);
        ReadShort(&p.v[1]);
        insert(&Sora,p,0);
        printf("%d\n",search(Dora,p,65535));
    }
    return 0;
}

