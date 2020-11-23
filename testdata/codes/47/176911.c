#include<stdio.h>
#include<string.h>
#include<math.h>
#include <stdlib.h>
#include <assert.h>

struct treenode {
    char word;
    int data;
    int cur;
    struct treenode *left;
    struct treenode *right;
};
typedef struct treenode Tree;

void printtree(Tree *root)
{
  if (root == NULL)
    return;
  printtree(root->left);
  //if(root->data !=0){
    printf("%c %d ", root->word, root->data);
    //printf("%d\n", root->cur);
  //}
  printtree(root->right);
}

Tree *insert(Tree *root, int way, int place, char c3, int c4)
{
    if(c4==0)return root;
    if(root==NULL){
        Tree *current;
        current = (Tree*)malloc(sizeof(Tree));
        assert(current != NULL);
        current->data = c4;
        current->word = c3;
        current->left = NULL;
        current->right = NULL;
        current->cur=0;
        root= current;
        return root;
    }
    if(way==0){
        if (root->left == NULL) {
            if(root->word == c3){   
                root->data= root->data+ c4;
                return root;
            }
            else{
                Tree *current;
                current = (Tree*)malloc(sizeof(Tree));
                assert(current != NULL);
                current->data = c4;
                current->word = c3;
                current->left = NULL;
                current->right = NULL;
                current->cur=0;
                root->left= current;
                root->cur= root->cur+ c4;
                return root;
            }
            
        }

        else{
            root->left= insert(root->left, 0, 0, c3, c4);
            root->cur= (root->cur)+c4;
            return root;
        }
    }
    
    else if(way==1){
        if (root->right == NULL) {
            if(root->word == c3){
                root->data= root->data+ c4;
                return root;
            }
            else{
                Tree *current;
                current = (Tree*)malloc(sizeof(Tree));
                assert(current != NULL);
                current->data = c4;
                current->word = c3;
                current->left = NULL;
                current->right = NULL;
                current->cur= 0;
                root->right= current;
                return root;
            }
            
        }
        
        else{
            root->right= insert(root->right, 1, 0, c3, c4);
            return root;
        }
    }

    else if(way==2){
         if (root == NULL) {
            Tree *current;
            current = (Tree*)malloc(sizeof(Tree));
            assert(current != NULL);
            current->data = c4;
            current->word = c3;
            current->left = NULL;
            current->right = NULL;
            current->cur=0;
            return(current);
        }
        if (place <= root->cur){
            if(place == root->cur && root->word== c3){
                root->data= root->data+ c4;
                return root;
            }

            root->left = insert(root->left, 2, place, c3, c4);
            if(way==2){
                root->cur= (root->cur)+ c4;
                //printf("%c %d\n", root->word, root->cur);
            }
            return root;
        }
        else if(place >= (root->cur)+ (root->data)){
            //printf("OK %c\n", c3);
            if(place == (root->cur)+(root->data) && root->word== c3){
                root->data= root->data+ c4;
                return root;
            }
            
            root->right= insert(root->right, 2, 
                place-(root->cur)-(root->data), c3, c4);
            return root;
        }

            if(root->word== c3){
                root->data= root->data+ c4;
                return root;
            }

            if(place- (root->cur) ==0){
                Tree *current;
                current = (Tree*)malloc(sizeof(Tree));
                assert(current != NULL);
                current->data = c4;
                current->word = c3;
                current->left = root->left;
                current->right = NULL;
                current->cur=root->cur;
                root->left= current;
                root->cur= root->cur+ c4;
                return root;
            }
            Tree *temp1= root->left;
            Tree *temp2= root->right;
            Tree *current;
            current = (Tree*)malloc(sizeof(Tree));
            assert(current != NULL);
            current->data = c4;
            current->word = c3;
            current->cur=place;

            Tree *t1;
            t1=(Tree*)malloc(sizeof(Tree));
            assert(t1 != NULL);
            t1->data = place- root->cur;
            t1->word = root->word;
            t1->cur=root->cur;

            Tree *t2;
            t2=(Tree*)malloc(sizeof(Tree));
            assert(t2 != NULL);
            t2->data = (root->data)+(root->cur)-place;
            t2->word = root->word;
            t2->cur=0;

            root= current;
            root->left= t1;
            root->right= t2;
            t1->left= temp1;
            t1->right= NULL;
            t2->left= NULL;
            t2->right= temp2; 

            return root;
      
    }
    
}

int count(char d[]){
    int e=strlen(d);
    //printf("len %d\n", e);
    int x=0;
    int c=1;
    for (int i = 0; i < e-1; ++i)
    {
        c=c*10;
    }
    for(int i=0; i<e; i++){
        x=x+(d[i]-48)*c;
        c=c/10;
        //printf("%d\n", x);
    }
    //printf("x=%d\n", x);
    return x;
}

int main(void){
 
    char c1[15], c2[15], c3[15];
    int c4;
    Tree *root= NULL;
    while(scanf("%s", &c1)!=EOF){
        if(c1[0]=='i'){        //insert
            scanf("%s", &c2);
 
            if(c2[0]=='l'){        //left
                scanf("%s", &c3);             
                scanf("%d", &c4);
                root= insert(root, 0, 0, c3[0], c4);
            }

            else if(c2[0]=='r'){    //right
                scanf("%s", &c3);
                scanf("%d", &c4);
                root= insert(root, 1, 0, c3[0], c4);
            }
 
            else{
                int y=count(c2)-1;
                scanf("%s", &c3);
                scanf("%d", &c4);
                root= insert(root, 2, y, c3[0], c4);
                //printf("%s ", c2);
                //printf("%d\n", y);
            }
                
        }
 
        else if(c1[0]=='p'){
             printtree(root);
             printf("$\n");
        }
    }
}
