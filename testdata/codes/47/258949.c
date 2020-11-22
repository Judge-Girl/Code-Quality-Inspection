#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int left, node;
	struct node *leftPtr, *rightPtr;
	char x;
}node;

node *Left(node* ptr, char k, int num){
	if(ptr == NULL){
		ptr = (node*)malloc(sizeof(node));
		ptr->node = num;
		ptr->leftPtr = ptr->rightPtr = NULL;
		ptr->x = k;
		ptr->left = 0;
	}
	else if(ptr->leftPtr == NULL && ptr->x == k)
		ptr->node += num;
	else{
		ptr->leftPtr = Left(ptr->leftPtr, k, num);
		ptr->left += num;
	}
	return ptr;
}

node *Right(node* ptr, char k, int num){
	if(ptr == NULL){
		ptr = (node*)malloc(sizeof(node));
		ptr->node = num;
		ptr->leftPtr = ptr->rightPtr = NULL;
		ptr->x = k;
		ptr->left = 0;
	}
	else if(ptr->rightPtr == NULL && ptr->x == k)
		ptr->node += num;
	else
		ptr->rightPtr = Right(ptr->rightPtr, k, num);
		
	return ptr;
}

node* Insert(node* ptr, int place, char k, int num){
	if(ptr == NULL){
		ptr = (node*)malloc(sizeof(node));
		ptr->node = num;
		ptr->leftPtr = ptr->rightPtr = NULL;
		ptr->x = k;
		ptr->left = 0;
	}
	else if(k == ptr->x && (ptr->left < place && ptr->left + ptr->node + 1 >= place))
		ptr->node += num;
	else if(place <= ptr->left + 1){
		ptr->leftPtr = Insert(ptr->leftPtr, place, k, num);
		ptr->left += num;
	}	
	else if(place > ptr->left + ptr->node)
		ptr->rightPtr = Insert(ptr->rightPtr, place - ptr->left - ptr->node, k, num);
	else{
		ptr->leftPtr = Right(ptr->leftPtr, ptr->x, place - ptr->left - 1);
		ptr->rightPtr = Left(ptr->rightPtr, ptr->x, ptr->node - (place - ptr->left - 1));
		ptr->left += place - ptr->left - 1;
		ptr->node = num;
		ptr->x = k;
	}
	return ptr;
}

void Print(node* ptr){
	if(ptr == NULL)
		return;
	Print(ptr->leftPtr);
	printf("%c %d ", ptr->x, ptr->node);
	Print(ptr->rightPtr);
}

void Free(node* ptr){
	if(ptr == NULL)
		return;
	Free(ptr->leftPtr);
	Free(ptr->rightPtr);
	free(ptr);
}

int main(void){
	node* root = NULL;
	char command[11], k[3];
	int num, set = 0, place;
	while(scanf("%s", command) != EOF){
		if(command[0] == 'i'){
			scanf("%s%s%d", command, k, &num);
			place = atoi(command);
			if(command[0] == 'l')
				root = Left(root, k[0], num);
			else if(command[0] == 'r')
				root = Right(root, k[0], num);
			else
				root = Insert(root, place, k[0], num);
		}
		else{
			Print(root);
			printf("$\n");
		}
	}
	Free(root);
	return 0;
}

