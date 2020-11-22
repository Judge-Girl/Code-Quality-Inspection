#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char c;
    int N;
    int LeftNum;
    int RightNum;
    struct node *left, *right; 
}Node;

Node *new(char c, int N, int RNum, int LNum, Node *rootR, Node *rootL){
    Node *root = (Node*)malloc(sizeof(Node));
    root->c = c;
    root->RightNum = RNum;
    root->LeftNum = LNum;
    root->N = N;
    root->left = rootL;
    root->right = rootR;
    return root;
}
Node *insert(Node *root, int pos, char c, int N){
    if(root == NULL)
        return new(c,N,0,0,NULL,NULL);
    if(pos > root->LeftNum && pos <= root->LeftNum+root->N+1 && c == root->c)
        root->N += N;
    else if(pos <= root->LeftNum+1){
        root->LeftNum += N;
        root->left = insert(root->left,pos,c,N);
    }
    else{
        pos -= root->LeftNum;
        if(pos > root->N){
            root->RightNum += N;
            root->right = insert(root->right,pos-root->N,c,N);
        }
        else{
            int R = root->N - pos + 1;
            int L = root->N - R;
            root->left = new(root->c,L,0,root->LeftNum,NULL,root->left);
            root->right = new(root->c,R,root->RightNum,0,root->right,NULL);
            root->c = c;
            root->LeftNum += L;
            root->RightNum += R;
            root->N = N;
        }
    }
    return root;
}
void traverse_print(Node *root){
    if(root == NULL) return;
    traverse_print(root->left);
    printf("%c %d ", root->c, root->N);
    traverse_print(root->right);
    return;
}
int main(void){
    char ins[7], dir[6], c;
    int N, Length = 0;;
    Node *root = NULL;
    while(scanf("%s", ins) != -1){
        if(!strcmp(ins,"print")){
            traverse_print(root);
            puts("$");
        }
        else{
            scanf("%s %c %d", dir, &c, &N);
            Length += N;
            if(dir[0] >= '0' && dir[0] <= '9'){
                int pos = atoi(dir);
                root = insert(root,pos,c,N);
            }
            else if(!strcmp(dir,"left")) root = insert(root,1,c,N);
            else root = insert(root,Length-N+1,c,N);
        }
    }
    return 0;
}
