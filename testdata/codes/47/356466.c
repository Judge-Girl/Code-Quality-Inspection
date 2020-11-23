#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int num_print = 0;
char ch_print;
typedef struct node{
	int num;
	int num_left;
	int num_right;
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

NODE *insert_node(NODE *node, int num_, char ch_){            
	node = (NODE *)malloc(sizeof(NODE));
	node->num = num_;
	node->ch = ch_;
	node->parent = node;
	node->left = NULL;
	node->right = NULL;
	node->num_left = 0;
	node->num_right = 0;
	return node;
}
NODE *l(NODE *root, int num_, char ch_){
	if(root == NULL){
        root = insert_node(root, num_, ch_);
	}
	else{
		root->num_left += num_;
		root->left = l(root->left, num_, ch_);
	}
	return root;
}

NODE *r(NODE *root, int num_, char ch_){
	if(root == NULL){
		root = insert_node(root, num_, ch_);
	}
	else{
		root->num_right += num_;
		root->right = r(root->right, num_, ch_);
	}
	return root;
}
void insert(NODE *root, int th, int word_len, int num_, char ch_){
	if(th == word_len + 1){
		while(root->right != NULL){
			root->num_right += num_;
			root = root->right;
		}
		root->num_right = num_;
		root->right = insert_node(root->right, num_, ch_);
		return;
	}
	if(th <= root->num_left){
		root->num_left += num_;
		insert(root->left, th, word_len, num_, ch_);
	}
	else if(th > root->num_left + root->num){
		root->num_right += num_;
		insert(root->right, th - root->num_left - root->num, word_len, num_, ch_);
	}
	else{
		th -= root->num_left;
		if(th == 1){
			root->num_left += num_;
			root->left = r(root->left, num_, ch_);
		}
		else{
			NODE *leaf = root;
			leaf->num_left += th - 1;
			leaf->left = r(leaf->left, th - 1, root->ch);
			leaf = root;
			leaf->num_right += root->num - th + 1;
			leaf->right = l(leaf->right, root->num - th + 1, root->ch);
			root->ch = ch_;
			root->num = num_;		
		}
	}
	return ;
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
						leaf->num_left += atoi(cmd[3]);
						leaf = leaf->left;
					}
					leaf->num_left = atoi(cmd[3]);
					leaf->left = insert_node(leaf->left, atoi(cmd[3]), cmd[2][0]);
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
						leaf->num_right += atoi(cmd[3]);
						leaf = leaf->right;
					}
					leaf->num_right = atoi(cmd[3]);
					leaf->right = insert_node(leaf->right, atoi(cmd[3]), cmd[2][0]);
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

