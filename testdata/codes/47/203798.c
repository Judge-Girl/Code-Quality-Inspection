#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    struct node* lch;
    struct node* rch;
    int lidx;
    int ridx;
    char c;
    int num;
}Node;
Node* insert_left(Node* root,char x , int n){
    if(root == NULL){
        Node* cur = (Node*)malloc(sizeof(Node));
        cur->lch = cur->rch = NULL;
        cur->c = x;
        cur->num = n;
        cur->lidx = cur->ridx = 0;
        return cur;
    }
    else{
        if(root->lch == NULL && x == root->c){
            root->num += n;
            return root;
        }
        else{
            root->lch = insert_left(root->lch,x,n);
            root->lidx += n;
        }
    }
    return root;
}
Node* insert_right(Node* root,char x , int n){
    if(root == NULL){
        Node* cur = (Node*)malloc(sizeof(Node));
        cur->lch = cur->rch = NULL;
        cur->c = x;
        cur->num = n;
        cur->lidx = cur->ridx = 0;
        return cur;
    }
    else{
        if(root->rch == NULL && x == root->c){
            root->num += n;
            return root;
        }
        root->rch = insert_right(root->rch,x,n);
        root->ridx += n;
    }
    return root;
}
Node* insert(Node* root,char x, int n , int idx)
{
    if(root == NULL){
        Node* cur = (Node*)malloc(sizeof(Node));
        cur->lch = cur->rch = NULL;
        cur->c = x;
        cur->num = n;
        cur->lidx = cur->ridx = 0;
        return cur;
    }
    int ll = root->lidx+1;
    int rr = ll+root->num;
    if(root->c == x){
        if(idx >= ll && idx <= rr){
            root->num += n;
            return root;
        }
    }
    if( idx > ll && idx < rr){
        Node* leftnode = (Node*)malloc(sizeof(Node));
        Node* rightnode = (Node*)malloc(sizeof(Node));
        int lnum = idx - ll;
        int rnum = rr - idx;
        Node* cur = (Node*)malloc(sizeof(Node));
        leftnode->lch = root->lch;
        leftnode->rch = NULL;
        leftnode->lidx = root->lidx;
        leftnode->ridx = 0;
        leftnode->c = rightnode->c = root->c;
        leftnode->num = lnum; rightnode->num = rnum;
        rightnode->rch = root->rch;
        rightnode->lch = NULL;
        rightnode->lidx = 0;
        rightnode->ridx = root->ridx;
        cur->c = x;
        cur->num = n;
        cur->lch = leftnode;
        cur->rch = rightnode;
        cur->lidx = root->lidx + lnum;
        cur->ridx = root->ridx + rnum;
        return cur;
    }
    else if(idx <= ll){
        root->lch = insert(root->lch,x,n,idx);
        root->lidx += n;
        return root;
    }
    else if(idx >= rr){
        root->rch = insert(root->rch,x,n,idx-rr+1);
        root->ridx += n;
        return root;
    }
    return root;
}
void print(Node* root)
{
    if(root==NULL)
        return ;
    print(root->lch);
    printf("%c %d ",root->c,root->num);
    print(root->rch);
}
int main(){
    Node* root = NULL;
    char cmd [10];
    while(scanf("%s",cmd)==1){
        if(cmd[0]=='p'){
            print(root);
            printf("$\n");
            continue;
        }
        else{
            scanf("%s",cmd);
            char x ; int n; scanf(" %c %d",&x,&n);
            if(cmd[0]=='l'){
                root = insert_left(root,x,n);
            }
            else if(cmd[0]=='r'){
                root = insert_right(root,x,n);
            }
            else{
                int index = atoi(cmd);
                root = insert(root ,x ,n ,index);
            }
        }
    }
}
