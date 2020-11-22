#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
typedef struct treenode {
	char data;
	int num;
	int Lnode, Rnode, height;
	struct treenode *left, *right;
} Treenode;
int max(int a, int b) {
	return (a > b)? a: b;
}
int get_height(Treenode *root) {
	return (root)? root->height: -1;
}
Treenode *new_node(char c, int n) {
	Treenode *node = (Treenode *)malloc(sizeof(Treenode));
	assert(node);
	node->data = c;
	node->num = n;
	node->Lnode = node->Rnode = node->height = 0;
	node->left = node->right = NULL;
	return node;
}
Treenode *right_rotate(Treenode *root) {
	Treenode *temp = root->right;
	root->Rnode = temp->Lnode;
	temp->Lnode = root->Lnode + root->Rnode + root->num;
	root->right = temp->left;
	temp->left = root;
	root->height = max(get_height(root->left), get_height(root->right)) + 1;
	temp->height = max(root->height, get_height(temp->right)) + 1;
	return temp;
}
Treenode *left_rotate(Treenode *root) {
	Treenode *temp = root->left;
	root->Lnode = temp->Rnode;
	temp->Rnode = root->Lnode + root->Rnode + root->num;
	root->left = temp->right;
	temp->right = root;
	root->height = max(get_height(root->left), get_height(root->right)) + 1;
	temp->height = max(get_height(temp->left), root->height) + 1;
	return temp;
}
Treenode *insert_left(Treenode *root, char c, int n) {
	if (!root) return new_node(c, n);
	if (!root->left && root->data == c) {
		root->num += n;
		return root;
	}
	root->left = insert_left(root->left, c, n);
	root->Lnode += n;
	if (get_height(root->left) > get_height(root->right) + 1)
		root = left_rotate(root);
	root->height = max(get_height(root->left), get_height(root->right)) + 1;
	return root;
}
Treenode *insert_right(Treenode *root, char c, int n) {
	if (!root) return new_node(c, n);
	if (!root->right && root->data == c) {
		root->num += n;
		return root;
	}
	root->right = insert_right(root->right, c, n);
	root->Rnode += n;
	if (get_height(root->right) > get_height(root->left) + 1)
		root = right_rotate(root);
	root->height = max(get_height(root->left), get_height(root->right)) + 1;
	return root;
}
Treenode *insert(Treenode *root, int pos, char c, int n, int len, int pass) {
	int Lbound = root->Lnode + pass;
	int Rbound = Lbound + root->num;
	if (c == root->data && pos >= Lbound && pos <= Rbound)
		root->num += n;
	else if (pos <= Lbound) {
		if (pos == Lbound) root->left = insert_right(root->left, c, n);
		else root->left = insert(root->left, pos, c, n, len, pass);
		root->Lnode += n;
		if (get_height(root->left) > get_height(root->right) + 1) {
			int Lchild_bound = root->left->Lnode + pass;
			int Rchild_bound = Lchild_bound + root->left->num;
			if (pos < Lchild_bound)
				root = left_rotate(root);
			else if (pos > Rchild_bound) {
				root->left = right_rotate(root->left);
				root = left_rotate(root);
			}
		}
		root->height = max(get_height(root->left), get_height(root->right)) + 1;
	}
	else if (pos >= Rbound) {
		if (pos == Rbound) root->right = insert_left(root->right, c, n);
		else root->right = insert(root->right, pos, c, n, len, root->num + root->Lnode + pass);
		root->Rnode += n;
		if (get_height(root->right) > get_height(root->left) + 1) {
			int Lchild_bound = root->Lnode + root->num + root->right->Lnode + pass;
			int Rchild_bound = Lchild_bound + root->right->num;
			if (pos > Rchild_bound)
				root = right_rotate(root);
			else if (pos < Lchild_bound) {
				root->right = left_rotate(root->right);
				root = right_rotate(root);
			}
		}
		root->height = max(get_height(root->left), get_height(root->right)) + 1;
	}
	else {
		root->left = insert_right(root->left, root->data, pos - Lbound);
		root->right = insert_left(root->right, root->data, Rbound - pos);
		root->Lnode += pos - Lbound;
		root->Rnode += Rbound - pos;
		root->data = c;
		root->num = n;
		root->height = max(get_height(root->left), get_height(root->right)) + 1;
	}
	return root;
}
void print(Treenode *root) {
	if (!root) return;
	print(root->left);
	printf("%c %d ", root->data, root->num);
	print(root->right);
}
int main() {
	char cmd[8], pos[12], c;
	int n, len = 0;
	Treenode *root = NULL;
	/* First time */
	while (scanf("%s", cmd) == 1 && !strcmp(cmd, "print")) {
		print(root);
		puts("$");
	}
	scanf("%s\n%c%d", pos, &c, &n);
	root = new_node(c, n);
	len += n;
	/* The rest */
	while (scanf("%s", cmd) == 1) {
		if (!strcmp(cmd, "print")) {
			print(root);
			puts("$");
		}
		else if (!strcmp(cmd, "insert")) {
			int posN;
			scanf("%s\n%c%d", pos, &c, &n);
			if (!strcmp(pos, "left")) posN = 1;
			else if (!strcmp(pos, "right")) posN = len + 1;
			else posN = atoi(pos);
			root = insert(root, posN - 1, c, n, len, 0);
			len += n;
		}
		else printf("invalid input\n");
	}
	return 0;
}

