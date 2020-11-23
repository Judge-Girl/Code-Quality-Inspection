#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#define DEBUG 1
typedef struct charnode{
    char c;
    int n;
    int leftn;
    int rightn;
    struct charnode *left;
    struct charnode *right;
}Charnode;

int lnr(char *p){
    if(isdigit(*p)) return 0;
    else if(!strcmp(p,"right")) return 1;
    else if(!strcmp(p,"left")) return -1;
    else assert(0);
}

void print(Charnode *root){
    if(root == NULL) return;
    print(root->left);
    printf("%c %d ",root -> c, root -> n);
    print(root->right);
}

Charnode* insertleft(Charnode *root,char c,int n){
    if(root==NULL){
        Charnode* current =(Charnode*)malloc(sizeof(Charnode));
        current -> left = NULL;
        current -> right = NULL;
        current -> leftn = 0;
        current -> rightn = 0;
        current -> c = c;
        current -> n = n;
        return current;
    }
    if(root -> left == NULL && root -> c == c){
        root -> n += n;
        return root;
    }
    root -> left = insertleft(root -> left,c,n);
    root -> leftn += n;
    return root;
}

Charnode* insertright(Charnode *root,char c,int n){
    if(root==NULL){
        Charnode* current = (Charnode*)malloc(sizeof(Charnode));
        current -> left = NULL;
        current -> right = NULL;
        current -> leftn = 0;
        current -> rightn = 0;
        current -> c = c;
        current -> n = n;
        return current;
    }
    if(root -> right == NULL && root -> c == c){
        root -> n += n;
        return root;
    }
    root -> right = insertright(root -> right,c,n);
    root -> rightn += n;
    return root;
}

Charnode* insertnode(Charnode *root,char c,int n,int loc,int s){
    if(root==NULL){
        Charnode* current = (Charnode*)malloc(sizeof(Charnode));
        current -> left = NULL;
        current -> right = NULL;
        current -> leftn = 0;
        current -> rightn = 0;
        current -> c = c;
        current -> n = n;
        return current;
    }
    if(loc >= s && loc <= s + root -> n && root -> c == c){
        root -> n += n;
        return root;
    }
    else if(loc > s && loc < s + root -> n){
        Charnode* currentleft = (Charnode*)malloc(sizeof(Charnode));
        Charnode* currentright = (Charnode*)malloc(sizeof(Charnode));
        currentleft -> c = root -> c;
        currentleft -> n = loc - s;
        currentleft -> leftn = root -> leftn;
        currentleft -> rightn = 0;
        currentleft -> left = root -> left;
        currentleft -> right = NULL;
        currentright -> c = root -> c;
        currentright -> n = s + root -> n - loc;
        currentright -> leftn = 0;
        currentright -> rightn = root -> rightn;
        currentright -> left = NULL;
        currentright -> right = root -> right;
        root -> c = c;
        root -> n = n;
        root -> rightn += currentright -> n;
        root -> leftn += currentleft -> n;
        root -> right = currentright;
        root -> left = currentleft;
        return root;
    }
    else if(loc <= s){
        if(root -> left != NULL) s = s - root -> left -> rightn - root -> left -> n;
        root -> left = insertnode(root -> left,c,n,loc,s);
        root -> leftn += n;
    }
    else if(loc >= s + root -> n){
        if(root -> right != NULL) s = s + root -> n + root -> right -> leftn;
        else s = s + root -> n;
        root -> right = insertnode(root -> right,c,n,loc,s);
        root -> rightn += n;
    }
    return root;
}
int main()
{
    char command[6];
    Charnode* root = NULL;
    while(scanf("%s",command)==1){
        if(!strcmp("print",command)){
            print(root);
            printf("$\n");
        }
        else if(!strcmp("insert",command)){
            char location[16],c[2];
            int n;
            scanf("%s %s %d",location,c,&n);
            int p = lnr(location);
            if(p==0){
                int loc = atoi(location);
                int s = 0;
                if(root != NULL) s = root -> leftn;
                root = insertnode(root,c[0],n,loc-1,s);
            }
            else if(p==1) root = insertright(root,c[0],n);
            else if(p==-1) root = insertleft(root,c[0],n);
            else assert(0);
        }
        else assert(0);
    }
}

