#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define DEBUG 0

//the fuck is happening
//edit: and so the adventure continues
//edit: HOLY SHIT NO MORE TLE
typedef struct tree {
    char c;
    int S, L, R; //self, left, right
    struct tree *left, *right;
} Tree;

Tree *insertLeft(Tree *root, char c, int S) { //char and amount
	Tree *current;
	if (root == NULL) { //if first one
		current = (Tree *)malloc(sizeof(Tree));
		current->c = c, current->S = S;
		return current;			
	}
	if (root->left == NULL && root->c == c) { 
			root->S += S; //just add it
			return root;
	}
	root->left = insertLeft(root->left, c, S);
	root->L = root->left->L + root->left->R + root->left->S;
	return root;
}

Tree *insertRight(Tree *root, char c, int S) { //char and amount
	Tree *current;
	if (root == NULL) { //if first one
		current = (Tree *)malloc(sizeof(Tree));
		current->c = c, current->S = S;
		return current;			
	}
	if (root->right == NULL && root->c == c) { 
			root->S += S; //just add it
			return root;
	}
	root->right = insertRight(root->right, c, S);
	root->R = root->right->L + root->right->R + root->right->S;
	return root;
}

 
Tree *makeTree(Tree *root, char c, int S, int k) { 
    Tree *current;
    if (root == NULL) {
		#if DEBUG == 1
        printf("empty, inserting new\n");
		#endif
        current = (Tree *)malloc(sizeof(Tree));
        current->c = c, current->S = S; //L and R are automatically set to 0, left, right are NULL
        return current;
    }
	
	if (k < 0) k = abs(k);
	#if DEBUG == 1
    printf("Inserting %c (%d), currently at %c, %d (%d, %d) and k = %d\n", c, S, root->c, root->S, root->L, root->R, k);
	if (k >= root->L && k <= root->L + root->S) puts("This will fit");
	if (root->c == c) puts("This also fits");	
	#endif	
	if (root->c == c && (k >= root->L && k <= root->L + root->S)) { //if in between, just add
		#if DEBUG == 1
		puts("just adding");
		#endif
		root->S += S;
		return root;
	}
	
    if (k <= root->L) { //insert left
		#if DEBUG == 1
        puts("inserting left");
		#endif
        root->left = makeTree(root->left, c, S, k);
        root->L = root->left->L + root->left->R + root->left->S;
        return root;
    }
    else if (root->S != 1 && k >= root->L + 1 && k <= root->L +root->S - 1) { //middle insertion
		#if DEBUG == 1
        puts("inserting middle");
		#endif
        current = (Tree *)malloc(sizeof(Tree));
		if (current == NULL) puts("OUT OF MEMORY");
        //make left
        current->left = (Tree *)malloc(sizeof(Tree));
		
        current->left->c = root->c; // copy over the original character
		
		current->left->S = k - root->L; // store the number of stuff in new
		// printf("%d\n\n", current->left->S);
		// assert(current->left->S >= 0);
		
		current->left->L = root->L, current->left->R = 0; // store the left's number 
		
        current->left->left = (Tree *)malloc(sizeof(Tree)); 
		current->left->left = root->left; 
		current->left->right = NULL;
		
		#if DEBUG == 1
		// printf("Left side: %d = %d + %d - %d\n", current->left->S, root->L, root->S, k);
		#endif	
        //make right
        current->right = (Tree *)malloc(sizeof(Tree));
        current->right->c = root->c, current->right->S = root->L +root->S - k;
		// assert(current->right->S >= 0);
		#if DEBUG == 1
		// printf("Right side: %d = %d + %d - %d\n", current->right->S, root->L, root->S, k);
		#endif		
		current->right->R = root->R, current->right->L = 0;
        current->right->right = (Tree *)malloc(sizeof(Tree)); 
		current->right->right = root->right;
		//make self
        current->c = c, current->S = S;
        current->L = current->left->L + current->left->R + current->left->S;
        current->R = current->right->L + current->right->R + current->right->S;
		#if DEBUG == 1
		printf("Result: %c %d (%d, %d)\n", current->c, current->S, current->L, current->R);
        printf("Left: %c, S = %d, (L, R) = (%d, %d)\n", current->left->c, current->left->S, current->left->L, current->left->R);
        printf("Right: %c, S = %d, (L, R) = (%d, %d)\n", current->right->c, current->right->S, current->right->L, current->right->R);
		#endif
        return current;
    } 
    else { //insert right
		#if DEBUG == 1
        puts("inserting right");
		#endif
        root->right = makeTree(root->right, c, S, root->L + root->S - k);
        root->R = root->right->L + root->right->R + root->right->S;
        return root;
    }
}


 
void P(Tree *root) {
	if (root == NULL) return;
	P(root->left);
	printf("%c %d ", root->c, root->S);
	P(root->right);
}
 
int main() {
    Tree *word = NULL; char cmd[500], c, currentChar; int n, currentVal, k, i = 0;
    while (scanf("%s", cmd) != EOF) {
        if (!strcmp(cmd, "print")) {
            P(word);
            printf("$\n");
        }
        else {
            scanf("%s %c %d", cmd, &c, &n);
            if (!strcmp(cmd, "left")) {      
				#if DEBUG == 1
				printf("Inserting %c to the front\n", c);         
				#endif
                word = insertLeft(word, c, n);
            }
            else if (!strcmp(cmd, "right")) {
                word = insertRight(word, c, n); 
				#if DEBUG == 1
				printf("Inserting %c to the back\n", c);
				#endif
            }
            else {
                k = atoi(cmd);
				if (k == 1) {
					word = insertLeft(word, c, n);
					#if DEBUG == 1
					printf("Inserting %c to the front\n", c);      
					#endif
				}
				// else if (word != NULL && k == (word->S + word->L + word->R + 1)) {
					// word = insertRight(word, c, n);
					// #if DEBUG == 1
					// printf("Inserting %c to the back\n", c);
					// #endif
				// }
                else word = makeTree(word, c, n, k-1);
            }
        }
    }    
    return 0;
}
