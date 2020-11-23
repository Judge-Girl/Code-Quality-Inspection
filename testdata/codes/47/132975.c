#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct t{
	int nm;
	char word;
	int consecutive;
	struct t *left;
	struct t *right;
	struct t *parent;
}Node;
Node rel[1000009]={};
int rel_ct=0;
Node *new_node(){
	Node *n = &rel[rel_ct++];
	n->nm=0;
	n->consecutive=0;
	n->left=NULL;
	n->right=NULL;
	n->parent=n;
	return n;
}
Node *insert_right(Node *root,Node *parent,char word,int nm){
	if(nm<=0)
		return root;
	if(root==NULL){
			if(parent!=NULL&&parent->word==word){
				parent->consecutive+=nm;
				return NULL;
			}
			else{
				Node *n = new_node();
				n->nm+=nm;
				n->word=word;
				n->parent=parent;
				n->consecutive=nm;
				return n;
			}
	}
	if(root!=NULL){
		root->nm+=nm;
		root->right=insert_right(root->right,root,word,nm);
	}
	return root;
}
Node *insert_left(Node *root,Node *parent,char word,int nm){
	if(nm<=0)
		return root;
	if(root==NULL){
		if(parent!=NULL&&parent->word==word){
			parent->consecutive+=nm;
			return NULL;
		}
		else{
			Node *n = new_node();
			n->nm+=nm;
			n->word=word;
			n->consecutive=nm;
			return n;
		}
	}
	if(root!=NULL){
		root->nm+=nm;
		root->left=insert_left(root->left,root,word,nm);
	}
	return root;
}
Node *insert(Node *root,Node *parent,char word,int locate,int nm,int ct){
	//printf("%d\n",ct);
	if(root==NULL){
		Node *n = new_node();
		n->nm+=nm;
		n->word=word;
		n->consecutive=nm;
		return n;
	}
	int infront=ct;
	root->nm+=nm;
	if(root->left!=NULL)
		infront+=root->left->nm;
	if(root->consecutive+infront>=locate){
		if(infront>=locate){
//			puts("hee");
			root->left=insert(root->left,root,word,locate,nm,ct);
		}
		else{
//			puts("here");
			int split=locate-infront;
			char tp_word=root->word;
			int tp_nm=root->nm;
			int tp_con=root->consecutive;
			root->word=word;
			root->consecutive=nm;
//			printf("infront:%d word:%c tp_word:%c\n",infront,word,tp_word);
			if(root->left!=NULL){
				root->left->nm+=split-1;
				root->left->right=insert_right(root->left->right,root->left,tp_word,split-1);
			}
			else{
				root->left=insert_left(root->left,root,tp_word,(split-1));
			}

			if(root->right!=NULL){
				root->right->nm+=tp_con-(split-1);
				root->right->left=insert_left(root->right->left,root->right,tp_word,tp_con-(split-1));
			}
			else{
				root->right=insert_right(root->right,root,tp_word,tp_con-(split-1));
			}
		//	printf("infront: %dtp_con:%d root->nm%d root->word:%c root->consecutive:%d\n",infront,tp_con,root->nm,root->word,root->consecutive);
		}
	}
	else{
//		puts("= =");
		root->right=insert(root->right,root,word,locate,nm,infront+root->consecutive);
	}
	return root;
}
char str[1000009];
int con[1000009];
int word_ct=0;
/*void inorder_print(Node *root){
	if(root==NULL)
		return;
	inorder_print(root->left);
	str[word_ct]=root->word;
	con[word_ct]=root->consecutive;
	word_ct++;
	inorder_print(root->right);		
}*/
char pre;
int inorder_ct=0;
void inorder_print(Node *root,Node *p){
	if(root==NULL){
		return;
	}
	inorder_print(root->left,root);
	if(inorder_ct!=0&&root->word!=pre){
		printf("%d ",inorder_ct);
		printf("%c ",root->word);
		inorder_ct=root->consecutive;
		pre=root->word;
	}
	else if(root->word==pre){
		inorder_ct+=root->consecutive;
	}
	else{
		printf("%c ",root->word);
		pre=root->word;
		inorder_ct+=root->consecutive;
	}
	inorder_print(root->right,root);
}
int main(){
	char input[10];
	Node *root = NULL;
	while(scanf("%s",input)!=EOF){
		if(strcmp(input,"print")==0){
/*	            word_ct=0;
				inorder_print(root);
				int i;
				int ct=0;
				for(i=0;i<word_ct;i++){
					if(i==0)
						ct=con[i];
					else if(i==word_ct-1&&ct==con[i]){
						printf("%c %d ",str[i],ct);
						break;
					}
					if(str[i]==str[i+1]){
						ct+=con[i+1];
					}
					else{
						printf("%c %d ",str[i],ct);
						ct=con[i+1];
					}
				}
*/
				inorder_ct=0;
				pre=' ';
				inorder_print(root,root);
				if(inorder_ct!=0)
					printf("%d ",inorder_ct);
				puts("$");
		}
		else if(strcmp(input,"insert")==0){
			scanf("%s",input);
			if(strcmp(input,"left")==0){
				char word;
				int nm;
				scanf("%*c%c",&word);
				scanf("%d",&nm);
				root=insert_left(root,root,word,nm);
			}
			else if(strcmp(input,"right")==0){
				char word;
				int nm;
				scanf("%*c%c",&word);
				scanf("%d",&nm);
				root=insert_right(root,root,word,nm);
			}
			else if(isdigit(input[0])){
				int temp=0;
				char word;
				for(int i=0;i<strlen(input);i++){
					temp*=10;
					temp+=input[i]-'0';
				}
				int nm;
				scanf("%*c%c",&word);
				scanf("%d",&nm);
				root = insert(root,root,word,temp,nm,0);
			}
		}
	}
	return 0;
}


