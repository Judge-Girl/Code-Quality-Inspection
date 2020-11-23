#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    char character;
    int leftn, rightn, length;
    struct node *left, *right;
} Node;
int num_node = 0;
void print(Node *head){
    if(head == NULL) return;
    print(head->left);
    printf("%c %d ",head->character,head->length);
    print(head->right);
    return;
}
Node* insert(Node *head,int pos,char c,int len){
	if(head == NULL){
		Node *current = (Node*)malloc(sizeof(Node));
		current->character = c;
		current->leftn = current->rightn = 0;
		current->length = len;
		current->left = current->right = NULL;
		return current;
	}
	if(pos <= head->leftn + 1){
		if(pos == head->leftn+1 && head->character == c){
			head->length += len;
			return head;
		}
		head->leftn += len;
		head->left = insert(head->left, pos, c, len);
		return head;
	}
	if(pos >= head->leftn + head->length + 1){
		if(pos == head->leftn + head->length + 1 && head->character == c){
			head->length += len;
			return head;
		}
		head->rightn += len;
		head->right = insert(head->right, pos-(head->leftn+head->length), c, len);
		return head;
	}
	if(head->character == c){
		head->length += len;
		return head;
	}
	Node *tmp = head;
	int remain = head->length - (pos-head->leftn-1);
	char remainc = head->character;
	head->length = (pos-head->leftn-1);
	head->rightn += (len+remain);	
	if(head->right == NULL){
		head->right = insert(head->right, pos, c, len);
		head->right->right = insert(head->right->right, pos, remainc, remain);
		return head;
	}
	head = head->right;
	head->leftn += (len+remain);
	while(head->left != NULL){
		head = head->left;
		head->leftn += (len+remain);
	}
	head->left = insert(head->left, pos, c, len);
	head->left->right = insert(head->left->right, pos, remainc, remain);
	return tmp;
}
int main(){
    Node *head = NULL;
    char mode[10], loc[10];
    int pos, total = 0;
    while(scanf("%s",mode) != EOF){
        if(strcmp(mode,"print") == 0){
        	print(head);
        	printf("$\n");
        }
        else{
        	scanf("%s",loc);
        	if(strcmp(loc,"left") == 0) pos = 1;
        	else if(strcmp(loc,"right") == 0) pos = total+1;
        	else pos = atoi(loc);
        	char c; int len;
        	scanf(" %c %d",&c, &len);
        	total += len;
        	head = insert(head, pos, c, len);
        }
    }
    return 0;
}
