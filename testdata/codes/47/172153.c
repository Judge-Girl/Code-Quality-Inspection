#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct word{
    char x;
    int n;
    int ln;
    int rn;
    struct word *left;
    struct word *right;
};
typedef struct word Word;

Word *insert(Word *head, int pos, char a, int t){
    if(head == NULL){
        Word *current = (Word *)malloc(sizeof(Word));
        current->x = a;
        current->n = t;
        current->ln = 0;
        current->rn = 0;
        current->left = NULL;
        current->right = NULL;
        return current;
    }
    if(pos <= head->ln + 1){
        if(pos == head->ln + 1 && head->x == a){
            head->n += t;
            return head;
        }
        head->ln += t;
        head->left = insert(head->left, pos, a, t);
        return head;
    }
    if(pos >= head->ln + head->n + 1){
        if(pos == head->ln + head->n + 1 && head->x == a){
            head->n += t;
            return head;
        }
        head->rn += t;
        head->right = insert(head->right, pos - (head->ln + head->n), a, t);
        return head;
    }
    if(head->x == a){
        head->n += t;
        return head;
    }
    int l = pos - head->ln - 1;
    int r = head->n - l;
    Word *current = (Word *)malloc(sizeof(Word));
    current->x = a;
    current->n = t;
    current->ln = head->ln;
    current->rn = head->rn;
    current->left = head->left;
    current->right = head->right;
    current = insert(current, current->ln + current->n + 1, head->x, r);
    current = insert(current, current->ln + 1, head->x, l);
    return current;
}

void printwords(Word *head){
    if(head == NULL) return;
    printwords(head->left);
    printf("%c %d ", head->x, head->n);
    printwords(head->right);
}

int main(){
    char in[10];
    char a[3];
    int n = 0;
    Word *head = NULL;
    int pos, t;
    while(scanf("%s", in) != EOF){
        if(strcmp(in, "print") == 0){
            printwords(head);
            printf("$\n");
        }else{
            scanf("%s", in);
            if(strcmp(in, "left") == 0) pos = 1;
            else if(strcmp(in, "right") == 0) pos = n + 1;
            else pos = atoi(in);
            scanf("%s%d", a, &t);
            n += t;
            head = insert(head, pos, a[0], t);
        }
    }
    return 0;
}
