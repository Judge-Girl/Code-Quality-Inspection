#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
	struct tree *left;
	struct tree *right;
	int llen;
	int rlen;
	char c;
	int len;
}tree;
void print(tree *root){
	if(root == NULL)
		return;
	print(root->left);
	printf("%c %d ",root->c,root->len);
	print(root->right);
}
tree *insert_left(tree* root, char x, int n){
	if(root == NULL){
		tree *new = (tree*)malloc(sizeof(tree));
		new->left = new->right = NULL;
		new->llen = new->rlen = 0;
		new->c = x;
		new->len = n;
		return new;
	}
	else{
		if(root->left == NULL && x == root->c){
			root->len += n;
			return root;
		}
		else{
			root->left = insert_left(root->left,x,n);
			root->llen += n;
			return root;
		}
	}
}
tree *insert_right(tree *root, char x, int n){
	if(root == NULL){
		tree *new = (tree*)malloc(sizeof(tree));
		new->left = new->right = NULL;
		new->llen = new->rlen = 0;
		new->c = x;
		new->len = n;
		return new;
	}
	else{
		if(root->right == NULL && x == root->c){
			root->len += n;
			return root;
		}
		root->right = insert_right(root->right,x,n);
		root->rlen += n;
		return root;
	}
}
tree *insert(tree *root, int k, char x, int n){
	if(root == NULL){
		tree *new = (tree*)malloc(sizeof(tree));
		new->left = new->right = NULL;
		new->llen = new->rlen = 0;
		new->c = x;
		new->len = n;
		return new;
	}
	if(x == root->c){
		if(root->llen + 1 <= k && root->llen + root->len + 1 >= k){
			root->len += n;
			return root;
		}
	}
	if(root->llen + 1 >= k){
		root->left = insert(root->left,k,x,n);
		root->llen += n;
		return root;
	}
	else if(root->llen + root->len + 1 <= k){
		root->right = insert(root->right, k - (root->llen + root->len),x,n);
		root->rlen += n;
		return root;
	}
	else if(k > root->llen + 1 && k < root->llen + root->len + 1){
		tree *leftn = (tree*)malloc(sizeof(tree));
		tree *rightn = (tree*)malloc(sizeof(tree));
		int lnum = k - root->llen - 1;
		int rnum = root->llen + root->len - k + 1;
		tree *new = (tree*)malloc(sizeof(tree));
		leftn->left = root->left;
		leftn->right = NULL;
		leftn->llen = root->llen;
		leftn->rlen = 0;
		leftn->c = rightn->c = root->c;
		leftn->len = lnum;
		rightn->left = NULL;
		rightn->right = root->right;
		rightn->llen = 0;
		rightn->rlen = root->rlen;
		rightn->len = rnum;
		new->left = leftn;
		new->right = rightn;
		new->llen = root->llen + lnum;
		new->rlen = root->rlen + rnum;
		new->c = x;
		new->len = n;
		return new;
	}
	return root;
}
int main(){
	tree *root = NULL;
	char todo[20];
	int flag = 1;
	while(scanf("%s",todo) != EOF){
		if(todo[0] == 'p'){
			print(root);
			printf("$\n");
			continue;
		}
		else{
			char where[10],x;
			int n;
			scanf("%s %c %d",where,&x,&n);
			if(where[0] == 'l'){
				root = insert_left(root,x,n);
			}
			else if(where[0] == 'r'){
				root = insert_right(root,x,n);
			}
			else{
				int k = atoi(where);
				root = insert(root,k,x,n);
			}
		}
	}
}

