#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define max_size 6

int total_length = 0;
typedef struct node {
     char c;
     int len, left_len, right_len;
     struct node *left_node, *right_node;
} Node;

Node  *build_node ( char c, int n ) {
     Node *new = (Node*) calloc(1, sizeof(Node));
     new->c = c;
     new->len = n;
     //new->left_len = new->right_len = 0;
     //new->left_node = new->right_node = NULL;
     return new;
}
Node *construct_tree ( Node *cur, int k, char c, int n, int prefix ) {
     if ( cur == NULL )
          return build_node(c, n);

     if ( ( cur->c == c ) && ( prefix + cur->left_len + 1 <= k ) && ( k <= prefix + cur->left_len + cur->len + 1) )
          cur->len += n;
     else if ( k <= ( prefix + cur->left_len + 1 ) ) {
          cur->left_len += n;
          cur->left_node = construct_tree( cur->left_node, k, c, n, prefix );
     }
     else if ( k >= ( prefix + cur->left_len + cur->len + 1 ) ) {
          cur->right_len += n;
          cur->right_node = construct_tree( cur->right_node, k, c, n, ( prefix + cur->left_len + cur->len ) );
     }
     else if ( ( prefix + cur->left_len + 1 ) < k && k < ( prefix + cur->left_len + cur->len + 1 ) ) {
          int left_length = ( k - prefix - cur->left_len - 1), right_length = ( cur->len - left_length );
          //printf("left_length = %d, right_length = %d\n", left_length, right_length);
          Node *new_left = build_node( cur->c, left_length ), *new_right = build_node( cur->c,  right_length );

          new_left->left_node = cur->left_node;
          new_left->left_len = cur->left_len;
          new_right->right_node = cur->right_node;
          new_right->right_len = cur->right_len;

          cur->c = c;
          cur->len = n;
          cur->left_len += left_length;
          cur->right_len += right_length;
          cur->left_node = new_left;
          cur->right_node = new_right;
     }
     else {
          printf("error\n");
          exit(0);
     }

     //if ( cur->left_node != NULL )
          //cur->left_len = ( cur->left_node->left_len + cur->left_node->len + cur->left_node->right_len );
     //if ( cur->right_node != NULL )
          //cur->right_len = ( cur->right_node->left_len + cur->right_node->len + cur->right_node->right_len );
     return cur;
}
void print_string ( Node *cur ) {
     if ( cur == NULL )
          return;
     print_string(cur->left_node);
     printf("%c %d ", cur->c, cur->len);
     print_string(cur->right_node);
     return;
}

int main ( ) {
     int k, n;
     Node *root = NULL;
     char *c = (char*) calloc(2, sizeof(char)), *cmd = (char*) calloc((max_size + 1), sizeof(char));

     while ( scanf("%s", cmd) != EOF ) {
          if ( cmd[0] == 'p' ) {
               print_string(root);
               printf("$\n");
          }
          else {
               scanf("%s%s%d", cmd, c, &n);
               if ( cmd[0] == 'l' )     // left
                    k = 1;
               else if ( cmd[0] == 'r' )     // right
                    k = ( total_length + 1 );
               else
                    k = atoi(cmd);
               total_length += n;
               root = construct_tree(root, k, c[0], n, 0);
          }
     }
     return 0;
}

