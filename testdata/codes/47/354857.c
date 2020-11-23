#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define LEFT 0
#define RIGHT 1
#define K 2
 
typedef struct node{
    char c;
    int length;
    int n_left;
    int n_right;
    struct node *prev;
    struct node *left;
    struct node *right;
}Node;

char prev;
int length;
 
void printNode(Node *root, int index)
{
    if(root == NULL){
        return;
    }
    int cur_index = root->n_left + index + 1;
    printNode(root->left, index);
    #ifdef DEBUG
    printf("%c %d %d~%d %d %d\n", root->c, root->length, cur_index, cur_index+root->length-1, root->n_left, root->n_right);
    #endif
    #ifndef DEBUG
    if(prev == -1){
        prev = root->c;
        length += root->length;
    }
    else if(root->c != prev){
        printf("%c %d ", prev, length);
        prev = root->c;
        length = root->length;
    }
    else{
        prev = root->c;
        length += root->length;
    }
    #endif
    printNode(root->right, cur_index+root->length-1);
}
 
Node *newNode(char c, int length, Node *left, Node *right)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->c = c;
    node->length = length;
    node->left = left;
    node->right = right;
    if(left != NULL){
        node->n_left = left->n_left + left->length + left->n_right;
    }
    else{
        node->n_left = 0;
    }
    if(right != NULL){
        node->n_right = right->n_right + right->length + right->n_left;
    }
    else{
        node->n_right = 0;
    }
    return node;
}
int aaa = 0;

Node *build(int index, char c, int length, Node *node, Node *prev)
{
    int cur_index_low = node->n_left+1;
    int cur_index_up = node->n_left + node->length;
    /*
    if(c == 'K' && index == 127){
        printf("=============\n");
    }
    */
    if(index == cur_index_low){
        /*
        if(c == 'K'){
            printf("c %d %d %d\n", index, cur_index_up, cur_index_low);
            //printf("%c\n", node->left->c);
            node->n_left += length;
            node->left = build(index, c, length, node->left, node);
        }
        */
        if(node->c == c){
            node->length += length;
        }
        else{
            if(node->n_left < node->n_right){
                node->n_left += length;
                node->left = newNode(c, length, node->left, NULL);
            }
            else{
                Node *left = node->left;
                node->left = NULL;
                node->n_left = 0;
                return newNode(c, length, left, node);
            }
        }
    }
    else if(index == cur_index_up + 1){
        /*
        if(c == 'K'){
            printf("b %d %d %d\n", index, cur_index_up, cur_index_low);
            printf("%c\n", node->c);
        }
        */
        if(node->c == c){
            node->length += length;
        }
        else if(node->right == NULL){
            node->right = newNode(c, length, NULL, NULL);
            node->n_right += length;
        }
        else{
            node->n_right += length;
            node->right = build(index - node->length - node->n_left, c, length, node->right, node);
        }
    }
    else if(index > cur_index_low && index <= cur_index_up){
        /*
        if(c == 'K'){
            printf("c %d %d %d\n", index, cur_index_up, cur_index_low);
        }
        */
        if(node->c == c){
            node->length += length;
        }
        else{
            return newNode(c, length, newNode(node->c, index-cur_index_low, node->left, NULL), 
                                    newNode(node->c, cur_index_up-index+1, NULL, node->right));
        }
    }
    else if(index < cur_index_low){
        //go left
        /*
        if(c == 'K'){
            printf("d %d %d %d\n", index, cur_index_up, cur_index_low);
        }
        */
        node->n_left += length;
        node->left = build(index, c, length, node->left, node);
    }
    else if(index > cur_index_up){
        //go right
        /*
        if(c == 'K'){
            printf("e %d %d %d\n", index, cur_index_up, cur_index_low);
        }
        */
        node->n_right += length;
        node->right = build(index - node->length - node->n_left, c, length, node->right, node);
    }
    return node;
}

Node *insert(int type, int index, char c, int length, Node *root)
{
    aaa++;
    if(root == NULL){
        root = newNode(c, length, NULL, NULL);
    }
    else if(type == LEFT){
        return build(1, c, length, root, root);
    }
    else if(type == RIGHT){
        Node *node = root;
 
        while(node->right != NULL){
            node->n_right += length;
            node = node->right;
        }
        if(node->c == c){
            node->length += length;
        }
        else{
            node->n_right += length;
            node->right = newNode(c, length, NULL, NULL);
        }
    }
    else if(type == K){
        root = build(index, c, length, root, root);
    }
    return root;
}
 
int main()
{
    char s[10];
    int k, n;
    char x[2];
    Node *root = NULL;
    while(scanf("%s", s) != EOF){
        if(strcmp(s, "insert") == 0){
            if(scanf("%d%s%d", &k, x, &n)){
                root = insert(K, k, x[0], n, root);
            }
            else{
                scanf("%s%s%d", s, x, &n);
                if(strcmp(s, "left") == 0){
                    root = insert(LEFT, 0, x[0], n, root);
                }
                else if(strcmp(s, "right") == 0){
                    root = insert(RIGHT, 0, x[0], n, root);
                }
            }
        }
        else if(strcmp(s, "print") == 0){
            prev = -1;
            length = 0;
            printNode(root, 0);
            #ifndef DEBUG
            if(prev == -1)
                printf("$\n");
            else
                printf("%c %d $\n", prev, length);
            #endif
            //printf("========\n");
        }
    }
}
