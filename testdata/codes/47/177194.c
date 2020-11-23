#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
typedef struct node
{
    char c;
    int numC, left_numC, right_numC;
    struct node *left, *right;
} Node;
 
Node *newNode(char c, int numC)
{
    Node *new = (Node *) malloc(sizeof(Node));
    new->c = c;
    new->numC = numC;
    new->left_numC = new->right_numC = 0;
    new->left = new->right = NULL;
    return new;
}
 
char cur_c;
int count;
void print_BsTree(Node *root)
{
	if(root == NULL)
		return;
    print_BsTree(root->left);
    if(root->c == cur_c)
        count += root->numC;
    else
    {
        if(count > 0)
            printf("%c %d ", cur_c, count);
        cur_c = root->c;
        count = root->numC;
    }
    print_BsTree(root->right);
}

Node *travel_to_right_bottom(Node *root, char c, int numC)
{
	if(root == NULL)
	{
		Node *new = newNode(c, numC);
		return new;
	}
	else
	{
		root->right = travel_to_right_bottom(root->right, c, numC);
		root->right_numC += numC;
		return root;
	}
}
Node *travel_to_left_bottom(Node *root, char c, int numC)
{
	if(root == NULL)
	{
		Node *new = newNode(c, numC);
		return new;
	}
	else
	{
		root->left = travel_to_left_bottom(root->left, c, numC);
		root->left_numC += numC;
		return root;
	}
}
 
Node *insert_node(Node *root, int index, char c, int numC)
{
    if(root == NULL)
    {
        Node *new = newNode(c, numC);
        return new;
    }
	else if(index <= root->left_numC)
    {
        root->left = insert_node(root->left, index, c, numC);
        root->left_numC += numC;
        return root;
    }
    else if(index > root->left_numC + root->numC + 1)
    {
        root->right = insert_node(root->right, index - root->left_numC - root->numC, c, numC);
        root->right_numC += numC;
        return root;
    }
    else if(c == root->c)
    {
        root->numC += numC;
        return root;
    }
    else if(index == root->left_numC + 1)
    {
		root->left = travel_to_right_bottom(root->left, c, numC);
        root->left_numC += numC;
        return root;
    }
    else if(index <= root->left_numC + root->numC)
    {
		int split_part_numC = root->left_numC + root->numC - index + 1;
        Node *new = newNode(c, numC);
        new->left_numC = index-1;
        new->right_numC = root->right_numC + split_part_numC;
		new->left = travel_to_right_bottom(root->left, root->c, root->numC-split_part_numC);
        new->right = travel_to_left_bottom(root->right, root->c, split_part_numC);
        return new;
    }
    else
    {
		root->right = travel_to_left_bottom(root->right, c, numC);
        root->right_numC += numC;
        return root;
    }
}
 
int main(void)
{
    int length = 0;
    char command[15];
    Node *root = newNode('\0',0);
    while(scanf("%s", command) != EOF)
    {
        if(command[0] == 'i')
        {
            char c;
            int numC;
            scanf(" %s %c %d\n", command, &c, &numC);
            length += numC;
            if(length == numC)
            {
                root->c = c;
                root->numC = numC;
                continue;
            }
            if(isdigit(command[0]))
            {
                int index = atoi(command);
                root = insert_node(root, index, c, numC);
            }
            else if(command[0] == 'r')
                root = insert_node(root, length-numC+1, c, numC);
            else
                root = insert_node(root, 1, c, numC);
        }
        else
        {
            scanf("\n");
            cur_c = ' ';
            count = 0;
            print_BsTree(root);
            if(count == 0)
                printf("$\n");
            else
                printf("%c %d $\n", cur_c, count);
        }
    }
    return 0;
}

