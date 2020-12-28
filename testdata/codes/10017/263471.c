#include <stdio.h>
#include <stdlib.h>
#define Abs(x) ((x) >= 0 ? (x) : -(x))
 
/* quadtree */
typedef struct node {
	int x;
	int y;
	struct node *northWest; /* include north and west */
	struct node *northEast;
	struct node *southWest;
	struct node *southEast;
} Node;

Node *insert(int x, int y, Node *root)
{
	if (root == NULL) {
		root = (Node *)malloc(sizeof(Node));
		root->x = x;
		root->y = y;
		root->northWest = NULL;
		root->northEast = NULL;
		root->southWest = NULL;
		root->southEast = NULL;
		return root;
	}

	if (x <= root->x && y >= root->y) {
		root->northWest = insert(x, y, root->northWest);
	} else if (x > root->x && y >= root->y) {
		root->northEast = insert(x, y, root->northEast);
	} else if (x <= root->x && y < root->y) {
		root->southWest = insert(x, y, root->southWest);
	} else if (x > root->x && y < root->y) {
		root->southEast = insert(x, y, root->southEast);
	} else {
		fputs("error", stderr);
		exit(EXIT_FAILURE);
	}

	return root;
}

int search(int x, int y, Node *root)
{
	if (root == NULL)
		return 100000;
	
	
	if (x <= root->x && y >= root->y) {
		int a = Abs(x - root->x) + Abs(y - root->y);
		int b = search(x, y, root->southWest);
		int c = search(x, y, root->northEast);
		int d = search(x, y, root->northWest);
		return (a <= b && a <= c && a <= d ? a :
				(b <= c && b <= d ? b : (c <= d ? c : d)));
	} else if (x > root->x && y >= root->y) {
		int a = Abs(x - root->x) + Abs(y - root->y);
		int b = search(x, y, root->southEast);
		int c = search(x, y, root->northWest);
		int d = search(x, y, root->northEast);
		return (a <= b && a <= c && a <= d ? a :
				(b <= c && b <= d ? b : (c <= d ? c : d)));
	} else if (x <= root->x && y < root->y) {
		int a = Abs(x - root->x) + Abs(y - root->y);
		int b = search(x, y, root->northWest);
		int c = search(x, y, root->southEast);
		int d = search(x, y, root->southWest);
		return (a <= b && a <= c && a <= d ? a :
				(b <= c && b <= d ? b : (c <= d ? c : d)));
	} else if (x > root->x && y < root->y) {
		int a = Abs(x - root->x) + Abs(y - root->y);
		int b = search(x, y, root->northEast);
		int c = search(x, y, root->southWest);
		int d = search(x, y, root->southEast);
		return (a <= b && a <= c && a <= d ? a :
				(b <= c && b <= d ? b : (c <= d ? c : d)));
	} else {
		fputs("error", stderr);
		exit(EXIT_FAILURE);
	}
}
/*
int search(int x, int y, Node *root)
{
	if (root == NULL)
		return 100000;
	
	
	if (x <= root->x && y >= root->y) {
		if (root->northWest == NULL) {
			int a = Abs(x - root->x) + Abs(y - root->y);
			int b = search(x, y, root->southWest);
			int c = search(x, y, root->northEast);
			return (a <= b && a <= c ? a : (b <= c ? b : c));
		}
		return search(x, y, root->northWest);
	} else if (x > root->x && y >= root->y) {
		if (root->northEast == NULL) {
			int a = Abs(x - root->x) + Abs(y - root->y);
			int b = search(x, y, root->southEast);
			int c = search(x, y, root->northWest);
			return (a <= b && a <= c ? a : (b <= c ? b : c));
		}
		return search(x, y, root->northEast);
	} else if (x <= root->x && y < root->y) {
		if (root->southWest == NULL) {
			int a = Abs(x - root->x) + Abs(y - root->y);
			int b = search(x, y, root->northWest);
			int c = search(x, y, root->southEast);
			return (a <= b && a <= c ? a : (b <= c ? b : c));
		}
		return search(x, y, root->southWest);
	} else if (x > root->x && y < root->y) {
		if (root->southEast == NULL) {
			int a = Abs(x - root->x) + Abs(y - root->y);
			int b = search(x, y, root->northEast);
			int c = search(x, y, root->southWest);
			return (a <= b && a <= c ? a : (b <= c ? b : c));
		}
		return search(x, y, root->southEast);
	} else {
		fputs("error", stderr);
		exit(EXIT_FAILURE);
	}
}
*/

int main(void)
{
	int n, x, y;
	Node *root1 = NULL;
	Node *root2 = NULL;
	
	scanf("%d", &n);
	scanf("%d%d", &x, &y);
	root1 = insert(x, y, root1);
	
	n *= 2;
	
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		if (i % 2) {
			printf("%d\n", search(x, y, root1));
			root2 = insert(x, y, root2);
		} else {
			printf("%d\n", search(x, y, root2));
			root1 = insert(x, y, root1);
		}
	}
	
	return 0;
}