#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int left_amount;
    int right_amount;
    int amount;
    char character;
    struct node *left;
    struct node *right;
}   Node;

Node *initialize(char character, int amount, int left_amount, int right_amount, Node *left, Node *right);
void insert_left(Node *root, char character, int amount);
void insert_right(Node *root, char character, int amount);
void insert_index(Node *root, char character, int amount, int index);
void print(Node *root);
void free_memory(Node *root);

int main(void){
    char instruction[20];
    Node *root = initialize('\0', 0, 0, 0, NULL, NULL);
    bool first = true;
    while (scanf("%s", instruction) != EOF){
        if (strcmp(instruction, "insert") == 0){
            char character;
            int amount;
            scanf("%s%*c%c%d", instruction, &character, &amount);
            if (first){
                root->amount = amount;
                root->character = character;
                first = false;
            }
            else if (strcmp(instruction, "left") == 0)
                insert_left(root, character, amount);
            else if (strcmp(instruction, "right") == 0)
                insert_right(root, character, amount);
            else
                insert_index(root, character, amount, atoi(instruction));
        }
        else if (strcmp(instruction, "print") == 0){
            print(root);
            printf("$\n");
        }
    }
    free_memory(root);
    return 0;
}

Node *initialize(char character, int amount, int left_amount, int right_amount, Node *left, Node *right){
    Node *tmp = malloc(sizeof(Node));
    tmp->character = character;
    tmp->amount = amount;
    tmp->left_amount = left_amount;
    tmp->right_amount = right_amount;
    tmp->left = left;
    tmp->right = right;
    return tmp;
}
void insert_left(Node *root, char character, int amount){
    root->left_amount += amount;
    if (root->left == NULL){
        if (root->character == character){
            root->left_amount -= amount;
            root->amount += amount;
            return;
        }
        root->left = initialize(character, amount, 0, 0, NULL, NULL);
    }
    else
        insert_left(root->left, character, amount);
}

void insert_right(Node *root, char character, int amount){
    root->right_amount += amount;
    if (root->right == NULL){
        if (root->character == character){
            root->right_amount -= amount;
            root->amount += amount;
            return;
        }
        root->right = initialize(character, amount, 0, 0, NULL, NULL);
    }
    else
        insert_right(root->right, character, amount);
}

void insert_index(Node *root, char character, int amount, int index){
    if (index == 1){
        insert_left(root, character, amount);
        return;
    }
    if (root->left_amount < index && index <= root->left_amount + root->amount){
        if (root->character == character){
            root->amount += amount;
            return;
        }
        int split_left_amount = index - root->left_amount - 1;
        int split_right_amount = root->amount - split_left_amount;
        if (split_left_amount == 0){
            root->left_amount += amount;
            insert_right(root->left, character, amount);
            return;
        }
        Node *split_left = initialize(root->character, split_left_amount, root->left_amount, 0, root->left, NULL);
        Node *split_right = initialize(root->character, split_right_amount, 0, root->right_amount, NULL, root->right);
        root->character = character;
        root->amount = amount;
        root->left_amount += split_left_amount;
        root->right_amount += split_right_amount;
        root->left = split_left;
        root->right = split_right;
        return;
    }
    else if (index <= root->left_amount){
        root->left_amount += amount;
        if (root->left != NULL)
            insert_index(root->left, character, amount, index);
    }
    else{
        if (index == root->left_amount + root->amount + 1 && root->character == character){
            root->amount += amount;
            return;
        }
        if (root->right == NULL){
            insert_right(root, character, amount);
            return;
        }
        root->right_amount += amount;
        insert_index(root->right, character, amount, index - root->left_amount - root->amount);
    }
}

void print(Node *root){
    if (root != NULL && root->amount != 0){
        print(root->left);
        printf("%c %d ", root->character, root->amount);
        print(root->right);
    }
}

void free_memory(Node *root){
    if (root != NULL){
        free_memory(root->left);
        free_memory(root->right);
        free(root);
    }
    return;
}
