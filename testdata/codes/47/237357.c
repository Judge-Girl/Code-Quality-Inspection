#pragma GCC optimize("O3")
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
	int n,s,value;
	char c;
	struct Node *l,*r;
};

void pull(struct Node *a)
{
	a->s=(a->l?a->l->s:0)+(a->r?a->r->s:0)+a->n;
}

struct Node mem[500000];
int top=0;

struct Node* newNode(int n,char c)
{
	mem[top].n=n;
	mem[top].c=c;
	mem[top].s=n;
	mem[top].value=rand();
	mem[top].l=mem[top].r=0;
	return mem+top++;
}

struct Node* merge(struct Node *a,struct Node *b)
{
	if(!a)
		return b;
	if(!b)
		return a;
	if(a->value<b->value)
	{
		a->r=merge(a->r,b);
		pull(a);
		return a;
	}
	else
	{
		b->l=merge(a,b->l);
		pull(b);
		return b;
	}
}

void split(struct Node *cur,int k,struct Node** a,struct Node** b)
{
	if(!cur)
	{
		*a=*b=NULL;
		return;
	}
	int ls=(cur->l?cur->l->s:0);
	if(k<=ls)
	{
		*b=cur;
		split(cur->l,k,a,&((*b)->l));
		pull(*b);
	}
	else if(k>=ls+cur->n)
	{
		*a=cur;
		split(cur->r,k-ls-cur->n,&((*a)->r),b);
		pull(*a);
	}
	else
	{
		k-=ls;
		struct Node *tmp=newNode(cur->n-k,cur->c);
		cur->n=k;
		tmp->r=cur->r;
		cur->r=0;
		*a=cur;
		*b=tmp;
		pull(*a);
		pull(*b);
	}
}

struct Node* insert(struct Node *root,int p,int n,char c)
{
	struct Node *a,*b;
	split(root,p,&a,&b);
	struct Node *tmp=newNode(n,c);
	a=merge(a,tmp);
	a=merge(a,b);
	return a;
}

int narr[500000];
char carr[500000];
int ind;

void dfs(struct Node* cur)
{
	if(!cur)
		return;
	dfs(cur->l);
	narr[ind]=cur->n;
	carr[ind++]=cur->c;
	dfs(cur->r);
}

int main()
{
	char t[8],d[15];
	int p,n;
	char c;
	struct Node *root=NULL;
	while(~scanf("%s",t))
	{
		if(strcmp(t,"insert")==0)
		{
			scanf("%s %c%d",d,&c,&n);
			if(strcmp(d,"left")==0)
				p=0;
			else if(strcmp(d,"right")==0)
				p=(root?root->s:0);
			else
				p=atoi(d)-1;
			root=insert(root,p,n,c);
		}
		else
		{
			ind=0;
			dfs(root);
			int cnt=0,i;
			char pre=0;
			for(i=0;i<ind;i++)
			{
				if(i==0)
				{
					cnt=narr[i];
					pre=carr[i];
				}
				else if(carr[i]!=pre)
				{
					printf("%c %d ",pre,cnt);
					cnt=narr[i];
					pre=carr[i];
				}
				else
					cnt+=narr[i];
			}
			if(cnt)
				printf("%c %d ",pre,cnt);
			printf("$\n");
		}
	}
	return 0;
}
