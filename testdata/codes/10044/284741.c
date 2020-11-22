#pragma GCC optimize("O2")
#include<stdio.h>
#include<stdlib.h>

#define N 111

struct INT{
	unsigned long long h,l;
};

typedef struct INT Int;

inline void set(Int *x,int i,int v)
{
	if(i<64)
	{
		if(((x->l>>i)&1)!=v)
			x->l^=1ll<<i;
	}
	else
	{
		if(((x->h>>(i-64))&1)!=v)
			x->h^=1ll<<(i-64);
	}
}

inline int get(Int x,int i)
{
	return (i<64?(x.l>>i):(x.h>>(i-64)))&1;
}

inline void reset(Int *x)
{
	x->l=x->h=0;
}

inline int popcount(Int x)
{
	return __builtin_popcountll(x.h)+__builtin_popcountll(x.l);
}

inline int lowbit(Int x)
{
	if(x.l!=0)
		return __builtin_ctzll(x.l);
	else
		return 64+__builtin_ctzll(x.h);
}

inline Int neg(Int x)
{
	Int ret;
	ret.l=~x.l;
	ret.h=~x.h;
	return ret;
}

inline Int band(Int x,Int y)
{
	Int ret;
	ret.l=x.l&y.l;
	ret.h=x.h&y.h;
	return ret;
}

Int linkto[ N ] , v[ N ];
int n;
void init( int _n ){
  n = _n;
  int i;
  for( i = 0 ; i < n ; i ++ ){
  	reset(&linkto[i]);
  	reset(&v[i]);
  }
}
void addEdge( int a , int b ){
	set(&v[a],b,1);
	set(&v[b],a,1);
}

int ans , stk[ N ];
int id[ N ] , di[ N ] , deg[ N ];
Int cans;
void maxclique(int elem_num, Int candi){
  if(elem_num > ans){
    ans = elem_num;
    reset(&cans);
    int i;
    for( i = 0 ; i < elem_num ; i ++ )
    	set(&cans,id[stk[i]],1);
  }
  int potential = elem_num + popcount(candi);
  if(potential <= ans) return;
  int pivot = lowbit(candi);
  Int smaller_candi = band(candi , neg(linkto[pivot]));
  while(popcount(smaller_candi) && potential > ans){
    int next = lowbit(smaller_candi);
    set(&candi,next,!get(candi,next));
    set(&smaller_candi,next,!get(smaller_candi,next));
    potential --;
    if(next == pivot || popcount(band(smaller_candi , linkto[next])) ){
      stk[elem_num] = next;
      maxclique(elem_num + 1, band(candi , linkto[next]));
    }
  }
}
int cmp(const void *a,const void *b)
{
	int i=deg[*(int*)a],j=deg[*(int*)b];
	return (i>j)-(i<j);
}
int solve(){
	int i,j;
  for( i = 0 ; i < n ; i ++ ){
    id[ i ] = i;
    deg[ i ] = popcount(v[ i ]);
  }
  qsort(id,n,sizeof(int),cmp);
  for( i = 0 ; i < n ; i ++ )
    di[ id[ i ] ] = i;
  for( i = 0 ; i < n ; i ++ )
    for( j = 0 ; j < n ; j ++ )
      if( get(v[i],j) )
      	set(&linkto[di[i]],di[j],1);
  Int cand; reset(&cand);
  for( i = 0 ; i < n ; i ++ )
  	set(&cand,i,1);
  ans = 1;
  reset(&cans); set(&cans,0,1);
  maxclique(0, cand);
  return ans;
}

int main()
{
	int n,i,j,c;
	scanf("%d",&n);
	init(n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&c);
			if(c==1)
				addEdge(i,j);
		}
	}
	printf("%d\n",solve());
	return 0;
}
