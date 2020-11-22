#include<stdio.h>
#include<stdlib.h>
int left_part;
typedef struct node{
    char val;
    int tol;
    int weight;
    struct node *left;
    struct node *right;
    struct node *parent;
}Node;

Node* GenNode(char val, int num, Node* parent){
    Node *ptr;
    ptr = (Node* )malloc(sizeof(Node));
    ptr->val = val;
    ptr->weight = num;
    ptr->tol = 0;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->parent = parent;
    return ptr;
}

void insert(Node *s, int num){
    if(s){
        s->tol+=num;
    if(s->parent){
        insert(s->parent, num);
    }
}
}

Node* find_node(Node *s, int i){
    int left_weight, s_weight = s->weight;

    if(s->left == NULL)
        left_weight = 0;
    else
        left_weight = s->left->tol;
    if(i>left_weight && i<=left_weight+s_weight){
        left_part = i-left_weight-1;
        return s;
    }
    if(i<=left_weight)
        return find_node(s->left, i);
    if(i == left_weight+s_weight+1){
        left_part = s_weight;
        return s;
    }
    if(i>left_weight+s_weight)
        return find_node(s->right, i-left_weight-s_weight);
}

Node* find_left(Node *s){
    if(s->left!=NULL)
        return find_left(s->left);
    return s;
}

Node* find_right(Node *s){
    if(s->right!=NULL)
        return find_right(s->right);
    return s;
}

Node *find_previous(Node *s, Node *current){
    if(s->right == current && current)
        return s;
    if(s->left!=NULL && !current)
        return find_right(s->left);
    if(!s->parent)
        return NULL;
    return find_previous(s->parent, s);
}

Node *find_next(Node *s, Node *current){
    if(s->left == current && current)
        return s;
    if(s->right!=NULL && !current)
        return find_left(s->right);
    if(!s->parent)
        return NULL;
    return find_next(s->parent, s);
}

void insert_left(Node *s, char val, int num){
    Node *cur = find_left(s);
    if(cur->val == val){
        cur->weight+=num;
        insert(cur, num);
    }else{
        cur->left = GenNode(val, num, cur);
        insert(cur->left, num);
    }return;
}

void insert_right(Node *s, char val, int num){
    Node *cur = find_right(s);
    if(cur->val == val){
        cur->weight+=num;
        insert(cur, num);
    }
    else{
        cur->right = GenNode(val, num, cur);
        insert(cur->right, num);
    }
    return;
}

void insert_mid(Node *s, char val, int num, int index){
    Node *current = find_node(s, index);
    if(val == current->val){
        current->weight+=num;
        insert(current, num);
        return;
    }
    if(left_part == 0){
        Node *r = find_previous(current, NULL);

        if(r){
            if(r->val == val){
                r->weight+=num;
                insert(r, num);
                return;
            }
            if(!r->right){
                r->right = GenNode(val, num, r);
                insert(r->right, num);
                return;
            }
        }
        current->left = GenNode(val, num, current);
        insert(current->left, num);
        return;
    }

    if(left_part == current->weight){
        Node *next = find_next(current, NULL);
        if(next){
            if(next->val == val){
                next->weight+=num;
                insert(next, num);
                return;
            }
            if(!next->left){
                next->left = GenNode(val, num, next);
                insert(next->left, num);
                return;
            }
        }
        current->right = GenNode(val, num, current);
        insert(current->right, num);
        return;
    }

    if(current->left==NULL){
        current->left =  GenNode(current->val, left_part, current);
        insert(current->left, left_part);
    }else{
        Node *r = find_right(current->left);
        r->right = GenNode(current->val, left_part, r);
        insert(r->right, left_part);
    }
    if(current->right == NULL){
        current->right = GenNode(current->val, current->weight - left_part, current);
        insert(current->right, current->weight - left_part);
    }else{
        Node *t = find_left(current->right);
        t->left = GenNode(current->val, current->weight - left_part, t);
        insert(t->left, current->weight - left_part);
    }
    current->val = val;
    insert(current, ((-1)*current->weight+num));
    current->weight = num;
    return;
}
void print(Node *s){
    if(s->left!=NULL)
        print(s->left);
    printf("%c %d ", s->val, s->weight);
    if(s->right!=NULL)
        print(s->right);
}
main()
{
    char c[11];
    char val[2];
    int num;
    Node *s = NULL;
    while(scanf("%s", c)!=EOF){
        if(c[0] == 'p'){
            if(s!=NULL){
                print(s);
            }printf("$\n");
        }else{
            if(s!=NULL){
                scanf("%s", c);
                if(c[0] == 'l'){
                    scanf("%s%d", val, &num);
                    insert_left(s, val[0], num);
                }else if(c[0] == 'r'){
                        scanf("%s%d", val, &num);
                    insert_right(s, val[0], num);
                }else{
                    int index = atoi(c);
                    scanf("%s%d", &val, &num);
                    if(index == 1)
                        insert_left(s, val[0], num);
                    else
                        insert_mid(s, val[0], num, index);
                }
            }else{
                scanf("%s%s%d", c, val, &num);
                s = GenNode(val[0], num, NULL);
            }
        }
    }
}


