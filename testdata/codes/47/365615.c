#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct treenode{
	char a;
	long long int lnum;
	int num;
	struct treenode *l;
	struct treenode *r;
}node;
node* insert_left(node* root,char c,int num2){
	if(root==NULL){
		root=(node*)malloc(sizeof(node));
        root->num=num2;
        root->a=c;
        root->lnum=0;
        root->l=NULL;
        root->r=NULL;
        return root;
	}
	node* current=root;
	while(current->l!=NULL){
		current->lnum+=num2;
        current=current->l;
    }
    if(current->a==c){
    	current->num+=num2;
    	return current;
	}else{
		current->lnum+=num2;
	    node* new=(node*)malloc(sizeof(node));
	    new->num=num2;
	    new->a=c;
	    new->lnum=0;
	    new->l=NULL;
	    new->r=NULL;
	    current->l=new;
	    current=current->l;
	    return current;
	}
}
node* insert_right(node* root,char c,int num2){
	if(root==NULL){
		root=(node*)malloc(sizeof(node));
        root->num=num2;
        root->lnum=0;
        root->a=c;
        root->l=NULL;
        root->r=NULL;
        return root;
	}
	node* current=root;
	while(current->r!=NULL){
        current=current->r;
    }
    if(current->a==c){
    	current->num+=num2;
    	return current;
	}else{
	    node* new=(node*)malloc(sizeof(node));
	    new->num=num2;
	    new->a=c;
	    new->lnum=0;
	    new->l=NULL;
	    new->r=NULL;
	    current->r=new;
	    current=current->r;
	    return current;
	}   
}
node* insert(node* root,char c,int num2,int po){
    if (root==NULL){
        root=(node*)malloc(sizeof(node));
        root->num=num2;
        root->a=c;
        root->lnum=0;
        root->l=NULL;
        root->r=NULL;
        return root;
    }
	node* current=root;
	int sum=0;
    while(1){
    	int st=current->lnum+1+sum,end=st+current->num-1;
    	if(po<=st){
    		if(current->l==NULL){
    			if(current->a==c){
			    	current->num+=num2;
			    	break;
				}else{
					current->lnum+=num2;
				    node* new=(node*)malloc(sizeof(node));
				    new->num=num2;
				    new->a=c;
				    new->lnum=0;
				    new->l=NULL;
				    new->r=NULL;
				    current->l=new;
				    current=current->l;
				    break;
				}
			}else{
				if(po==st){
					if(current->a==c){
			    		current->num+=num2;
			    		break;
			    	}
				}
				current->lnum+=num2;
				current=current->l;
			}
		}else if(po>end){
			sum+=(current->lnum+current->num);
			if(current->r==NULL){
				if(current->a==c){
			    	current->num+=num2;
			    	break;
				}else{
				    node* new=(node*)malloc(sizeof(node));
				    new->num=num2;
				    new->a=c;
				    new->lnum=0;
				    new->l=NULL;
				    new->r=NULL;
				    current->r=new;
				    current=current->r;
				    break;
				}   
			}else{
				if(po==end+1){
					if(current->a==c){
			    		current->num+=num2;
			    		break;
			    	}
				}
				current=current->r;
			}
		}else{
			if(current->a==c){
				current->num+=num2;
				break;
			}else{
				int right=end-po+1,left=current->num-right;
				current->num=right;
				node* new=(node*)malloc(sizeof(node));
			    new->num=left;
			    new->a=current->a;
			    new->lnum=current->lnum;
			    current->lnum+=left;
			    new->l=current->l;
			    new->r=NULL;
			    current->l=new;
			    node* new2=(node*)malloc(sizeof(node));
			    new2->num=right;
			    new2->a=current->a;
			    new2->lnum=0;
			    new2->l=NULL;
			    new2->r=current->r;
			    current->r=new2;
			    current->a=c;
			    current->num=num2;
			    break;
			}
		}
    }
    return current;
}
void print(node* root){
	if(root!=NULL){
		print(root->l);
		printf("%c %d ",root->a,root->num);
		print(root->r);
	}
	return;
}
int main(){
	node *root=NULL;
	char aa[8];
	while(scanf("%s",aa)!=EOF){
		if(!strcmp(aa,"insert")){
			char b[12];
			scanf("%s",b);
			if(!strcmp(b,"left")){
				char c[2];
				scanf("%s",c);
				int d;
				scanf("%d",&d);
				node* inode=insert_left(root,c[0],d);
				if(root==NULL){
					root=inode;
				}
			}else if(!strcmp(b,"right")){
				char c[2];
				scanf("%s",c);
				int d;
				scanf("%d",&d);
				node* inode=insert_right(root,c[0],d);
				if(root==NULL){
					root=inode;
				}
			}else{
				int bb=atoi(b);
				char c[2];
				scanf("%s",c);
				int d;
				scanf("%d",&d);
				node* inode=insert(root,c[0],d,bb);
				if(root==NULL){
					root=inode;
				}
			}
		}else{
			print(root);
			printf("$\n");
		}
	}
}
