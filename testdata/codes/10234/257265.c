#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int val;
    struct Node *left, *right;
} Node;
 void andtree(Node *head1, Node *head2, Node *current){
	if(head1 -> left != NULL && head2 -> left != NULL){
		current -> left = (Node*) malloc(sizeof(Node));
		current -> left -> val = head1 -> left -> val * head2 -> left -> val;
		andtree(head1 -> left, head2 -> left, current -> left);
	}
	else{
		current -> left = NULL;
	}
	if(head1 -> right != NULL && head2 -> right != NULL){
		current -> right = (Node*) malloc(sizeof(Node));
		current -> right -> val = head1 -> right -> val * head2 -> right -> val;
		andtree(head1 -> right, head2 -> right, current -> right);
	}
	else{
		current -> right = NULL;
	}
}
Node *treeAND(Node *root1, Node *root2){
	Node *head = (Node*) malloc(sizeof(Node));
	head -> val = root1 -> val * root2 -> val;
	andtree(root1, root2, head);
	return head;
}
void ortree(Node *head1, Node *head2, Node *current){
	if(head1 != NULL && head2 != NULL){
		current -> val = head1 -> val + head2 -> val;
		if(head1 -> left != NULL || head2 -> left != NULL){
			current -> left = (Node*) malloc(sizeof(Node));
			if(head1 -> left != NULL && head2 -> left != NULL)
				ortree(head1 -> left, head2 -> left, current -> left);
			else if(head1 -> left != NULL)
				ortree(head1 -> left, NULL, current -> left);
			else if(head2 -> left != NULL)
				ortree(NULL, head2 -> left, current -> left);
		}
		if(head1 -> right != NULL || head2 -> right != NULL){
			current -> right = (Node*) malloc(sizeof(Node));
			if(head1 -> right != NULL && head2 -> right != NULL)
				ortree(head1 -> right, head2 -> right, current -> right);
			else if(head1 -> right != NULL)
				ortree(head1 -> right, NULL, current -> right);
			else if(head2 -> right != NULL)
				ortree(NULL, head2 -> right, current -> right);
		}
	}
	else if(head1 != NULL){
		current -> val = head1 -> val;
		if(head1 -> left != NULL){
			current -> left = (Node*) malloc(sizeof(Node));
			ortree(head1 -> left, NULL, current -> left);
		}
		if(head1 -> right != NULL){
			current -> right = (Node*) malloc(sizeof(Node));
			ortree(head1 -> right, NULL, current -> right);
		}
	}
	else if(head2 != NULL){
		current -> val = head2 -> val;
		if(head2 -> left != NULL){
			current -> left = (Node*) malloc(sizeof(Node));
			ortree(NULL, head2 -> left, current -> left);
		}
		if(head2 -> right != NULL){
			current -> right = (Node*) malloc(sizeof(Node));
			ortree(NULL, head2 -> right, current -> right);
		}
	}
}
Node *treeOR(Node *root1, Node *root2){
	Node *head = (Node*) malloc(sizeof(Node));
	head -> val = root1 -> val + root2 -> val;
	ortree(root1, root2, head);
	return head;
}
