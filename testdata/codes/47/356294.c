#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int num_print = 0;
char ch_print;
typedef struct node{
	int num;
	int num_left;
	int num_right;
	int dir;    //1 left 2 right
	char ch;
	struct node *left;
	struct node *right;
	struct node *parent;
}NODE;

void inorder(NODE *node){
	if(node == NULL){
		return;
	}
	if(node->num == 0){
		return;
	}
	inorder(node->left);
	if(num_print == 0){
		num_print = node->num;
		ch_print = node->ch;
	}
	else{
		if(ch_print == node->ch){
			num_print += node->num;
		}
		else{
			printf("%c %d ", ch_print, num_print);
			ch_print = node->ch;
			num_print = node->num;
		}
	}
	//printf("%c %d ", node->ch, node->num);
	//printf("%d %d\n",node->num_left, node->num_right);
	//printf("%c %d %d\n", node->ch, node->num_left, node->num_right);
	inorder(node->right);
	return;
}

void insert_node(NODE *node, int diraction, int num_, char ch_){            //1 left, 2 right
	if(diraction == 1){
		node->left = (NODE *)malloc(sizeof(NODE));
		node->left->num = num_;
		node->left->ch = ch_;
		node->left->parent = node;
		node->left->left = NULL;
		node->left->right = NULL;
		node->left->num_left = 0;
		node->left->num_right = 0;
		node->left->dir = 1;
		node->num_left = num_;
		while(node->parent != NULL){
			if(node->dir == 1){
				node->parent->num_left += num_;
			}
			else if(node->dir == 2){
				node->parent->num_right += num_;
			}
			node = node->parent;
		}
	}
	else if(diraction == 2){
		node->right = (NODE *)malloc(sizeof(NODE));
		node->right->num = num_;
		node->right->ch = ch_;
		node->right->num_left = 0;
		node->right->num_right = 0;
		node->right->parent = node;
		node->right->dir = 2;
		node->right->left = NULL;
		node->right->right = NULL;
		node->num_right = num_;
		while(node->parent != NULL){
			if(node->dir == 1){
				node->parent->num_left += num_;
			}
			else if(node->dir == 2){
				node->parent->num_right += num_;
			}
			node = node->parent;
		}
	}
	return;
}

void insert(NODE *root, int th, int word_len, int num_, char ch_){
	if(th == word_len + 1){
		while(root->right != NULL){
			root = root->right;
		}
		insert_node(root, 2, num_, ch_);
		return;
	}
	if(th <= root->num_left){
		insert(root->left, th, word_len, num_, ch_);
	}
	else if(th > root->num_left + root->num){
		insert(root->right, th - root->num_left - root->num, word_len, num_, ch_);
	}
	else{
		th -= root->num_left;
		if(th == 1){
			if(root->left == NULL){
				insert_node(root, 1, num_, ch_);
			}
			else{
				root = root->left;
				while(root->right != NULL){
					root = root->right;
				}
				insert_node(root, 2, num_, ch_);
			}
		}
		else{
			NODE *leaf = root;
			if(root->left == NULL){
				insert_node(root, 1, th - 1, root->ch);
			}
			else{
				leaf = leaf->left;
				while(leaf->right != NULL){
					leaf = leaf->right;
				}
				insert_node(leaf, 2, th - 1, root->ch);
			}
			leaf = root;
			if(root->right == NULL){
				insert_node(root, 2, root->num - th + 1, root->ch);
			}
			else{
				leaf = leaf->right;
				while(leaf->left != NULL){
					leaf = leaf->left;
				}
				insert_node(leaf, 1, root->num - th + 1, root->ch);
			}
			leaf = root;
			while(leaf->parent != NULL){
				if(leaf->dir == 1){
					leaf->parent->num_left += (num_ - root->num);
				}
				else{
					leaf->parent->num_right += (num_ - root->num);
				}
				leaf = leaf->parent;
			}
			root->ch = ch_;
			root->num = num_;		
		}
	}
	return 0;
}


int main(){
	char cmd[4][20];
	int i, j, word_len = 0;
	NODE root;
	root.num_left = 0; root.num_right =0; root.num = 0; 
	root.left = NULL; root.right = NULL; root.parent = NULL;
	NODE *leaf;
	while(scanf(" %s", &cmd[0]) != EOF){
		if(strcmp(cmd[0], "print") == 0){
			inorder(&root);
			if(num_print != 0){
				printf("%c %d ", ch_print, num_print);
			}
			printf("$\n");
			num_print = 0;
		}
		else{
			for(i = 1; i <= 3; i++){
				scanf(" %s", cmd[i]);
			}
			if(strcmp(cmd[1], "left") == 0){
				if(root.num == 0){
					root.ch = cmd[2][0];
					root.num = atoi(cmd[3]);
				}
				else{
					leaf = &root;
					while(leaf->left != NULL){
						leaf = leaf->left;
					}
					insert_node(leaf, 1, atoi(cmd[3]), cmd[2][0]);
				}
				word_len += atoi(cmd[3]);
			}
			else if(strcmp(cmd[1], "right") == 0){
				if(root.num == 0){
					root.ch = cmd[2][0];
					root.num = atoi(cmd[3]);
				}
				else{
					leaf = &root;
					while(leaf->right != NULL){
						leaf = leaf->right;
					}
					insert_node(leaf, 2, atoi(cmd[3]), cmd[2][0]);
				}
				word_len += atoi(cmd[3]);
			}
			else{
				if(root.num == 0){
					root.ch = cmd[2][0];
					root.num = atoi(cmd[3]);
				}
				else{
					insert(&root, atoi(cmd[1]), word_len, atoi(cmd[3]), cmd[2][0]);
				}
				word_len += atoi(cmd[3]);
			}
		}
	}
	return 0;
} 

