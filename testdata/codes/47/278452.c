#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
	int y; //自己加自己的子數 個數有幾個
	char x; //字母
	int n; //數量
	struct node *left;
	struct node *right;
}Node;
Node *Construct_Node(char x, int n)
{
	Node *new = (Node *)malloc(sizeof(Node));
	new->y = n;
	new->x = x;
	new->n = n;
	new->left = NULL;
	new->right = NULL;
	return new;
}
void PUT(Node *now, char x, int n, int type)
{
	if (now->x != x) { //NEW
		Node *new = Construct_Node(x, n);
		if (type == -1)
			now->left = new;
		else
			now->right = new;
	} else { //COMPRESS
		now->n += n;
	}
	now->y += n;
	return;
}
Node *FINDPOS(Node *root, int k, char x, int n)
{
	Node *now = root;
	if (k == -1) { //LEFT
		while (now->left != NULL) {
			now->y += n;
			now = now->left;
		}
		PUT(now, x, n, -1);
	} else if (k == 0) { //RIGHT
		while (now->right != NULL) {
			now->y += n;
			now = now->right;
		}
		PUT(now, x, n, 0);
	} else { //K
		int nowk = k;
		while (1) {
			int ly = 0;
			if (now->left)
				ly = (now->left)->y;
			if (x == now->x && (ly+1 == nowk || ly+now->n + 1 == nowk)) {
				now->y += n;
				now->n += n;
				break;
			} else if (nowk <= ly + 1) { //GO LEFT
				if (now->left) {
					now->y += n;
					now = now->left;
				} else {
					PUT(now, x, n, -1);
					break;
				}
			} else if (nowk > ly + (now->n)) { //GO RIGHT
				if (now->right) {
					nowk -= (ly + now->n);
					now->y += n;
					now = now->right;
				} else {
					PUT(now, x, n, 0);
					break;
				}
			} else { //NOW
				if (now->x != x) { //SPLIT
					Node *new1 = Construct_Node(now->x, nowk - ly - 1);
					Node *new2 = Construct_Node(now->x, now->n-nowk+ly+1);
					new1->left = now->left;
					new2->right = now->right;
					now->left = new1;
					now->right = new2;
					int ly1 = 0, ry2 = 0;
					if (new1->left)
						ly1 = new1->left->y;
					if (new2->right)
						ry2 = new2->right->y;
					new1->y = ly1 + new1->n;
					new2->y = ry2 + new2->n;
					now->y += n;
					now->x = x;
					now->n = n;		
					break;
				} else {
					now->y += n;
					now->n += n;
					break;
				}
			}
		}
	}
	return now;
}
void GO(Node *now)
{
	if (now == NULL)
		return;
	GO(now->left);
	putchar(now->x);
	putchar(' ');
	printf("%d", now->n);
	putchar(' ');
	GO(now->right);
	return;
}
void PRINT(Node *root)
{
	GO(root);
	printf("$\n");
	return;
}
int main()
{
	Node *root = NULL;
	char command[8];
	while (scanf("%s", command) != EOF) {
		char x[2];
		char string[16];
		int k, n;
		if (!strcmp(command, "insert")) { //insert
			scanf("%s", string);
			if (!strcmp(string, "left"))
				k = -1;
			else if (!strcmp(string, "right"))
				k = 0;
			else
				k = atoi(string);
			scanf("%s%d", x, &n);
			if (root)
				FINDPOS(root, k, x[0], n);
			else
				root = Construct_Node(x[0], n);
		} else { //print
			PRINT(root);
		}
	}
	return 0;
}

