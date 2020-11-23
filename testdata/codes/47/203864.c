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
void insert_left(tree *t, node *n, char con, int num)
{
    if (t->root == NULL) {
        node *temp = get_node(con, num);
        t->root = temp;
        temp->rcount = num;
        temp->lcount = 0;
        temp->left = temp->right = NULL;
    }
    else {
        node *ptr = n;
        while (ptr != NULL) {
            ptr->lcount += num;
            if (ptr->left == NULL) {
                if (ptr->element == con) {
                    ptr->number += num;
                    ptr->rcount += num;
                    ptr->lcount -= num;
                }
                else {
                    node *temp = get_node(con, num);
                    temp->lcount = 0;
                    temp->rcount = num;
                    temp->left = temp->right = NULL;
                    ptr->left = temp;
                }
                break;
            }
            ptr = ptr->left;
        }
    }
    return;
}
void insert_right(tree *t, node * n, char con, int num)
{
    if (t->root == NULL) {
        node *temp = get_node(con, num);
        temp->rcount = num;
        temp->lcount = 0;
        temp->left = temp->right = NULL;
        t->root = temp;
    }
    else {
        node *ptr = n;
        while (ptr != NULL) {
            ptr->rcount += num;
            if (ptr->right == NULL) {
                if (ptr->element == con) {
                    ptr->number += num;
                }
                else {
                    node *temp = get_node(con, num);
                    temp->lcount = 0;
                    temp->rcount = num;
                    temp->left = temp->right = NULL;
                    ptr->right = temp;
                }
                break;
            }
            ptr = ptr->right;
        }
    }
    return;
}
void insert(tree *t, int pos, char con, int num)
{
    node *ptr = t->root;
    int index = ptr->lcount + 1, flag = 1;
    while (flag) {
        if (pos > index + ptr->number) {
            ptr->rcount += num;
            index += (ptr->number + ptr->right->lcount);
            ptr = ptr->right;
        }
        else if (pos < index) {
            ptr->lcount += num;
            index -= ptr->left->rcount;
            ptr = ptr->left;
        }
        else if (pos == index + ptr->number) {
            if (ptr->element == con) {
                ptr->rcount += num;
                ptr->number += num;
            }
            else {
                if (ptr->right == NULL) {
                    ptr->rcount += num;
                    node *temp = get_node(con, num);
                    ptr->right = temp;
                    temp->rcount = num;
                    temp->lcount = 0;
                    temp->left = temp->right = NULL;
                }
                else {
                    ptr->rcount += num;
                    ptr = ptr->right;
                    insert_left(t, ptr, con, num);
                }
            }
            flag = 0;
        }
        else if (pos == index) {
            if (ptr->element == con) {
                ptr->rcount += num;
                ptr->number += num;
            }
            else {
                if (ptr->left == NULL) {
                    ptr->lcount += num;
                    node *temp = get_node(con, num);
                    ptr->left = temp;
                    temp->rcount = num;
                    temp->lcount = 0;
                    temp->left = temp->right = NULL;
                }
                else {
                    ptr->lcount += num;
                    ptr = ptr->left;
                    insert_right(t, ptr, con, num);
                }
            }
            flag = 0;
        }
        else if (pos > index && pos < index + ptr->number) {
            if (ptr->element == con) {
                ptr->rcount += num;
                ptr->number += num;
            }
            else {
                node *sp1 = get_node(ptr->element, pos - index);
                node *sp2 = get_node(ptr->element, ptr->number + index - pos);
                node *tempr = ptr->right;
                node *templ = ptr->left;
                ptr->element = con;
                ptr->number = num;
                sp1->lcount = ptr->lcount;
                sp1->rcount = pos - index;
                sp2->lcount = 0;
                sp2->rcount = ptr->rcount - (pos - index);
                ptr->rcount = sp2->rcount + num;
                sp1->right = sp2->left = NULL;
                sp1->left = templ;
                sp2->right = tempr;
                ptr->lcount += (pos - index);
                ptr->left = sp1;
                ptr->right = sp2;
            }
            flag = 0;
        }
    }
    return;
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
            t.len += num;
            if (!strcmp(place, "right")) {
                insert_right(&t, t.root, con, num);
            }
            else if (!strcmp(place, "left")) {
                insert_left(&t, t.root, con, num);
            }
            else {
                int pos = atoi(place);
                if (pos == 1)
                    insert_left(&t, t.root, con, num);
                else if (pos == t.len + 1)
                    insert_right(&t, t.root, con, num);
                else
                    insert(&t, pos, con, num);
            }
        }
    }
    return 0;
}
