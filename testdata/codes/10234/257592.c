#include<stdio.h>
#include"tree.h"
void AND_ins(Node* cur_node,Node* cur_node1,Node* cur_node2){
    (*cur_node).val=(*cur_node1).val*(*cur_node2).val;
    if((*cur_node1).left!=NULL&&(*cur_node2).left!=NULL){
        (*cur_node).left=(Node*)malloc(sizeof(Node));
        AND_ins((*cur_node).left,(*cur_node1).left,(*cur_node2).left);
    }
    else{
        (*cur_node).left=NULL;
    }
    if((*cur_node1).right!=NULL&&(*cur_node2).right!=NULL){
        (*cur_node).right=(Node*)malloc(sizeof(Node));
        AND_ins((*cur_node).right,(*cur_node1).right,(*cur_node2).right);
    }
    else{
        (*cur_node).right=NULL;
    }
    return;
}
void OR_ins(Node* cur_node,Node* cur_node1,Node* cur_node2){
    int val1=0;
    int val2=0;
    if(cur_node1!=NULL){
        val1=(*cur_node1).val;
    }
    if(cur_node2!=NULL){
        val2=(*cur_node2).val;
    }
    (*cur_node).val=val1+val2;
    if(cur_node1==NULL){
    	if((*cur_node2).left!=NULL){
      		(*cur_node).left=(Node*)malloc(sizeof(Node));
        	OR_ins((*cur_node).left,NULL,(*cur_node2).left);
  	   	}
  	   	else{
        	(*cur_node).left=NULL;
    	}
    	if((*cur_node2).right!=NULL){
       		(*cur_node).right=(Node*)malloc(sizeof(Node));
       		OR_ins((*cur_node).right,NULL,(*cur_node2).right);
    	}
    	else{
       		(*cur_node).right=NULL;
    	}
	}
	else if(cur_node2==NULL){
		if((*cur_node1).left!=NULL){
      		(*cur_node).left=(Node*)malloc(sizeof(Node));
        	OR_ins((*cur_node).left,(*cur_node1).left,NULL);
  	   	}
  	   	else{
        	(*cur_node).left=NULL;
    	}
    	if((*cur_node1).right!=NULL){
       		(*cur_node).right=(Node*)malloc(sizeof(Node));
       		OR_ins((*cur_node).right,(*cur_node1).right,NULL);
    	}
    	else{
       		(*cur_node).right=NULL;
    	}
	}
	else{
		if((*cur_node1).left!=NULL||(*cur_node2).left!=NULL){
        	(*cur_node).left=(Node*)malloc(sizeof(Node));
        	OR_ins((*cur_node).left,(*cur_node1).left,(*cur_node2).left);
    	}
    	else{
        	(*cur_node).left=NULL;
    	}
    	if((*cur_node1).right!=NULL||(*cur_node2).right!=NULL){
       		(*cur_node).right=(Node*)malloc(sizeof(Node));
        	OR_ins((*cur_node).right,(*cur_node1).right,(*cur_node2).right);
    		}
    	else{
       		(*cur_node).right=NULL;
  		}
	}
    return;
}
Node *treeAND(Node *root1, Node *root2){
    Node* root=(Node*)malloc(sizeof(Node));
    AND_ins(root,root1,root2);
    return root;
}
Node *treeOR(Node *root1, Node *root2){
    Node* root=(Node*)malloc(sizeof(Node));
    OR_ins(root,root1,root2);
    return root;
}
