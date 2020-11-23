#pragma GCC optimize("Ofast")
#include"stdio.h"
#include"ctype.h"
#define Node struct Node
#define abs(x) (x>=0?x:-(x))
#define min(a,b) (a<=b?a:b)

Node
{
	Node *l,*r;
	int a[2];
};

Node mem[200010];
int t;
Node* nil;

Node* pt;

Node* insert(Node* cur,int k)
{
	if(cur==nil)
		return pt;
	if(k==2)
		k=0;
	if(pt->a[k]<=cur->a[k])
		cur->l=insert(cur->l,k+1);
	else
		cur->r=insert(cur->r,k+1);
	return cur;
}

inline int dis(Node* a,Node* b)
{
	return abs(a->a[0]-b->a[0])+abs(a->a[1]-b->a[1]);
}

int cd[2],ans;

void query(Node* cur,int k)
{
	if(cur==nil||cd[0]+cd[1]>=ans)
		return;
	if(k==2)
		k=0;
	ans=min(ans,dis(cur,pt));
	int tmp=cd[k];
	if(pt->a[k]<=cur->a[k])
	{
		query(cur->l,k+1);
		cd[k]=cur->a[k]-pt->a[k];
		query(cur->r,k+1);
	}
	else
	{
		query(cur->r,k+1);
		cd[k]=pt->a[k]-cur->a[k];
		query(cur->l,k+1);
	}
	cd[k]=tmp;
}

inline void rit(int *n)
{
	char c;
	while(!isdigit(c=getchar_unlocked()));
	*n=c-'0';
	while(isdigit(c=getchar_unlocked()))
		*n=*n*10+c-'0';
}

int main()
{
	int q,c,x,y;
	rit(&q);
	ans=0;
	nil=&mem[0];
	nil->l=nil->r=nil;
	t=1;
	Node* root[2]={nil,nil};
	q<<=1;
	int i;
	for(i=0;i<q;i++)
	{
		rit(&x);
		rit(&y);
		if(root[~i&1]!=nil)
		{
			pt=&mem[t];
			pt->a[0]=x;
			pt->a[1]=y;
			ans=2e9;
			query(root[~i&1],0);
			printf("%d\n",ans);
		}
		pt=&mem[t++];
		pt->a[0]=x;
		pt->a[1]=y;
		pt->l=pt->r=nil;
		root[i&1]=insert(root[i&1],0);
	}
	return 0;
}
