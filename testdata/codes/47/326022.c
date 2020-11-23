#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

int x = 0;
int num = 0;
int len = 0;
char deli[2] = " \n";
char alpha;
typedef struct treenode{
	char c;
	int length;
	struct treenode *prev;
	struct treenode *next;
	int left_size,right_size;
}TreeNode;
TreeNode *base = NULL;
void print(TreeNode *root){ 
	if(root == NULL){
		return;
	} 
	print(root->prev);
	printf("%c %d ",root->c, root->length);
	print(root->next);
}
TreeNode *split_node(TreeNode *root, char c, int address, int num){
	TreeNode *current = NULL,*current_2 = NULL;
	current = (TreeNode*)malloc(sizeof(TreeNode));
	assert(current != NULL);
	current->right_size = root->right_size;
	current->length = root->left_size + root->length - address + 1; 
	current->next = root->next;
	current->prev = NULL;
	current->c = root->c;
	current->left_size = 0;
	root->next = current;
	current_2 = (TreeNode*)malloc(sizeof(TreeNode));
	assert(current_2 != NULL);
	current_2->left_size = root->left_size;
	current_2->right_size = 0;
	current_2->length =	address - root->left_size - 1;
	current_2->next = NULL;
	current_2->prev = root->prev;
	current_2->c = root->c;
	root->prev = current_2;
	root->length = num;
	root->left_size = root->prev->left_size + root->prev->right_size + root->prev->length;
	root->right_size = root->next->left_size + root->next->right_size + root->next->length;
	root->c = c;
	return(root);
}
TreeNode *insert(TreeNode *root, char c, int address, int num){
	if(root == NULL){
		TreeNode *current;
		current = (TreeNode*)malloc(sizeof(TreeNode));
		//assert(current != NULL);
		current->prev = NULL;
		current->next = NULL;
		current->right_size = 0;
		current->left_size = 0;
		current->c = c;
		current->length = num;
		return (current);
	}
	if(address == root->left_size + root->length + 1 && root->c == c){
		root->length += num;
		return(root);
	}
	else if(address == root->left_size + 1 && root->c == c){
		root->length += num;
		return(root);
	}
	if(address > root->left_size + 1 && address <= root->left_size + root->length && root->length != 1){
		if(root->c == c){
			root->length += num;
			return(root);
		}
		return(split_node(root, c, address, num));
	}
	if(address <= root->left_size + 1){
		root->prev = insert(root->prev, c, address, num);
		root->left_size = root->prev->left_size + root->prev->right_size + root->prev->length;
		
	}
	else if(address > root->left_size + root->length){
		root->next = insert(root->next, c, address - root->left_size - root->length, num);
		root->right_size = root->next->left_size + root->next->right_size + root->next->length;
	}
	return(root);
}
char *operate(char *instruction){
	if(!strcmp(instruction,"print")){
		print(base);
	//	printf("\n%d\n",len);
		puts("$");
	}
	if(!strcmp(instruction,"insert")){
		instruction = strtok(NULL,deli);
		
		if(!strcmp(instruction,"left")){
			x = 1;
		}
		else if(!strcmp(instruction,"right")){
			x = len + 1;
		}
		else{
			sscanf(instruction,"%d",&x);
		}
		instruction = strtok(NULL,deli);
		sscanf(instruction,"%c",&alpha);
		instruction = strtok(NULL,deli);
		sscanf(instruction,"%d",&num);
		base = insert(base, alpha, x, num);
		len += num;
	}
	instruction = strtok(NULL,deli);
	return instruction;
}
int main(void) {
	char input[128] = "";
	while(fgets(input,128,stdin) != NULL){
	char *start = strtok(input,deli);
	while(start != NULL){
		start = operate(start);
	}
	}
	return 0;
}
