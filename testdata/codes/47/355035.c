#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct node{
    char c;
    int num;
    int leftNum;
    int rightNum;
    struct node*left;
    struct node*right;
}Node;

Node *genNode(char c,int num,int leftNum,int rightNum,Node*left,Node*right){
    Node *tmp=malloc(sizeof(Node));
    assert(tmp!=NULL);
    tmp->c = c;
    tmp->num = num;
    tmp->leftNum = leftNum;
    tmp->rightNum = rightNum;
    tmp->left=left;
    tmp->right=right;
    return tmp;
}

Node *insert(Node *root,int pos,int c,int num){
    if(root==NULL) return genNode(c,num,0,0,NULL,NULL);
    if(c==root->c && pos>root->leftNum && pos<=(root->leftNum + root->num +1) ){
        root->num+=num;
        return root;
    }else if(pos <= root->leftNum+1){
        root->leftNum += num;
        root->left = insert(root->left,pos,c,num);
    }else if(pos > (root->leftNum + root->num) ){
        root->rightNum += num;
        root->right = insert(root->right, (pos - root->leftNum - root->num),c,num);
    }else{//split the root
        Node *split_left = genNode(root->c,pos-root->leftNum-1,root->leftNum,0,root->left,NULL);
        Node *split_right = genNode(root->c,root->num-(pos-root->leftNum-1),0,root->rightNum,NULL,root->right);
        free(root);
        int leftNum = split_left->num + split_left->leftNum;
        int rightNum = split_right->num + split_right->rightNum;
        root = genNode(c,num,leftNum,rightNum,split_left,split_right);
    }
    return root;
}

void Print(Node *root){
    if(root==NULL) return;
    Print(root->left);
    printf("%c %d ",root->c,root->num);
    Print(root->right);
}

int main(){
    char ins[8];//instruction
    Node *root=NULL;
    int length=0;
    while(scanf("%s",ins)!=EOF){
        if (strcmp(ins,"print")==0){
            Print(root);
            printf("$\n");
        }else{
            char position[12],c;
            int pos,num;
            scanf("%s%*c%c%d",position,&c,&num);
            if(strcmp(position,"left")==0) pos=1;
            else if(strcmp(position,"right")==0) pos=length+1;
            else pos=atoi(position);
            length+=num;
            root=insert(root,pos,c,num);
        }
    }
    return 0;
}
