#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct word{
    char c;
    int sz,lsz,rsz;
    struct word *l,*r;
}word;
 
word* left(word *root,char x,int n){
    if (root==NULL){
        root=(word*)malloc(sizeof(word));
        root->c=x;
        root->sz=n;
		root->lsz=0;
		root->rsz=0;
    }
    else if (root->l==NULL && root->c==x) root->sz+=n;
    else{
		root->lsz+=n;
		root->l=left(root->l,x,n);
	}
    return root;
}
word* right(word *root,char x,int n){
    if (root==NULL){
        root=(word*)malloc(sizeof(word));
        root->c=x;
        root->sz=n;
		root->lsz=0;
		root->rsz=0;
    }
    else if (root->r==NULL && root->c==x) root->sz+=n;
    else{  
		root->r=right(root->r,x,n);
		root->rsz+=n;
	}
    return root;
}
word* k(word *root,int cnt,char x,int n){
    if (root!=NULL){
        if (cnt-1<root->lsz){
			root->l=k(root->l,cnt,x,n);
			root->lsz+=n;
		}
        else if (cnt-1==root->lsz) {
            if (root->c==x) root->sz+=n;
            else{
				root->l=right(root->l,x,n);
				root->lsz+=n;
			}
        }
        else if (cnt-1<root->lsz+root->sz){
            if (root->c==x) root->sz+=n;
            else {
                root->l=right(root->l,root->c,cnt-1-root->lsz);
                root->r=left(root->r,root->c,root->sz-(cnt-1-root->lsz));
				root->rsz+=root->sz-(cnt-1-root->lsz);
				root->lsz=cnt-1;
                root->c=x;
                root->sz=n;
            }
        }
        else if (cnt-1==root->lsz+root->sz){
            if (root->c==x) root->sz+=n;
            else{
				root->r=left(root->r,x,n);
				root->rsz+=n;
			}
        }
        else if (cnt-1<root->lsz+root->sz+root->rsz){
			root->r=k(root->r,cnt-root->lsz-root->sz,x,n);
			root->rsz+=n;
		}
        else{
			root=right(root,x,n);// cnt-1==l+m+r
			root->rsz+=n;
		}
    }
    else{
        root=(word*)malloc(sizeof(word));
        root->c=x;
        root->sz=n;
    }
    return root;
}
void print(word* root){
    if (root!=NULL){
        print(root->l);
        printf("%c %d ",root->c,root->sz);
        print(root->r);
    }
    return;
}
 
int main (){
    word *h=NULL;
    char tmp[11];
    while (~scanf("%s",tmp)){
        if (!strcmp(tmp,"insert")){
            char x;
            int n;
            scanf("%s %c %d",tmp,&x,&n);
            if (!strcmp(tmp,"left")) h=left(h,x,n);
            else if (!strcmp(tmp,"right")) h=right(h,x,n);
            else {
                int cnt=atoi(tmp);
                h=k(h,cnt,x,n);
            }
        }
        else{
            print(h);
            printf("$\n");
        }
    }
    return 0;
}

