#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct  node{
	char c[2];
	int c_size;
	int l_sub_num, r_sub_num;
	struct node *l, *r;
}Node;

void print(Node *n){
	if(n == NULL)return;
	print(n->l);
	printf("%c %d ", n->c[0], n->c_size);
	print(n->r);
}

Node *new_node(Node *n, char c[2], int c_size){
	Node *cur = malloc(sizeof(Node));
	cur->c[0] = c[0];
	cur->c[1] = c[1];
	cur->c_size = c_size;
	cur->l_sub_num = cur->r_sub_num = 0;
	cur->l = cur->r = NULL;
	return cur;
}

Node* update(Node *n){
	if(n->l != NULL){
		n->l_sub_num = n->l->l_sub_num + n->l->r_sub_num + n->l->c_size;
	}
	if(n->r != NULL){
		n->r_sub_num = n->r->l_sub_num + n->r->r_sub_num + n->r->c_size;
	}
	return n;
}
Node *insert(Node *n, int id, char c[2], int c_size){
	if(n == NULL){
		n = new_node(n, c, c_size);
		return n;
	}
	if((id >= n->l_sub_num && id <= n->l_sub_num + n->c_size) && c[0] == n->c[0]){
		n->c_size += c_size;
		return n;
	}
	else if(id <= n->l_sub_num){
		n->l = insert(n->l, id, c, c_size);
	}
	else if(id >= n->l_sub_num + n->c_size){
		n->r = insert(n->r, id - n->l_sub_num - n->c_size, c, c_size);
	}
	else{
		n->l = insert(n->l, n->l_sub_num, n->c, id - n->l_sub_num);
		n->r = insert(n->r, 0, n->c, n->l_sub_num + n->c_size - id);
		n->c[0] = c[0];
		n->c[1] = c[1];
		n->c_size = c_size;
	}
	n = update(n);
	return n;
}
int main(){
	char task[8], kth[12], c[2];
	int id, c_size, sum = 0;
	Node *root = NULL;
	while(scanf("%s", task) != EOF){
		if(strcmp(task, "print") == 0){
			print(root);
			printf("$\n");
		}
		else{
			scanf("%s%s%d", kth, c, &c_size);
			if(strcmp(kth, "left") == 0){
				id = 0;
			}
			else if(strcmp(kth, "right") == 0){
				id = sum;
			}
			else{
				id = atoi(kth) - 1;
			}
			sum += c_size;
			root = insert(root, id, c, c_size);
		}
	}
	return 0;
}
