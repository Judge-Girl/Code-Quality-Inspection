#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char c;
  int len;
  int leftLen, rightLen;
  struct Node *left, *right;
} Node;

void Print(Node *root) {
  if (root == NULL) return;
  Print(root->left);
  printf("%c %d ", root->c, root->len);
  Print(root->right);
}

Node* Insert(Node *root, int k, char c, int len) {
  if (root == NULL) {
    root = malloc(sizeof(Node));
    root->c = c;
    root->len = len;
    root->leftLen = root->rightLen = 0;
    root->left = root->right = NULL;
  } else if (root->c == c && (root->leftLen <= k && k <= root->leftLen + root->len)) {
#ifdef DEBUG
    printf("%d: Extending %c %d (left: %d, right %d)\n", k, root->c, root->len, root->leftLen, root->rightLen);
#endif

    root->len += len;
  } else if (k <= root->leftLen || (k == 0 && root->left == NULL)) {
#ifdef DEBUG
    printf("%d: Inserting left of %c %d (left: %d, right: %d)\n", k, root->c, root->len, root->leftLen, root->rightLen);
#endif

    root->left = Insert(root->left, k, c, len);
    root->leftLen += len;
  } else if (k >= root->leftLen + root->len) {
#ifdef DEBUG
    printf("%d: Inserting right of %c %d (left: %d, right: %d)\n", k, root->c, root->len, root->leftLen, root->rightLen);
#endif

    root->right = Insert(root->right, k - root->leftLen - root->len, c, len); // test
    root->rightLen += len;
  } else {
#ifdef DEBUG
    printf("%d: Splitting %c %d (left: %d, right: %d)\n", k, root->c, root->len, root->leftLen, root->rightLen);
#endif

    // left
    Node *leftMost = root->left;
    root->left = malloc(sizeof(Node));
    root->left->c = root->c;
    root->left->len = k - root->leftLen;
    root->left->leftLen = (leftMost == NULL) ? 0 : (leftMost->leftLen + leftMost->len + leftMost->rightLen);
    root->left->rightLen = 0;
    root->left->left = leftMost;
    root->left->right = NULL;
    // right
    Node *rightMost = root->right;
    root->right = malloc(sizeof(Node));
    root->right->c = root->c;
    root->right->len = root->leftLen + root->len - k;
    root->right->leftLen = 0;
    root->right->rightLen = (rightMost == NULL) ? 0 : (rightMost->leftLen + rightMost->len + rightMost->rightLen);
    root->right->left = NULL;
    root->right->right = rightMost;
    // mid
    root->c = c;
    root->len = len;
    root->leftLen = root->left->leftLen + root->left->len + root->left->rightLen;
    root->rightLen = root->right->leftLen + root->right->len + root->right->rightLen;
  }
  return root;
}

int main() {
  char instruction[128];
  Node *root = NULL;
  while (scanf("%s", instruction) != EOF) {
    if (strcmp(instruction, "print") == 0) {
      Print(root);
      printf("$\n");
    } else if (strcmp(instruction, "insert") == 0) {
      char c;
      int k, len;  
      scanf("%s %c%d", instruction, &c, &len);
      if (strcmp(instruction, "left") == 0) k = 0;
      else if (strcmp(instruction, "right") == 0) k = (root == NULL) ? 0 : (root->leftLen + root->len + root->rightLen);
      else k = atoi(instruction) - 1;
      root = Insert(root, k, c, len);
    }
  
#ifdef DEBUG
    printf("Current: ");
    Print(root);
    printf("$\n");
#endif
  }
}


