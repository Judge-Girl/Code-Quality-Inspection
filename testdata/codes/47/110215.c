#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	char c;int n,n_l,n_r;struct Node *left;struct Node *right;
}Node;
Node *insert(Node *node,char C,int NUM,int k){
	if(node==NULL){
		node=(Node *)malloc(sizeof(Node));
		node->c=C; node->n=NUM; node->n_l = node->n_r = 0; node->left = node->right = NULL;
		return node;
	}else{
		int temp=(k-node->n_l);
		if(temp<1){
			node->left = insert(node->left,C,NUM,k);
			node->n_l += NUM;
			return node;
		}else{
			if(temp==1){
				if(C==node->c){
					node->n += NUM;
					return node;
				}else{
					node->left = insert(node->left,C,NUM,k);
					node->n_l += NUM;
					return node;
				}
			}else{
				temp -= node->n;
				if(temp>1){
					node->right = insert(node->right,C,NUM,temp);
					node->n_r += NUM;
					return node;
				}else{
					if(temp==1){
						if(C==node->c){
							node->n += NUM;
							return node;
						}else{
							node->right = insert(node->right,C,NUM,temp);
							node->n_r += NUM;
							return node;
						}
					}else{
						if(C==node->c){
							node->n += NUM;
							return node;
						}else{
							temp=(1-temp);
							int t=(node->n - temp);
							Node *p = (Node *)malloc(sizeof(Node));
							p->n_l = (t + node->n_l);
							p->n_r = (temp + node->n_r);
							p->n = NUM; p->c = C;
							p->left = (Node *)malloc(sizeof(Node));
							p->right = (Node *)malloc(sizeof(Node));
							p->left->c = p->right->c = node->c;
							p->left->n = t; p->right->n = temp;
							p->left->n_l = node->n_l;
							p->right->n_r = node->n_r;
							p->left->left = node->left;
							p->right->right = node->right;
							free(node);
							return p;
						}
					}
				}
			}
		}
	}
}
Node *insert_r(Node *node,char C,int NUM){
	if(node==NULL){
		node = (Node *)malloc(sizeof(Node));
		node->c = C; node->n = NUM; node->n_l = node->n_r = 0;
		node->left = node->right = NULL;
	}else{
		Node *p=node;
		while(p->right!=NULL){
			p=p->right;
		}
		if(p->c == C){
			p->n += NUM;
		}else{
			p->right = (Node *)malloc(sizeof(Node));
			p->right->c = C; p->right->n = NUM; p->right->n_l = p->right->n_r = 0;
			p->right->left = p->right->right = NULL;
		}
	}
	return node;
}
void print(Node *node){
	if(node!=NULL){
		print(node->left);
		printf("%c %d ",node->c,node->n);
		print(node->right);
	}
}
int main(void) {
	char temp[12];int k,i; Node *p;
	while(scanf("%s",temp)!=EOF){
		switch(temp[0]){
			case 'p':
				print(p);
				printf("$\n");
				break;
			case 'i':
				scanf("%s",temp);
				switch(temp[0]){
					case 'l':
						scanf("%s",temp);
						scanf("%d",&i);
						p=insert(p,temp[0],i,1);
						break;
					case 'r':
						scanf("%s",temp);
						scanf("%d",&i);
						p=insert_r(p,temp[0],i);
						break;
					default:
						k=i=0;
						while(temp[i]!='\0'){
							k = k*10+(temp[i]-'0');
							i++;
						}
						scanf("%s",temp);
						scanf("%d",&i);
						p=insert(p,temp[0],i,k);
				}
				break;
		}
	}
	// your code goes here
	return 0;
}

