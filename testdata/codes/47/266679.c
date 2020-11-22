#include <stdio.h>
#include <stdlib.h>
#define LEN 11

typedef struct node {
	char c;
	int len, front;
	struct node *left, *right;
}node;

node *create() {
	node *tmp = (node *) malloc(sizeof(node));
	tmp->c = '\0';
	tmp->len = 0;
	tmp->front = 0;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

void insert(node *root, int pos, char c, int len) {
	if (root->len == 0) { // init
		root->c = c;
		root->len = len;
	}
	else {
		node *current = root;
		while (1) {
			if (pos <= current->front) {
				if (current->left == NULL) {
					node *new_node = create();
					new_node->c = c;
					new_node->len = len;
					current->left = new_node;
					current->front += len;
					break;
				}
				current->front += len;
				current = current->left;
			}
			else if (pos > current->front + current->len + 1) {
				if (current->right == NULL) {
					node *new_node = create();
					new_node->c = c;
					new_node->len = len;
					current->right = new_node;
					break;
				}
				pos -= (current->front + current->len);
				current = current->right;
			}
			else if (pos == current->front + current->len + 1) {
				if (c == current->c) {
					current->len += len;
					break;
				}
				if (current->right == NULL) {
					node *new_node = create();
					new_node->c = c;
					new_node->len = len;
					current->right = new_node;
					break;
				}
				current = current->right;
				while (current->left != NULL) {
					current->front += len;
					current = current->left;
				}
				if (c == current->c)
					current->len += len;
				else {
					current->front += len;
					node *new_node = create();
					new_node->c = c;
					new_node->len = len;
					current->left = new_node;
				}
				break;
			}
			else if (pos == current->front + 1) {
				if (c == current->c) {
					current->len += len;
					break;
				}
				if (current->left == NULL) {
					node *new_node = create();
					new_node->c = c;
					new_node->len = len;
					current->left = new_node;
					current->front += len;
					break;
				}
				current->front += len;
				current = current->left;
				while (current->right != NULL)
					current = current->right;
				if (c == current->c)
					current->len += len;
				else {
					node *new_node = create();
					new_node->c = c;
					new_node->len = len;
					current->right = new_node;
				}
				break;
			}
			else {
				if (c == current->c) {
					current->len += len;
					break;
				}
				node *new_left = create();
				node *new_right = create();
				
				new_left->c = current->c;
				new_left->len = pos - current->front - 1;
				new_left->front = current->front;
				new_left->left = current->left;

				new_right->c = current->c;
				new_right->len = current->len - new_left->len;
				new_right->right = current->right;				

				current->c = c;
				current->len = len;
				current->front += new_left->len;
				current->left = new_left;
				current->right = new_right;
				// printf("左子樹: %c %d, 中間: %c %d, 右子樹: %c %d\n",current->left->c, current->left->len, current->c, current->len, current->right->c, current->right->len);
				break;
			}
		}
	}
}

void print(node *root) {
	if (root == NULL || root->len == 0)
		return;
	print(root->left);
	printf("%c %d ", root->c, root->len);
	print(root->right);
}

int main() {
	node *root = create();
	char input[LEN], pos[LEN], in_char;
	int int_pos, char_len, char_cnt = 0;

	while (scanf("%s", input) != EOF) {
		if (input[0] == 'p') {
			print(root);
			puts("$");
		}
		else {
			scanf("%s %c%d", pos, &in_char, &char_len); // need a space before %c, or it will eat a sapce!
			if (pos[0] == 'l')
				int_pos = 1;
			else if (pos[0] == 'r')
				int_pos = char_cnt + 1;
			else
				int_pos = atoi(pos);
			char_cnt += char_len;
			insert(root, int_pos, in_char, char_len);
		}
	}
	return 0;
}

