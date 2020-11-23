#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    char c;
    int num, lnum, rnum;
    struct Node *left, *right;
}node;
node end = {'\0', 0, 0, 0, NULL, NULL};
node *gennode(char c, int num, node *left, node *right) {
    node *cur = (node *)malloc(sizeof(node));
    cur->c = c;
    cur->num = num;
    cur->lnum = cur->rnum = 0;
    cur->left = left;
    cur->right = right;
    return cur;
}
node *insert(node *root, char c, int num, int pos) {
    if (root->c == '\0') { //leaf
        root = gennode(c, num, &end, &end);
    } else if (root->c == c && (pos >= root->lnum + 1 && pos <= root->lnum + root->num + 1)) { // combine
    	root->num += num;
    } else if (pos <= root->lnum + 1) { // left insert
    	root->left = insert(root->left, c, num, pos);
    	root->lnum += num;
    } else if (pos >= root->lnum + root->num + 1) { // right insert	
    	root->right = insert(root->right, c, num, pos - (root->lnum + root->num));
    	root->rnum += num;
    } else { // cut  	
    	node *newleft = gennode(root->c, pos - (root->lnum + 1), root->left, &end);
    	newleft->lnum = root->lnum;
    	node *newright = gennode(root->c, root->num - (pos - (root->lnum + 1)), &end, root->right);
    	newright->rnum = root->rnum;
    	root->c = c, root->num = num;
    	root->left = newleft, root->right = newright;
    	root->lnum = newleft->lnum + newleft->num;
    	root->rnum = newright->rnum + newright->num;
    }
    return root;
}
void print(node *root) {
    if (root->c == '\0')    
    	return ;
    print(root->left);
    printf("%c %d ", root->c, root->num);
    print(root->right);
}
int main() {
	node *root = &end;
	char cmd[8];
	while (scanf("%s", cmd) == 1) {
		if (cmd[0] == 'p') {
			print(root);
            puts("$");
        } else {
            char pos[16] = {'\0'}, x;
            int n = 0;   
            scanf("%s ", pos);
            if (pos[0] == 'l') {
                scanf("%c %d", &x, &n);
                root = insert(root, x, n, 1);
            } else if (pos[0] == 'r') {
                scanf("%c %d", &x, &n);
                root = insert(root, x, n, root->lnum + root->num + root->rnum + 1);
            } else {
                int p = atoi(pos);
                scanf("%c %d", &x, &n);
                root = insert(root, x, n, p);
            }
        }
	}
	return 0;
}
