#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
	int num,numLeft,numRight;
	char word;
	struct Node *left, *right, *parent;

}Node;
Node *head = NULL;
void printing(Node *root) {
	if(!root)return;
	if(root->left)printing(root->left);
	printf("%c %d ", root->word, root->num);
	if(root->right)printing(root->right);
}
Node* initialize(char target, int number, Node *parent) {
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp->word = target;
	tmp->num = number;
	tmp->numLeft = 0;
	tmp->numRight = 0;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->parent = parent;
	return tmp;
}
void insertLeft(Node *root, char target, int number) {
	if(!root) {
		head = initialize(target,number,NULL);
	} else if (!root->left) {
		if(root->word ==target) {
			root->num += number;
			return;
		}
		root->numLeft += number;
		Node *tmp = initialize(target,number,root);
		root->left = tmp;
	} else {
		root->numLeft += number;
		insertLeft(root->left, target, number);
	}
}
void insertRight(Node *root, char target, int number) {
	if (!root) {
		head = initialize(target,number,NULL);
	} else if (!root->right) {
		if(root->word == target) {
			root->num += number;
			return;
		}
		root->numRight += number;
		Node *tmp = initialize(target,number,root);
		root->right = tmp;
	} else {
		root->numRight += number;
		insertRight(root->right, target, number);
	}
}
void insertAtPos(Node *root, int position, char target, int number, int dir) {
	if (!root) {
		head = initialize(target,number,NULL);
	} else if (position < root->numLeft+1) {
		root->numLeft += number;
		insertAtPos(root->left, position, target, number,-1);
	} else if (position > root->numLeft + root->num+1) {
		root->numRight += number;
		insertAtPos(root->right, position-root->numLeft-root->num, target, number,1);
	} else if (target == root->word) {
		root->num += number;
	} else {
		int l,r;
		l=position-root->numLeft-1;
		r=root->num-l;
		if(l>0 && r>0){
			if(root->left) { 
				insertRight(root->left,root->word,l);
			} else {
				root->left = initialize(root->word,l,root);
			}
			if(root->right) {
				insertLeft(root->right,root->word,r);
			} else {
				root->right = initialize(root->word,r,root);
			}
			root->numLeft+=l;
			root->numRight+=r;
			root->num=number;
			root->word=target;
		} else if (l==0) {
			if(root->left) {
				insertRight(root->left,target,number);
			} else {
				root->left = initialize(target,number,root);
			}
			root->numLeft+=number;	
		} else if (r==0) {
			if(root->right) {
				insertLeft(root->right,target,number);
			} else {
				root->right = initialize(target,number,root);
			}
			root->numRight+=number;
		}
	}
}
int main(){
	char command[20];
	while(scanf("%s", command) != EOF){
		Node *root=head;
		if(strcmp(command,"print") == 0){
			printing(root);
			printf("$\n");
		} else if(strcmp(command,"insert")==0){
			char pos[30],target[3];
			int number;
			scanf("%s%s%d",pos, target, &number);
			if(strcmp(pos,"left")==0)insertLeft(root, target[0], number);
			else if(strcmp(pos,"right")==0)insertRight(root, target[0], number);
			else { 
				int position = atoi(pos);
				insertAtPos(root, position, target[0], number,0);
			}
		}
	}
}

