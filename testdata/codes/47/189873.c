#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#define MAXN 2000090
typedef struct node{
    int leftSubNum, rightSubNum, num;
    struct node *left, *right;
    char c;
}Treenode;
Treenode node[MAXN];
int numOfNode = 0, totalchar=0;
int strToDigit(char s[]){
    int sum=0, i=0;
    while(isdigit(s[i])){
        sum *= 10;
        sum += s[i]-'0';
        i++;
    }
    return sum;
}
Treenode* insertNode(Treenode *root, int pos, char x, int numOfchar){
    if(root==NULL){
        node[numOfNode].left = node[numOfNode].right = NULL;
        node[numOfNode].leftSubNum = node[numOfNode].rightSubNum = 0;
        node[numOfNode].c = x; node[numOfNode].num = numOfchar;
        numOfNode++;
        return &node[numOfNode-1];
    }
    int lpos = root->leftSubNum - pos;
    int rpos = pos - root->num - root->leftSubNum;
    if(lpos>0){//pos<root->leftSubNum
        root->leftSubNum += numOfchar;
        root->left = insertNode(root->left, pos, x, numOfchar);
    }
    else if(rpos>0){//pos>root->num+root->leftSubNum
        root->rightSubNum += numOfchar;
        root->right=insertNode(root->right,rpos,x,numOfchar);
    }
    else if(lpos==0){//pos==root->leftSubNum
        if(root->c==x)
            root->num += numOfchar;
        else{
            root->leftSubNum += numOfchar;
            root->left = insertNode(root->left, pos, x, numOfchar);
        }
    }
    else if(rpos==0){//pos==root->num+root->leftSubNum
        if(root->c==x)
            root->num += numOfchar;
        else{
            root->rightSubNum += numOfchar;
            root->right=insertNode(root->right,rpos,x,numOfchar);
        }
    }
    else{
        if(root->c==x)
            root->num += numOfchar;
        else{
            int leftnum = pos - root->leftSubNum;
            int rightnum = root->num - leftnum;
            root->left=insertNode(root->left,root->leftSubNum,root->c,leftnum);
            root->right=insertNode(root->right,0,root->c,rightnum);
            root->leftSubNum += leftnum;
            root->rightSubNum += rightnum;
            root->num = numOfchar; root->c = x;
        }
    }
    return root;
}
void myprint(Treenode *root){
    if(root==NULL)
        return;
    myprint(root->left);
    printf("%c %d ",root->c,root->num);
    myprint(root->right);
}
int main()
{
    char command[60], *ptr[4];
    Treenode *root = NULL;
    while(fgets(command, 60, stdin)!=NULL){
        if(command[0]=='p'){
            myprint(root);
            puts("$");
        }
        else{
            char *start = strtok(command," ");
            int index = 0;
            while(start!=NULL){
                ptr[index++] = start;
                start = strtok(NULL, " ");
            }
            assert(index==4);
            int pos;
            if(*ptr[1]=='l')
                pos = 1;
            else if(*ptr[1]=='r')
                pos = totalchar+1;
            else
                pos = strToDigit(ptr[1]);
            int numbOfchar = strToDigit(ptr[3]);
            totalchar += numbOfchar;
            root = insertNode(root, pos-1, *ptr[2], numbOfchar);
        }
    }
    return 0;
}

