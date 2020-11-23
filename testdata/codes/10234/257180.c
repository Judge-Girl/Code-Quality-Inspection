#include "tree.h"
#include <stdlib.h>
typedef struct Node node;
node* treeAND(node* a,node *b){
if(a&&b){
a->val *= b->val;
a->right = treeAND(a->right,b->right);
a->left = treeAND(a->left,b->left);
return a;
}else return NULL;

}
node* treeOR(node* a,node* b){
if(a||b){
if(a){


}else{
node* tmp = a;
a = b;
b = tmp;
}
a->val += b?b->val:0;
a->right = treeOR(a->right,b?b->right:NULL);
a->left = treeOR(a->left,b?b->left:NULL);
return a;
}else return NULL;

}

