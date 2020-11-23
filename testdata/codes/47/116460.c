#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node{
    int n,index;
    struct Node *l,*m,*r;
    char name;
}Node;
Node* new_node(int a,char b){
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->n=a ,temp->index=2 ,temp->name=b ,temp->l=NULL, temp->m=NULL, temp->r=NULL;
    return temp;
}
void build(Node *root,int pos,char ch,int last,int now){
    if(root->l==NULL){
        if(pos-now==1){
            root->l=new_node(last,ch);
            root->r=new_node(root->n,root->name);
            root->n+=last;
        }else{
            root->l=new_node(pos-now-1,root->name);
            root->m=new_node(last,ch);
            root->r=new_node(root->n-(pos-now-1),root->name);
            root->n+=last;
            if(root->r->n==0) root->r=root->m, root->index=2;
            else root->index=3;
        }
    }
    else if(root->index==2){
        if(now+root->l->n >= pos) build(root->l,pos,ch,last,now);
        else build(root->r,pos,ch,last,now+root->l->n);
        root->n+=last;
    }else{
        if(now+root->l->n >= pos) build(root->l,pos,ch,last,now);
        else if(now+root->l->n+root->m->n >= pos) build(root->m,pos,ch,last,now+root->l->n);
        else build(root->r,pos,ch,last,now+root->l->n+root->m->n);
        root->n+=last;
    }
}
void print(Node *root,char *last,int *ans){
    if(root->l==NULL){
        if(*ans==-1){
            *last=root->name;
            *ans=root->n;
            return;
        }
        if(root->name==*last){
            *ans+=root->n;
            return;
        }
        printf("%c %d ",*last,*ans);
        *last=root->name;
        *ans=root->n;
        return;
    }
    print(root->l,last,ans);
    if(root->index==3) print(root->m,last,ans);
    print(root->r,last,ans);
}
int main(){
    Node *root=new_node(0,'*');
    char command[7];
    int i;
    while(scanf("%s",&command)!=EOF){
        if(command[0]=='i'){
            char pos[33],ch[2];
            int last;
            scanf("%s%s%d",&pos,&ch,&last);
            if(root->name=='*'){
                root->name=ch[0];
                root->n=last;
                root->index=2;
            }
            else if(pos[0]=='l') build(root,1,ch[0],last,0);
            else if(pos[0]=='r') build(root,root->n+1,ch[0],last,0);
            else{
                int poss=atoi(&pos[0]);
                build(root,poss,ch[0],last,0);
            }
        }else{
            char last;
            int ans=-1;
            if(root->name!='*'){
                print(root,&last,&ans);
                printf("%c %d ",last,ans);
            }
            printf("$\n");
        }
    }
    return 0;
}

