#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

char last_print ;
int total ;
int first_time ;

typedef struct tree{
    char c ;
    int time ;//subtree total
    struct tree *left , *right , *middle ;
}Tree ;

void initTree(Tree *tree , char c , int time);
void printTree(Tree *tree) ;
int read_number(char *) ;
void find_place(Tree *head , Tree *new_head , int *th , int count) ;
void find_right(Tree *head , Tree *new_head) ;
void find_left(Tree *head , Tree *new_head) ;

int main()
{
    Tree *head  = NULL ;
    char read_command[100] ;
    while(fgets(read_command , 100 , stdin) != NULL){
        if(read_command[0] == 'p'){
            last_print = '\0' ;
            total = 0 ;
            first_time = 1 ;
            printTree(head)  ;
            if(!first_time)
                printf("%c %d " , last_print , total) ;
            printf("$\n") ;
        }else if(head == NULL){//haven't built any tree yet
            int time ;
            char c ;
            if(read_command[7] == 'l'){
                time = read_number(&read_command[14]) ;
                c = read_command[12] ;
            }
            else if(read_command[7] == 'r'){
                time = read_number(&read_command[15]) ;
                c = read_command[13] ;
            }else{
                time = read_number(&read_command[11]) ;
                c = read_command[9] ;
            }
            head = (Tree *)malloc(sizeof(Tree)) ;
            initTree(head , c , time) ;
        }else if(read_command[7] == 'l'){
            Tree *new_head ;
            new_head = (Tree *)malloc(sizeof(Tree)) ;
            int time = read_number(&read_command[14]) ;
            initTree(new_head , read_command[12] , time) ;
            find_left(head , new_head) ;
        }else if(read_command[7] == 'r'){
            Tree *new_head ;
            new_head = (Tree *)malloc(sizeof(Tree)) ;
            int time = read_number(&read_command[15]) ;
            initTree(new_head , read_command[13] , time) ;
            find_right(head , new_head) ;
        }else{
            int th = read_number(&read_command[7]) ;
            //process new_head
            char *ptr = &read_command[7] ;
            while(*ptr != ' ') ptr++ ;
            ptr++ ;
            Tree *new_head ;
            new_head = (Tree *)malloc(sizeof(Tree)) ;
            int time = read_number(ptr+2) ;
            initTree(new_head , *ptr , time) ;
            find_place(head , new_head , &th , 0) ;
        }
    }
    return 0;
}

void initTree(Tree *tree , char c , int time){
    tree->c = c ;
    tree->time = time ;
    tree->left = tree->right = tree->middle = NULL ;
}

void printTree(Tree *tree){
    if(tree == NULL)
        return ;
    //printf("%c %d " , tree->c , tree->time) ;
    if(tree->left == NULL && tree->right == NULL && tree->middle == NULL){
        if(tree->c == last_print)
            total += tree->time ;
        else{
            if(first_time)
                first_time = 0 ;
            else printf("%c %d " , last_print , total) ;
            last_print = tree->c ;
            total = tree->time ;
        }
    }
    printTree(tree->left) ;
    printTree(tree->middle) ;
    printTree(tree->right) ;
}

int read_number(char *ptr){
    int number = 0 ;
    while(isdigit(*ptr)){
        number = 10*number + *ptr - '0' ;
        ptr ++ ;
    }
    return number ;
}

void find_place(Tree *head , Tree *new_head , int *th , int count){
    if(head->left == NULL && head->middle == NULL && head->right == NULL){
        if(head->c == new_head->c){
            head->time += new_head->time ;
            return ;
        }
        if(head->time+count+1 == *th){
            head->left = (Tree *)malloc(sizeof(Tree)) ;
            initTree(head->left , head->c , head->time) ;
            head->right = new_head ;
        }else if(*th+count-1 == 0){
            head->left = new_head ;
            head->right = (Tree *)malloc(sizeof(Tree)) ;
            initTree(head->right , head->c , head->time) ;
        }else{
            head->left = (Tree *)malloc(sizeof(Tree)) ;
            initTree(head->left , head->c , *th-count-1) ;
            head->middle = new_head ;
            head->right = (Tree *)malloc(sizeof(Tree)) ;
            initTree(head->right , head->c , head->time-*th+count+1) ;
        }
        head->time += new_head->time ;
        return ;
    }
    if(head->left != NULL && *th <= head->left->time+count+1){
        head->time += new_head->time ;
        find_place(head->left , new_head , th , count) ;
        return ;
    }
    if(head->left != NULL)
        count += head->left->time ;
    if(head->middle != NULL && *th <= head->middle->time+count+1){
        head->time += new_head->time ;
        find_place(head->middle , new_head , th , count) ;
        return ;
    }
    if(head->middle != NULL)
        count += head->middle->time ;
    if(head->right != NULL && *th <= head->right->time+count+1){
        head->time += new_head->time ;
        find_place(head->right , new_head , th , count) ;
    }
}

void find_right(Tree *head , Tree *new_head){
    while(head->right != NULL){
        head->time += new_head->time ;
        head = head->right ;
    }
    if(head->c != new_head->c){
        head->right = new_head ;
        head->left = (Tree *)malloc(sizeof(Tree)) ;
        initTree(head->left , head->c , head->time) ;
    }
    head->time += new_head->time ;
}

void find_left(Tree *head , Tree *new_head){
    while(head->left != NULL){
        head->time += new_head->time ;
        head = head->left ;
    }
    if(head->c != new_head->c){
        head->left = new_head ;
        head->right = (Tree *)malloc(sizeof(Tree)) ;
        initTree(head->right , head->c , head->time) ;
    }
    head->time += new_head->time ;
}

