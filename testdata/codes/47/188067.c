#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#define maxl (1<<3)
#define mmaxl (1<<7)

typedef struct treenode{
    char x;
    int n, size;
    struct treenode *left;
    struct treenode *right;
} Node;

Node* newNode(char x, int n, int size)
{
    Node *new;
    new = (Node*) malloc(sizeof(Node));
    assert(new != NULL);
    new->left = NULL;
    new->right = NULL;
    new->x = x;
    new->n = n;
    new->size = size;
    return new;
}


Node* insert_left(Node *current, char x, int n) {
    if(current == NULL)
        return newNode(x, n, n);
    current->size += n;
    if(current->left == NULL){
        if(x == current->x)
            current->n += n;
        else{
            current->left = newNode(x, n, n);
        }
    }
    else{
        current->left = insert_left(current->left, x, n);
    }
    return current;
}

Node* insert_right(Node *current, char x, int n)
{
    if(current == NULL)
        return newNode(x, n, n);
    current->size += n;
    if(current->right == NULL){
        if(x == current->x)
            current->n += n;
        else
            current->right = newNode(x, n, n);
    }
    else
        current->right = insert_right(current->right, x, n);
    return current;
}

Node* insert(Node *current, int pos, char x, int n)
{
    if(current == NULL)
        return newNode(x, n, n);
    //insert left
    current->size += n;
    int left_size = 0;
    if(current->left != NULL)
        left_size = current->left->size;
    if(pos < left_size){
        current->left = insert(current->left, pos, x, n);
    }
    else if(pos > left_size + current->n){
        current->right = insert(current->right, pos - (left_size + current->n), x, n);
    }
    else
    {
        if(x == current->x) {
            current->n += n;
        }
        else if(pos == left_size){
            current->left = insert_right(current->left, x, n);
        }
        else if(pos == left_size + current->n){
            current->right = insert_left(current->right, x, n);
        }
        else {
            current->left = insert_right(current->left, current->x, pos - left_size);
            current->right = insert_left(current->right, current->x, left_size + current->n - pos);
            current->x = x;
            current->n = n;
        }
    }
    return current;
}

void print(Node *current)
{
    if(current == NULL)
        return;
    print(current->left);
    printf("%c %d ", current->x, current->n);
    print(current->right);
}

int main()
{
    Node* root = NULL;
    int n;
    char x, cmd[maxl], pos[mmaxl];
    while(scanf("%s ", cmd) != EOF)
    {
        if(cmd[0] == 'i')
        {
            scanf("%s %c %d", pos, &x, &n);
            if(isdigit(pos[0])){
                int k;
                sscanf(pos, "%d", &k);
                root = insert(root, k-1, x, n);
            }
            else if(pos[0] == 'l')
                root = insert_left(root, x, n);
            else if(pos[0] == 'r')
                root = insert_right(root, x, n);
        }
        else
        {
            print(root);
            puts("$");
        }
    }
    return 0;
}

