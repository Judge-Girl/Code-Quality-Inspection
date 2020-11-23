#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
typedef struct node
{
    int number, lcount, rcount;
    char element;
    struct node *right, *left;
} node;
typedef struct tree
{
    node *root;
    int len;
} tree;
void ini_tree(tree *t)
{
    t->len = 0;
    t->root = NULL;
}
void in_order(node *n)
{
    if (n == NULL)
        return;
    in_order(n->left);
    printf("%c %d ", n->element, n->number);
    in_order(n->right);
    return;
}
node* get_node(char con, int num)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->number = num;
    temp->element = con;
    return temp;
}
node* insert_left(node *n, char con, int num)
{
    if (n == NULL) {
        node *temp = get_node(con, num);
        temp->rcount = num;
        temp->lcount = 0;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (n->left == NULL && n->element == con) {
        n->number += num;
        n->rcount += num;
        return n;
    }
    n->lcount += num;
    n->left = insert_left(n->left, con, num);
    return n;
}
node* insert_right(node * n, char con, int num)
{
    if (n == NULL) {
        node *temp = get_node(con, num);
        temp->rcount = num;
        temp->lcount = 0;
        temp->left = temp->right = NULL;
        return temp;
    }
    n->rcount += num;
    if (n->right == NULL && n->element == con) {
        n->number += num;
        return n;
    }
    n->right = insert_right(n->right, con, num);
    return n;
}
node* insert(node *n, int pos, char con, int num)
{
    if (n == NULL) {
        node *temp = get_node(con, num);
        temp->rcount = num;
        temp->left = temp->right = NULL;
        return temp;
    }
    int left_index = n->lcount + 1;
    int right_index = left_index + n->number;
    if (n->element == con) {
    	if (left_index <= pos && pos <= right_index) {
    		n->number += num;
    		n->rcount += num;
			return n;
		}
	}
    if (pos > left_index && pos < right_index) {
        /*if (n->element == con) {
            n->number += num;
            n->rcount += num;
            return n;
        }
        else {*/
            node *sp1 = get_node(n->element, pos - left_index);
            sp1->left = n->left;
            sp1->rcount = pos - left_index;
            sp1->lcount = n->lcount;
            node *sp2 = get_node(n->element, left_index + n->number - pos);
            sp2->right = n->right;
            sp2->rcount = n->rcount - (pos - left_index);
            sp2->lcount = 0;
            sp2->left = sp1->right = NULL;
            n->element = con;
            n->number = num;
            n->rcount = num + sp2->rcount;
            n->lcount = sp1->lcount + sp1->number;
            n->left = sp1;
            n->right = sp2;
        //}
        return n;
    }
    if (pos <= left_index) {
        /*if (pos == left_index && n->element == con) {
            n->number += num;
            n->rcount += num;
        }*/
        //else {
            n->lcount += num;
            n->left = insert(n->left, pos, con, num);
        //}
    }
    else if (pos >= right_index) {
        /*if (pos == right_index && n->element == con) {
            n->number += num;
            n->rcount += num;
        }*/
        //else {
            n->rcount += num;
            n->right = insert(n->right, pos - right_index + 1, con, num);
        //}
    }
    return n;
}
int main(void) {
    tree t;
    ini_tree(&t);
    char command[10], place[10], con;
    int num;
    while (scanf("%s", command) != EOF) {
        if (!strcmp(command, "print")) {
            in_order(t.root);
            printf("$\n");
        }
        else if (!strcmp(command, "insert")) {
            scanf("%s%*c%c%d", place, &con, &num);
            if (!strcmp(place, "right")) {
                t.root = insert_right(t.root, con, num);
            }
            else if (!strcmp(place, "left")) {
                t.root = insert_left(t.root, con, num);
            }
            else {
                int pos = atoi(place);
                if (pos == 1)
                    t.root = insert_left(t.root, con, num);
                else if (pos == t.len + 1)
                    t.root = insert_right(t.root, con, num);
                else
                    insert(t.root, pos, con, num);
            }
            t.len += num;
        }
    }
    return 0;
}



