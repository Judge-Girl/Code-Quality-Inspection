#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include<string.h>
#include<limits.h>
#define max(x,y) (x)>(y)?(x):(y);
typedef struct anode {
	int length;
	char c;
	struct anode* right;
	struct anode* left;
	int left_len;
	int right_len;
	int height;
}Anode;
Anode* newnode(char c, int length) {
	Anode* re = (Anode*)calloc(1, sizeof(Anode));
	re->c = c;
	re->length = length;
	return re;
}
int height(Anode* n) {
	if (n == NULL) {
		return 0;
	}
	return n->height;
}
void update_length(Anode* root) {
	if (root->left != NULL) {
		root->left_len = root->left->left_len + root->left->right_len + root->left->length;
	}
	else {
		root->left_len = 0;
	}
	if (root->right != NULL) {
		root->right_len = root->right->left_len + root->right->right_len + root->right->length;
	}
	else {
		root->right = 0;
	}
}
int getflag(Anode* n) {
	if (n == NULL) {
		return 0;
	}
	return height(n->left) - height(n->right);
}
Anode* rightRotate(Anode* y)
{
	Anode* x = y->left;
	Anode* T2 = x->right;

	// Perform rotation  
	x->right = y;
	y->left = T2;

	// Update heights  
	y->height = max(height(y->left),
		height(y->right)) + 1;
	x->height = max(height(x->left),
		height(x->right)) + 1;
	update_length(y);
	update_length(x);
	
	// Return new root  
	return x;
}

// A utility function to left  
// rotate subtree rooted with x  
// See the diagram given above.  
Anode* leftRotate(Anode* x)
{
	Anode* y = x->right;
	Anode* T2 = y->left;

	// Perform rotation  
	y->left = x;
	x->right = T2;

	// Update heights  
	x->height = max(height(x->left),
		height(x->right)) + 1;
	y->height = max(height(y->left),
		height(y->right)) + 1;
	update_length(x);
	update_length(y);
	// Return new root  
	return y;
}
Anode* insert(Anode* root,int pos,char c, int length) {
	if (root == NULL) {
		return newnode(c, length);
	}
	else if (root->c == c && root->left_len < pos && root->length + root->left_len + 1 >= pos) {
		root->length += length;
		return root;
	}
	else if (pos <= 1 + root->left_len) {
		root->left = insert(root->left, pos, c, length);
	}
	else if(pos >= (root->left_len + root->length) + 1){
		root->right = insert(root->right, pos - (root->left_len + root->length), c, length);
	}
	else {
		//split
		int L_length = pos - root->left_len - 1;
		int R_length = root->length - L_length;
		int L_pos = root->left_len + 1;
		int R_pos = 1;
		char L_c = root->c, R_c = root->c;
		root->c = c;
		root->length = length;
		root->left = insert(root->left, L_pos, L_c, L_length);
		root->right = insert(root->right, R_pos, R_c, R_length);
	}
	update_length(root);
	root->height = 1 + max(height(root->left), height(root->right));
	int flag = getflag(root);
	// Left Left Case 
	if (flag > 1 && root->left->right == NULL) {
		return rightRotate(root);
	}
	// Right Right Case 
	if (flag < -1 && root->right->left == NULL) {
		return leftRotate(root);
	}
	// Left Right Case 
	if (flag > 1 && root->left->left == NULL){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	// Right Left Case 
	if (flag < -1 && root->right->right == NULL){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}
void print(Anode* p) {
	if (p == NULL)return;
	if (p->left != NULL) {
		print(p->left);
	}
	printf("%c %d ", p->c, p->length);
	if (p->right != NULL) {
		print(p->right);
	}
}
int main() {
	Anode* tree = NULL;
	char c[2];
	int length;
	int pos;
	char command[20] = {};
	char insertpos[20] = {};
	while (scanf("%s", command) != EOF) {
		if (strcmp(command, "print\0") == 0) {
			print(tree);
			printf("$\n");
		}
		else {
			scanf("%s %s %d", insertpos, c, &length);
			if (strcmp(insertpos, "left\0") == 0) {
				pos = 1;
			}
			else if (strcmp(insertpos, "right\0") == 0) {
				pos = 1;
				if (tree != NULL) {
					pos += tree->left_len;
					pos += tree->length;
					pos += tree->right_len;
				}
			}
			else {
				pos = atoi(insertpos);
			}
			tree = insert(tree, pos, c[0], length);
		}
	}
	return 0;
}
