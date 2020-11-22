#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int left, node;
	struct node *leftPtr, *rightPtr;
	char x;
}node;

/*
void New(node* ptr, char k, int num){
	//printf("in new\n");
	ptr = (node*)malloc(sizeof(node));
	ptr->left = ptr->right = 0;
	ptr->node = ptr->total = num;
	ptr->x = k;
	printf("new : %c %d\n", ptr->x, ptr->node);
	return;
}*/

node *Left(node* ptr, char k, int num){
	//if(num == 0)
	//	return ptr;
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
	
	/*
	printf("Left: %c %d\n", k, num);
	ptr->total += num;
	if(ptr->left == 0){
		if(ptr->total == 0 || ptr->x != k){
			ptr->node += num;
			New(ptr->leftPtr, k, num);
		}
		else
			ptr->node += num;
		return;
	}
	ptr->left += num;
	Left(ptr->leftPtr, k, num);
	*/
}

node *Right(node* ptr, char k, int num){
	//if(num == 0)
	//	return ptr;
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
	
	
	/*
	ptr->total += num;
	if(ptr->right == 0){
		if(ptr->total == 0 || ptr->x != k){
			ptr->node += num;
			New(ptr->rightPtr, k, num);
		}
		else
			ptr->node += num;
		return;
	}
	ptr->right += num;
	Right(ptr->rightPtr, k, num);
	*/
}

node* Insert(node* ptr, int place, char k, int num){
	//if(k == 'K' && ptr->x == 's')
		//printf("%d %d\n", place, num);
	//if(num == 0)
		//return ptr;
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
	
	/*
	if(num <= ptr->left){
		ptr->left += num;
		ptr->total += num;
		Insert(ptr->leftPtr, place, k, num);
	}	
	else if(num <= ptr->left + ptr->node + 1){
		if(ptr->x == k){
			ptr->node += num;
			ptr->total += num;
		}
		else if(num == ptr->left + 1){
			ptr->left += num;
			ptr->total += num;
			Right(ptr->leftPtr, k, num);
		}
		else if(num == ptr->left + ptr->node + 1){
			ptr->right += num;
			ptr->total += num;
			Left(ptr->rightPtr, k, num);
		}
		else{
			int toLeft = num - 1, toRight = ptr->node - toLeft;
			Right(ptr->leftPtr, ptr->x, toLeft);
			Left(ptr->rightPtr, ptr->x, toRight);
			ptr->left += toLeft;
			ptr->right += toRight;
			ptr->node = num;
			ptr->total += num;
			ptr->x = k;
		}
	}
	else{
		ptr->right += num;
		ptr->total += num;
		Insert(ptr->rightPtr, place - ptr->left - ptr->node, k, num);
	}
	*/
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
	int num, set = 0;
	while(scanf("%s", command) != EOF){
		//printf("in  while %s\n", command);
		if(command[0] == 'i'){
			//printf("after init\n");
			scanf("%s", command);
			if(command[0] == 'l'){
				scanf("%s%d", k, &num);
				//printf("insert left %c %d\n", k[0], num);
				root = Left(root, k[0], num);
			}
			else if(command[0] == 'r'){
				scanf("%s%d", k, &num);
				//printf("insert right %c %d\n", k[0], num);
				root = Right(root, k[0], num);
				//printf("after right\n");
			}
			else{
				int place = atoi(command);
				scanf("%s%d", k, &num);
				//printf("insert %d %c %d", place, k[0], num);
				root = Insert(root, place, k[0], num);
			}
		}
		else{
			Print(root);
			printf("$\n");
		}
		//Print(root);
		//printf("$\n");
	}
	Free(root);
	//printf("return 0");
	return 0;
}

