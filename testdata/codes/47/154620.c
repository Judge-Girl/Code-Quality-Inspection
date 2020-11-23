#include<stdio.h>
#include<stdlib.h>
#define sTreap struct Treap
struct Treap{
	char c;
	sTreap *l,*r;
	int n,sz,pri;
	void (*pull)(sTreap**);
}*root;
int Size(sTreap *t){
	if(t)return t->sz;
	return 0;
}
void pulls(sTreap **t){
	(*t)->sz=(*t)->n+Size((*t)->l)+Size((*t)->r);
}
sTreap *merge(sTreap *a,sTreap *b){
	if(!a||!b)return a?a:b;
	if(a->pri>b->pri){
		a->r=merge(a->r,b);
		a->pull=pulls;
		a->pull(&a);
		return a;
	}
	else{
		b->l=merge(a,b->l);
		b->pull=pulls;
		b->pull(&b);
		return b;
	}
}
void split(sTreap *t,int k,sTreap **a,sTreap **b,int *x,char *c){
	if(!t){
		*a=NULL,*b=NULL;
		return;
	}
	if(k>=Size(t->l)+t->n){
		*a=t;
		split(t->r,k-Size(t->l)-t->n,&((*a)->r),b,x,c);
	}
	else if(k<=Size(t->l)){
		*b=t;
		split(t->l,k,a,&((*b)->l),x,c);
	}
	else{
		*a=t;
		*x=t->n-(k-Size(t->l));
		*c=t->c;
		(*a)->n=k-Size(t->l);
		split(t->r,0,&((*a)->r),b,x,c);
	}
	t->pull=pulls;
	t->pull(&t);
	return;
}
char ans_c[1000000];
int ans_v[1000000],ptr;
void print(sTreap *t){
	if(t->l)print(t->l);
	ans_c[ptr]=t->c,ans_v[ptr]=t->n;
	ptr++;
	if(t->r)print(t->r);
}
int main(){
	srand(0);
	root=NULL;
	char str[1024];
	while(scanf("%s",str)!=EOF){
		if(str[0]=='p'){
			if(root){
				ptr=0;
				print(root);
				for(int i=0;i<ptr;i++){
					if(i<ptr-1&&ans_c[i+1]==ans_c[i])ans_v[i+1]+=ans_v[i];
					else printf("%c %d ",ans_c[i],ans_v[i]);
				}
			}
			printf("$\n");
		}
		else{
			scanf("%s",str);
			int k,num;
			if(str[0]=='l')k=0;
			else if(str[0]=='r')
				k=Size(root);
			else k=atoi(str),k--;
			char ch;
			scanf(" %c %d",&ch,&num);
			sTreap *a,*b;
			int num2=-1;
			char ch2;
			split(root,k,&a,&b,&num2,&ch2);
			if(num2==-1){
				sTreap *t=(sTreap*)malloc(sizeof(sTreap));
				t->n=num;
				t->sz=num;
				t->c=ch;
				t->pri=rand();
				t->l=NULL,t->r=NULL;
				root=merge(merge(a,t),b);
			}
			else{
				sTreap *t=(sTreap*)malloc(sizeof(sTreap)),*t1=(sTreap*)malloc(sizeof(sTreap));
				t->n=num,t1->n=num2;
				t->sz=num,t1->sz=num2;
				t->c=ch,t1->c=ch2;
				t->pri=rand(),t1->pri=rand();
				t->l=t->r=t1->l=t1->r=NULL;
				root=merge(merge(merge(a,t),t1),b);
			}
		}
	}
    return 0;
}


