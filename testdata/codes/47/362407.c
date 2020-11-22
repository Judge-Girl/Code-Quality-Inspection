#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
	int lt, rt;
	char c;
	int num;
	struct node *left, *right;
}Node;

Node *gennode(int lt, int rt, char c, int num, Node *left, Node *right){
	Node *node = (Node *)malloc(sizeof(Node));
	node->lt = lt, node->rt = rt;
	node->c = c, node->num = num;
	node->left = left, node->right = right;
	return node;
}

void insertL(Node *root, char c, int num){
	Node *cur = root;
	while (cur->left != NULL){
		cur->lt += num;
		cur = cur->left;
	}
	if (cur->c == c) cur->num += num;
	else cur->lt = num, cur->left = gennode(0, 0, c, num, NULL, NULL);
	return;
}

void insertR(Node *root, char c, int num){
	Node *cur = root;
	while (cur->right != NULL){
		cur->rt += num;
		cur = cur->right;
	}
	if (cur->c == c) cur->num += num;
	else cur->rt = num, cur->right = gennode(0, 0, c, num, NULL, NULL);
	return;
}

void insertK(Node *root, char c, int num, int k){
	if (k < root->lt) insertK(root->left, c, num, k), root->lt += num;
	else if (k > root->lt + root->num) insertK(root->right, c, num, k - (root->num + root->lt)), root->rt += num;
	else if (k == root->lt){
		if (root->c == c) root->num += num;
		else if (root->left != NULL) insertK(root->left, c, num, k), root->lt += num;
		else root->left = gennode(0, 0, c, num, NULL, NULL), root->lt += num;
	}
	else if (k == root->lt + root->num){
		if (root->c == c) root->num += num;
		else if (root->right != NULL) insertK(root->right, c, num, k - (root->lt + root->num)), root->rt += num;
		else root->right = gennode(0, 0, c, num, NULL, NULL), root->rt += num;
	}
	else{
		if (root->c == c) root->num += num;
		else{
			Node *newleft = gennode(root->lt, 0, root->c, k - root->lt, root->left, NULL);
			Node *newright = gennode(0, root->rt, root->c, root->num - newleft->num, NULL, root->right);
			root->left = newleft, root->right = newright;
			root->c = c, root->num = num;
			root->lt = newleft->lt + newleft->num;
			root->rt = newright->rt + newright->num;
		}
	}
	return;
}

void print(Node *root){
	if (root == NULL) return;
	print(root->left);
	printf("%c %d ", root->c, root->num);
	print(root->right);
	return;
}

int main(){
	char cmd[4][20];
	Node *root;
	while (scanf("%s", cmd[0]) != EOF){
		if (strcmp(cmd[0], "print") == 0){
			printf("$\n");
			continue;
		}
		scanf("%s%s%s", cmd[1], cmd[2], cmd[3]);
		root = gennode(0, 0, cmd[2][0], atoi(cmd[3]), NULL, NULL);
		break;
	}
	while (scanf("%s", cmd[0]) != EOF){
		if (strcmp(cmd[0], "print") == 0){
			print(root);
			puts("$");
		}
		else{
			scanf("%s%s%s", cmd[1], cmd[2], cmd[3]);
			if (strcmp("left", cmd[1]) == 0) insertL(root, cmd[2][0], atoi(cmd[3]));
			else if (strcmp("right", cmd[1]) == 0) insertR(root, cmd[2][0], atoi(cmd[3]));
			else insertK(root, cmd[2][0], atoi(cmd[3]), atoi(cmd[1]) - 1);
		}
	}
}

















