#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct word{
    char alp;
    int many,ln;
    struct word *l,*r;
};
typedef struct word Map;
void print(Map *root){
	if(root==NULL)
		return;
    print(root->l);
    printf("%c %d ",root->alp,root->many);
    //fprintf(fp,"%c %d ",root->alp,root->many);
    //printf(" ln:%d ",root->ln);
    print(root->r);
    return;
}
Map *left(Map *root,char alp,int many){
    if(root==NULL){
        Map* n = (Map*)malloc(sizeof(Map));
        n->alp = alp;
        n->many = many;
        n->ln = 0;
        n->l = NULL;
        n->r = NULL;
        return n;
    }
    else if(root->l==NULL&&root->alp==alp){
    	root->many += many;
    	return root;
	}
    root->ln += many;
    root->l = left(root->l,alp,many);
    return root;
}
Map *right(Map *root,char alp,int many){
    if(root==NULL){
        Map* n = (Map*)malloc(sizeof(Map));
        n->alp = alp;
        n->many = many;
        n->ln = 0;
        n->l = NULL;
        n->r = NULL;
        return n;
    }
    else if(root->r==NULL&&root->alp==alp){
    	root->many += many;
    	return root;
	}
    root->r = right(root->r,alp,many);
    return root;
}
Map *insert(Map *root,int where,char alp,int many){
    if(root==NULL)
    	return right(root,alp,many);
    if(where==1)
    	return left(root,alp,many);
    if(where==root->ln+1){
    	if(root->alp==alp)
    		root->many += many;
		else{
			root->ln += many;
			root->l = right(root->l,alp,many);
		}
		return root;
	}
    if(where<=root->ln){
    	if(root->l==NULL){
    		return left(root,alp,many);
		}
    	root->ln += many;
    	root->l = insert(root->l,where,alp,many);
    	return root;
    }
    if(where>root->ln+root->many){
    	if(root->r==NULL)
    		return right(root,alp,many);
    	if(where-root->ln-root->many==1&&root->alp==alp){
    		root->many += many;
    		return root;
		}
    	root->r = insert(root->r,where-root->ln-root->many,alp,many);
    	return root;
	}
	else{
		if(root->alp==alp){
			root->many+=many;
			return root;
		}
		Map *l = (Map*)malloc(sizeof(Map));
		l->alp = root->alp;
		l->many = where - root->ln - 1;
		l->ln = root->ln;
		l->l = root->l;
		l->r = NULL;
		Map *n = (Map*)malloc(sizeof(Map));
		n->alp = alp;
		n->many = many;
		n->ln = where - 1;
		n->l = l;
		n->r = root;
		root->l = NULL;
		root->ln = 0;
		root->many -= l->many;
		return n;
	}
}
int main(void) {
    char temp[50];
    Map *root = NULL;
    while(gets(temp)!=NULL){
        char *del = " ";
        char *str = strtok(temp,del);
        int cnt = 0;
        char cmd[4][20];
        while(str!=NULL){
            strcpy(cmd[cnt],str);
            cnt++;
            str = strtok(NULL,del);
        }
        if(cmd[0][0] == 'p'){
            print(root);
            printf("$\n");
        }
        else{
            if(cmd[1][0] == 'l'){
                root = left(root,cmd[2][0],atoi(cmd[3]));
            }
            else if(cmd[1][0] == 'r'){
                root = right(root,cmd[2][0],atoi(cmd[3]));
            }
            else{
                root = insert(root,atoi(cmd[1]),cmd[2][0],atoi(cmd[3]));
            }
        }
    }
    return 0;
}
