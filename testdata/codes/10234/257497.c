#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
 
Node *treeAND(Node *root1, Node *root2){
Node *new=(Node *)malloc(sizeof(Node));


if(root1==NULL)
{
    return root1;}
if(root2==NULL)
{
 return root2;}
new->left=treeAND(root1->left,root2->left);
new->val=root1->val*root2->val;
new->right=treeAND(root1->right,root2->right);


return new;
}
Node *treeOR(Node *root1, Node *root2){
Node *new=malloc(sizeof(root1)+sizeof(root2));


if(root1==NULL)
{
    return root2;}
if(root2==NULL)
{
    return root1;}
new->left=treeOR(root1->left,root2->left);
new->val=root1->val+root2->val;
new->right=treeOR(root1->right,root2->right);
return new;

}

