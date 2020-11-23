#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct tree{
	int leftnum, chnum;
	char c;
	struct tree* left;
	struct tree* right;	
};
typedef struct tree tree;
int str2int(char* str)
{
	int result = 0;
	while (*str - '0' >= 0 && *str - '0' <= 9){
		result = result * 10 + *str - '0';
		str++;
	}
	return result;
}
void printanswer(tree* root)
{
	if (root == NULL){
		return;
	}
	printanswer(root->left);
	printf("%c %d ", root->c, root->chnum);
	printanswer(root->right);
}
tree* addleft(tree* root, char c, int num){
	tree* current = root;
	if (current == NULL){	
		current = (tree*)malloc(sizeof(tree));
		current->left = current->right = NULL;
		current->leftnum = 0;
		current->c = c;
		current->chnum = num;
		return current;	 
	}
	while (current->left != NULL){
		current->leftnum += num;
		current = current->left;
	}
	if (current->c == c){
		current->chnum += num;
		return root;
	}
	current->left = (tree*)malloc(sizeof(tree));
	current->leftnum += num;
	current = current->left;
	current->left = current->right = NULL;
	current->leftnum = 0;
	current->c = c;
	current->chnum = num;
	return root;	 
}
tree* addright(tree* root, char c, int num){
	tree* current = root;
	if (current == NULL){	
		current = (tree*)malloc(sizeof(tree));
		current->left = current->right = NULL;
		current->leftnum = 0;
		current->c = c;
		current->chnum = num;
		return current;	 
	}
	while (current->right != NULL){
		current = current->right;
	}
	if (current->c == c){
		current->chnum += num;
		return root;
	}
	current->right = (tree*)malloc(sizeof(tree));
	current = current->right;
	current->left = current->right = NULL;
	current->leftnum = 0;
	current->c = c;	
	current->chnum = num;
	return root;
}
tree* addmid(tree* root, char c, int pos, int num)
{
	if (root == NULL && pos == 1){
		root = (tree*)malloc(sizeof(tree));
		root->left = root->right = NULL;
		root->leftnum = 0;
		root->c = c;
		root->chnum = num;
		return root;
	}
	if (pos >= root->leftnum + 1 && pos <= root->leftnum + root->chnum + 1){
		if (root->c == c){
			root->chnum += num;
			return root;
		}
	}
	if (pos > root->leftnum + 1 && pos <= root->leftnum + root->chnum){
		tree* leftblock = (tree*)malloc(sizeof(tree));
		leftblock->left = root->left;
		leftblock->right = NULL;
		leftblock->chnum = pos - root->leftnum - 1;
		leftblock->leftnum = root->leftnum;
		leftblock->c = root->c;
		tree* rightblock = (tree*)malloc(sizeof(tree));
		rightblock->right = root->right;
		rightblock->left = NULL;
		rightblock->chnum = root->leftnum + root->chnum - pos + 1;
		rightblock->leftnum = 0;
		rightblock->c = root->c;
		root->left = leftblock;
		root->right = rightblock;
		root->leftnum = pos - 1;
		root->chnum = num;
		root->c = c;
	}
	else if (pos <= root->leftnum + 1){
		if (root->left == NULL){
			root->left = addleft(root->left, c, num);
		}
		else
			root->left = addmid(root->left, c, pos, num);
		root->leftnum += num;
	}
	else if (pos > root->leftnum + root->chnum){
		if (root->right == NULL){
			root->right = addright(root->right, c, num);
		}
		else
			root->right = addmid(root->right, c, (pos - (root->leftnum + root->chnum)), num);
	}
	return root;
}
int main(void)
{
	tree* root;
	root = NULL;
	char cmd[50];
	while (fgets(cmd, 50, stdin) != NULL){
		if (cmd[0] == 'p'){
			printanswer(root);	
			printf("$\n");
		}	
		else{
			if (cmd[7] == 'l'){
				char c = cmd[12];
				int num = str2int(&cmd[14]);
				root = addleft(root, c, num);
			}
			else if (cmd[7] == 'r'){
				char c = cmd[13];
				int num = str2int(&cmd[15]);
				root = addright(root, c, num);
			}
			else{
				int pos = str2int(&cmd[7]);
				int chpos = 7;
				while (cmd[chpos] != ' ')
					chpos++;
				chpos++;
				char c = cmd[chpos];
				int num = str2int(&cmd[chpos + 2]);
				root = addmid(root, c, pos, num);
			}		
		}
#ifdef DEBUG
		if (root != NULL){
			printf("root: %c leftnum %d rightnum %d\n", root->c, root->leftnum, root->rightnum);
			printtree(root);
			printf("\n");
			printanswer(root);
			printf("$\n");
		}
#endif	
	}
	return 0;
}

