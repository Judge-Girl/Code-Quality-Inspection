#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int total = 0;
typedef struct tree{
	char c;
	int length;
	int leftlen,rightlen;
	struct tree *left, *right;
}Tree;
void print(Tree *root){
	if(root == NULL) return ;
	print(root->left);
	printf("%c %d ",root->c,root->length);
	print(root->right);
}
Tree *insert(Tree *root,char c,int len,int pos){
	Tree *cur, *cur2;
	if(root == NULL){
		cur = (Tree *)malloc(sizeof(Tree));
		cur->c = c;
		cur->length = len;
		cur->leftlen = 0;
		cur->rightlen = 0;
		cur->left = NULL;
		cur->right = NULL;
		return cur;
	}
	if(root->c == c && pos > root->leftlen && pos <= (root->leftlen+root->length+1)){
        root->length+=len;
        return root;
    }
    if(pos > (root->leftlen + root->length)){
        root->right = insert(root->right,c,len,pos-root->length-root->leftlen);
        root->rightlen = (root->right->length)+(root->right->leftlen)+(root->right->rightlen);
        return root;
    }
    if(pos <= (root->leftlen+1)){
    	root->left = insert(root->left,c,len,pos);
    	root->leftlen = (root->left->length)+(root->left->leftlen)+(root->left->rightlen);
    	return root;
    }
    cur2 = (Tree *)malloc(sizeof(Tree));
    cur2->c = root->c;
    cur2->length = root->length - (pos - root->leftlen - 1);
    cur2->leftlen = 0;
    cur2->rightlen = root->rightlen;
    cur2->left = NULL;
    cur2->right = root->right;
    root->length-=cur2->length;
    root->rightlen = 0;
    root->right = NULL;
    cur = (Tree *)malloc(sizeof(Tree));
    cur->c = c;
    cur->length = len;
    cur->leftlen = root->length+root->leftlen;
    cur->rightlen = cur2->length+cur2->rightlen;
    cur->left = root;
    cur->right = cur2;
    return cur;
}
int main(){
	char instruction[10];
	Tree *root = NULL;
	while(scanf("%s",instruction) != EOF){
		if(strcmp(instruction,"insert") == 0){
			char ins[10]; scanf("%s",ins);
			char c[2]; scanf("%s",c);
			int len; scanf("%d",&len);
			if(strcmp(ins,"left") == 0){
				root = insert(root,c[0],len,1);
			}
			else if(strcmp(ins,"right") == 0){
				root = insert(root,c[0],len,total+1);
			}
			else{
				root = insert(root,c[0],len,atoi(ins));
			}
			total+=len;
		}
		else{
			print(root);
			printf("$\n");
		}
	}
}
