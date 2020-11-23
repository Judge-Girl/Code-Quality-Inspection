// implementation of 2-dimension kd-tree data structure
#include <stdio.h>
#include <stdlib.h>
#define DIMENSION 2
#define MAXN 50000

typedef struct Node {
	int pos[DIMENSION], visited, dimension;
	struct Node *left, *right;
} Node;

Node *nil, *root[DIMENSION];

Node *KDInsert (Node *X, int dimension, int pos[]) {
	if (dimension == DIMENSION)
		dimension = 0;
	if (X == nil) {
		X = (Node *)malloc (sizeof (Node));
		for (int i = 0; i < DIMENSION; i++)
			X->pos[i] = pos[i];
		X->visited = 0;
		X->dimension = dimension; 
		X->left = nil;
		X->right = nil;
		return X;
	}
	if (pos[dimension] < X->pos[dimension])
		X->left = KDInsert (X->left, dimension + 1, pos);
	else
		X->right = KDInsert (X->right, dimension + 1, pos);
	return X;
}

int MD (int a[2], int b[2]) {	// Manhattan Distance
	return abs (a[0] - b[0]) + abs (a[1] - b[1]);
}

int NNMD (Node *root, int pos[]) {	// Nearest Neighbor's Manhattan Distance
	Node *stack[MAXN], *visit[MAXN], *current = root;
	int stackptr = 0, visptr = 0, min_md = 2147483647, cur_md, dimension;
	while (current != nil) {
		stack[stackptr++] = current;
		dimension = current->dimension;
		if (pos[dimension] < current->pos[dimension])
			current = current->left;
		else
			current = current->right;
	}
	while (stackptr != 0) {
		current = stack[--stackptr];
		dimension = current->dimension;
		visit[visptr++] = current;
		current->visited = 1;
		cur_md = MD (pos, current->pos);
//		printf ("pos (%d, %d), cur->pos (%d,%d), md:%d\n", pos[0], pos[1], current->pos[0], current->pos[1], cur_md);
		if (cur_md <= min_md)
			min_md = cur_md;
		if (abs (pos[dimension] - current->pos[dimension]) <= min_md) {
			if (current->left->visited == 0) {
				current = current->left;
				while (current != nil) {
					stack[stackptr++] = current;
					dimension = current->dimension;
					if (pos[dimension] < current->pos[dimension])
						current = current->left;
					else
						current = current->right;
				}
			}
			else if (current->right->visited == 0) {
				current = current->right;
				while (current != nil) {
					stack[stackptr++] = current;
					dimension = current->dimension;
					if (pos[dimension] < current->pos[dimension])
						current = current->left;
					else
						current = current->right;
				}
			}
		}
	}
	while (visptr != 0)
		visit[--visptr]->visited = 0;
	return min_md;
}

void traverse (Node *X) {
	if (X == nil)
		return;
	traverse (X->left);
	printf ("(%d,%d), d:%d,v:%d\n", X->pos[0], X->pos[1], X->dimension, X->visited);
	traverse (X->right);
	return;
}

int main () {
	nil = (Node *)malloc (sizeof (Node));
	nil->left = nil->right = nil;
	nil->visited = 1;	// for NNMD query
	for (int i = 0; i < DIMENSION; i++)
		root[i] = nil;
	int n, player, pos[2];
	scanf ("%d", &n);
	scanf ("%d%d", &pos[0], &pos[1]);
	root[0] = KDInsert (root[0], 0, pos);
/*	puts ("tree 0");
	traverse (root[0]);
	puts ("tree 1");
	traverse (root[1]);*/
	for (int i = 1; i < 2 * n; i++) {
		scanf ("%d%d", &pos[0], &pos[1]);
		root[i % 2] = KDInsert (root[i % 2], 0, pos);
		printf ("%d\n", NNMD (root[(i + 1) % 2], pos));
/*		puts ("tree 0");
		traverse (root[0]);
		puts ("tree 1");
		traverse (root[1]);*/
	}
	return 0;
}

