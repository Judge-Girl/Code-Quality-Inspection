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

Node* insert(Node *head,Pos p,char c){
	if(!head){
		Node* ptr=malloc(sizeof(Node));
		ptr->left=NULL;
		ptr->right=NULL;
		ptr->p=p;
		ptr->c=c;
		return ptr;
	}
	if(p.v[head->c]>head->p.v[head->c])
		head->right=insert(head->right,p,head->c^1);
	else
		head->left=insert(head->left,p,head->c^1);
	return head;
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

int hasEOF = 0;
int readchar() {
    static int N = 1<<20;
    static char buf[1<<20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) {
            hasEOF = 1;
            return EOF;   
        }
        p = buf;
    }
    return *p++;
}
int ReadShort(short *x) {
    char c;
    while((c = readchar()) <= ' ')    {if(c == EOF) return 0;}
    *x = c - '0';
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    return 1;
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
		Dora=insert(Dora,p,0);
		if(i)	printf("%d\n",search(Sora,p,65535));
		ReadShort(&p.v[0]);
		ReadShort(&p.v[1]);
		Sora=insert(Sora,p,0);
		printf("%d\n",search(Dora,p,65535));
	}
	return 0;
}

