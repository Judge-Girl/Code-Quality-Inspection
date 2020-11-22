#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int max(int a, int b){ return (a>b)?a:b; }

typedef struct Treap Treap;
struct Treap
{
	int size;
	int cnt;
	char c;
	char cL,cR;
	Treap *L,*R;
};
// initializer
Treap* TREAP(char _c, int _cnt)
{
	Treap *T = malloc(sizeof(Treap));
	(*T) = (Treap){
		_cnt,_cnt,
		_c,_c,_c,
		NULL,NULL
	};
	return T;
}

void Delete(Treap**T)
{
	free(*T);
	*T = NULL;
}

int Size(Treap *T)
{
	if(T==NULL)
		return 0;
	return T->size;
}
void Up(Treap *T)
{
	if(T==NULL)
		return;
	T->size = Size(T->L)+Size(T->R) + T->cnt;
	T->cL = (T->L)?(T->L->cL):(T->c);
	T->cR = (T->R)?(T->R->cR):(T->c);
}


Treap* merge(Treap *A, Treap *B)
{
	if(A==NULL)
		return B;
	if(B==NULL)
		return A;
	
	// Merge Node
	if(A->R==NULL && B->L==NULL && A->c==B->c)
	{
		A->cnt += B->cnt;
		A->R = B->R;
		Up(A);
		free(B);
		return A;
	}
	if(A->cR == B->cL && !(A->R && B->L))
	{
		if(A->R)
		{
			A->R = merge(A->R,B);
			Up(A);
			return A;
		}
		else
		{
			B->L = merge(A,B->L);
			Up(B);
			return B;
		}
	}
	
	if(rand()%(Size(A)+Size(B)) <= Size(A))
	{
		A->R = merge(A->R,B);
		Up(A);
		return A;
	}
	else
	{
		B->L = merge(A,B->L);
		Up(B);
		return B;
	}
}


void Split(Treap *T, Treap** A, Treap** B, int k)
{
	if(T==NULL)
	{
		*A = *B = NULL;
		return;
	}
	
//	printf("spliting: (%c,%d), k=%d\n", T->c, T->cnt, k);
	
	if( k <= Size(T->L) )	// L
	{
//		puts(" split left");
		*B = T;
		Split(T->L, A,&((*B)->L), k);
		Up(*B);
	}
	else if( k >= Size(T->L)+(T->cnt) )	// R
	{
//		puts(" split right");
		*A = T;
		Split(T->R, &((*A)->R),B, k - (Size(T->L)+(T->cnt)) );
		Up(*A);
	}
	else	// Split Node
	{
//		puts(" split this");
		k -= Size(T->L);
		(*A) = T;
		(*B) = malloc(sizeof(Treap));
		*(*B) = *(*A);
		(*A)->cnt = k;
		(*B)->cnt -= k;
		(*A)->R = NULL;
		(*B)->L = NULL;
		Up(*A);
		Up(*B);
	}
}



void Print(Treap *T)
{
	if(T==NULL)
		return;
	if(T->L)
		Print(T->L);
	
	printf("%c %d ", T->c, T->cnt);
	
	if(T->R)
		Print(T->R);
}

int main()
{
	char cmd[20],pos[20],ch[20];
	int k,cnt;
	Treap *T=NULL, *A=NULL, *B=NULL;
	while(scanf("%s",cmd) != EOF)
	{
		if(cmd[0] == 'i')	// insert
		{
			scanf("%s",pos);
			if(pos[0]=='l')
			{
				scanf("%s%d",ch,&cnt);
				T = merge(TREAP(ch[0],cnt),T);
			}
			else if(pos[0]=='r')
			{
				scanf("%s%d",ch,&cnt);
				T = merge(T,TREAP(ch[0],cnt));
			}
			else
			{
				sscanf(pos, "%d", &k);
				scanf("%s%d",ch,&cnt);
				Split(T,&A,&B,k-1);
				T = merge( A,
					merge( TREAP(ch[0],cnt), B) );
			}
		}
		else	// print
		{
			Print(T);
			printf("$\n"); 
		}
		
			/*
		Print(T);
		puts("");
		//	*/
	}
	
	
	
	return 0;
}

