#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

typedef struct tree{
    char c ;
    long long int time ;
    long long int l_sub ;
    struct tree *left, *right;
}Tree ;

typedef struct tree_stack{
    struct tree *treenode;
    struct Tree_stack *next;
}Tree_stack;

Tree_stack* creates(void);         // 建立堆疊
int isEmpty(Tree_stack*);           // 堆疊已空
Tree_stack* add(Tree_stack*, Tree*);   // 新增元素
Tree_stack* delete(Tree_stack*);     // 刪除元素

Tree_stack* creates() {
    return NULL;
}

int isEmpty(Tree_stack* top) {
    return (top == NULL);
}

Tree_stack* add(Tree_stack* top, Tree* node) {
    Tree_stack* newnode;

    newnode = (Tree_stack*) malloc(sizeof(Tree_stack));

    if(newnode == NULL) {
        printf("\n記憶體配置失敗！");
        exit(1);
    }

    newnode->treenode = node;
    newnode->next = top;
    top = newnode;

    return top;
}

Tree_stack* delete(Tree_stack* top) {
    Tree_stack* tmpnode;

    tmpnode = top;
    if(tmpnode == NULL) {
        printf("\n堆疊已空！");
        return NULL;
    }

    top = top->next;
    free(tmpnode);

    return top;
}


void printTree(Tree *root){
    //iterator
    Tree_stack* stack = creates();
    Tree* current = root;
    while(1){
        while(current){
            stack = add(stack,current);
            current = current->left;
        }
        if(isEmpty(stack))return;
        current = stack->treenode;

        printf("%c %d ",current->c,current->time);
        stack = delete(stack);
        current = current->right;
    }
    /*recursion
    if(tree)
    {
        if(tree->left)printTree(tree->left);
        printf("%c %d ",tree->c,tree->time);
        if(tree->right)printTree(tree->right);
    }*/
}
long long int read_number(char *ptr){
    long long int number = 0 ;
    while(isdigit(*ptr)){
        number = 10*number + *ptr - '0' ;
        ptr ++ ;
    }
    return number ;
}

int main()
{
    Tree *head = NULL;

    char read_command[100] ;
    while(fgets(read_command , 100 , stdin) != NULL){
        if(read_command[0] == 'p'){//print
            printTree(head);
            printf("$\n");
        }
        else if(read_command[7] == 'l' && read_command[8] == 'e'){//left
            Tree *temp ;
            temp = (Tree *)malloc(sizeof(Tree)) ;
            temp->c = read_command[12] ;
            temp->time = read_number(&read_command[14]) ;
            temp->l_sub = 0;
            temp->left = NULL ;
            temp->right = NULL ;

            if(head==NULL)
                head = temp;
            else{
                Tree* current = head;
                //find place to place and add sub tree num
                while(current->left){
                    current->l_sub += temp->time;
                    current = current->left;
                }

                //duplicate
                if(current->c == temp->c){
                    current->time += temp->time;
                    free(temp);
                }
                else{
                    current->l_sub += temp->time;
                    current->left = temp;
                }
            }
        }else if(read_command[7] == 'r' && read_command[8] == 'i'){//right
            Tree *temp;
            temp = (Tree *)malloc(sizeof(Tree)) ;
            temp->c = read_command[13] ;
            temp->time = read_number(&read_command[15]) ;
            temp->l_sub = 0;
            temp->left = NULL ;
            temp->right = NULL ;

            if(head==NULL)
                head = temp;
            else{
                Tree* current = head;
                //find place to place and add sub tree num
                while(current->right)
                    current = current->right;

                //duplicate
                if(current->c == temp->c){
                    current->time += temp->time;
                    free(temp);
                }
                else current->right = temp;
            }
        }else{//insert
            long long int th = read_number(&read_command[7]) ;
            //process new_head
            char *ptr = &read_command[7] ;
            while(*ptr != ' ') ptr++ ;
            ptr++ ;
            Tree *temp ;
            temp = (Tree *)malloc(sizeof(Tree)) ;
            temp->c = *ptr ;
            temp->time = read_number(ptr+2) ;
            temp->l_sub = 0;
            temp->left = NULL;
            temp->right = NULL;

            if(head==NULL){
                head = temp;
                continue;
            }

            //process put place
            long long int now_th = head->l_sub;
            Tree* current = head;
            while(1){
                if(th > now_th+1 && th <= now_th + current->time)//插在一串相同字元之間
                {
                    //duplicate
                    if(current->c == temp->c){
                        current->time += temp->time;
                        free(temp);
                    }
                    else{
                        Tree* divide;
                        divide = (Tree *)malloc(sizeof(Tree)) ;
                        divide->c = current->c;
                        divide->time = th - (now_th + 1);
                        divide->l_sub = 0;
                        divide->left = NULL;
                        divide->right = temp;

                        current->time -= divide->time;
                        current->l_sub += temp->time + divide->time;

                        if(current->left){
                            current = current->left;
                            while(current->right)
                                current = current->right;
                            current->right = divide;
                        }
                        else current->left = divide;
                    }
                    break;
                }
                else if(th == now_th+1)//插在左邊
                {
                    if(current->c == temp->c){//duplicate
                        current->time += temp->time;
                        free(temp);
                        break;
                    }
                    if(!current->left){//no left tree
                        if(current->c == temp->c){//duplicate
                            current->time += temp->time;
                            free(temp);
                            break;
                        }
                        current->l_sub = temp->time;
                        current->left = temp;
                        break;
                    }
                    else{//has left tree and find very right
                        current->l_sub += temp->time;
                        current = current->left;
                        while(1){
                            if(current->right)
                                current = current->right;
                            else break;
                        }
                    }
                    //duplicate
                    if(current->c == temp->c){
                        current->time += temp->time;
                        free(temp);
                    }
                    else current->right = temp;
                    break;
                }
                else if(th == now_th+current->time+1)//插在右邊
                {
                    if(current->c == temp->c){//duplicate
                        current->time += temp->time;
                        free(temp);
                        break;
                    }
                    if(!current->right)//has no right tree
                    {
                        if(current->c == temp->c){//duplicate
                            current->time += temp->time;
                            free(temp);
                            break;
                        }
                        current->right = temp;
                        break;
                    }
                    else{
                        current = current->right;
                        while(1){
                            current->l_sub += temp->time;
                            if(current->left)
                                current = current->left;
                            else break;
                        }
                    }
                    //duplicate
                    if(current->c == temp->c){
                        current->l_sub -= temp->time;
                        current->time += temp->time;
                        free(temp);
                    }
                    else current->left = temp;
                    break;
                }
                else
                {
                    if(th < now_th+1)//go left
                    {
                        if(current->left){
                            now_th = now_th  - (current->l_sub - current->left->l_sub);
                            current->l_sub += temp->time;
                            current = current->left;
                        }
                        else{
                            current->l_sub += temp->time;
                            current->left = temp;
                            break;
                        }
                    }
                    else if(th > now_th+current->time+1)//go right
                    {
                        if(current->right){/**recursion find left***/
                            now_th = now_th  + (current->time + current->right->l_sub);
                            current = current->right;
                        }
                        else{
                            current->right = temp;
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

