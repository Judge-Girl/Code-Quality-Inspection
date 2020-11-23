#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char ch;
    int n;
    int nleft;
    int nright;
    struct list *list;
    struct node *left;
    struct node *right;
}Node;

void insertleft(Node *root, char ch, int n){
    Node *ptr = root;
    while(ptr->left != NULL) ptr->nleft += n, ptr = ptr->left;
    if(ch == ptr->ch){
        ptr->n += n;
        return  ;
    }
    ptr->nleft += n;
    Node *temp = ptr;
    ptr = malloc(sizeof(Node));
    ptr->ch = ch, ptr->n = n, ptr->nleft = 0, ptr->nright = 0;
    temp->left = ptr;
    ptr->left = NULL, ptr->right = NULL;
    return  ;
}

void insertright(Node *root, char ch, int n){
    Node *ptr = root;
    while(ptr->right != NULL) ptr->nright += n, ptr = ptr->right;
    if(ch == ptr->ch){
        ptr->n += n;
        return  ;
    }
    ptr->nright += n;
    Node *temp = ptr;
    ptr = malloc(sizeof(Node));
    ptr->ch = ch, ptr->n = n, ptr->nleft = 0, ptr->nright = 0;
    temp->right = ptr;
    ptr->left = NULL, ptr->right = NULL;
    return  ;
}

void insert(Node *root, char ch, int n, int k, int pos){
    if(k < pos){
        insert(root->left, ch, n, k, pos - root->left->nright - root->left->n);
        root->nleft += n;
    }
    else if(k == pos){
        if(ch == root->ch){
            root->n += n;
            return  ;
        }
        if(root->left != NULL){
            insertright(root->left, ch, n);
            root->nleft += n;
            return  ;
        }
        root->left = malloc(sizeof(Node));
        root->left->ch = ch, root->left->n = n;
        root->left->nleft = 0, root->left->nright = 0;
        root->nleft += n;
    }
    else if(k > pos && k < pos + root->n){
        if(ch == root->ch){
            root->n += n;
            return  ;
        }
        if(root->right != NULL){
            insertleft(root->right, root->ch, root->n - (k - pos));
            insertleft(root->right, ch, n);
            root->nright += n + root->n - (k - pos);
            root->n = k - pos;
            return  ;
        }
        root->right = malloc(sizeof(Node));
        root->right->ch = root->ch, root->right->n = root->n - (k - pos);
        root->right->nleft = n, root->right->nright = 0;
        root->right->left = malloc(sizeof(Node)), root->right->right = NULL;
        root->right->left->ch = ch, root->right->left->n = n;
        root->right->left->nleft = 0, root->right->left->nright = 0;
        root->right->left->left = NULL, root->right->left->right = NULL;
        root->nright += n + root->n - (k - pos);
        root->n = k - pos;
    }
    else if(k == pos + root->n){
        if(ch == root->ch){
            root->n += n;
            return  ;
        }
        if(root->right != NULL){
            insertleft(root->right, ch, n);
            root->nright += n;
            return  ;
        }
        root->right = malloc(sizeof(Node));
        root->right->ch = ch, root->right->n = n;
        root->right->nright = 0, root->right->nleft = 0;
        root->nright += n;
    }
    else{
        insert(root->right, ch, n, k, pos + root->n + root->right->nleft);
        root->nright += n;
    }
    return  ;
}

void print(Node *root){
    if(root == NULL) return  ;
    print(root->left);
    printf("%c %d ", root->ch, root->n);
    print(root->right);
    return  ;
}

int main(void){
    Node *root = NULL;
    char command[10] = {'\0'}, ch[3] = {'\0'};
    int n;
    while(scanf("%s", command) != EOF){
        if(command[0] == 'i'){
            scanf("%s%s%d", command, ch, &n);
            if(root == NULL){
                root = malloc(sizeof(Node));
                root->n = n, root->ch = ch[0], root->nleft = 0, root->nright = 0;
                root->right = NULL, root->left = NULL;
                continue;
            }
            if(command[0] != 'r' && command[0] != 'l'){
                int k = atoi(command);
                if(k - 1 == 0){
                    command[0] = 'l';
                }
                else if(k - 1 == root->nleft + root->nright + root->n){
                    command[0] = 'r';
                }
            }
            if(command[0] == 'r'){
                insertright(root, ch[0], n);
            }
            else if(command[0] == 'l'){
                insertleft(root, ch[0], n);
            }
            else{
                int k = atoi(command);
                insert(root, ch[0], n, k - 1, root->nleft);
            }
        }
        else{
            print(root);
            printf("$\n");
        }
    }
    return 0;
}

