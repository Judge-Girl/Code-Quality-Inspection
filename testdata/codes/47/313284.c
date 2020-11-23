#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <memory.h>


typedef struct treenode{
    char alpha;
    int alphanum;
    int leftnum;
    int rightnum;
    struct treenode *left;
    struct treenode *right;
}Node;
 
Node *insert(Node *root, int alphanum, char alpha, int index){
	if(root == NULL){
		Node* newnode = (Node *)malloc(sizeof(Node));
		newnode->alpha = alpha;
		newnode->alphanum = alphanum;
		newnode->leftnum = 0;
		newnode->rightnum = 0;
		newnode->left = NULL;
		newnode->right = NULL;
		return newnode;
	}
	if(index <= root->leftnum + root->alphanum + 1 && index > root->leftnum){
		if(root->alpha == alpha){
			root->alphanum += alphanum;
			return root;
		}
		if(index != root->leftnum + 1 && index != root->leftnum + root->alphanum + 1){
			Node* newleft = (Node *)malloc(sizeof(Node));
			Node* newright = (Node *)malloc(sizeof(Node));
			newleft->alpha = root->alpha;
			newleft->alphanum = index - root->leftnum - 1;
			newleft->leftnum = root->leftnum;
			newleft->rightnum = 0;
			newleft->left = root->left;
			newleft->right = NULL;
			newright->alpha = root->alpha;
			newright->alphanum = root->alphanum + root->leftnum - index + 1;
			newright->rightnum = root->rightnum;
			newright->leftnum = 0;
			newright->right = root->right;
			newright->left = NULL;
			root->alpha = alpha;
			root->leftnum += newleft->alphanum;
			root->rightnum += newright->alphanum;
			root->alphanum = alphanum;
			root->left = newleft;
			root->right = newright;
			return root;
		}
	}	
	if(index > root->leftnum + root->alphanum){
		root->rightnum += alphanum;
		root->right = insert(root->right, alphanum, alpha, index - root->leftnum - root->alphanum);
	}
	else{
		root->leftnum += alphanum;
		root->left = insert(root->left, alphanum, alpha, index);
	}
	return root;
}

void printtree(Node* root){
	if(root == NULL) return;
	printtree(root->left);
	printf("%c %d ", root->alpha, root->alphanum);
	printtree(root->right);
	return;
}

void freetree(Node* root){
	if(root == NULL) return;
	freetree(root->left);
	freetree(root->right);
	free(root);
	return;
}

int main(){
	char left[] = "left", right[] = "right", print[] = "print";
    Node *root = NULL;
    char command[10], alpha, block;
    int alphanum, len = 0;
    while(scanf("%s", command) != EOF){
    	if(strcmp(command, print) == 0){
    		printtree(root);
    		printf("$\n");
    		continue;
		}
		scanf("%s%c%c%d", command, &block, &alpha, &alphanum);
		if(strcmp(command, left) == 0)
			root = insert(root, alphanum, alpha, 1);
		else if(strcmp(command, right) == 0)
			root = insert(root, alphanum, alpha, len + 1);
		else{
			int index = atoi(command);
			root = insert(root, alphanum, alpha, index);
		}		
		len += alphanum;
	}
    free(root);
    return 0;
}

