#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH_OF_COMMAND 16

struct Node
{
	char character;
	int count , left_count , right_count;
	struct Node *left_child , *right_child;
};

typedef struct Node Node;

Node *new_node(char character , int count , int left_count , int right_count , Node *left_child , Node *right_child)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->character = character;
	node->count = count;
	node->left_count = left_count;
	node->right_count = right_count;
	node->left_child = left_child;
	node->right_child = right_child;
	return node;
}

Node *insert_left(Node *root , char character , int count)
{
	if (!root)
	{
		Node *node = new_node(character , count , 0 , 0 , 0 , 0);
		return node;
	}

	if (!root->left_child && root->character == character)
	{
		root->count += count;
		return root;
	}

	root->left_count += count;
	root->left_child = insert_left(root->left_child , character , count);
	return root;
}

Node *insert_right(Node *root , char character , int count)
{
	if (!root)
	{
		Node *node = new_node(character , count , 0 , 0 , 0 , 0);
		return node;
	}

	if (!root->right_child && root->character == character)
	{
		root->count += count;
		return root;
	}

	root->right_count += count;
	root->right_child = insert_right(root->right_child , character , count);
	return root;
}

Node *insert_middle(Node *root , char character , int count , int position)
{
	if (!root)
	{
		Node *node = new_node(character , count , 0 , 0 , 0 , 0);
		return node;
	}

	if (position <= root->left_count)
	{
		root->left_count += count;

		if (position == 1)
			root->left_child = insert_left(root->left_child , character , count);
		else
			root->left_child = insert_middle(root->left_child , character , count , position);
	}
	else if (position >= root->left_count + root->count + 2)
	{
		root->right_count += count;

		if (position == root->left_count + root->count + root->right_count + 1)
			root->right_child = insert_right(root->right_child , character , count);
		else
			root->right_child = insert_middle(root->right_child , character , count , position - root->left_count - root->count);
	}
	else
	{
		if (root->character == character)
			root->count += count;
		else
		{
			if (position == root->left_count + 1)
			{
				root->left_count += count;
				root->left_child = insert_right(root->left_child , character , count);
			}
			else if (position == root->left_count + root->count + 1)
			{
				root->right_count += count;
				root->right_child = insert_left(root->right_child , character , count);
			}
			else
			{
				Node *left_node = new_node(root->character , position - root->left_count - 1 , root->left_count , 0 , root->left_child , 0);
				Node *right_node = new_node(root->character , root->left_count + root->count - position + 1 , 0 , root->right_count , 0 , root->right_child);
				root->character = character;
				root->count = count;
				root->left_count = left_node->count + left_node->left_count;
				root->right_count = right_node->count + right_node->right_count;
				root->left_child = left_node;
				root->right_child = right_node;
			}
		}
	}

	return root;
}

void print_tree(Node *root)
{
	if (!root)
		return;

	print_tree(root->left_child);
	printf("%c %d " , root->character , root->count);
	print_tree(root->right_child);
	return;
}

int main(int argc , char **argv)
{
	Node *root = 0;
	char command[MAX_LENGTH_OF_COMMAND] = {0};
	char character[2] = {0};
	int count;

	while (scanf("%s" , command) != EOF)
	{
		if (strcmp(command , "print") == 0)
		{
			print_tree(root);
			printf("$\n");
		}
		else
		{
			scanf("%s%s%d" , command , character , &count);

			if (strcmp(command , "left") == 0)
				root = insert_left(root , character[0] , count);
			else if (strcmp(command , "right") == 0)
				root = insert_right(root , character[0] , count);
			else
				root = insert_middle(root , character[0] , count , atoi(command));
		}
	}

	return 0;
}
