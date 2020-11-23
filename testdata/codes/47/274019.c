#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
	char c;
	int length, sz;
	struct Node *left, *right;
} Node;
Node *BST_root = NULL;

void InsertLeft (char x, int n) {
	Node *current = BST_root;
	if (current == NULL) {
		BST_root = (Node *)malloc (sizeof (Node));
		BST_root->c = x;
		BST_root->length = n;
		BST_root->sz = n;
		BST_root->left = NULL;
		BST_root->right = NULL;
		return;
	}
	while (current->left != NULL) {
		current->sz += n;
		current = current->left;
	}
	current->sz += n;
	if (current->c == x)
		current->length += n;
	else {
		Node *new = (Node *)malloc (sizeof (Node));
		new->c = x;
		new->length = n;
		new->sz = n;
		new->left = NULL;
		new->right = NULL;
		current->left = new;
	}
	return;
}

void InsertRight (char x, int n) {
	Node *current = BST_root;
	if (current == NULL) {
		BST_root = (Node *)malloc (sizeof (Node));
		BST_root->c = x;
		BST_root->length = n;
		BST_root->sz = n;
		BST_root->left = NULL;
		BST_root->right = NULL;
		return;
	}
	while (current->right != NULL) {
		current->sz += n;
		current = current->right;
	}
	current->sz += n;
	if (current->c == x)
		current->length += n;
	else {
		Node *new = (Node *)malloc (sizeof (Node));
		new->c = x;
		new->length = n;
		new->sz = n;
		new->left = NULL;
		new->right = NULL;
		current->right = new;
	}
	return;
}

int SZ (Node *X) {
	if (X == NULL)
		return 0;
	else
		return X->sz;
}

int Length (Node *X) {
	if (X == NULL)
		return 0;
	else
		return X->length;
}

void InsertK (int k, char x, int n) {
	if (BST_root == NULL) {
		BST_root = (Node *)malloc (sizeof (Node));
		BST_root->c = x;
		BST_root->length = n;
		BST_root->sz = n;
		BST_root->left = NULL;
		BST_root->right = NULL;
		return;
	}
	int leftbound, rightbound;
	leftbound = SZ (BST_root->left) + 1;
	rightbound = leftbound + BST_root->length;
	Node *current = BST_root;
	while (!(k >= leftbound && k <= rightbound)) {
		current->sz += n;
		if (k < leftbound) {
			current = current->left;
			rightbound = leftbound - SZ (current->right);
			leftbound = rightbound - Length (current);
		}
		else {
			current = current->right;
			leftbound = rightbound + SZ (current->left);
			rightbound = leftbound + Length (current);
		}
	}
	current->sz += n;
	if (current->c == x)
		current->length += n;
	else if (k == leftbound) {
		if (current->left == NULL) {
			Node *new = (Node *)malloc (sizeof (Node));
			new->c = x;
			new->length = n;
			new->sz = n;
			new->left = NULL;
			new->right = NULL;
			current->left = new;
		}
		else {
			current = current->left;
			while (current->right != NULL) {
				current->sz += n;
				current = current->right;
			}
			current->sz += n;
			if (current->c == x)
				current->length += n;
			else {
				Node *new = (Node *)malloc (sizeof (Node));
				new->c = x;
				new->length = n;
				new->sz = n;
				new->left = NULL;
				new->right = NULL;
				current->right = new;
			}
		}
	}
	else if (k == rightbound) {
		if (current->right == NULL) {
			Node *new = (Node *)malloc (sizeof (Node));
			new->c = x;
			new->length = n;
			new->sz = n;
			new->left = NULL;
			new->right = NULL;
			current->right = new;
		}
		else {
			current = current->right;
			while (current->left != NULL) {
				current->sz += n;
				current = current->left;
			}
			current->sz += n;
			if (current->c == x)
				current->length += n;
			else {
				Node *new = (Node *)malloc (sizeof (Node));
				new->c = x;
				new->length = n;
				new->sz = n;
				new->left = NULL;
				new->right = NULL;
				current->left = new;
			}
		}
	}
	else {
		current->length = n;
		Node *newleft = (Node *)malloc (sizeof (Node));
		Node *newright = (Node *)malloc (sizeof (Node));
		newleft->left = current->left;
		newleft->right = NULL;
		newright->left = NULL;
		newright->right = current->right;
		current->left = newleft;
		current->right = newright;
		newleft->c = current->c;
		newright->c = current->c;
		newleft->length = k - leftbound;
		newleft->sz = SZ (newleft->left) + newleft->length;
		current->c = x;
		current->length = n;
		newright->length = rightbound - k;
		newright->sz = SZ (newright->right) + newright->length;
	}
	return;
}

void print (Node *root) {
	if (root == NULL)
		return;
	print (root->left);
	printf ("%c %d ", root->c, root->length);
	print (root->right);
	return;
}

void print2 (Node *root, int layer) {
	if (root == NULL)
		return;
	puts ("left");
	print2 (root->left, layer + 1);
	for (int i = 0; i < layer; i++)
		printf ("-");
	printf ("%c %d %d\n", root->c, root->length, root->sz);
	puts ("right");
	print2 (root->right, layer + 1);
	return;
}


int main () {
	char command[12] = "", x[2] = "";
	int n, k;
	while (scanf ("%s", command) != EOF) {
		if (command[0] == 'i') {
			scanf ("%s%s%d", command, x, &n);
			if (command[0] == 'l') {

				InsertLeft (x[0], n);
			}
			else if (command[0] == 'r') {
				InsertRight (x[0], n);
			}
			else {
				k = atoi (command);
				InsertK (k, x[0], n);
			}
		}
		else {
			print (BST_root);
			puts ("$");
		}
	}
	return 0;
}
